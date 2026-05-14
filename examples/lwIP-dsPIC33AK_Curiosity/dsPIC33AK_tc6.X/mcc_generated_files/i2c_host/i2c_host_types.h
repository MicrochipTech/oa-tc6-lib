/**
 * I2C Generated Driver Types Header File
 * 
 * @file      i2c_host_types.h
 * 
 * @ingroup   i2chostdriver
 * 
 * @brief     This is the generated driver types header file for the I2C driver
 *
 * @skipline @version   Firmware Driver Version 1.1.4
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

#ifndef I2C_HOST_TYPES_H
#define    I2C_HOST_TYPES_H

#include <stdint.h>

/**
 @ingroup  i2chostdriver
 @enum     I2C_HOST_ERROR
 @brief    This Enum can be used to know the Host Error Status. 
           Refer I2Cx_ErrorGet e.g. \ref I2C1_ErrorGet.
*/
enum I2C_HOST_ERROR
{
    I2C_HOST_ERROR_NONE,             /**< No Error */
    I2C_HOST_ERROR_NACK,             /**< Client returned NACK */
    I2C_HOST_ERROR_BUS_COLLISION,    /**< Bus Collision Error */
};

/**
 @ingroup  i2chostdriver
 @struct   I2C_TRANSFER_SETUP
 @brief    I2C Clock Speed (100KHZ to 1MHZ)
*/
struct I2C_TRANSFER_SETUP
{
  uint32_t clkSpeed;            ///< I2C Clock Speed
};

#endif


