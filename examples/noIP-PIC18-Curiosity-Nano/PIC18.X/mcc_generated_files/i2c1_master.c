/**
  I2C1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    i2c1_master.c

  @Summary
    This is the generated driver implementation file for the I2C1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for I2C1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F57Q43
        Driver Version    :  1.0.2
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above or later
        MPLAB             :  MPLAB X 6.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "i2c1_master.h"
#include <xc.h>

// I2C1 STATES
typedef enum {
    I2C1_IDLE = 0,
    I2C1_SEND_ADR_READ,
    I2C1_SEND_ADR_WRITE,
    I2C1_TX,
    I2C1_RX,
    I2C1_TX_EMPTY,
    I2C1_RX_EMPTY,        
    I2C1_SEND_RESTART_READ,
    I2C1_SEND_RESTART_WRITE,
    I2C1_SEND_RESTART,
    I2C1_SEND_STOP,
    I2C1_RX_ACK,
    I2C1_TX_ACK,
    I2C1_RX_NACK_STOP,
    I2C1_RX_NACK_RESTART,
    I2C1_RESET,
    I2C1_ADDRESS_NACK,
    I2C1_BUS_COLLISION,
    I2C1_BUS_ERROR
} i2c1_fsm_states_t;

// I2C1 Event callBack List
typedef enum {
    I2C1_DATA_COMPLETE = 0,
    I2C1_WRITE_COLLISION,
    I2C1_ADDR_NACK,
    I2C1_DATA_NACK,
    I2C1_TIMEOUT,
    I2C1_NULL
} i2c1_callbackIndex_t;

// I2C1 Status Structure
typedef struct
{
    i2c1_callback_t callbackTable[6];
    void *callbackPayload[6];           //  each callBack can have a payload
    uint16_t time_out;                  // I2C1 Timeout Counter between I2C1 Events.
    uint16_t time_out_value;            // Reload value for the timeouts
    i2c1_address_t address;             // The I2C1 Address
    uint8_t *data_ptr;                  // pointer to a data buffer
    size_t data_length;                 // Bytes in the data buffer
    i2c1_fsm_states_t state;            // Driver State
    i2c1_error_t error;
    unsigned addressNackCheck:2;
    unsigned busy:1;
    unsigned inUse:1;
    unsigned bufferFree:1;

} i2c1_status_t;

static void I2C1_SetCallback(i2c1_callbackIndex_t idx, i2c1_callback_t cb, void *ptr);
static void I2C1_Poller(void);
static inline void I2C1_ClearInterruptFlags(void);
static inline void I2C1_MasterFsm(void);

/* I2C1 interfaces */
static inline bool I2C1_MasterOpen(void);
static inline void I2C1_MasterClose(void);    
static inline uint8_t I2C1_MasterGetRxData(void);
static inline void I2C1_MasterSendTxData(uint8_t data);
static inline void I2C1_MasterSetCounter(uint8_t counter);
static inline uint8_t I2C1_MasterGetCounter();
static inline void I2C1_MasterResetBus(void);
static inline void I2C1_MasterEnableRestart(void);
static inline void I2C1_MasterDisableRestart(void);
static inline void I2C1_MasterStop(void);
static inline bool I2C1_MasterIsNack(void);
static inline void I2C1_MasterSendAck(void);
static inline void I2C1_MasterSendNack(void);
static inline void I2C1_MasterClearBusCollision(void);
static inline bool I2C1_MasterIsRxBufFull(void);
static inline bool I2C1_MasterIsTxBufEmpty(void);
static inline bool I2C1_MasterIsStopFlagSet(void);
static inline bool I2C1_MasterIsCountFlagSet(void);
static inline bool I2C1_MasterIsNackFlagSet(void);
static inline void I2C1_MasterClearStopFlag(void);
static inline void I2C1_MasterClearCountFlag(void);
static inline void I2C1_MasterClearNackFlag(void);

/* Interrupt interfaces */
static inline void I2C1_MasterEnableIrq(void);
static inline bool I2C1_MasterIsIrqEnabled(void);
static inline void I2C1_MasterDisableIrq(void);
static inline void I2C1_MasterClearIrq(void);
static inline void I2C1_MasterWaitForEvent(void);

