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
#include "led_green.h"

void LED_GREEN_Initialize(void)
{
    TRISDbits.TRISD0 = 0;

    /* PWM control register configuration */
    PCLKCONbits.MCLKSEL = 0b1;

    PG2CON = 0;
    PG2CONbits.CLKSEL = 1;
    PG2CONbits.MODSEL = 0b000;      /* Independent edge triggered mode */

    PG2IOCON1 = 0;
    PG2IOCON1bits.PMOD = 0b10;       /* Independent mode */
    PG2IOCON1bits.PENH = 1;          /* High output enabled */

    /* PWM uses PG2DC, PG2PER, PG2PHASE registers */
    /* PWM Generator does not broadcast UPDATE status bit state or EOC signal */
    /* Update the data registers at start of next PWM cycle (SOC) */
    /* PWM Generator operates in Single Trigger mode */
    /* Start of cycle (SOC) = local EOC */
    /* Write to DATA REGISTERS */
    PG2PER = 0x10000U; /* PWM frequency */
    PG2DC = 0x8000U;   /* 50% duty */

    PG2CONbits.ON = 0;
}

void LED_GREEN_On(void)
{
    PG2CONbits.ON = 1;
}

void LED_GREEN_Off(void)
{
    PG2CONbits.ON = 0;
}

void LED_GREEN_Toggle(void)
{
    PG2CONbits.ON ^= 1;
}

void LED_GREEN_Set(bool on)
{
    PG2CONbits.ON = on;
}

void LED_GREEN_SetIntensity(uint16_t request)
{
    while(PG2STATbits.UPDATE == 1)
    {
    }

    PG2DC = request;

    PG2STATbits.UPDREQ = 1;
}
