/**
 * PINS Generated Driver Source File
 *
 * @file      pins.c
 *
 * @ingroup   pinsdriver
 *
 * @brief     This is the generated driver source file for PINS driver.
 *
 * @skipline @version   PLIB Version 1.0.4
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

// Section: Includes
#include <xc.h>
#include <stddef.h>
#include "../pins.h"

// Section: File specific functions
static void (*Ext_Int_InterruptHandler)(void) = NULL;

// Section: Driver Interface Function Definitions
void PINS_Initialize(void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000UL;
    LATB = 0x0000UL;
    LATC = 0x0408UL;
    LATD = 0x0000UL;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x0BFFUL;
    TRISB = 0x0F7FUL;
    TRISC = 0x0BBEUL;
    TRISD = 0x01FEUL;


    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPUA = 0x0000UL;
    CNPUB = 0x0000UL;
    CNPUC = 0x0008UL;
    CNPUD = 0x0000UL;
    CNPDA = 0x0000UL;
    CNPDB = 0x0000UL;
    CNPDC = 0x0000UL;
    CNPDD = 0x0000UL;


    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000UL;
    ODCB = 0x0000UL;
    ODCC = 0x0000UL;
    ODCD = 0x0000UL;


    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x0BFBUL;
    ANSELB = 0x0F67UL;

    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
      PINS_PPSUnlock(); // unlock PPS

        RPINR14bits.SDI1R = 0x0028UL; //RC7->SPI1:SDI1;
        RPINR13bits.U1RXR = 0x002CUL; //RC11->UART1:U1RX;
        RPOR9bits.RP39R = 0x0019UL;  //RC6->SPI1:SDO1;
        RPOR10bits.RP43R = 0x0013UL;  //RC10->UART1:U1TX;
        RPINR14bits.SCK1R = 0x0037UL;  //RD6->SPI1:SCK1IN;
        RPOR13bits.RP55R = 0x001AUL;  //RD6->SPI1:SCK1OUT;

        // For hardware control of SPI1:CS
        _RP11R = _RPOUT_SS1;          // RA10->SPI1:CS

      PINS_PPSLock(); // lock PPS

    /*******************************************************************************
    * Interrupt On Change: negative
    *******************************************************************************/
    CNEN1Abits.CNEN1A2 = 1; //Pin : RA2;

    /****************************************************************************
     * Interrupt On Change: flag
     ***************************************************************************/
    CNFAbits.CNFA2 = 0;    //Pin : Ext_Int

    /****************************************************************************
     * Interrupt On Change: config
     ***************************************************************************/
    CNCONAbits.CNSTYLE = 1; //Config for PORTA
    CNCONAbits.ON = 1; //Config for PORTA

    /* Initialize IOC Interrupt Handler*/
    Ext_Int_SetInterruptHandler(&Ext_Int_CallBack);

    /****************************************************************************
     * Interrupt On Change: Interrupt Enable
     ***************************************************************************/
    IFS3bits.CNAIF = 0; //Clear CNAI interrupt flag
    IEC3bits.CNAIE = 1; //Enable CNAI interrupt
}

void __attribute__ ((weak)) Ext_Int_CallBack(void)
{

}

void Ext_Int_SetInterruptHandler(void (* InterruptHandler)(void))
{
    IEC3bits.CNAIE = 0; //Disable CNAI interrupt
    Ext_Int_InterruptHandler = InterruptHandler;
    IEC3bits.CNAIE = 1; //Enable CNAI interrupt
}

/* Interrupt service function for the CNAI interrupt. */
/* cppcheck-suppress misra-c2012-8.4
*
* (Rule 8.4) REQUIRED: A compatible declaration shall be visible when an object or
* function with external linkage is defined
*
* Reasoning: Interrupt declaration are provided by compiler and are available
* outside the driver folder
*/
void __attribute__ (( interrupt, no_auto_psv )) _CNAInterrupt (void)
{
    if(CNFAbits.CNFA2 == 1)
    {
        if(Ext_Int_InterruptHandler != NULL)
        {
            Ext_Int_InterruptHandler();
        }

        CNFAbits.CNFA2 = 0;  //Clear flag for Pin - Ext_Int
    }

    // Clear the flag
    IFS3bits.CNAIF = 0;
}

