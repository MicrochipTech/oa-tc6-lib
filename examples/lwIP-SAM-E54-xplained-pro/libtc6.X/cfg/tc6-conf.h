//DOM-IGNORE-BEGIN
/*
Copyright (C) 2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/
//DOM-IGNORE-END
/*******************************************************************************
  Configuration of Low Level Driver for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol

  Company:
    Microchip Technology Inc.
    
  File Name:
    tc6-conf.h

  Summary:
    Configuration of Low Level Driver TC6 SPI

  Description:
    This file provides the configuration of the OpenAlliance TC6 protocol
*******************************************************************************/

#ifndef TC6_CONFIG_H_
#define TC6_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/**
 * \brief Platform specific assertion call. Maybe defined to nothing
 */
#ifndef TC6_ASSERT
#ifdef DEBUG
#define TC6_ASSERT(condition)   __conditional_software_breakpoint(condition)
#else
#define TC6_ASSERT(condition)    
#endif
#endif

/**
 * \brief Set the maximum amount of parallel TC6 instances. 1 means a single MACPHY hardware is attached
 */
#ifndef TC6_MAX_INSTANCES
#define TC6_MAX_INSTANCES   (1u)
#endif

/**
 * \brief Defines the additional payload caused by the TC6 protocol (Footer or Header)
 * \note This value is defined by the Open Alliance, do not modify.
 */
#ifndef TC6_HEADER_SIZE
#define TC6_HEADER_SIZE     (4u)
#endif

/**
 * \brief Defines the data payload length of a single TC6 chunk
 * \note The only valid values are either 32 or 64
 */
#ifndef TC6_CHUNK_SIZE
#define TC6_CHUNK_SIZE      (64u)
#endif

/**
 * \brief Defines the entire payload length of a single TC6 chunk including header / footer.
 * \note Do not modify.
 */
#ifndef TC6_CHUNK_BUF_SIZE
#define TC6_CHUNK_BUF_SIZE  (TC6_CHUNK_SIZE + TC6_HEADER_SIZE)
#endif

/**
 * \brief Defines the maximum burst length of an SPI transfer. Meaning number of TC6 chunks with a single SPI transaction.
 * \note Depending on the situation, less chunks maybe transfered within a single transaction.
 */
#ifndef TC6_CHUNKS_XACT
#define TC6_CHUNKS_XACT     (24u)
#endif

/**
 * \brief Defines the maximum amount of simultaneous control register operations
 * \note Do not modify.
 */
#ifndef TC6_MAX_CNTRL_VARS
#define TC6_MAX_CNTRL_VARS  (1u)
#endif

#endif /* TC6_CONFIG_H_ */
