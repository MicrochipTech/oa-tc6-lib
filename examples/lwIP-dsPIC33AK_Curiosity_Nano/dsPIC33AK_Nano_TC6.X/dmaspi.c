//DOM-IGNORE-BEGIN
/*
Copyright (C) 2025, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
//DOM-IGNORE-END

/*
 * File:   dmaspi.c
 * Author: C73524
 *
 * Created on January 30, 2025, 12:38 PM
 */

#include "xc.h"
#include "dmaspi.h"
#include "mcc_generated_files/dma/dma.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/spi_host/spi1.h"

/* Defines a dummy patter to use when receive-only transactions are executed. */
#define DMA_PATTERN_DUMMY   (0x00u)

/**
 * @brief DMA control structure.
 */
struct DMA_CONTROL {
    // User's handler for completion of DMA
    dmaCompletionHandler completionHandler;

    uint8_t dummy;      // Dummy byte
    uint8_t busy;       // Operation in progress
    uint8_t txonly;     // Indicates a transmit-only operation was submitted
};

static struct DMA_CONTROL dmaControl = {0};

/**
 * @brief DMA callback for DMA0 (SPI transmit).
 * @param event the DMA event that occurred.
 * @note When a combined transmit/receive operation occurs,
 *       receive completes after transmit.
 */
static void DMA0_Callback(enum DMA_EVENT event)
{
    if (DMA_TRANSFER_DONE == event)
    {
        /* If a transmit-only operation was submitted, indicate that the DMA is available.
         * If a receive operation is in progress, it will handle the state change since
         * receive always completes after transmit. */
        if (1U == dmaControl.txonly)
        {
            dmaControl.txonly = 0U;
            dmaControl.busy = DMA_AVAILABLE;
        }
    }
}

/**
 * @brief DMA callback for DMA1 (SPI receive).
 * @param event the DMA event that occurred.
 */
static void DMA1_Callback(enum DMA_EVENT event)
{
    // On overflow, the SPI must be cleared to resync.
    if ((1U == DMA1STATbits.OVERRUN) || (1U == SPI1STATbits.SPIROV))
    {
        // Do a dummy read to clear the SPI buffer
        uint8_t temp = SPI1BUF;

        DMA1STATbits.OVERRUN = 0;
        SPI1STATbits.SPIROV = 0;
        temp = temp;    // To placate compiler
    };

    if (DMA_TRANSFER_DONE == event)
    {
        /* Indicate that the DMA is available.
         * This must be done before the completion handler is called,
         * as the handler may check the status. */
        dmaControl.busy = DMA_AVAILABLE;

        // Call the completion handler if registered.
        if (NULL != dmaControl.completionHandler)
        {
            dmaControl.completionHandler();
        }
    }
}

/**
 * @brief Initialize the DMA<->SPI interface.
 */
void dmaSpiInit(dmaCompletionHandler handler)
{
    // Register the completion handler.
    dmaControl.completionHandler = handler;

    // Open the SPI device.
    (void)SPI1_Open(HOST_CONFIG);

    // In DMA mode, the SPI transmit/receive interrupts are not enabled.
    IEC2bits.SPI1RXIE = 0;
    IEC2bits.SPI1TXIE = 0;
    IFS2bits.SPI1RXIF = 0;
    IFS2bits.SPI1TXIF = 0;

    // Register callbacks for DMA handling.
    DMA_ChannelCallbackRegister(DMA_CHANNEL_0, (void*)&DMA0_Callback);
    DMA_ChannelCallbackRegister(DMA_CHANNEL_1, (void*)&DMA1_Callback);
}


/**
 * @brief Close the DMA<->SPI interface.
 */
void dmaSpiClose(void)
{
    // Close the SPI module.
    SPI1_Close();

    // Disable DMA channels (enabled when used).
    IEC2bits.DMA0IE = 0;
    IEC2bits.DMA1IE = 0;

    // Disable interrupt-on-completion.
    DMA0CHbits.DONEEN = 0;
    DMA1CHbits.DONEEN = 0;
}


/**
 * @brief Function initializes DMA message transfer from and to defined buffers to SPI1.
 * @param uint8_t *pTx    start address of data need to transmit
 *        uint8_t *pRx    start address buffer for recieved data
 *        uint16_t length number of bytes need to transfer
 * @return uint8_t DMA_AVAILABLE -> no pending transfer
 *                 DMA_BUSY -> pending transfer
 */
