//DOM-IGNORE-BEGIN
/*
Copyright (C) 2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
//DOM-IGNORE-END
/*******************************************************************************
  Low Level Driver for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol

  Company:
    Microchip Technology Inc.

  File Name:
    tc6.c

  Summary:
    Low Level Driver TC6 SPI

  Description:
    This file provides the implementation of the OpenAlliance TC6 protocol
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "tc6-conf.h"
#include "tc6.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define TC6_MAGIC           (0x48423578ul)
#define TC6_CHUNKS_PER_ISR  (2u)

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                    INTERNAL DEFINES AND VARIABLES                    */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define FLD(bytePos, bitpos, width)  bytePos, bitpos, width

/*
 * TX Data Header: 32-bit SPI TX Data Chunk Command Header
 */


/* Data fields {{{ */

#define HDR_DNC   FLD(0u, 7u, 1u) /* Data, Not Control */
#define HDR_SEQ   FLD(0u, 6u, 1u) /* Data Chunk Sequence */
/*#define HDR_NORX FLD(0u, 5u, 1u)  No Receive */
/*#define HDR_VS  FLD(1u, 6u, 2u)    VS */
#define HDR_DV    FLD(1u, 5u, 1u) /* Data Valid */
#define HDR_SV    FLD(1u, 4u, 1u) /* Start of Frame Valid */
#define HDR_SWO   FLD(1u, 0, 4u) /* Start of Frame Word Offset */
#define HDR_EV    FLD(2u, 6u, 1u) /* End of Frame Valid */
#define HDR_EBO   FLD(2u, 0u, 6u) /* End of Frame Byte Offset */
#define HDR_TSC   FLD(3u, 6u, 2u) /* Transmit Frame Timestamp Capture */
#define HDR_P     FLD(3u, 0u, 1u) /* Header Parity Bit */

/* }}} */

/* Control Transaction fields {{{ */

#define HDR_C_DNC    FLD(0u, 7u, 1u) /* Data, Not Control */
/*#define HDR_C_HDRB FLD(0u, 6u, 1u)  TX Header Bad */
#define HDR_C_WNR    FLD(0u, 5u, 1u) /* Write, Not Read */
#define HDR_C_AID    FLD(0u, 4u, 1u) /* Address Increment Disable */
#define HDR_C_MMS    FLD(0u, 0u, 4u) /* Memory Map Selector */
#define HDR_C_ADDR_HI FLD(1u, 0u, 8u) /* Address Higher Byte */
#define HDR_C_ADDR_LO FLD(2u, 0u, 8u) /* Address Lower Byte */
#define HDR_C_LEN    FLD(3u, 1u, 7u) /* Length */
#define HDR_C_P      FLD(3u, 0u, 1u) /* Parity Bit */

/* }}} */

/*
 * RX Data Footer: 36-bit SPI RX Data Chunk Command Footer
 */

#define FTR_EXST     FLD(0u, 7u, 1u) /* Extended Status */
#define FTR_HDRB     FLD(0u, 6u, 1u) /* TX Header Bad */
#define FTR_SYNC     FLD(0u, 5u, 1u) /* Configuration Synchronized */
#define FTR_RCA      FLD(0u, 0u, 5u) /* Receive Chunks Available */
/*#define FTR_VS     FLD(1u, 6u, 2u)    Vendor Specific */
#define FTR_DV       FLD(1u, 5u, 1u) /* Data Valid */
#define FTR_SV       FLD(1u, 4u, 1u) /* Start of Frame Valid */
#define FTR_SWO      FLD(1u, 0u, 4u) /* Start of Frame Word Offset */
#define FTR_FD       FLD(2u, 7u, 1u) /* Frame Drop */
#define FTR_EV       FLD(2u, 6u, 1u) /* End of Frame Valid */
#define FTR_EBO      FLD(2u, 0u, 6u) /* End of Frame Byte Offset */
#define FTR_RTSA     FLD(3u, 7u, 1u) /* Receive Frame Timestamp Added */
#define FTR_RTSP     FLD(3u, 6u, 1u) /* Receive Frame Timestamp Parity */
#define FTR_TXC      FLD(3u, 1u, 5u) /* Transmit Credits */
/*#define FTR_P      FLD(3u, 0u, 1u)    Footer Parity Bit */

