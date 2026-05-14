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

#include "led_rgb.h"
#include "led_red.h"
#include "led_green.h"
#include "led_blue.h"

void LED_RGB_Initialize(void)
{
    LED_RED_Initialize();
    LED_GREEN_Initialize();
    LED_BLUE_Initialize();
}

void LED_RGB_On(void)
{
    LED_RED_On();
    LED_GREEN_On();
    LED_BLUE_On();
}

void LED_RGB_Off(void)
{
    LED_RED_Off();
    LED_GREEN_Off();
    LED_BLUE_Off();
}

void LED_RGB_Toggle(void)
{
    LED_RED_Toggle();
    LED_GREEN_Toggle();
    LED_BLUE_Toggle();
}

void LED_RGB_Set(bool on)
{
    LED_RED_Set(on);
    LED_GREEN_Set(on);
    LED_BLUE_Set(on);
}

void LED_RGB_SetColor(uint8_t red, uint8_t green, uint8_t blue)
{
    LED_RED_SetIntensity((uint16_t)red << 8u);
    LED_GREEN_SetIntensity((uint16_t)green << 8u);
    LED_BLUE_SetIntensity((uint16_t)blue << 8u);
}
