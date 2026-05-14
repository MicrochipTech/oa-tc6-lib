/**
 * I2C Generated Driver Interface Header File
 * 
 * @file      i2c_host_interface.h
 * 
 * @defgroup  i2chostdriver I2C Host Driver
 * 
 * @brief     I2C driver for Host Mode using dsPIC MCUs
 *
 * @skipline @version   Firmware Driver Version 1.1.4
 *
 * @skipline @version   PLIB Version 1.0.1
 *
 * @skipline  Device : dsPIC33AK512MPS506
*/

/*
© [2026] Microchip Technology Inc. and its subsidiaries.

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

#ifndef I2C_HOST_INTERFACE_H
#define I2C_HOST_INTERFACE_H

// Section: Included Files
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "i2c_host_types.h"

// Section: Data Type Definitions        

/**
 @ingroup  i2chostdriver
 @struct   I2C_HOST_INTERFACE
 @brief    Structure containing the function pointers of I2C driver
*/
struct I2C_HOST_INTERFACE
{   
    void (*Initialize)(void);
    ///< Pointer to I2Cx_Initialize e.g. \ref I2C1_Initialize
    
    void (*Deinitialize)(void);
    ///< Pointer to I2Cx_Deinitialize e.g. \ref I2C1_Deinitialize
    
    bool (*Write)(uint16_t address, uint8_t *data, size_t dataLength);
    ///< Pointer to I2Cx_Write e.g. \ref I2C1_Write
    
    bool (*Read)(uint16_t address, uint8_t *data, size_t dataLength);
    ///< Pointer to I2Cx_Read e.g. \ref I2C1_Read
    
    bool (*WriteRead)(uint16_t address, uint8_t *writeData, size_t writeLength, uint8_t *readData, size_t readLength);
    ///< Pointer to I2Cx_WriteRead e.g. \ref I2C1_WriteRead
    
    bool (*TransferSetup)(struct I2C_TRANSFER_SETUP* setup, uint32_t srcClkFreq);
    ///< Pointer to I2Cx_TransferSetup e.g. \ref I2C1_TransferSetup
    
    enum I2C_HOST_ERROR (*ErrorGet)(void);
    ///< Pointer to I2Cx_ErrorGet e.g. \ref I2C1_ErrorGet
    
    bool (*IsBusy)(void);
    ///< Pointer to I2Cx_IsBusy e.g. \ref I2C1_IsBusy
    
    void (*HostCallbackRegister)(void (*handler)(void));
    ///< Pointer to I2Cx_CallbackRegister e.g. \ref I2C1_CallbackRegister
    
    void (*Tasks)(void);
    ///< Pointer to I2Cx_Tasks e.g. \ref I2C1_Tasks (Supported only in polling mode)
};

#endif


