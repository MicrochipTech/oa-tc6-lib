/**
 * UART1 Generated Driver Source File
 * 
 * @file        uart1.c
 *  
 * @ingroup     uartdriver
 *  
 * @brief       This is the generated driver source file for the UART1 driver
 *
 * @version     Driver Version 1.3.0
 *
 * @skipline    Device : dsPIC33CK256MP508
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

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

// Section: Included Files
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <xc.h>
#include "../uart1.h"

// Section: Macro Definitions
#define UART1_CLOCK 100000000U
#define UART1_BAUD_TO_BRG_WITH_FRACTIONAL(x) (UART1_CLOCK/(x))
#define UART1_BAUD_TO_BRG_WITH_BRGH_1(x) (UART1_CLOCK/(4U*(x))-1U)
#define UART1_BAUD_TO_BRG_WITH_BRGH_0(x) (UART1_CLOCK/(16U*(x))-1U)
#define UART1_BRG_TO_BAUD_WITH_FRACTIONAL(x) (UART1_CLOCK/(x))
#define UART1_BRG_TO_BAUD_WITH_BRGH_1(x) (UART1_CLOCK/(4U*((x)+1U)))
#define UART1_BRG_TO_BAUD_WITH_BRGH_0(x) (UART1_CLOCK/(16U*((x)+1U)))

#define UART1_MIN_ACHIEVABLE_BAUD_WITH_FRACTIONAL 95U
#define UART1_MIN_ACHIEVABLE_BAUD_WITH_BRGH_1 24U

// Section: Driver Interface

const struct UART_INTERFACE UART1_Drv = {
    .Initialize = &UART1_Initialize,
    .Deinitialize = &UART1_Deinitialize,
    .Read = &UART1_Read,
    .Write = &UART1_Write,
    .IsRxReady = &UART1_IsRxReady,
    .IsTxReady = &UART1_IsTxReady,
    .IsTxDone = &UART1_IsTxDone,
    .TransmitEnable = &UART1_TransmitEnable,
    .TransmitDisable = &UART1_TransmitDisable,
    .AutoBaudSet = &UART1_AutoBaudSet,
    .AutoBaudQuery = &UART1_AutoBaudQuery,
    .AutoBaudEventEnableGet = &UART1_AutoBaudEventEnableGet,
    .BRGCountSet = &UART1_BRGCountSet,
    .BRGCountGet = &UART1_BRGCountGet,
    .BaudRateSet = &UART1_BaudRateSet,
    .BaudRateGet = &UART1_BaudRateGet,
    .ErrorGet = &UART1_ErrorGet,
    .RxCompleteCallbackRegister = &UART1_RxCompleteCallbackRegister,
    .TxCompleteCallbackRegister = &UART1_TxCompleteCallbackRegister,
    .TxCollisionCallbackRegister = &UART1_TxCollisionCallbackRegister,
    .FramingErrorCallbackRegister = &UART1_FramingErrorCallbackRegister,
    .OverrunErrorCallbackRegister = &UART1_OverrunErrorCallbackRegister,
    .ParityErrorCallbackRegister = &UART1_ParityErrorCallbackRegister,
};

// Section: Private Variable Definitions

static volatile bool softwareBufferEmpty = true;
static union
{
    struct
    {
        uint16_t frammingError :1;
        uint16_t parityError :1;
        uint16_t overrunError :1;
        uint16_t txCollisionError :1;
        uint16_t autoBaudOverflow :1;
        uint16_t reserved :11;
    };
    size_t status;
} uartError;

// Section: Data Type Definitions

/**
 @ingroup  uartdriver
 @static   UART Driver Queue Status
 @brief    Defines the object required for the status of the queue
*/
static uint8_t * volatile rxTail;
static uint8_t *rxHead;
static uint8_t *txTail;
static uint8_t * volatile txHead;
static bool volatile rxOverflowed;

/**
 @ingroup  uartdriver
 @brief    Defines the length of the Transmit and Receive Buffers
*/

/* We add one extra byte than requested so that we don't have to have a separate
 * bit to determine the difference between buffer full and buffer empty, but
 * still be able to hold the amount of data requested by the user.  Empty is
 * when head == tail.  So full will result in head/tail being off by one due to
 * the extra byte.
 */
#define UART1_CONFIG_TX_BYTEQ_LENGTH (8+1)
#define UART1_CONFIG_RX_BYTEQ_LENGTH (8+1)

/**
 @ingroup  uartdriver
 @static   UART Driver Queue
 @brief    Defines the Transmit and Receive Buffers
*/
static uint8_t txQueue[UART1_CONFIG_TX_BYTEQ_LENGTH];
static uint8_t rxQueue[UART1_CONFIG_RX_BYTEQ_LENGTH];

