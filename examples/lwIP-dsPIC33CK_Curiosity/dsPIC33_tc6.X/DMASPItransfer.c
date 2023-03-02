//DOM-IGNORE-BEGIN
/*
Copyright (C) 2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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
 * File:   DMASPItransfer.c
 * Author: C00233
 *
 * Created on October 12, 2022, 1:50 PM
 */

#include "xc.h"
#include "DMASPItransfer.h"

static struct {
    uint16_t u16PackLen; /* length of bytes in transfer */
    uint8_t * pu8RcvDataPtr; /* address of reception buffer */
    uint8_t * puTmtDataPtr;
    uint8_t u8RcvMode;
    uint8_t u8TmtMode;
    uint8_t u8DummyByte;
    uint8_t u8Busy; /* indicate pending data process */
} sVarDmaSpi;

void CB_DMA_Channel(uint8_t channel);

void vidInitDmaSpiTransfer(void) {

    SPI1_Open(HOST_CONFIG); //SPI Module enable
    DMA.ChannelCallbackRegister((void*) &CB_DMA_Channel);
}

void CB_DMA_Channel(uint8_t channel) {

    sVarDmaSpi.u8Busy = 0;
    switch (channel) {
        case DMA_CHANNEL_0:
            Nop();
            break;
        case DMA_CHANNEL_1:
            Nop();
            sVarDmaSpi.u8Busy = 0u; /* reset event blocking */
            vidTransactionDone();
            break;
        default:
            break;
    }
}

/**
 * @description function initializes DMA message transfer from and to defined
 *              buffers to SPI1 TX.
 *              function is protected against unexpected activation while
 *              transfer is pending.
 * @param       uint8_t *pTx    start address of data need to transmit
 *              uint8_t *pRx    start address buffer for recieved data
 *              uint16_t length number of bytes need to transfer
 * @return      bool            0 -> no pending transfer
 *                              0x55 -> pending transfer
 * @sequence    on demand
 * @note
 */
uint8_t u8SpiStartTransaction(uint8_t *pu8Tx, uint8_t *pu8Rx, uint16_t u16length) {
    uint16_t DMACH0_register_backup;
    uint8_t blRetVal;
    if (0 == sVarDmaSpi.u8Busy) {
        if ((0u != pu8Tx) || (0u != pu8Rx)) /* at least one pointer is defined */ {

            if ((0u != pu8Tx) && (0u != pu8Rx)) /* normal transmission and receive */ {

                SPI1IMSKLbits.SPIRBFEN = 0; /*Interrupt on SPI rxbuf full condition*/
                SPI1IMSKLbits.SPITBEN = 0; /*Interrupt on SPI txbuf empty condition*/
                /*DMA configured One-Shot mode*/
                /*Configure DMA Channel 0 for SPI transmit. Triggered by SPI transmit event.
                 Source address increments, Destination address constant */
                DMA.ChannelEnable(DMA_CHANNEL_0);
                DMA.SourceAddressSet(DMA_CHANNEL_0, (uint16_t) pu8Tx);
                DMA.DestinationAddressSet(DMA_CHANNEL_0, (uint16_t) & SPI1BUFL);
                DMA.TransferCountSet(DMA_CHANNEL_0, (uint16_t) u16length);
                /*Configure DMA Channel 1 for SPI receive.Triggered by SPI receive event.
                  Source address constant, Destination address increments */
                DMA.ChannelEnable(DMA_CHANNEL_1);
                DMA.SourceAddressSet(DMA_CHANNEL_1, (uint16_t) & SPI1BUFL);
                DMA.DestinationAddressSet(DMA_CHANNEL_1, (uint16_t) pu8Rx);
                DMA.TransferCountSet(DMA_CHANNEL_1, (uint16_t) u16length);


                /*DMA trigger sources*/
                IFS0bits.SPI1RXIF = 0;
                SPI1IMSKLbits.SPIRBFEN = 1; /*Interrupt on SPI rxbuf full condition*/
                IFS0bits.SPI1TXIF = 0;
                SPI1IMSKLbits.SPITBEN = 1; /*Interrupt on SPI txbuf empty condition*/

            } else if (0u == pu8Tx) /* dummy data is used as only reception */ {
                sVarDmaSpi.u8DummyByte = DMA_PATTERN_DUMMY;
                SPI1IMSKLbits.SPIRBFEN = 0; /*Interrupt on SPI rxbuf full condition*/
                SPI1IMSKLbits.SPITBEN = 0; /*Interrupt on SPI txbuf empty condition*/
                /*DMA configured One-Shot mode*/
                /*Configure DMA Channel 0 for SPI transmit. Triggered by SPI transmit event.
                 Source address increments, Destination address constant */
                DMACH0_register_backup = DMACH0;
                DMACH0bits.SAMODE = 0; //source address no increment
                DMA.ChannelEnable(DMA_CHANNEL_0);
                DMA.SourceAddressSet(DMA_CHANNEL_0, (uint16_t) & sVarDmaSpi.u8DummyByte);
                DMA.DestinationAddressSet(DMA_CHANNEL_0, (uint16_t) & SPI1BUFL);
                DMA.TransferCountSet(DMA_CHANNEL_0, (uint16_t) u16length);

                /*Configure DMA Channel 1 for SPI receive.Triggered by SPI receive event.
                  Source address constant, Destination address increments */
                DMA.ChannelEnable(DMA_CHANNEL_1);
                DMA.SourceAddressSet(DMA_CHANNEL_1, (uint16_t) & SPI1BUFL);
                DMA.DestinationAddressSet(DMA_CHANNEL_1, (uint16_t) pu8Rx);
                DMA.TransferCountSet(DMA_CHANNEL_1, (uint16_t) u16length);


                /*DMA trigger sources*/
                IFS0bits.SPI1RXIF = 0;
                SPI1IMSKLbits.SPIRBFEN = 1; /*Interrupt on SPI rxbuf full condition*/
                IFS0bits.SPI1TXIF = 0;
                SPI1IMSKLbits.SPITBEN = 1; /*Interrupt on SPI txbuf empty condition*/
                DMACH0 = DMACH0_register_backup;
            } else if (0u == pu8Rx)/* if rcv pointer is NUL then no store of received data is needed */ {

                SPI1IMSKLbits.SPITBEN = 0; /*Interrupt on SPI txbuf empty condition*/
                /*DMA configured One-Shot mode*/
                /*Configure DMA Channel 0 for SPI transmit. Triggered by SPI receive event
                 Source address increments, Destination address constant */
                DMA.SourceAddressSet(DMA_CHANNEL_0, (uint16_t) pu8Tx);
                DMA.DestinationAddressSet(DMA_CHANNEL_0, (uint16_t) & SPI1BUFL);
                DMA.ChannelEnable(DMA_CHANNEL_0);
                DMA.TransferCountSet(DMA_CHANNEL_0, (uint16_t) u16length);
                IFS0bits.SPI1TXIF = 0;
                SPI1IMSKLbits.SPITBEN = 1;

            } else {
                /* do nothing */
            }

            sVarDmaSpi.u8Busy = 0x55u;
            blRetVal = 1u;
        } else {
            blRetVal = 0u;
        }
    } else {
        blRetVal = 0u;
    }
    return blRetVal;
}

/**
 * @description returns transfer process status
 * @param       void
 * @return      uint8_t 0x55 -> in process, 0 -> no transfer
 * @sequence    on demand
 * @note
 */
uint8_t u8GetProcessStatus(void) {
    return sVarDmaSpi.u8Busy;
}
