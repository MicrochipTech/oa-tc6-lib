/**
 * I2C2 Generated Driver Source File
 *
 * @file      i2c2.c
 *
 * @ingroup   i2chostdriver
 *
 * @brief     This is the generated driver source file for I2C2 driver
 *
 * @skipline @version   Firmware Driver Version 1.1.4
 *
 * @skipline @version   PLIB Version 1.0.1
 *
 * @skipline  Device : dsPIC33AK512MPS512
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

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

#include <xc.h>
#include "../i2c2.h"

/**
 @ingroup  i2chostdriver
 @enum     I2C_HOST_STATES
 @brief    This data type defines the I2C Task State
*/
enum I2C_HOST_STATES
{
    I2C_HOST_IDLE,                            /**< value 1 I2C Host idle */
    I2C_HOST_START,                           /**< I2C Host start */
    I2C_HOST_SEND_7BIT_ADDRESS,               /**< I2C Host send 7bit Client address */
    I2C_HOST_SEND_10BIT_LOWER_ADDRESS,        /**< I2C Host send 10bit LSB Client address */
    I2C_HOST_SEND_10BIT_HIGHER_ADDRESS,       /**< I2C Host send 10bit MSB Client address */
    I2C_HOST_CHECK_ADDRESS_ACK_NACK_STATUS,   /**< I2C Host check 7bit or 10bit LSB Client address ACK or NACK status from Client device */
    I2C_HOST_SEND_DATA_TO_CLIENT,             /**< I2C Host send data to Client device */
    I2C_HOST_RECEIVE_DATA_FROM_CLIENT,        /**< I2C Host receive data from Client device */
    I2C_HOST_RECEIVE_WAIT_ACK_NACK_COMPLETE,  /**< I2C Host receive wait for ack process complete */
    I2C_HOST_STOP                             /**< I2C Host stop */
};

/**
 @ingroup  i2chostdriver
 @struct   I2C_OBJECT
 @brief    This data structure defines the I2C Instance Object
*/
struct I2C_OBJECT
{
    enum I2C_HOST_ERROR   error; ///< I2C Error status
    enum I2C_HOST_STATES  state; ///< I2C Host process state
    size_t      writeDataCount;       ///< Number of data to transfer
    size_t      readDataCount;        ///< Number of data to receive
    uint8_t     clientAddressHigh;    ///< 10bit Client higher device address [<7:4>(Reserve '1'), <3>(Reserve '0'), <2:1>(A9, A8), <0> (R,_W)]
    uint8_t     clientAddressLow;     ///< Client device address {10bit:[<7:0>(A7:A0), 7bit:[<7:1>(A6:A0), <0> (R, _W)]]
    uint8_t     *writeData;           ///< Transmit data buffer
    uint8_t     *readData;            ///< Receive data buffer
    bool        is10BitAddressMode;   ///< 7bit or 10 bit address mode status
    bool        isWriteMode;          ///< I2C Bus Write mode or Read mode
};

//I2C Start, Restart, Stop, Receive, General call enable masks
#define I2C_MASK_ALL_ENABLE                     0x001F

// I2C object Address information
#define I2C_ADDRESS_READ_WRITE_POS              0x1
#define I2C_10_BIT_HIGHER_ADDRESS_SHIFT_POS     0x7
#define I2C_10_BIT_HIGHER_ADDRESS_MASK          0x6
#define I2C_10_BIT_HIGHER_RESERVED_ADDRESS      0xF0
#define I2C_10_BIT_LOWER_ADDRESS_MASK           0xFF
#define I2C_WRITE_READ_ADDRESS_POS_MASK         0xFE
#define I2C_READ_MODE                           0x1
#define I2C_WRITE_MODE                          0x0
#define I2C_7_BIT_ADDRESS_SIZE                  0x7F
#define I2C_10_BIT_ADDRESS_SIZE                 0x3FF

// I2C Bus speed information
#define I2C_FREQ_100KHZ  (100000UL)     // 100Khz
#define I2C_FREQ_400KHZ  (400000UL)     // 400Khz
#define I2C_FREQ_1MHZ    (1000000UL)  // 1Mhz

