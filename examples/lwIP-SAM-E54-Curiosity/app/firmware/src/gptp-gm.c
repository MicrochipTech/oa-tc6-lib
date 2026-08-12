#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "tc6-conf.h"
#include "tc6.h"
#include "tc6-stub.h"
#include "tc6-lwip.h"
#include "gptp-gm.h"

/* PTP / 802.1AS frame layout constants */
#define PTP_ETHERTYPE            (0x88F7u)
#define PTP_TRANSPORT_SPECIFIC   (0x1u)   /* 802.1AS marker in high nibble of byte 0 */
#define PTP_MSGTYPE_SYNC         (0x0u)
#define PTP_MSGTYPE_FOLLOW_UP    (0x8u)
#define PTP_VERSION              (0x02u)
#define PTP_FLAG_TWO_STEP        (0x0200u) /* flagField, big-endian: twoStepFlag */
#define PTP_CONTROL_SYNC         (0x00u)
#define PTP_CONTROL_FOLLOW_UP    (0x02u)
#define PTP_HEADER_LEN           (34u)
#define PTP_TIMESTAMP_LEN        (10u)
#define PTP_FOLLOWUP_TLV_LEN     (32u)
#define ETH_HEADER_LEN           (14u)
#define ETH_MIN_FRAME_LEN        (60u)    /* without FCS */
#define PTP_SYNC_MSG_LEN         (PTP_HEADER_LEN + PTP_TIMESTAMP_LEN)                        /* 44 */
#define PTP_FOLLOWUP_MSG_LEN     (PTP_HEADER_LEN + PTP_TIMESTAMP_LEN + PTP_FOLLOWUP_TLV_LEN) /* 76 */
#define SYNC_FRAME_LEN           (ETH_MIN_FRAME_LEN)                          /* 14+44=58 padded to 60 */
#define FOLLOWUP_FRAME_LEN       (ETH_HEADER_LEN + PTP_FOLLOWUP_MSG_LEN)      /* 90 */
#define GPTP_GM_MAX_FRAME_LEN    (96u)    /* >= max(SYNC_FRAME_LEN, FOLLOWUP_FRAME_LEN) */

/* If a sent Sync's TX timestamp callback never arrives, clear the pending
   state after this long so a single lost capture cannot permanently stall
   the Grand Master. Uses wrap-safe unsigned tick subtraction. */
#define GPTP_GM_TS_TIMEOUT_MS    (4u * GPTP_GM_SYNC_INTERVAL_MS)

static const uint8_t GPTP_MCAST_MAC[6] = { 0x01u, 0x80u, 0xC2u, 0x00u, 0x00u, 0x0Eu };

typedef struct
{
    int8_t idx;
    bool initialized;
    bool enabled;                /* gates Sync transmission; scheduler keeps running */
    uint8_t srcMac[6];
    uint8_t clockIdentity[8];
    uint16_t sequenceId;
    uint8_t txSlot;              /* 1,2,3 - rotates each Sync */
    uint32_t nextSyncTick;
    bool syncPending;            /* a Sync is awaiting its TX timestamp */
    uint16_t pendingSequenceId;  /* sequenceId of the in-flight Sync */
    uint8_t pendingSlot;         /* tsc slot of the in-flight Sync */
    uint32_t pendingSinceTick;   /* tick when the in-flight Sync was enqueued */
    uint32_t missedCount;        /* timestamp-missed diagnostics */
    uint8_t syncBuf[GPTP_GM_MAX_FRAME_LEN];
    uint8_t followUpBuf[GPTP_GM_MAX_FRAME_LEN];
} GptpGm_t;

static GptpGm_t m_gm[TC6_MAX_INSTANCES];

static void WriteBE16(uint8_t *p, uint16_t v);
static void WriteBE32(uint8_t *p, uint32_t v);
static void BuildClockIdentity(const uint8_t mac[6], uint8_t id[8]);
static uint16_t BuildPtpHeader(uint8_t *buf, const GptpGm_t *gm, uint8_t msgType, uint16_t msgLen, uint16_t seqId, uint8_t control);
static void BuildSyncFrame(GptpGm_t *gm, uint16_t seqId);
static void BuildFollowUpFrame(GptpGm_t *gm, uint16_t seqId, uint32_t seconds, uint32_t nanoseconds);
static void SendSync(GptpGm_t *gm);

static void WriteBE16(uint8_t *p, uint16_t v)
{
    p[0] = (uint8_t)(v >> 8);
    p[1] = (uint8_t)(v & 0xFFu);
}

static void WriteBE32(uint8_t *p, uint32_t v)
{
    p[0] = (uint8_t)(v >> 24);
    p[1] = (uint8_t)(v >> 16);
    p[2] = (uint8_t)(v >> 8);
    p[3] = (uint8_t)(v & 0xFFu);
}

