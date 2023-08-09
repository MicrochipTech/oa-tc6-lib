/*******************************************************************************
  USART1 PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_usart1.c

  Summary:
    USART1 PLIB Implementation File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
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

#include "device.h"
#include "plib_usart1.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: USART1 Implementation
// *****************************************************************************
// *****************************************************************************

static void USART1_ErrorClear( void )
{
    uint32_t dummyData = 0U;

   if ((USART1_REGS->US_CSR & (US_CSR_USART_OVRE_Msk | US_CSR_USART_PARE_Msk | US_CSR_USART_FRAME_Msk)) != 0U)
   {
        /* Clear the error flags */
        USART1_REGS->US_CR = US_CR_USART_RSTSTA_Msk;

        /* Flush existing error bytes from the RX FIFO */
        while ((USART1_REGS->US_CSR & US_CSR_USART_RXRDY_Msk) != 0U)
        {
            dummyData = USART1_REGS->US_RHR & US_RHR_RXCHR_Msk;
        }
   }

    /* Ignore the warning */
    (void)dummyData;
}


volatile static USART_OBJECT usart1Obj;

static void __attribute__((used)) USART1_ISR_RX_Handler( void )
{
    uint32_t rxData = 0U;
    uint8_t* pu8Data = (uint8_t *)usart1Obj.rxBuffer;
    uint16_t* pu16Data = (uint16_t*)usart1Obj.rxBuffer;

    if(usart1Obj.rxBusyStatus == true)
    {
        size_t rxSize = usart1Obj.rxSize;
        size_t rxProcessedSize = usart1Obj.rxProcessedSize;

        while(((USART1_REGS->US_CSR & US_CSR_USART_RXRDY_Msk) != 0U) && (rxSize > rxProcessedSize))
        {
            rxData = (USART1_REGS->US_RHR & US_RHR_RXCHR_Msk);
            if ((USART1_REGS->US_MR & US_MR_USART_MODE9_Msk) != 0U)
            {
                pu16Data[rxProcessedSize] = (uint16_t)rxData;
                rxProcessedSize++;
            }
            else
            {
                pu8Data[rxProcessedSize] = (uint8_t)rxData;
                rxProcessedSize++;
            }
        }

        usart1Obj.rxProcessedSize = rxProcessedSize;

        /* Check if the buffer is done */
        if(usart1Obj.rxProcessedSize >= rxSize)
        {
            usart1Obj.rxBusyStatus = false;

            /* Disable Read, Overrun, Parity and Framing error interrupts */
            USART1_REGS->US_IDR = (US_IDR_USART_RXRDY_Msk | US_IDR_USART_FRAME_Msk | US_IDR_USART_PARE_Msk | US_IDR_USART_OVRE_Msk);

            if(usart1Obj.rxCallback != NULL)
            {
                uintptr_t rxContext = usart1Obj.rxContext;

                usart1Obj.rxCallback(rxContext);
            }
        }
    }
    else
    {
        /* Nothing to process */
    }
}

static void __attribute__((used)) USART1_ISR_TX_Handler( void )
{
    uint32_t txData = 0U;
    uint8_t* pu8Data = (uint8_t *)usart1Obj.txBuffer;
    uint16_t* pu16Data = (uint16_t*)usart1Obj.txBuffer;

    if(usart1Obj.txBusyStatus == true)
    {
        size_t txSize = usart1Obj.txSize;
        size_t txProcessedSize = usart1Obj.txProcessedSize;

        while(((USART1_REGS->US_CSR & US_CSR_USART_TXRDY_Msk) != 0U) && (txSize > txProcessedSize))
        {
            if ((USART1_REGS->US_MR & US_MR_USART_MODE9_Msk) != 0U)
            {
                txData = pu16Data[txProcessedSize];
            }
            else
            {
                txData = pu8Data[txProcessedSize];
            }
            USART1_REGS->US_THR = txData & US_THR_TXCHR_Msk;
            txProcessedSize++;
        }

        usart1Obj.txProcessedSize = txProcessedSize;

        /* Check if the buffer is done */
        if(usart1Obj.txProcessedSize >= txSize)
        {
            usart1Obj.txBusyStatus = false;

            USART1_REGS->US_IDR = US_IDR_USART_TXRDY_Msk;

            if(usart1Obj.txCallback != NULL)
            {
                uintptr_t txContext = usart1Obj.txContext;

                usart1Obj.txCallback(txContext);
            }
        }
    }
    else
    {
        /* Nothing to process */
    }
}

