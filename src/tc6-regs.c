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
#include <string.h>
#include "tc6.h"
#include "tc6-conf.h"
#include "tc6-regs.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define DELAY_UNLOCK_EXT        (100u)
#define CONTROL_PROTECTION      (true)

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

typedef struct
{
    uint8_t mac[6];
    TC6_t *pTC6;
    void *pTag;
    uint32_t unlockExtTime;
    uint32_t readResult;
    uint8_t nodeId;
    uint8_t nodeCount;
    uint8_t burstCount;
    uint8_t burstTimer;
    uint8_t chipRev;
    bool extBlock;
    bool initialized;
    bool initDone;
    bool enablePlca;
    bool plcaChanged;
    bool promiscuous;
    bool txCutThrough;
    bool rxCutThrough;
} TC6Reg_t;

static TC6Reg_t m_reg[TC6_MAX_INSTANCES] = { 0 };

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static TC6Reg_t *GetContext(TC6_t *pTC6);
static void DoInitialization(TC6Reg_t *pReg);
static void HandlePlca(TC6Reg_t *pReg);
static void OnSoftResetCB(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag);
static void OnReadId1(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag);
static void OnReadId2(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag);
static void OnInitialRegCB(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag);
static void OnChipResult(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);
static bool ReadReg(TC6_t *pInst, uint32_t addr, uint32_t *pVal);
static bool ReadIndirectReg(TC6_t *pInst, uint32_t addr, uint32_t *pVal, uint32_t mask);
static int8_t GetSignedVal(uint32_t val);
static void InitChip(TC6_t *pInst);