static i2c1_fsm_states_t I2C1_DO_IDLE(void);
static i2c1_fsm_states_t I2C1_DO_SEND_ADR_READ(void);
static i2c1_fsm_states_t I2C1_DO_SEND_ADR_WRITE(void);
static i2c1_fsm_states_t I2C1_DO_TX(void);
static i2c1_fsm_states_t I2C1_DO_RX(void);
static i2c1_fsm_states_t I2C1_DO_TX_EMPTY(void);
static i2c1_fsm_states_t I2C1_DO_RX_EMPTY(void);
static i2c1_fsm_states_t I2C1_DO_SEND_RESTART_READ(void);
static i2c1_fsm_states_t I2C1_DO_SEND_RESTART_WRITE(void);
static i2c1_fsm_states_t I2C1_DO_SEND_RESTART(void);
static i2c1_fsm_states_t I2C1_DO_SEND_STOP(void);
static i2c1_fsm_states_t I2C1_DO_RX_ACK(void);
static i2c1_fsm_states_t I2C1_DO_TX_ACK(void);
static i2c1_fsm_states_t I2C1_DO_RX_NACK_STOP(void);
static i2c1_fsm_states_t I2C1_DO_RX_NACK_RESTART(void);
static i2c1_fsm_states_t I2C1_DO_RESET(void);
static i2c1_fsm_states_t I2C1_DO_ADDRESS_NACK(void);
static i2c1_fsm_states_t I2C1_DO_BUS_COLLISION(void);
static i2c1_fsm_states_t I2C1_DO_BUS_ERROR(void);

typedef i2c1_fsm_states_t (*i2c1FsmHandler)(void);
const i2c1FsmHandler i2c1_fsmStateTable[] = {
    I2C1_DO_IDLE,
    I2C1_DO_SEND_ADR_READ,
    I2C1_DO_SEND_ADR_WRITE,
    I2C1_DO_TX,
    I2C1_DO_RX,
    I2C1_DO_TX_EMPTY,
    I2C1_DO_RX_EMPTY,
    I2C1_DO_SEND_RESTART_READ,
    I2C1_DO_SEND_RESTART_WRITE,
    I2C1_DO_SEND_RESTART,
    I2C1_DO_SEND_STOP,
    I2C1_DO_RX_ACK,
    I2C1_DO_TX_ACK,
    I2C1_DO_RX_NACK_STOP,
    I2C1_DO_RX_NACK_RESTART,
    I2C1_DO_RESET,
    I2C1_DO_ADDRESS_NACK,
    I2C1_DO_BUS_COLLISION,
    I2C1_DO_BUS_ERROR
};

i2c1_status_t I2C1_Status = {0};

void I2C1_Initialize()
{
    //EN disabled; RSEN disabled; S Cleared by hardware after Start; CSTR Enable clocking; MODE 7-bit address; 
    I2C1CON0 = 0x04;
    //ACKCNT Acknowledge; ACKDT Acknowledge; ACKSTAT ACK received; ACKT 0; RXO 0; TXU 0; CSD Clock Stretching enabled; 
    I2C1CON1 = 0x80;
    //ACNT disabled; GCEN disabled; FME disabled; ABD disabled; SDAHT 30 ns hold time; BFRET 8 I2C Clock pulses; 
    I2C1CON2 = 0x18;
    //CLK MFINTOSC; 
    I2C1CLK = 0x03;
    //CNTIF 0; ACKTIF 0; WRIF 0; ADRIF 0; PCIF 0; RSCIF 0; SCIF 0; 
    I2C1PIR = 0x00;
    //CNTIE disabled; ACKTIE disabled; WRIE disabled; ADRIE disabled; PCIE disabled; RSCIE disabled; SCIE disabled; 
    I2C1PIE = 0x00;
    //BTOIF No bus timeout; BCLIF No bus collision detected; NACKIF No NACK/Error detected; BTOIE disabled; BCLIE disabled; NACKIE disabled; 
    I2C1ERR = 0x00;
    //Count register 
    I2C1CNT = 0xFF;
    return;
}

