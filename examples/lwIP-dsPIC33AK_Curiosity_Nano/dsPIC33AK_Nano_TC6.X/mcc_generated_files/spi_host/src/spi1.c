/**
 * SPI1 Generated Driver Source File
 *
 * @file        spi1.c
 *
 * @ingroup     spihostdriver
 *
 * @brief       This is the generated driver source file for SPI1 driver.
 *
 * @skipline @version     PLIB Version 1.0.1
 *
 * @skipline    Device : dsPIC33AK512MPS506
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

// Section: Included Files
#include <xc.h>
#include "../spi1.h"

// Section: File specific data type definitions

/**
 @ingroup spidriver
  @brief Dummy data to be sent for half duplex communication.
*/
#define SPI1_DUMMY_DATA 0x0

//Defines an object for SPI_HOST_INTERFACE.

const struct SPI_HOST_INTERFACE SPI1 = {
    .Initialize         = &SPI1_Initialize,
    .Deinitialize       = &SPI1_Deinitialize,
    .Close              = &SPI1_Close,
    .Open               = &SPI1_Open,
    .BufferExchange     = &SPI1_BufferExchange,
    .BufferRead         = &SPI1_BufferRead,
    .BufferWrite        = &SPI1_BufferWrite,
    .ByteExchange       = &SPI1_ByteExchange,
    .ByteRead           = &SPI1_ByteRead,
    .ByteWrite          = &SPI1_ByteWrite,
    .IsRxReady          = &SPI1_IsRxReady,
    .IsTxReady          = &SPI1_IsTxReady,
};


/**
 @ingroup spihostdriver
 @struct SPI1_CONFIG
 @brief Defines the SPI1 configuration.
*/
struct SPI1_HOST_CONFIG
{
    uint32_t controlRegister1; //SPI1BRG
    uint32_t controlRegister2; //SPI1CON1
};

static const struct SPI1_HOST_CONFIG config[] = {
                                        {
                                            /*Configuration setting for HOST_CONFIG.
                                            SPI Mode : Mode 1, Sampled at : Middle, Clock Frequency : 16666.667 kHz
                                            Enable MSSEN*/
                                            0x2,//SPI1BRG
                                            0x00100320,//SPI1CON1
                                        }
                                    };

// Section: Driver Interface Function Definitions

void SPI1_Initialize (void)
{
    // WLENGTH 0x0;
    SPI1CON2 = 0x0;
    // SPIRBF disabled; SPITBF disabled; SPITBE enabled; SPIRBE enabled; SPIROV disabled; SRMT disabled; SPITUR disabled; SPIBUSY disabled; FRMERR disabled; TXELM disabled; RXELM disabled;
    SPI1STAT = 0x28;
    // SPIBUF 0x0;
    SPI1BUF = 0x0;
    // SPIBRG 0x0;
    SPI1BRG = 0x0;
    // SPIURDT 0x0;
    SPI1URDT = 0x0;
    // ENHBUF enabled; SPIFE Frame Sync pulse precedes; MCLKEN Standard Speed Peripheral Clock; DISSCK disabled; DISSDI disabled; MSTEN Host; CKP Idle:Low, Active:High; SSEN disabled; CKE Idle to Active; SMP Middle; MODE16 disabled; MODE32 disabled; DISSDO disabled; SIDL disabled; ON disabled; FRMCNT 0x0; FRMSYPW One clock wide; MSSEN disabled; FRMPOL disabled; FRMSYNC disabled; FRMEN disabled; AUDMOD I2S; URDTEN disabled; AUDMONO stereo; IGNTUR disabled; IGNROV disabled; SPISGNEXT not sign-extended; AUDEN disabled;
    SPI1CON1 = 0x00100321;
}

void SPI1_Deinitialize (void)
{
    SPI1_Close();

    SPI1CON1 = 0x0;
    SPI1CON2 = 0x0;
    SPI1STAT = 0x28;
    SPI1BUF = 0x0;
    SPI1BRG = 0x0;
    SPI1URDT = 0x0;
}

