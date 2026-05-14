/**
\file
\addtogroup doc_driver_i2c_code
\brief This file provides some basic blocking helper functions for common operations on the I2C API

\copyright (c) 2020 Microchip Technology Inc. and its subsidiaries.
\page License
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/


#include ".././i2c1_master.h"
#include "i2c_simple_master.h"

/****************************************************************/
static i2c1_operations_t wr1RegCompleteHandler(void *p)
{
    I2C1_SetBuffer(p,1);
    I2C1_SetDataCompleteCallback(NULL,NULL);
    return I2C1_CONTINUE;
}

/**
 *  \ingroup doc_driver_i2c_code
 *  \brief Function to write 1 byte of data to a register location
 *
 *  \param [in] address [type]i2c_address_t The slave address
 *         [in] reg     [type]uint8_t The register address to be written to
 *         [in] data    [type]uint8_t The data to be written
 *
 *  \return None
 */
void i2c_write1ByteRegister(i2c1_address_t address, uint8_t reg, uint8_t data)
{
    while(!I2C1_Open(address)); // sit here until we get the bus..
    I2C1_SetDataCompleteCallback(wr1RegCompleteHandler,&data);
    I2C1_SetBuffer(&reg,1);
    I2C1_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
}

/**
 *  \ingroup doc_driver_i2c_code
 *  \brief Function to write N byte of data
 *
 *  \param [in] address [type]i2c_address_t Slave address
 *         [in] data    [type]uint8_t Array of data to be send
 *         [in] len     [type]uint8_t The size of the array
 *
 *  \return None
 */
void i2c_writeNBytes(i2c1_address_t address, void* data, size_t len)
{
    while(!I2C1_Open(address)); // sit here until we get the bus..
    I2C1_SetBuffer(data,len);
    I2C1_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
}

/****************************************************************/
static i2c1_operations_t rd1RegCompleteHandler(void *p)
{
    I2C1_SetBuffer(p,1);
    I2C1_SetDataCompleteCallback(NULL,NULL);
    return I2C1_RESTART_READ;
}

/**
 *  \ingroup doc_driver_i2c_code
 *  \brief Function to read 1 byte of data from a register location
 *
 *  \param [in] address [type]i2c_address_t Slave address
 *         [in] reg     [type]uint8_t The register address to be read
 *
 *  \return [out] The read data byte
 */
uint8_t i2c_read1ByteRegister(i2c1_address_t address, uint8_t reg)
{
    uint8_t    d2=42;
    i2c1_error_t e;
    int x;

    for(x = 2; x != 0; x--)
    {
        while(!I2C1_Open(address)); // sit here until we get the bus..
        I2C1_SetDataCompleteCallback(rd1RegCompleteHandler,&d2);
        I2C1_SetBuffer(&reg,1);
        I2C1_SetAddressNackCallback(NULL,NULL); //NACK polling?
        I2C1_MasterWrite();
        while(I2C1_BUSY == (e = I2C1_Close())); // sit here until finished.
        if(e==I2C1_NOERR) break;
    }


    return d2;
}

/****************************************************************/
static i2c1_operations_t rd2RegCompleteHandler(void *p)
{
    I2C1_SetBuffer(p,2);
    I2C1_SetDataCompleteCallback(NULL,NULL);
    return I2C1_RESTART_READ;
}

/**
 *  \ingroup doc_driver_i2c_code
 *  \brief Function to read 2 byte of data from a register location
 *
 *  \param [in] address [type]i2c_address_t Slave address
 *         [in] reg     [type]uint8_t The register address to be read
 *
 *  \return [out] The read 2 bytes of data
 */
uint16_t i2c_read2ByteRegister(i2c1_address_t address, uint8_t reg)
{
    // result is little endian
    uint16_t    result = UINT16_MAX;
    while(!I2C1_Open(address)); // sit here until we get the bus..
    I2C1_SetDataCompleteCallback(rd2RegCompleteHandler,&result);
    I2C1_SetBuffer(&reg,1);
    I2C1_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.

    return (result << 8 | result >> 8);
}

/****************************************************************/
static i2c1_operations_t wr2RegCompleteHandler(void *p)
{
    I2C1_SetBuffer(p,2);
    I2C1_SetDataCompleteCallback(NULL,NULL);
    return I2C1_CONTINUE;
}

/**
 *  \ingroup doc_driver_i2c_code
 *  \brief Function to write 1 byte of data to a register location
 *
 *  \param [in] address [type]i2c_address_t The slave address
 *         [in] reg     [type]uint8_t The register address to be written to
 *         [in] data    [type]uint8_t The data to be written
 *
 *  \return None
 */
void i2c_write2ByteRegister(i2c1_address_t address, uint8_t reg, uint16_t data)
{
    while(!I2C1_Open(address)); // sit here until we get the bus..
    I2C1_SetDataCompleteCallback(wr2RegCompleteHandler,&data);
    I2C1_SetBuffer(&reg,1);
    I2C1_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
}

/****************************************************************/
typedef struct
{
    size_t len;
    char *data;
}buf_t;

static i2c1_operations_t rdBlkRegCompleteHandler(void *p)
{
    I2C1_SetBuffer(((buf_t *)p)->data,((buf_t*)p)->len);
    I2C1_SetDataCompleteCallback(NULL,NULL);
    return I2C1_RESTART_READ;
}

/**
 *  \ingroup doc_driver_i2c_code
 *  \brief Function to read block of data from a register location
 *
 *  \param [in] address [type]i2c_address_t Slave address
 *         [in] reg     [type]uint8_t The register address to be read
 *         [out] data   [type]void* The read data block
 *         [in] len     [type]size_t The size of data block
 *
 *  \return None
 */
void i2c_readDataBlock(i2c1_address_t address, uint8_t reg, void *data, size_t len)
{
    // result is little endian
    buf_t    d;
    d.data = data;
    d.len = len;

    while(!I2C1_Open(address)); // sit here until we get the bus..
    I2C1_SetDataCompleteCallback(rdBlkRegCompleteHandler,&d);
    I2C1_SetBuffer(&reg,1);
    I2C1_SetAddressNackCallback(NULL,NULL); //NACK polling?
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
}

/**
 *  \ingroup doc_driver_i2c_code
 *  \brief Function to read N bytes of data
 *
 *  \param [in] address [type]i2c_address_t Slave address
 *         [out] data   [type]void* The read data block
 *         [in] len     [type]size_t The size of data block
 *
 *  \return None
 */
void i2c_readNBytes(i2c1_address_t address, void *data, size_t len)
{
    while(!I2C1_Open(address)); // sit here until we get the bus..
    I2C1_SetBuffer(data,len);
    I2C1_MasterRead();
    while(I2C1_BUSY == I2C1_Close()); // sit here until finished.
}
