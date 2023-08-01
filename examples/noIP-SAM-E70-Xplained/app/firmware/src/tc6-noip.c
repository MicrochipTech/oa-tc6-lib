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
  RAW Ethernet driver for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol

  Company:
    Microchip Technology Inc.

  File Name:
    tc6-noip.c

  Summary:
    RAW Ethernet Driver TC6 SPI

  Description:
    This file provides a RAW API to send and receive Ethernet packets
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "tc6-conf.h"
#include "tc6-regs.h"
#include "tc6-stub.h"
#include "tc6-noip.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define PRINT_FORCE(...)        printf(__VA_ARGS__)
#define PRINT(...)              PrintRateLimited(__VA_ARGS__)
#define NOIP_TC6_MAGIC          (0x47392741u)
#define PRINT_RATE_TIMEOUT      (1000u)
#define PRINT_RATE_THRESHOLD    (5u)

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define ESC_RESETCOLOR              "\033[0m"
#define ESC_CLEAR_LINE              "\033[2K"
#define ESC_GREEN                   "\033[0;32m"
#define ESC_RED                     "\033[0;31m"
#define ESC_YELLOW                  "\033[1;33m"
#define ESC_BLUE                    "\033[0;36m"

typedef struct
{
    uint8_t ethRxBuf[1516];
    uint8_t mac[6];
    TC6_t *tc6;
    struct pbuf *pbuf;
    TC6NoIP_On_PlcaStatus pStatusCallback;
    uint16_t rxLen;
    bool rxInvalid;
} TC6Lib_t;

typedef struct
{
    TC6Lib_t tc;
    uint32_t magic;
    uint8_t idx;
} TC6NoIP_t;

