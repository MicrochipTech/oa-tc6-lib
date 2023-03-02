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
#include "lwip/netif.h"
#include "lwip/init.h"
#include "lwip/timeouts.h"
#include "netif/etharp.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "tc6-conf.h"
#include "tc6-regs.h"
#include "tc6.h"
#include "tc6-stub.h"
#include "tc6-lwip.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define PRINT(...)              PrintRateLimited(__VA_ARGS__)
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
    uint8_t idx;
} TC6LwIP_t;

static TC6LwIP_t mlw[TC6_MAX_INSTANCES];

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static bool FilterRxEthernetPacket(uint16_t ethType);
static void PrintRateLimited(const char *statement, ...);
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
    ip4_addr_t ipAddr;
    ip4_addr_t nm;
    ip4_addr_t gw;
    bool success = true;
    if (!ip) {
        success = false;
    }
    if (success) {
        /* Search for empty entry */
        success = false;
        for (i = 0; i < TC6_MAX_INSTANCES; i++) {
            if (LWIP_TC6_MAGIC != mlw[i].magic) {
                lw = &mlw[i];
                lw->idx = i;
                success = true;
                if (0 == i) {
                    /* Initialize lwIP stack only on the first call of this function */
                    lwip_init();
                }
                break;
            }
        }
    }
    if (success) {
        success = TC6Stub_Init(lw->idx, lw->ip.mac);
    }
    if (success) {
        lw->tc.tc6 = TC6_Init(lw);
        success = (NULL != lw->tc.tc6);
    }
    if (success) {
        success = TC6Regs_Init(lw->tc.tc6, lw, lw->ip.mac, enablePlca, nodeId, nodeCount, burstCount, burstTimer, promiscuous, txCutThrough, rxCutThrough);
    }
    if (success) {
        while(!TC6Regs_GetInitDone(lw->tc.tc6)) {
            TC6_Service(lw->tc.tc6, true);
        }
    }
    if (success) {
        uint8_t *mac = lw->ip.mac;
        lw->magic = LWIP_TC6_MAGIC;
        (void)snprintf(lw->ip.ipAddr, sizeof(lw->ip.ipAddr), "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);

        /* Setup lwIP interface */
#if (TC6LwIP_DHCP)
        ip_addr_set_zero(&ip);
        ip_addr_set_zero(&nm);
        ip_addr_set_zero(&gw);
        PRINT("LwIP-Init [MAC=%02X:%02X:%02X:%02X:%02X:%02X, DHCP]\r\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
#else
        ipaddr_aton(lw->ip.ipAddr, &ipAddr);
        ipaddr_aton(TC6LwIP_NETMASK, &nm);
        ipaddr_aton(TC6LwIP_GATEWAY, &gw);
        PRINT("LwIP-Init [MAC=%02X:%02X:%02X:%02X:%02X:%02X, IP='%s']\r\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], lw->ip.ipAddr);
#endif
        if (!netif_add(&lw->ip.netint, &ipAddr , &nm, &gw, lw, lwIpInit, ethernet_input)) {
            TC6_ASSERT(false);
            PRINT("Could not add TC6 interface to lwIP!\r\n");
            success = false;
        }
        if (success) {
            netif_set_link_up(&lw->ip.netint);
        }
    }
    return (success ? lw->idx : -1);
}

void TC6LwIP_Service(void)
{
    uint8_t idx;
    sys_check_timeouts(); /* LWIP timers - ARP, DHCP, TCP, etc. */
    for (idx = 0; idx < TC6_MAX_INSTANCES; idx++) {
        TC6LwIP_t *lw = &mlw[idx];
        if (LWIP_TC6_MAGIC == lw->magic) {
            if (TC6Stub_IntActive(lw->idx)) {
                if (TC6_Service(lw->tc.tc6, false)) {
                    TC6Stub_ReleaseInt(lw->idx);
                }
            } else if (lw->tc.tc6NeedService) {
                lw->tc.tc6NeedService = false;
                TC6_Service(lw->tc.tc6, true);
            }
        }
    }
    TC6Regs_CheckTimers();
}

bool TC6LwIP_GetPlcaStatus(int8_t idx, TC6LwIP_On_PlcaStatus pStatusCallback)
{
    bool success = false;
    if ((idx < TC6_MAX_INSTANCES) && (NULL != pStatusCallback) ) {
        TC6LwIP_t *lw = &mlw[idx];
        lw->tc.pStatusCallback = pStatusCallback;
        success = TC6_ReadRegister(lw->tc.tc6, 0x0004CA03, true, OnPlcaStatus, lw); /* PLCA_status_register.plca_status */
    }
    return success;
}

bool TC6LwIP_SendWouldBlock(int8_t idx)
{
    bool wouldBlock = false;
    if (idx < TC6_MAX_INSTANCES) {
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
    if (mac && (idx < TC6_MAX_INSTANCES)) {
        TC6LwIP_t *lw = &mlw[idx];
        *mac = lw->ip.mac;
    }
}

bool TC6LwIP_SetPlca(int8_t idx, bool plcaEnable, uint8_t nodeId, uint8_t nodeCount)
{
    bool success = false;
    if (idx < TC6_MAX_INSTANCES) {
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
    switch (ethType) {
    case 0x0800:
        /* IPv4 */
        tcpStack = true;
        break;
    case 0x0806:
        /* ARP */
        tcpStack = true;
        break;
    }
    return tcpStack;
}

static void PrintRateLimited(const char *statement, ...)
{
    static uint32_t cnt_ = 0;
    static uint32_t t0_;
    uint32_t now = TC6Stub_GetTick();

    if (t0_ && ((now - t0_) >= PRINT_RATE_TIMEOUT)) {
        if (cnt_ > PRINT_RATE_THRESHOLD) {
            printf(ESC_YELLOW "[skipped %lu]" ESC_RESETCOLOR "\r\n", (cnt_ - PRINT_RATE_THRESHOLD));
        }
        t0_ = 0;
        cnt_ = 0;
    }
    ++cnt_;
    if (cnt_ <= PRINT_RATE_THRESHOLD) {
        va_list args;
        va_start( args, statement );
        (void)vfprintf(stdout, statement, args);
        va_end( args );
        t0_ = now;
    }
}

static TC6LwIP_t *GetContextNetif(struct netif *intf)
{
    TC6LwIP_t *lw = NULL;
    uint8_t i;
    for (i = 0; i < TC6_MAX_INSTANCES; i++) {
        if (&mlw[i].ip.netint == intf) {
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
    for (i = 0; i < TC6_MAX_INSTANCES; i++) {
        if (mlw[i].tc.tc6 == pTC6) {
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
    uint8_t seg = 0;
    err_t result;
    bool success;
    TC6_ASSERT(netif && p);
    TC6_ASSERT(LWIP_TC6_MAGIC == ((TC6LwIP_t*)netif->state)->magic);
    maxSeg = TC6_GetRawSegments(lw->tc.tc6, &txSeg);
    if (maxSeg) {
        pbuf_ref(p);
        while (seg < maxSeg) {
            txSeg[seg].pEth = (uint8_t *)pC->payload;
            txSeg[seg].segLen = pC->len;
            seg++;
            if (NULL != pC->next) {
                TC6_ASSERT(seg < TC6_TX_ETH_MAX_SEGMENTS);
                pC = pC->next;
            } else {
                break;
            }
        }
        success = TC6_SendRawEthernetSegments(lw->tc.tc6, txSeg, seg, p->tot_len, 0, OnRawTx, p);
        TC6_ASSERT(success); /* Must always succeed as TC6_GetRawSegments returned a valid value */
        result = success ? ERR_OK : ERR_IF;
    } else {
        result = ERR_WOULDBLOCK;
    }
    return result;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                FUNCTION TO GET SYSTEM TICKS FOR lwIP                 */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

u32_t sys_now(void)
{
    return TC6Stub_GetTick();
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*             CALLBACK FUNCTION FROM TC6 Protocol Driver               */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void OnRawTx(TC6_t *pInst, const uint8_t *pTx, uint16_t len, void *pTag, void *pGlobalTag)
{
    struct pbuf *p = pTag;
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
    pbuf_free(p);
}

void TC6_CB_OnRxEthernetSlice(TC6_t *pInst, const uint8_t *pRx, uint16_t offset, uint16_t len, void *pGlobalTag)
{
    TC6LwIP_t *lw = GetContextTC6(pInst);
    bool success = true;
    (void)pInst;
    (void)pGlobalTag;
    TC6_ASSERT(lw->tc.tc6 == pInst);
    if (lw->tc.rxInvalid) {
        success = false;
    }
    if (success && ((offset + len) > TC6LwIP_MTU)) {
        PrintRateLimited("on_rx_slice:packet greater than MTU", (offset + len));
        lw->tc.rxInvalid = true;
        success = false;
    }
    if (success && (0u != offset)) {
        if (!lw->tc.pbuf || !lw->tc.rxLen) {
            TC6_ASSERT(false);
            lw->tc.rxInvalid = true;
            success = false;
        }
    } else {
        if (success && (lw->tc.pbuf || lw->tc.rxLen)) {
            TC6_ASSERT(false);
            lw->tc.rxInvalid = true;
            success = false;
        }

        if (success) {
            lw->tc.pbuf = pbuf_alloc(PBUF_RAW, TC6LwIP_MTU, PBUF_RAM);
            if (!lw->tc.pbuf) {
                lw->tc.rxInvalid = true;
                success = false;
            }
        }
        if (success && (NULL != lw->tc.pbuf->next)) {
            TC6_ASSERT(lw->tc.pbuf->ref != 0);
            PrintRateLimited("rx_slice: could not allocate unsegmented memory diff", (lw->tc.pbuf->tot_len - lw->tc.pbuf->len));
            lw->tc.rxInvalid = true;
            pbuf_free(lw->tc.pbuf);
            lw->tc.pbuf = NULL;
            success = false;
        }
    }
    if (success) {
        (void)memcpy(lw->tc.pbuf->payload + offset, pRx, len);
        lw->tc.rxLen += len;
    }
}

void TC6_CB_OnRxEthernetPacket(TC6_t *pInst, bool success, uint16_t len, uint64_t *rxTimestamp, void *pGlobalTag)
{
#define MIN_HEADER_LEN  (42u)
    TC6LwIP_t *lw = GetContextTC6(pInst);
    uint16_t ethType;
    struct eth_hdr *ethhdr;
    (void)pInst;
    (void)rxTimestamp;
    (void)pGlobalTag;
    TC6_ASSERT(lw->tc.tc6 == pInst);
    bool result = true;
    if (!success || lw->tc.rxInvalid || !lw->tc.pbuf || !lw->tc.rxLen) {
        result = false;
    }
    if (result && (lw->tc.rxLen != len)) {
        PrintRateLimited("on_rx_eth_ready: size mismatch", 0u);
        result = false;
    }
    if (result && (len < MIN_HEADER_LEN)) {
        PrintRateLimited("on_rx_eth_ready: received invalid small packet len", len);
        result = false;
    }
    if (result) {
        TC6_ASSERT(lw->tc.pbuf);
        TC6_ASSERT(lw->tc.pbuf->ref != 0);
        pbuf_realloc(lw->tc.pbuf, len); /* Shrink a pbuf chain to a desired length. */
        ethhdr = lw->tc.pbuf->payload;
        ethType = htons(ethhdr->type);
        if (FilterRxEthernetPacket(ethType)) {
            /* Integrator decided that TCP/IP stack shall consume the received packet */
            err_t result = lw->ip.netint.input(lw->tc.pbuf, &lw->ip.netint);
            if (ERR_OK == result) {
                lw->tc.pbuf = NULL;
                lw->tc.rxLen = 0;
                lw->tc.rxInvalid = false;
            } else {
                PrintRateLimited("on_rx_eth_ready: IP input error", result);
                result = false;
            }
        }
    }
    if (!result) {
        if (NULL != lw->tc.pbuf) {
            TC6_ASSERT(NULL != lw->tc.pbuf);
            pbuf_free(lw->tc.pbuf);
            lw->tc.pbuf = NULL;
        }
        lw->tc.rxLen = 0;
        lw->tc.rxInvalid = false;
    }
}

void TC6_CB_OnNeedService(TC6_t *pInst, void *pGlobalTag)
{
    TC6LwIP_t *lw = GetContextTC6(pInst);
    lw->tc.tc6NeedService = true;
}

void TC6_CB_OnError(TC6_t *pInst, TC6_Error_t err, void *pGlobalTag)
{
    bool reinit = false;
    switch (err) {
    case TC6Error_Succeeded:
        PRINT(ESC_GREEN "No error occurred" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Error_NoHardware:
        PRINT(ESC_RED "MISO data implies that there is no MACPHY hardware available" ESC_RESETCOLOR "\r\n");
        reinit = true;
        break;
    case TC6Error_UnexpectedSv:
        PRINT(ESC_RED " Unexpected Start Valid Flag" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Error_UnexpectedDvEv:
        PRINT(ESC_RED "Unexpected Data Valid or End Valid Flag" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Error_BadChecksum:
        PRINT(ESC_RED "Checksum in footer is wrong" ESC_RESETCOLOR "\r\n");
        reinit = true;
        break;
    case TC6Error_UnexpectedCtrl:
        PRINT(ESC_RED "Unexpected control packet received" ESC_RESETCOLOR "\r\n");
        reinit = true;
        break;
    case TC6Error_BadTxData:
        PRINT(ESC_RED "Header Bad Flag received" ESC_RESETCOLOR "\r\n");
        reinit = true;
        break;
    case TC6Error_SyncLost:
        PRINT(ESC_RED "Sync Flag is no longer set" ESC_RESETCOLOR "\r\n");
        reinit = true;
        break;
    case TC6Error_SpiError:
        PRINT(ESC_RED "TC6 SPI Error" ESC_RESETCOLOR "\r\n");
        reinit = true;
        break;
    case TC6Error_ControlTxFail:
        PRINT(ESC_RED "TC6 Control Message Error" ESC_RESETCOLOR "\r\n");
        break;
    default:
        PRINT(ESC_RED "Unknown TC6 error occurred" ESC_RESETCOLOR "\r\n");
        break;
    }
    if (reinit) {
        TC6Regs_Reinit(pInst);
    }
}

uint32_t TC6Regs_CB_GetTicksMs(void)
{
    return TC6Stub_GetTick();
}

 void TC6Regs_CB_OnEvent(TC6_t *pInst, TC6Regs_Event_t event, void *pTag)
 {
    bool reinit = false;
    switch(event)
    {
    case TC6Regs_Event_UnknownError:
        PRINT(ESC_RED "UnknownError" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Transmit_Protocol_Error:
        PRINT(ESC_RED "Transmit_Protocol_Error" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Transmit_Buffer_Overflow_Error:
        PRINT(ESC_RED "Transmit_Buffer_Overflow_Error" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Transmit_Buffer_Underflow_Error:
        PRINT(ESC_RED "Transmit_Buffer_Underflow_Error" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Receive_Buffer_Overflow_Error:
        PRINT(ESC_RED "Receive_Buffer_Overflow_Error" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Loss_of_Framing_Error:
        PRINT(ESC_RED "Loss_of_Framing_Error" ESC_RESETCOLOR "\r\n");
        reinit = true;
        break;
    case TC6Regs_Event_Header_Error:
        PRINT(ESC_RED "Header_Error" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Reset_Complete:
        PRINT(ESC_GREEN "Reset_Complete" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_PHY_Interrupt:
        PRINT(ESC_GREEN "PHY_Interrupt" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Transmit_Timestamp_Capture_Available_A:
        PRINT(ESC_GREEN "Transmit_Timestamp_Capture_Available_A" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Transmit_Timestamp_Capture_Available_B:
        PRINT(ESC_GREEN "Transmit_Timestamp_Capture_Available_B" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Transmit_Timestamp_Capture_Available_C:
        PRINT(ESC_GREEN "Transmit_Timestamp_Capture_Available_C" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Transmit_Frame_Check_Sequence_Error:
        PRINT(ESC_RED "Transmit_Frame_Check_Sequence_Error" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Control_Data_Protection_Error:
        PRINT(ESC_RED "Control_Data_Protection_Error" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_RX_Non_Recoverable_Error:
        PRINT(ESC_RED "RX_Non_Recoverable_Error" ESC_RESETCOLOR "\r\n");
        reinit = true;
        break;
    case TC6Regs_Event_TX_Non_Recoverable_Error:
        PRINT(ESC_RED "TX_Non_Recoverable_Error" ESC_RESETCOLOR "\r\n");
        reinit = true;
        break;
    case TC6Regs_Event_FSM_State_Error:
        PRINT(ESC_RED "FSM_State_Error" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_SRAM_ECC_Error:
        PRINT(ESC_RED "SRAM_ECC_Error" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Undervoltage:
        PRINT(ESC_RED "Undervoltage" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Internal_Bus_Error:
        PRINT(ESC_RED "Internal_Bus_Error" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_TX_Timestamp_Capture_Overflow_A:
        PRINT(ESC_RED "TX_Timestamp_Capture_Overflow_A" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_TX_Timestamp_Capture_Overflow_B:
        PRINT(ESC_RED "TX_Timestamp_Capture_Overflow_B" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_TX_Timestamp_Capture_Overflow_C:
        PRINT(ESC_RED "TX_Timestamp_Capture_Overflow_C" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_TX_Timestamp_Capture_Missed_A:
        PRINT(ESC_RED "TX_Timestamp_Capture_Missed_A" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_TX_Timestamp_Capture_Missed_B:
        PRINT(ESC_RED "TX_Timestamp_Capture_Missed_B" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_TX_Timestamp_Capture_Missed_C:
        PRINT(ESC_RED "TX_Timestamp_Capture_Missed_C" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_MCLK_GEN_Status:
        PRINT(ESC_YELLOW "MCLK_GEN_Status" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_gPTP_PA_TS_EG_Status:
        PRINT(ESC_YELLOW "gPTP_PA_TS_EG_Status" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_Extended_Block_Status:
        PRINT(ESC_YELLOW "Extended_Block_Status" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_SPI_Err_Int:
        PRINT(ESC_YELLOW "SPI_Err_Int" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_MAC_BMGR_Int:
        PRINT(ESC_YELLOW "MAC_BMGR_Int" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_MAC_Int:
        PRINT(ESC_YELLOW "MAC_Int" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_HMX_Int:
        PRINT(ESC_YELLOW "HMX_Int" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_GINT_Mask:
        PRINT(ESC_YELLOW "GINT_Mask" ESC_RESETCOLOR "\r\n");
        break;
    case TC6Regs_Event_PHY_Not_Trimmed:
        PRINT(ESC_RED "PHY is not trimmed" ESC_RESETCOLOR "\r\n");
        break;
    }
    if (reinit) {
        TC6Regs_Reinit(pInst);
    }
 }

static void OnPlcaStatus(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    TC6LwIP_t *lw =tag;
    (void)pInst;
    (void)addr;
    (void)pGlobalTag;
    if ((NULL != lw) && (NULL != lw->tc.pStatusCallback)) {
        bool status = false;
        if (success) {
            status = (0u != ((1u << 15) & value));
        }
        lw->tc.pStatusCallback(lw->idx, success, status);
    }
}

bool TC6_CB_OnSpiTransaction(uint8_t tc6instance, uint8_t *pTx, uint8_t *pRx, uint16_t len, void *pGlobalTag)
{
    return TC6Stub_SpiTransaction(tc6instance, pTx, pRx, len);
}