// I2C Bus Macro's
#define I2C_EnableModule()  (I2C2CON1bits.ON = 1)
#define I2C_DisableModule() (I2C2CON1bits.ON = 0)
#define I2C_Start()         (I2C2CON1bits.SEN = 1)
#define I2C_Stop()          (I2C2CON1bits.PEN = 1)
#define I2C_ReStart()       (I2C2CON1bits.RSEN = 1)
#define I2C_ReceiveEnable() (I2C2CON1bits.RCEN = 1)

// Section: Driver Interface
const struct I2C_HOST_INTERFACE I2C2_Host = {
    .Initialize = I2C2_Initialize,
    .Deinitialize = I2C2_Deinitialize,
    .Write = I2C2_Write,
    .Read = I2C2_Read,
    .WriteRead = I2C2_WriteRead,
    .TransferSetup = I2C2_TransferSetup,
    .ErrorGet = I2C2_ErrorGet,
    .IsBusy = I2C2_IsBusy,
    .HostCallbackRegister = &I2C2_CallbackRegister,
    .Tasks = NULL
};

// Section: Private Variable Definitions
static volatile struct I2C_OBJECT i2cObj;

static void (*I2C2_HostHandler)(void) = NULL;

// Section: File specific functions
static void I2C2_AddressConfiguration(uint16_t address, bool writeMode);
static inline void I2C2_WriteCollisionStatusClear(void);
static inline void I2C2_RecevieOverFlowStatusClear(void);
static inline void I2C2_BusCollisionStatusClear(void);
static inline void I2C2_HostDataProcess(void);
static inline void I2C2_CommonInterruptEnable(void);

// Section: Driver Interface Function Definitions
void I2C2_Initialize(void)
{
    // initialize the hardware
    // SEN disabled; RSEN disabled; PEN disabled; RCEN disabled; ACKEN disabled; ACKDT Sends ACK; STREN disabled; GCEN disabled; DISSLW disabled; A10M 7 Bit; STRICT disabled; SCLREL Releases; SIDL Continues; ON enabled; DHEN disabled; AHEN disabled; SBCDE disabled; SDAHT 100 ns; BOEN disabled; SCIE disabled; PCIE disabled; SMBEN I2C input threshold voltage;
    I2C2CON1 = 0x9000UL;
    // S disabled; P disabled; I2COV disabled; IWCOL disabled; BCL disabled;
    I2C2STAT1 = 0x0UL;
    // I2CADD 0x0;
    I2C2ADD = 0x0UL;
    // I2CMSK 0x0;
    I2C2MSK = 0x0UL;
    // RXIE disabled; HACKSIE enabled; CLTIE disabled; HSTIE enabled; BCLIE disabled; CRCIE disabled; NACKIE disabled; FRMEIE disabled; BITIE disabled; CBCTIE disabled; HBCTIE disabled; BSCLTIE disabled; EOPIE disabled; HBCLIE enabled; HSCIE enabled; HPCIE enabled; HDRXIE enabled; HDTXIE enabled; CDTXIE disabled; CDRXIE disabled; TXIE disabled; CADDRIE disabled; HSBCLIE disabled; CBCLIE disabled; I2CEIE disabled;
    I2C2INTC = 0x1C002803UL;
    // I2CHBRG 27;
    I2C2HBRG = 0x1AUL; // 1B
    // I2CLBRG 27;
    I2C2LBRG = 0x1AUL; // 1B

    // I2C2 Host Callback initialize
    I2C2_CallbackRegister(&I2C2_Callback);

    i2cObj.state = I2C_HOST_IDLE;
    i2cObj.error = I2C_HOST_ERROR_NONE;

    // I2C2 Interrupt initialize
    I2C2_CommonInterruptEnable();
}

void I2C2_Deinitialize(void)
{
    I2C_DisableModule();

    // clear the Host interrupt
    IFS2bits.I2C2IF = 0;
    IEC2bits.I2C2IE = 0;

    I2C2CON1 = 0x1000UL;
    I2C2STAT1 = 0x0UL;
    I2C2ADD = 0x0UL;
    I2C2MSK = 0x0UL;
    I2C2INTC = 0x0UL;
    I2C2HBRG = 0x0UL;
    I2C2LBRG = 0x0UL;
}

