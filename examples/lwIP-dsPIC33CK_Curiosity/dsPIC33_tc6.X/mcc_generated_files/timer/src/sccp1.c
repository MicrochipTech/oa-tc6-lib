/**
 * SCCP1-TIMER Generated Driver Source File
 * 
 * @file      sccp1.c
 * 
 * @ingroup   timerdriver
 * 
 * @brief     This is the generated driver source file for SCCP1-TIMER driver
 *
 * @version   Driver Version 1.4.0
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

// Section: Included Files

#include <stddef.h> 
#include "../sccp1.h"

// Section: Data Type Definitions

#define MASK_32_BIT_LOW 0x0000FFFFU
#define MASK_32_BIT_HIGH 0xFFFF0000U

// Section: File specific functions

static void (*SCCP1_TimeoutHandler)(void) = NULL;

// Section: Driver Interface

// Defines an object for TIMER_INTERFACE

const struct TIMER_INTERFACE Timer1 = {
    .Initialize     = &SCCP1_Timer_Initialize,
    .Deinitialize   = &SCCP1_Timer_Deinitialize,
    .Start          = &SCCP1_Timer_Start,
    .Stop           = &SCCP1_Timer_Stop,
    .PeriodCountSet = &SCCP1_Timer_PeriodCountSet,
    .PeriodSet      = &SCCP1_Timer_PeriodSet,
    .CounterGet     = &SCCP1_Timer_CounterGet,
    .PeriodGet	    = &SCCP1_Timer_PeriodGet,
    .InterruptPrioritySet = &SCCP1_Timer_InterruptPrioritySet,
    .TimeoutCallbackRegister = &SCCP1_Timer_TimeoutCallbackRegister,
    .Tasks          = NULL,
};

// Section: Driver Interface Function Definitions

void SCCP1_Timer_Initialize(void)
{
    // MOD ; CCSEL disabled; TMR32 16 Bit; TMRPS 1:4; CLKSEL FOSC/2; TMRSYNC disabled; CCPSLP disabled; CCPSIDL disabled; CCPON disabled; 
    CCP1CON1L = 0x40; //The module is disabled, till other settings are configured
    //SYNC None; ALTSYNC disabled; ONESHOT disabled; TRIGEN disabled; IOPS Each Time Base Period Match; RTRGEN disabled; OPSRC Timer Interrupt Event; 
    CCP1CON1H = 0x0;
    //ASDG 0x0; SSDG disabled; ASDGM disabled; PWMRSEN disabled; 
    CCP1CON2L = 0x0;
    //ICSEL ; AUXOUT Disabled; ICGSM Level-Sensitive mode; OCAEN disabled; OENSYNC disabled; 
    CCP1CON2H = 0x0;
    //PSSACE Tri-state; POLACE disabled; OSCNT None; OETRIG disabled; 
    CCP1CON3H = 0x0;
    //ICOV disabled; ICDIS disabled; SCEVT disabled; ASEVT disabled; TRCLR disabled; TRSET disabled; ICGARM disabled; 
    CCP1STATL = 0x0;
    //TMRL 0x0000; 
    CCP1TMRL = 0x0;
    //TMRH 0x0000; 
    CCP1TMRH = 0x0;
    //PRL 24999; 
    CCP1PRL = 0x61A7;
    //PRH 0; 
    CCP1PRH = 0x0;
    //CMPA 0; 
    CCP1RA = 0x0;
    //CMPB 0; 
    CCP1RB = 0x0;
    //BUFL 0x0000; 
    CCP1BUFL = 0x0;
    //BUFH 0x0000; 
    CCP1BUFH = 0x0;
    
    SCCP1_Timer_TimeoutCallbackRegister(&SCCP1_TimeoutCallback);

    IFS0bits.CCT1IF = 0;
    // Enabling SCCP1 interrupt
    IEC0bits.CCT1IE = 1;

    CCP1CON1Lbits.CCPON = 1; //Enable Module
}

void SCCP1_Timer_Deinitialize(void)
{
    CCP1CON1Lbits.CCPON = 0;
    
    IFS0bits.CCT1IF = 0;
    IEC0bits.CCT1IE = 0;
    
    CCP1CON1L = 0x0; 
    CCP1CON1H = 0x0; 
    CCP1CON2L = 0x0; 
    CCP1CON2H = 0x100; 
    CCP1CON3H = 0x0; 
    CCP1STATL = 0x0; 
    CCP1TMRL = 0x0; 
    CCP1TMRH = 0x0; 
    CCP1PRL = 0xFFFF; 
    CCP1PRH = 0xFFFF; 
    CCP1RA = 0x0; 
    CCP1RB = 0x0; 
    CCP1BUFL = 0x0; 
    CCP1BUFH = 0x0; 
}

void SCCP1_Timer_Start(void)
{
    IFS0bits.CCT1IF = 0;
    // Enable SCCP1 interrupt
    IEC0bits.CCT1IE = 1;
    
    CCP1CON1Lbits.CCPON = 1;
}

void SCCP1_Timer_Stop(void)
{
    CCP1CON1Lbits.CCPON = 0;
    
    IFS0bits.CCT1IF = 0;
    // Disable SCCP1 interrupt
    IEC0bits.CCT1IE = 0;
}

void SCCP1_Timer_PeriodSet(uint32_t count)
{
    if(count > 0xFFFFU)
    {
        CCP1PRL = (uint16_t)(count & MASK_32_BIT_LOW);
        CCP1PRH = (uint16_t)((count & MASK_32_BIT_HIGH) >> 16);
        CCP1CON1Lbits.T32 = 1;
    }
    else
    {
        CCP1PRL = (uint16_t)(count & MASK_32_BIT_LOW);
        CCP1CON1Lbits.T32 = 0;
    }
}

void SCCP1_Timer_InterruptPrioritySet(enum INTERRUPT_PRIORITY priority)
{
    IPC1bits.CCT1IP = priority;
}

void SCCP1_Timer_TimeoutCallbackRegister(void (*handler)(void))
{
    if(NULL != handler)
    {
        SCCP1_TimeoutHandler = handler;
    }
}

void SCCP1_TimeoutCallbackRegister(void* handler)
{
    if(NULL != handler)
    {
        SCCP1_TimeoutHandler = handler;
    }
}

void __attribute__ ((weak)) SCCP1_TimeoutCallback (void)
{ 

} 

void __attribute__ ( ( interrupt, no_auto_psv ) ) _CCT1Interrupt (void)
{
    if(NULL != SCCP1_TimeoutHandler)
    {
        (*SCCP1_TimeoutHandler)();
    }
    IFS0bits.CCT1IF = 0;
}

void SCCP1_Timer_PeriodCountSet(size_t count)
{
    CCP1PRL = (uint16_t)(count & MASK_32_BIT_LOW);
    CCP1CON1Lbits.T32 = 0;
}

/**
 End of File
*/
