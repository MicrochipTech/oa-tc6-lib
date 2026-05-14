/**
 * DMA Generated Driver Source File
 *
 * @file      dma.c
 *
 * @ingroup   dmadriver
 *
 * @brief     This is the generated driver source file for DMA driver
 *
 * @skipline @version   PLIB Version 1.0.1
 *
 * @skipline  Device : dsPIC33AK512MPS506
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

#include <stddef.h>
#include "../dma.h"

// Section: File specific functions

static void (*DMA_Channel0Handler)(enum DMA_EVENT event) = NULL;
static void (*DMA_Channel1Handler)(enum DMA_EVENT event) = NULL;
static void (*DMA_Channel2Handler)(enum DMA_EVENT event) = NULL;
static void (*DMA_Channel3Handler)(enum DMA_EVENT event) = NULL;
static void (*DMA_Channel4Handler)(enum DMA_EVENT event) = NULL;
static void (*DMA_Channel5Handler)(enum DMA_EVENT event) = NULL;
static void (*DMA_Channel6Handler)(enum DMA_EVENT event) = NULL;
static void (*DMA_Channel7Handler)(enum DMA_EVENT event) = NULL;

// Section: Driver Interface

const struct DMA_INTERFACE DMA = {
    .Initialize                 = &DMA_Initialize,
    .Deinitialize               = &DMA_Deinitialize,
    .ChannelEnable              = &DMA_ChannelEnable,
    .ChannelDisable             = &DMA_ChannelDisable,
    .TransferCountSet           = &DMA_TransferCountSet,
    .TransferCountGet           = &DMA_TransferCountGet,
    .SoftwareTriggerEnable      = &DMA_SoftwareTriggerEnable,
    .SourceAddressSet           = &DMA_SourceAddressSet,
    .DestinationAddressSet      = &DMA_DestinationAddressSet,
    .IsSoftwareRequestPending   = &DMA_IsSoftwareRequestPending,
    .ChannelCallbackRegister = &DMA_ChannelCallbackRegister,
    .ChannelTasks               = &DMA_ChannelTasks
};

// Section: Driver Interface Function Definitions

void DMA_Initialize(void)
{
    // PRIORITY Fixed priority scheme; SIDL disabled; ON enabled;
    DMACON = 0x8000UL;
    //
    DMABUF= 0x0UL;
    // LADDR 16384;
    DMALOW= 0x4000UL;
    // HADDR 81919;
    DMAHIGH= 0x13FFFUL;
    // CHEN disabled; HALFEN disabled; MATEN disabled; INTOEN disabled; CHREQ disabled; SIZE Byte; FLWCON Read from SADDR[23:0] followed by write to DADDR[23:0]; TRMODE One-Shot; DAMODE Unchanged; SAMODE Incremented; RETEN disabled; RELOADS disabled; RELOADD disabled; RELOADC disabled; PCHAEN disabled; PPEN disabled;
    DMA0CH= 0x4000UL;
    // CHEN disabled; HALFEN disabled; MATEN disabled; INTOEN disabled; CHREQ disabled; SIZE Byte; FLWCON Read from SADDR[23:0] followed by write to DADDR[23:0]; TRMODE One-Shot; DAMODE Incremented; SAMODE Unchanged; RETEN disabled; RELOADS disabled; RELOADD disabled; RELOADC disabled; PCHAEN disabled; PPEN disabled;
    DMA1CH= 0x1000UL;
    // CHEN disabled; HALFEN disabled; MATEN disabled; INTOEN disabled; CHREQ disabled; SIZE Byte; FLWCON Read from SADDR[23:0] followed by write to DADDR[23:0]; TRMODE One-Shot; DAMODE Unchanged; SAMODE Unchanged; RETEN disabled; RELOADS disabled; RELOADD disabled; RELOADC disabled; PCHAEN disabled; PPEN disabled;
    DMA2CH= 0x0UL;
    // CHEN disabled; HALFEN disabled; MATEN disabled; INTOEN disabled; CHREQ disabled; SIZE Byte; FLWCON Read from SADDR[23:0] followed by write to DADDR[23:0]; TRMODE One-Shot; DAMODE Unchanged; SAMODE Unchanged; RETEN disabled; RELOADS disabled; RELOADD disabled; RELOADC disabled; PCHAEN disabled; PPEN disabled;
    DMA3CH= 0x0UL;
    // CHEN disabled; HALFEN disabled; MATEN disabled; INTOEN disabled; CHREQ disabled; SIZE Byte; FLWCON Read from SADDR[23:0] followed by write to DADDR[23:0]; TRMODE One-Shot; DAMODE Unchanged; SAMODE Unchanged; RETEN disabled; RELOADS disabled; RELOADD disabled; RELOADC disabled; PCHAEN disabled; PPEN disabled;
    DMA4CH= 0x0UL;
    // CHEN disabled; HALFEN disabled; MATEN disabled; INTOEN disabled; CHREQ disabled; SIZE Byte; FLWCON Read from SADDR[23:0] followed by write to DADDR[23:0]; TRMODE One-Shot; DAMODE Unchanged; SAMODE Unchanged; RETEN disabled; RELOADS disabled; RELOADD disabled; RELOADC disabled; PCHAEN disabled; PPEN disabled;
    DMA5CH= 0x0UL;
    // CHSEL SPI1 TX;
    DMA0SEL= 0x7UL;
    // CHSEL SPI1 RX;
    DMA1SEL= 0x6UL;
    // CHSEL INT0;
    DMA2SEL= 0x0UL;
    // CHSEL INT0;
    DMA3SEL= 0x0UL;
    // CHSEL INT0;
    DMA4SEL= 0x0UL;
    // CHSEL INT0;
    DMA5SEL= 0x0UL;
    // MATCH disabled; OVERRUN disabled; HALF disabled; DONE disabled; DMAFLT No Fault; DMAFLT2 disabled; DMAFLT3 disabled;
    DMA0STAT= 0x0UL;
    // MATCH disabled; OVERRUN disabled; HALF disabled; DONE disabled; DMAFLT No Fault; DMAFLT2 disabled; DMAFLT3 disabled;
    DMA1STAT= 0x0UL;
    // MATCH disabled; OVERRUN disabled; HALF disabled; DONE disabled; DMAFLT No Fault; DMAFLT2 disabled; DMAFLT3 disabled;
    DMA2STAT= 0x0UL;
    // MATCH disabled; OVERRUN disabled; HALF disabled; DONE disabled; DMAFLT No Fault; DMAFLT2 disabled; DMAFLT3 disabled;
    DMA3STAT= 0x0UL;
    // MATCH disabled; OVERRUN disabled; HALF disabled; DONE disabled; DMAFLT No Fault; DMAFLT2 disabled; DMAFLT3 disabled;
    DMA4STAT= 0x0UL;
    // MATCH disabled; OVERRUN disabled; HALF disabled; DONE disabled; DMAFLT No Fault; DMAFLT2 disabled; DMAFLT3 disabled;
    DMA5STAT= 0x0UL;
    // SADDR 0;
    DMA0SRC= 0x0UL;
    // SADDR 0;
    DMA1SRC= 0x0UL;
    // SADDR 0;
    DMA2SRC= 0x0UL;
    // SADDR 0;
    DMA3SRC= 0x0UL;
    // SADDR 0;
    DMA4SRC= 0x0UL;
    // SADDR 0;
    DMA5SRC= 0x0UL;
    // DADDR 0;
    DMA0DST= 0x0UL;
    // DADDR 0;
    DMA1DST= 0x0UL;
    // DADDR 0;
    DMA2DST= 0x0UL;
    // DADDR 0;
    DMA3DST= 0x0UL;
    // DADDR 0;
    DMA4DST= 0x0UL;
    // DADDR 0;
    DMA5DST= 0x0UL;
    // CNT 0;
    DMA0CNT= 0x0UL;
    // CNT 0;
    DMA1CNT= 0x0UL;
    // CNT 0;
    DMA2CNT= 0x0UL;
    // CNT 0;
    DMA3CNT= 0x0UL;
    // CNT 0;
    DMA4CNT= 0x0UL;
    // CNT 0;
    DMA5CNT= 0x0UL;
    // CLR 0x0;
    DMA0CLR= 0x0UL;
    // CLR 0x0;
    DMA1CLR= 0x0UL;
    // CLR 0x0;
    DMA2CLR= 0x0UL;
    // CLR 0x0;
    DMA3CLR= 0x0UL;
    // CLR 0x0;
    DMA4CLR= 0x0UL;
    // CLR 0x0;
    DMA5CLR= 0x0UL;
    // SET 0x0;
    DMA0SET= 0x0UL;
    // SET 0x0;
    DMA1SET= 0x0UL;
    // SET 0x0;
    DMA2SET= 0x0UL;
    // SET 0x0;
    DMA3SET= 0x0UL;
    // SET 0x0;
    DMA4SET= 0x0UL;
    // SET 0x0;
    DMA5SET= 0x0UL;
    // INV 0x0;
    DMA0INV= 0x0UL;
    // INV 0x0;
    DMA1INV= 0x0UL;
    // INV 0x0;
    DMA2INV= 0x0UL;
    // INV 0x0;
    DMA3INV= 0x0UL;
    // INV 0x0;
    DMA4INV= 0x0UL;
    // INV 0x0;
    DMA5INV= 0x0UL;
    // MSK 0x0;
    DMA0MSK= 0x0UL;
    // MSK 0x0;
    DMA1MSK= 0x0UL;
    // MSK 0x0;
    DMA2MSK= 0x0UL;
    // MSK 0x0;
    DMA3MSK= 0x0UL;
    // MSK 0x0;
    DMA4MSK= 0x0UL;
    // MSK 0x0;
    DMA5MSK= 0x0UL;
    // PAT 0x0;
    DMA0PAT= 0x0UL;
    // PAT 0x0;
    DMA1PAT= 0x0UL;
    // PAT 0x0;
    DMA2PAT= 0x0UL;
    // PAT 0x0;
    DMA3PAT= 0x0UL;
    // PAT 0x0;
    DMA4PAT= 0x0UL;
    // PAT 0x0;
    DMA5PAT= 0x0UL;

    // Clearing Channel 0 Interrupt Flag;
    IFS2bits.DMA0IF = 0;
    // Enabling Channel 0 Interrupt
    IEC2bits.DMA0IE = 1;

    // Clearing Channel 1 Interrupt Flag;
    IFS2bits.DMA1IF = 0;
    // Enabling Channel 1 Interrupt
    IEC2bits.DMA1IE = 1;

    // Clearing Channel 2 Interrupt Flag;
    IFS2bits.DMA2IF = 0;

    // Clearing Channel 3 Interrupt Flag;
    IFS2bits.DMA3IF = 0;

    // Clearing Channel 4 Interrupt Flag;
    IFS3bits.DMA4IF = 0;

    // Clearing Channel 5 Interrupt Flag;
    IFS3bits.DMA5IF = 0;

    // Clearing Channel 6 Interrupt Flag;
    IFS3bits.DMA6IF = 0;

    // Clearing Channel 7 Interrupt Flag;
    IFS3bits.DMA7IF = 0;

    DMA_ChannelCallbackRegister(DMA_CHANNEL_0, &DMA_Channel0Callback);
    DMA_ChannelCallbackRegister(DMA_CHANNEL_1, &DMA_Channel1Callback);
    DMA_ChannelCallbackRegister(DMA_CHANNEL_2, &DMA_Channel2Callback);
    DMA_ChannelCallbackRegister(DMA_CHANNEL_3, &DMA_Channel3Callback);
    DMA_ChannelCallbackRegister(DMA_CHANNEL_4, &DMA_Channel4Callback);
    DMA_ChannelCallbackRegister(DMA_CHANNEL_5, &DMA_Channel5Callback);
    DMA_ChannelCallbackRegister(DMA_CHANNEL_6, &DMA_Channel6Callback);
    DMA_ChannelCallbackRegister(DMA_CHANNEL_7, &DMA_Channel7Callback);

}

void DMA_Deinitialize(void)
{
    DMACONbits.ON = 0;

    DMA0CHbits.CHEN = 0;
    DMA1CHbits.CHEN = 0;
    DMA2CHbits.CHEN = 0;
    DMA3CHbits.CHEN = 0;
    DMA4CHbits.CHEN = 0;
    DMA5CHbits.CHEN = 0;
    DMA6CHbits.CHEN = 0;
    DMA7CHbits.CHEN = 0;

    DMACON = 0x0UL;
    DMABUF = 0x0UL;
    DMALOW = 0x0UL;
    DMAHIGH = 0x0UL;
    DMA0CH = 0x0UL;
    DMA1CH = 0x0UL;
    DMA2CH = 0x0UL;
    DMA3CH = 0x0UL;
    DMA4CH = 0x0UL;
    DMA5CH = 0x0UL;
    DMA0SEL = 0x0UL;
    DMA1SEL = 0x0UL;
    DMA2SEL = 0x0UL;
    DMA3SEL = 0x0UL;
    DMA4SEL = 0x0UL;
    DMA5SEL = 0x0UL;
    DMA0STAT = 0x0UL;
    DMA1STAT = 0x0UL;
    DMA2STAT = 0x0UL;
    DMA3STAT = 0x0UL;
    DMA4STAT = 0x0UL;
    DMA5STAT = 0x0UL;
    DMA0SRC = 0x0UL;
    DMA1SRC = 0x0UL;
    DMA2SRC = 0x0UL;
    DMA3SRC = 0x0UL;
    DMA4SRC = 0x0UL;
    DMA5SRC = 0x0UL;
    DMA0DST = 0x0UL;
    DMA1DST = 0x0UL;
    DMA2DST = 0x0UL;
    DMA3DST = 0x0UL;
    DMA4DST = 0x0UL;
    DMA5DST = 0x0UL;
    DMA0CNT = 0x1UL;
    DMA1CNT = 0x1UL;
    DMA2CNT = 0x1UL;
    DMA3CNT = 0x1UL;
    DMA4CNT = 0x1UL;
    DMA5CNT = 0x1UL;
    DMA0CLR = 0x0UL;
    DMA1CLR = 0x0UL;
    DMA2CLR = 0x0UL;
    DMA3CLR = 0x0UL;
    DMA4CLR = 0x0UL;
    DMA5CLR = 0x0UL;
    DMA0SET = 0x0UL;
    DMA1SET = 0x0UL;
    DMA2SET = 0x0UL;
    DMA3SET = 0x0UL;
    DMA4SET = 0x0UL;
    DMA5SET = 0x0UL;
    DMA0INV = 0x0UL;
    DMA1INV = 0x0UL;
    DMA2INV = 0x0UL;
    DMA3INV = 0x0UL;
    DMA4INV = 0x0UL;
    DMA5INV = 0x0UL;
    DMA0MSK = 0x0UL;
    DMA1MSK = 0x0UL;
    DMA2MSK = 0x0UL;
    DMA3MSK = 0x0UL;
    DMA4MSK = 0x0UL;
    DMA5MSK = 0x0UL;
    DMA0PAT = 0x0UL;
    DMA1PAT = 0x0UL;
    DMA2PAT = 0x0UL;
    DMA3PAT = 0x0UL;
    DMA4PAT = 0x0UL;
    DMA5PAT = 0x0UL;

    IFS2bits.DMA0IF = 0;
    IEC2bits.DMA0IE = 0;
    IFS2bits.DMA1IF = 0;
    IEC2bits.DMA1IE = 0;
    IFS2bits.DMA2IF = 0;
    IFS2bits.DMA3IF = 0;
    IFS3bits.DMA4IF = 0;
    IFS3bits.DMA5IF = 0;
    IFS3bits.DMA6IF = 0;
    IFS3bits.DMA7IF = 0;
}

void DMA_ChannelCallbackRegister(enum DMA_CHANNEL channel, void(*callback)(enum DMA_EVENT event))
{
    switch(channel)
	{
        case DMA_CHANNEL_0:
                if(NULL != callback)
                {
                    DMA_Channel0Handler = callback;
                }
                break;
        case DMA_CHANNEL_1:
                if(NULL != callback)
                {
                    DMA_Channel1Handler = callback;
                }
                break;
        case DMA_CHANNEL_2:
                if(NULL != callback)
                {
                    DMA_Channel2Handler = callback;
                }
                break;
        case DMA_CHANNEL_3:
                if(NULL != callback)
                {
                    DMA_Channel3Handler = callback;
                }
                break;
        case DMA_CHANNEL_4:
                if(NULL != callback)
                {
                    DMA_Channel4Handler = callback;
                }
                break;
        case DMA_CHANNEL_5:
                if(NULL != callback)
                {
                    DMA_Channel5Handler = callback;
                }
                break;
        case DMA_CHANNEL_6:
                if(NULL != callback)
                {
                    DMA_Channel6Handler = callback;
                }
                break;
        case DMA_CHANNEL_7:
                if(NULL != callback)
                {
                    DMA_Channel7Handler = callback;
                }
                break;
        default:
				break;
    }
}

void __attribute__ ((weak)) DMA_Channel0Callback(enum DMA_EVENT event)
{
    (void)event;
}

void __attribute__ ((weak)) DMA_Channel1Callback(enum DMA_EVENT event)
{
    (void)event;
}

void __attribute__ ((weak)) DMA_Channel2Callback(enum DMA_EVENT event)
{
    (void)event;
}

void __attribute__ ((weak)) DMA_Channel3Callback(enum DMA_EVENT event)
{
    (void)event;
}

void __attribute__ ((weak)) DMA_Channel4Callback(enum DMA_EVENT event)
{
    (void)event;
}

void __attribute__ ((weak)) DMA_Channel5Callback(enum DMA_EVENT event)
{
    (void)event;
}

void __attribute__ ((weak)) DMA_Channel6Callback(enum DMA_EVENT event)
{
    (void)event;
}

void __attribute__ ((weak)) DMA_Channel7Callback(enum DMA_EVENT event)
{
    (void)event;
}

void __attribute__ ( ( interrupt, no_auto_psv ) ) _DMA0Interrupt(void)
{
    if(NULL != DMA_Channel0Handler)
    {
        if(DMA0STATbits.OVERRUN == 1)
        {
            (*DMA_Channel0Handler)(DMA_OVERRUN);
            DMA0STATbits.OVERRUN = 0;
        }
        if(DMA0STATbits.DONE == 1)
        {
            (*DMA_Channel0Handler)(DMA_TRANSFER_DONE);
            DMA0STATbits.DONE = 0U;
        }
    }

    IFS2bits.DMA0IF = 0;
}
void __attribute__ ( ( interrupt, no_auto_psv ) ) _DMA1Interrupt(void)
{
    if(NULL != DMA_Channel1Handler)
    {
        if(DMA1STATbits.OVERRUN == 1)
        {
            (*DMA_Channel1Handler)(DMA_OVERRUN);
            DMA1STATbits.OVERRUN = 0;
        }
        if(DMA1STATbits.DONE == 1)
        {
            (*DMA_Channel1Handler)(DMA_TRANSFER_DONE);
            DMA1STATbits.DONE = 0U;
        }
    }

    IFS2bits.DMA1IF = 0;
}

void DMA_ChannelTasks(void)
{
	if(IFS2bits.DMA2IF == 1)
	{
        if(NULL != DMA_Channel2Handler)
        {
		    if(DMA2STATbits.OVERRUN == 1)
            {
                (*DMA_Channel2Handler)(DMA_OVERRUN);
                DMA2STATbits.OVERRUN = 0;
            }
            if(DMA2STATbits.DONE == 1)
            {
                (*DMA_Channel2Handler)(DMA_TRANSFER_DONE);
                DMA2STATbits.DONE = 0U;
            }
        }

		IFS2bits.DMA2IF = 0;
	}
	if(IFS2bits.DMA3IF == 1)
	{
        if(NULL != DMA_Channel3Handler)
        {
		    if(DMA3STATbits.OVERRUN == 1)
            {
                (*DMA_Channel3Handler)(DMA_OVERRUN);
                DMA3STATbits.OVERRUN = 0;
            }
            if(DMA3STATbits.DONE == 1)
            {
                (*DMA_Channel3Handler)(DMA_TRANSFER_DONE);
                DMA3STATbits.DONE = 0U;
            }
        }

		IFS2bits.DMA3IF = 0;
	}
	if(IFS3bits.DMA4IF == 1)
	{
        if(NULL != DMA_Channel4Handler)
        {
		    if(DMA4STATbits.OVERRUN == 1)
            {
                (*DMA_Channel4Handler)(DMA_OVERRUN);
                DMA4STATbits.OVERRUN = 0;
            }
            if(DMA4STATbits.DONE == 1)
            {
                (*DMA_Channel4Handler)(DMA_TRANSFER_DONE);
                DMA4STATbits.DONE = 0U;
            }
        }

		IFS3bits.DMA4IF = 0;
	}
	if(IFS3bits.DMA5IF == 1)
	{
        if(NULL != DMA_Channel5Handler)
        {
		    if(DMA5STATbits.OVERRUN == 1)
            {
                (*DMA_Channel5Handler)(DMA_OVERRUN);
                DMA5STATbits.OVERRUN = 0;
            }
            if(DMA5STATbits.DONE == 1)
            {
                (*DMA_Channel5Handler)(DMA_TRANSFER_DONE);
                DMA5STATbits.DONE = 0U;
            }
        }

		IFS3bits.DMA5IF = 0;
	}
	if(IFS3bits.DMA6IF == 1)
	{
        if(NULL != DMA_Channel6Handler)
        {
		    if(DMA6STATbits.OVERRUN == 1)
            {
                (*DMA_Channel6Handler)(DMA_OVERRUN);
                DMA6STATbits.OVERRUN = 0;
            }
            if(DMA6STATbits.DONE == 1)
            {
                (*DMA_Channel6Handler)(DMA_TRANSFER_DONE);
                DMA6STATbits.DONE = 0U;
            }
        }

		IFS3bits.DMA6IF = 0;
	}
	if(IFS3bits.DMA7IF == 1)
	{
        if(NULL != DMA_Channel7Handler)
        {
		    if(DMA7STATbits.OVERRUN == 1)
            {
                (*DMA_Channel7Handler)(DMA_OVERRUN);
                DMA7STATbits.OVERRUN = 0;
            }
            if(DMA7STATbits.DONE == 1)
            {
                (*DMA_Channel7Handler)(DMA_TRANSFER_DONE);
                DMA7STATbits.DONE = 0U;
            }
        }

		IFS3bits.DMA7IF = 0;
	}

}