i2c1_error_t I2C1_Open(i2c1_address_t address)
{
    i2c1_error_t returnValue = I2C1_BUSY;
    
    if(!I2C1_Status.inUse)
    {
        I2C1_Status.address = address;
        I2C1_Status.busy = 0;
        I2C1_Status.inUse = 1;
        I2C1_Status.addressNackCheck = 0;
        I2C1_Status.state = I2C1_RESET;
        I2C1_Status.time_out_value = 500; // MCC should determine a reasonable starting value here.
        I2C1_Status.bufferFree = 1;

        // set all the call backs to a default of sending stop
        I2C1_Status.callbackTable[I2C1_DATA_COMPLETE]=I2C1_CallbackReturnStop;
        I2C1_Status.callbackPayload[I2C1_DATA_COMPLETE] = NULL;
        I2C1_Status.callbackTable[I2C1_WRITE_COLLISION]=I2C1_CallbackReturnStop;
        I2C1_Status.callbackPayload[I2C1_WRITE_COLLISION] = NULL;
        I2C1_Status.callbackTable[I2C1_ADDR_NACK]=I2C1_CallbackReturnStop;
        I2C1_Status.callbackPayload[I2C1_ADDR_NACK] = NULL;
        I2C1_Status.callbackTable[I2C1_DATA_NACK]=I2C1_CallbackReturnStop;
        I2C1_Status.callbackPayload[I2C1_DATA_NACK] = NULL;
        I2C1_Status.callbackTable[I2C1_TIMEOUT]=I2C1_CallbackReturnReset;
        I2C1_Status.callbackPayload[I2C1_TIMEOUT] = NULL;
        
        I2C1_MasterClearIrq();
        I2C1_MasterOpen();
        returnValue = I2C1_NOERR;
    }
    return returnValue;
}

i2c1_error_t I2C1_Close(void)
{
    i2c1_error_t returnValue = I2C1_BUSY;
    if(!I2C1_Status.busy)
    {
        I2C1_Status.inUse = 0;
        I2C1_Status.address = 0xff;
        I2C1_MasterClearIrq();
        I2C1_MasterDisableIrq();
        I2C1_MasterClose();
        returnValue = I2C1_Status.error;
    }
    return returnValue;
}

i2c1_error_t I2C1_MasterOperation(bool read)
{
    i2c1_error_t returnValue = I2C1_BUSY;
    if(!I2C1_Status.busy)
    {
        I2C1_Status.busy = true;
        returnValue = I2C1_NOERR;
        I2C1_MasterSetCounter((uint8_t) I2C1_Status.data_length);

        if(read)
        {
            I2C1_Status.state = I2C1_RX;
            I2C1_DO_SEND_ADR_READ();
        }
        else
        {
            I2C1_Status.state = I2C1_TX;
            I2C1_DO_SEND_ADR_WRITE();
        }
        I2C1_Poller();
    }
    return returnValue;
}

i2c1_error_t I2C1_MasterRead(void)
{
    return I2C1_MasterOperation(true);
}

i2c1_error_t I2C1_MasterWrite(void)
{
    return I2C1_MasterOperation(false);
}

void I2C1_SetTimeOut(uint8_t timeOutValue)
{
    I2C1_MasterDisableIrq();
    I2C1_Status.time_out_value = timeOutValue;
    I2C1_MasterEnableIrq();
}

void I2C1_SetBuffer(void *buffer, size_t bufferSize)
{
    if(I2C1_Status.bufferFree)
    {
        I2C1_Status.data_ptr = buffer;
        I2C1_Status.data_length = bufferSize;
        I2C1_Status.bufferFree = false;
    }
}

void I2C1_SetDataCompleteCallback(i2c1_callback_t cb, void *ptr)
{
    I2C1_SetCallback(I2C1_DATA_COMPLETE, cb, ptr);
}

void I2C1_SetWriteCollisionCallback(i2c1_callback_t cb, void *ptr)
{
    I2C1_SetCallback(I2C1_WRITE_COLLISION, cb, ptr);
}