static TC6NoIP_t mlw[TC6_MAX_INSTANCES];

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void PrintRateLimited(const char *statement, ...);
static void OnPlcaStatus(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

int8_t TC6NoIP_Init(bool enablePlca, uint8_t nodeId, uint8_t nodeCount, uint8_t burstCount, uint8_t burstTimer, bool promiscuous, bool txCutThrough, bool rxCutThrough)
{
    TC6NoIP_t *lw = NULL;
    uint8_t i;
    bool success = false;
    /* Search for empty entry */
    for (i = 0; i < TC6_MAX_INSTANCES; i++) {
        if (NOIP_TC6_MAGIC != mlw[i].magic) {
            lw = &mlw[i];
            lw->idx = i;
            success = true;
            break;
        }
    }
    if (success) {
        success = TC6Stub_Init(lw->idx, lw->tc.mac);
        if (!success) {
            PRINT_FORCE(ESC_RED "[%d]TC6Stub_Init() failed" ESC_RESETCOLOR "\r\n", lw->idx);
        }
    }
    if (success) {
        lw->tc.tc6 = TC6_Init(lw);
        success = (NULL != lw->tc.tc6);
        if (!success) {
            PRINT_FORCE(ESC_RED "[%d]TC6_Init() failed" ESC_RESETCOLOR "\r\n", lw->idx);
        }
    }
    if (success) {
        success = TC6Regs_Init(lw->tc.tc6, lw, lw->tc.mac, enablePlca, nodeId, nodeCount, burstCount, burstTimer, promiscuous, txCutThrough, rxCutThrough);
        if (!success) {
            PRINT_FORCE(ESC_RED "[%d]TC6Regs_Init() failed" ESC_RESETCOLOR "\r\n", lw->idx);
        }
    }
    if (success) {
        lw->magic = NOIP_TC6_MAGIC;
    } else {
        TC6_Destroy(lw->tc.tc6);
    }
    return (success ? (int8_t)lw->idx : -1);
}

void TC6NoIP_Service(void)
{
    uint8_t idx;
    for (idx = 0; idx < TC6_MAX_INSTANCES; idx++) {
        TC6NoIP_t *lw = &mlw[idx];
        if (NOIP_TC6_MAGIC == lw->magic) {
            if (TC6Stub_IntActive(lw->idx)) {
                if (TC6_Service(lw->tc.tc6, false)) {
                    TC6Stub_ReleaseInt(lw->idx);
                }
            } else {
                TC6_Service(lw->tc.tc6, true);
            }
        }
    }
    TC6Regs_CheckTimers();
}

bool TC6NoIP_GetPlcaStatus(int8_t idx, TC6NoIP_On_PlcaStatus pStatusCallback)
{
    bool success = false;
    if ((idx >= 0) && (idx < TC6_MAX_INSTANCES) && (NULL != pStatusCallback) ) {
        TC6NoIP_t *lw = &mlw[idx];
        lw->tc.pStatusCallback = pStatusCallback;
        success = TC6_ReadRegister(lw->tc.tc6, 0x0004CA03, true, OnPlcaStatus, lw); /* PLCA_status_register.plca_status */
    }
    return success;
}

bool TC6NoIP_SendEthernetPacket(int8_t idx, const uint8_t *pTx, uint16_t len, TC6NoIP_OnTxCallback_t txCallback)
{
    bool success = false;
    if ((idx >= 0) && (idx < TC6_MAX_INSTANCES)) {
        uint32_t idxCpy = idx;
        success = TC6_SendRawEthernetPacket(mlw[idx].tc.tc6, pTx, len, 0, (TC6_RawTxCallback_t)txCallback, (void *)idxCpy);
    }
    return success;
}

bool TC6NoIP_GetMacAddress(int8_t idx, uint8_t mac[6])
{
    bool success = false;
    if ((idx >= 0) && (idx < TC6_MAX_INSTANCES) && (NULL != mac)) {
        memcpy(mac, mlw[idx].tc.mac, 6);
        success = true;
    }
    return success;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*             CALLBACK FUNCTION FROM TC6 Protocol Driver               */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

void TC6_CB_OnRxEthernetSlice(TC6_t *pInst, const uint8_t *pRx, uint16_t offset, uint16_t len, void *pGlobalTag)
{
    TC6NoIP_t *lw = pGlobalTag;
    if ((offset + len) < sizeof(lw->tc.ethRxBuf)) {
        memcpy(&lw->tc.ethRxBuf[offset], pRx, len);
    }
}

void TC6_CB_OnRxEthernetPacket(TC6_t *pInst, bool success, uint16_t len, uint64_t *rxTimestamp, void *pGlobalTag)
{
    TC6NoIP_t *lw = pGlobalTag;
    TC6NoIP_CB_OnEthernetReceive(lw->idx, lw->tc.ethRxBuf, len);
}

void TC6_CB_OnNeedService(TC6_t *pInst, void *pGlobalTag)
{
}

void TC6_CB_OnError(TC6_t *pInst, TC6_Error_t err, void *pGlobalTag)
{
    TC6NoIP_t *lw = pGlobalTag;
    bool reinit = false;
    switch (err) {
        case TC6Error_Succeeded:
            PRINT(ESC_CLEAR_LINE ESC_GREEN "[%d]No error occurred" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Error_NoHardware:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]MISO data implies that there is no MACPHY hardware available" ESC_RESETCOLOR "\r\n", lw->idx);
            reinit = true;
            break;
        case TC6Error_UnexpectedSv:
            PRINT(ESC_CLEAR_LINE ESC_RED " [%d]Unexpected Start Valid Flag" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Error_UnexpectedDvEv:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Unexpected Data Valid or End Valid Flag" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Error_BadChecksum:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Checksum in footer is wrong" ESC_RESETCOLOR "\r\n", lw->idx);
            reinit = true;
            break;
        case TC6Error_UnexpectedCtrl:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Unexpected control packet received" ESC_RESETCOLOR "\r\n", lw->idx);
            reinit = true;
            break;
        case TC6Error_BadTxData:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Header Bad Flag received" ESC_RESETCOLOR "\r\n", lw->idx);
            reinit = true;
            break;
        case TC6Error_SyncLost:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Sync Flag is no longer set" ESC_RESETCOLOR "\r\n", lw->idx);
            reinit = true;
            break;
        case TC6Error_SpiError:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]TC6 SPI Error" ESC_RESETCOLOR "\r\n", lw->idx);
            reinit = true;
            break;
        case TC6Error_ControlTxFail:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]TC6 Control Message Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        default:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Unknown TC6 error occurred" ESC_RESETCOLOR "\r\n", lw->idx);
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
    TC6NoIP_t *lw = pTag;
    bool reinit = false;
    switch (event) {
        case TC6Regs_Event_UnknownError:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]UnknownError" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Transmit_Protocol_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Transmit_Protocol_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Transmit_Buffer_Overflow_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Transmit_Buffer_Overflow_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Transmit_Buffer_Underflow_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Transmit_Buffer_Underflow_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Receive_Buffer_Overflow_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Receive_Buffer_Overflow_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Loss_of_Framing_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Loss_of_Framing_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            reinit = true;
            break;
        case TC6Regs_Event_Header_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Header_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Reset_Complete:
            PRINT(ESC_CLEAR_LINE ESC_GREEN "[%d]Reset_Complete" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_PHY_Interrupt:
            PRINT(ESC_CLEAR_LINE ESC_GREEN "[%d]PHY_Interrupt" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Transmit_Timestamp_Capture_Available_A:
            PRINT(ESC_CLEAR_LINE ESC_GREEN "[%d]Transmit_Timestamp_Capture_Available_A" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Transmit_Timestamp_Capture_Available_B:
            PRINT(ESC_CLEAR_LINE ESC_GREEN "[%d]Transmit_Timestamp_Capture_Available_B" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Transmit_Timestamp_Capture_Available_C:
            PRINT(ESC_CLEAR_LINE ESC_GREEN "[%d]Transmit_Timestamp_Capture_Available_C" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Transmit_Frame_Check_Sequence_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Transmit_Frame_Check_Sequence_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Control_Data_Protection_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Control_Data_Protection_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_RX_Non_Recoverable_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]RX_Non_Recoverable_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            reinit = true;
            break;
        case TC6Regs_Event_TX_Non_Recoverable_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]TX_Non_Recoverable_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            reinit = true;
            break;
        case TC6Regs_Event_FSM_State_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]FSM_State_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_SRAM_ECC_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]SRAM_ECC_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Undervoltage:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Undervoltage" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Internal_Bus_Error:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]Internal_Bus_Error" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_TX_Timestamp_Capture_Overflow_A:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]TX_Timestamp_Capture_Overflow_A" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_TX_Timestamp_Capture_Overflow_B:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]TX_Timestamp_Capture_Overflow_B" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_TX_Timestamp_Capture_Overflow_C:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]TX_Timestamp_Capture_Overflow_C" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_TX_Timestamp_Capture_Missed_A:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]TX_Timestamp_Capture_Missed_A" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_TX_Timestamp_Capture_Missed_B:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]TX_Timestamp_Capture_Missed_B" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_TX_Timestamp_Capture_Missed_C:
            PRINT(ESC_CLEAR_LINE ESC_RED "[%d]TX_Timestamp_Capture_Missed_C" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_MCLK_GEN_Status:
            PRINT(ESC_CLEAR_LINE ESC_YELLOW "[%d]MCLK_GEN_Status" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_gPTP_PA_TS_EG_Status:
            PRINT(ESC_CLEAR_LINE ESC_YELLOW "g[%d]PTP_PA_TS_EG_Status" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Extended_Block_Status:
            PRINT(ESC_CLEAR_LINE ESC_YELLOW "[%d]Extended_Block_Status" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_SPI_Err_Int:
            PRINT(ESC_CLEAR_LINE ESC_YELLOW "[%d]SPI_Err_Int" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_MAC_BMGR_Int:
            PRINT(ESC_CLEAR_LINE ESC_YELLOW "[%d]MAC_BMGR_Int" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_MAC_Int:
            PRINT(ESC_CLEAR_LINE ESC_YELLOW "[%d]MAC_Int" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_HMX_Int:
            PRINT(ESC_CLEAR_LINE ESC_YELLOW "[%d]HMX_Int" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_GINT_Mask:
            PRINT(ESC_CLEAR_LINE ESC_YELLOW "[%d]GINT_Mask" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Chip_Error:
            PRINT(ESC_RED "[%d]Chip_error! Please contact microchip support for replacement" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
        case TC6Regs_Event_Unsupported_Hardware:
            PRINT(ESC_RED "[%d]Unsupported MAC-PHY hardware found" ESC_RESETCOLOR "\r\n", lw->idx);
            break;
    }
    if (reinit) {
        TC6Regs_Reinit(pInst);
    }
}

static void PrintRateLimited(const char *statement, ...)
{
    static uint32_t cnt_ = 0;
    static uint32_t t0_;
    uint32_t now = TC6Stub_GetTick();

    if (t0_ && ((now - t0_) >= PRINT_RATE_TIMEOUT)) {
        if (cnt_ > PRINT_RATE_THRESHOLD) {
            printf(ESC_CLEAR_LINE ESC_YELLOW "[skipped %lu]" ESC_RESETCOLOR "\r\n", (cnt_ - PRINT_RATE_THRESHOLD));
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

static void OnPlcaStatus(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    TC6NoIP_t *lw = tag;
    (void)pInst;
    (void)addr;
    (void)pGlobalTag;
    if ((NULL != lw) && (NULL != lw->tc.pStatusCallback)) {
        bool status = false;
        if (success) {
            status = (0u != ((1u << 15) & value));
        }
        lw->tc.pStatusCallback((int8_t)lw->idx, success, status);
    }
}

bool TC6_CB_OnSpiTransaction(uint8_t tc6instance, uint8_t *pTx, uint8_t *pRx, uint16_t len, void *pGlobalTag)
{
    return TC6Stub_SpiTransaction(tc6instance, pTx, pRx, len);
}