uint8_t dmaSpiStartTransaction(uint8_t *pTx, uint8_t *pRx, uint16_t length)
{
    uint8_t result = DMA_AVAILABLE;

    if ( (0U == dmaControl.busy) && ((NULL != pTx) || (NULL != pRx)) )
    {
        // DMA will be active.  This is cleared when the DMA operation finishes.
        dmaControl.busy = DMA_BUSY;

        // Default to 'receive or transmit/receive' for completion status handling.
        dmaControl.txonly = 0U;

        // Transmit and receive requested.
        if ((NULL != pTx) && (NULL != pRx))
        {
            // Clear interrupt masks for SPI receive and transmit.
            SPI1IMSKbits.SPIRBFEN = 0;  // Interrupt on SPI rxbuf full condition
            SPI1IMSKbits.SPITBEN = 0;   // Interrupt on SPI txbuf empty condition

            // Clear DMA interrupt flags
            IFS2bits.DMA0IF = 0;
            IFS2bits.DMA1IF = 0;

            // Set DMA 0 (transmit) for one-shot mode, source address increment, destination address constant.
            DMA0CHbits.TRMODE = 0;
            DMA0CHbits.SAMODE = 1;
            DMA0CHbits.DAMODE = 0;
            DMA_ChannelEnable(DMA_CHANNEL_0);
            DMA_SourceAddressSet(DMA_CHANNEL_0, (size_t)pTx);
            DMA_DestinationAddressSet(DMA_CHANNEL_0, (size_t)&SPI1BUF);
            DMA_TransferCountSet(DMA_CHANNEL_0, (size_t)length);

            // Set DMA 1 (receive) for one-shot mode, source address constant, destination address increment.
            DMA1CHbits.TRMODE = 0;
            DMA1CHbits.SAMODE = 0;
            DMA1CHbits.DAMODE = 1;
            DMA_ChannelEnable(DMA_CHANNEL_1);
            DMA_SourceAddressSet(DMA_CHANNEL_1, (size_t)&SPI1BUF);
            DMA_DestinationAddressSet(DMA_CHANNEL_1, (size_t)pRx);
            DMA_TransferCountSet(DMA_CHANNEL_1, (size_t)length);

            // Set interrupt masks for SPI receive and transmit.
            SPI1IMSKbits.SPIRBFEN = 1;  // Interrupt on SPI rxbuf full condition
            SPI1IMSKbits.SPITBEN = 1;   // Interrupt on SPI txbuf empty condition

            // Enable interrupt-on-completion.
            DMA0CHbits.DONEEN = 1;
            DMA1CHbits.DONEEN = 1;

            // Enable the interrupts to start the transfer.
            IEC2bits.DMA0IE = 1;
            IEC2bits.DMA1IE = 1;
        }

        // Receive-only requested.
        else if (NULL == pTx)
        {
            // Transmit drives the process, even if there is no data to transmit.
            // Dummy data is used for reception since there is no receive destination available.
            dmaControl.dummy = DMA_PATTERN_DUMMY;

            // Clear interrupt masks for SPI receive and transmit.
            SPI1IMSKbits.SPIRBFEN = 0;  // Interrupt on SPI rxbuf full condition
            SPI1IMSKbits.SPITBEN = 0;   // Interrupt on SPI txbuf empty condition

            // Clear DMA interrupt flags.
            IFS2bits.DMA0IF = 0;
            IFS2bits.DMA1IF = 0;

            // Set DMA 0 (transmit) for one-shot mode, source address constant, destination address constant.
            DMA0CHbits.TRMODE = 0;
            DMA0CHbits.SAMODE = 0;
            DMA0CHbits.DAMODE = 0;
            DMA_ChannelEnable(DMA_CHANNEL_0);
            DMA_SourceAddressSet(DMA_CHANNEL_0, (size_t)&dmaControl.dummy);
            DMA_DestinationAddressSet(DMA_CHANNEL_0, (size_t)&SPI1BUF);
            DMA_TransferCountSet(DMA_CHANNEL_0, (size_t)length);

            // Set DMA 1 (receive) for one-shot mode, source address constant, destination address increment.
            DMA1CHbits.TRMODE = 0;
            DMA1CHbits.SAMODE = 0;
            DMA1CHbits.DAMODE = 1;
            DMA_ChannelEnable(DMA_CHANNEL_1);
            DMA_SourceAddressSet(DMA_CHANNEL_1, (size_t) &SPI1BUF);
            DMA_DestinationAddressSet(DMA_CHANNEL_1, (size_t)pRx);
            DMA_TransferCountSet(DMA_CHANNEL_1, (size_t)length);

            // Set interrupt masks for SPI receive.
            SPI1IMSKbits.SPIRBFEN = 1;  // Interrupt on SPI rxbuf full condition

            // Enable interrupt-on-completion.
            DMA0CHbits.DONEEN = 1;
            DMA1CHbits.DONEEN = 1;

            // Enable the interrupts to start the transfer.
            IEC2bits.DMA0IE = 1;
            IEC2bits.DMA1IE = 1;
        }

        // Transmit-only requested.
        else
        {
            // Indicate this is a transmit-only transaction.
            // This affects the management of availability of the DMA.
            dmaControl.txonly = 1U;

            // Clear DMA interrupt flags
            IFS2bits.DMA0IF = 0;

            // Clear interrupt masks for SPI receive and transmit.
            SPI1IMSKbits.SPIRBFEN = 0;  // Interrupt on SPI rxbuf full condition
            SPI1IMSKbits.SPITBEN = 0;   // Interrupt on SPI txbuf empty condition

            // Set DMA 0 (transmit) for one-shot mode, source address increment, destination address constant.
            DMA0CHbits.TRMODE = 0;
            DMA0CHbits.SAMODE = 1;
            DMA0CHbits.DAMODE = 0;
            DMA_ChannelEnable(DMA_CHANNEL_0);
            DMA_SourceAddressSet(DMA_CHANNEL_0, (size_t)pTx);
            DMA_DestinationAddressSet(DMA_CHANNEL_0, (size_t)&SPI1BUF);
            DMA_TransferCountSet(DMA_CHANNEL_0, (size_t)length);

            // Set interrupt masks for SPI transmit.
            SPI1IMSKbits.SPITBEN = 1;   // Interrupt on SPI txbuf empty condition

            // Enable interrupt-on-completion.
            DMA0CHbits.DONEEN = 1;

            // Enable the interrupts to start the transfer.
            IEC2bits.DMA0IE = 1;
        }

        // DMA is running.
        result = DMA_BUSY;
    }

    return result;
}

/**
 * @brief Returns transfer status.
 * @return      DMA_BUSY -> in process
 *              DMA_AVAILABLE -> no transfer
 */
uint8_t dmaSpiGetStatus(void)
{
    return dmaControl.busy;
}
