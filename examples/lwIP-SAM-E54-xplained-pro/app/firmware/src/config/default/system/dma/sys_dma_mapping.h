/*******************************************************************************
  DMA System Service Mapping File

  Company:
    Microchip Technology Inc.

  File Name:
    sys_dma_mapping.h

  Summary:
    DMA System Service mapping file.

  Description:
    This header file contains the mapping of the APIs defined in the API header
    to either the function implementations or macro implementation or the
    specific variant implementation.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END

#ifndef SYS_DMA_MAPPING_H
#define SYS_DMA_MAPPING_H


// *****************************************************************************
// *****************************************************************************
// Section: DMA System Service Mapping
// *****************************************************************************
// *****************************************************************************

#include "peripheral/dmac/plib_dmac.h"

//******************************************************************************
/*
  Function:
    void SYS_DMA_ChannelCallbackRegister
    (
        SYS_DMA_CHANNEL channel,
        const SYS_DMA_CHANNEL_CALLBACK eventHandler,
        const uintptr_t contextHandle
    )

  Summary:
    This function allows a DMA client to set an event handler.

  Description:
    This function allows a client to set an event handler. The client may want
    to receive transfer related events in cases when it submits a DMA
    transfer request. The event handler should be set before the client
    intends to perform operations that could generate events.

    This function accepts a contextHandle parameter. This parameter could be
    set by the client to contain (or point to) any client specific data object
    that should be associated with this DMA channel.

  Precondition:
    DMA Controller should have been initialized.

  Parameters:
    channel - A specific DMA channel from which the events are expected.

    eventHandler - Pointer to the event handler function.

    contextHandle - Value identifying the context of the
    application/driver/middleware that registered the event handling function.

  Returns:
    None.

  Example:
    <code>
    MY_APP_OBJ myAppObj;

    void APP_DMA_TransferEventHandler(SYS_DMA_TRANSFER_EVENT event,
            uintptr_t contextHandle)
    {
        switch(event)
        {
            case SYS_DMA_TRANSFER_COMPLETE:
                break;

            case SYS_DMA_TRANSFER_ERROR:
                break;

            default:
                break;
        }
    }
    SYS_DMA_ChannelCallbackRegister(channel, APP_DMA_TransferEventHandler,
            (uintptr_t)&myAppObj);
    </code>

  Remarks:
    None.
 */
#define SYS_DMA_ChannelCallbackRegister(channel, eventHandler, context)  DMAC_ChannelCallbackRegister((DMAC_CHANNEL)channel, (DMAC_CHANNEL_CALLBACK)eventHandler, context)


//******************************************************************************
/* Function:
    bool SYS_DMA_ChannelTransfer
    (
        SYS_DMA_CHANNEL channel,
        const void *srcAddr,
        const void *destAddr,
        size_t blockSize
    )

  Summary:
    Adds a data transfer to a DMA channel and enables the channel to start
    data transfer.

  Description:
    This function adds a single block data transfer characteristics for a
    specific XDMAC channel id it is not busy already. It also enables the
    channel to start data transfer.

    If the requesting client registered an event callback with the PLIB,
    the PLIB will issue a SYS_DMA_TRANSFER_COMPLETE event if the transfer was
    processed successfully and SYS_DMA_TRANSFER_ERROR event if the transfer was
    not processed successfully.

  Precondition:
    DMA Controller should have been initialized.

  Parameters:
    channel - A specific DMA channel

    srcAddr - Source of the DMA transfer

    destAddr - Destination of the DMA transfer

    blockSize - Size of the transfer block

  Returns:
    True - If transfer request is accepted.
    False - If previous transfer is in progress and the request is rejected.

  Example:
    <code>
    MY_APP_OBJ myAppObj;
    uint8_t buf[10] = {0,1,2,3,4,5,6,7,8,9};
    void *srcAddr = (uint8_t *) buf;
    void *destAddr = (uin8_t*) &U1TXREG;
    size_t size = 10;

    SYS_DMA_ChannelCallbackRegister(APP_DMA_TransferEventHandler,
        (uintptr_t)&myAppObj);

    if (SYS_DMA_ChannelTransfer(SYS_DMA_CHANNEL_1, srcAddr, destAddr, size) == true)
    {

    }
    else
    {

    }
    </code>

  Remarks:
    When DMA transfer buffers are placed in cache-able memory, cache maintenance
    operation must be performed by cleaning and invalidating cache for DMA
    buffers located in cache-able SRAM region using CMSIS APIs. The buffer start
    address must be aligned to cache line and buffer size must be multiple of
    cache line. Refer to device documentation to find the cache line size.

    Invalidate cache lines having received buffer before using it to load the
    latest data in the actual memory to the cache
    SCB_InvalidateDCache_by_Addr((uint32_t *)&readBuffer, sizeof(readBuffer));

    Clean cache lines having source buffer before submitting a transfer request
    to XDMAC to load the latest data in the cache to the actual memory
    SCB_CleanDCache_by_Addr((uint32_t *)&writeBuffer, sizeof(writeBuffer));
*/
#define SYS_DMA_ChannelTransfer(channel, srcAddr, destAddr, blockSize)  DMAC_ChannelTransfer((DMAC_CHANNEL)channel, srcAddr, destAddr, blockSize)


//******************************************************************************
/* Function:
    bool SYS_DMA_ChannelIsBusy (SYS_DMA_CHANNEL channel)

  Summary:
    Returns the busy status of a specific DMA Channel.

  Description:
    This function returns the busy status of the DMA channel.
    DMA channel will be busy if any transfer is in progress.

    This function can be used to check the status of the channel prior to
    submitting a transfer request. And this can also be used to check the status
    of the submitted request if callback mechanism is not preferred.

  Precondition:
    DMA Controller should have been initialized.

  Parameters:
    channel - A specific DMA channel

  Returns:
    Busy status of the specific channel.
    True - Channel is busy
    False - Channel is free

  Example:
    <code>

    MY_APP_OBJ myAppObj;
    uint8_t buf[10] = {0,1,2,3,4,5,6,7,8,9};
    void *srcAddr = (uint8_t *) buf;
    void *destAddr = (uin8_t*) &U1TXREG;
    size_t size = 10;

    if(false == SYS_DMA_ChannelIsBusy(SYS_DMA_CHANNEL_1))
    {
        SYS_DMA_ChannelTransfer(SYS_DMA_CHANNEL_1, srcAddr, destAddr, size);
    }
    </code>

  Remarks:
    None.
*/
#define SYS_DMA_ChannelIsBusy(channel)  DMAC_ChannelIsBusy((DMAC_CHANNEL)channel)


//******************************************************************************
/* Function:
    void SYS_DMA_ChannelDisable (SYS_DMA_CHANNEL channel)

  Summary:
    Disables the specified channel.

  Description:
    This function disables the specified channel and resets it.
    Ongoing transfer will be aborted.

  Precondition:
    DMA Controller should have been initialized.

  Parameters:
    channel - A specific DMA channel

  Returns:
    None.

  Example:
    <code>
    SYS_DMA_ChannelDisable(SYS_DMA_CHANNEL_1);
    </code>

  Remarks:
    None.
*/
#define SYS_DMA_ChannelDisable(channel)  DMAC_ChannelDisable((DMAC_CHANNEL)channel)

#endif // SYS_DMA_MAPPING_H
