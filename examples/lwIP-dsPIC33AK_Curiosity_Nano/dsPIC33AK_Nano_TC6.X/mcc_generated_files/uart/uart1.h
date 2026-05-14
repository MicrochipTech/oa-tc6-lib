/**
 * UART1 Generated Driver Header File
 * 
 * @file      uart1.h
 *            
 * @ingroup   uartdriver
 *            
 * @brief     This is the generated driver header file for the UART1 driver
 *
 * @skipline @version   PLIB Version 1.1.0
 *            
 * @skipline  Device : dsPIC33AK512MPS506
*/

/*
© [2026] Microchip Technology Inc. and its subsidiaries.

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

#ifndef UART1_H
#define UART1_H

// Section: Included Files

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "uart_interface.h"

// Section: Data Type Definitions

/**
 @ingroup  uartdriver
 @brief    Structure object of type UART_INTERFACE with the 
           custom name given by the user in the Melody Driver User interface. 
           The default name e.g. UART1 can be changed by the 
           user in the UART user interface. 
           This allows defining a structure with application specific name 
           using the 'Custom Name' field. Application specific name allows the 
           API Portability.
*/
extern const struct UART_INTERFACE UART1_Drv;

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_Initialize API
 */
#define UART1_Drv_Initialize UART1_Initialize

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_Deinitialize API
 */
#define UART1_Drv_Deinitialize UART1_Deinitialize

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_Read API
 */
#define UART1_Drv_Read UART1_Read

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_Write API
 */
#define UART1_Drv_Write UART1_Write

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_IsRxReady API
 */
#define UART1_Drv_IsRxReady UART1_IsRxReady

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_IsTxReady API
 */
#define UART1_Drv_IsTxReady UART1_IsTxReady

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_IsTxDone API
 */
#define UART1_Drv_IsTxDone UART1_IsTxDone

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_TransmitEnable API
 */
#define UART1_Drv_TransmitEnable UART1_TransmitEnable

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_TransmitDisable API
 */
#define UART1_Drv_TransmitDisable UART1_TransmitDisable

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_TransmitInterruptEnable API
 */
#define UART1_Drv_TransmitInterruptEnable UART1_TransmitInterruptEnable

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_TransmitInterruptDisable API
 */
#define UART1_Drv_TransmitInterruptDisable UART1_TransmitInterruptDisable

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_AutoBaudSet API
 */
#define UART1_Drv_AutoBaudSet UART1_AutoBaudSet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_AutoBaudQuery API
 */
#define UART1_Drv_AutoBaudQuery UART1_AutoBaudQuery

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_AutoBaudEventEnableGet API
 */
#define UART1_Drv_AutoBaudEventEnableGet UART1_AutoBaudEventEnableGet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_ErrorGet API
 */
#define UART1_Drv_ErrorGet UART1_ErrorGet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_BRGCountSet API
 */
#define UART1_Drv_BRGCountSet UART1_BRGCountSet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_BRGCountGet API
 */
#define UART1_Drv_BRGCountGet UART1_BRGCountGet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_BaudRateSet API
 */
#define UART1_Drv_BaudRateSet UART1_BaudRateSet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_BaudRateGet API
 */
#define UART1_Drv_BaudRateGet UART1_BaudRateGet

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_RxCompleteCallbackRegister API
 */
#define UART1_Drv_RxCompleteCallbackRegister  UART1_RxCompleteCallbackRegister

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_TxCompleteCallbackRegister API
 */
#define UART1_Drv_TxCompleteCallbackRegister  UART1_TxCompleteCallbackRegister

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_TxCollisionCallbackRegister API
 */
#define UART1_Drv_TxCollisionCallbackRegister  UART1_TxCollisionCallbackRegister

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_FramingErrorCallbackRegister API
 */
#define UART1_Drv_FramingErrorCallbackRegister  UART1_FramingErrorCallbackRegister

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_OverrunErrorCallbackRegister API
 */
#define UART1_Drv_OverrunErrorCallbackRegister  UART1_OverrunErrorCallbackRegister

/**
 * @ingroup  uartdriver
 * @brief    This macro defines the Custom Name for \ref UART1_ParityErrorCallbackRegister API
 */
#define UART1_Drv_ParityErrorCallbackRegister  UART1_ParityErrorCallbackRegister

// Section: UART1 Driver Routines

/**
 * @ingroup  uartdriver
 * @brief    Initializes the UART driver
 * @param    none
 * @return   none
 */