static void (*UART1_RxCompleteHandler)(void);
static void (*UART1_TxCompleteHandler)(void);
static void (*UART1_TxCollisionHandler)(void);
static void (*UART1_FramingErrorHandler)(void);
static void (*UART1_OverrunErrorHandler)(void);
static void (*UART1_ParityErrorHandler)(void);

// Section: Driver Interface

void UART1_Initialize(void)
{
    IEC0bits.U1TXIE = 0;
    IEC0bits.U1RXIE = 0;
    IEC11bits.U1EVTIE = 0;

    // URXEN ; RXBIMD ; UARTEN disabled; MOD Asynchronous 8-bit UART; UTXBRK ; BRKOVR ; UTXEN ; USIDL ; WAKE ; ABAUD ; BRGH ; 
    U1MODE = 0x0;
    // STSEL 1 Stop bit sent, 1 checked at RX; BCLKMOD enabled; SLPEN ; FLO ; BCLKSEL FOSC/2; C0EN ; RUNOVF ; UTXINV ; URXINV ; HALFDPLX ; 
    U1MODEH = 0x800;
    // OERIE ; RXBKIF ; RXBKIE ; ABDOVF ; OERR ; TXCIE ; TXCIF ; FERIE ; TXMTIE ; ABDOVE ; CERIE ; CERIF ; PERIE ; 
    U1STA = 0x80;
    // URXISEL ; UTXBE ; UTXISEL TX_SEVEN_WORDS; URXBE ; STPMD ; TXWRE ; 
    U1STAH = 0x702E;
    // BaudRate 115207.37; Frequency 100000000 Hz; BRG 868; 
    U1BRG = 0x364;
    // BRG 0; 
    U1BRGH = 0x0;
    
    txHead = txQueue;
    txTail = txQueue;
    rxHead = rxQueue;
    rxTail = rxQueue;
   
    rxOverflowed = false;
    
    UART1_RxCompleteCallbackRegister(&UART1_RxCompleteCallback);
    UART1_TxCompleteCallbackRegister(&UART1_TxCompleteCallback);
    UART1_TxCollisionCallbackRegister(&UART1_TxCollisionCallback);
    UART1_FramingErrorCallbackRegister(&UART1_FramingErrorCallback);
    UART1_OverrunErrorCallbackRegister(&UART1_OverrunErrorCallback);
    UART1_ParityErrorCallbackRegister(&UART1_ParityErrorCallback);

    // UART Frame error interrupt
    U1STAbits.FERIE = 1;
    // UART Parity error interrupt
    U1STAbits.PERIE = 1;
    // UART Receive Buffer Overflow interrupt
    U1STAbits.OERIE = 1;
    // UART Transmit collision interrupt
    U1STAbits.TXCIE = 1;
    // UART Auto-Baud Overflow interrupt
    U1STAbits.ABDOVE = 1;  
    // UART Receive Interrupt
    IEC0bits.U1RXIE = 1;
    // UART Event interrupt
    IEC11bits.U1EVTIE = 1;
    // UART Error interrupt
    IEC3bits.U1EIE    = 1;
    
    //Make sure to set LAT bit corresponding to TxPin as high before UART initialization
    U1MODEbits.UARTEN = 1;   // enabling UART ON bit
    U1MODEbits.UTXEN = 1;
    U1MODEbits.URXEN = 1;
}

void UART1_Deinitialize(void)
{
    // UART Transmit interrupt
    IFS0bits.U1TXIF = 0;
    IEC0bits.U1TXIE = 0;
    
    // UART Receive Interrupt
    IFS0bits.U1RXIF = 0;
    IEC0bits.U1RXIE = 0;
    
    // UART Event interrupt
    IFS11bits.U1EVTIF = 0;
    IEC11bits.U1EVTIE = 0;
    
    // UART Error interrupt
    IFS3bits.U1EIF = 0;
    IEC3bits.U1EIE    = 0;
    
    U1MODE = 0x0;
    U1MODEH = 0x0;
    U1STA = 0x80;
    U1STAH = 0x2E;
    U1BRG = 0x0;
    U1BRGH = 0x0;
}

uint8_t UART1_Read(void)
{
    uint8_t data = 0;

    if(rxHead != rxTail)
	{
		data = *rxHead;

		rxHead++;

		if (rxHead == &rxQueue[UART1_CONFIG_RX_BYTEQ_LENGTH])
		{
			rxHead = rxQueue;
		}
	}
    return data;
}

