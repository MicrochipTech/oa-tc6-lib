//DOM-IGNORE-BEGIN
/*
Copyright (C) 2025, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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
  lwIP Interface Driver for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol

  Company:
    Microchip Technology Inc.

  File Name:
    tc6-lwip.c

  Summary:
    lwIP Interface Driver for 10BASE-T1S MAC PHY

  Description:
    This file acts as a bridge between the TC6 library and the lwIP TCP/IP stack
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/ip_addr.h"
#include "lwip/etharp.h"
#include "lwip/opt.h"
#include "lwip/stats.h"
#include "lwip/timeouts.h"
#include "netif/ethernet.h"
#include "tc6-conf.h"
#include "tc6-regs.h"
#include "tc6.h"
#include "tc6-stub.h"
#include "tc6-lwip.h"
#include "mcc_generated_files/system/pins.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define PRINT(...)              (void)printf(__VA_ARGS__)

#define LWIP_TC6_MAGIC          (0x47392741u)
#define PRINT_RATE_TIMEOUT      (1000u)
#define PRINT_RATE_THRESHOLD    (5u)

#ifdef DEBUG
#define ASSERT(x)               __conditional_software_breakpoint(x)
#else
#define ASSERT(x)
#endif

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define ESC_RESETCOLOR              "\033[0m"
#define ESC_GREEN                   "\033[0;32m"
#define ESC_RED                     "\033[0;31m"
#define ESC_YELLOW                  "\033[1;33m"
#define ESC_BLUE                    "\033[0;36m"


typedef struct
{
    TC6_t *tc6;
    struct pbuf *pbuf;
    TC6LwIP_On_PlcaStatus pStatusCallback;
    uint16_t rxLen;
    bool rxInvalid;
    bool tc6NeedService;
    bool resetComplete;
} TC6Lib_t;

typedef struct
{
    char ipAddr[16];
    struct netif netint;
    uint8_t mac[6];
} LwIp_t;

typedef struct
{
    TC6Lib_t tc;
    LwIp_t ip;
    uint32_t magic;
    int8_t idx;
} TC6LwIP_t;

static TC6LwIP_t mlw[TC6_MAX_INSTANCES];

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static bool FilterRxEthernetPacket(uint16_t ethType);
static TC6LwIP_t *GetContextNetif(struct netif *intf);
static TC6LwIP_t *GetContextTC6(TC6_t *pTC6);

static void OnPlcaStatus(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  CALLBACK FUNCTIONS FROM TCP/IP STACK                */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static err_t lwIpInit(struct netif *netif);
static err_t lwIpOut(struct netif *netif, struct pbuf *p);
static void OnRawTx(TC6_t *pInst, const uint8_t *pTx, uint16_t len, void *pTag, void *pGlobalTag);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

