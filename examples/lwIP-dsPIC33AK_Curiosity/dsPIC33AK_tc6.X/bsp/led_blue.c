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
#include "led_blue.h"

void LED_BLUE_Initialize(void)
{
    TRISDbits.TRISD2 = 0;

    /* PWM control register configuration */
    PCLKCONbits.MCLKSEL = 0b1;

    PG1CON = 0;
    PG1CONbits.CLKSEL = 1;
    PG1CONbits.MODSEL = 0b000;      /* Independent edge triggered mode */

    PG1IOCON1 = 0;
    PG1IOCON1bits.PMOD = 0b10;       /* Independent mode */
    PG1IOCON1bits.PENH = 1;          /* High output enabled */

    /* PWM uses PG1DC, PG1PER, PG1PHASE registers */
    /* PWM Generator does not broadcast UPDATE status bit state or EOC signal */
    /* Update the data registers at start of next PWM cycle (SOC) */
    /* PWM Generator operates in Single Trigger mode */
    /* Start of cycle (SOC) = local EOC */
    /* Write to DATA REGISTERS */
    PG1PER = 0x10000U; /* PWM frequency */
    PG1DC = 0x8000U;   /* 50% duty */

    PG1CONbits.ON = 0;
}

void LED_BLUE_On(void)
{
    PG1CONbits.ON = 1;
}

void LED_BLUE_Off(void)
{
    PG1CONbits.ON = 0;
}

void LED_BLUE_Toggle(void)
{
    PG1CONbits.ON ^= 1;
}

void LED_BLUE_Set(bool on)
{
    PG1CONbits.ON = on;
}

void LED_BLUE_SetIntensity(uint16_t request)
{
    while(PG1STATbits.UPDATE == 1)
    {
    }

    PG1DC = request;

    PG1STATbits.UPDREQ = 1;
}
