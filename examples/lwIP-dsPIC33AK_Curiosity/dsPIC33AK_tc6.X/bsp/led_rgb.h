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

#ifndef LED_RGB_H
#define LED_RGB_H

#include <stdbool.h>
#include <stdint.h>

/**
 * @ingroup  led_rgb
 * @brief    Initializes the LED.  Must be called before other functions can be used.
 * @param    none
 * @return   none
 */
void LED_RGB_Initialize(void);

/**
 * @ingroup  led_rgb
 * @brief    Turns on the LED
 * @param    none
 * @return   none
 */
void LED_RGB_On(void);

/**
 * @ingroup  led_rgb
 * @brief    Turns off the LED
 * @param    none
 * @return   none
 */
void LED_RGB_Off(void);

/**
 * @ingroup  led_rgb
 * @brief    Toggles the LED between on/off states (on->off or off->on)
 * @param    none
 * @return   none
 */
void LED_RGB_Toggle(void);

/**
 * @ingroup  led_rgb
 * @brief    Sets the LED on(true) or off(false) based on provided input.
 * @param[in] bool on - true = on, false = off
 * @return   none
 */
void LED_RGB_Set(bool on);

/**
 * @ingroup  led_rgb
 * @brief    Set the RGB value of the LED (approximate)
 * @param[in] uint8_t red - 8-bit red value
 * @param[in] uint8_t green - 8-bit green value
 * @param[in] uint8_t blue - 8-bit blue value
 * @return   none
 */
void LED_RGB_SetColor(uint8_t red, uint8_t green, uint8_t blue);

#endif