static const uint8_t MASK[9] = { 0x00u, 0x01u, 0x03u, 0x07u, 0x0Fu, 0x1Fu, 0x3Fu, 0x7Fu, 0xFFu };

/** Integrator needs to allocate this structure. But the elements must not be accessed.
 *  They are getting filled via function calls only.
 */
struct TC6_t
{
    uint8_t bufMOSI[TC6_CHUNKS_XACT * TC6_CHUNK_BUF_SIZE];
    uint8_t bufMISO[TC6_CHUNKS_XACT * TC6_CHUNK_BUF_SIZE];
    void *gTag;
    uint64_t ts;
    uint32_t magic;
    uint16_t buf_len;
    uint16_t offsetRx;
    uint8_t instance;
    uint8_t seq_num;
    uint8_t txc;
    uint8_t rca;
    bool enableData;
    bool synced;
    bool exst_locked;
    bool eth_started;
    bool eth_error;
};

static struct TC6_t m_tc6[TC6_MAX_INSTANCES];
static volatile bool m_tc6Valid[TC6_MAX_INSTANCES] = { 0 };

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static inline uint8_t GET_VAL(uint8_t bytePos, uint8_t bitpos, uint8_t width, const uint8_t pIn[4]);
static inline void SET_VAL(uint8_t bytePos, uint8_t bitpos, uint8_t width, uint8_t val, uint8_t pOut[4]);
static inline void CLEAR_HEADER(uint8_t pOut[4]);
static bool accessRegisters(TC6_t *g, MemoryOp_t op, uint32_t addr, uint32_t *value,
                            bool secure, uint32_t modifyMask);

static uint8_t get_parity(const uint8_t *pVal);
static void addEmptyChunks(TC6_t *g, uint16_t chunkCnt);
static bool spiDataTransaction(TC6_t *g, uint16_t chunkCnt);
static void waitForTXC(TC6_t *g, uint16_t waitLen);

/* Protocol Implementation */
static uint16_t mk_ctrl_req(bool wnr, bool aid, uint32_t addr, uint8_t num_regs, const uint32_t *regs, uint8_t *buff, uint16_t size_of_buff);
static uint16_t mk_secure_ctrl_req(bool wnr, bool aid, uint32_t addr, uint8_t num_regs, const uint32_t *regs, uint8_t *buff, uint16_t size_of_buff);
static uint16_t read_rx_ctrl_buffer(const uint8_t *rx_buf, uint16_t rx_buf_size, uint32_t *regs_buf, uint8_t regs_buf_size, bool secure);
static bool pollRxData(TC6_t *g, bool forceEmpty);
static void parseRxData(TC6_t *g, const uint8_t *buff, uint16_t buf_len);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

TC6_t *TC6_Init(void *pGlobalTag)
{
    uint8_t i;
    struct TC6_t *g = NULL;
    for (i = 0; i < TC6_MAX_INSTANCES; i++) {
        if (!m_tc6Valid[i]) {
            /* Setup memory */
            m_tc6Valid[i] = true;
            g = &m_tc6[i];
            (void)memset(g, 0, sizeof(TC6_t));
            g->instance = i;
            g->magic = TC6_MAGIC;
            g->txc = 24;
            g->gTag = pGlobalTag;
            break;
        }
    }
    if (!g) {
        TC6_ASSERT(false);
    }
    return g;
}

bool TC6_HandleMacPhyInterrupt(uint8_t tc6instance)
{
    bool success = false;
    if (tc6instance < TC6_MAX_INSTANCES) {
        TC6_t *g = &m_tc6[tc6instance];
        success = pollRxData(g, true);
    }
    return success;
}

void TC6_Destroy(TC6_t *g)
{
    uint8_t i;
    TC6_CB_OnIntPinInterruptEnable(g->instance, false);
    for (i = 0; i < TC6_MAX_INSTANCES; i++) {
        if (g == &m_tc6[i]) {
            m_tc6Valid[i] = false;
            break;
        }
    }
    TC6_CB_OnIntPinInterruptEnable(g->instance, true);
}

void TC6_Reset(TC6_t *g)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));

    TC6_CB_OnIntPinInterruptEnable(g->instance, false);
    /* Set protocol defaults */
    g->txc = 24u;
    g->enableData = false;
    g->synced = false;
    TC6_CB_OnIntPinInterruptEnable(g->instance, true);
}