static void OnInitDone(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag);
static void OnExtendedBlock(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);
static void OnClearStatus1(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);
static void OnStatus1(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);
static void OnClearStatus0(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);
static void OnStatus0(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

bool TC6Regs_Init(TC6_t *pTC6, void *pTag, const uint8_t mac[6], bool enablePlca, uint8_t nodeId, uint8_t nodeCount, uint8_t burstCount, uint8_t burstTimer, bool promiscuous, bool txCutThrough, bool rxCutThrough)
{
    TC6Reg_t *pReg = GetContext(pTC6);
    if (NULL != pReg) {
        pReg->pTag = pTag;
        pReg->enablePlca = enablePlca;
        pReg->nodeId = nodeId;
        pReg->nodeCount = nodeCount;
        pReg->burstCount = burstCount;
        pReg->burstTimer = burstTimer;
        pReg->promiscuous = promiscuous;
        pReg->txCutThrough = txCutThrough;
        pReg->rxCutThrough = rxCutThrough;
        (void)memcpy(pReg->mac, mac, 6);
        DoInitialization(pReg);
    }
    return ((NULL != pReg) && pReg->initialized);
}

void TC6Regs_CheckTimers(void)
{
    uint8_t i;
    /* Find existing entry */
    for (i = 0u; i < TC6_MAX_INSTANCES; i++) {
        TC6Reg_t *pReg = &m_reg[i];
        if ((0u != pReg->unlockExtTime) && ((TC6Regs_CB_GetTicksMs() - pReg->unlockExtTime) >= DELAY_UNLOCK_EXT)) {
            pReg->unlockExtTime = 0;
            TC6_UnlockExtendedStatus(pReg->pTC6);
        }
        DoInitialization(pReg);

        if (pReg->plcaChanged) {
            pReg->plcaChanged = false;
            HandlePlca(pReg);
        }
    }
}

bool TC6Regs_GetInitDone(TC6_t *pTC6)
{
    bool initDone = false;
    TC6Reg_t *pReg = GetContext(pTC6);
    if (NULL != pReg) {
        initDone = (pReg->initialized && pReg->initDone);
    }
    return initDone;
}

void TC6Regs_Reinit(TC6_t *pTC6)
{
    TC6Reg_t *pReg = GetContext(pTC6);
    if (NULL != pReg) {
        pReg->initialized = false;
        pReg->initDone = false;
    }
}

bool TC6Regs_SetPlca(TC6_t *pTC6, bool plcaEnable, uint8_t nodeId, uint8_t nodeCount)
{
    bool success = false;
    TC6Reg_t *pReg = GetContext(pTC6);
    if (NULL != pReg) {
        pReg->enablePlca = plcaEnable;
        pReg->nodeId = nodeId;
        pReg->nodeCount = nodeCount;
        pReg->plcaChanged = true;
        success = true;
    }
    return success;
}

uint8_t TC6Regs_GetChipRevision(TC6_t *pTC6)
{
    TC6Reg_t *pReg = GetContext(pTC6);
    return pReg->chipRev;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  CALLBACK FUNCTIONS FROM TC6 STACK                   */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

void TC6_CB_OnExtendedStatus(TC6_t *pInst, void *pGlobalTag)
{
   (void)pGlobalTag;
    TC6Reg_t *pReg = GetContext(pInst);
    pReg->unlockExtTime = TC6Regs_CB_GetTicksMs();
    while (!TC6_ReadRegister(pInst, 0x00000008, CONTROL_PROTECTION, OnStatus0, NULL)) {
        TC6_Service(pInst, true);
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

static void DoInitialization(TC6Reg_t *pReg)
{
    uint32_t regVal;
    uint16_t i = 0;
    
    /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
    /*                          AUTO GENERATED DEFINES                      */
    /*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

    static const MemoryMap_t TC6_MEMMAP[] = {
        {  .address=0x00000004,  .value=0x00000026,  .mask=0x00000000,  .op=MemOp_Write,  .secure=false }, /* CONFIG0 */
        {  .address=0x00010000,  .value=0x00000000,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  }, /* NETWORK_CONTROL */
        {  .address=0x00040091,  .value=0x00009660,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x00040081,  .value=0x00000080,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x00010077,  .value=0x00000028,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x00040043,  .value=0x000000FF,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x00040044,  .value=0x0000FFFF,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x00040045,  .value=0x00000000,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x00040053,  .value=0x000000FF,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x00040054,  .value=0x0000FFFF,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x00040055,  .value=0x00000000,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x00040040,  .value=0x00000002,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x00040050,  .value=0x00000002,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400E9,  .value=0x00009E50,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400F5,  .value=0x00001CF8,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400F4,  .value=0x0000C020,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400F8,  .value=0x00009B00,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400F9,  .value=0x00004E53,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400B0,  .value=0x00000103,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400B1,  .value=0x00000910,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400B2,  .value=0x00001D26,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400B3,  .value=0x0000002A,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400B4,  .value=0x00000103,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400B5,  .value=0x0000070D,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400B6,  .value=0x00001720,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400B7,  .value=0x00000027,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400B8,  .value=0x00000509,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400B9,  .value=0x00000E13,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400BA,  .value=0x00001C25,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },
        {  .address=0x000400BB,  .value=0x0000002B,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  },

        {  .address=0x0000000C,  .value=0x00000100,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  }, /* IMASK0 */
        {  .address=0x00040081,  .value=0x000000E0,  .mask=0x00000000,  .op=MemOp_Write,  .secure=true  }, /* DEEP_SLEEP_CTRL_1 */
    };

    static const uint32_t TC6_MEMMAP_LENGTH = (sizeof(TC6_MEMMAP) / sizeof(MemoryMap_t));

    if ((NULL != pReg) && !pReg->initialized) {
        pReg->initialized = true;
        TC6_Reset(pReg->pTC6);
        /* Perform Soft Reset with unprotected call */
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x00000003u /* RESET */, 0x1u, false, OnSoftResetCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        /* Perform Soft Reset with protected call */
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x00000003u /* RESET */, 0x1u, true, OnSoftResetCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        while (pReg->initialized && !TC6_ReadRegister(pReg->pTC6, 0x00000001, false, OnReadId1, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        pReg->chipRev = 0xFFu;
        while (pReg->initialized && !TC6_ReadRegister(pReg->pTC6, 0x000A0094, false, OnReadId2, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        while (pReg->initialized && (0xFFu == pReg->chipRev)) {
            /* Wait until Chip Revision is reported back */
            TC6_Service(pReg->pTC6, true);
        }
        /* Start with default settings */
        while (pReg->initialized && (i < TC6_MEMMAP_LENGTH)) {
            i += TC6_MultipleRegisterAccess(pReg->pTC6, &TC6_MEMMAP[i], (TC6_MEMMAP_LENGTH - i), OnInitialRegCB, NULL);
            if (i != TC6_MEMMAP_LENGTH) {
                TC6_Service(pReg->pTC6, true);
            }
        }
        regVal = (1u == pReg->chipRev) ? 0x5F21ul : 0x3F31ul;
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x000400D0, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        while (pReg->initialized && (2u == pReg->chipRev) && !TC6_WriteRegister(pReg->pTC6, 0x000400E0, 0x0000C000, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        /* MAC address setting */
        regVal = ((uint32_t)pReg->mac[3] << 24) | ((uint32_t)pReg->mac[2] << 16) | ((uint32_t)pReg->mac[1] << 8) | (uint32_t)pReg->mac[0];
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x00010024u /* SPEC_ADD2_BOTTOM */, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        regVal = ((uint32_t)pReg->mac[5] << 8) | (uint32_t)pReg->mac[4];
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x00010025u /* SPEC_ADD2_TOP */, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        /* MAC address setting, setting unique lower MAC address, back off time is generated out of that */
        regVal = ((uint32_t)pReg->mac[5] << 24) | ((uint32_t)pReg->mac[4] << 16) | ((uint32_t)pReg->mac[3] << 8) | (uint32_t)pReg->mac[2];
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x00010022u /* SPEC_ADD1_BOTTOM */, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }

        /* Promiscuous mode setting */
        regVal = pReg->promiscuous ? 0x10 : 0x0;
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x00010001 /* NETWORK_CONFIG */, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        if (pReg->initialized) {
            InitChip(pReg->pTC6);
        }

        HandlePlca(pReg);

        /* Cut Through / Store and Forward mode */
        regVal = 0x9026;
        if (pReg->txCutThrough) {
            regVal |= 0x200u;
        }
        if (pReg->rxCutThrough) {
            regVal |= 0x100u;
        }
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x00000004 /* CONFIG0 */, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x00010000 /* NETWORK_CONTROL */, 0xCu, CONTROL_PROTECTION, OnInitDone, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
    }
}

static void HandlePlca(TC6Reg_t *pReg)
{
    /* Collision Detection */
    uint32_t regVal = pReg->enablePlca ? 0x0083u : 0x8083u;
    while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x00040087u /* COL_DET_CTRL0 */, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
        TC6_Service(pReg->pTC6, true);
    }
    if (pReg->initialized && pReg->enablePlca) {
        /* T1S Phy Node Id and Max Node Count */
        regVal = ((uint32_t)pReg->nodeCount << 8) | pReg->nodeId;
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x0004CA02 /* PLCA_CONTROL_1_REGISTER */, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        /* PLCA Burst Count and Burst Timer */
        regVal = ((uint32_t)pReg->burstCount << 8) | pReg->burstTimer;
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x0004CA05 /* PLCA_BURST_MODE_REGISTER */, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
        /* Enable PLCA */
        regVal = ((uint32_t)1u << 15);
        while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x0004CA01/* PLCA_CONTROL_0_REGISTER */, regVal, CONTROL_PROTECTION, OnInitialRegCB, NULL)) {
            TC6_Service(pReg->pTC6, true);
        }
    }
}

static void OnSoftResetCB(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag)
{
    (void)pInst;
    (void)success;
    (void)addr;
    (void)value;
    (void)pTag;
    (void)pGlobalTag;
    /* Silently ignore anything */
}

static void OnReadId1(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag)
{
    TC6Reg_t *pReg = GetContext(pInst);
    (void)pInst;
    (void)addr;
    (void)pTag;
    (void)pGlobalTag;
    pReg->initialized &= success;
    if (success) {
        uint32_t oui = value >> 10;
        uint32_t model = (value >> 4) & 0x3FFu;
        if ((0x1F0u != oui) || (0x1Bu != model)) {
            TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Unsupported_Hardware, pReg->pTag);
            pReg->initialized = false;
        }
    }
}

static void OnReadId2(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag)
{
    TC6Reg_t *pReg = GetContext(pInst);
    (void)pInst;
    (void)addr;
    (void)pTag;
    (void)pGlobalTag;
    pReg->initialized &= success;
    if (success) {
        pReg->chipRev = (value & 0xFu);
        if (0u == pReg->chipRev) {
            TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Unsupported_Hardware, pReg->pTag);
            pReg->initialized = false;
        }
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
    pReg->initialized &= success;
}

static void OnChipResult(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    TC6Reg_t *pReg = GetContext(pInst);
    (void)addr;
    (void)value;
    (void)tag;
    (void)pGlobalTag;
    pReg->initialized &= success;
    if (success) {
        pReg->readResult = value;
    } else {
        pReg->readResult = 0xFFFFFFFEu;
    }
}

static bool ReadReg(TC6_t *pInst, uint32_t addr, uint32_t *pVal)
{
    TC6Reg_t *pReg = GetContext(pInst);
    pReg->readResult = 0xFFFFFFFFu;
    while (pReg->initialized && !TC6_ReadRegister(pInst, addr, CONTROL_PROTECTION, OnChipResult, NULL)) {
        TC6_Service(pInst, true);
    }
    while(pReg->initialized && (0xFFFFFFFFu == pReg->readResult)) {
        TC6_Service(pInst, true);
    }
    if (NULL != pVal) {
        *pVal = pReg->readResult;
    }
    return (0xFFFFFFFEu != pReg->readResult);
}

static bool ReadIndirectReg(TC6_t *pInst, uint32_t addr, uint32_t *pVal, uint32_t mask)
{
    TC6Reg_t *pReg = GetContext(pInst);
    uint32_t regVal = (addr & 0x000Fu);
    while (pReg->initialized && !TC6_WriteRegister(pInst, 0x000400D8, regVal, CONTROL_PROTECTION, NULL, NULL)) {
        TC6_Service(pInst, true);
    }
    while (pReg->initialized && !TC6_WriteRegister(pInst, 0x000400DA, 0x0002, CONTROL_PROTECTION, NULL, NULL)) {
        TC6_Service(pInst, true);
    }
    pReg->readResult = 0xFFFFFFFFu;
    while (pReg->initialized && !TC6_ReadRegister(pInst, 0x000400D9, CONTROL_PROTECTION, OnChipResult, NULL)) {
        TC6_Service(pInst, true);
    }
    while(pReg->initialized && (0xFFFFFFFFu == pReg->readResult)) {
        TC6_Service(pInst, true);
    }
    if (NULL != pVal) {
        *pVal = (pReg->readResult & mask);
    }
    return (0xFFFFFFFEu != pReg->readResult);
}

static int8_t GetSignedVal(uint32_t val)
{
    int8_t result;
    if ((val & (1u << 4u)) ==  (1u << 4u)) {
        /* negative value */
        result = (int8_t)(val | 0xE0u);
    } else {
        /* positive value */
        result = (int8_t)val;
    }
    return result;
}

static void InitChip(TC6_t *pInst)
{
    TC6Reg_t *pReg = GetContext(pInst);
    uint32_t val;
    int16_t tempParam;
    uint16_t cfgParam;
    int8_t initOffset1 = 0;
    int8_t initOffset2 = 0;
    uint16_t initValue3 = 0u;
    uint16_t initValue4 = 0u;
    uint16_t initValue5 = 0u;
    uint16_t initValue6 = 0u;
    uint16_t initValue7 = 0u;
    if (ReadIndirectReg(pInst, 0x5, &val, 0x40)) {
        if (0u == val) {
            TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Chip_Error, pReg->pTag);
            pReg->initialized = false;
        }
    }
    if (pReg->initialized && ReadIndirectReg(pInst, 0x4, &val, 0x1F)) {
        initOffset1 = GetSignedVal(val);
        if (initOffset1 < -5) {
            TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Chip_Error, pReg->pTag);
            pReg->initialized = false;
        }
    }
    if (pReg->initialized && ReadIndirectReg(pInst, 0x8, &val, 0x1F)) {
        initOffset2 = GetSignedVal(val);
    }
    if (pReg->initialized && ReadReg(pInst, 0x00040084, &val)) {
        initValue3 = (uint8_t)val;
    }
    if (pReg->initialized && ReadReg(pInst, 0x0004008A, &val)) {
        initValue4 = (uint8_t)val;
    }
    if (pReg->initialized && ReadReg(pInst, 0x000400AD, &val)) {
        initValue5 = (uint8_t)val;
    }
    if (pReg->initialized && ReadReg(pInst, 0x000400AE, &val)) {
        initValue6 = (uint8_t)val;
    }
    if (pReg->initialized && ReadReg(pInst, 0x000400AF, &val)) {
        initValue7 = (uint8_t)val;
    }

    /* CONFIG PARAMETER 3 */
    cfgParam = initValue3 & 0x000Fu;
    tempParam = (int16_t)9 + initOffset1; /* To be MISRA compliant */
    cfgParam |= (uint16_t)tempParam << 10;

    tempParam = (int16_t)14 + initOffset1; /* To be MISRA compliant */
    cfgParam |= (uint16_t)tempParam << 4;

    while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x00040084, cfgParam, CONTROL_PROTECTION, NULL, NULL)) {
        TC6_Service(pReg->pTC6, true);
    }

    /* CONFIG PARAMETER 4 */
    cfgParam = initValue4 & 0x3FFu;
    tempParam = (int16_t)40 + initOffset2; /* To be MISRA compliant */
    cfgParam |= (uint16_t)(tempParam) << 10;

    while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x0004008A, cfgParam, CONTROL_PROTECTION, NULL, NULL)) {
        TC6_Service(pReg->pTC6, true);
    }

    /* CONFIG PARAMETER 5 */
    cfgParam = initValue5 & 0xC0C0u;
    tempParam = (int16_t)5 + initOffset1; /* To be MISRA compliant */
    cfgParam |= (uint16_t)tempParam << 8;

    tempParam = (int16_t)9 + initOffset1; /* To be MISRA compliant */
    cfgParam |= (uint16_t)tempParam;

    while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x000400AD, cfgParam, CONTROL_PROTECTION, NULL, NULL)) {
        TC6_Service(pReg->pTC6, true);
    }

    /* CONFIG PARAMETER 6 */
    cfgParam = initValue6 & 0xC0C0u;
    tempParam = (int16_t)9 + initOffset1; /* To be MISRA compliant */
    cfgParam |= (uint16_t)tempParam << 8;

    tempParam = (int16_t)14 + initOffset1; /* To be MISRA compliant */
    cfgParam |= (uint16_t)tempParam;

    while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x000400AE, cfgParam, CONTROL_PROTECTION, NULL, NULL)) {
        TC6_Service(pReg->pTC6, true);
    }

    /* CONFIG PARAMETER 7 */
    cfgParam = initValue7 & 0xC0C0u;

    tempParam = (int16_t)17 + initOffset1; /* To be MISRA compliant */
    cfgParam |= (uint16_t)tempParam << 8;

    tempParam = (int16_t)22 + initOffset1; /* To be MISRA compliant */
    cfgParam |= (uint16_t)tempParam;

    while (pReg->initialized && !TC6_WriteRegister(pReg->pTC6, 0x000400AF, cfgParam, CONTROL_PROTECTION, NULL, NULL)) {
        TC6_Service(pReg->pTC6, true);
    }
}