void I2C1_SetAddressNackCallback(i2c1_callback_t cb, void *ptr)
{
    I2C1_SetCallback(I2C1_ADDR_NACK, cb, ptr);
}

void I2C1_SetDataNackCallback(i2c1_callback_t cb, void *ptr)
{
    I2C1_SetCallback(I2C1_DATA_NACK, cb, ptr);
}

void I2C1_SetTimeoutCallback(i2c1_callback_t cb, void *ptr)
{
    I2C1_SetCallback(I2C1_TIMEOUT, cb, ptr);
}

static void I2C1_SetCallback(i2c1_callbackIndex_t idx, i2c1_callback_t cb, void *ptr)
{
    if(cb)
    {
        I2C1_Status.callbackTable[idx] = cb;
        I2C1_Status.callbackPayload[idx] = ptr;
    }
    else
    {
        I2C1_Status.callbackTable[idx] = I2C1_CallbackReturnStop;
        I2C1_Status.callbackPayload[idx] = NULL;
    }
}

static void I2C1_Poller(void)
{
    while(I2C1_Status.busy)
    {
        I2C1_MasterWaitForEvent();
        I2C1_MasterFsm();
    }
}

static inline void I2C1_MasterFsm(void)
{
    I2C1_ClearInterruptFlags();

    if(I2C1_Status.addressNackCheck && I2C1_MasterIsNack())
    {
        I2C1_Status.state = I2C1_ADDRESS_NACK;
    }
    I2C1_Status.state = i2c1_fsmStateTable[I2C1_Status.state]();
}

static inline void I2C1_ClearInterruptFlags(void)
{
    if(I2C1_MasterIsCountFlagSet())
    {
        I2C1_MasterClearCountFlag();
    }
    else if(I2C1_MasterIsStopFlagSet())
    {
        I2C1_MasterClearStopFlag();
    }
    else if(I2C1_MasterIsNackFlagSet())
    {
        I2C1_MasterClearNackFlag();
    }
}

static i2c1_fsm_states_t I2C1_DO_IDLE(void)
{
    I2C1_Status.busy = false;
    I2C1_Status.error = I2C1_NOERR;
    return I2C1_RESET;
}

static i2c1_fsm_states_t I2C1_DO_SEND_ADR_READ(void)
{
    I2C1_Status.addressNackCheck = 2;
    if(I2C1_Status.data_length ==  1)
    {
        I2C1_DO_RX_EMPTY();
    }
    I2C1_MasterSendTxData((uint8_t) (I2C1_Status.address << 1 | 1));
    return I2C1_RX;
}

static i2c1_fsm_states_t I2C1_DO_SEND_ADR_WRITE(void)
{
    I2C1_Status.addressNackCheck = 2;
    I2C1_MasterSendTxData((uint8_t) (I2C1_Status.address << 1));
    return I2C1_TX;
}

static i2c1_fsm_states_t I2C1_DO_TX(void)
{
    if(I2C1_MasterIsNack())
    {
        switch(I2C1_Status.callbackTable[I2C1_DATA_NACK](I2C1_Status.callbackPayload[I2C1_DATA_NACK]))
        {
            case I2C1_RESTART_READ:
                return I2C1_DO_SEND_RESTART_READ();
            case I2C1_RESTART_WRITE:
                  return I2C1_DO_SEND_RESTART_WRITE();
            default:
            case I2C1_CONTINUE:
            case I2C1_STOP:
                return I2C1_IDLE;
        }
    }
    else if(I2C1_MasterIsTxBufEmpty())
    {
        if(I2C1_Status.addressNackCheck)
        {
            I2C1_Status.addressNackCheck--;
        }
        uint8_t dataTx = *I2C1_Status.data_ptr++;
        i2c1_fsm_states_t retFsmState = (--I2C1_Status.data_length)?I2C1_TX:I2C1_DO_TX_EMPTY();
        I2C1_MasterSendTxData(dataTx);
        return retFsmState;
    }
    else
    {
        return I2C1_TX;
    }
}

