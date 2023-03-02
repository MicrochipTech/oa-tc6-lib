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
  Default Register Settings for Microchip LAN865x 10BASE-T1S MACPHY

  Company:
    Microchip Technology Inc.

  File Name:
    tc6-regs.c
*******************************************************************************/


#include <stddef.h>
#include "tc6.h"
#include "tc6-conf.h"
#include "tc6-regs.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          AUTO GENERATED DEFINES                      */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static const MemoryMap_t TC6_MEMMAP[] = {
    {  .address=0x00000004, .value=0x00000026,  .mask=0x00000000,  .op=MemOp_Write,            .secure=false },
    {  .address=0x00000004, .value=0x00000026,  .mask=0x00000000,  .op=MemOp_Write,            .secure=false },
    {  .address=0x00000004, .value=0x00000026,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00040091,  .value=0x00009660,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00040081,  .value=0x000000C0,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00010077,  .value=0x00000028,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00040043,  .value=0x000000FF,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00040044,  .value=0x0000FFFF,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00040045,  .value=0x00000000,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00040053,  .value=0x000000FF,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00040054,  .value=0x0000FFFF,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00040055,  .value=0x00000000,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00040040,  .value=0x00000002,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x00040050,  .value=0x00000002,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400D0,  .value=0x00005F21,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400E9,  .value=0x00009E50,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400F5,  .value=0x00001CF8,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400F4,  .value=0x0000C020,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400F8,  .value=0x00009B00,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400F9,  .value=0x00004E53,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400B0,  .value=0x00000103,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400B1,  .value=0x00000910,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400B2,  .value=0x00001D26,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400B3,  .value=0x0000002A,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400B4,  .value=0x00000103,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400B5,  .value=0x0000070D,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400B6,  .value=0x00001720,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400B7,  .value=0x00000027,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400B8,  .value=0x00000509,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400B9,  .value=0x00000E13,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400BA,  .value=0x00001C25,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },
    {  .address=0x000400BB,  .value=0x0000002B,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  },

    {  .address=0x00040087,  .value=0x00000083,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  }, /* COL_DET_CTRL0 */
    {  .address=0x0000000C,  .value=0x00000100,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  }, /* IMASK0 */
    {  .address=0x00040081,  .value=0x000000E0,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  }, /* DEEP_SLEEP_CTRL_1 */
    {  .address=0x00010000,  .value=0x0000000C,  .mask=0x00000000,  .op=MemOp_Write,            .secure=true  }, /* NETWORK_CONTROL */
};

const uint32_t TC6_MEMMAP_LENGTH = (sizeof(TC6_MEMMAP) / sizeof(MemoryMap_t));

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define DELAY_EFUSE             (1u)
#define DELAY_UNLOCK_EXT        (100u)
#define CONTROL_PROTECTION      (true)

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

typedef struct
{
    TC6_t *pTC6;
    uint32_t unlockExtTime;
    bool extBlock;
    bool initSuccess;
} TC6Reg_t;

static TC6Reg_t m_reg[TC6_MAX_INSTANCES] = { 0 };

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static TC6Reg_t *GetContext(TC6_t *pTC6);
static void InitDelay(void);
static void OnInitialRegCB(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag);
static void OnEFuseResult(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);
static bool ReadEFuseReg(TC6_t *pInst, uint32_t addr, uint32_t *pVal);
static int8_t GetSignedVal(uint32_t val);
static void WriteRegisterBits(TC6_t *pInst, uint32_t addr, uint8_t start, uint8_t end, uint32_t value);
static void InitTrim(TC6_t *pInst);

