/**
 * RESET Generated Driver Types Header File
 * 
 * @file      reset_types.h
 *            
 * @ingroup   resetdriver
 *            
 * @brief     This is the generated driver types header file for the RESET driver
 *            
 * @version   Driver Version 1.0.0
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

#ifndef RESET_TYPES_H
#define    RESET_TYPES_H
 
/**
 @ingroup  resetdriver
 @enum     RESET_TYPES
 @brief    Defines the RCON error types 
*/
enum RESET_TYPES
{
    RESET_ERROR_RCON_TRAPR      = 1, /**< A Trap Conflict Reset has occurred */
    RESET_ERROR_RCON_IOPUWR     = 2, /**< An illegal opcode detection, an illegal address mode or Uninitialized W register used as an Address Pointer caused a Reset */
    RESET_ERROR_RCON_CM         = 3, /**< A Configuration Mismatch Reset has occurred */
    RESET_ERROR_RCON_WDTO_ISR   = 4  /**< WDT time-out has occurred */
};

/**
 @ingroup  resetdriver
 @enum     RESET_MASKS
 @brief    Defines the RESET cause mask location   
*/
enum RESET_MASKS
{ 
  RESET_MASK_WDTO      = 0x0010,   /**< Defines the watchdog timeout reset flag mask location */
  RESET_MASK_SWR       = 0x0040,   /**< Defines the software reset mask location */
  RESET_MASK_EXTR      = 0x0080,   /**< Defines the external reset mask location */
  RESET_MASK_CM        = 0x0200,   /**< Defines the configuration mismatch reset mask location */
  RESET_MASK_IOPUWR    = 0x4000,   /**< Defines the illegal opcode or uninitialized W access reset mask location */
  RESET_MASK_TRAPR     = 0x8000,   /**< Defines the trap reset mask location */
};

#endif    /* RESET_TYPES_H */

/**
 End of File
*/