bool I2C2_Write(uint16_t address, uint8_t *data, size_t dataLength)
{
    bool status = true;


     // Validate the Host should not busy, Should not NULL data pointer,
     // Should not data size is less than 1 and Should not more than 10 bit
     // address size.

    if((i2cObj.state == I2C_HOST_IDLE) && ((data != NULL) && (dataLength > (size_t)0))
            && (address <= (size_t)I2C_10_BIT_ADDRESS_SIZE))
    {
        I2C2_AddressConfiguration(address, true);
        i2cObj.writeData = data;
        i2cObj.writeDataCount = dataLength;
        i2cObj.readData = NULL;
        i2cObj.readDataCount = 0;
        I2C2_WriteCollisionStatusClear();
        I2C2_BusCollisionStatusClear();

        // Enable Host interrupt to start the transmit sequence
        IFS2bits.I2C2IF = 1;
    }
    else
    {
        status = false;
    }

    return status;
}

bool I2C2_Read(uint16_t address, uint8_t *data, size_t dataLength)
{
    bool status = true;


    // Validate the Host should not busy, Should not NULL data pointer,
    // Should not data size is less than 1 and Should not more than 10 bit
    // address size.

    if((i2cObj.state == I2C_HOST_IDLE) && ((data != NULL) && (dataLength > (size_t)0))
            && (address <= (size_t)I2C_10_BIT_ADDRESS_SIZE))
    {
        I2C2_AddressConfiguration(address, false);
        i2cObj.readData = data;
        i2cObj.readDataCount = dataLength;
        i2cObj.writeData = NULL;
        i2cObj.writeDataCount = 0;
        I2C2_WriteCollisionStatusClear();
        I2C2_RecevieOverFlowStatusClear();
        I2C2_BusCollisionStatusClear();

        // Enable Host interrupt to start the transmit sequence
        IFS2bits.I2C2IF = 1;
    }
    else
    {
        status = false;
    }

    return status;
}

bool I2C2_WriteRead(uint16_t address, uint8_t *writeData, size_t writeLength, uint8_t *readData, size_t readLength)
{
    bool status = true;


    // Validate the Host should not busy, Should not NULL data pointer,
    // Should not data size is less than 1 and Should not more than 10 bit
    // address size.

    if((i2cObj.state == I2C_HOST_IDLE) && ((writeData != NULL) && (writeLength > (size_t)0))
            && ((readData != NULL) && (readLength > (size_t)0))
            && (address <= (size_t)I2C_10_BIT_ADDRESS_SIZE))
    {
        I2C2_AddressConfiguration(address, true);
        i2cObj.writeData = writeData;
        i2cObj.writeDataCount = writeLength;
        i2cObj.readData = readData;
        i2cObj.readDataCount = readLength;
        I2C2_WriteCollisionStatusClear();

        // Enable Host interrupt to start Transmit sequence
        IFS2bits.I2C2IF = 1;
    }
    else
    {
        status = false;
    }

    return status;
}

bool I2C2_TransferSetup(struct I2C_TRANSFER_SETUP *setup, uint32_t srcClkFreq)
{
    bool status = false;

    uint32_t peripheralClkSpeed = srcClkFreq ? srcClkFreq : I2C2_CLOCK_FREQUENCY;

    if((((uint32_t)I2C_FREQ_100KHZ <= setup->clkSpeed) && (setup->clkSpeed <= (uint32_t)I2C_FREQ_1MHZ))
            && (setup != NULL))
    {

        // I2CxBRG = (((1/(2*FSCL)) - Delay) x Fi2C) - 3

        // Delay: 200ns
        // FSCL:  setup->clkSpeed
        // FCY:   peripheralClkSpeed
        float clkSpeed_f = (float)setup->clkSpeed;
        float peripheralClkSpeed_f = (float)peripheralClkSpeed;
        float brgVal_f = (((1.0f / (2.0f * clkSpeed_f)) - 0.0000002f) * peripheralClkSpeed_f) - 0.000000200f;
        uint32_t brgVal = (brgVal_f > 0.0f) ? (uint32_t)(brgVal_f) : 0U;

        // I2CxBRG value cannot be from 0 to 3 or more than the size of the baud rate register
        if((brgVal >= (uint16_t)4) && (brgVal <= (uint16_t)16777215))
        {
            I2C_DisableModule();
            I2C2LBRG = brgVal;
            I2C2HBRG = brgVal;

            // Enable slew rate for 400 KHZ clock speed; disable for all other speeds
            if (setup->clkSpeed == (uint32_t)I2C_FREQ_400KHZ)
            {
                I2C2CON1bits.DISSLW = 1;
            }
            else
            {
                I2C2CON1bits.DISSLW = 0;
            }

            I2C_EnableModule();
            status = true;
        }
    }

    return status;
}