void TC6_EnableData(TC6_t *g, bool enable)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    g->enableData = enable;
    if (g->enableData) {
        pollRxData(g, true);
    }
}

uint8_t TC6_GetInstance(TC6_t *g)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    return g ? g->instance : 0xFFu;
}

void TC6_GetState(TC6_t *g, uint8_t *pTxCredit, uint8_t *pRxCredit, bool *pSynced)
{
   TC6_ASSERT(g && (TC6_MAGIC == g->magic));
   TC6_CB_OnIntPinInterruptEnable(g->instance, false);
   if (NULL != pTxCredit) {
      *pTxCredit = g->txc;
   }
   if (NULL != pRxCredit) {
      *pRxCredit = g->rca;
   }
   if (NULL != pSynced) {
      *pSynced = g->synced;
   }
   TC6_CB_OnIntPinInterruptEnable(g->instance, true);
}

bool TC6_SendRawEthernetSegments(TC6_t *g, const TC6_RawTxSegment *pSegments, uint8_t segmentCount, uint16_t totalLen, uint8_t tsc)
{
    bool success = true;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    TC6_CB_OnIntPinInterruptEnable(g->instance, false);
    if (!g || !pSegments || !segmentCount || !totalLen) {
        TC6_ASSERT(false);
        success = false;
    }
    if (success && g->enableData) {
        uint16_t i;
        uint16_t chunks = (totalLen / TC6_CHUNK_SIZE);
        uint16_t segCurr = 0u;
        uint16_t segOffset = 0u;
        uint16_t offsetEth = 0u;
        if (totalLen % TC6_CHUNK_SIZE) {
            chunks++;
        }
        if (chunks > TC6_CHUNKS_XACT) {
            chunks = TC6_CHUNKS_XACT;
        }
        waitForTXC(g, totalLen);
        for (i = 0u; i < chunks; i++) {
            uint16_t copyPos = 0u;
            uint16_t toCopyLen;
            uint16_t paddedLen;
            uint8_t *pSpi = &g->bufMOSI[i * TC6_CHUNK_BUF_SIZE];
            CLEAR_HEADER(pSpi);
            SET_VAL(HDR_DNC, 1u, pSpi);
            SET_VAL(HDR_DV, 1u, pSpi);
            if (0u == i) {
                SET_VAL(HDR_SV, 1u, pSpi);
                SET_VAL(HDR_TSC, tsc, pSpi);
            }
            toCopyLen = (totalLen - offsetEth);
            toCopyLen = (toCopyLen <= TC6_CHUNK_SIZE) ? toCopyLen : TC6_CHUNK_SIZE;
            paddedLen = TC6_CHUNK_SIZE - toCopyLen;
            while(copyPos < toCopyLen) {
                const uint8_t *pEth = &pSegments[segCurr].pEth[segOffset];
                uint16_t len = pSegments[segCurr].segLen - segOffset;
                uint16_t diff = (toCopyLen - copyPos);
                if (len > diff) {
                    len = diff;
                }
                (void)memcpy(&pSpi[TC6_HEADER_SIZE + copyPos], pEth, len);
                copyPos += len;
                segOffset += len;
                TC6_ASSERT(segOffset <= pSegments[segCurr].segLen);
                if (segOffset == pSegments[segCurr].segLen) {
                    segOffset = 0;
                    segCurr++;
                    TC6_ASSERT(segCurr <= segmentCount);
                }
            }
            TC6_ASSERT(copyPos == toCopyLen);
            if (0u != paddedLen) {
                (void)memset(&pSpi[TC6_HEADER_SIZE + toCopyLen], 0x0u, paddedLen);
            }
            offsetEth += toCopyLen;
            TC6_ASSERT(offsetEth <= totalLen);
            if (offsetEth == totalLen) {
                SET_VAL(HDR_EV, 1u, pSpi);
                SET_VAL(HDR_EBO, (uint8_t)(toCopyLen - 1u), pSpi);
            }
            SET_VAL(HDR_P, get_parity(pSpi), pSpi);
        }
        while(!spiDataTransaction(g, chunks));
        pollRxData(g, false);
        success = true;
    } else {
        success = false;
    }
    TC6_CB_OnIntPinInterruptEnable(g->instance, true);
    return success;
}