static i2c1_fsm_states_t I2C1_DO_RX(void)
{
    if(!I2C1_MasterIsRxBufFull())
    {
        return I2C1_RX;
    }
    if(I2C1_Status.addressNackCheck)
    {
        I2C1_Status.addressNackCheck--;
    }

    if(--I2C1_Status.data_length)
    {
        *I2C1_Status.data_ptr++ = I2C1_MasterGetRxData();
        return I2C1_RX;
    }
    else
    {
        i2c1_fsm_states_t retFsmState = I2C1_DO_RX_EMPTY();
        *I2C1_Status.data_ptr++ = I2C1_MasterGetRxData();
        return retFsmState;
    }
}

static i2c1_fsm_states_t I2C1_DO_TX_EMPTY(void)
{
    I2C1_Status.bufferFree = true;
    switch(I2C1_Status.callbackTable[I2C1_DATA_COMPLETE](I2C1_Status.callbackPayload[I2C1_DATA_COMPLETE]))
    {
        case I2C1_RESTART_READ:
            I2C1_MasterEnableRestart();
            return I2C1_SEND_RESTART_READ;
        case I2C1_CONTINUE:
            // Avoid the counter stop condition , Counter is incremented by 1
            I2C1_MasterSetCounter((uint8_t) I2C1_Status.data_length + 1);
            return I2C1_TX;
        default:
        case I2C1_STOP:
            I2C1_MasterDisableRestart();
            return I2C1_SEND_STOP;
    }
}

static i2c1_fsm_states_t I2C1_DO_RX_EMPTY(void)
{
    I2C1_Status.bufferFree = true;
    switch(I2C1_Status.callbackTable[I2C1_DATA_COMPLETE](I2C1_Status.callbackPayload[I2C1_DATA_COMPLETE]))
    {
        case I2C1_RESTART_WRITE:
            I2C1_MasterEnableRestart();
            return I2C1_SEND_RESTART_WRITE;
        case I2C1_RESTART_READ:
            I2C1_MasterEnableRestart();
            return I2C1_SEND_RESTART_READ;
        case I2C1_CONTINUE:
            // Avoid the counter stop condition , Counter is incremented by 1
            I2C1_MasterSetCounter((uint8_t) (I2C1_Status.data_length + 1));
            return I2C1_RX;
        default:
        case I2C1_STOP:
            if(I2C1_Status.state != I2C1_SEND_RESTART_READ)
            {
                I2C1_MasterDisableRestart();
            }
            return I2C1_RESET;
    }
}

static i2c1_fsm_states_t I2C1_DO_SEND_RESTART_READ(void)
{
    I2C1_MasterSetCounter((uint8_t) I2C1_Status.data_length);
    return I2C1_DO_SEND_ADR_READ();
}

static i2c1_fsm_states_t I2C1_DO_SEND_RESTART_WRITE(void)
{
    return I2C1_SEND_ADR_WRITE;
}


static i2c1_fsm_states_t I2C1_DO_SEND_RESTART(void)
{
    return I2C1_SEND_ADR_READ;
}

static i2c1_fsm_states_t I2C1_DO_SEND_STOP(void)
{
    I2C1_MasterStop();
    if(I2C1_MasterGetCounter())
    {
        I2C1_MasterSetCounter(0);
        I2C1_MasterSendTxData(0);
    }
    return I2C1_IDLE;
}

static i2c1_fsm_states_t I2C1_DO_RX_ACK(void)
{
    I2C1_MasterSendAck();
    return I2C1_RX;
}

static i2c1_fsm_states_t I2C1_DO_TX_ACK(void)
{
    I2C1_MasterSendAck();
    return I2C1_TX;
}

static i2c1_fsm_states_t I2C1_DO_RX_NACK_STOP(void)
{
    I2C1_MasterSendNack();
    I2C1_MasterStop();
    return I2C1_DO_IDLE();
}

static i2c1_fsm_states_t I2C1_DO_RX_NACK_RESTART(void)
{
    I2C1_MasterSendNack();
    return I2C1_SEND_RESTART;
}