void __attribute__((used)) USART1_InterruptHandler( void )
{
    /* Error status */
    uint32_t errorStatus = (USART1_REGS->US_CSR & (US_CSR_USART_OVRE_Msk | US_CSR_USART_FRAME_Msk | US_CSR_USART_PARE_Msk));

    if(errorStatus != 0U)
    {
        /* Save the error to be reported later */
        usart1Obj.errorStatus = (USART_ERROR)errorStatus;

        /* Clear error flags and flush the error data */
        USART1_ErrorClear();

        /* Disable Read, Overrun, Parity and Framing error interrupts */
        USART1_REGS->US_IDR = (US_IDR_USART_RXRDY_Msk | US_IDR_USART_FRAME_Msk | US_IDR_USART_PARE_Msk | US_IDR_USART_OVRE_Msk);

        usart1Obj.rxBusyStatus = false;

        /* USART errors are normally associated with the receiver, hence calling
         * receiver callback */
        if( usart1Obj.rxCallback != NULL )
        {
            uintptr_t rxContext = usart1Obj.rxContext;

            usart1Obj.rxCallback(rxContext);
        }
    }

    /* Receiver status */
    if ((USART1_REGS->US_CSR & US_CSR_USART_RXRDY_Msk) != 0U)
    {
        USART1_ISR_RX_Handler();
    }

    /* Transmitter status */
    if ( ((USART1_REGS->US_CSR & US_CSR_USART_TXRDY_Msk) != 0U) && ((USART1_REGS->US_IMR & US_IMR_USART_TXRDY_Msk) != 0U) )
    {
        USART1_ISR_TX_Handler();
    }
}

void USART1_Initialize( void )
{
    /* Reset USART1 */
    USART1_REGS->US_CR = (US_CR_USART_RSTRX_Msk | US_CR_USART_RSTTX_Msk | US_CR_USART_RSTSTA_Msk);

    /* Enable USART1 */
    USART1_REGS->US_CR = (US_CR_USART_TXEN_Msk | US_CR_USART_RXEN_Msk);

    /* Configure USART1 mode */
    USART1_REGS->US_MR = (US_MR_USART_USCLKS_MCK | US_MR_USART_CHRL_8_BIT | US_MR_USART_PAR_NO | US_MR_USART_NBSTOP_1_BIT | US_MR_USART_OVER(0));

    /* Configure USART1 Baud Rate */
    USART1_REGS->US_BRGR = US_BRGR_CD(81U);

    /* Initialize instance object */
    usart1Obj.rxBuffer = NULL;
    usart1Obj.rxSize = 0;
    usart1Obj.rxProcessedSize = 0;
    usart1Obj.rxBusyStatus = false;
    usart1Obj.rxCallback = NULL;
    usart1Obj.txBuffer = NULL;
    usart1Obj.txSize = 0;
    usart1Obj.txProcessedSize = 0;
    usart1Obj.txBusyStatus = false;
    usart1Obj.txCallback = NULL;
    usart1Obj.errorStatus = USART_ERROR_NONE;
}

USART_ERROR USART1_ErrorGet( void )
{
    USART_ERROR errors = usart1Obj.errorStatus;

    usart1Obj.errorStatus = USART_ERROR_NONE;

    /* All errors are cleared, but send the previous error state */
    return errors;
}

bool USART1_SerialSetup( USART_SERIAL_SETUP *setup, uint32_t srcClkFreq )
{
    uint32_t baud;
    uint32_t brgVal = 0;
    uint32_t overSampVal = 0;
    uint32_t usartMode;
    bool status = false;

    if(usart1Obj.rxBusyStatus == true)
    {
        /* Transaction is in progress, so return without updating settings */
        return false;
    }
    if(usart1Obj.txBusyStatus == true)
    {
        /* Transaction is in progress, so return without updating settings */
        return false;
    }

    if (setup != NULL)
    {
        baud = setup->baudRate;

        if(srcClkFreq == 0U)
        {
            srcClkFreq = USART1_FrequencyGet();
        }

        /* Calculate BRG value */
        if (srcClkFreq >= (16U * baud))
        {
            brgVal = (srcClkFreq / (16U * baud));
        }
        else if (srcClkFreq >= (8U * baud))
        {
            brgVal = (srcClkFreq / (8U * baud));
            overSampVal = US_MR_USART_OVER(1U);
        }
        else
        {
            return false;
        }

        if (brgVal > 65535U)
        {
            /* The requested baud is so low that the ratio of srcClkFreq to baud exceeds the 16-bit register value of CD register */
            return false;
        }

        /* Configure USART1 mode */
        usartMode = USART1_REGS->US_MR;
        usartMode &= ~(US_MR_USART_CHRL_Msk | US_MR_USART_MODE9_Msk | US_MR_USART_PAR_Msk | US_MR_USART_NBSTOP_Msk | US_MR_USART_OVER_Msk);
        USART1_REGS->US_MR = usartMode | ((uint32_t)setup->dataWidth | (uint32_t)setup->parity | (uint32_t)setup->stopBits | (uint32_t)overSampVal);

        /* Configure USART1 Baud Rate */
        USART1_REGS->US_BRGR = US_BRGR_CD(brgVal);
        status = true;
    }

    return status;
}