bool TC6_SendRawEthernetPacket(TC6_t *g, const uint8_t *pTx, uint16_t len, uint8_t tsc)
{
    bool success = false;
    if (g && pTx && len) {
        TC6_RawTxSegment seg;
        seg.segLen = len;
        seg.pEth = pTx;
        success = TC6_SendRawEthernetSegments(g, &seg, 1, len, tsc);
    }
    return success;
}

bool TC6_ReadRegister(TC6_t *g, uint32_t addr, uint32_t *value, bool secure)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    return accessRegisters(g, MemOp_Read, addr
        , value
        , secure
        , 0    /* mask */);
}

bool TC6_WriteRegister(TC6_t *g, uint32_t addr, uint32_t value, bool secure)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    return accessRegisters(g, MemOp_Write, addr
        , &value
        , secure
        , 0    /* mask */);
}

bool TC6_ReadModifyWriteRegister(TC6_t *g, uint32_t addr, uint32_t value, uint32_t mask, bool secure)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    return accessRegisters(g, MemOp_ReadModifyWrite, addr
        , &value
        , secure
        , mask);
}

uint16_t TC6_MultipleRegisterAccess(TC6_t *g, const MemoryMap_t *pMap, uint16_t mapLength)
{
    uint16_t i = 0;
    uint16_t t = 0;
    bool full = false;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    for (; (i < mapLength) && !full; i++) {
        uint32_t value = pMap[i].value;
        if (accessRegisters(g, pMap[i].op, pMap[i].address, &value, pMap[i].secure, pMap[i].mask)) {
            t++;
        } else {
            full = true;
        }
    }
    return t;
}

void TC6_UnlockExtendedStatus(TC6_t *g)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    g->exst_locked = false;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  PRIVATE FUNCTION IMPLEMENTATIONS                    */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static inline uint8_t GET_VAL(uint8_t bytePos, uint8_t bitpos, uint8_t width, const uint8_t pIn[4])
{
    TC6_ASSERT(NULL != pIn);
    TC6_ASSERT(bytePos < 4u);
    TC6_ASSERT(bitpos < 8u);
    TC6_ASSERT(width != 0u);
    TC6_ASSERT(width <= 8u);
    uint8_t val = (pIn[bytePos] >> bitpos) & MASK[width];
    return val;
}

static inline void SET_VAL(uint8_t bytePos, uint8_t bitpos, uint8_t width, uint8_t val, uint8_t pOut[4])
{
    TC6_ASSERT(NULL != pOut);
    TC6_ASSERT(bytePos < 4u);
    TC6_ASSERT(bitpos < 8u);
    TC6_ASSERT(width != 0u);
    TC6_ASSERT(width <= 8u);
    pOut[bytePos] |= (val & MASK[width]) << bitpos;
}

static inline void CLEAR_HEADER(uint8_t pOut[4])
{
    (void)memset(pOut, 0u, 4u);
}