void UART1_Write(uint8_t byte)
{
    // if software buffer is empty and hardware FIFO is not full write to TXREG directly
    if((softwareBufferEmpty == true) && (U1STAHbits.UTXBF == 0))
    {
        U1TXREG = byte;
    }
    else
    {
        while(UART1_IsTxReady() == 0)
        {
        }

        *txTail = byte;

        txTail++;
        
        if (txTail == &txQueue[UART1_CONFIG_TX_BYTEQ_LENGTH])
        {
            txTail = txQueue;
        }

        IEC0bits.U1TXIE = 1;
        softwareBufferEmpty = false;
    }
}

bool UART1_IsRxReady(void)
{    
    return !(rxHead == rxTail);
}

bool UART1_IsTxReady(void)
{
    uint16_t size;
    uint8_t *snapshot_txHead = (uint8_t*)txHead;
    
    if (txTail < snapshot_txHead)
    {
        size = (snapshot_txHead - txTail - 1);
    }
    else
    {
        size = ( UART1_CONFIG_TX_BYTEQ_LENGTH - (txTail - snapshot_txHead) - (uint16_t)1 );
    }
    
    return (size != (uint16_t)0);
}

bool UART1_IsTxDone(void)
{
    bool status = false;
    
    if(txTail == txHead)
    {
        status = (bool)(U1STAbits.TRMT && U1STAHbits.UTXBE);
    }
    
    return status;
}

void UART1_TransmitEnable(void)
{
    U1MODEbits.UTXEN = 1;
}

void UART1_TransmitDisable(void)
{
    U1MODEbits.UTXEN = 0;
}

void UART1_AutoBaudSet(bool enable)
{
    U1INTbits.ABDIF = 0U;
    U1INTbits.ABDIE = enable;
    U1MODEbits.ABAUD = enable;
}

bool UART1_AutoBaudQuery(void)
{
    return U1MODEbits.ABAUD;
}

bool UART1_AutoBaudEventEnableGet(void)
{ 
    return U1INTbits.ABDIE; 
}


void UART1_BRGCountSet(uint32_t brgValue)
{
    U1BRG = brgValue & 0xFFFFU;
    U1BRGH = (brgValue >>16U) & 0x000FU;
}

uint32_t UART1_BRGCountGet(void)
{
    uint32_t brgValue;
    
    brgValue = U1BRGH;
    brgValue = (brgValue << 16U) | U1BRG;
    
    return brgValue;
}

void UART1_BaudRateSet(uint32_t baudRate)
{
    uint32_t brgValue;
    
    if((baudRate >= UART1_MIN_ACHIEVABLE_BAUD_WITH_FRACTIONAL) && (baudRate != 0))
    {
        U1MODEHbits.BCLKMOD = 1;
        U1MODEbits.BRGH = 0;
        brgValue = UART1_BAUD_TO_BRG_WITH_FRACTIONAL(baudRate);
    }
    else if(baudRate >= UART1_MIN_ACHIEVABLE_BAUD_WITH_BRGH_1)
    {
        U1MODEHbits.BCLKMOD = 0;
        U1MODEbits.BRGH = 1;
        brgValue = UART1_BAUD_TO_BRG_WITH_BRGH_1(baudRate);
    }
    else
    {
        U1MODEHbits.BCLKMOD = 0;
        U1MODEbits.BRGH = 0;
        brgValue = UART1_BAUD_TO_BRG_WITH_BRGH_0(baudRate);
    }
    U1BRG = brgValue & 0xFFFFU;
    U1BRGH = (brgValue >>16U) & 0x000FU;
}

uint32_t UART1_BaudRateGet(void)
{
    uint32_t brgValue;
    uint32_t baudRate;
    
    brgValue = UART1_BRGCountGet();
    if((U1MODEHbits.BCLKMOD == 1) && (brgValue != 0))
    {
        baudRate = UART1_BRG_TO_BAUD_WITH_FRACTIONAL(brgValue);
    }
    else if(U1MODEbits.BRGH == 1)
    {
        baudRate = UART1_BRG_TO_BAUD_WITH_BRGH_1(brgValue);
    }
    else
    {
        baudRate = UART1_BRG_TO_BAUD_WITH_BRGH_0(brgValue);
    }
    return baudRate;
}

size_t UART1_ErrorGet(void)
{
    size_t fetchUartError = uartError.status;
    uartError.status = 0;
    return fetchUartError;
}

void UART1_RxCompleteCallbackRegister(void* handler)
{
    if(NULL != handler)
    {
        UART1_RxCompleteHandler = handler;
    }
}

void __attribute__ ((weak)) UART1_RxCompleteCallback(void)
{ 

} 

void UART1_TxCompleteCallbackRegister(void* handler)
{
    if(NULL != handler)
    {
        UART1_TxCompleteHandler = handler;
    }
}

