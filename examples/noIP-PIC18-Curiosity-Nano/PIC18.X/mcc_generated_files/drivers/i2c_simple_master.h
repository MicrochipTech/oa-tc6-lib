/**
\file
\defgroup doc_driver_i2c_code I2C Simple Driver Source Code Reference
\ingroup doc_driver_i2c
\brief This file contains the API that implements the I2C simple master driver functionalities.

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

#ifndef I2C_SIMPLE_MASTER_H
#define	I2C_SIMPLE_MASTER_H

#include <stdint.h>
#include <stdio.h>
#include ".././i2c1_master.h"

uint8_t i2c_read1ByteRegister(i2c1_address_t address, uint8_t reg);
uint16_t i2c_read2ByteRegister(i2c1_address_t address, uint8_t reg);
void i2c_write1ByteRegister(i2c1_address_t address, uint8_t reg, uint8_t data);
void i2c_write2ByteRegister(i2c1_address_t address, uint8_t reg, uint16_t data);

void i2c_writeNBytes(i2c1_address_t address, void* data, size_t len);
void i2c_readDataBlock(i2c1_address_t address, uint8_t reg, void *data, size_t len);
void i2c_readNBytes(i2c1_address_t address, void *data, size_t len);

#endif	/* I2C_SIMPLE_MASTER_H */