void UART1_Initialize(void);

/**
 * @ingroup  uartdriver
 * @brief    Deinitializes the UART to POR values
 * @param    none
 * @return   none
 */
void UART1_Deinitialize(void);

/**
 * @ingroup  uartdriver
 * @brief    Reads a byte of data from the UART1
 * @pre      Check receive status using \ref UART1_IsRxReady function
 *           before calling this function or call this function within the 
 *           \ref UART1_RxCompleteCallback. 
 * @param    none
 * @return   A data byte received by the driver.
 */
uint8_t UART1_Read(void);

/**
 * @ingroup    uartdriver
 * @brief      Writes a byte of data to the UART1
 * @pre        UART1_Initialize function should have been called
 *             before calling this function. The transfer status should be checked
 *             to see if transmitter is not full before calling this function.
 * @param[in]  data - Data byte to write to the UART1
 * @return     none
 */
void UART1_Write(uint8_t data);

/**
 * @ingroup  uartdriver
 * @brief    Returns a boolean value if data is available to read
 * @param    none
 * @return   true  - Data available to read
 * @return   false - Data not available to read
 */
bool UART1_IsRxReady(void);

/**
 * @ingroup  uartdriver
 * @brief    Returns a boolean value if data can be written
 * @param    none
 * @return   true    - Data can be written
 * @return   false   - Data can not be written
 */
bool UART1_IsTxReady(void);

/**
 * @ingroup  uartdriver
 * @brief    Indicates if all bytes have been transferred
 * @param    none
 * @return   true    - All bytes transferred
 * @return   false   - Data transfer is pending
 */
bool UART1_IsTxDone(void);

/**
 * @ingroup  uartdriver
 * @brief    Enables UART1 transmit 
 * @param    none
 * @return   none
 */
void UART1_TransmitEnable(void);

/**
 * @ingroup  uartdriver
 * @brief    Disables UART1 transmit 
 * @param    none
 * @return   none
 */
void UART1_TransmitDisable(void);

/**
 * @ingroup  uartdriver
 * @brief    Enables UART1 transmit interrupt 
 * @param    none
 * @return   none
 */
void UART1_TransmitInterruptEnable(void);

/**
 * @ingroup  uartdriver
 * @brief    Disables UART1 transmit interrupt
 * @note     Do not disable the interrupt when transmission in progress
 * @note     Software bufferes are not used when transmit interrupt is disabled
 * @param    none
 * @return   none
 */
void UART1_TransmitInterruptDisable(void);

/**
 * @ingroup  uartdriver
 * @brief    Enables or disables UART1 Auto-Baud detection
 * @param[in]  enable - true, starts the auto-baud detection  
 * @param[in]  enable - false, disables the auto-baud detection  
 * @return   none
 */
void UART1_AutoBaudSet(bool enable);

/**
 * @ingroup  uartdriver
 * @brief    Returns the status of Auto-Baud detection
 * @param    none
 * @return   true    - Auto-Baud detection in progress or counter overflow occurred
 * @return   false   - Auto-Baud detection is complete or disabled
 */
bool UART1_AutoBaudQuery(void);

/**
 * @ingroup  uartdriver
 * @brief    Returns enable state of the Auto-Baud feature
 * @param    none
 * @return   true    - Auto-Baud is enabled
 * @return   false   - Auto-Baud is disabled
 */
bool UART1_AutoBaudEventEnableGet(void);

/**
 * @ingroup  uartdriver
 * @brief    Sets the BRG value of UART1
 * @param[in]   baudRate - BRG value upto 20 bits   
 * @return   none
 * @note    Make sure the is no transmission in progress using \ref UART1_IsTxDone function
 */
void UART1_BRGCountSet(uint32_t brgValue);

/**
 * @ingroup  uartdriver
 * @brief    Gets the BRG value of UART1
 * @param    none
 * @return   Combined BRG value upto 20 bits
 */
uint32_t UART1_BRGCountGet(void);

/**
 * @ingroup  uartdriver
 * @brief    Sets the calculated Baud-Rate of UART1
 * @param[in]   baudRate - Value of Baud-Rate to be set  
 * @return   none
 * @note    Make sure the is no transmission in progress using \ref UART1_IsTxDone function
 */
void UART1_BaudRateSet(uint32_t baudRate);

/**
 * @ingroup  uartdriver
 * @brief    Gets the actual Baud-Rate of UART1
 * @param    none
 * @return   Actual baud-rate of UART1
 */
