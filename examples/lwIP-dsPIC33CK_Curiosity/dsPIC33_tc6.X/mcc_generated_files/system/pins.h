/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver Pins Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *            
 * @version   Driver Version 1.0.0
 *            
 * @skipline  Device : dsPIC33CK256MP508
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

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

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB9 GPIO Pin which has a custom name of TC6_RESET to High
 * @pre      The RB9 must be set as Output Pin             
 * @return   none  
 */
#define TC6_RESET_SetHigh()          (_LATB9 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB9 GPIO Pin which has a custom name of TC6_RESET to Low
 * @pre      The RB9 must be set as Output Pin
 * @return   none  
 */
#define TC6_RESET_SetLow()           (_LATB9 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB9 GPIO Pin which has a custom name of TC6_RESET
 * @pre      The RB9 must be set as Output Pin
 * @return   none  
 */
#define TC6_RESET_Toggle()           (_LATB9 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB9 GPIO Pin which has a custom name of TC6_RESET
 * @return   none  
 */
#define TC6_RESET_GetValue()         _RB9

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB9 GPIO Pin which has a custom name of TC6_RESET as Input
 * @return   none  
 */
#define TC6_RESET_SetDigitalInput()  (_TRISB9 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB9 GPIO Pin which has a custom name of TC6_RESET as Output
 * @return   none  
 */
#define TC6_RESET_SetDigitalOutput() (_TRISB9 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB12 GPIO Pin which has a custom name of PROBE to High
 * @pre      The RB12 must be set as Output Pin             
 * @return   none  
 */
#define PROBE_SetHigh()          (_LATB12 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB12 GPIO Pin which has a custom name of PROBE to Low
 * @pre      The RB12 must be set as Output Pin
 * @return   none  
 */
#define PROBE_SetLow()           (_LATB12 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB12 GPIO Pin which has a custom name of PROBE
 * @pre      The RB12 must be set as Output Pin
 * @return   none  
 */
#define PROBE_Toggle()           (_LATB12 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB12 GPIO Pin which has a custom name of PROBE
 * @return   none  
 */
#define PROBE_GetValue()         _RB12

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB12 GPIO Pin which has a custom name of PROBE as Input
 * @return   none  
 */
#define PROBE_SetDigitalInput()  (_TRISB12 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB12 GPIO Pin which has a custom name of PROBE as Output
 * @return   none  
 */
#define PROBE_SetDigitalOutput() (_TRISB12 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB14 GPIO Pin which has a custom name of PROBE_1 to High
 * @pre      The RB14 must be set as Output Pin             
 * @return   none  
 */
#define PROBE_1_SetHigh()          (_LATB14 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RB14 GPIO Pin which has a custom name of PROBE_1 to Low
 * @pre      The RB14 must be set as Output Pin
 * @return   none  
 */
#define PROBE_1_SetLow()           (_LATB14 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RB14 GPIO Pin which has a custom name of PROBE_1
 * @pre      The RB14 must be set as Output Pin
 * @return   none  
 */
#define PROBE_1_Toggle()           (_LATB14 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RB14 GPIO Pin which has a custom name of PROBE_1
 * @return   none  
 */
#define PROBE_1_GetValue()         _RB14

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB14 GPIO Pin which has a custom name of PROBE_1 as Input
 * @return   none  
 */
#define PROBE_1_SetDigitalInput()  (_TRISB14 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RB14 GPIO Pin which has a custom name of PROBE_1 as Output
 * @return   none  
 */
#define PROBE_1_SetDigitalOutput() (_TRISB14 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD2 GPIO Pin which has a custom name of IO_CS1 to High
 * @pre      The RD2 must be set as Output Pin             
 * @return   none  
 */
#define IO_CS1_SetHigh()          (_LATD2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RD2 GPIO Pin which has a custom name of IO_CS1 to Low
 * @pre      The RD2 must be set as Output Pin
 * @return   none  
 */
#define IO_CS1_SetLow()           (_LATD2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RD2 GPIO Pin which has a custom name of IO_CS1
 * @pre      The RD2 must be set as Output Pin
 * @return   none  
 */
#define IO_CS1_Toggle()           (_LATD2 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RD2 GPIO Pin which has a custom name of IO_CS1
 * @return   none  
 */
#define IO_CS1_GetValue()         _RD2

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD2 GPIO Pin which has a custom name of IO_CS1 as Input
 * @return   none  
 */