/* EUI-64 from MAC-48: MAC[0..2] FF FE MAC[3..5] */
static void BuildClockIdentity(const uint8_t mac[6], uint8_t id[8])
{
    id[0] = mac[0];
    id[1] = mac[1];
    id[2] = mac[2];
    id[3] = 0xFFu;
    id[4] = 0xFEu;
    id[5] = mac[3];
    id[6] = mac[4];
    id[7] = mac[5];
}

/* Fills the 14-byte Ethernet header + 34-byte PTP common header.
   Returns the offset just past the common header (== ETH_HEADER_LEN + PTP_HEADER_LEN). */
static uint16_t BuildPtpHeader(uint8_t *buf, const GptpGm_t *gm, uint8_t msgType, uint16_t msgLen, uint16_t seqId, uint8_t control)
{
    uint8_t *e = buf;
    uint8_t *h = &buf[ETH_HEADER_LEN];

    /* Ethernet header */
    (void)memcpy(&e[0], GPTP_MCAST_MAC, 6);
    (void)memcpy(&e[6], gm->srcMac, 6);
    WriteBE16(&e[12], PTP_ETHERTYPE);

    /* PTP common header (34 bytes) */
    (void)memset(h, 0, PTP_HEADER_LEN);
    h[0]  = (uint8_t)((PTP_TRANSPORT_SPECIFIC << 4) | (msgType & 0x0Fu));
    h[1]  = PTP_VERSION;
    WriteBE16(&h[2], msgLen);
    h[4]  = GPTP_GM_DOMAIN_NUMBER;
    /* h[5] reserved = 0 */
    WriteBE16(&h[6], (PTP_MSGTYPE_SYNC == msgType) ? PTP_FLAG_TWO_STEP : 0x0000u);
    /* h[8..15] correctionField = 0; h[16..19] reserved = 0 */
    (void)memcpy(&h[20], gm->clockIdentity, 8); /* sourcePortIdentity.clockIdentity */
    WriteBE16(&h[28], 1u);                       /* sourcePortIdentity.portNumber = 1 */
    WriteBE16(&h[30], seqId);
    h[32] = control;
    h[33] = (uint8_t)GPTP_GM_LOG_SYNC_INTERVAL;  /* logMessageInterval */

    return (uint16_t)(ETH_HEADER_LEN + PTP_HEADER_LEN);
}

static void BuildSyncFrame(GptpGm_t *gm, uint16_t seqId)
{
    uint16_t off;
    (void)memset(gm->syncBuf, 0, sizeof(gm->syncBuf));
    off = BuildPtpHeader(gm->syncBuf, gm, PTP_MSGTYPE_SYNC, PTP_SYNC_MSG_LEN, seqId, PTP_CONTROL_SYNC);
    /* originTimestamp (10 bytes) left zero for two-step. Frame zero-padded to 60 bytes. */
    (void)off;
}

static void BuildFollowUpFrame(GptpGm_t *gm, uint16_t seqId, uint32_t seconds, uint32_t nanoseconds)
{
    uint16_t off;
    uint8_t *b;
    (void)memset(gm->followUpBuf, 0, sizeof(gm->followUpBuf));
    off = BuildPtpHeader(gm->followUpBuf, gm, PTP_MSGTYPE_FOLLOW_UP, PTP_FOLLOWUP_MSG_LEN, seqId, PTP_CONTROL_FOLLOW_UP);
    b = &gm->followUpBuf[off];

    /* preciseOriginTimestamp: 6-byte seconds (top 2 bytes zero) + 4-byte nanoseconds */
    b[0] = 0u;
    b[1] = 0u;
    WriteBE32(&b[2], seconds);
    WriteBE32(&b[6], nanoseconds);
    b += PTP_TIMESTAMP_LEN;

    /* Follow_Up information TLV (organizationExtension), 32 bytes total */
    WriteBE16(&b[0], 0x0003u); /* tlvType = ORGANIZATION_EXTENSION */
    WriteBE16(&b[2], 28u);     /* lengthField */
    b[4] = 0x00u; b[5] = 0x80u; b[6] = 0xC2u;       /* OUI 00-80-C2 (IEEE 802.1) */
    b[7] = 0x00u; b[8] = 0x00u; b[9] = 0x01u;       /* organizationSubType = 1 */
    /* cumulativeScaledRateOffset(4), gmTimeBaseIndicator(2),
       lastGmPhaseChange(12), scaledLastGmFreqChange(4) all zero (bytes 10..31). */
}

