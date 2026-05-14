/*------------------------------------------------------------------------------------------------*/
/* System Tick Handler                                                                            */
/* Copyright 2021, Microchip Technology Inc. and its subsidiaries.                                */
/*                                                                                                */
/* Redistribution and use in source and binary forms, with or without                             */
/* modification, are permitted provided that the following conditions are met:                    */
/*                                                                                                */
/* 1. Redistributions of source code must retain the above copyright notice, this                 */
/*    list of conditions and the following disclaimer.                                            */
/*                                                                                                */
/* 2. Redistributions in binary form must reproduce the above copyright notice,                   */
/*    this list of conditions and the following disclaimer in the documentation                   */
/*    and/or other materials provided with the distribution.                                      */
/*                                                                                                */
/* 3. Neither the name of the copyright holder nor the names of its                               */
/*    contributors may be used to endorse or promote products derived from                        */
/*    this software without specific prior written permission.                                    */
/*                                                                                                */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"                    */
/* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE                      */
/* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE                 */
/* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE                   */
/* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL                     */
/* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR                     */
/* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER                     */
/* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,                  */
/* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE                  */
/* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/*------------------------------------------------------------------------------------------------*/

#include <string.h>
#include "systick.h"

#include "mcc_generated_files/timer/tmr1.h"
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/system/interrupt.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

// Support a delay method based on system peripheral clock.
#ifndef FCY
    #include "mcc_generated_files/system/clock.h"
    #define FCY CLOCK_FastPeripheralFrequencyGet()
#endif
#include <libpic30.h>

/// @brief Defines the Systick object.
typedef struct
{
   volatile uint64_t tickCounter;
} SYSTICK_OBJECT;

static SYSTICK_OBJECT systick;

#define ENTER_CRITICAL()   (INTERRUPT_GlobalDisable())
#define LEAVE_CRITICAL()   (INTERRUPT_GlobalEnable())

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void TimerCallback(void);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void SysTick_Initialize(void)
{
    (void)memset(&systick, 0, sizeof(SYSTICK_OBJECT));

    Timer1.TimeoutCallbackRegister(TimerCallback);
    Timer1.Start();
}

uint32_t SysTick_GetTickMs(void)
{
    volatile uint32_t now;

    ENTER_CRITICAL();
    now = (uint32_t)(systick.tickCounter / SYSTICK_TIMER_SCALER_MS);
    LEAVE_CRITICAL();

    return now;
}

uint64_t SysTick_GetTickUs(void)
{
    volatile uint64_t now;

    ENTER_CRITICAL();
    now = (systick.tickCounter * SYSTICK_TIMER_SCALER_US);
    LEAVE_CRITICAL();

    return now;
}

void SysTick_DelayMs(uint32_t milliseconds)
{
    __delay_ms(milliseconds);
}

void SysTick_DelayUs(uint32_t microseconds)
{
    __delay_us(microseconds);
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  PRIVATE  FUNCTION IMPLEMENTATIONS                   */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void TimerCallback(void)
{
    systick.tickCounter++;
}