enum I2C_HOST_ERROR I2C2_ErrorGet(void)
{
    enum I2C_HOST_ERROR error;

    error = i2cObj.error;
    i2cObj.error = I2C_HOST_ERROR_NONE;

    return error;
}

bool I2C2_IsBusy(void)
{
    bool status = false;

    if((I2C2CON1 & I2C_MASK_ALL_ENABLE) != 0)
    {
        status = true;
    }
    else if((i2cObj.state != I2C_HOST_IDLE) ||
            (I2C2STAT1bits.S == true) || (I2C2STAT1bits.TRSTAT == true))
    {
        status = true;
    }
    else
    {
    }

    return status;
}

void I2C2_CallbackRegister(void (*callback)(void))
{
    if(NULL != callback)
    {
        I2C2_HostHandler = callback;
    }
}

void __attribute__ ((weak)) I2C2_Callback(void)
{

}

void __attribute__ ((interrupt, no_auto_psv)) _I2C2Interrupt(void)
{
    // Interrupt flag should be clear before the start bit sequence
    IFS2bits.I2C2IF = 0;
    if(I2C2STAT1bits.BCL == 1)
    {
        // If we have a Write Collision, reset the buffer and go to the idle state
        i2cObj.writeData = NULL;
        i2cObj.readData = NULL;
        i2cObj.writeDataCount = 0;
        i2cObj.readDataCount = 0;
        i2cObj.state = I2C_HOST_IDLE;
        i2cObj.error = I2C_HOST_ERROR_BUS_COLLISION;
        I2C2STAT1bits.BCL = 0;

        if(I2C2_HostHandler != NULL)
        {
            I2C2_HostHandler();
        }
    }
    else if(I2C2STAT1bits.IWCOL == 1)
    {
        // If we have a Write Collision, reset the buffer and go to the idle state
        I2C2STAT1bits.IWCOL = 0;
        i2cObj.writeData = NULL;
        i2cObj.readData = NULL;
        i2cObj.writeDataCount = 0;
        i2cObj.readDataCount = 0;
        i2cObj.state = I2C_HOST_IDLE;
    }
    else
    {
        // I2C Host Write/Read data process operation
        I2C2_HostDataProcess();
    }
}

/**
 @ingroup  i2chostdriver
 @static   I2C Client address configuration
 @brief    Reads the I2C Client address from input and update
           to the I2C object address (7bit or 10bit).
*/
static void I2C2_AddressConfiguration(uint16_t address, bool writeMode)
{

    uint8_t writeModeStatus = writeMode ? I2C_WRITE_MODE : I2C_READ_MODE;

    if(address <= (uint16_t)I2C_7_BIT_ADDRESS_SIZE)
    {
        // 7bit Client address <7:1>(A6:A0), <0> (R, _W)
        i2cObj.clientAddressLow = (uint8_t)(((address << I2C_ADDRESS_READ_WRITE_POS) &
                (uint8_t)I2C_WRITE_READ_ADDRESS_POS_MASK) | writeModeStatus);
        i2cObj.isWriteMode = writeMode;
        i2cObj.is10BitAddressMode = false;
    }
    else
    {
        // 10bit MSB Client address <7:4>(Reserve '1'), <3>(Reserve '0'), <2:1>(A9, A8), <0> (R,_W)
        // 10bit LSB Client address <7:0>(A7:A0)

        i2cObj.clientAddressHigh = (((((address >> I2C_10_BIT_HIGHER_ADDRESS_SHIFT_POS)
                & (uint8_t)I2C_10_BIT_HIGHER_ADDRESS_MASK) & (uint8_t)I2C_WRITE_READ_ADDRESS_POS_MASK)
                | (uint8_t)I2C_10_BIT_HIGHER_RESERVED_ADDRESS) | writeModeStatus);
        i2cObj.clientAddressLow = (address & (uint16_t)I2C_10_BIT_LOWER_ADDRESS_MASK);
        i2cObj.is10BitAddressMode = true;
        i2cObj.isWriteMode = writeMode;
    }
}