static bool accessRegisters(TC6_t *g, MemoryOp_t op, uint32_t addr, uint32_t *value, bool secure, uint32_t modifyMask)
{
    uint32_t regVal = 0xFFFFFFFFu;
    uint16_t payloadSize = 0;
    bool success = false;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    TC6_ASSERT(op <= MemOp_Read);

    TC6_CB_OnIntPinInterruptEnable(g->instance, false);
    if (secure) {
        payloadSize = mk_secure_ctrl_req((MemOp_Write == op), false /* autoIncrement */, addr, 1 /* Array Len */, value, g->bufMOSI, sizeof(g->bufMOSI));
    } else {
        payloadSize = mk_ctrl_req((MemOp_Write == op), false /* autoIncrement */, addr, 1 /* Array Len */, value, g->bufMOSI, sizeof(g->bufMOSI));
    }
    if (0u != payloadSize) {
        success = TC6_CB_OnSpiTransaction(g->instance, g->bufMOSI, g->bufMISO, payloadSize, g->gTag);
        if (success) {
            uint16_t num = read_rx_ctrl_buffer(g->bufMISO, payloadSize, &regVal, sizeof(regVal), secure);
            success = (0u != num);
        }
    } else {
        TC6_CB_OnError(g, TC6Error_ControlTxFail, g->gTag);
        TC6_ASSERT(false);
    }
    if (success) {
        if (MemOp_Read == op) {
            *value = regVal;
        }
        else if (MemOp_ReadModifyWrite == op) {
            uint32_t newVal = (regVal & ~modifyMask) | *value;
            /* recursive call to do the final write */
            success = accessRegisters(g, MemOp_Write, addr, &newVal, secure, modifyMask);
        }
    }
    TC6_CB_OnIntPinInterruptEnable(g->instance, true);
    return success;
}


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*              CALLBACK FUNCTION FROM PROTOCOL STATEMACHINE            */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void on_rx_slice(TC6_t *g, const uint8_t *pBuf, uint16_t offset, uint16_t bufLen, bool rtsa, bool rtsp)
{
    const uint8_t *buff = pBuf; /* Because of MISRA warning */
    uint16_t buf_len = bufLen;  /* Because of MISRA warning */
    /* TODO: handle timestamp (RTSP) */
    (void)rtsp;

    if (offset == 0u) {
        g->buf_len = 0;
        g->ts = 0;
    }

    /* handle timestamp (RTSA) */
    /* ToDo: get timestamp according to selected timestamp length (32bit or 64bit) */
    if (rtsa) {
        g->ts = ((uint64_t)buff[0] << 56) |
                ((uint64_t)buff[1] << 48) |
                ((uint64_t)buff[2] << 40) |
                ((uint64_t)buff[3] << 32) |
                ((uint64_t)buff[4] << 24) |
                ((uint64_t)buff[5] << 16) |
                ((uint64_t)buff[6] << 8)  |
                ((uint64_t)buff[7]);

        buff = &buff[8];
        buf_len -= 8u;
    }

    g->buf_len += buf_len;
    TC6_CB_OnRxEthernetSlice(g, buff, offset, buf_len, g->gTag);
}

static void on_rx_done(TC6_t *g, uint16_t buf_len, bool mfd)
{
    bool success = !mfd && !g->eth_error;
    (void)buf_len;
    g->eth_error = false;
    if (success) {
        uint64_t *pTS = (0u != g->ts) ? &g->ts : NULL;
        TC6_CB_OnRxEthernetPacket(g, true, g->buf_len, pTS, g->gTag);
    } else {
        TC6_CB_OnRxEthernetPacket(g, false, 0, NULL, g->gTag);
    }
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PROTOCOL STATEMACHINE                        */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static inline void value2net(uint32_t value, uint8_t *buf)
{
    buf[0] = (uint8_t)(value >> 24);
    buf[1] = (uint8_t)(value >> 16);
    buf[2] = (uint8_t)(value >> 8);
    buf[3] = (uint8_t)value;
}

static inline uint32_t net2value(const uint8_t *buf)
{
    return ((uint32_t)buf[0] << 24) | ((uint32_t)buf[1] << 16) | ((uint32_t)buf[2] << 8) | ((uint32_t)buf[3]);
}

static uint8_t get_parity(const uint8_t *pVal)
{
    uint8_t val = 0u;

#if UINT_MAX == UINT32_MAX
    /* 32 Bit machine */
    uint32_t v = *((const uint32_t *)pVal);
    v ^= v >> 16;
    v ^= v >> 8;
    v ^= v >> 4;
    v ^= v >> 2;
    v ^= v >> 1;

    val =  ~v & 1u; /* odd parity */
#else
    /* 16 Bit machine */
    uint16_t h = *((const uint16_t*)&pVal[0]);
    uint16_t l = *((const uint16_t*)&pVal[2]);
    h ^= h >> 8;
    h ^= h >> 4;
    h ^= h >> 2;
    h ^= h >> 1;

    l ^= l >> 8;
    l ^= l >> 4;
    l ^= l >> 2;
    l ^= l >> 1;

    val =  ~(h ^ l) & 1u;
#endif

    return val;
}

static void addEmptyChunks(TC6_t *g, uint16_t chunkCnt)
{
    uint16_t i;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic) && chunkCnt);
    for (i = 0; (i < chunkCnt) && (i < TC6_CHUNKS_XACT); i++) {
        uint8_t *p = &g->bufMOSI[i * TC6_CHUNK_BUF_SIZE];
        p[0] = 0x80u;
        p[1] = 0x0u;
        p[2] = 0x0u;
        p[3] = 0x0u;
        (void)memset(&p[4], 0x00, TC6_CHUNK_SIZE);
    }
}