static i2c1_fsm_states_t I2C1_DO_RESET(void)
{
    I2C1_MasterResetBus();
    I2C1_Status.busy = false;
    I2C1_Status.error = I2C1_NOERR;
    return I2C1_RESET;
}
static i2c1_fsm_states_t I2C1_DO_ADDRESS_NACK(void)
{
    I2C1_Status.addressNackCheck = 0;
    I2C1_Status.error = I2C1_FAIL;
    I2C1_Status.busy = false;
    switch(I2C1_Status.callbackTable[I2C1_ADDR_NACK](I2C1_Status.callbackPayload[I2C1_ADDR_NACK]))
    {
        case I2C1_RESTART_READ:
        case I2C1_RESTART_WRITE:
            return I2C1_DO_SEND_RESTART();
        default:
            return I2C1_RESET;
    }
}

static i2c1_fsm_states_t I2C1_DO_BUS_COLLISION(void)
{
    // Clear bus collision status flag
    I2C1_MasterClearIrq();

    I2C1_Status.error = I2C1_FAIL;
    switch (I2C1_Status.callbackTable[I2C1_WRITE_COLLISION](I2C1_Status.callbackPayload[I2C1_WRITE_COLLISION])) {
    case I2C1_RESTART_READ:
        return I2C1_DO_SEND_RESTART_READ();
    case I2C1_RESTART_WRITE:
        return I2C1_DO_SEND_RESTART_WRITE();
    default:
        return I2C1_DO_RESET();
    }
}

static i2c1_fsm_states_t I2C1_DO_BUS_ERROR(void)
{
    I2C1_MasterResetBus();
    I2C1_Status.busy  = false;
    I2C1_Status.error = I2C1_FAIL;
    return I2C1_RESET;
}

void I2C1_BusCollisionIsr(void)
{
    I2C1_MasterClearBusCollision();
    I2C1_Status.state = I2C1_RESET;
}

i2c1_operations_t I2C1_CallbackReturnStop(void *funPtr)
{
    return I2C1_STOP;
}

i2c1_operations_t I2C1_CallbackReturnReset(void *funPtr)
{
    return I2C1_RESET_LINK;
}

i2c1_operations_t I2C1_CallbackRestartWrite(void *funPtr)
{
    return I2C1_RESTART_WRITE;
}

i2c1_operations_t I2C1_CallbackRestartRead(void *funPtr)
{
    return I2C1_RESTART_READ;
}



/* I2C1 Register Level interfaces */
static inline bool I2C1_MasterOpen(void)
{
    if(!I2C1CON0bits.EN)
    {
        //CNTIF 0; ACKTIF 0; WRIF 0; ADRIF 0; PCIF 0; RSCIF 0; SCIF 0; 
        I2C1PIR = 0x00;
        //CNTIE disabled; ACKTIE disabled; WRIE disabled; ADRIE disabled; PCIE disabled; RSCIE disabled; SCIE disabled; 
        I2C1PIE = 0x00;
        //BTOIF No bus timeout; BCLIF No bus collision detected; NACKIF No NACK/Error detected; BTOIE disabled; BCLIE disabled; NACKIE disabled; 
        I2C1ERR = 0x00;
        //Count register 
        I2C1CNT = 0xFF;
        //Clock PadReg Configuration
        RB1I2C   = 0x51;
        //Data PadReg Configuration
        RB2I2C   = 0x51;
        //Enable I2C1
        I2C1CON0bits.EN = 1;
        return true;
    }
    return false;
}

static inline void I2C1_MasterClose(void)
{
    //Disable I2C1
    I2C1CON0bits.EN = 0;
    //CNTIF 0; ACKTIF 0; WRIF 0; ADRIF 0; PCIF 0; RSCIF 0; SCIF 0; 
    I2C1PIR = 0x00;
    //Set Clear Buffer Flag
    I2C1STAT1bits.CLRBF = 1;
}

static inline uint8_t I2C1_MasterGetRxData(void)
{
    return I2C1RXB;
}

static inline void I2C1_MasterSendTxData(uint8_t data)
{
    I2C1TXB  = data;
}

static inline uint8_t I2C1_MasterGetCounter()
{
    return I2C1CNT;
}

static inline void I2C1_MasterSetCounter(uint8_t counter)
{
    I2C1CNT = counter;
}

