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
#include "definitions.h"
#include "tc6-conf.h"
#include "tc6.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define DEFAULT_SPI_SPEED       (15000000)
#define FIRST_TC6_INSTANCE      (0)
#define SPI_OFFSET              (0)
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
    DRV_I2C_TRANSFER_HANDLE i2cHandle;
    DRV_SPI_TRANSFER_SETUP spiSetup;
    DRV_HANDLE handle;
    uint8_t intIn;
    uint8_t intOut;
    uint8_t intReported;
    uint8_t idx;
    bool opened;
    volatile bool busy;
    volatile uint8_t macValid;
} Stub_Local_t;

static Stub_Local_t d[TC6_MAX_INSTANCES] = { 0 };

extern SYSTICK_OBJECT systick; /* Instanced in plib_systick.c */

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static bool GetMacAddress(Stub_Local_t *ps);

static void EventHandlerI2C(DRV_I2C_TRANSFER_EVENT event, DRV_I2C_TRANSFER_HANDLE transferHandle, uintptr_t context);
static void EventHandlerSPI(DRV_SPI_TRANSFER_EVENT event, DRV_SPI_TRANSFER_HANDLE transferHandle, uintptr_t context);

static void IntHandler(uintptr_t context);

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
        if (GetMacAddress(ps)) {
            memcpy(pMac, ps->mac, 6u);
        } else {
            PRINT("Using fallback MAC address, instance=%d\r\n", idx);
            memcpy(pMac, FALLBACK_MAC, 6u);
        }
        switch (idx) {
        case FIRST_TC6_INSTANCE:
            EIC_CallbackRegister(EIC_PIN_14, IntHandler, (uintptr_t)ps);
            TC6_RESET_1_Clear();
            SYSTICK_DelayMs(10);
            TC6_RESET_1_Set();
            SYSTICK_DelayMs(10);
            break;
        default:
            ASSERT(false);
            break;
        }
        if (!ps->opened) {
            ps->opened = true;
            ASSERT((idx + SPI_OFFSET) < DRV_SPI_INSTANCES_NUMBER);
            ps->handle = DRV_SPI_Open((idx + SPI_OFFSET), DRV_IO_INTENT_EXCLUSIVE);
            switch (idx) {
            case FIRST_TC6_INSTANCE:
                ps->spiSetup.chipSelect = SYS_PORT_PIN_PC15;
                break;
            default:
                ASSERT(false);
                break;
            }
        }
        ps->spiSetup.baudRateInHz = DEFAULT_SPI_SPEED;
        ps->spiSetup.clockPhase = DRV_SPI_CLOCK_PHASE_VALID_LEADING_EDGE;
        ps->spiSetup.clockPolarity = DRV_SPI_CLOCK_POLARITY_IDLE_LOW;
        ps->spiSetup.dataBits = DRV_SPI_DATA_BITS_8;
        ps->spiSetup.csPolarity = DRV_SPI_CS_POLARITY_ACTIVE_LOW;
        DRV_SPI_TransferEventHandlerSet(ps->handle, EventHandlerSPI, (uintptr_t)ps);
        success = DRV_SPI_TransferSetup(ps->handle, &ps->spiSetup);
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
    if (TC6_INT_1_Get()) {
        ps->intOut = ps->intReported;
    }
}

uint32_t TC6Stub_GetTick(void)
{
    return systick.tickCounter;
}

bool TC6Stub_SpiTransaction(uint8_t idx, uint8_t *pTx, uint8_t *pRx, uint16_t len)
{
    DRV_SPI_TRANSFER_HANDLE transferHandle;
    Stub_Local_t *ps = &d[idx];
    bool success = false;
    ASSERT(idx < TC6_MAX_INSTANCES);

    if (ps->opened && !ps->busy) {
        ps->busy = true;
        DRV_SPI_WriteReadTransferAdd(ps->handle, pTx, len, pRx, len, &transferHandle);
        if (transferHandle == DRV_SPI_TRANSFER_HANDLE_INVALID) {
            ps->busy = false;
        } else {
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
    uint8_t MAC_EEPROM_I2C_SLAVE_ADDR = 0x58;
    uint8_t MAC_EEPROM_EUI_REG_ADDR = 0x9A;
    bool success = false;
    if (NULL != ps) {
        DRV_HANDLE i2c_handle = DRV_I2C_Open(ps->idx, DRV_IO_INTENT_EXCLUSIVE);
        if (DRV_HANDLE_INVALID == i2c_handle) {
            ASSERT(false);
            return false;
        }
        ps->macValid = 0;
        DRV_I2C_TransferEventHandlerSet(i2c_handle, EventHandlerI2C, (uintptr_t)ps);
        DRV_I2C_WriteReadTransferAdd(i2c_handle, MAC_EEPROM_I2C_SLAVE_ADDR, &MAC_EEPROM_EUI_REG_ADDR, sizeof(MAC_EEPROM_EUI_REG_ADDR), ps->mac, 6, &ps->i2cHandle);
        if (DRV_I2C_TRANSFER_HANDLE_INVALID == ps->i2cHandle) {
            PRINT("Failed to enqueue read MAC address from EEPROM\r\n");
            return false;
        }
        while (!ps->macValid) {}
        ps->i2cHandle = DRV_I2C_TRANSFER_HANDLE_INVALID;
        if (2 == ps->macValid) {
            PRINT("Failed to obtain MAC address from EEPROM\r\n");
            return false;
        }
        DRV_I2C_Close(i2c_handle);
        success = true;
    }
    return success;
}

static void EventHandlerI2C(DRV_I2C_TRANSFER_EVENT event, DRV_I2C_TRANSFER_HANDLE transferHandle, uintptr_t context)
{
    Stub_Local_t *ps = (Stub_Local_t *)context;
    (void)transferHandle;
    ASSERT((NULL != ps) && (ps->idx < TC6_MAX_INSTANCES));
    switch (event) {
    case DRV_I2C_TRANSFER_EVENT_PENDING:
        /* Not yet ready*/
        break;
    case DRV_I2C_TRANSFER_EVENT_COMPLETE:
        ps->macValid = 1;
        break;
    case DRV_I2C_TRANSFER_EVENT_ERROR:
    default:
        ps->macValid = 2;
        break;
    }
}

static void EventHandlerSPI(DRV_SPI_TRANSFER_EVENT event, DRV_SPI_TRANSFER_HANDLE transferHandle, uintptr_t context)
{
    Stub_Local_t *ps = (Stub_Local_t *)context;
    (void)transferHandle;
    ASSERT((NULL != ps) && (ps->idx < TC6_MAX_INSTANCES));
    if (event == DRV_SPI_TRANSFER_EVENT_ERROR) {
        ASSERT(false);
    }
    if (event == DRV_SPI_TRANSFER_EVENT_PENDING) {
        return;
    }
    ps->busy = false;
    TC6_SpiBufferDone(ps->idx, (event == DRV_SPI_TRANSFER_EVENT_COMPLETE));
}

static void IntHandler(uintptr_t context)
{
    Stub_Local_t *ps = (Stub_Local_t *)context;
    ps->intIn++;
}