static bool spiDataTransaction(TC6_t *g, uint16_t chunkCnt)
{
    uint16_t bufLen = (chunkCnt * TC6_CHUNK_BUF_SIZE);
    bool success = false;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic) && chunkCnt);;
    success = TC6_CB_OnSpiTransaction(g->instance, g->bufMOSI, g->bufMISO, bufLen, g->gTag);
    TC6_ASSERT(TC6_MAGIC == g->magic);
    if (success) {
        parseRxData(g, g->bufMISO, bufLen);
    }
    return success;
}

static void waitForTXC(TC6_t *g, uint16_t waitLen)
{
    uint16_t waitChunks = (waitLen / TC6_CHUNK_SIZE);
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    if (waitLen % TC6_CHUNK_SIZE) {
        waitChunks++;
    }
    while (waitChunks > g->txc) {
        addEmptyChunks(g, 1u);
        while(!spiDataTransaction(g, 1));
    }
}

/* Control Transaction API {{{ */

/*
 * The functions below create regular or secure control transaction buffer
 * ready for an SPI Tx transfer.  The register values for the 'write' operation
 * are taken from the 'tx_buf'.  The content for the SPI transfer is generated
 * into the 'tx_buf'.
 *
 * @wnr: Write, not read.
 * @aid: Disable address increment.
 * @addr:
 *     Upper 16 bit: Memory map selector (MMS).
 *     Lower 16 bit: Address.
 * @num_regs: Number of registers to read or write.
 * @tx_buf: Buffer for SPI Tx transfer.
 *     If operation is 'write', then the first 'num_regs' elements of the
 *     'tx_buf' must contain values to write.
 * @tx_buf_size: size of the 'tx_buf' in bytes.
 *
 * Returns number of the 'tx_buf' bytes to be sent using the SPI Tx transfer.
 * In case of error the function returns 0 and the buffer remains unchanged.
 *
 * SECURITY NOTE:
 *
 * The places for turn-around- or other gaps in the 'tx_buf' are kept
 * unchanged.  If needed, the application must clean up the buffer before
 * transfer it to the function.
 */

static uint16_t mk_ctrl_req(bool wnr, bool aid, uint32_t addr,
        uint8_t num_regs, const uint32_t *regs,
        uint8_t *tx_buf, uint16_t tx_buf_size)
{
    bool success = true;

    if ((num_regs < 1u) || (num_regs > 128u)) {
        success = false;
    }

    if ((num_regs + 2u) > (tx_buf_size / 4u)) {
        success = false;
    }

    if (success) {
        if (wnr) {
            uint8_t *dst = tx_buf;
            uint16_t i;

            dst = &dst[num_regs * 4u];
            for (i = num_regs; i > 0u; i--) {
                uint32_t v = regs[i - 1u];

                value2net(v, dst);
                dst = &dst[-4];
            }
        }

        CLEAR_HEADER(tx_buf);
        SET_VAL(HDR_C_DNC, 0, tx_buf);
        SET_VAL(HDR_C_WNR, wnr, tx_buf);
        SET_VAL(HDR_C_AID, aid, tx_buf);
        SET_VAL(HDR_C_MMS, (uint8_t)(addr >> 16), tx_buf);
        SET_VAL(HDR_C_ADDR_HI, (uint8_t)(addr >> 8), tx_buf);
        SET_VAL(HDR_C_ADDR_LO, (uint8_t)addr, tx_buf);
        SET_VAL(HDR_C_LEN, (num_regs - 1u), tx_buf);
        SET_VAL(HDR_C_P, get_parity(tx_buf), tx_buf);
    }
    return success ? ((num_regs * 4u) + 8u) : 0u;
}

