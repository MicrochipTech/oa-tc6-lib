/**
 * TRAPS Generated Driver Header File 
 * 
 * @file      traps.h
 *            
 * @defgroup  trapsdriver Traps Driver
 *            
 * @brief     Traps driver with handler for all types of traps using dsPIC MCUs.
 *            
 * @version   Driver Version 1.0.1
 *            
 * @skipline  Device : dsPIC33CK256MP508
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

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

#ifndef TRAPS_H
#define TRAPS_H

// Section: Included Files
#include <stdint.h>

// Section: Data Type Definitions

/**
 @ingroup  trapsdriver
 @enum     TRAPS_ERROR_CODE
 @brief    Defines the TRAPS error codes
*/
enum TRAPS_ERROR_CODE 
{
// Traps
    TRAPS_OSC_FAIL = 0, /**< Oscillator Fail Trap vector */
    TRAPS_STACK_ERR = 1, /**< Stack Error Trap Vector */
    TRAPS_ADDRESS_ERR = 2, /**< Address error Trap vector */
    TRAPS_MATH_ERR = 3, /**< Math Error Trap vector */
    TRAPS_HARD_ERR = 7, /**< Generic Hard Trap vector */
    TRAPS_DOOVR_ERR = 10, /**< Generic Soft Trap vector */
    TRAPS_APLL_ERR = 11, /**< Generic Soft Trap vector */
    TRAPS_NVM_ERR = 12, /**< Generic Soft Trap vector */
    TRAPS_CAN_ERR = 13, /**< Generic Soft Trap vector */
};

// Section: Driver Interface Function

/**
 * @ingroup    trapsdriver
 * @brief      Stores the trap error code and waits forever.
 *             This is a weak attribute function. The user can 
 *             override and implement the same function without weak attribute.
 * @param[in]  code - trap error code
 * @return     none  
 */
void TRAPS_halt_on_error(uint16_t code);

#endif

