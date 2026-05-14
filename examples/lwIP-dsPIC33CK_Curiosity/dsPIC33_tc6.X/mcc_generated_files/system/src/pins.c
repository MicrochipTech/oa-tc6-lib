/**
 * PINS Generated Driver Source File
 *
 * @file      pins.c
 *
 * @ingroup   pinsdriver
 *
 * @brief     This is the generated driver source file for PINS driver.
 *
 * @version   Driver Version 1.0.0
 *
 * @skipline  Device : dsPIC33CK256MP508
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

// Section: Includes
#include <xc.h>
#include <stddef.h>
#include "../pins.h"

// Section: File specific functions
void (*Ext_Int_InterruptHandler)(void) = NULL;

// Section: Driver Interface Function Definitions
void PINS_Initialize(void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;
    LATC = 0x0000;
    LATD = 0x0000;
    LATE = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x001F;
    TRISB = 0xADFD;
    TRISC = 0xFFFF;
    TRISD = 0xFFAB;
    TRISE = 0x7FFF;


    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPUA = 0x0000;
    CNPUB = 0x0000;
    CNPUC = 0x0000;
    CNPUD = 0x0000;
    CNPUE = 0x0800;
    CNPDA = 0x0000;
    CNPDB = 0x0000;
    CNPDC = 0x0000;
    CNPDD = 0x0000;
    CNPDE = 0x0000;


    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;
    ODCC = 0x0000;
    ODCD = 0x0000;
    ODCE = 0x0000;


    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x001F;
    ANSELB = 0x019C;
    ANSELC = 0x00CF;
    ANSELD = 0x2C00;
    ANSELE = 0x000F;

    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
     __builtin_write_RPCON(0x0000); // unlock PPS

        RPINR20bits.SDI1R = 0x0047; //RD7->SPI1:SDI1;
        RPINR18bits.U1RXR = 0x0043; //RD3->UART1:U1RX;
        RPOR19bits.RP70R = 0x0005;  //RD6->SPI1:SDO1;
        RPOR18bits.RP68R = 0x0001;  //RD4->UART1:U1TX;
        RPINR20bits.SCK1R = 0x0048;  //RD8->SPI1:SCK1IN;
        RPOR20bits.RP72R = 0x0006;  //RD8->SPI1:SCK1OUT;
        RPOR17bits.RP66R = 0x0007; //RD2->SPI1:SS
     __builtin_write_RPCON(0x0800); // lock PPS

    /*******************************************************************************
    * Interrupt On Change: negative
    *******************************************************************************/
    CNEN1Ebits.CNEN1E11 = 1; //Pin : RE11;

    /****************************************************************************
     * Interrupt On Change: flag
     ***************************************************************************/
    CNFEbits.CNFE11 = 0;    //Pin : Ext_Int

    /****************************************************************************
     * Interrupt On Change: config
     ***************************************************************************/
    CNCONEbits.CNSTYLE = 1; //Config for PORTE
    CNCONEbits.ON = 1; //Config for PORTE

    /* Initialize IOC Interrupt Handler*/
    Ext_Int_SetInterruptHandler(&Ext_Int_CallBack);

    /****************************************************************************
     * Interrupt On Change: Interrupt Enable
     ***************************************************************************/
    IFS4bits.CNEIF = 0; //Clear CNEI interrupt flag
    IEC4bits.CNEIE = 1; //Enable CNEI interrupt
}

void __attribute__ ((weak)) Ext_Int_CallBack(void)
{

}

void Ext_Int_SetInterruptHandler(void (* InterruptHandler)(void))
{
    IEC4bits.CNEIE = 0; //Disable CNEI interrupt
    Ext_Int_InterruptHandler = InterruptHandler;
    IEC4bits.CNEIE = 1; //Enable CNEI interrupt
}

void Ext_Int_SetIOCInterruptHandler(void *handler)
{
    Ext_Int_SetInterruptHandler(handler);
}

/* Interrupt service function for the CNEI interrupt. */
void __attribute__ (( interrupt, no_auto_psv )) _CNEInterrupt (void)
{
    if(CNFEbits.CNFE11 == 1)
    {
        if(Ext_Int_InterruptHandler)
        {
            Ext_Int_InterruptHandler();
        }

        CNFEbits.CNFE11 = 0;  //Clear flag for Pin - Ext_Int
    }

    // Clear the flag
    IFS4bits.CNEIF = 0;
}