static uint16_t mk_secure_ctrl_req(bool wnr, bool aid, uint32_t addr,
        uint8_t num_regs, const uint32_t *regs,
        uint8_t *tx_buf, uint16_t tx_buf_size)
{
    bool success = true;

    if ((num_regs < 1u) || (num_regs > 128u)) {
        success = false;
    }

    if (success && (((num_regs * 2u) + 2u) > (tx_buf_size / 4u))) {
        success = false;
    }

    if (success) {
        if (wnr) {
            uint16_t i;
            uint8_t *dst = tx_buf;

            dst = &dst[num_regs * 8u];
            for (i = num_regs; i > 0u; i--) {
                uint32_t v = regs[i - 1u];

                value2net(~v, dst);
                value2net(v, &dst[-4]);
                dst = &dst[-8];
            }
        }

        CLEAR_HEADER(tx_buf);
        SET_VAL(HDR_C_DNC, 0, tx_buf);
        SET_VAL(HDR_C_WNR, wnr, tx_buf);
        SET_VAL(HDR_C_AID, aid, tx_buf);
        SET_VAL(HDR_C_MMS, (uint8_t)(addr >> 16), tx_buf);
        SET_VAL(HDR_C_ADDR_HI, (uint8_t)(addr >> 8), tx_buf);
        SET_VAL(HDR_C_ADDR_LO, (uint8_t)addr, tx_buf);
        SET_VAL(HDR_C_LEN, (num_regs - 1u), tx_buf);
        SET_VAL(HDR_C_P, get_parity(tx_buf), tx_buf);
    }
    return success ? ((num_regs * 8u) + 8u) : 0u;
}

static uint16_t read_rx_ctrl_buffer(const uint8_t *rx_buf, uint16_t rx_buf_size,
        uint32_t *regs_buf, uint8_t regs_buf_size, bool secure)
{
    uint16_t i;
    uint16_t num = 0;
    const uint8_t *src;

    if (secure) {
        if ((0u == (rx_buf_size % 8u)) && ((rx_buf_size / 8u) >= 2u)) {
            num = (rx_buf_size / 8u) - 1u;
            if ((regs_buf_size / 4u) < num) {
                num = 0;
            }
        }

        src = rx_buf;
        for (i = 0; i < num; i++) {
            uint32_t normal;
            uint32_t inverted;
            src = &src[8];
            normal = net2value(src);
            inverted = ~net2value(&src[4]);
            if (normal != inverted) {
                num = 0;
            }
        }
        src = rx_buf;
        for (i = 0; i < num; i++) {
            src = &src[8];
            regs_buf[i] = net2value(src);
        }
    } else {
        num = (rx_buf_size - 8u) / 4u;
        if ((regs_buf_size / 4u) < num) {
            num = 0;
        } else {
            src = &rx_buf[8];
            for (i = 0; i < num; i++) {
                regs_buf[i] = net2value(src);
                src = &src[4];
            }
        }
    }
    return num;
}

/* }}} */

/* Rx API {{{ */

static inline void signal_rx_error(TC6_t *g, TC6_Error_t err)
{
    g->eth_error = true;
    g->eth_started = false;
    g->offsetRx = 0;
    TC6_CB_OnError(g, err, g->gTag);
}

