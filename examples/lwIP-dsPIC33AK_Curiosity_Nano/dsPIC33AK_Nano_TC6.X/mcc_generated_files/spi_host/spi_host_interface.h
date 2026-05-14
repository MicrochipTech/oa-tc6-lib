
/**
 * SPI Generated Driver Interface Header File
 * 
 * @file        spi_host_interface.h
 * 
 * @defgroup    spihostdriver SPI Host Driver
 * 
 * @brief       Serial Peripheral Interface (SPI) HOST Driver using dsPIC MCUs
 *
 * @skipline @version     PLIB Version 1.0.1
 *
 * @skipline    Device : dsPIC33AK512MPS506
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

#ifndef SPI_HOST_INTERFACE_H
#define SPI_HOST_INTERFACE_H

// Section: Included Files
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// Section: Data Type Definitions
        

/**
 @ingroup spihostdriver
 @struct SPI_HOST_INTERFACE
 @brief Structure containing the function pointers of SPI HOST driver.
*/
struct SPI_HOST_INTERFACE
{   
    void (*Initialize)(void); 
    ///< Pointer to SPIx_Initialize e.g. \ref SPI1_Initialize
    
    void (*Deinitialize)(void);
    ///< Pointer to SPIx_Deinitialize e.g. \ref SPI1_Deinitialize
    
    void (*Close)(void);
    ///< Pointer to SPIx_Close e.g. \ref SPI1_Close
    
    bool (*Open)(uint8_t spiConfigIndex);
    ///< Pointer to SPIx_Open e.g. \ref SPI1_Open
    
    void (*BufferExchange)(void *bufferData, size_t bufferSize);
    ///< Pointer to SPIx_BufferExchange e.g. \ref SPI1_BufferExchange
    
    void (*BufferRead)(void *bufferData, size_t bufferSize);
    ///< Pointer to SPIx_BufferRead e.g. \ref SPI1_BufferRead
    
    void (*BufferWrite)(void *bufferData, size_t bufferSize);
    ///< Pointer to SPIx_BufferWrite e.g. \ref SPI1_BufferWrite
    
    uint8_t (*ByteExchange)(uint8_t byteData);  
    ///< Pointer to SPIx_ByteExchange e.g. \ref SPI1_ByteExchange
    
    uint8_t (*ByteRead)(void);
    ///< Pointer to SPIx_ByteRead e.g. \ref SPI1_ByteRead
    
    void (*ByteWrite)(uint8_t byteData);
    ///< Pointer to SPIx_ByteWrite e.g. \ref SPI1_ByteWrite
    
    bool (*IsRxReady)(void);
    ///< Pointer to SPIx_IsRxReady e.g. \ref SPI1_IsRxReady
    
    bool (*IsTxReady)(void);
    ///< Pointer to SPIx_IsTxReady e.g. \ref SPI1_IsTxReady
};

#endif //SPI_HOST_INTERFACE_H


