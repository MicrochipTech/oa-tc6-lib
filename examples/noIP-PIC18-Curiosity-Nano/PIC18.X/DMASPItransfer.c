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

#include "xc.h"
#include "DMASPItransfer.h"
#include "mcc_generated_files/pin_manager.h"

/*
 * structure container for DMA data handling on SPI
 */
static struct
{
    uint16_t u16PackLen; /* length of bytes in transfer */
    uint8_t * pu8RcvDataPtr; /* address of reception buffer */
    uint8_t * puTmtDataPtr;
    uint8_t u8RcvMode;
    uint8_t u8TmtMode;
    uint8_t u8DummyByte;
    uint8_t u8Busy; /* indicate pending data process */
} sVarDmaSpi;

/**
 * @description initializes the necessary modules and port pin conditions
 * @param       void
 * @return      void
 * @sequence    on startup
 * @note
 */
void vidInitDmaSpiTransfer(void)
{
    DMA2DCNTIE = 1; /* enable reception ready event */
    /*
     * to be able to support high speed data processing slew rate
     * on SPI pins need to be deactivated
     */
    SLRCONCbits.SLRC6 = 0u;
    SLRCONCbits.SLRC4 = 0u;
    SLRCONCbits.SLRC5 = 0u;
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
uint8_t u8SpiStartTransaction(uint8_t *pu8Tx, uint8_t *pu8Rx, uint16_t u16length)
{
    uint8_t blRetVal;

    if (0u == sVarDmaSpi.u8Busy)
    {
        while (SPI1CON2bits.BUSY);
        PIR2bits.DMA1SCNTIF = 0u;
        if ((0u != pu8Tx) || (0u != pu8Rx)) /* at least one pointer is defined */
        {
            if ((0u != pu8Tx) && (0u != pu8Rx)) /* normal transmission and receive */
            {
                sVarDmaSpi.u8TmtMode = INC_GPR_FIX_SFR;
                sVarDmaSpi.u8RcvMode = FIX_SFR_INC_GPR;
                sVarDmaSpi.u16PackLen = (uint16_t) u16length;
                sVarDmaSpi.pu8RcvDataPtr = pu8Rx;
                sVarDmaSpi.puTmtDataPtr = pu8Tx;
            }
            else if (0u == pu8Tx) /* dummy data is used as only reception */
            {
                sVarDmaSpi.u8TmtMode = FIX_GPR_FIX_SFR;
                sVarDmaSpi.u8RcvMode = FIX_SFR_INC_GPR;
                sVarDmaSpi.u16PackLen = u16length;
                sVarDmaSpi.pu8RcvDataPtr = pu8Rx;
                sVarDmaSpi.puTmtDataPtr = &sVarDmaSpi.u8DummyByte;

                sVarDmaSpi.u8DummyByte = DMA_PATTERN_DUMMY;
            }
            else if (0u == pu8Rx)/* if rcv pointer is NUL then no store of received data is needed */
            {
                /* prepare receive DMA */
                sVarDmaSpi.u8TmtMode = INC_GPR_FIX_SFR;
                sVarDmaSpi.u8RcvMode = FIX_SFR_FIX_GPR;
                sVarDmaSpi.u16PackLen = u16length;
                sVarDmaSpi.pu8RcvDataPtr = &sVarDmaSpi.u8DummyByte;
                sVarDmaSpi.puTmtDataPtr = pu8Tx;
            }
            else
            {
                /* do nothing */
            }

            vidChipSelectLow(); /* activate SPI chip select */

            /* prepare receive DMA */

            DMASELECT = DMA_CHANNEL_1;
            DMAnCON0bits.EN = 0u;
            DMAnCON1 = sVarDmaSpi.u8TmtMode;
            DMAnSSZ = (uint16_t) sVarDmaSpi.u16PackLen;
            DMAnSSA = (uint16_t) sVarDmaSpi.puTmtDataPtr;
            SPI1TCNT = DMAnSSZ;

            DMAnCON0bits.SIRQEN = 1u;
            DMAnCON0bits.EN = 1u;


            DMASELECT = DMA_CHANNEL_2;
            DMAnCON0bits.EN = 0u;
            DMAnCON1 = sVarDmaSpi.u8RcvMode;
            DMAnDSZ = (uint16_t) sVarDmaSpi.u16PackLen;
            DMAnDSA = (uint16_t) sVarDmaSpi.pu8RcvDataPtr;

            DMAnCON0bits.SIRQEN = 1u;
            DMAnCON0bits.EN = 1u;

            sVarDmaSpi.u8Busy = 0x55u;
            blRetVal = 1u;
        }
        else
        {
            blRetVal = 0u;
        }
    }
    else
    {
        blRetVal = 1u;
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
uint8_t u8GetProcessStatus(void)
{
    return sVarDmaSpi.u8Busy;
}

/**
 * @description interrupt service routine triggered at end of receive
 * @param       void
 * @return      void
 * @sequence    on triggered event
 * @note
 */
void vidDma2DestCountISR(void)
{
    vidChipSelectHigh();

#if 0
    /* just for testing */
    if (0u != u8CheckDataContent())
    {
        __builtin_software_breakpoint();
    }
    u8UnmarkDataContent();

#endif
    sVarDmaSpi.u8Busy = 0u; /* reset event blocking */

    vidTransactionDone();

    // Clear the source count interrupt flag
    DMA2DCNTIF = 0;
}

/*
 * end of file
 */
