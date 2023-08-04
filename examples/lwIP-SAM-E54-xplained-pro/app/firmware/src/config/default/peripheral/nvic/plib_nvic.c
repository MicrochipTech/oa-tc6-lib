/*******************************************************************************
  NVIC PLIB Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    plib_nvic.c

  Summary:
    NVIC PLIB Source File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "device.h"
#include "plib_nvic.h"


// *****************************************************************************
// *****************************************************************************
// Section: NVIC Implementation
// *****************************************************************************
// *****************************************************************************

void NVIC_Initialize( void )
{
    /* Priority 0 to 7 and no sub-priority. 0 is the highest priority */
    NVIC_SetPriorityGrouping( 0x00 );

    /* Enable NVIC Controller */
    __DMB();
    __enable_irq();

    /* Enable the interrupt sources and configure the priorities as configured
     * from within the "Interrupt Manager" of MHC. */
    NVIC_SetPriority(EIC_EXTINT_0_IRQn, 7);
    NVIC_EnableIRQ(EIC_EXTINT_0_IRQn);
    NVIC_SetPriority(EIC_EXTINT_7_IRQn, 7);
    NVIC_EnableIRQ(EIC_EXTINT_7_IRQn);
    NVIC_SetPriority(DMAC_0_IRQn, 6);
    NVIC_EnableIRQ(DMAC_0_IRQn);
    NVIC_SetPriority(DMAC_1_IRQn, 6);
    NVIC_EnableIRQ(DMAC_1_IRQn);
    NVIC_SetPriority(DMAC_2_IRQn, 6);
    NVIC_EnableIRQ(DMAC_2_IRQn);
    NVIC_SetPriority(DMAC_3_IRQn, 6);
    NVIC_EnableIRQ(DMAC_3_IRQn);
    NVIC_SetPriority(DMAC_OTHER_IRQn, 6);
    NVIC_EnableIRQ(DMAC_OTHER_IRQn);
    NVIC_SetPriority(SERCOM2_0_IRQn, 6);
    NVIC_EnableIRQ(SERCOM2_0_IRQn);
    NVIC_SetPriority(SERCOM2_1_IRQn, 6);
    NVIC_EnableIRQ(SERCOM2_1_IRQn);
    NVIC_SetPriority(SERCOM2_2_IRQn, 6);
    NVIC_EnableIRQ(SERCOM2_2_IRQn);
    NVIC_SetPriority(SERCOM2_OTHER_IRQn, 6);
    NVIC_EnableIRQ(SERCOM2_OTHER_IRQn);
    NVIC_SetPriority(SERCOM3_0_IRQn, 6);
    NVIC_EnableIRQ(SERCOM3_0_IRQn);
    NVIC_SetPriority(SERCOM3_1_IRQn, 6);
    NVIC_EnableIRQ(SERCOM3_1_IRQn);
    NVIC_SetPriority(SERCOM3_2_IRQn, 6);
    NVIC_EnableIRQ(SERCOM3_2_IRQn);
    NVIC_SetPriority(SERCOM3_OTHER_IRQn, 6);
    NVIC_EnableIRQ(SERCOM3_OTHER_IRQn);
    NVIC_SetPriority(SERCOM4_0_IRQn, 6);
    NVIC_EnableIRQ(SERCOM4_0_IRQn);
    NVIC_SetPriority(SERCOM4_1_IRQn, 6);
    NVIC_EnableIRQ(SERCOM4_1_IRQn);
    NVIC_SetPriority(SERCOM4_2_IRQn, 6);
    NVIC_EnableIRQ(SERCOM4_2_IRQn);
    NVIC_SetPriority(SERCOM4_OTHER_IRQn, 6);
    NVIC_EnableIRQ(SERCOM4_OTHER_IRQn);
    NVIC_SetPriority(SERCOM6_0_IRQn, 6);
    NVIC_EnableIRQ(SERCOM6_0_IRQn);
    NVIC_SetPriority(SERCOM6_1_IRQn, 6);
    NVIC_EnableIRQ(SERCOM6_1_IRQn);
    NVIC_SetPriority(SERCOM6_2_IRQn, 6);
    NVIC_EnableIRQ(SERCOM6_2_IRQn);
    NVIC_SetPriority(SERCOM6_OTHER_IRQn, 6);
    NVIC_EnableIRQ(SERCOM6_OTHER_IRQn);
    NVIC_SetPriority(SERCOM7_0_IRQn, 6);
    NVIC_EnableIRQ(SERCOM7_0_IRQn);
    NVIC_SetPriority(SERCOM7_1_IRQn, 6);
    NVIC_EnableIRQ(SERCOM7_1_IRQn);
    NVIC_SetPriority(SERCOM7_2_IRQn, 6);
    NVIC_EnableIRQ(SERCOM7_2_IRQn);
    NVIC_SetPriority(SERCOM7_OTHER_IRQn, 6);
    NVIC_EnableIRQ(SERCOM7_OTHER_IRQn);

    /* Enable Usage fault */
    SCB->SHCSR |= (SCB_SHCSR_USGFAULTENA_Msk);
    /* Trap divide by zero */
    SCB->CCR   |= SCB_CCR_DIV_0_TRP_Msk;

    /* Enable Bus fault */
    SCB->SHCSR |= (SCB_SHCSR_BUSFAULTENA_Msk);

    /* Enable memory management fault */
    SCB->SHCSR |= (SCB_SHCSR_MEMFAULTENA_Msk);

}

void NVIC_INT_Enable( void )
{
    __DMB();
    __enable_irq();
}

bool NVIC_INT_Disable( void )
{
    bool processorStatus = (__get_PRIMASK() == 0U);

    __disable_irq();
    __DMB();

    return processorStatus;
}

void NVIC_INT_Restore( bool state )
{
    if( state == true )
    {
        __DMB();
        __enable_irq();
    }
    else
    {
        __disable_irq();
        __DMB();
    }
}