static void OnInitDone(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag)
{
    TC6Reg_t *pReg = GetContext(pInst);
    (void)addr;
    (void)value;
    (void)pTag;
    (void)pGlobalTag;
    (void)success;
    TC6_EnableData(pInst, true);
    pReg->initDone = true;
}

static void OnExtendedBlock(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    TC6Reg_t *pReg = GetContext(pInst);
    (void)addr;
    (void)tag;
    (void)pGlobalTag;
    if (success) {
        uint8_t i;
        for (i = 0u; i < 32u; i++) {
            if (0u != (value & (1u << i))) {
                switch (i) {
                    case 0:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_SPI_Err_Int, pReg->pTag); break;
                    case 1:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_MAC_BMGR_Int, pReg->pTag); break;
                    case 2:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_MAC_Int, pReg->pTag); break;
                    case 3:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_HMX_Int, pReg->pTag); break;
                    case 31: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_GINT_Mask, pReg->pTag); break;
                    default: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_UnknownError, pReg->pTag); break;
                }
            }
        }
    } else {
        TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_UnknownError, pReg->pTag);
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
        while (!TC6_ReadRegister(pInst, 0x000A0087, CONTROL_PROTECTION, OnExtendedBlock, NULL)) {
            TC6_Service(pInst, true);
        }
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
                    case 0:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_RX_Non_Recoverable_Error, pReg->pTag); break;
                    case 1:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_TX_Non_Recoverable_Error, pReg->pTag); break;
                    case 17: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_FSM_State_Error, pReg->pTag); break;
                    case 18: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_SRAM_ECC_Error, pReg->pTag); break;
                    case 19: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Undervoltage, pReg->pTag); break;
                    case 20: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Internal_Bus_Error, pReg->pTag); break;
                    case 21: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_TX_Timestamp_Capture_Overflow_A, pReg->pTag); break;
                    case 22: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_TX_Timestamp_Capture_Overflow_B, pReg->pTag); break;
                    case 23: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_TX_Timestamp_Capture_Overflow_C, pReg->pTag); break;
                    case 24: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_TX_Timestamp_Capture_Missed_A, pReg->pTag); break;
                    case 25: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_TX_Timestamp_Capture_Missed_B, pReg->pTag); break;
                    case 26: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_TX_Timestamp_Capture_Missed_C, pReg->pTag); break;
                    case 27: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_MCLK_GEN_Status, pReg->pTag); break;
                    case 28: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_gPTP_PA_TS_EG_Status, pReg->pTag); break;
                    case 29: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Extended_Block_Status, pReg->pTag);
                         pReg->extBlock = true;
                        break;
                    default: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_UnknownError, pReg->pTag); break;
                }
            }
        }
        if (0u != value) {
            /* Write to clear pending flags */
            while (!TC6_WriteRegister(pInst, addr, value, CONTROL_PROTECTION, OnClearStatus1, NULL)) {
                TC6_Service(pInst, true);
            }
        }
    } else {
        TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_UnknownError, pReg->pTag);
    }
}

