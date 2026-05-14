/*
� [2024] Microchip Technology Inc. and its subsidiaries.

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

#include <xc.h>
#include "led_red.h"

void LED_RED_Initialize(void)
{
    TRISDbits.TRISD9 = 0;

    /* PWM control register configuration */
    PCLKCONbits.MCLKSEL = 0b1;

    PG6CON = 0;
    PG6CONbits.CLKSEL = 1;
    PG6CONbits.MODSEL = 0b000;      /* Independent edge triggered mode */

    PG6IOCON1 = 0;
    PG6IOCON1bits.PMOD = 0b10;       /* Independent mode */
    PG6IOCON1bits.PENH = 1;          /* High output enabled */

    /* PWM uses PG4DC, PG4PER, PG4PHASE registers */
    /* PWM Generator does not broadcast UPDATE status bit state or EOC signal */
    /* Update the data registers at start of next PWM cycle (SOC) */
    /* PWM Generator operates in Single Trigger mode */
    /* Start of cycle (SOC) = local EOC */
    /* Write to DATA REGISTERS */
    PG6PER = 0x10000U; /* PWM frequency */
    PG6DC = 0x8000U;   /* 50% duty */

    PG6CONbits.ON = 0;
}

void LED_RED_On(void)
{
    PG6CONbits.ON = 1;
}

void LED_RED_Off(void)
{
    PG6CONbits.ON = 0;
}

void LED_RED_Toggle(void)
{
    PG6CONbits.ON ^= 1;
}

void LED_RED_Set(bool on)
{
    PG6CONbits.ON = on;
}

void LED_RED_SetIntensity(uint16_t request)
{
    while(PG6STATbits.UPDATE == 1)
    {
    }

    PG6DC = request;

    PG6STATbits.UPDREQ = 1;
}
