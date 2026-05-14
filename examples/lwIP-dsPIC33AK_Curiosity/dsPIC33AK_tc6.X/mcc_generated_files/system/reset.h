/**
 * RESET Generated Driver Header File
 * 
 * @file      reset.h
 *            
 * @defgroup  resetdriver Reset Driver
 *            
 * @brief     This is the generated driver header file for the RESET driver
 *
 * @skipline @version   PLIB Version 1.0.1
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

#ifndef RESET_H
#define    RESET_H

#include <stdint.h>
#include "reset_types.h"

/**
 * @ingroup  resetdriver
 * @brief    Returns the cause of previous reset
 * @pre      This function should be called before any use of CLRWDT
 *           since it has a side-effect of clearing the appropriate bits in the
 *           register showing reset cause (see DS70602B page 8-10)
 * @return   none  
 */
uint32_t RESET_CauseGet(void);

/**
 * @ingroup  resetdriver
 * @brief    It handles the reset cause by clearing the cause register values.
 *           This is a weak attribute function. The user can 
 *           override and implement the same function without weak attribute.
 * @return   none  
 */
void RESET_CauseHandler(void);

/**
 * @ingroup  resetdriver
 * @brief    Clears the Reset Cause register
 * @return   none  
 */
void RESET_CauseClearAll(void);

#endif    /* RESET_H */
/**
 End of File
*/
