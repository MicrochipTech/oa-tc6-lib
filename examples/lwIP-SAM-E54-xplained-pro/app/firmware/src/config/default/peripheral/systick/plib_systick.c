/*******************************************************************************
  SysTick Peripheral Library

  Company:
    Microchip Technology Inc.

  File Name:
    plib_systick.c

  Summary:
    Systick Source File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#include "device.h"
#include "interrupts.h"
#include "plib_systick.h"

volatile SYSTICK_OBJECT systick;

void SYSTICK_TimerInitialize ( void )
{
    SysTick->CTRL = 0U;
    SysTick->VAL = 0U;
    SysTick->LOAD = 0x1D4C0U - 1U;
    SysTick->CTRL = SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_CLKSOURCE_Msk;

    systick.tickCounter = 0U;
    systick.callback = NULL;
}

void SYSTICK_TimerRestart ( void )
{
    SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk);
    SysTick->VAL = 0U;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

void SYSTICK_TimerStart ( void )
{
    SysTick->VAL = 0U;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

void SYSTICK_TimerStop ( void )
{
    SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk);
}

void SYSTICK_TimerPeriodSet ( uint32_t period )
{
    SysTick->LOAD = period - 1U;
}

uint32_t SYSTICK_TimerPeriodGet ( void )
{
        return(SysTick->LOAD);
}

uint32_t SYSTICK_TimerCounterGet ( void )
{
    return (SysTick->VAL);
}

uint32_t SYSTICK_TimerFrequencyGet ( void )
{
    return (SYSTICK_FREQ);
}

void SYSTICK_DelayMs ( uint32_t delay_ms)
{
   uint32_t elapsedCount=0U, delayCount;
   uint32_t deltaCount, oldCount, newCount, period;

   period = SysTick->LOAD + 1U;

   /* Calculate the count for the given delay */
   delayCount=(SYSTICK_FREQ/1000U)*delay_ms;

   if((SysTick->CTRL & SysTick_CTRL_ENABLE_Msk) == SysTick_CTRL_ENABLE_Msk)
   {
       oldCount = SysTick->VAL;

       while (elapsedCount < delayCount)
       {
           newCount = SysTick->VAL;
           deltaCount = oldCount - newCount;

           if(newCount > oldCount)
           {
               deltaCount = period - newCount + oldCount;
           }

           oldCount = newCount;
           elapsedCount = elapsedCount + deltaCount;
       }
   }
}

void SYSTICK_DelayUs ( uint32_t delay_us)
{
   uint32_t elapsedCount=0U, delayCount;
   uint32_t deltaCount, oldCount, newCount, period;

   period = SysTick->LOAD + 1U;

    /* Calculate the count for the given delay */
   delayCount=(SYSTICK_FREQ/1000000U)*delay_us;

   if((SysTick->CTRL & SysTick_CTRL_ENABLE_Msk) == SysTick_CTRL_ENABLE_Msk)
   {
       oldCount = SysTick->VAL;

       while (elapsedCount < delayCount)
       {
           newCount = SysTick->VAL;
           deltaCount = oldCount - newCount;

           if(newCount > oldCount)
           {
               deltaCount = period - newCount + oldCount;
           }

           oldCount = newCount;
           elapsedCount = elapsedCount + deltaCount;
       }
   }
}



uint32_t SYSTICK_GetTickCounter(void)
{
	return systick.tickCounter;
}

void SYSTICK_StartTimeOut (SYSTICK_TIMEOUT* timeout, uint32_t delay_ms)
{
	timeout->start = SYSTICK_GetTickCounter();
	timeout->count = (delay_ms*1000U)/SYSTICK_INTERRUPT_PERIOD_IN_US;
}

void SYSTICK_ResetTimeOut (SYSTICK_TIMEOUT* timeout)
{
	timeout->start = SYSTICK_GetTickCounter();
}

bool SYSTICK_IsTimeoutReached (SYSTICK_TIMEOUT* timeout)
{
    bool valTimeout  = true;
	if ((SYSTICK_GetTickCounter() - timeout->start) < timeout->count)
	{
		valTimeout = false;
	}

	return valTimeout;

}
void SYSTICK_TimerCallbackSet ( SYSTICK_CALLBACK callback, uintptr_t context )
{
   systick.callback = callback;
   systick.context = context;
}

void __attribute__((used)) SysTick_Handler(void)
{
   /* Additional temporary variable used to prevent MISRA violations (Rule 13.x) */
   uintptr_t context = systick.context;

   /* Reading control register clears the count flag */
   (void)SysTick->CTRL;

   systick.tickCounter++;
   if(systick.callback != NULL)
   {
       systick.callback(context);
   }
}