uint32_t UART1_BaudRateGet(void);

/**
 * @ingroup  uartdriver
 * @brief    Returns the error status of UART1
 * @param    none
 * @return   Errors with masking as per \ref UART1_ERROR_MASKS
 */
size_t UART1_ErrorGet(void);

/**
 * @ingroup         uartdriver
 * @brief           This function can be used to override default callback 
 *                  \ref UART1_RxCompleteCallback and to define custom callback for 
 *                  UART1 RxComplete event.
 * @param[in][out]  Address of the callback routine
 * @return          none
 */
void UART1_RxCompleteCallbackRegister(void (*handler)(void));

/**
 * @ingroup  uartdriver
 * @brief    This is the default callback with weak attribute. The user can 
 *           override and implement the default callback without weak attribute 
 *           or can register a custom callback function using UART1_RxCompleteCallbackRegister.
 * @param    none
 * @return   none
 */
void UART1_RxCompleteCallback(void);

/**
 * @ingroup         uartdriver
 * @brief           This function can be used to override default callback 
 *                  \ref UART1_TxCompleteCallback and to define custom callback for 
 *                  UART1 TxComplete event.
 * @param[in][out]  Address of the callback routine
 * @return          none
 */
void UART1_TxCompleteCallbackRegister(void (*handler)(void));

/**
 * @ingroup  uartdriver
 * @brief    This is the default callback with weak attribute. The user can 
 *           override and implement the default callback without weak attribute 
 *           or can register a custom callback function using UART1_TxCompleteCallbackRegister.
 * @param    none
 * @return   none
 * @note            This callback is triggerred if there is data in the software buffer and there is atleast 
 *                  one byte space in hardware transmit FIFO 
 */
void UART1_TxCompleteCallback(void);

/**
 * @ingroup         uartdriver
 * @brief           This function can be used to override default callback 
 *                  \ref UART1_TxCollisionCallback and to define custom callback for 
 *                  UART1 TxCollision event.
 * @param[in][out]  Address of the callback routine
 * @return          none
 */
void UART1_TxCollisionCallbackRegister(void (*handler)(void));

/**
 * @ingroup  uartdriver
 * @brief    This is the default callback with weak attribute. The user can 
 *           override and implement the default callback without weak attribute 
 *           or can register a custom callback function using UART1_TxCollisionCallbackRegister.
 * @param    none
 * @return   none
 */
void UART1_TxCollisionCallback(void);

/**
 * @ingroup         uartdriver
 * @brief           This function can be used to override default callback 
 *                  \ref UART1_FramingErrorCallback and to define custom callback for 
 *                  UART1 FramingError event.
 * @param[in][out]  Address of the callback routine
 * @return          none
 */
void UART1_FramingErrorCallbackRegister(void (*handler)(void));

/**
 * @ingroup  uartdriver
 * @brief    This is the default callback with weak attribute. The user can 
 *           override and implement the default callback without weak attribute 
 *           or can register a custom callback function using UART1_FramingErrorCallbackRegister.
 * @param    none
 * @return   none
 */
void UART1_FramingErrorCallback(void);

/**
 * @ingroup         uartdriver
 * @brief           This function can be used to override default callback 
 *                  \ref UART1_OverrunErrorCallback and to define custom callback for 
 *                  UART1 OverrunError event.
 * @param[in][out]  Address of the callback routine
 * @return          none
 */
void UART1_OverrunErrorCallbackRegister(void (*handler)(void));

/**
 * @ingroup  uartdriver
 * @brief    This is the default callback with weak attribute. The user can 
 *           override and implement the default callback without weak attribute 
 *           or can register a custom callback function using UART1_OverrunErrorCallbackRegister.
 * @param    none
 * @return   none
 */
void UART1_OverrunErrorCallback(void);

/**
 * @ingroup         uartdriver
 * @brief           This function can be used to override default callback 
 *                  \ref UART1_ParityErrorCallback and to define custom callback for 
 *                  UART1 ParityError event.
 * @param[in][out]  Address of the callback routine
 * @return          none
 */
void UART1_ParityErrorCallbackRegister(void (*handler)(void));

/**
 * @ingroup  uartdriver
 * @brief    This is the default callback with weak attribute. The user can 
 *           override and implement the default callback without weak attribute 
 *           or can register a custom callback function using UART1_ParityErrorCallbackRegister.
 * @param    none
 * @return   none
 */
void UART1_ParityErrorCallback(void);
#endif  // UART1_H

