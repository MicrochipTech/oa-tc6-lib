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
    tc6-regs.h
*******************************************************************************/

#ifndef TC6_REGS_H_
#define TC6_REGS_H_

#include <stdint.h>
#include "tc6.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                            DEFINITIONS                               */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

typedef enum
{
    TC6Regs_Event_UnknownError = 0,
    TC6Regs_Event_Transmit_Protocol_Error,
    TC6Regs_Event_Transmit_Buffer_Overflow_Error,
    TC6Regs_Event_Transmit_Buffer_Underflow_Error,
    TC6Regs_Event_Receive_Buffer_Overflow_Error,
    TC6Regs_Event_Loss_of_Framing_Error,
    TC6Regs_Event_Header_Error,
    TC6Regs_Event_Reset_Complete,
    TC6Regs_Event_PHY_Interrupt,
    TC6Regs_Event_Transmit_Timestamp_Capture_Available_A,
    TC6Regs_Event_Transmit_Timestamp_Capture_Available_B,
    TC6Regs_Event_Transmit_Timestamp_Capture_Available_C,
    TC6Regs_Event_Transmit_Frame_Check_Sequence_Error,
    TC6Regs_Event_Control_Data_Protection_Error,
    TC6Regs_Event_RX_Non_Recoverable_Error,
    TC6Regs_Event_TX_Non_Recoverable_Error,
    TC6Regs_Event_FSM_State_Error,
    TC6Regs_Event_SRAM_ECC_Error,
    TC6Regs_Event_Undervoltage,
    TC6Regs_Event_Internal_Bus_Error,
    TC6Regs_Event_TX_Timestamp_Capture_Overflow_A,
    TC6Regs_Event_TX_Timestamp_Capture_Overflow_B,
    TC6Regs_Event_TX_Timestamp_Capture_Overflow_C,
    TC6Regs_Event_TX_Timestamp_Capture_Missed_A,
    TC6Regs_Event_TX_Timestamp_Capture_Missed_B,
    TC6Regs_Event_TX_Timestamp_Capture_Missed_C,
    TC6Regs_Event_MCLK_GEN_Status,
    TC6Regs_Event_gPTP_PA_TS_EG_Status,
    TC6Regs_Event_Extended_Block_Status,
    TC6Regs_Event_SPI_Err_Int,
    TC6Regs_Event_MAC_BMGR_Int,
    TC6Regs_Event_MAC_Int,
    TC6Regs_Event_HMX_Int,
    TC6Regs_Event_GINT_Mask
} TC6Regs_Event_t;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                            PUBLIC API                                */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/** \brief Initializes the LAN865x with its default register settings
 *  \note Must be called before any other functions of this component.
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param mac - The 6 Byte public visible MAC address of the TC6 MAC.
 *  \return True, if interface driver was created and registered to lwIP. false, otherwise.
 */
bool TC6Regs_Init(TC6_t *pInst, const uint8_t mac[6], bool enablePlca, uint8_t nodeId, uint8_t nodeCount, uint8_t burstCount, uint8_t burstTimer, bool promiscuous, bool txCutThrough, bool rxCutThrough);


/** \brief Checks internal timers and trigger corresponding actions
 *  \note Must be called cyclic (slow delay is fine (< 1 second))
 */
void TC6Regs_CheckTimers(void);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                   Implementation of TC6 Callback                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/** \brief This component implements the callback TC6_CB_OnExtendedStatus defined in TC6.h
 *  \note Integrator must not implement this function, as this is already done inside this component.
 * \note This function must be implemented by the integrator.
 * \param pInst - The pointer returned by TC6_Init.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
void TC6_CB_OnExtendedStatus(TC6_t *pInst, void *pGlobalTag);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                        CALLBACK SECTION                              */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/**
 * \brief Callback when ever this component needs to get the current tick count in Milliseconds
 * \note This function must be implemented by the integrator.
 * \return Integrator need to return the current tick count.
 */
uint32_t TC6Regs_CB_GetTicksMs(void);

/**
 * \brief Callback when ever an GMAC/PHY event occured
 * \note This function must be implemented by the integrator.
 * \param event - Enumeration matching to the occured event.
 */
 void TC6Regs_CB_OnEvent(TC6Regs_Event_t event);

#endif /* TC6_REGS_H_ */