int8_t TC6LwIP_Init(const uint8_t ip[4], bool enablePlca, uint8_t nodeId, uint8_t nodeCount, uint8_t burstCount, uint8_t burstTimer, bool promiscuous, bool txCutThrough, bool rxCutThrough)
{
    TC6LwIP_t *lw = NULL;
    uint8_t i;
    ip_addr_t ipAddr;
    ip_addr_t nm;
    ip_addr_t gw;

    bool success = true;

    if (NULL == ip)
    {
        success = false;
    }

    if (true == success)
    {
        /* Search for empty entry */
        success = false;

        for (i = 0U; i < TC6_MAX_INSTANCES; i++)
        {
            if (LWIP_TC6_MAGIC != mlw[i].magic)
            {
                lw = &mlw[i];
                lw->idx = i;
                success = true;

                memset(lw, 0, sizeof(TC6LwIP_t));

                if (0U == i)
                {
                    /* Initialize lwIP stack only on the first call of this function */
                    lwip_init();
                }
                break;
            }
        }
    }

    if (true == success)
    {
        success = TC6Stub_Init(lw->idx, lw->ip.mac);
    }

    if (true == success)
    {
        lw->tc.tc6 = TC6_Init(lw);
        success = (NULL != lw->tc.tc6);
    }

    if (true == success)
    {
        lw->tc.resetComplete = false;
        success = TC6Regs_Init(lw->tc.tc6, lw, lw->ip.mac, enablePlca, nodeId, nodeCount, burstCount, burstTimer, promiscuous, txCutThrough, rxCutThrough);
    }

    if (true == success)
    {
        uint8_t *mac = lw->ip.mac;

        /* Wait for register init and reset completion before proceeding */
        while((false == TC6Regs_GetInitDone(lw->tc.tc6)) || (false == TC6_CB_ResetComplete(lw->idx)))
        {
            TC6_Service(lw->tc.tc6, true);
        }

        lw->magic = LWIP_TC6_MAGIC;
        (void)snprintf(lw->ip.ipAddr, sizeof(lw->ip.ipAddr), "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);

        /* Setup lwIP interface */
#if TC6LwIP_DHCP
        ip_addr_set_zero(&ip);
        ip_addr_set_zero(&nm);
        ip_addr_set_zero(&gw);
        PRINT("LwIP-Init [MAC=%02X:%02X:%02X:%02X:%02X:%02X, DHCP, ChipRev=%d", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], TC6Regs_GetChipRevision(lw->tc.tc6));
#else
        ipaddr_aton(lw->ip.ipAddr, &ipAddr);
        ipaddr_aton(TC6LwIP_NETMASK, &nm);
        ipaddr_aton(TC6LwIP_GATEWAY, &gw);
        PRINT("LwIP-Init [MAC=%02X:%02X:%02X:%02X:%02X:%02X, IP='%s', ChipRev=%d", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], lw->ip.ipAddr, TC6Regs_GetChipRevision(lw->tc.tc6));
#endif
        if (enablePlca)
        {
            PRINT(", PLCA-NodeId=%d]\r\n", nodeId);
        } else
        {
            PRINT(", CSMA/CD]\r\n");
        }

        if (!netif_add(&lw->ip.netint, &ipAddr, &nm, &gw, lw, lwIpInit, ethernet_input))
        {
            TC6_ASSERT(false);
            PRINT("Could not add TC6 interface to lwIP!\r\n");
            success = false;
        }

        if (success)
        {
            netif_set_link_up(&lw->ip.netint);
        }
    }

    return ((true == success) ? lw->idx : -1);
}

void TC6LwIP_Service(void)
{
    uint8_t idx;

    TC6Regs_CheckTimers();

    sys_check_timeouts(); /* LWIP timers - ARP, DHCP, TCP, etc. */

    for (idx = 0; idx < TC6_MAX_INSTANCES; idx++)
    {
        TC6LwIP_t *lw = &mlw[idx];

        if (LWIP_TC6_MAGIC == lw->magic)
        {
            if (TC6Stub_IntActive(lw->idx))
            {
                if (true == TC6_Service(lw->tc.tc6, false))
                {
                    TC6Stub_ReleaseInt(lw->idx);
                }

            }
            else
            {
                if (true == lw->tc.tc6NeedService)
                {
                    lw->tc.tc6NeedService = false;
                    TC6_Service(lw->tc.tc6, true);
                }
            }
        }
    }
}

bool TC6LwIP_GetPlcaStatus(int8_t idx, TC6LwIP_On_PlcaStatus pStatusCallback)
{
    bool success = false;

    if ((idx < TC6_MAX_INSTANCES) && (NULL != pStatusCallback) )
    {
        TC6LwIP_t *lw = &mlw[idx];

        lw->tc.pStatusCallback = pStatusCallback;
        success = TC6_ReadRegister(lw->tc.tc6, 0x0004CA03, true, OnPlcaStatus, lw); /* PLCA_status_register.plca_status */
    }

    return success;
}

bool TC6LwIP_SendWouldBlock(int8_t idx)
{
    bool wouldBlock = false;

    if (idx < TC6_MAX_INSTANCES)
    {
        TC6LwIP_t *lw = &mlw[idx];
        TC6_RawTxSegment *dummySeg;
        uint8_t segCount;

        segCount = TC6_GetRawSegments(lw->tc.tc6, &dummySeg);
        wouldBlock = (0u == segCount);
    }

    return wouldBlock;
}

