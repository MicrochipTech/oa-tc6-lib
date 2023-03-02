/**
 * SCCP1-TIMER Generated Driver Header File 
 * 
 * @file      sccp1.h
 * 
 * @ingroup   timerdriver
 * 
 * @brief     This is the generated driver header file for the SCCP1-TIMER driver
 *
 * @version   Driver Version 1.4.0
 *
 * @skipline  Device : dsPIC33CK256MP508
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

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

#ifndef SCCP1_H
#define SCCP1_H

// Section: Included Files

#include <stddef.h>
#include <stdint.h>
#include <xc.h>
#include "timer_interface.h"

// Section: Data Type Definitions


/**
 * @ingroup  timerdriver
 * @brief    Structure object of type TIMER_INTERFACE with the custom name given by 
 *           the user in the Melody Driver User interface. The default name 
 *           e.g. Timer1 can be changed by the user in the TIMER user interface. 
 *           This allows defining a structure with application specific name using 
 *           the 'Custom Name' field. Application specific name allows the API Portability.
*/
extern const struct TIMER_INTERFACE Timer1;

/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_Initialize API
 */
#define Timer1_Initialize SCCP1_Timer_Initialize
/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_Deinitialize API
 */
#define Timer1_Deinitialize SCCP1_Timer_Deinitialize
/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_Tasks API
 */
#define Timer1_Tasks SCCP1_Timer_Tasks
/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_Start API
 */
#define Timer1_Start SCCP1_Timer_Start
/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_Stop API
 */
#define Timer1_Stop SCCP1_Timer_Stop
/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_PeriodCountSet API
 */
#define Timer1_PeriodCountSet SCCP1_Timer_PeriodCountSet
/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_PeriodSet API
 */
#define Timer1_PeriodSet SCCP1_Timer_PeriodSet
/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_PeriodGet API
 */
#define Timer1_PeriodGet SCCP1_Timer_PeriodGet
/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_CounterGet API
 */
#define Timer1_CounterGet SCCP1_Timer_CounterGet
/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_Counter16BitGet API
 */
#define Timer1_Counter16BitGet SCCP1_Timer_Counter16BitGet
/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_InterruptPrioritySet API
 */
#define Timer1_InterruptPrioritySet SCCP1_Timer_InterruptPrioritySet

/**
 * @ingroup  timerdriver
 * @brief    This macro defines the Custom Name for \ref SCCP1_Timer_TimeoutCallbackRegister API
 */
#define Timer1_TimeoutCallbackRegister SCCP1_Timer_TimeoutCallbackRegister

// Section: Driver Interface Functions

/**
 * @ingroup  timerdriver
 * @brief    Initializes the SCCP1 module 
 * @return   none  
 */
void SCCP1_Timer_Initialize (void);

/**
 * @ingroup  timerdriver
 * @brief    Deinitializes the SCCP1 to POR values
 * @return   none  
 */
void SCCP1_Timer_Deinitialize(void);

/**
 * @ingroup  timerdriver
 * @brief    Starts the timer
 * @pre      \ref SCCP1_Timer_Initialize must be called
 * @return   none  
 */
void SCCP1_Timer_Start(void);

/**
 * @ingroup  timerdriver
 * @brief    Stops the timer
 * @pre      \ref SCCP1_Timer_Initialize must be called
 * @return   none  
 */
void SCCP1_Timer_Stop(void);

/**
 * @ingroup  timerdriver
 * @brief    Sets the SCCP1-Timer period count value
 * @pre      \ref SCCP1_Timer_Initialize must be called
 * @param[in]  count - period value
 * @return   none  
 */
void SCCP1_Timer_PeriodSet(uint32_t count);

/**
 * @ingroup  timerdriver
 * @brief    This inline function gets the SCCP1-Timer period count value
 * @pre      \ref SCCP1_Timer_Initialize must be called
 * @return   Period count value  
 */
inline static uint32_t SCCP1_Timer_PeriodGet(void)
{
    if(CCP1CON1Lbits.T32 == 1)
    {
        return (((uint32_t)CCP1PRH << 16U) | (CCP1PRL) );
    }
    else
    {
        return (uint32_t) CCP1PRL;
    }
}

/**
 * @ingroup  timerdriver
 * @brief    This inline function gets the SCCP1-Timer elapsed count value
 * @return   Elapsed count value of the timer  
 */
inline static uint32_t SCCP1_Timer_CounterGet(void)
{
    if(CCP1CON1Lbits.T32 == 1)
    {
        return (((uint32_t)CCP1TMRH << 16U) | CCP1TMRL);
    }
    else
    {
        return (uint32_t)CCP1TMRL;
    }
}

/**
 * @ingroup  timerdriver
 * @brief    This inline function gets the SCCP1-Timer least significant 16 bit elapsed count value
 * @return   Least significant 16 bit elapsed count value of the timer  
 */
inline static uint16_t SCCP1_Timer_Counter16BitGet(void)
{
    return CCP1TMRL;
}

/**
 * @ingroup  timerdriver
 * @brief    Sets the Interrupt Priority Value 
 * @return   none  
 */
void SCCP1_Timer_InterruptPrioritySet(enum INTERRUPT_PRIORITY priority);


/**
 * @ingroup    timerdriver
 * @brief      This function can be used to override default callback and to define 
 *             custom callback for SCCP1 Timeout event.
 * @param[in]  handler - Address of the callback function.  
 * @return     none 
 */
void SCCP1_Timer_TimeoutCallbackRegister(void (*handler)(void));

/**
 * @ingroup    timerdriver
 * @brief      This function can be used to override default callback and to define 
 *             custom callback for SCCP1 Timeout event.
 * @param[in]  handler - Address of the callback function.  
 * @return     none 
 */
void SCCP1_TimeoutCallbackRegister(void* handler)__attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse SCCP1_Timer_TimeoutCallbackRegister instead. ")));

/**
 * @ingroup  timerdriver
 * @brief    This is the default callback with weak attribute. The user can 
 *           override and implement the default callback without weak attribute 
 *           or can register a custom callback function using  \ref SCCP1_Timer_TimeoutCallbackRegister.
 * @return   none  
 */
void SCCP1_TimeoutCallback(void);


/**
 * @ingroup  timerdriver
 * @brief    Sets the SCCP1-Timer period count value
 * @pre      \ref SCCP1_Timer_Initialize must be called
 * @param[in]  count - period value
 * @return   none  
 */
void SCCP1_Timer_PeriodCountSet(size_t count)__attribute__((deprecated ("\nThis will be removed in future MCC releases. \nUse SCCP1_Timer_PeriodSet instead. ")));

#endif //SCCP1_H

/**
 End of File
*/


