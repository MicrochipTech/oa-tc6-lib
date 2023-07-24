/**
  DMA2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    dma2.c

  @Summary
    This is the generated driver implementation file for the DMA2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for DMA2.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F57Q43
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "dma2.h"

void (*DMA2_DCNTI_InterruptHandler)(void);

/**
  Section: DMA2 APIs
*/

void DMA2_Initialize(void)
{
    //DMA Instance Selection : 0x01
    DMASELECT = 0x01;
    //Source Address : &SPI1RXB
    DMAnSSA = (volatile __uint24)&SPI1RXB;
    //Destination Address : &DstVarName1
    DMAnDSA= 0;
    //DMODE incremented; DSTP not cleared; SMR SFR; SMODE unchanged; SSTP not cleared; 
    DMAnCON1 = 0x40;
    //Source Message Size : 1
    DMAnSSZ = 1;
    //Destination Message Size : 1
    DMAnDSZ = 1;
    //Start Trigger : SIRQ None; 
    DMAnSIRQ = 0x18;
    //Abort Trigger : AIRQ None; 
    DMAnAIRQ = 0x00;
	
    // Clear Destination Count Interrupt Flag bit
    PIR6bits.DMA2DCNTIF = 0; 
    // Clear Source Count Interrupt Flag bit
    PIR6bits.DMA2SCNTIF = 0; 
    // Clear Abort Interrupt Flag bit
    PIR6bits.DMA2AIF = 0; 
    // Clear Overrun Interrupt Flag bit
    PIR6bits.DMA2ORIF =0; 
    
    PIE6bits.DMA2DCNTIE = 0;
    PIE6bits.DMA2SCNTIE = 0;
    PIE6bits.DMA2AIE = 0;
    PIE6bits.DMA2ORIE = 0;
	
    //EN enabled; SIRQEN disabled; DGO not in progress; AIRQEN disabled; 
    DMAnCON0 = 0x80;
	
}

void DMA2_SelectSourceRegion(uint8_t region)
{
    DMASELECT = 0x01;
	DMAnCON1bits.SMR  = region;
}

void DMA2_SetSourceAddress(uint24_t address)
{
    DMASELECT = 0x01;
	DMAnSSA = address;
}

void DMA2_SetDestinationAddress(uint16_t address)
{
    DMASELECT = 0x01;
	DMAnDSA = address;
}

void DMA2_SetSourceSize(uint16_t size)
{
    DMASELECT = 0x01;
	DMAnSSZ= size;
}

void DMA2_SetDestinationSize(uint16_t size)
{                     
    DMASELECT = 0x01;
	DMAnDSZ= size;
}

uint24_t DMA2_GetSourcePointer(void)
{
    DMASELECT = 0x01;
	return DMAnSPTR;
}

uint16_t DMA2_GetDestinationPointer(void)
{
    DMASELECT = 0x01;
	return DMAnDPTR;
}

void DMA2_SetStartTrigger(uint8_t sirq)
{
    DMASELECT = 0x01;
	DMAnSIRQ = sirq;
}

void DMA2_SetAbortTrigger(uint8_t airq)
{
    DMASELECT = 0x01;
	DMAnAIRQ = airq;
}

void DMA2_StartTransfer(void)
{
    DMASELECT = 0x01;
	DMAnCON0bits.DGO = 1;
}

void DMA2_StartTransferWithTrigger(void)
{
    DMASELECT = 0x01;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA2_StopTransfer(void)
{
    DMASELECT = 0x01;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA2_SetDMAPriority(uint8_t priority)
{
    // This function is dependant on the PR1WAY CONFIG bit
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA2PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
}

void DMA2_DMADCNTI_ISR(void)
{
    // Clear the source count interrupt flag
    PIR6bits.DMA2DCNTIF = 0;

    if (DMA2_DCNTI_InterruptHandler)
            DMA2_DCNTI_InterruptHandler();
}

void DMA2_SetDCNTIInterruptHandler(void (* InterruptHandler)(void))
{
	 DMA2_DCNTI_InterruptHandler = InterruptHandler;
}

void DMA2_DefaultInterruptHandler(void){
    // add your DMA2 interrupt custom code
    // or set custom function using DMA2_SetSCNTIInterruptHandler() /DMA2_SetDCNTIInterruptHandler() /DMA2_SetAIInterruptHandler() /DMA2_SetORIInterruptHandler()
}
/**
 End of File
*/
