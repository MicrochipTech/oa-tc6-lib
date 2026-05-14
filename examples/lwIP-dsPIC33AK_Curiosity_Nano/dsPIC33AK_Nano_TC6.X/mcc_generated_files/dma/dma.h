/**
 * DMA Generated Driver Header File
 * 
 * @file      dma.h
 * 
 * @ingroup   dmadriver
 * 
 * @brief     This is the generated driver header file for the DMA driver
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

#ifndef DMA_H
#define DMA_H

// Section: Included Files

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "dma_types.h"
#include "dma_interface.h"
       
// Section: Data Type Definitions

/**
 * @ingroup  dmadriver
 * @brief    Structure object of type DMA_INTERFACE with the custom name
 *           given by the user in the Melody Driver User interface. The default name 
 *           e.g. DMA can be changed by the user in the DMA user interface. 
 *           This allows defining a structure with application specific name using 
 *           the 'Custom Name' field. Application specific name allows the API Portability.
*/
extern const struct DMA_INTERFACE DMA;


// Section: Driver Interface Functions

/**
 * @ingroup  dmadriver
 * @brief    Initializes the DMA module
 * @param    none
 * @return   none
 */
void DMA_Initialize (void);

/**
 * @ingroup  dmadriver
 * @brief    Deinitializes the DMA to POR values
 * @param    none
 * @return   none
 */
void DMA_Deinitialize(void);
    
/**
 * @ingroup    dmadriver
 * @brief      This inline function enables the DMA channel
 * @pre        DMA_Initialize must be called
 * @param[in]  channel	- DMA channel number
 * @return     none
 */
inline static void DMA_ChannelEnable(enum DMA_CHANNEL channel)
{
    switch(channel) 
	{
        case DMA_CHANNEL_0:
                DMA0CHbits.CHEN = 1;
                break; 
        case DMA_CHANNEL_1:
                DMA1CHbits.CHEN = 1;
                break; 
        case DMA_CHANNEL_2:
                DMA2CHbits.CHEN = 1;
                break; 
        case DMA_CHANNEL_3:
                DMA3CHbits.CHEN = 1;
                break; 
        case DMA_CHANNEL_4:
                DMA4CHbits.CHEN = 1;
                break; 
        case DMA_CHANNEL_5:
                DMA5CHbits.CHEN = 1;
                break; 
        case DMA_CHANNEL_6:
                DMA6CHbits.CHEN = 1;
                break; 
        case DMA_CHANNEL_7:
                DMA7CHbits.CHEN = 1;
                break; 
        default: break;
    }
}

/**
 * @ingroup    dmadriver
 * @brief      This inline function disables the DMA channel
 * @pre        DMA_Initialize must be called. 
 * @param[in]  channel	- DMA channel number
 * @return     none
 */
inline static void DMA_ChannelDisable(enum DMA_CHANNEL channel)
{
    switch(channel) 
	{
        case DMA_CHANNEL_0:
                DMA0CHbits.CHEN = 0;
                break;    
        case DMA_CHANNEL_1:
                DMA1CHbits.CHEN = 0;
                break;    
        case DMA_CHANNEL_2:
                DMA2CHbits.CHEN = 0;
                break;    
        case DMA_CHANNEL_3:
                DMA3CHbits.CHEN = 0;
                break;    
        case DMA_CHANNEL_4:
                DMA4CHbits.CHEN = 0;
                break;    
        case DMA_CHANNEL_5:
                DMA5CHbits.CHEN = 0;
                break;    
        case DMA_CHANNEL_6:
                DMA6CHbits.CHEN = 0;
                break;    
        case DMA_CHANNEL_7:
                DMA7CHbits.CHEN = 0;
                break;    
        default: break;
    }
}

/**
 * @ingroup    dmadriver
 * @brief      This inline function sets the number of transfer counts to DMA channel
 * @pre        DMA_Initialize must be called
 * @param[in]  channel	        - DMA channel number
 * @param[in]  transferCount	- Transfer count Value
 * @return     none
 */
inline static void DMA_TransferCountSet(enum DMA_CHANNEL channel, uint16_t transferCount)
{
    switch(channel) 
	{
        case DMA_CHANNEL_0:
				DMA0CNT = transferCount;
                break;
        case DMA_CHANNEL_1:
				DMA1CNT = transferCount;
                break;
        case DMA_CHANNEL_2:
				DMA2CNT = transferCount;
                break;
        case DMA_CHANNEL_3:
				DMA3CNT = transferCount;
                break;
        case DMA_CHANNEL_4:
				DMA4CNT = transferCount;
                break;
        case DMA_CHANNEL_5:
				DMA5CNT = transferCount;
                break;
        case DMA_CHANNEL_6:
				DMA6CNT = transferCount;
                break;
        case DMA_CHANNEL_7:
				DMA7CNT = transferCount;
                break;
        default: break;
    }
}

