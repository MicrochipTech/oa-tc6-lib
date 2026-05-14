/**
 * DMA Generated Driver Interface Header File
 * 
 * @file      dma_interface.h
 * 
 * @defgroup  dmadriver DMA Driver
 * 
 * @brief     Direct Memory Access driver to service high data throughput peripherals 
 *            allowing them to access data memory directly using dsPIC MCUs.
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

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

// Section: Included Files
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "dma_types.h"

// Section: Data Type Definitions
        
/**
 @ingroup  dmadriver
 @struct   DMA_INTERFACE
 @brief    Structure containing the function pointers of DMA driver
*/
struct DMA_INTERFACE
{   
    void (*Initialize)(void);
    ///< Pointer to \ref DMA_Initialize
    
    void (*Deinitialize)(void);
    ///< Pointer to \ref DMA_Deinitialize
    
	void (*ChannelEnable)(enum DMA_CHANNEL channel);
    ///< Pointer to \ref DMA_ChannelEnable
    
	void (*ChannelDisable)(enum DMA_CHANNEL channel);
    ///< Pointer to \ref DMA_ChannelDisable
    
	void (*TransferCountSet)(enum DMA_CHANNEL channel, uint16_t transferCount);
    ///< Pointer to \ref DMA_TransferCountSet
    
	uint16_t (*TransferCountGet)(enum DMA_CHANNEL channel);
    ///< Pointer to \ref DMA_TransferCountGet
    
	void (*SoftwareTriggerEnable)(enum DMA_CHANNEL channel);
    ///< Pointer to \ref DMA_SoftwareTriggerEnable
    
	void (*SourceAddressSet)(enum DMA_CHANNEL channel, size_t address); 
    ///< Pointer to \ref DMA_SourceAddressSet
    
	void (*DestinationAddressSet)(enum DMA_CHANNEL channel, size_t address);
    ///< Pointer to \ref DMA_DestinationAddressSet
    
	bool (*IsSoftwareRequestPending)(enum DMA_CHANNEL channel);
    ///< Pointer to \ref DMA_IsSoftwareRequestPending
    
    void (*ChannelCallbackRegister)(enum DMA_CHANNEL channel, void(*callback)(enum DMA_EVENT event));
    ///< Pointer to \ref DMA_ChannelCallbackRegister
    
	void (*ChannelTasks)(void);
    ///< Pointer to \ref DMA_ChannelTasks (Supported only in polling mode)
};

#endif //DMA_INTERFACE_H