static inline void process_rx(TC6_t *g, const uint8_t *buff, uint16_t buf_len)
{
    const uint8_t *fptr = &buff[buf_len - TC6_HEADER_SIZE];

    if (GET_VAL(FTR_SV, fptr) ||
        GET_VAL(FTR_DV, fptr) ||
        GET_VAL(FTR_EV, fptr))
    {
        uint16_t len;
        uint8_t sv;
        uint8_t ev;
        uint8_t rtsa = 0;
        uint8_t rtsp = 0;
        uint8_t mfd;
        uint8_t sbo;
        uint8_t ebo;
        bool twoFrames;
        bool success = true;

        sv = GET_VAL(FTR_SV, fptr);
        sbo = sv ? (GET_VAL(FTR_SWO, fptr) * 4u) : 0u;

        ev = GET_VAL(FTR_EV, fptr);
        ebo = ev ? (GET_VAL(FTR_EBO, fptr) + 1u) : TC6_CHUNK_SIZE;

        mfd = GET_VAL(FTR_FD, fptr);
        twoFrames = (ebo <= sbo);

        if (twoFrames) {
            /* Two ETH frames in chunk */
            on_rx_slice(g, buff, g->offsetRx, (uint16_t)ebo, rtsa, rtsp);
            on_rx_done(g, (uint16_t)(g->offsetRx + ebo), mfd);
            g->offsetRx = 0;
            len = (uint16_t)(TC6_CHUNK_SIZE - sbo);
        } else {
            /* Single Eth frame in chunk */
            len = ((uint16_t)ebo - (uint16_t)sbo);
        }

        if (!twoFrames && sv && g->eth_started) {
            signal_rx_error(g, TC6Error_UnexpectedSv);
            success = false;
        }

        if (success && !g->eth_started && !g->eth_error && !sv) {
            signal_rx_error(g, TC6Error_UnexpectedDvEv);
            success = false;
        }

        if ((!sv || twoFrames) && g->eth_error) {
            /* Wait for next start valid flag to clear error flag */
            success = false;
        }

        if (success) {
            if (0u != sv) {
                rtsa = GET_VAL(FTR_RTSA, fptr);
                rtsp = GET_VAL(FTR_RTSP, fptr);
            }

            g->eth_started = true;
            g->eth_error = false;
            on_rx_slice(g, &buff[sbo], g->offsetRx, len, rtsa, rtsp);

            /* ToDo: adjust length according to length of timestamp (32bit or 64bit) */
            if (0u != rtsa) {
                len -= 8u;
            }

            if (!twoFrames && ev) {
                uint16_t offset = g->offsetRx;
                g->eth_started = false;
                g->offsetRx = 0;
                on_rx_done(g, offset + len, mfd);
            } else {
                g->offsetRx += len;
            }
        }
    } else {
        g->eth_error = false;
    }
}

static bool pollRxData(TC6_t *g, bool forceEmpty)
{
    bool success = false;
    if ((TC6_MAGIC == g->magic) && (g->enableData)) {
        uint8_t rca = (forceEmpty ? TC6_CHUNKS_PER_ISR : g->rca);
        while (0u != rca) {
            if (rca > TC6_CHUNKS_XACT) {
                rca = TC6_CHUNKS_XACT;
            }
            addEmptyChunks(g, rca);
            while (!spiDataTransaction(g, rca));
            rca = g->rca;
        }
        success = true;
    }
    return success;
}

static void parseRxData(TC6_t *g, const uint8_t *buff, uint16_t buf_len)
{
    uint32_t processed;
    bool success = true;
    if (!buf_len || (buf_len % TC6_CHUNK_BUF_SIZE)) {
        TC6_ASSERT(false); /* integration error */
        success = false;
    }
    for (processed = 0; success && (processed < buf_len); processed += TC6_CHUNK_BUF_SIZE) {
        const uint8_t *pFooter = &buff[processed + TC6_CHUNK_SIZE];

        if (((0x0u == pFooter[0]) && (0x0u == pFooter[1]) && (0x0u == pFooter[2]) && (0x0u == pFooter[3])) ||
            ((0xFFu == pFooter[0]) && (0xFFu == pFooter[1]) && (0xFFu == pFooter[2]) && (0xFFu == pFooter[3])))
        {
            signal_rx_error(g, TC6Error_NoHardware);
            success = false;
        }
        if (success && get_parity(pFooter)) {
            signal_rx_error(g, TC6Error_BadChecksum);
            success = false;
        }
        if (success && GET_VAL(FTR_HDRB, pFooter)) {
            signal_rx_error(g, TC6Error_BadTxData);
            success = false;
        }
        g->synced = GET_VAL(FTR_SYNC, pFooter);
        if (success && !g->synced) {
            signal_rx_error(g, TC6Error_SyncLost);
            success = false;
        }
        if (success && GET_VAL(FTR_FD, pFooter)) {
            TC6_CB_OnRxEthernetPacket(g, false, 0, NULL, g->gTag);
            success = false;
        }
        if (success) {
            g->txc = GET_VAL(FTR_TXC, pFooter);
            g->rca = GET_VAL(FTR_RCA, pFooter);
            process_rx(g, &buff[processed], TC6_CHUNK_BUF_SIZE);
            if (!g->exst_locked) {
                if (0u != GET_VAL(FTR_EXST, pFooter)) {
                    g->exst_locked = true;
                    TC6_CB_OnExtendedStatus(g, g->gTag);
                }
            }
        } else {
            g->offsetRx = 0;
            g->eth_error = false;
        }
    }
}

/* }}} */