bool USART1_Read( void *buffer, const size_t size )
{
    bool status = false;
    if(buffer != NULL)
    {
        /* Check if receive request is in progress */
        if(usart1Obj.rxBusyStatus == false)
        {
            /* Clear errors that may have got generated when there was no active read request pending */
            USART1_ErrorClear();

            /* Clear the errors related to previous read requests */
            usart1Obj.errorStatus = USART_ERROR_NONE;

            usart1Obj.rxBuffer = buffer;
            usart1Obj.rxSize = size;
            usart1Obj.rxProcessedSize = 0;
            usart1Obj.rxBusyStatus = true;

            status = true;

            /* Enable Read, Overrun, Parity and Framing error interrupts */
            USART1_REGS->US_IER = (US_IER_USART_RXRDY_Msk | US_IER_USART_FRAME_Msk | US_IER_USART_PARE_Msk | US_IER_USART_OVRE_Msk);
        }
    }

    return status;
}

bool USART1_Write( void *buffer, const size_t size )
{
    bool status = false;
    if(NULL != buffer)
    {
        uint8_t* pu8Data = (uint8_t *)buffer;
        uint16_t* pu16Data = (uint16_t*)buffer;
        uint32_t txData = 0U;
        /* Check if transmit request is in progress */
        if(usart1Obj.txBusyStatus == false)
        {
            usart1Obj.txBuffer = buffer;
            usart1Obj.txSize = size;
            usart1Obj.txProcessedSize = 0;
            usart1Obj.txBusyStatus = true;
            status = true;


            size_t txSize = usart1Obj.txSize;
            size_t txProcessedSize = usart1Obj.txProcessedSize;

            /* Initiate the transfer by writing as many bytes as possible */
            while (((USART1_REGS->US_CSR & US_CSR_USART_TXRDY_Msk) != 0U) && (txProcessedSize < txSize))
            {
                if ((USART1_REGS->US_MR & US_MR_USART_MODE9_Msk) != 0U)
                {
                    txData = pu16Data[txProcessedSize];
                }
                else
                {
                    txData = pu8Data[txProcessedSize];
                }
                USART1_REGS->US_THR = (txData & US_THR_TXCHR_Msk);
                txProcessedSize++;
            }

            usart1Obj.txProcessedSize = txProcessedSize;

            USART1_REGS->US_IER = US_IER_USART_TXRDY_Msk;
        }
    }
    return status;
}


bool USART1_TransmitComplete( void )
{
    return((USART1_REGS->US_CSR & US_CSR_USART_TXEMPTY_Msk) != 0U);

}

void USART1_WriteCallbackRegister( USART_CALLBACK callback, uintptr_t context )
{
    usart1Obj.txCallback = callback;
    usart1Obj.txContext = context;
}

void USART1_ReadCallbackRegister( USART_CALLBACK callback, uintptr_t context )
{
    usart1Obj.rxCallback = callback;
    usart1Obj.rxContext = context;
}

bool USART1_WriteIsBusy( void )
{
    return usart1Obj.txBusyStatus;
}

bool USART1_ReadIsBusy( void )
{
    return usart1Obj.rxBusyStatus;
}

bool USART1_ReadAbort(void)
{
    if (usart1Obj.rxBusyStatus == true)
    {
        /* Disable Read, Overrun, Parity and Framing error interrupts */
        USART1_REGS->US_IDR = (US_IDR_USART_RXRDY_Msk | US_IDR_USART_FRAME_Msk | US_IDR_USART_PARE_Msk | US_IDR_USART_OVRE_Msk);

        usart1Obj.rxBusyStatus = false;

        /* If required, application should read the num bytes processed prior to calling the read abort API */
        usart1Obj.rxProcessedSize = 0U;
        usart1Obj.rxSize = 0U;
    }

    return true;
}

size_t USART1_WriteCountGet( void )
{
    return usart1Obj.txProcessedSize;
}

size_t USART1_ReadCountGet( void )
{
    return usart1Obj.rxProcessedSize;
}

