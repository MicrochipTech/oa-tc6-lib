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
  MCU specific stub code for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol

  Company:
    Microchip Technology Inc.

  File Name:
    tc6-stub.c

  Summary:
    MCU specific stub code

  Description:
    This file acts as a bridge between the TC6 library and the Board Support Package
    for the dedicated MCU
*******************************************************************************/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "tc6-conf.h"
#include "tc6-stub.h"
#include "tc6.h"
#include "dmaspi.h"
#include "systick.h"

#include "mcc_generated_files/i2c_host/i2c2.h"
#include "mcc_generated_files/system/pins.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define DEFAULT_SPI_SPEED       (16000000)
#define FIRST_TC6_INSTANCE      (0)
#define SECOND_TC6_INSTANCE     (1)
#define SPI_OFFSET              (0)
#define PRINT(...)              (void)printf(__VA_ARGS__)
#define ASSERT(x)               __conditional_software_breakpoint(x)

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
    bool firstTransaction;
    volatile uint8_t busy;
    volatile uint8_t macValid;
} Stub_Local_t;

static Stub_Local_t d[TC6_MAX_INSTANCES] = {{{ 0 }}};

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static bool GetMacAddress(Stub_Local_t *ps);
static void IntHandler(void);
void vidTransactionDone(void);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

bool TC6Stub_Init(uint8_t idx, uint8_t pMac[6])
{
    bool success = false;

    if (idx >= TC6_MAX_INSTANCES)
    {
        ASSERT(false);
    }
    else
    {
        Stub_Local_t *ps = &d[idx];
        ps->idx = idx;
        ps->firstTransaction = true;

        if (GetMacAddress(ps))
        {
            (void)memcpy(pMac, ps->mac, 6u);
            ps->macValid = 1u;
        }
        else
        {
            (void)memcpy(pMac, FALLBACK_MAC, 6u);
        }

        switch (idx)
        {
            case FIRST_TC6_INSTANCE:
            {
                Ext_Int_SetInterruptHandler(IntHandler);
                TC6_RESET_SetLow();
                SysTick_DelayMs(10);
                TC6_RESET_SetHigh();
                SysTick_DelayMs(10);
            }
            break;

            default:
                break;
        }

        if (false == ps->opened)
        {
            ps->opened = true;
        }

        dmaSpiInit(vidTransactionDone);

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

    if (true == Ext_Int_GetValue())
    {
        ps->intOut = ps->intReported;
    }
}

uint32_t TC6Stub_GetTick(void)
{
    return SysTick_GetTickMs();
}

uint64_t TC6Stub_GetTickUs(void)
{
    return SysTick_GetTickUs();
}

bool TC6Stub_SpiTransaction(uint8_t idx, uint8_t *pTx, uint8_t *pRx, uint16_t len)
{
    Stub_Local_t *ps = &d[idx];
    bool success = false;

    ASSERT(idx < TC6_MAX_INSTANCES);

    if ((true == ps->opened) && (false == ps->busy))
    {
        ps->busy = true;

        if (DMA_AVAILABLE == dmaSpiStartTransaction(pTx, pRx, len))
        {
            ps->busy = false;
        }
        else
        {
            success = true;
        }
    }

    return success;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  PRIVATE FUNCTION IMPLEMENTATIONS                    */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static bool GetMacAddress(Stub_Local_t *ps)
{
    bool success = false;

    if (NULL != ps)
    {
        uint8_t MAC_EEPROM_I2C_SLAVE_ADDR = 0x58U;
        uint8_t MAC_EEPROM_EUI_REG_ADDR = 0x9AU;

        success = I2C2_WriteRead(MAC_EEPROM_I2C_SLAVE_ADDR, &MAC_EEPROM_EUI_REG_ADDR, sizeof(MAC_EEPROM_EUI_REG_ADDR), ps->mac, sizeof(ps->mac));
        if (true == success)
        {
            // Wait for the device to complete the transaction.
            bool i2cBusy;

            do
            {
                i2cBusy = I2C2_IsBusy();
            } while (true == i2cBusy);

            enum I2C_HOST_ERROR err = I2C2_ErrorGet();

            success = (err == I2C_HOST_ERROR_NONE);
        }
    }

    return success;
}

void TC6_SpiTransaction_status(uint8_t idx)
{
    Stub_Local_t *ps = &d[idx];
    ps->busy = dmaSpiGetStatus(); // spi status
}

void vidTransactionDone(void)
{
    d[0].firstTransaction = false;
    TC6_SpiTransaction_status(FIRST_TC6_INSTANCE);
    TC6_SpiBufferDone(0, true);
}

static void IntHandler(void)
{
    Stub_Local_t *ps = &d[0];
    ps->intIn++;
}
