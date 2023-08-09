
/**
 * SPI1 Generated Driver Source File
 *
 * @file        spi1.c
 *
 * @ingroup     spihostdriver
 *
 * @brief       This is the generated driver source file for SPI1 driver.
 *
 * @version     Driver Version 1.1.0
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
#include <xc.h>
#include "../spi1.h"

// Section: File specific data type definitions

/**
 @ingroup spidriver
  @brief Dummy data to be sent for half duplex communication.
*/
#define SPI1_DUMMY_DATA 0x0

//Defines an object for SPI_HOST_INTERFACE.

const struct SPI_HOST_INTERFACE SPI1_Host = {
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
    uint16_t controlRegister1; //SPI1BRGL
    uint16_t controlRegister2; //SPI1CON1L
};

static const struct SPI1_HOST_CONFIG config[] = {
                                        {
                                            /*Configuration setting for HOST_CONFIG.
                                            SPI Mode : Mode 1, Sampled at : Middle, Clock Frequency : 16000 kHz*/
                                            0x3,//SPI1BRGL
                                            0x120,//SPI1CON1L
                                        },
                                    };

// Section: Driver Interface Function Definitions

void SPI1_Initialize (void)
{
    // SPIBRGL 0;
    SPI1BRGL = 0x0;
    // AUDEN disabled; FRMEN disabled; AUDMOD I2S; FRMSYPW One clock wide; AUDMONO stereo; FRMCNT 0x0; MSSEN disabled; FRMPOL disabled; IGNROV disabled; SPISGNEXT not sign-extended; FRMSYNC disabled; URDTEN disabled; IGNTUR disabled;
    SPI1CON1H = 0x0;
    // Master Slave select SS enable. Active low
    SPI1CON1Hbits.MSSEN = 1;

    // WLENGTH 0;
    SPI1CON2L = 0x0;
    // SPIROV disabled; FRMERR disabled;
    SPI1STATL = 0x0;
    // SPIURDTL 0;
    SPI1URDTL = 0x0;
    // SPIURDTH 0;
    SPI1URDTH = 0x0;
    // SPIEN disabled; DISSDO disabled; MCLKEN FOSC/2; CKP Idle:Low, Active:High; SSEN disabled; MSTEN Host; MODE16 disabled; SMP Middle; DISSCK disabled; SPIFE Frame Sync pulse precedes; CKE Idle to Active; MODE32 disabled; SPISIDL disabled; ENHBUF enabled; DISSDI disabled;
    SPI1CON1L = 0x20;
}

void SPI1_Deinitialize (void)
{
    SPI1_Close();

    SPI1BRGL = 0x0;
    SPI1CON1L = 0x0;
    SPI1CON1H = 0x0;
    SPI1CON2L = 0x0;
    SPI1STATL = 0x28;
    SPI1URDTL = 0x0;
    SPI1URDTH = 0x0;
}

void SPI1_Close(void)
{
    SPI1CON1Lbits.SPIEN = 0U;
}

bool SPI1_Open(uint8_t spiConfigIndex)
{
    bool status = 0U;
    if(!SPI1CON1Lbits.SPIEN)
    {
        SPI1BRGL = config[spiConfigIndex].controlRegister1;
        SPI1CON1L = config[spiConfigIndex].controlRegister2;
        SPI1CON1Lbits.SPIEN = 1U;

        status = 1U;
    }
    return status;
}

uint8_t SPI1_ByteExchange(uint8_t byteData)
{
    while(1U == SPI1STATLbits.SPITBF)
    {

    }

    SPI1BUFL = byteData;

    while (1U == SPI1STATLbits.SPIRBE)
    {

    }

    return SPI1BUFL;
}

void SPI1_BufferExchange(void *bufferData, size_t bufferSize)
{
    uint8_t *data = bufferData;
    uint16_t dataSentCount = 0U;
    uint16_t dataReceivedCount = 0U;

    while(1U == SPI1STATLbits.SPITBF)
    {

    }

    while (dataSentCount < bufferSize)
    {
        if ( 1U != SPI1STATLbits.SPITBF )
        {
            SPI1BUFL = data[dataSentCount];
            dataSentCount++;
        }

        if (0U == SPI1STATLbits.SPIRBE)
        {
            data[dataReceivedCount] = SPI1BUFL;
            dataReceivedCount++;
        }
    }
    while (dataReceivedCount < bufferSize)
    {
        if (0U == SPI1STATLbits.SPIRBE)
        {
            data[dataReceivedCount] = SPI1BUFL;
            dataReceivedCount++;
        }
    }
}

void SPI1_BufferWrite(void *bufferData, size_t bufferSize)
{
    uint8_t *data = bufferData;
    uint8_t rData;
    uint16_t dataSentCount = 0U;
    uint16_t dataReceivedCount = 0U;

    while(1U == SPI1STATLbits.SPITBF)
    {

    }

    while (dataSentCount < bufferSize)
    {
        if ( 1U != SPI1STATLbits.SPITBF )
        {
            SPI1BUFL = data[dataSentCount];
            dataSentCount++;
        }

        if (0U == SPI1STATLbits.SPIRBE)
        {
            rData = SPI1BUFL; //Dummy Read
            dataReceivedCount++;
        }

    }
    while (dataReceivedCount < bufferSize)
    {
        if (0U == SPI1STATLbits.SPIRBE)
        {
            rData = SPI1BUFL; //Dummy Read
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

    while(1U == SPI1STATLbits.SPITBF)
    {

    }

    while (dataSentCount < bufferSize)
    {
        if ( 1U != SPI1STATLbits.SPITBF )
        {
            SPI1BUFL = wData;
            dataSentCount++;
        }

        if (0U == SPI1STATLbits.SPIRBE)
        {
            data[dataReceivedCount] = SPI1BUFL;
            dataReceivedCount++;
        }
    }
    while (dataReceivedCount < bufferSize)
    {
        if (0U == SPI1STATLbits.SPIRBE)
        {
            data[dataReceivedCount] = SPI1BUFL;
            dataReceivedCount++;
        }
    }
}

void SPI1_ByteWrite(uint8_t byteData)
{
    while(1U == SPI1STATLbits.SPITBF)
    {

    }

    SPI1BUFL = byteData;
}

uint8_t SPI1_ByteRead(void)
{
    while (1U == SPI1STATLbits.SPIRBE)
    {

    }

    return SPI1BUFL;
}

bool SPI1_IsRxReady(void)
{
    return (!SPI1STATLbits.SPIRBE);
}

bool SPI1_IsTxReady(void)
{
    return (!SPI1STATLbits.SPITBF);
}