static void SendSync(GptpGm_t *gm)
{
    uint16_t seq = gm->sequenceId;
    uint8_t slot = gm->txSlot;

    BuildSyncFrame(gm, seq);
    if (TC6LwIP_SendRawEthernetPacket(gm->idx, gm->syncBuf, SYNC_FRAME_LEN, slot)) {
        gm->syncPending = true;
        gm->pendingSequenceId = seq;
        gm->pendingSlot = slot;
        gm->pendingSinceTick = TC6Stub_GetTick();
        gm->sequenceId++;
        gm->txSlot = (slot >= 3u) ? 1u : (uint8_t)(slot + 1u);
    }
    /* If enqueue failed, leave state unchanged; the next Service tick retries. */
}

bool gPTP_GM_Init(int8_t idx)
{
    bool success = false;
    if ((idx >= 0) && (idx < TC6_MAX_INSTANCES)) {
        GptpGm_t *gm = &m_gm[idx];
        uint8_t *macPtr = NULL;
        (void)memset(gm, 0, sizeof(*gm));
        gm->idx = idx;
        if (TC6LwIP_GetTimestampSupported(idx)) {
            TC6LwIP_GetMacAddress(idx, &macPtr); /* macPtr -> internal 6-byte MAC */
            if (NULL != macPtr) {
                (void)memcpy(gm->srcMac, macPtr, 6);
                BuildClockIdentity(gm->srcMac, gm->clockIdentity);
                gm->sequenceId = 0u;
                gm->txSlot = 1u;
                gm->syncPending = false;
                gm->nextSyncTick = TC6Stub_GetTick() + GPTP_GM_SYNC_INTERVAL_MS;
                gm->enabled = true;
                gm->initialized = true;
                success = true;
            }
        }
    }
    return success;
}

void gPTP_GM_Service(void)
{
    uint8_t i;
    uint32_t now = TC6Stub_GetTick();
    for (i = 0u; i < TC6_MAX_INSTANCES; i++) {
        GptpGm_t *gm = &m_gm[i];
        if (gm->initialized) {
            /* Watchdog: if the TX timestamp for an in-flight Sync never came
               back, release the pending state so sending can resume. */
            if (gm->syncPending && ((uint32_t)(now - gm->pendingSinceTick) >= GPTP_GM_TS_TIMEOUT_MS)) {
                gm->syncPending = false;
                gm->missedCount++;
            }
            if ((int32_t)(now - gm->nextSyncTick) >= 0) {
                /* Absolute rescheduling: advance the deadline from itself, not
                   from now, so per-cycle observation latency is absorbed and
                   the mean interval stays at GPTP_GM_SYNC_INTERVAL_MS instead
                   of drifting long. The (int32_t) subtraction is wrap-safe
                   across the 32-bit ms tick rollover. If we ever fall a full
                   interval behind (e.g. a long stall), re-snap to now so we
                   emit one Sync rather than bursting to catch up. */
                gm->nextSyncTick += GPTP_GM_SYNC_INTERVAL_MS;
                if ((int32_t)(now - gm->nextSyncTick) >= 0) {
                    gm->nextSyncTick = now + GPTP_GM_SYNC_INTERVAL_MS;
                }
                if (gm->enabled && !gm->syncPending) {
                    SendSync(gm);
                }
                /* If a Sync is still pending (timestamp not yet returned), skip
                   this cycle rather than overlap; the watchdog above and the
                   missed-timestamp path both clear a stuck pending state. */
            }
        }
    }
}

void gPTP_GM_OnTxTimestamp(int8_t idx, bool success, uint8_t tsc, uint64_t timestamp)
{
    if ((idx >= 0) && (idx < TC6_MAX_INSTANCES)) {
        GptpGm_t *gm = &m_gm[idx];
        if (gm->initialized && gm->syncPending && (tsc == gm->pendingSlot)) {
            gm->syncPending = false;
            if (success) {
                uint32_t seconds = (uint32_t)(timestamp >> 32);
                uint32_t nanos = (uint32_t)(timestamp & 0xFFFFFFFFu);
                BuildFollowUpFrame(gm, gm->pendingSequenceId, seconds, nanos);
                (void)TC6LwIP_SendRawEthernetPacket(idx, gm->followUpBuf, FOLLOWUP_FRAME_LEN, 0u);
            } else {
                gm->missedCount++; /* skip this Follow_Up, no retry */
            }
        }
    }
}

void gPTP_GM_SetEnabled(int8_t idx, bool enable)
{
    if ((idx >= 0) && (idx < TC6_MAX_INSTANCES)) {
        GptpGm_t *gm = &m_gm[idx];
        if (gm->initialized) {
            gm->enabled = enable;
        }
    }
}

bool gPTP_GM_IsEnabled(int8_t idx)
{
    bool enabled = false;
    if ((idx >= 0) && (idx < TC6_MAX_INSTANCES)) {
        GptpGm_t *gm = &m_gm[idx];
        enabled = (gm->initialized && gm->enabled);
    }
    return enabled;
}
