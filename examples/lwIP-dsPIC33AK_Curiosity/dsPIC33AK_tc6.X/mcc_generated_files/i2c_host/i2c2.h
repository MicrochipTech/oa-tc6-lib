/**
 * I2C2 Generated Driver Header File
 * 
 * @file      i2c2.h
 * 
 * @ingroup   i2chostdriver
 * 
 * @brief     This is the generated driver header file for the I2C2 driver
 *
 * @skipline @version   Firmware Driver Version 1.1.4
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

#ifndef I2C2_H
#define I2C2_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "i2c_host_types.h"
#include "i2c_host_interface.h"

// Section: Data Type Definitions
 
/**
 * @ingroup  i2chostdriver
 * @brief    Structure object of type I2C_HOST_INTERFACE with the custom name
 *           given by the user in the Melody Driver User interface. The default name 
 *           e.g. I2C1_Host can be changed by the user in the I2C user interface. 
 *           This allows defining a structure with application specific name using 
 *           the 'Custom Name' field. Application specific name allows the API Portability.
*/
extern const struct I2C_HOST_INTERFACE I2C2_Host;

/**
 * @ingroup  i2chostdriver  
 * @brief    This macro defines source clock frequency of I2C2
 */
#define I2C2_CLOCK_FREQUENCY                     100000000UL

/**
 * @ingroup  i2chostdriver  
 * @brief    This macro defines the Custom Name for \ref I2C2_Initialize API
 */
#define I2C2_Host_Initialize I2C2_Initialize
/**
 * @ingroup  i2chostdriver  
 * @brief    This macro defines the Custom Name for \ref I2C2_Deinitialize API
 */
#define I2C2_Host_Deinitialize I2C2_Deinitialize
/**
 * @ingroup  i2chostdriver  
 * @brief    This macro defines the Custom Name for \ref I2C2_Write API
 */
#define I2C2_Host_Write I2C2_Write
/**
 * @ingroup  i2chostdriver  
 * @brief    This macro defines the Custom Name for \ref I2C2_Read API
 */
#define I2C2_Host_Read I2C2_Read
/**
 * @ingroup  i2chostdriver  
 * @brief    This macro defines the Custom Name for \ref I2C2_WriteRead API
 */
#define I2C2_Host_WriteRead I2C2_WriteRead
/**
 * @ingroup  i2chostdriver  
 * @brief    This macro defines the Custom Name for \ref I2C2_TransferSetup API
 */
#define I2C2_Host_TransferSetup I2C2_TransferSetup
/**
 * @ingroup  i2chostdriver  
 * @brief    This macro defines the Custom Name for \ref I2C2_ErrorGet API
 */
#define I2C2_Host_ErrorGet I2C2_ErrorGet
/**
 * @ingroup  i2chostdriver  
 * @brief    This macro defines the Custom Name for \ref I2C2_CallbackRegister API
 */
#define I2C2_Host_CallbackRegister I2C2_CallbackRegister

/**
 * @ingroup  i2chostdriver
 * @brief    Initializes the I2C2 module
 * @param    none
 * @return   none
 */
void I2C2_Initialize(void);

/**
 * @ingroup  i2chostdriver
 * @brief    Deinitializes the I2C2 to POR values
 * @param    none
 * @return   none
 */
void I2C2_Deinitialize(void);

/**
 * @ingroup    i2chostdriver
 * @brief      Writes the data to a Client on the bus. The function will attempt to 
 *             write length number of bytes from data buffer to a Client whose address 
 *             is specified by address. The I2C Host will generate a Start condition, 
 *             write the data and then generate a Stop Condition. If the Client NACK 
 *             the request or a bus error was encountered on the bus, the transfer is 
 *             terminated. The application can call the I2C2_ErrorGet() function to know 
 *             that cause of the error. 
 *             
 *             The function is non-blocking. It initiates bus activity and returns 
 *             immediately. The transfer is then completed in the peripheral interrupt. 
 *             A transfer request cannot be placed when another transfer is in progress. 
 *             Calling the write function when another function is already in progress 
 *             will cause the function to return false.
 *             
 * @pre        none
 * @param[in]  address     -   7-bit / 10-bit Client address
 * @param[in]  data        -   pointer to source data buffer that contains the data 
 *             to be transmitted.
 * @param[in]  dataLength  - length of data buffer in number of bytes. Also the 
 *             number of bytes to be written.
 * @return     true  - The request was placed successfully and the bus activity was
 *             initiated.
 * @return     false - The request fails,if there was already a transfer in progress
 *             when this function was called.
 */
bool I2C2_Write(uint16_t address, uint8_t *data, size_t dataLength);