void SPI1_Close(void)
{
    SPI1CON1bits.ON = 0U;
}

bool SPI1_Open(uint8_t spiConfigIndex)
{
    bool status = false;
    if(!SPI1CON1bits.ON)
    {
        SPI1BRG = config[spiConfigIndex].controlRegister1;
        SPI1CON1 = config[spiConfigIndex].controlRegister2;
        SPI1CON1bits.ON = 1U;

        status = true;
    }
    return status;
}

uint8_t SPI1_ByteExchange(uint8_t byteData)
{
    while(1U == SPI1STATbits.SPITBF)
    {

    }

    SPI1BUF = byteData;

    while (1U == SPI1STATbits.SPIRBE)
    {

    }

    return (uint8_t)SPI1BUF;
}

void SPI1_BufferExchange(void *bufferData, size_t bufferSize)
{
    uint8_t *data = bufferData;
    uint16_t dataSentCount = 0U;
    uint16_t dataReceivedCount = 0U;

    while(1U == SPI1STATbits.SPITBF)
    {

    }

    while (dataSentCount < bufferSize)
    {
        if ( 1U != SPI1STATbits.SPITBF )
        {
            SPI1BUF = data[dataSentCount];
            dataSentCount++;
        }

        if (0U == SPI1STATbits.SPIRBE)
        {
            data[dataReceivedCount] = SPI1BUF;
            dataReceivedCount++;
        }
    }
    while (dataReceivedCount < bufferSize)
    {
        if (0U == SPI1STATbits.SPIRBE)
        {
            data[dataReceivedCount] = SPI1BUF;
            dataReceivedCount++;
        }
    }
}

void SPI1_BufferWrite(void *bufferData, size_t bufferSize)
{
    uint8_t *data = bufferData;
    uint8_t  __attribute__ ((unused))rData;
    uint16_t dataSentCount = 0U;
    uint16_t dataReceivedCount = 0U;

    while(1U == SPI1STATbits.SPITBF)
    {

    }

    while (dataSentCount < bufferSize)
    {
        if ( 1U != SPI1STATbits.SPITBF )
        {
            SPI1BUF = data[dataSentCount];
            dataSentCount++;
        }

        if (0U == SPI1STATbits.SPIRBE)
        {
            rData = SPI1BUF; //Dummy Read
            dataReceivedCount++;
        }

    }
    while (dataReceivedCount < bufferSize)
    {
        if (0U == SPI1STATbits.SPIRBE)
        {
            rData = SPI1BUF; //Dummy Read
            dataReceivedCount++;
        }
    }
}

void SPI1_BufferRead(void *bufferData, size_t bufferSize)
{
    uint8_t *data = bufferData;
    const uint8_t wData = SPI1_DUMMY_DATA;
    uint16_t dataSentCount = 0U;
    uint16_t dataReceivedCount = 0U;

    while(1U == SPI1STATbits.SPITBF)
    {

    }

    while (dataSentCount < bufferSize)
    {
        if ( 1U != SPI1STATbits.SPITBF )
        {
            SPI1BUF = wData;
            dataSentCount++;
        }

        if (0U == SPI1STATbits.SPIRBE)
        {
            data[dataReceivedCount] = SPI1BUF;
            dataReceivedCount++;
        }
    }
    while (dataReceivedCount < bufferSize)
    {
        if (0U == SPI1STATbits.SPIRBE)
        {
            data[dataReceivedCount] = SPI1BUF;
            dataReceivedCount++;
        }
    }
}

void SPI1_ByteWrite(uint8_t byteData)
{
    while(1U == SPI1STATbits.SPITBF)
    {

    }

    SPI1BUF = byteData;
}

uint8_t SPI1_ByteRead(void)
{
    while (1U == SPI1STATbits.SPIRBE)
    {

    }

    return (uint8_t)SPI1BUF;
}

bool SPI1_IsRxReady(void)
{
    return (!SPI1STATbits.SPIRBE);
}

bool SPI1_IsTxReady(void)
{
    return (!SPI1STATbits.SPITBF);
}