void TC6LwIP_GetMac(int8_t idx, uint8_t *mac[6])
{
    if (mac && (idx < TC6_MAX_INSTANCES))
    {
        TC6LwIP_t *lw = &mlw[idx];
        *mac = lw->ip.mac;
    }
}

struct netif *TC6LwIP_GetNetIf(int8_t idx)
{
    if (idx < TC6_MAX_INSTANCES) {
        TC6LwIP_t *lw = &mlw[idx];
        return &(lw->ip.netint);
    }

    return NULL;
}

bool TC6LwIP_SetPlca(int8_t idx, bool plcaEnable, uint8_t nodeId, uint8_t nodeCount)
{
    bool success = false;

    if (idx < TC6_MAX_INSTANCES)
    {
        TC6LwIP_t *lw = &mlw[idx];
        success = TC6Regs_SetPlca(lw->tc.tc6, plcaEnable, nodeId, nodeCount);
    }

    return success;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  PRIVATE FUNCTION IMPLEMENTATIONS                    */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static bool FilterRxEthernetPacket(uint16_t ethType)
{
    bool tcpStack = false;

    switch (ethType)
    {
        /* IPv4 */
        /* ARP */
        case ETHTYPE_IP:
        case ETHTYPE_ARP:
        {
            tcpStack = true;
        }
        break;

        default:
        break;
    }

    return tcpStack;
}


static TC6LwIP_t *GetContextNetif(struct netif *intf)
{
    TC6LwIP_t *lw = NULL;
    uint8_t i;

    for (i = 0U; i < TC6_MAX_INSTANCES; i++)
    {
        if (&mlw[i].ip.netint == intf)
        {
            lw = &mlw[i];
            break;
        }
    }

    return lw;
}

static TC6LwIP_t *GetContextTC6(TC6_t *pTC6)
{
    TC6LwIP_t *lw = NULL;
    uint8_t i;

    for (i = 0U; i < TC6_MAX_INSTANCES; i++)
    {
        if (mlw[i].tc.tc6 == pTC6)
        {
            lw = &mlw[i];
            break;
        }
    }

    return lw;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  CALLBACK FUNCTIONS FROM TCP/IP STACK                */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static err_t lwIpInit(struct netif *netif)
{
    TC6LwIP_t *lw = GetContextNetif(netif);

    TC6_ASSERT(netif && lw);
    TC6_ASSERT(LWIP_TC6_MAGIC == ((TC6LwIP_t*)netif->state)->magic);

    netif->output = etharp_output;
    netif->linkoutput = lwIpOut;
    netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_ETHERNET;
    netif->mtu = TC6LwIP_MTU;
    netif->hwaddr_len = ETHARP_HWADDR_LEN;

    (void)memcpy(netif->name, TC6LwIP_HOSTNAME, 2);
    (void)memcpy(netif->hwaddr, lw->ip.mac, NETIF_MAX_HWADDR_LEN);

    netif_set_up(netif);
    netif_set_default(netif);

    return ERR_OK;
}

static err_t lwIpOut(struct netif *netif, struct pbuf *p)
{
    TC6_RawTxSegment *txSeg = NULL;
    TC6LwIP_t *lw = GetContextNetif(netif);
    struct pbuf *pC = p;
    uint8_t maxSeg;
    err_t result;

    TC6_ASSERT(netif && p);
    TC6_ASSERT(LWIP_TC6_MAGIC == ((TC6LwIP_t*)netif->state)->magic);

    // Cannot send if the PHY is not ready.
    if (!TC6_CB_ResetComplete(0))
    {
        result = ERR_IF;
    }
    else
    {
        maxSeg = TC6_GetRawSegments(lw->tc.tc6, &txSeg);
        if (0U != maxSeg)
        {
            bool success;
            uint8_t seg = 0;

            pbuf_ref(p);

            while (seg < maxSeg)
            {
                txSeg[seg].pEth = (uint8_t *)pC->payload;
                txSeg[seg].segLen = pC->len;
                seg++;

                if (NULL != pC->next)
                {
                    TC6_ASSERT(seg < TC6_TX_ETH_MAX_SEGMENTS);
                    pC = pC->next;

                }
                else
                {
                    break;
                }
            }

            success = TC6_SendRawEthernetSegments(lw->tc.tc6, txSeg, seg, p->tot_len, 0, OnRawTx, p);

            TC6_ASSERT(success); /* Must always succeed as TC6_GetRawSegments returned a valid value */

            result = success ? ERR_OK : ERR_IF;

        }
        else
        {
            result = ERR_WOULDBLOCK;
        }

    }

    if (result != ERR_OK) {
        LWIP_DEBUGF(ETHARP_DEBUG, ("IP output error %d\n", result));
    }

    return result;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                FUNCTION TO GET SYSTEM TICKS FOR lwIP                 */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

uint32_t sys_now(void)
{
    return TC6Stub_GetTick();
}

uint64_t sys_now_us(void)
{
    return TC6Stub_GetTickUs();
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*             CALLBACK FUNCTION FROM TC6 Protocol Driver               */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void OnRawTx(TC6_t *pInst, const uint8_t *pTx, uint16_t len, void *pTag, void *pGlobalTag)
{
    struct pbuf *p = (struct pbuf *)pTag;
    (void)pInst;
    (void)pTx;
    (void)len;
    (void)pTag;
    (void)pGlobalTag;

    TC6_ASSERT(GetContextTC6(pInst));
    TC6_ASSERT(pTx == p->payload);
    TC6_ASSERT(len == p->tot_len);
    TC6_ASSERT(len == p->len);
    TC6_ASSERT(p->ref);

    LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_TRACE, ("raw_tx: freeing packet\n"));
    pbuf_free(p);
}

void TC6_CB_OnRxEthernetSlice(TC6_t *pInst, const uint8_t *pRx, uint16_t offset, uint16_t len, void *pGlobalTag)
{
    TC6LwIP_t *lw = GetContextTC6(pInst);
    bool success = true;

    (void)pInst;
    (void)pGlobalTag;

    TC6_ASSERT(lw->tc.tc6 == pInst);

    if (lw->tc.rxInvalid)
    {
        success = false;
    }

    if (success && ((offset + len) > (TC6LwIP_MTU + ETHARP_FCS_LEN)))
    {
        PRINT("%s: packet size %u greater than MTU", __func__, (offset + len));
        lw->tc.rxInvalid = true;
        success = false;
    }

    if (success && (NULL == lw->tc.pbuf))
    {
        lw->tc.pbuf = pbuf_alloc(PBUF_RAW, TC6LwIP_MTU, PBUF_RAM);
        if (!lw->tc.pbuf)
        {
            lw->tc.rxInvalid = true;
            success = false;
        }

        if (success && (NULL != lw->tc.pbuf->next))
        {
            PRINT("%s: could not allocate unsegmented memory diff %u", __func__, (lw->tc.pbuf->tot_len - lw->tc.pbuf->len));

            lw->tc.rxInvalid = true;

            pbuf_free(lw->tc.pbuf);

            lw->tc.pbuf = NULL;
            success = false;
        }
    }

    if (success)
    {
        (void)memcpy(lw->tc.pbuf->payload + offset, pRx, len);
        lw->tc.rxLen += len;
    }
}

void TC6_CB_OnRxEthernetPacket(TC6_t *pInst, bool success, uint16_t len, uint64_t *rxTimestamp, void *pGlobalTag)
{
#define MIN_HEADER_LEN  (42u)
    TC6LwIP_t *lw = GetContextTC6(pInst);
    bool result = true;

    (void)pInst;
    (void)rxTimestamp;
    (void)pGlobalTag;

    // Cannot receive if the PHY is not ready.
    if (!TC6_CB_ResetComplete(0))
    {
        result = false;
    }
    else
    {
        TC6_ASSERT(lw->tc.tc6 == pInst);

        if ((false == success) || (true == lw->tc.rxInvalid) || (NULL == lw->tc.pbuf) || (0U == lw->tc.rxLen))
        {
            result = false;
        }

        if ((true == result) && (lw->tc.rxLen != len))
        {
            PRINT("%s: size mismatch (%u <> %u)", __func__, lw->tc.rxLen, len);
            result = false;
        }

        if ((true == result) && (len < MIN_HEADER_LEN))
        {
            PRINT("%s: received invalid small packet len %u", __func__, len);
            result = false;
        }

        if (true == result)
        {
            uint16_t ethType;
            struct eth_hdr *ethhdr;

            TC6_ASSERT(lw->tc.pbuf);
            TC6_ASSERT(lw->tc.pbuf->ref != 0);

            LWIP_DEBUGF(PBUF_DEBUG | LWIP_DBG_TRACE, ("rx_packet: reallocating packet to size %u\n", len));
            pbuf_realloc(lw->tc.pbuf, len); /* Shrink a pbuf chain to a desired length. */

            ethhdr = lw->tc.pbuf->payload;
            ethType = htons(ethhdr->type);

            if (true == FilterRxEthernetPacket(ethType))
            {
                /* Integrator decided that TCP/IP stack shall consume the received packet */
                err_t lwresult = lw->ip.netint.input(lw->tc.pbuf, &lw->ip.netint);

                if (ERR_OK == lwresult)
                {
                    lw->tc.pbuf = NULL;
                    lw->tc.rxLen = 0;
                    lw->tc.rxInvalid = false;
                }
                else
                {
                    PRINT("%s: IP input error %u", __func__, result);
                    result = false;
                }
            }
        }

        if (NULL != lw->tc.pbuf)
        {
            // If the buffer has not been freed by the consumer, free it now.
            if (lw->tc.pbuf->ref > 0)
            {
                LWIP_DEBUGF(ETHARP_DEBUG | LWIP_DBG_TRACE, ("rx_packet: freeing packet\n"));
                pbuf_free(lw->tc.pbuf);
            }
            else {
                LWIP_DEBUGF(ETHARP_DEBUG | LWIP_DBG_TRACE, ("rx_packet: packet was freed by consumer\n"));
            }

            lw->tc.pbuf = NULL;
        }
        else
        {
            LWIP_DEBUGF(ETHARP_DEBUG | LWIP_DBG_TRACE, ("rx_packet: packet was freed by consumer\n"));
        }

        lw->tc.rxLen = 0;
        lw->tc.rxInvalid = false;
    }
}

void TC6_CB_OnNeedService(TC6_t *pInst, void *pGlobalTag)
{
    (void)pGlobalTag;

    TC6LwIP_t *lw = GetContextTC6(pInst);
    lw->tc.tc6NeedService = true;
}

void TC6_CB_OnError(TC6_t *pInst, TC6_Error_t err, void *pGlobalTag)
{
    bool reinit = false;

    (void)pGlobalTag;
    const char *str = TC6_GetErrorStr(err);
    PRINT(ESC_RED "%s" ESC_RESETCOLOR "\r\n", str);

    switch (err)
    {
        case TC6Error_Succeeded:
        case TC6Error_ControlTxFail:
        case TC6Error_PlcaStatusFail:
        default:
            break;

        case TC6Error_NoHardware:
        case TC6Error_UnexpectedSv:
        case TC6Error_UnexpectedDvEv:
        case TC6Error_BadChecksum:
        case TC6Error_UnexpectedCtrl:
        case TC6Error_BadTxData:
        case TC6Error_SyncLost:
        case TC6Error_SpiError:
            reinit = true;
            break;
    }

    if (true == reinit)
    {
        TC6LwIP_t *lw = GetContextTC6(pInst);

        lw->tc.resetComplete = false;
        TC6Regs_Reinit(pInst);
    }
}

uint32_t TC6Regs_CB_GetTicksMs(void)
{
    return TC6Stub_GetTick();
}

void TC6Regs_CB_OnEvent(TC6_t *pInst, TC6Regs_Event_t event, void *pGlobalTag)
{
    bool reinit = false;
    TC6LwIP_t *lw = GetContextTC6(pInst);

    (void)pGlobalTag;
    const char *str = TC6Regs_GetEventStr(event);

    switch(event)
    {
        case TC6Regs_Event_UnknownError:
        case TC6Regs_Event_Transmit_Protocol_Error:
        case TC6Regs_Event_Loss_of_Framing_Error:
        case TC6Regs_Event_Header_Error:
            PRINT(ESC_RED "%s" ESC_RESETCOLOR "\r\n", str);
            reinit = true;
            break;

        case TC6Regs_Event_Reset_Complete:
            PRINT(ESC_GREEN "%s" ESC_RESETCOLOR "\r\n", str);
            lw->tc.resetComplete = true;
            lw->tc.rxLen = 0;
            break;

        // All other cases:
        //   TC6Regs_Event_Transmit_Buffer_Overflow_Error:
        //   TC6Regs_Event_Transmit_Buffer_Underflow_Error:
        //   TC6Regs_Event_Receive_Buffer_Overflow_Error:
        //   TC6Regs_Event_Header_Error:
        //   TC6Regs_Event_PHY_Interrupt:
        //   TC6Regs_Event_Transmit_Timestamp_Capture_Available_A:
        //   TC6Regs_Event_Transmit_Timestamp_Capture_Available_B:
        //   TC6Regs_Event_Transmit_Timestamp_Capture_Available_C:
        //   TC6Regs_Event_Transmit_Frame_Check_Sequence_Error:
        //   TC6Regs_Event_Control_Data_Protection_Error:
        //   TC6Regs_Event_FSM_State_Error:
        //   TC6Regs_Event_SRAM_ECC_Error:
        //   TC6Regs_Event_Undervoltage:
        //   TC6Regs_Event_Internal_Bus_Error:
        //   TC6Regs_Event_TX_Timestamp_Capture_Overflow_A:
        //   TC6Regs_Event_TX_Timestamp_Capture_Overflow_B:
        //   TC6Regs_Event_TX_Timestamp_Capture_Overflow_C:
        //   TC6Regs_Event_TX_Timestamp_Capture_Missed_A:
        //   TC6Regs_Event_TX_Timestamp_Capture_Missed_B:
        //   TC6Regs_Event_TX_Timestamp_Capture_Missed_C:
        //   TC6Regs_Event_MCLK_GEN_Status:
        //   TC6Regs_Event_gPTP_PA_TS_EG_Status:
        //   TC6Regs_Event_Extended_Block_Status:
        //   TC6Regs_Event_SPI_Err_Int:
        //   TC6Regs_Event_MAC_BMGR_Int:
        //   TC6Regs_Event_MAC_Int:
        //   TC6Regs_Event_HMX_Int:
        //   TC6Regs_Event_GINT_Mask:
        //   TC6Regs_Event_Chip_Error:
        //   TC6Regs_Event_Unsupported_Hardware:
        default:
            //PRINT(ESC_RED "%s" ESC_RESETCOLOR "\r\n", str);
            break;
    }

    if (true == reinit)
    {
        TC6LwIP_t *lw = GetContextTC6(pInst);

        lw->tc.resetComplete = false;
        TC6Regs_Reinit(pInst);
    }
}

static void OnPlcaStatus(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    TC6LwIP_t *lw = (TC6LwIP_t *)tag;

    (void)pInst;
    (void)addr;
    (void)pGlobalTag;

    if ((NULL != lw) && (NULL != lw->tc.pStatusCallback))
    {
        bool status = false;

        if (true == success)
        {
            status = (0UL != ((1UL << 15) & value));
        }

        lw->tc.pStatusCallback(lw->idx, success, status);
    }
}

bool TC6_CB_ResetComplete(uint8_t tc6Instance)
{
    return mlw[tc6Instance].tc.resetComplete;
}

bool TC6_CB_OnSpiTransaction(uint8_t tc6instance, uint8_t *pTx, uint8_t *pRx, uint16_t len, void *pGlobalTag)
{
    (void)pGlobalTag;

    return TC6Stub_SpiTransaction(tc6instance, pTx, pRx, len);
}