static void OnClearStatus0(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    (void)success;
    (void)addr;
    (void)value;
    (void)tag;
    (void)pGlobalTag;
    while (!TC6_ReadRegister(pInst, 0x00000009u, CONTROL_PROTECTION, OnStatus1, NULL)) {
        TC6_Service(pInst, true);
    }
}

static void OnStatus0(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *tag, void *pGlobalTag)
{
    TC6Reg_t *pReg = GetContext(pInst);
    (void)addr;
    (void)tag;
    (void)pGlobalTag;
    if (success) {
        uint8_t i;
        for (i = 0u; i < 32u; i++) {
            if (0u != (value & (1u << i))) {
                switch (i) {
                    case 0:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Transmit_Protocol_Error, pReg->pTag); break;
                    case 1:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Transmit_Buffer_Overflow_Error, pReg->pTag); break;
                    case 2:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Transmit_Buffer_Underflow_Error, pReg->pTag); break;
                    case 3:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Receive_Buffer_Overflow_Error, pReg->pTag); break;
                    case 4:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Loss_of_Framing_Error, pReg->pTag); break;
                    case 5:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Header_Error, pReg->pTag); break;
                    case 6:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Reset_Complete, pReg->pTag); break;
                    case 7:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_PHY_Interrupt, pReg->pTag); break;
                    case 8:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Transmit_Timestamp_Capture_Available_A, pReg->pTag); break;
                    case 9:  TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Transmit_Timestamp_Capture_Available_B, pReg->pTag); break;
                    case 10: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Transmit_Timestamp_Capture_Available_C, pReg->pTag); break;
                    case 11: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Transmit_Frame_Check_Sequence_Error, pReg->pTag); break;
                    case 12: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_Control_Data_Protection_Error, pReg->pTag); break;
                    default: TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_UnknownError, pReg->pTag); break;
                }
            }
        }
        if (0u == value) {
            while (!TC6_ReadRegister(pInst, 0x00000009, CONTROL_PROTECTION, OnStatus1, NULL)) {
                TC6_Service(pInst, true);
            }
        } else {
            /* Write to clear pending flags */
            while (!TC6_WriteRegister(pInst, addr, value, CONTROL_PROTECTION, OnClearStatus0, NULL)) {
                TC6_Service(pInst, true);
            }
        }
    } else {
        TC6Regs_CB_OnEvent(pInst, TC6Regs_Event_UnknownError, pReg->pTag);
    }
}
