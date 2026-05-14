/**
 * RESET Generated Driver Types Header File
 * 
 * @file      reset_types.h
 *            
 * @ingroup   resetdriver
 *            
 * @brief     This is the generated driver types header file for the RESET driver
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

#ifndef RESET_TYPES_H
#define    RESET_TYPES_H

/**
 @ingroup  resetdriver
 @enum     RESET_MASKS
 @brief    Defines the RESET cause mask location   
*/
enum RESET_MASKS
{ 
  RESET_MASK_WDTO      = 0x00000010,   /**< Defines the watchdog timeout reset flag mask location */
  RESET_MASK_SWR       = 0x00000040,   /**< Defines the software reset mask location */
  RESET_MASK_EXTR      = 0x00000080,   /**< Defines the external reset mask location */
  RESET_MASK_CM        = 0x00000200,   /**< Defines the configuration mismatch reset mask location */
};

#endif    /* RESET_TYPES_H */

/**
 End of File
*/