#define IO_CS1_SetDigitalInput()  (_TRISD2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RD2 GPIO Pin which has a custom name of IO_CS1 as Output
 * @return   none  
 */
#define IO_CS1_SetDigitalOutput() (_TRISD2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RE7 GPIO Pin which has a custom name of GPIO_USER_BUTTON_1 to High
 * @pre      The RE7 must be set as Output Pin             
 * @return   none  
 */
#define GPIO_USER_BUTTON_1_SetHigh()          (_LATE7 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RE7 GPIO Pin which has a custom name of GPIO_USER_BUTTON_1 to Low
 * @pre      The RE7 must be set as Output Pin
 * @return   none  
 */
#define GPIO_USER_BUTTON_1_SetLow()           (_LATE7 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RE7 GPIO Pin which has a custom name of GPIO_USER_BUTTON_1
 * @pre      The RE7 must be set as Output Pin
 * @return   none  
 */
#define GPIO_USER_BUTTON_1_Toggle()           (_LATE7 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RE7 GPIO Pin which has a custom name of GPIO_USER_BUTTON_1
 * @return   none  
 */
#define GPIO_USER_BUTTON_1_GetValue()         _RE7

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RE7 GPIO Pin which has a custom name of GPIO_USER_BUTTON_1 as Input
 * @return   none  
 */
#define GPIO_USER_BUTTON_1_SetDigitalInput()  (_TRISE7 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RE7 GPIO Pin which has a custom name of GPIO_USER_BUTTON_1 as Output
 * @return   none  
 */
#define GPIO_USER_BUTTON_1_SetDigitalOutput() (_TRISE7 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RE11 GPIO Pin which has a custom name of Ext_Int to High
 * @pre      The RE11 must be set as Output Pin             
 * @return   none  
 */
#define Ext_Int_SetHigh()          (_LATE11 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RE11 GPIO Pin which has a custom name of Ext_Int to Low
 * @pre      The RE11 must be set as Output Pin
 * @return   none  
 */
#define Ext_Int_SetLow()           (_LATE11 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RE11 GPIO Pin which has a custom name of Ext_Int
 * @pre      The RE11 must be set as Output Pin
 * @return   none  
 */
#define Ext_Int_Toggle()           (_LATE11 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RE11 GPIO Pin which has a custom name of Ext_Int
 * @return   none  
 */
#define Ext_Int_GetValue()         _RE11

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RE11 GPIO Pin which has a custom name of Ext_Int as Input
 * @return   none  
 */
#define Ext_Int_SetDigitalInput()  (_TRISE11 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RE11 GPIO Pin which has a custom name of Ext_Int as Output
 * @return   none  
 */
#define Ext_Int_SetDigitalOutput() (_TRISE11 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RE15 GPIO Pin which has a custom name of IO_LED_RED to High
 * @pre      The RE15 must be set as Output Pin             
 * @return   none  
 */
#define IO_LED_RED_SetHigh()          (_LATE15 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RE15 GPIO Pin which has a custom name of IO_LED_RED to Low
 * @pre      The RE15 must be set as Output Pin
 * @return   none  
 */
#define IO_LED_RED_SetLow()           (_LATE15 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RE15 GPIO Pin which has a custom name of IO_LED_RED
 * @pre      The RE15 must be set as Output Pin
 * @return   none  
 */
#define IO_LED_RED_Toggle()           (_LATE15 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RE15 GPIO Pin which has a custom name of IO_LED_RED
 * @return   none  
 */
#define IO_LED_RED_GetValue()         _RE15

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RE15 GPIO Pin which has a custom name of IO_LED_RED as Input
 * @return   none  
 */
#define IO_LED_RED_SetDigitalInput()  (_TRISE15 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RE15 GPIO Pin which has a custom name of IO_LED_RED as Output
 * @return   none  
 */
#define IO_LED_RED_SetDigitalOutput() (_TRISE15 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @return   none  
 */
void PINS_Initialize(void);

/**
 * @ingroup  pinsdriver
 * @brief    This function is callback for Ext_Int Pin
 * @return   none   
 */
void Ext_Int_CallBack(void);


/**
 * @ingroup    pinsdriver
 * @brief      This function assigns a function pointer with a callback address
 * @param[in]  InterruptHandler - Address of the callback function 
 * @return     none  
 */
void Ext_Int_SetInterruptHandler(void (* InterruptHandler)(void));


#endif
