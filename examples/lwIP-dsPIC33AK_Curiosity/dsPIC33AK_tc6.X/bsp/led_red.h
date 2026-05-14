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

#ifndef LED_RED_H
#define LED_RED_H

#include <stdbool.h>
#include <stdint.h>

/**
 * @ingroup  led_red
 * @brief    Initializes the LED.  Must be called before other functions can be used.
 * @param    none
 * @return   none
 */
void LED_RED_Initialize(void);

/**
 * @ingroup  led_red
 * @brief    Turns on the LED
 * @param    none
 * @return   none
 */
void LED_RED_On(void);

/**
 * @ingroup  led_red
 * @brief    Turns off the LED
 * @param    none
 * @return   none
 */
void LED_RED_Off(void);

/**
 * @ingroup  led_red
 * @brief    Toggles the LED between on/off states (on->off or off->on)
 * @param    none
 * @return   none
 */
void LED_RED_Toggle(void);

/**
 * @ingroup  led_red
 * @brief    Sets the LED on(true) or off(false) based on provided input.
 * @param[in] bool on - true = on, false = off
 * @return   none
 */
void LED_RED_Set(bool on);

/**
 * @ingroup  led_red
 * @brief    Sets the intensity/brightness of the LED.
 * @param[in] uint16_t request - the requested intensity (16-bit)
 * @return   none
 */
void LED_RED_SetIntensity(uint16_t intensity);

#endif