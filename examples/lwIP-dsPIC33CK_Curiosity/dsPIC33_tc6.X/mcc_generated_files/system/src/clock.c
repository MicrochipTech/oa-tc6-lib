/**
 * CLOCK Generated Driver Source File 
 * 
 * @file      clock.c
 *            
 * @ingroup   clockdriver
 *            
 * @brief     This is the generated source file for CLOCK driver
 *            
 * @version   Driver Version 1.0.1
 *            
 * @skipline  Device : dsPIC33CK256MP508
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

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
#include <stdint.h>
#include "../clock.h"

void CLOCK_Initialize(void)
{
    /*  
       Input frequency                               :  8.00 MHz
       Clock source                                  :  Primary Oscillator with PLL
       System frequency (Fosc)                       :  200.00 MHz [(8.00 MHz / 1) * 50 / 1 / 2 = 200.00 MHz]
       PLL VCO frequency (Fvco)                      :  400.00 MHz [(8.00 MHz / 1) * 50 = 400.00 MHz]
       PLL output frequency (Fpllo)                  :  400.00 MHz [(8.00 MHz / 1) * 50 / 1 = 400.00 MHz]
       PLL VCO divider frequency (Fvcodiv)           :  100.00 MHz [400.00 MHz / 4 = 100.00 MHz]
       Clock switching enabled                       :  true
       Clock source when device boots                :  FRC Oscillator
       Auxiliary clock source                        :  FRC Oscillator
       Auxiliary clock input frequency               :  8.00 MHz
       Auxiliary clock PLL output frequency (AFpllo) :  8.00 MHz
    */
    // RCDIV FRC/1; PLLPRE 1:1; DOZE 1:8; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x3001;
    // PLLDIV 50; 
    PLLFBD = 0x32;
    // TUN Center frequency; 
    OSCTUN = 0x0;
    // PLLPOST 1:1; VCODIV FVCO/4; POST2DIV 1:1; 
    PLLDIV = 0x11;
    // ENAPLL disabled; FRCSEL FRC Oscillator; APLLPRE ; 
    ACLKCON1 = 0x101;
    // APLLFBDIV ; 
    APLLFBD1 = 0x96;
    // APSTSCLR ; APOST2DIV ; AVCODIV FVCO/4; 
    APLLDIV1 = 0x31;
    // CANCLKEN disabled; CANCLKSEL FVCO/4; CANCLKDIV Divide by 1; 
    CANCLKCON = 0x500;
    // ROEN enabled; DIVSWEN enabled; ROSLP disabled; ROSEL FOSC; OE enabled; ROSIDL disabled; 
    REFOCONL = 0x9200;
    // RODIV 12; 
    REFOCONH = 0xC;
    // ROTRIM 256; 
    REFOTRIMH = 0x8000;
    // IOLOCK disabled; 
    RPCON = 0x0;
    // PMDLOCK disabled; 
    PMDCON = 0x0;
    // ADC1MD enabled; T1MD enabled; U2MD enabled; U1MD enabled; SPI2MD enabled; SPI1MD enabled; QEIMD enabled; PWMMD enabled; I2C1MD enabled; C1MD enabled; 
    PMD1 = 0x0;
    // CCP2MD enabled; CCP1MD enabled; CCP4MD enabled; CCP3MD enabled; CCP7MD enabled; CCP8MD enabled; CCP5MD enabled; CCP6MD enabled; CCP9MD enabled; 
    PMD2 = 0x0;
    // U3MD enabled; CRCMD enabled; I2C2MD enabled; I2C3MD enabled; QEI2MD enabled; PMPMD enabled; 
    PMD3 = 0x0;
    // REFOMD enabled; 
    PMD4 = 0x0;
    // DMA1MD enabled; DMA2MD enabled; DMA3MD enabled; DMA0MD enabled; SPI3MD enabled; 
    PMD6 = 0x0;
    // PTGMD enabled; CMP1MD enabled; CMP3MD enabled; CMP2MD enabled; 
    PMD7 = 0x0;
    // DMTMD enabled; CLC3MD enabled; OPAMPMD enabled; BIASMD enabled; CLC4MD enabled; SENT1MD enabled; CLC1MD enabled; CLC2MD enabled; SENT2MD enabled; 
    PMD8 = 0x0;
    // CF no clock failure; NOSC PRIPLL; CLKLOCK unlocked; OSWEN Switch is Complete; 
    __builtin_write_OSCCONH((uint8_t) (0x03));
    __builtin_write_OSCCONL((uint8_t) (0x01));
    // Wait for Clock switch to occur
    while (OSCCONbits.OSWEN != 0);
    while (OSCCONbits.LOCK != 1);
}

bool CLOCK_AuxPllLockStatusGet()
{
    return ACLKCON1bits.APLLCK;
}

