/**
 * TIMER Generated Driver Interface Header File
 * 
 * @file      timer_interface.h
 * 
 * @defgroup  timerdriver Timer Driver
 * 
 * @brief     Timer Driver is a 16-bit driver or 32-bit timer that can operate as a 
 *            free-running interval timer using dsPIC MCUs.
 *
 * @skipline  Device : dsPIC33AK512MPS512
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

// Section: Included Files
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "../system/interrupt_types.h"

// Section: Data Type Definitions

/**
 @ingroup  timerdriver
 @struct   TIMER_INTERFACE
 @brief    Structure containing the function pointers of TIMER driver
*/
struct TIMER_INTERFACE
{
    void (*Initialize)(void);
    ///< Pointer to SCCPx_Timer_Initialize or TMRx_Initialize e.g. \ref SCCP1_Timer_Initialize or \ref TMR1_Initialize 
    
    void (*Deinitialize)(void);
    ///< Pointer to SCCPx_Timer_Deinitialize or TMRx_Deinitialize e.g. \ref SCCP1_Timer_Deinitialize or \ref TMR1_Deinitialize
    
    void (*Start)(void);
    ///< Pointer to SCCPx_Timer_Start or TMRx_Start e.g. \ref SCCP1_Timer_Start or \ref TMR1_Start
    
    void (*Stop)(void);
    ///< Pointer to SCCPx_Timer_Stop or TMRx_Stop e.g. \ref SCCP1_Timer_Stop or \ref TMR1_Stop
    
    void (*PeriodSet)(uint32_t count);
    ///< Pointer to SCCPx_Timer_PeriodSet or TMRx_PeriodSet e.g. \ref SCCP1_Timer_PeriodSet or \ref TMR1_PeriodSet
	
	uint32_t (*PeriodGet)(void);
    ///< Pointer to SCCPx_Timer_PeriodGet or TMRx_PeriodGet e.g. \ref SCCP1_Timer_PeriodGet or \ref TMR1_PeriodGet

    uint32_t (*CounterGet)(void);
    ///< Pointer to SCCPx_Timer_CounterGet or TMRx_CounterGet e.g. \ref SCCP1_Timer_CounterGet or \ref TMR1_CounterGet
    
    void (*InterruptPrioritySet)(enum INTERRUPT_PRIORITY priority);
    ///< Pointer to SCCPx_Timer_InterruptPrioritySet or TMRx_InterruptPrioritySet e.g. \ref SCCP1_Timer_InterruptPrioritySet or \ref TMR1_InterruptPrioritySet

    void (*TimeoutCallbackRegister)(void (*CallbackHandler)(void));
    ///< Pointer to SCCPx_TimeoutCallbackRegister or TMRx_TimeoutCallbackRegister e.g. \ref SCCP1_TimeoutCallbackRegister or \ref TMR1_TimeoutCallbackRegister
    
    void (*Tasks)(void);
    ///< Pointer to SCCPx_Timer_Tasks or TMRx_Tasks e.g. \ref SCCP1_Timer_Tasks or \ref TMR1_Tasks (Supported only in polling mode)
};

#endif // TIMER_INTERFACE_H

