/**
 * CLOCK Generated Driver Types Header File
 * 
 * @file      CLOCK_types.h
 * 
 * @ingroup   clockdriver
 * 
 * @brief     This is the generated driver types header file for the CLOCK driver
 *
 * @skipline @version   PLIB Version 1.1.2
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

#ifndef CLOCK_TYPES_H
#define CLOCK_TYPES_H

/**
 @ingroup  clockdriver
 @enum     CLOCK_GENERATOR
 @brief    CLOCK generator instances
*/
enum CLOCK_GENERATOR
{
    CLOCK_GENERATOR_1 = 1,    /**< Clock Generator 1 */
    CLOCK_GENERATOR_2 = 2,    /**< Clock Generator 2 */
    CLOCK_GENERATOR_3 = 3,    /**< Clock Generator 3 */
    CLOCK_GENERATOR_8 = 8,    /**< Clock Generator 8 */
    
    CLOCK_SYSTEM = 1,    /**< Clock for System */
    CLOCK_FRC = 2,    /**< Clock for FRC */
    CLOCK_WDT = 3,    /**< Clock for WDT */
    CLOCK_BFRC = 3,    /**< Clock for BFRC */
    CLOCK_UART = 8,    /**< Clock for UART */
    
    CLOCK_GENERATOR_MAX = 4
};

/**
 @ingroup  clockdriver
 @enum     CLOCK_FAIL_STATUS_MASKS
 @brief    Mask values for clock fail status 
*/
enum CLOCK_FAIL_STATUS_MASKS
{
    CLOCK_GEN1_FAIL_MASK = 0x1,    /**< Fail mask for Clock Generator 1 */
    CLOCK_GEN2_FAIL_MASK = 0x2,    /**< Fail mask for Clock Generator 2 */
    CLOCK_GEN3_FAIL_MASK = 0x4,    /**< Fail mask for Clock Generator 3 */
    CLOCK_GEN8_FAIL_MASK = 0x80,    /**< Fail mask for Clock Generator 8 */
    CLOCK_PLL1_FAIL_MASK = 0x1000000,    /**< Fail mask for PLL Generator 1 */
};

/**
 @ingroup  clockdriver
 @enum     CLOCK_MONITOR
 @brief    CLOCK monitor instances
*/
enum CLOCK_MONITOR
{
    CLOCK_MONITOR_MAX = 0
};

#endif // CLOCK_TYPES_H


