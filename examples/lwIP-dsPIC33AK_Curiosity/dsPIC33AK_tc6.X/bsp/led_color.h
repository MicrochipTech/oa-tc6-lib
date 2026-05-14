/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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

#ifndef LED_COLOR_H
#define LED_COLOR_H

#include <stdbool.h>

/**
 @ingroup  led_color
 @struct   LED_COLOR
 @brief    Defines structure for interface for an RGB LED
*/
struct LED_COLOR
{
    //Initializes the LED.  Must be called before other functions can be used.
    void (*const initialize)(void);
    //Turns on the LED
    void (*const on)(void);
    //Turns off the LED
    void (*const off)(void);
    //Toggles the LED between on/off states (on->off or off->on)
    void (*const toggle)(void);
    //Sets the LED on(true) or off(false) based on provided input.
    void (*const set)(bool);
    //Set the RGB value of the LED (approximate)
    void (*const setColor)(uint8_t red, uint8_t green, uint8_t blue);
};

#endif