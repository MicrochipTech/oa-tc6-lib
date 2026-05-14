/**
 * MAIN Generated Driver Header File
 * 
 * @file      system.h
 * 
 * @defgroup  systemdriver System Driver
 * 
 * @brief     System driver using dsPIC MCUs.
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

#include "xc.h"
#include "stdint.h"

#ifndef SYSTEM_H
#define	SYSTEM_H

/**
 * @ingroup systemdriver
 * @brief   Initializes the System module
 * @return  none 
 */
void SYSTEM_Initialize(void);

/**
 * @ingroup systemdriver
 * @brief   This inline function gets the base address of the DEVID register 
 *          for the currently selected device
 * @return  base address of the DEVID register 
 */
inline static uint32_t SYSTEM_DeviceIdRegisterAddressGet(void)
{
    return __DEVID_BASE;
}

#endif	/* SYSTEM_H */
/**
 End of File
*/