static void OnExtendedBlock(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);
static void OnClearStatus1(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);
static void OnStatus1(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);
static void OnClearStatus0(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);
static void OnStatus0(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

bool TC6Regs_Init(TC6_t *pTC6, const uint8_t mac[6], bool enablePlca, uint8_t nodeId, uint8_t nodeCount, uint8_t burstCount, uint8_t burstTimer, bool promiscuous, bool txCutThrough, bool rxCutThrough)
{
    uint32_t i = 0;
    uint32_t regVal;
    TC6Reg_t *pReg = GetContext(pTC6);
    if (NULL != pReg) {
        pReg->initSuccess = true;
        while (pReg->initSuccess & (i < TC6_MEMMAP_LENGTH)) {
            i += TC6_MultipleRegisterAccess(pTC6, &TC6_MEMMAP[i], (uint16_t)(TC6_MEMMAP_LENGTH - i), OnInitialRegCB, NULL);
            if (i != TC6_MEMMAP_LENGTH) {
                TC6_Service(pTC6, true);
            }
        }
        if (enablePlca) {
            /* T1S Phy Node Id and Max Node Count */
            regVal = (uint32_t)(nodeCount << 8) | nodeId;
            while (pReg->initSuccess && !TC6_WriteRegister(pTC6, 0x0004CA02, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
                TC6_Service(pTC6, true);
            }
            /* PLCA Burst Count and Burst Timer */
            regVal = (uint32_t)(burstCount << 8) | burstTimer;
            while (pReg->initSuccess && !TC6_WriteRegister(pTC6, 0x0004CA05, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
                TC6_Service(pTC6, true);
            }
            /* Enable PLCA */
            regVal = ((uint32_t)1u << 15);
            while (pReg->initSuccess && !TC6_WriteRegister(pTC6, 0x0004CA01, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
                TC6_Service(pTC6, true);
            }
        }
        /* MAC address setting */
        regVal = ((uint32_t)mac[3] << 24) | ((uint32_t)mac[2] << 16) | ((uint32_t)mac[1] << 8) | (uint32_t)mac[0];
        while (pReg->initSuccess && !TC6_WriteRegister(pTC6, 0x00010024, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pTC6, true);
        }
        regVal = ((uint32_t)mac[5] << 8) | (uint32_t)mac[4];
        while (pReg->initSuccess && !TC6_WriteRegister(pTC6, 0x00010025, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pTC6, true);
        }
        /* MAC address setting, setting unique lower MAC address, back off time is generated out of that */
        regVal = ((uint32_t)mac[5] << 24) | ((uint32_t)mac[4] << 16) | ((uint32_t)mac[3] << 8) | (uint32_t)mac[2];
        while (pReg->initSuccess && !TC6_WriteRegister(pTC6, 0x00010022, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pTC6, true);
        }
        /* Promiscuous mode setting */
        regVal = promiscuous ? 0x10 : 0x0;
        while (pReg->initSuccess && !TC6_WriteRegister(pTC6, 0x00010001, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pTC6, true);
        }
        /* Unmasking Receive Buffer Overflow Int*/
        while (pReg->initSuccess && !TC6_ReadModifyWriteRegister(pTC6, 0x0000000C, 0, (1 << 3), CONTROL_PROTECTION, NULL, NULL)) {
            TC6_Service(pTC6, true);
        }
        /* Cut Through / Store and Forward mode */
        regVal = 0x9026;
        if (txCutThrough) {
            regVal |= (1u << 9u);
        }
        if (rxCutThrough) {
            regVal |= (1u << 8u);
        }
        while (pReg->initSuccess && !TC6_WriteRegister(pTC6, 0x00000004, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pTC6, true);
        }
        InitTrim(pTC6);
        TC6_EnableData(pTC6, true);
    }
    return ((NULL != pReg) && (pReg->initSuccess));
}

void TC6Regs_CheckTimers(void)
{
    TC6Reg_t *pReg = NULL;
    uint8_t i;
    /* Find existing entry */
    for (i = 0u; (NULL == pReg) && (i < TC6_MAX_INSTANCES); i++) {
        pReg = &m_reg[i];
        if ((0 != pReg->unlockExtTime) && ((TC6Regs_CB_GetTicksMs() - pReg->unlockExtTime) >= DELAY_UNLOCK_EXT)) {
            pReg->unlockExtTime = 0;
            TC6_UnlockExtendedStatus(pReg->pTC6);
        }
    }
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  CALLBACK FUNCTIONS FROM TC6 STACK                   */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

void TC6_CB_OnExtendedStatus(TC6_t *pInst, void *pGlobalTag)
{
   (void)pGlobalTag;
    TC6Reg_t *pReg = GetContext(pInst);
    pReg->unlockExtTime = TC6Regs_CB_GetTicksMs();
    if (!TC6_ReadRegister(pInst, 0x00000008, CONTROL_PROTECTION, OnStatus0, NULL)) {
        TC6_UnlockExtendedStatus(pReg->pTC6);
    }
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  PRIVATE FUNCTION IMPLEMENTATIONS                    */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static TC6Reg_t *GetContext(TC6_t *pTC6)
{
    TC6Reg_t *pReg = NULL;
    uint8_t i;
    /* Find existing entry */
    for (i = 0u; (NULL == pReg) && (i < TC6_MAX_INSTANCES); i++) {
        if (m_reg[i].pTC6 == pTC6) {
            pReg = &m_reg[i];
        }
    }
    /* If not found, find free entry */
    for (i = 0u; (NULL == pReg) && (i < TC6_MAX_INSTANCES); i++) {
        if (NULL == m_reg[i].pTC6) {
            pReg = &m_reg[i];
            pReg->pTC6 = pTC6;
        }
    }
    return pReg;
}

static void InitDelay(void)
{
    uint32_t startTime = TC6Regs_CB_GetTicksMs();
    while ((TC6Regs_CB_GetTicksMs() - startTime) <  DELAY_EFUSE) {
        /* Wait */
    }
}

static void OnInitialRegCB(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag)
{
    TC6Reg_t *pReg = GetContext(pInst);
    (void)pInst;
    (void)addr;
    (void)value;
    (void)pTag;
    (void)pGlobalTag;
    pReg->initSuccess &= success;
}

static void OnEFuseResult(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    uint32_t *pVal = tag;
    (void)pInst;
    (void)addr;
    (void)value;
    (void)pGlobalTag;
    if (NULL != pVal) {
        if (success) {
            *pVal = value;
        } else {
            *pVal = 0xFFFFFFFEu;
        }
    }
}

static bool ReadEFuseReg(TC6_t *pInst, uint32_t addr, uint32_t *pVal)
{
    uint32_t regVal = (addr & 0x000Fu);
    while (!TC6_WriteRegister(pInst, 0x000400D8, regVal, CONTROL_PROTECTION, NULL, NULL)) {
        TC6_Service(pInst, true);
    }
    while (!TC6_WriteRegister(pInst, 0x000400DA, 0x0002, CONTROL_PROTECTION, NULL, NULL)) {
        TC6_Service(pInst, true);
    }
    InitDelay();
    regVal = 0xFFFFFFFFu;
    while (!TC6_ReadRegister(pInst, 0x000400D9, CONTROL_PROTECTION, OnEFuseResult, &regVal)) {
        TC6_Service(pInst, true);
    }
    while(0xFFFFFFFFu == regVal) {
        TC6_Service(pInst, true);
    }
    *pVal = regVal;
    return (0xFFFFFFFEu != regVal);
}

static int8_t GetSignedVal(uint32_t val)
{
    int8_t result;
    if ((val & (1u << 4u)) ==  (1u << 4u))	{
        /* negative value */
        result = (int8_t)(val | 0xE0u);
    } else {
        /* positive value */
        result = (int8_t)val;
    }
    return result;
}

static void WriteRegisterBits(TC6_t *pInst, uint32_t addr, uint8_t start, uint8_t end, uint32_t value)
{
    uint32_t mask = 0;
	uint8_t i;
    for (i = start; i <= end; i++) {
		mask = mask | (1u << i);
    }
    while (!TC6_ReadModifyWriteRegister(pInst, addr, (value << start), mask, CONTROL_PROTECTION, NULL, NULL)) {
        TC6_Service(pInst, true);
    }
}

static void InitTrim(TC6_t *pInst)
{
    TC6Reg_t *pReg = GetContext(pInst);
    uint32_t val;
    int8_t efuseA4 = 0;
    int8_t efuseA8 = 0;
    bool isTrimmed = false;
    if (ReadEFuseReg(pInst, 0x5, &val)) {
        isTrimmed = (0u != (val & 0x40u));
    }
    if (isTrimmed) {
        isTrimmed = false;
        if (ReadEFuseReg(pInst, 0x4, &val)) {
            efuseA4 = GetSignedVal(val);

            if (ReadEFuseReg(pInst, 0x8, &val)) {
                efuseA8 = GetSignedVal(val);

                if ((efuseA4 < -5) || (efuseA8 < -5) || (efuseA4 > 5) || (efuseA8 > 5)) {
                    /* Phy is trimmed, but out of range */
                    pReg->initSuccess = false;
                } else {
                    val = (uint32_t)(0x9 + efuseA4);
                    WriteRegisterBits(pInst, 0x00040084, 10, 15, val);

                    val = (uint32_t)(0xE + efuseA4);
                    WriteRegisterBits(pInst, 0x00040084, 4,  9, val);

                    val = (uint32_t)(0x28 + efuseA8);
                    WriteRegisterBits(pInst, 0x0004008A, 10, 15, val);

                    val = (uint32_t)(0x5 + efuseA4);
                    WriteRegisterBits(pInst, 0x000400AD, 8, 13, val);

                    val = (uint32_t)(0x9 + efuseA4);
                    WriteRegisterBits(pInst, 0x000400AD, 0,  5, val);

                    val = (uint32_t)(0x9 + efuseA4);
                    WriteRegisterBits(pInst, 0x000400AE, 8, 13, val);

                    val = (uint32_t)(0xE + efuseA4);
                    WriteRegisterBits(pInst, 0x000400AE,  0,  5, val);

                    val = (uint32_t)(0x11 + efuseA4);
                    WriteRegisterBits(pInst, 0x000400AF, 8, 13, val);

                    val = (uint32_t)(0x16 + efuseA4);
                    WriteRegisterBits(pInst, 0x000400AF, 0,  5, val);
                    isTrimmed = true;
                }
            }
        }
    }
}

static void OnExtendedBlock(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    (void)pInst;
    (void)addr;
    (void)tag;
    (void)pGlobalTag;
    if (success) {
        uint8_t i;
        for (i = 0u; i < 32u; i++) {
            if (0u != (value & (1u << i))) {
                switch (i) {
                    case 0:  TC6Regs_CB_OnEvent(TC6Regs_Event_SPI_Err_Int); break;
                    case 1:  TC6Regs_CB_OnEvent(TC6Regs_Event_MAC_BMGR_Int); break;
                    case 2:  TC6Regs_CB_OnEvent(TC6Regs_Event_MAC_Int); break;
                    case 3:  TC6Regs_CB_OnEvent(TC6Regs_Event_HMX_Int); break;
                    case 31: TC6Regs_CB_OnEvent(TC6Regs_Event_GINT_Mask); break;
                    default: TC6Regs_CB_OnEvent(TC6Regs_Event_UnknownError); break;
                }
            }
        }
    } else {
        TC6Regs_CB_OnEvent(TC6Regs_Event_UnknownError);
    }
}

static void OnClearStatus1(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    TC6Reg_t *pReg = GetContext(pInst);
    (void)success;
    (void)addr;
    (void)value;
    (void)tag;
    (void)pGlobalTag;
    if (pReg->extBlock) {
        pReg->extBlock = false;
        TC6_ReadRegister(pInst, 0x000A0087, CONTROL_PROTECTION, OnExtendedBlock, NULL);
    }
}

static void OnStatus1(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    TC6Reg_t *pReg = GetContext(pInst);
    (void)addr;
    (void)tag;
    (void)pGlobalTag;
    pReg->extBlock = false;
    if (success) {
        uint8_t i;
        for (i = 0u; i < 32u; i++) {
            if (0u != (value & (1u << i))) {
                switch (i) {
                    case 0:  TC6Regs_CB_OnEvent(TC6Regs_Event_RX_Non_Recoverable_Error); break;
                    case 1:  TC6Regs_CB_OnEvent(TC6Regs_Event_TX_Non_Recoverable_Error); break;
                    case 17: TC6Regs_CB_OnEvent(TC6Regs_Event_FSM_State_Error); break;
                    case 18: TC6Regs_CB_OnEvent(TC6Regs_Event_SRAM_ECC_Error); break;
                    case 19: TC6Regs_CB_OnEvent(TC6Regs_Event_Undervoltage); break;
                    case 20: TC6Regs_CB_OnEvent(TC6Regs_Event_Internal_Bus_Error); break;
                    case 21: TC6Regs_CB_OnEvent(TC6Regs_Event_TX_Timestamp_Capture_Overflow_A); break;
                    case 22: TC6Regs_CB_OnEvent(TC6Regs_Event_TX_Timestamp_Capture_Overflow_B); break;
                    case 23: TC6Regs_CB_OnEvent(TC6Regs_Event_TX_Timestamp_Capture_Overflow_C); break;
                    case 24: TC6Regs_CB_OnEvent(TC6Regs_Event_TX_Timestamp_Capture_Missed_A); break;
                    case 25: TC6Regs_CB_OnEvent(TC6Regs_Event_TX_Timestamp_Capture_Missed_B); break;
                    case 26: TC6Regs_CB_OnEvent(TC6Regs_Event_TX_Timestamp_Capture_Missed_C); break;
                    case 27: TC6Regs_CB_OnEvent(TC6Regs_Event_MCLK_GEN_Status); break;
                    case 28: TC6Regs_CB_OnEvent(TC6Regs_Event_gPTP_PA_TS_EG_Status); break;
                    case 29: TC6Regs_CB_OnEvent(TC6Regs_Event_Extended_Block_Status);
                         pReg->extBlock = true;
                        break;
                    default: TC6Regs_CB_OnEvent(TC6Regs_Event_UnknownError); break;
                }
            }
        }
        if (0u != value) {
            /* Write to clear pending flags */
            TC6_WriteRegister(pInst, addr, value, CONTROL_PROTECTION, OnClearStatus1, NULL);
        }
    } else {
        TC6Regs_CB_OnEvent(TC6Regs_Event_UnknownError);
    }
}

static void OnClearStatus0(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    (void)success;
    (void)addr;
    (void)value;
    (void)tag;
    (void)pGlobalTag;
    TC6_ReadRegister(pInst, 0x00000009u, CONTROL_PROTECTION, OnStatus1, NULL);
}

static void OnStatus0(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    (void)addr;
    (void)tag;
    (void)pGlobalTag;
    if (success) {
        uint8_t i;
        for (i = 0u; i < 32u; i++) {
            if (0u != (value & (1u << i))) {
                switch (i) {
                    case 0:  TC6Regs_CB_OnEvent(TC6Regs_Event_Transmit_Protocol_Error); break;
                    case 1:  TC6Regs_CB_OnEvent(TC6Regs_Event_Transmit_Buffer_Overflow_Error); break;
                    case 2:  TC6Regs_CB_OnEvent(TC6Regs_Event_Transmit_Buffer_Underflow_Error); break;
                    case 3:  TC6Regs_CB_OnEvent(TC6Regs_Event_Receive_Buffer_Overflow_Error); break;
                    case 4:  TC6Regs_CB_OnEvent(TC6Regs_Event_Loss_of_Framing_Error); break;
                    case 5:  TC6Regs_CB_OnEvent(TC6Regs_Event_Header_Error); break;
                    case 6:  TC6Regs_CB_OnEvent(TC6Regs_Event_Reset_Complete); break;
                    case 7:  TC6Regs_CB_OnEvent(TC6Regs_Event_PHY_Interrupt); break;
                    case 8:  TC6Regs_CB_OnEvent(TC6Regs_Event_Transmit_Timestamp_Capture_Available_A); break;
                    case 9:  TC6Regs_CB_OnEvent(TC6Regs_Event_Transmit_Timestamp_Capture_Available_B); break;
                    case 10: TC6Regs_CB_OnEvent(TC6Regs_Event_Transmit_Timestamp_Capture_Available_C); break;
                    case 11: TC6Regs_CB_OnEvent(TC6Regs_Event_Transmit_Frame_Check_Sequence_Error); break;
                    case 12: TC6Regs_CB_OnEvent(TC6Regs_Event_Control_Data_Protection_Error); break;
                    default: TC6Regs_CB_OnEvent(TC6Regs_Event_UnknownError); break;
                }
            }
        }
        if (0u == value) {
            TC6_ReadRegister(pInst, 0x00000009, CONTROL_PROTECTION, OnStatus1, NULL);
        } else {
            /* Write to clear pending flags */
            TC6_WriteRegister(pInst, addr, value, CONTROL_PROTECTION, OnClearStatus0, NULL);
        }
    } else {
        TC6Regs_CB_OnEvent(TC6Regs_Event_UnknownError);
    }
}