/**
 * @ingroup    dmadriver
 * @brief      This inline function returns the number of transfer counts from DMA channel
 * @pre        DMA_Initialize must be called
 * @param[in]  channel	- DMA channel number
 * @return     Returns the transfer count value
 */
inline static uint16_t DMA_TransferCountGet(enum DMA_CHANNEL channel)
{
	uint16_t transferCount = 0U;
    switch(channel) 
	{
        case DMA_CHANNEL_0:
				transferCount = (uint16_t)DMA0CNT;	
				break;
        case DMA_CHANNEL_1:
				transferCount = (uint16_t)DMA1CNT;	
				break;
        case DMA_CHANNEL_2:
				transferCount = (uint16_t)DMA2CNT;	
				break;
        case DMA_CHANNEL_3:
				transferCount = (uint16_t)DMA3CNT;	
				break;
        case DMA_CHANNEL_4:
				transferCount = (uint16_t)DMA4CNT;	
				break;
        case DMA_CHANNEL_5:
				transferCount = (uint16_t)DMA5CNT;	
				break;
        case DMA_CHANNEL_6:
				transferCount = (uint16_t)DMA6CNT;	
				break;
        case DMA_CHANNEL_7:
				transferCount = (uint16_t)DMA7CNT;	
				break;
        default: 
				break;
    }
	return transferCount;
}

/**
 * @ingroup    dmadriver
 * @brief      This inline function sets the software trigger of the DMA channel
 * @pre        DMA_Initialize must be called
 * @param[in]  channel - DMA channel number
 * @return     none
 */
inline static void DMA_SoftwareTriggerEnable(enum DMA_CHANNEL channel)
{
    switch(channel) 
	{
        case DMA_CHANNEL_0:
				DMA0CHbits.CHREQ = 1;
                break;
        case DMA_CHANNEL_1:
				DMA1CHbits.CHREQ = 1;
                break;
        case DMA_CHANNEL_2:
				DMA2CHbits.CHREQ = 1;
                break;
        case DMA_CHANNEL_3:
				DMA3CHbits.CHREQ = 1;
                break;
        case DMA_CHANNEL_4:
				DMA4CHbits.CHREQ = 1;
                break;
        case DMA_CHANNEL_5:
				DMA5CHbits.CHREQ = 1;
                break;
        case DMA_CHANNEL_6:
				DMA6CHbits.CHREQ = 1;
                break;
        case DMA_CHANNEL_7:
				DMA7CHbits.CHREQ = 1;
                break;
        default: break;
    }
}

/**
 * @ingroup    dmadriver
 * @brief      This inline function sets the source address to specified DMA channel
 * @pre        DMA_Initialize must be called
 * @param[in]  channel - DMA channel number
 * @param[in]  address - Source address
 * @return     none
 */
inline static void DMA_SourceAddressSet(enum DMA_CHANNEL channel, size_t address) 
{
    switch(channel) 
	{
        case DMA_CHANNEL_0:
				DMA0SRC = address;		
                break;
        case DMA_CHANNEL_1:
				DMA1SRC = address;		
                break;
        case DMA_CHANNEL_2:
				DMA2SRC = address;		
                break;
        case DMA_CHANNEL_3:
				DMA3SRC = address;		
                break;
        case DMA_CHANNEL_4:
				DMA4SRC = address;		
                break;
        case DMA_CHANNEL_5:
				DMA5SRC = address;		
                break;
        case DMA_CHANNEL_6:
				DMA6SRC = address;		
                break;
        case DMA_CHANNEL_7:
				DMA7SRC = address;		
                break;
        default: break;
    }    
}

/**
 * @ingroup    dmadriver
 * @brief      This inline function sets the destination address to specified DMA channel
 * @pre        DMA_Initialize must be called
 * @param[in]  channel - DMA channel number
 * @param[in]  address - Destination address
 * @return     none
 */
inline static void DMA_DestinationAddressSet(enum DMA_CHANNEL channel, size_t address) 
{
    switch(channel) 
	{
        case DMA_CHANNEL_0:
				DMA0DST = address;
                break;
        case DMA_CHANNEL_1:
				DMA1DST = address;
                break;
        case DMA_CHANNEL_2:
				DMA2DST = address;
                break;
        case DMA_CHANNEL_3:
				DMA3DST = address;
                break;
        case DMA_CHANNEL_4:
				DMA4DST = address;
                break;
        case DMA_CHANNEL_5:
				DMA5DST = address;
                break;
        case DMA_CHANNEL_6:
				DMA6DST = address;
                break;
        case DMA_CHANNEL_7:
				DMA7DST = address;
                break;
        default: break;
    }    
}

/**
 * @ingroup    dmadriver
 * @brief      This inline function returns the status of the software request of the DMA channel
 * @pre        DMA_Initialize must be called
 * @param[in]  channel  - DMA channel number
 * @return     true		- DMA request is pending
 * @return     false	- DMA request is not pending
 */