void __attribute__ ((weak)) UART1_TxCompleteCallback(void)
{ 

} 

void UART1_TxCollisionCallbackRegister(void* handler)
{
    if(NULL != handler)
    {
        UART1_TxCollisionHandler = handler;
    }
}

void __attribute__ ((weak)) UART1_TxCollisionCallback(void)
{ 

} 

void UART1_FramingErrorCallbackRegister(void* handler)
{
    if(NULL != handler)
    {
        UART1_FramingErrorHandler = handler;
    }
}

void __attribute__ ((weak)) UART1_FramingErrorCallback(void)
{ 

} 

void UART1_OverrunErrorCallbackRegister(void* handler)
{
    if(NULL != handler)
    {
        UART1_OverrunErrorHandler = handler;
    }
}

void __attribute__ ((weak)) UART1_OverrunErrorCallback(void)
{ 

} 

void UART1_ParityErrorCallbackRegister(void* handler)
{
    if(NULL != handler)
    {
        UART1_ParityErrorHandler = handler;
    }
}

void __attribute__ ((weak)) UART1_ParityErrorCallback(void)
{ 

} 

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1TXInterrupt(void)
{

    if(txHead == txTail)
    {
        IEC0bits.U1TXIE = 0;
        softwareBufferEmpty = true;
    }
    else
    {
        IFS0bits.U1TXIF = 0;

        while(!(U1STAHbits.UTXBF == 1))
        {
            U1TXREG = *txHead;
            txHead++;

            if(txHead == &txQueue[UART1_CONFIG_TX_BYTEQ_LENGTH])
            {
                txHead = txQueue;
            }

            // Are we empty?
            if(txHead == txTail)
            {
				if(NULL != UART1_TxCompleteHandler)
					{
						(*UART1_TxCompleteHandler)();
					}
                break;
            }
        }
    }
}

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1RXInterrupt(void)
{
    size_t rxQueueSize = 0;
    uint8_t *rxTailPtr = NULL;
    
    IFS0bits.U1RXIF = 0;
    
    while(!(U1STAHbits.URXBE == 1))
    {
        *rxTail = U1RXREG;

        rxQueueSize = UART1_CONFIG_RX_BYTEQ_LENGTH - 1;
        rxTailPtr = rxTail;
        rxTailPtr++;
        // Will the increment not result in a wrap and not result in a pure collision?
        // This is most often condition so check first
        if ((rxTail != &rxQueue[rxQueueSize]) && (rxTailPtr != rxHead))
        {
            rxTail++;
        } 
        else if ( (rxTail == &rxQueue[rxQueueSize]) &&
                  (rxHead !=  rxQueue) )
        {
            // Pure wrap no collision
            rxTail = rxQueue;
        } 
        else // must be collision
        {
            rxOverflowed = true;
        }
    }
	
    if(NULL != UART1_RxCompleteHandler)
    {
        (*UART1_RxCompleteHandler)();
    }
}

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1EInterrupt(void)
{
    if (U1STAbits.ABDOVF == 1)
    {
        uartError.autoBaudOverflow = uartError.status|UART_ERROR_AUTOBAUD_OVERFLOW_MASK;
        U1STAbits.ABDOVF = 0;
    }
    
    if (U1STAbits.TXCIF == 1)
    {
        uartError.txCollisionError = uartError.status|UART_ERROR_TX_COLLISION_MASK;
        if(NULL != UART1_TxCollisionHandler)
        {
            (*UART1_TxCollisionHandler)();
        }
        
        U1STAbits.TXCIF = 0;
    }
    
    if (U1STAbits.OERR == 1)
    {
        uartError.overrunError = uartError.status|UART_ERROR_RX_OVERRUN_MASK;
        if(NULL != UART1_OverrunErrorHandler)
        {
            (*UART1_OverrunErrorHandler)();
        }
        
        U1STAbits.OERR = 0;
    }
    
    if (U1STAbits.PERR == 1)
    {
        uartError.parityError = uartError.status|UART_ERROR_PARITY_MASK;
        if(NULL != UART1_ParityErrorHandler)
        {
            (*UART1_ParityErrorHandler)();
        }
    }
    
    if (U1STAbits.FERR == 1)
    {
        uartError.frammingError = uartError.status|UART_ERROR_FRAMING_MASK;
        if(NULL != UART1_FramingErrorHandler)
        {
            (*UART1_FramingErrorHandler)();
        }
    }
        
    IFS3bits.U1EIF = 0;
}

/* ISR for UART Event Interrupt */
void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1EVTInterrupt(void)
{
    U1INTbits.ABDIF = false;
    IFS11bits.U1EVTIF = false;
}
