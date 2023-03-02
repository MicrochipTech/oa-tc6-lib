/**
 * DMA Generated Driver Types Header File
 * 
 * @file      dma_types.h
 * 
 * @ingroup   dmadriver
 * 
 * @brief     This is the generated driver types header file for the DMA driver
 *
 * @version   Driver Version 1.1.1
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

#ifndef DMA_TYPES_H
#define DMA_TYPES_H

// Section: Data Type Definitions

/**
 @ingroup  dmadriver
 @enum     DMA_CHANNEL 
 @brief    Defines the DMA channles that are 
           selected from the MCC Melody User Interface for the DMA transfers.
           The below are the custom names given in the MCC Melody User Interface.
*/
enum DMA_CHANNEL
{
    DMA_CHANNEL_0 =  0,              /**< DMA channel 0 */
    DMA_CHANNEL_1 =  1,              /**< DMA channel 1 */
    DMA_CHANNEL_2 =  2,              /**< DMA channel 2 */
    DMA_CHANNEL_3 =  3,              /**< DMA channel 3 */
    DMA_NUMBER_OF_CHANNELS = 4        /**< Maximum number of Channels supported by hardware : 4 */
};

#endif  //DMA_TYPES_H

