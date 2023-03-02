/**
 * WATCHDOG Generated Driver Header File
 * 
 * @file      watchdog.h
 * 
 * @defgroup  watchdogdriver WDT Driver
 * 
 * @brief     Watchdog Timer Driver using dsPIC MCUs.
 *
 * @version   Driver Version 1.0.0
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

#ifndef WATCHDOG_H
#define WATCHDOG_H

#include <xc.h>

// Section: Type defines
 
/**
 * @ingroup  watchdogdriver
 * @brief    This macro holds the key value to clear Watchdog Timer (WDT)
*/
#define WATCHDOG_CLR_KEY 0x5743

/**
 * @ingroup  watchdogdriver
 * @brief    This inline function is used to enable the Watchdog Timer (WDT) using the software bit
 * @return   none  
 */
inline static void WATCHDOG_TimerSoftwareEnable(void)
{
    WDTCONLbits.ON = 1;
}

/**
 * @ingroup  watchdogdriver
 * @brief    This inline function is used to disable the Watchdog Timer (WDT) using the software bit
 * @return   none  
 */
inline static void WATCHDOG_TimerSoftwareDisable(void)
{
    WDTCONLbits.ON = 0;
}

/**
 * @ingroup  watchdogdriver
 * @brief    This inline function is used to clear the Watchdog Timer (WDT)
 * @return   none  
 */
inline static void WATCHDOG_TimerClear(void)
{
    WDTCONH = WATCHDOG_CLR_KEY;
}

#endif /* WATCHDOG_H */
/**
 End of File
*/