inline static bool DMA_IsSoftwareRequestPending(enum DMA_CHANNEL channel)
{
	bool status = false;
    switch(channel) 
	{
        case DMA_CHANNEL_0:
                status = DMA0CHbits.CHREQ;
                break;				
        case DMA_CHANNEL_1:
                status = DMA1CHbits.CHREQ;
                break;				
        case DMA_CHANNEL_2:
                status = DMA2CHbits.CHREQ;
                break;				
        case DMA_CHANNEL_3:
                status = DMA3CHbits.CHREQ;
                break;				
        case DMA_CHANNEL_4:
                status = DMA4CHbits.CHREQ;
                break;				
        case DMA_CHANNEL_5:
                status = DMA5CHbits.CHREQ;
                break;				
        case DMA_CHANNEL_6:
                status = DMA6CHbits.CHREQ;
                break;				
        case DMA_CHANNEL_7:
                status = DMA7CHbits.CHREQ;
                break;				
        default: 
				break;
    }
	return status;
}

/**
 * @ingroup  dmadriver
 * @brief    This function is used to implement the tasks for polled implementations of DMA Channel
 * @pre      DMA_Initialize must be called
 * @param    none
 * @return   none
 */
void DMA_ChannelTasks(void);

/**
 * @ingroup    dmadriver
 * @brief      This function can be used to override default callback and to define 
 *             custom callback for DMA Channel event.
 * @param[in]  channel - DMA Channel from \ref enum DMA_CHANNEL
 * @param[in]  callback - Address of the callback function
 * @return     none 
 */
void DMA_ChannelCallbackRegister(enum DMA_CHANNEL channel, void(*callback)(enum DMA_EVENT event));

/**
 * @ingroup    dmadriver
 * @brief      This is the default callback with weak attribute. The user can 
 *             override and implement the default callback without weak attribute 
 *             or can register a custom callback function using \ref DMA_ChannelCallbackRegister.
 * @param[in]  event - DMA interrupt event \ref DMA_EVENT
 * @return     none  
 */
void DMA_Channel0Callback(enum DMA_EVENT event);

/**
 * @ingroup    dmadriver
 * @brief      This is the default callback with weak attribute. The user can 
 *             override and implement the default callback without weak attribute 
 *             or can register a custom callback function using \ref DMA_ChannelCallbackRegister.
 * @param[in]  event - DMA interrupt event \ref DMA_EVENT
 * @return     none  
 */
void DMA_Channel1Callback(enum DMA_EVENT event);

/**
 * @ingroup    dmadriver
 * @brief      This is the default callback with weak attribute. The user can 
 *             override and implement the default callback without weak attribute 
 *             or can register a custom callback function using \ref DMA_ChannelCallbackRegister.
 * @param[in]  event - DMA interrupt event \ref DMA_EVENT
 * @return     none  
 */
void DMA_Channel2Callback(enum DMA_EVENT event);

/**
 * @ingroup    dmadriver
 * @brief      This is the default callback with weak attribute. The user can 
 *             override and implement the default callback without weak attribute 
 *             or can register a custom callback function using \ref DMA_ChannelCallbackRegister.
 * @param[in]  event - DMA interrupt event \ref DMA_EVENT
 * @return     none  
 */
void DMA_Channel3Callback(enum DMA_EVENT event);

/**
 * @ingroup    dmadriver
 * @brief      This is the default callback with weak attribute. The user can 
 *             override and implement the default callback without weak attribute 
 *             or can register a custom callback function using \ref DMA_ChannelCallbackRegister.
 * @param[in]  event - DMA interrupt event \ref DMA_EVENT
 * @return     none  
 */
void DMA_Channel4Callback(enum DMA_EVENT event);

/**
 * @ingroup    dmadriver
 * @brief      This is the default callback with weak attribute. The user can 
 *             override and implement the default callback without weak attribute 
 *             or can register a custom callback function using \ref DMA_ChannelCallbackRegister.
 * @param[in]  event - DMA interrupt event \ref DMA_EVENT
 * @return     none  
 */
void DMA_Channel5Callback(enum DMA_EVENT event);

/**
 * @ingroup    dmadriver
 * @brief      This is the default callback with weak attribute. The user can 
 *             override and implement the default callback without weak attribute 
 *             or can register a custom callback function using \ref DMA_ChannelCallbackRegister.
 * @param[in]  event - DMA interrupt event \ref DMA_EVENT
 * @return     none  
 */
void DMA_Channel6Callback(enum DMA_EVENT event);

/**
 * @ingroup    dmadriver
 * @brief      This is the default callback with weak attribute. The user can 
 *             override and implement the default callback without weak attribute 
 *             or can register a custom callback function using \ref DMA_ChannelCallbackRegister.
 * @param[in]  event - DMA interrupt event \ref DMA_EVENT
 * @return     none  
 */
void DMA_Channel7Callback(enum DMA_EVENT event);
    
#endif  // DMA_H


