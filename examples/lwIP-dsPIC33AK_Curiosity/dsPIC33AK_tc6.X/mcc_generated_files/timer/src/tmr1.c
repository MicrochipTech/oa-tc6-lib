/**
 * TMR1 Generated Driver Source File 
 * 
 * @file      tmr1.c
 * 
 * @ingroup   timerdriver
 * 
 * @brief     This is the generated driver source file for TMR1 driver
 *
 * @version   PLIB Version 1.0.1
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

// Section: Included Files
#include "../tmr1.h"
#include "../timer_interface.h"

// Section: File specific functions

static void (*TMR1_TimeoutHandler)(void) = NULL;

// Section: Driver Interface

const struct TIMER_INTERFACE Timer1 = {
    .Initialize            = &TMR1_Initialize,
    .Deinitialize          = &TMR1_Deinitialize,
    .Start                 = &TMR1_Start,
    .Stop                  = &TMR1_Stop,
    .PeriodSet             = &TMR1_PeriodSet,
    .PeriodGet             = &TMR1_PeriodGet,
    .CounterGet            = &TMR1_CounterGet,
    .InterruptPrioritySet  = &TMR1_InterruptPrioritySet,
    .TimeoutCallbackRegister = &TMR1_TimeoutCallbackRegister,
    .Tasks          = NULL
};

// Section: TMR1 Module APIs

void TMR1_Initialize (void)
{
    //TCS Standard Speed Peripheral Clock; TSYNC disabled; TCKPS 1:1; TGATE disabled; TECS Standard Speed Peripheral Clock; PRWIP Write complete; TMWIP Write complete; TMWDIS disabled; SIDL disabled; ON disabled; 
    T1CON = 0x0UL;
    //TMR 0x0; 
    TMR1 = 0x0UL;
    //Period 0.01 ms; Frequency 100,000,000 Hz; PR 999; 
    PR1 = 0x3E7UL;
    
    TMR1_TimeoutCallbackRegister(&TMR1_TimeoutCallback);

    //Clear interrupt flag
    IFS1bits.T1IF = 0;
    //Enable the interrupt
    IEC1bits.T1IE = 1;
    
    TMR1_Start();
}

void TMR1_Deinitialize (void)
{
    TMR1_Stop();
    
    //Disable the interrupt
    IEC1bits.T1IE = 0;
    
    T1CON = 0x0UL;
    TMR1 = 0x0UL;
    PR1 = 0xFFFFFFFFUL;
}

void TMR1_Start( void )
{
    // Start the Timer 
    T1CONbits.ON = 1;
}

void TMR1_Stop( void )
{
    // Stop the Timer 
    T1CONbits.ON = 0;
}

void TMR1_PeriodSet(uint32_t count)
{
    PR1 = count;
}

void TMR1_InterruptPrioritySet(enum INTERRUPT_PRIORITY priority)
{
    IPC6bits.T1IP = priority;
}

void TMR1_TimeoutCallbackRegister(void (*handler)(void))
{
    if(NULL != handler)
    {
        TMR1_TimeoutHandler = handler;
    }
}

void __attribute__ ((weak)) TMR1_TimeoutCallback( void )
{ 

} 

void __attribute__ ((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    (*TMR1_TimeoutHandler)();
    IFS1bits.T1IF = 0;
}

/**
 End of File
*/
