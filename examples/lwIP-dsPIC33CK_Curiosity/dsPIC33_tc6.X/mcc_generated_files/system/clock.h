/**
 * CLOCK Generated Driver Header File 
 * 
 * @file      clock.h
 *            
 * @defgroup  clockdriver Clock Driver
 *            
 * @brief     Clock configurator driver for System and Peripheral Clock using dsPIC MCUs.
 *            
 * @version   Driver Version 1.0.1
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

#ifndef CLOCK_H
#define CLOCK_H

// Section: Included Files

#include <stdbool.h>

/** 
  @ingroup  clockdriver
  @brief    This macro is used to read the System clock (FOSC) Frequency configured in 
            the MCC Melody User Interface
*/
#define CLOCK_SystemFrequencyGet()        (200000000UL)

/** 
  @ingroup  clockdriver
  @brief    This macro is used to read the Peripheral Clock (FP) Frequency 
            configured in the MCC Melody User Interface
*/
#define CLOCK_PeripheralFrequencyGet()    ((uint32_t)CLOCK_SystemFrequencyGet() / (uint32_t)2)

/** 
  @ingroup  clockdriver
  @brief    This macro is used to read the Instruction Clock (FCY) Frequency 
            configured in the MCC Melody User Interface
*/
#define CLOCK_InstructionFrequencyGet()   ((uint32_t)CLOCK_SystemFrequencyGet() / (uint32_t)2)

// Section: CLOCK APIs

/**
 * @ingroup  clockdriver
 * @brief    Initializes all the INTERNAL OSCILLATOR sources and clock switch configurations. 
 * @return   none  
 */
void CLOCK_Initialize(void);

/**
 * @ingroup  clockdriver
 * @brief    Returns Auxiliary PLL status
 * @pre      \ref CLOCK_Initialize() should be called for the associated
 *           function to work.
 * @return   true   - Auxiliary PLL locked
 * @return   false  - Auxiliary PLL not locked
 */
bool CLOCK_AuxPllLockStatusGet();

#endif    /* CLOCK_H */
/**
 End of File
*/