static inline void I2C1_MasterResetBus(void)
{
    //Disable I2C1
    I2C1CON0bits.EN = 0;
    //Set Clear Buffer Flag
    I2C1STAT1bits.CLRBF = 1;
    //Enable I2C1
    I2C1CON0bits.EN = 1;
}

static inline void I2C1_MasterEnableRestart(void)
{
    //Enable I2C1 Restart
    I2C1CON0bits.RSEN = 1;
}

static inline void I2C1_MasterDisableRestart(void)
{
    //Disable I2C1 Restart
    I2C1CON0bits.RSEN = 0;
}

static inline void I2C1_MasterStop(void)
{
    //Clear Start Bit
    I2C1CON0bits.S = 0;
}

static inline bool I2C1_MasterIsNack(void)
{
    return I2C1CON1bits.ACKSTAT;
}

static inline void I2C1_MasterSendAck(void)
{
    I2C1CON1bits.ACKDT = 0;
}

static inline void I2C1_MasterSendNack(void)
{
    I2C1CON1bits.ACKDT = 1;
}

static inline void I2C1_MasterClearBusCollision(void)
{
    I2C1ERRbits.BCLIF = 0;
    I2C1ERRbits.BTOIF = 0;
    I2C1ERRbits.NACKIF = 0;
}

static inline bool I2C1_MasterIsRxBufFull(void)
{
    return I2C1STAT1bits.RXBF;
}

static inline bool I2C1_MasterIsTxBufEmpty(void)
{
    return I2C1STAT1bits.TXBE;
}

static inline bool I2C1_MasterIsStopFlagSet(void)
{
    return I2C1PIRbits.PCIF;
}

static inline bool I2C1_MasterIsCountFlagSet(void)
{
    return I2C1PIRbits.CNTIF;
}

static inline bool I2C1_MasterIsNackFlagSet(void)
{
    return I2C1ERRbits.NACKIF;
}

static inline void I2C1_MasterClearStopFlag(void)
{
    I2C1PIRbits.PCIF = 0;
}

static inline void I2C1_MasterClearCountFlag(void)
{
    I2C1PIRbits.CNTIF = 0;
}

static inline void I2C1_MasterClearNackFlag(void)
{
    I2C1ERRbits.NACKIF = 0;
}

static inline void I2C1_MasterEnableIrq(void)
{
    PIE7bits.I2C1IE    = 1;
    PIE7bits.I2C1EIE    = 1;
    PIE7bits.I2C1RXIE  = 1;
    PIE7bits.I2C1TXIE  = 1;

    I2C1PIEbits.PCIE = 1; 
    I2C1PIEbits.CNTIE = 1; 
    I2C1ERRbits.NACKIE = 1; 
}

static inline bool I2C1_MasterIsIrqEnabled(void)
{
    return (PIE7bits.I2C1RXIE && PIE7bits.I2C1TXIE && PIE7bits.I2C1IE);
}

static inline void I2C1_MasterDisableIrq(void)
{
    PIE7bits.I2C1IE    = 0;
    PIE7bits.I2C1EIE    = 0;
    PIE7bits.I2C1RXIE  = 0;
    PIE7bits.I2C1TXIE  = 0;
    I2C1PIEbits.SCIE = 0;
    I2C1PIEbits.PCIE = 0;
    I2C1PIEbits.CNTIE = 0;
    I2C1PIEbits.ACKTIE = 0;
    I2C1PIEbits.RSCIE = 0;
    I2C1ERRbits.BCLIE = 0;
    I2C1ERRbits.BTOIE = 0;
    I2C1ERRbits.NACKIE = 0;
}

static inline void I2C1_MasterClearIrq(void)
{
    I2C1PIR = 0x00;
}

static inline void I2C1_MasterWaitForEvent(void)
{
    while(1)
    {
        if(PIR7bits.I2C1TXIF)
        {    
            break;
        }
        if(PIR7bits.I2C1RXIF)
        {  
            break;
        } 
        if(I2C1PIRbits.PCIF)
        {
            break;
        } 
        if(I2C1PIRbits.CNTIF)
        {
            break;
        }
        if(I2C1ERRbits.NACKIF)
        {
            break;
        }
    }
}
