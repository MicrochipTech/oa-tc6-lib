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
#include "pot.h"

void POT_Initialize(void)
{
    // In this example channel 0 will be used.
    // Oversampling conversion mode.
    AD5CH0CON1bits.MODE = 3;
    // Set number of conversions accumulated to 256.
    AD5CH0CON1bits.ACCNUM = 2;

    // Software trigger will start a conversion.
    AD5CH0CON1bits.TRG1SRC = 1;

     // Re-trigger back to back.
    AD5CH0CON1bits.TRG2SRC = 2;

    // Use a single ended input.
    AD5CH0CON1bits.DIFF = 0;
    // Select the AN0 analog positive input/pin for the signal.
    AD5CH0CON1bits.PINSEL = 0;
    // Select the GND as negative input/pin for the signal.
    AD5CH0CON1bits.NINSEL = 0;
    // Select signal sampling time (6.5 TADs = 81 nS).
    AD5CH0CON1bits.SAMC = 3;
    // Set ADC to RUN mode.
    AD5CONbits.MODE = 2;
    // Enable ADC.
    AD5CONbits.ON = 1;

    // Wait when ADC will be ready/calibrated.
    while(AD5CONbits.ADRDY == 0)
    {
    }
}

uint16_t POT_Read(void)
{
    // Trigger channel #1 in software and wait for the result.
    AD5SWTRGbits.CH0TRG = 1;
    // Wait for a conversion ready flag.
    while(AD5STATbits.CH0RDY == 0)
    {
    }

    // Read result. It will clear the conversion ready flag.
    return AD5CH0DATA;
}