/**
 @ingroup  i2chostdriver
 @static   I2C Bus write collision clear
 @brief    Clears the I2C Bus write collision
*/
static inline void I2C2_WriteCollisionStatusClear(void)
{
    if(true == I2C2STAT1bits.IWCOL)
    {
        I2C2STAT1bits.IWCOL = 0;
    }
}

/**
 @ingroup  i2chostdriver
 @static   I2C Bus receive overflow clear
 @brief    Clears the I2C Bus receive overflow
*/
static inline void I2C2_RecevieOverFlowStatusClear(void)
{
    if(true == I2C2STAT1bits.I2COV)
    {
        I2C2STAT1bits.I2COV = 0;
    }
}

/**
 @ingroup  i2chostdriver
 @static   I2C Bus Bus collision clear
 @brief    Clears the I2C Bus collision.
*/
static inline void I2C2_BusCollisionStatusClear(void)
{
    if(true == I2C2STAT1bits.BCL)
    {
        I2C2STAT1bits.BCL = 0;
    }
}

/**
 @ingroup  i2chostdriver
 @static   I2C ISR state machine
 @brief    This function is I2C ISR state machine
*/
static inline void I2C2_HostDataProcess(void)
{
    switch(i2cObj.state)
    {
        case I2C_HOST_IDLE:
        case I2C_HOST_START:
            if((i2cObj.writeDataCount > (size_t)0) || ((i2cObj.readDataCount > (size_t)0)
                    && (i2cObj.error == I2C_HOST_ERROR_NONE)))
            {
                if(true == i2cObj.is10BitAddressMode)
                {
                    i2cObj.state = I2C_HOST_SEND_10BIT_HIGHER_ADDRESS;
                }
                else
                {
                    i2cObj.state = I2C_HOST_SEND_7BIT_ADDRESS;
                }

                I2C_Start();
            }
            break;

        case I2C_HOST_SEND_10BIT_HIGHER_ADDRESS:
            // Transmit the 10 bit Higher address <A9:A8> | <0>(W/R)
            if(false == I2C2STAT1bits.TBF)
            {
                I2C2TRN = i2cObj.clientAddressHigh;
                if(true == i2cObj.isWriteMode)
                {
                    i2cObj.state = I2C_HOST_SEND_10BIT_LOWER_ADDRESS;
                }
                else
                {
                    i2cObj.state = I2C_HOST_CHECK_ADDRESS_ACK_NACK_STATUS;
                }
            }
            break;

        case I2C_HOST_SEND_10BIT_LOWER_ADDRESS:
            if(false == I2C2STAT1bits.ACKSTAT)
            {
                // Transmit the 10 bit Lower address <A7:A0>
                I2C2TRN = i2cObj.clientAddressLow;

                // Check read or write mode
                if(false == i2cObj.isWriteMode)
                {
                    // I2C Read mode
                    i2cObj.state = I2C_HOST_CHECK_ADDRESS_ACK_NACK_STATUS;
                }
                else
                {
                    // I2C Write mode
                    i2cObj.state = I2C_HOST_SEND_DATA_TO_CLIENT;
                }
            }
            else
            {

                //Host received NACK status from client and stop the Host sequence

                I2C_Stop();
                i2cObj.error = I2C_HOST_ERROR_NACK;
                i2cObj.state = I2C_HOST_STOP;
            }
            break;

        case I2C_HOST_SEND_7BIT_ADDRESS:
            // Transmit the 7 bit address <A7:A1> | <0>(W/R)
            I2C2TRN = i2cObj.clientAddressLow;

            // Check read or write mode
            if(false == i2cObj.isWriteMode)
            {
                // I2C Read mode
                i2cObj.state = I2C_HOST_CHECK_ADDRESS_ACK_NACK_STATUS;
            }
            else
            {
                // I2C Write mode
                i2cObj.state = I2C_HOST_SEND_DATA_TO_CLIENT;
            }
            break;

        case I2C_HOST_SEND_DATA_TO_CLIENT:
            // Check previous byte is ACK
            if(false == I2C2STAT1bits.ACKSTAT)
            {
                if(i2cObj.writeDataCount > (size_t)0)
                {
                    if(false == I2C2STAT1bits.TBF)
                    {
                        // Transmit data to client
                        if(NULL != i2cObj.writeData)
                        {
                            I2C2TRN = *(i2cObj.writeData);
                            i2cObj.writeData++;
                        }

                        i2cObj.writeDataCount--;
                    }
                }
                else
                {
                    // Repeated start condition for continuous read sequence
                    if(i2cObj.readDataCount > (size_t)0)
                    {
                        // Restart enable
                        I2C_ReStart();

                        if(true == i2cObj.is10BitAddressMode)
                        {
                            i2cObj.clientAddressHigh = (i2cObj.clientAddressHigh | (uint8_t)I2C_READ_MODE);
                            i2cObj.isWriteMode = false;
                            i2cObj.state = I2C_HOST_SEND_10BIT_HIGHER_ADDRESS;
                        }
                        else
                        {
                            i2cObj.clientAddressLow = (i2cObj.clientAddressLow | (uint8_t)I2C_READ_MODE);
                            i2cObj.isWriteMode = false;
                            i2cObj.state = I2C_HOST_SEND_7BIT_ADDRESS;
                        }
                    }
                    else
                    {
                        // I2C Write process completed
                        I2C_Stop();
                        i2cObj.state = I2C_HOST_STOP;
                        i2cObj.error = I2C_HOST_ERROR_NONE;
                    }
                }
            }
            else
            {

                //Host received NACK status from client and stop the Host sequence

                I2C_Stop();
                i2cObj.error = I2C_HOST_ERROR_NACK;
                i2cObj.state = I2C_HOST_STOP;
            }
            break;

        case I2C_HOST_CHECK_ADDRESS_ACK_NACK_STATUS:
            if(false == I2C2STAT1bits.ACKSTAT)
            {
               // I2C Receive mode Enable
               I2C_ReceiveEnable();
               i2cObj.state = I2C_HOST_RECEIVE_DATA_FROM_CLIENT;
            }
            else
            {

                //Host received NACK status from client and stop the Host sequence

                I2C_Stop();
                i2cObj.error = I2C_HOST_ERROR_NACK;
                i2cObj.state = I2C_HOST_STOP;
            }
            break;

        case I2C_HOST_RECEIVE_DATA_FROM_CLIENT:
            if(true == I2C2STAT1bits.RBF)
            {
                // Receive data from client
                if(NULL != i2cObj.readData)
                {
                    *(i2cObj.readData) = I2C2RCV;
                    i2cObj.readData++;
                }

                i2cObj.readDataCount--;

                if(i2cObj.readDataCount > (size_t)0)
                {
                    // Set the flag to acknowledge the data
                    I2C2CON1bits.ACKDT  = 0;
                    // Initiate the acknowledge
                    I2C2CON1bits.ACKEN = 1;
                    i2cObj.state = I2C_HOST_RECEIVE_WAIT_ACK_NACK_COMPLETE;
                }
                else
                {

                    // I2C Receive last byte, Send NACK to Client
                    // Stop the Host sequence


                    // Set the flag to acknowledge the data
                    I2C2CON1bits.ACKDT  = 1;
                    // Initiate the acknowledge
                    I2C2CON1bits.ACKEN = 1;
                    i2cObj.state = I2C_HOST_STOP;
                }
            }
            break;

        case I2C_HOST_RECEIVE_WAIT_ACK_NACK_COMPLETE:
               // I2C Receive mode Enable
               I2C_ReceiveEnable();
               i2cObj.state = I2C_HOST_RECEIVE_DATA_FROM_CLIENT;
            break;

        case I2C_HOST_STOP:
            if(((uint16_t)1 == I2C2STAT1bits.R_W) && ((uint16_t)0 == I2C2STAT1bits.P))
            {
                I2C_Stop();
            }

            if(I2C2_HostHandler != NULL)
            {
                I2C2_HostHandler();
            }

            i2cObj.state = I2C_HOST_IDLE;
            I2C_Stop(); // SJS added per examples in spec to force stop condition on last byte
            break;

        default:
            break;
    }
}

/**
 @ingroup  i2chostdriver
 @static   Enable the I2C Bus Interrupts
 @brief    Enable the I2C Bus Interrupts
*/
static inline void I2C2_CommonInterruptEnable(void)
{
    // I2C2 Host Event
    // clear the Host interrupt flag
    IFS2bits.I2C2IF = 0;
    // enable the Host interrupt
    IEC2bits.I2C2IE = 1;
}