/**
 * @ingroup     i2chostdriver
 * @brief       Reads the data from a Client on the bus. The function will attempt 
 *              to read length number of bytes into data buffer from a Client whose 
 *              address is specified as address. The I2C Host generate a Start condition, 
 *              read the data and then generate a Stop Condition. If the Client NAKs 
 *              the request or a bus error is encountered on the bus, the transfer is 
 *              terminated. The application can call I2C2_ErrorGet() function to know 
 *              that cause of the error. 
 *              
 *              The function is non-blocking. It initiates bus activity and returns 
 *              immediately. The transfer is completed in the peripheral interrupt. 
 *              A transfer request cannot be placed when another transfer is in progress. 
 *              Calling the read function when another function is already in progress 
 *              will cause the function to return false.
 *              
 * @pre         none
 *              function to work.
 * @param[in]   address     - 7-bit / 10-bit Client address
 * @param[out]  data        - pointer to source data buffer that contains the data
 *              to be transmitted.
 * @param[in]   dataLength  - length of data buffer in number of bytes. Also the
 *              number of bytes to be written.
 * @return      true  - The request was placed successfully and the bus activity was 
 *              initiated.
 * @return      false - The request fails,if there was already a transfer in progress
 *              when this function was called.
 */
bool I2C2_Read(uint16_t address, uint8_t *data, size_t dataLength);

/**
 * @ingroup     i2chostdriver
 * @brief       Writes data from the writeData to the bus and then reads data from 
 *              the Client and stores the received in the readData. The function 
 *              generate a Start condition on the bus and will then send writeLength 
 *              number of bytes contained in writeData. The function will then insert 
 *              a Repeated start condition and proceed to read readLength number of 
 *              bytes from the client. The received bytes are stored in readData buffer. 
 *              A Stop condition is generated after the last byte has been received. 
 *              
 *              If the Client NAKs the request or a bus error was encountered on 
 *              the bus, the transfer is terminated. The application can call 
 *              I2C2_ErrorGet() function to know thatcause of the error. 
 *              
 *              The function is non-blocking. It initiates bus activity and returns 
 *              immediately. The transfer is then completed in the peripheral interrupt. 
 *              A transfer request cannot be placed when another transfer is in progress. 
 *              Calling this function when another function is already in progress 
 *              will cause the function to return false.
 *              
 * @pre         none
 * @param[in]   address      - 7-bit / 10-bit Client address
 * @param[in]   writeData    - pointer to write data buffer
 * @param[in]   writeLength  - write data length in bytes
 * @param[out]  readData    - pointer to read data buffer
 * @param[in]   readLength  - read data length in bytes
 * @return      true  - The request was placed successfully and the bus activity 
 *              was initiated.
 * @return      false - The request fails,if there was already a transfer in progress
 *              when this function was called.
 */
bool I2C2_WriteRead(uint16_t address, uint8_t *writeData, size_t writeLength, uint8_t *readData, size_t readLength);

/**
 * @ingroup    i2chostdriver
 * @brief      This function dynamically setup the I2C clock speed (100KHZ to 1MHZ)
 * @pre        none
 * @param[in]  setup 	  -  Pointer to the structure containing the transfer setup
 * @param[in]  srcClkFreq  -  I2C Peripheral Clock Source Frequency(FCY = FOSC/2)
 * @return     true  - Transfer setup was updated Successfully
 * @return     false - Failure while updating transfer setup
 */
bool I2C2_TransferSetup(struct I2C_TRANSFER_SETUP* setup, uint32_t srcClkFreq); 


/**
 * @ingroup  i2chostdriver
 * @brief    Returns the error occurred during I2C Transmit and Receive
 * @pre      none
 * @param    none
 * @return   I2C_HOST_ERROR_NONE          - No Error
 * @return   I2C_HOST_ERROR_NACK          - Client returned NACK
 * @return   I2C_HOST_ERROR_BUS_COLLISION - Bus Collision Error
 */
enum I2C_HOST_ERROR I2C2_ErrorGet(void);

/**
 * @ingroup  i2chostdriver
 * @brief    This function true if the I2C module is busy with 
 *           a transfer. The application can use the function to check if I2C 
 *           module is busy before calling any of the data transfer functions. 
 *           The library does not allow a data transfer operation if another 
 *           transfer  operation is already in progress.
 * @pre      none
 * @param    none
 * @return   true    - Busy
 * @return   false   - Not Busy
 */
bool I2C2_IsBusy(void);

/**
 * @ingroup    i2chostdriver
 * @brief      This function can be used to overrides default callback 
 *             \ref I2C2_HostCallback and to define custom callback for 
 *             I2C2 Host event.
 * @pre        none
 * @param[in]  address  -  Address of the callback function
 * @return     none
 */
void I2C2_CallbackRegister(void (*callback)(void));


/**
 * @ingroup  i2chostdriver
 * @brief    This is the default callback with weak attribute. The user can 
 *           override and implement the default callback without weak attribute 
 *           or can register a custom callback function using I2C2_CallbackRegister.
 * @pre      none
 * @param    none
 * @return   none
 */
void I2C2_Callback(void);

#endif


