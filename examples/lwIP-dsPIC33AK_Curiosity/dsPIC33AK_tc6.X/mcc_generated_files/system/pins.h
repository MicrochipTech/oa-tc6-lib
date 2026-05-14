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
 * @skipline @version   PLIB Version 1.0.1
 *
 * @skipline  Device : dsPIC33AK512MPS512
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

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
 * @brief    Sets the RA15 GPIO Pin which has a custom name of TC6_RESET to High
 * @pre      The RA15 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define TC6_RESET_SetHigh()          (_LATA15 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA15 GPIO Pin which has a custom name of TC6_RESET to Low
 * @pre      The RA15 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define TC6_RESET_SetLow()           (_LATA15 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA15 GPIO Pin which has a custom name of TC6_RESET
 * @pre      The RA15 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define TC6_RESET_Toggle()           (_LATA15 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA15 GPIO Pin which has a custom name of TC6_RESET
 * @param    none
 * @return   none  
 */
#define TC6_RESET_GetValue()         _RA15

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA15 GPIO Pin which has a custom name of TC6_RESET as Input
 * @param    none
 * @return   none  
 */
#define TC6_RESET_SetDigitalInput()  (_TRISA15 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA15 GPIO Pin which has a custom name of TC6_RESET as Output
 * @param    none
 * @return   none  
 */
#define TC6_RESET_SetDigitalOutput() (_TRISA15 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RE2 GPIO Pin which has a custom name of Ext_Int to High
 * @pre      The RE2 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define Ext_Int_SetHigh()          (_LATE2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RE2 GPIO Pin which has a custom name of Ext_Int to Low
 * @pre      The RE2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define Ext_Int_SetLow()           (_LATE2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RE2 GPIO Pin which has a custom name of Ext_Int
 * @pre      The RE2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define Ext_Int_Toggle()           (_LATE2 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RE2 GPIO Pin which has a custom name of Ext_Int
 * @param    none
 * @return   none  
 */
#define Ext_Int_GetValue()         _RE2

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RE2 GPIO Pin which has a custom name of Ext_Int as Input
 * @param    none
 * @return   none  
 */
#define Ext_Int_SetDigitalInput()  (_TRISE2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RE2 GPIO Pin which has a custom name of Ext_Int as Output
 * @param    none
 * @return   none  
 */
#define Ext_Int_SetDigitalOutput() (_TRISE2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RE5 GPIO Pin which has a custom name of ETH_CS to High
 * @pre      The RE5 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define ETH_CS_SetHigh()          (_LATE5 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RE5 GPIO Pin which has a custom name of ETH_CS to Low
 * @pre      The RE5 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define ETH_CS_SetLow()           (_LATE5 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RE5 GPIO Pin which has a custom name of ETH_CS
 * @pre      The RE5 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define ETH_CS_Toggle()           (_LATE5 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RE5 GPIO Pin which has a custom name of ETH_CS
 * @param    none
 * @return   none  
 */
#define ETH_CS_GetValue()         _RE5

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RE5 GPIO Pin which has a custom name of ETH_CS as Input
 * @param    none
 * @return   none  
 */
#define ETH_CS_SetDigitalInput()  (_TRISE5 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RE5 GPIO Pin which has a custom name of ETH_CS as Output
 * @param    none
 * @return   none  
 */
#define ETH_CS_SetDigitalOutput() (_TRISE5 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);

/**
 * @ingroup  pinsdriver
 * @brief    This function is callback for Ext_Int Pin
 * @param    none
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
