/**
 * PINS Generated Driver Source File
 *
 * @file      pins.c
 *
 * @ingroup   pinsdriver
 *
 * @brief     This is the generated driver source file for PINS driver.
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

// Section: Includes
#include <xc.h>
#include <stddef.h>
#include "../pins.h"

// Section: File specific functions
static void (*Ext_Int_InterruptHandler)(void) = NULL;

/**
 * @ingroup  pinsdriver
 * @brief    Locks all the Peripheral Remapping registers and cannot be written.
 * @return   none
 */
#define PINS_PPSLock()           (RPCONbits.IOLOCK = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Unlocks all the Peripheral Remapping registers and can be written.
 * @return   none
 */
#define PINS_PPSUnlock()         (RPCONbits.IOLOCK = 0)

// Section: Driver Interface Function Definitions
void PINS_Initialize(void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000UL;
    LATB = 0x0000UL;
    LATC = 0x0000UL;
    LATD = 0x0000UL;
    LATE = 0x0000UL;
    LATF = 0x0000UL;
    LATG = 0x0000UL;
    LATH = 0x0002UL;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x7FFFUL;
    TRISB = 0xFFFFUL;
    TRISC = 0xFFFEUL;
    TRISD = 0xFFFFUL;
    TRISE = 0x07DFUL;
    TRISF = 0x0FEFUL;
    TRISG = 0x03E7UL;
    TRISH = 0x0005UL;


    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPUA = 0x0000UL;
    CNPUB = 0x0000UL;
    CNPUC = 0x0000UL;
    CNPUD = 0x0000UL;
    CNPUE = 0x0000UL;
    CNPUF = 0x0000UL;
    CNPUG = 0x0000UL;
    CNPUH = 0x0000UL;
    CNPDA = 0x0000UL;
    CNPDB = 0x0000UL;
    CNPDC = 0x0000UL;
    CNPDD = 0x0000UL;
    CNPDE = 0x0000UL;
    CNPDF = 0x0000UL;
    CNPDG = 0x0000UL;
    CNPDH = 0x0000UL;


    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000UL;
    ODCB = 0x0000UL;
    ODCC = 0x0000UL;
    ODCD = 0x0000UL;
    ODCE = 0x0000UL;
    ODCF = 0x0000UL;
    ODCG = 0x0000UL;
    ODCH = 0x0000UL;


    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x7FFFUL;
    ANSELB = 0xFFFFUL;
    ANSELE = 0x0003UL;
    ANSELF = 0x0001UL;

    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
      PINS_PPSUnlock(); // unlock PPS

        RPINR14bits.SDI1R = 0x006AUL; //RG9->SPI1:SDI1;
        RPINR13bits.U1RXR = 0x0032UL; //RD1->UART1:U1RX;
        RPOR25bits.RP101R = 0x0019UL;  //RG4->SPI1:SDO1;
        RPOR28bits.RP114R = 0x0013UL;  //RH1->UART1:U1TX;
        RPINR14bits.SCK1R = 0x004BUL;  //RE10->SPI1:SCK1IN;
        RPOR18bits.RP75R = 0x001AUL;  //RE10->SPI1:SCK1OUT;

        _RP70R = _RPOUT_SS1;    //RE5->SPI1:CS
      PINS_PPSLock(); // lock PPS

    /*******************************************************************************
    * Interrupt On Change: negative
    *******************************************************************************/
    CNEN1Ebits.CNEN1E2 = 1; //Pin : RE2;

    /****************************************************************************
     * Interrupt On Change: flag
     ***************************************************************************/
    CNFEbits.CNFE2 = 0;    //Pin : Ext_Int

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
    IFS9bits.CNEIF = 0; //Clear CNEI interrupt flag
    IEC9bits.CNEIE = 1; //Enable CNEI interrupt
}

void __attribute__ ((weak)) Ext_Int_CallBack(void)
{

}

void Ext_Int_SetInterruptHandler(void (* InterruptHandler)(void))
{
    IEC9bits.CNEIE = 0; //Disable CNEI interrupt
    Ext_Int_InterruptHandler = InterruptHandler;
    IEC9bits.CNEIE = 1; //Enable CNEI interrupt
}

/* Interrupt service function for the CNEI interrupt. */
void __attribute__ (( interrupt, no_auto_psv )) _CNEInterrupt (void)
{
    if(CNFEbits.CNFE2 == 1)
    {
        if(Ext_Int_InterruptHandler != NULL)
        {
            Ext_Int_InterruptHandler();
        }

        CNFEbits.CNFE2 = 0;  //Clear flag for Pin - Ext_Int
    }

    // Clear the flag
    IFS9bits.CNEIF = 0;
}

