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
  MCU specific stub code for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol

  Company:
    Microchip Technology Inc.

  File Name:
    tc6-stub.c

  Summary:
    MCU specifc stub code

  Description:
    This file acts as a bridge between the TC6 library and the Board Support Package
    for the dedicated MCU
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "mcc_generated_files/mcc.h"
#include "tc6-conf.h"
#include "tc6.h"
#include "systick.h"
#include "DMASPItransfer.h"/*THW220107 add include file */

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define FIRST_TC6_INSTANCE      (0)
#define PRINT(...)              (void)printf(__VA_ARGS__)
#ifdef DEBUG
#define ASSERT(x)               __conditional_software_breakpoint(x)
#else
#define ASSERT(x)
#endif

static const uint8_t FALLBACK_MAC[] = {0x00u, 0x80u, 0xC2u, 0x00u, 0x01u, 0xCCu};

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

typedef struct
{
    uint8_t mac[6];
    uint8_t intIn;
    uint8_t intOut;
    uint8_t intReported;
    uint8_t idx;
    bool opened;
    bool busy;
    bool firstTransaction;
} Stub_Local_t;

static Stub_Local_t d[TC6_MAX_INSTANCES] = { 0 };

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void IntHandler(void);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

bool TC6Stub_Init(uint8_t idx, uint8_t pMac[6])
{
    bool success = false;
    if (idx >= TC6_MAX_INSTANCES) {
        ASSERT(false);
    } else {
        Stub_Local_t *ps = &d[idx];
        ps->idx = idx;
        ps->firstTransaction = true;
        memcpy(pMac, FALLBACK_MAC, 5u);
        pMac[5] = idx;

        IO_RST1_SetLow();
        SysTick_DelayMS(10);
        IO_RST1_SetHigh();
        SysTick_DelayMS(10);

        INT0_SetInterruptHandler(IntHandler);
        SPI1_Open(SPI1_DEFAULT); /* open SPI instance */
        vidInitDmaSpiTransfer();
        DMA2_SetDCNTIInterruptHandler(&vidDma2DestCountISR);
        success = true;
    }
    return success;
}

bool TC6Stub_IntActive(uint8_t idx)
{
    Stub_Local_t *ps = &d[idx];
    ASSERT(idx < TC6_MAX_INSTANCES);
    ps->intReported = ps->intIn;
    return (ps->intReported != ps->intOut);
}

void TC6Stub_ReleaseInt(uint8_t idx)
{
    Stub_Local_t *ps = &d[idx];
    ASSERT(idx < TC6_MAX_INSTANCES);
    ps->intOut = ps->intReported;
}

uint32_t TC6Stub_GetTick(void)
{
    return SysTick_GetMillis();
}

bool TC6Stub_SpiTransaction(uint8_t idx, uint8_t *pTx, uint8_t *pRx, uint16_t len)
{
    uint16_t i;
    if (idx > FIRST_TC6_INSTANCE) {
        TC6_ASSERT(false);
        return false;
    }
    /*
     * provide information to DMA to transfer data via DMA <-> SPI
     */
    (void)u8SpiStartTransaction(pTx, pRx, len);
    /* wait until transfer finished */
    while (DMA_TRANSFER_PROGRESS == u8GetProcessStatus());
    return true;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  PRIVATE FUNCTION IMPLEMENTATIONS                    */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/


static void IntHandler(void)
{
    Stub_Local_t *ps = &d[0];
    ps->intIn++;
    EXT_INT0_InterruptFlagClear();
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                     CALLBACK FROM DMA SPI DRIVER                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

void vidChipSelectHigh(void)
{
    IO_CS1_SetHigh();
}

void vidChipSelectLow(void)
{
    /* SPI Driver is sending corrupted data on the first transaction, silently drop it by not toggling the CS */
    if (!d[0].firstTransaction) {
        IO_CS1_SetLow();
    }
}

void vidTransactionDone(void)
{
    d[0].firstTransaction = false;
    TC6_SpiBufferDone(0, true);
}
