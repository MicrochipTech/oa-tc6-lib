//DOM-IGNORE-BEGIN
/*
Copyright (C) 2025, Microchip Technology Inc., and its subsidiaries. All rights reserved.

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

#ifndef __DMASPI_H__
#define	__DMASPI_H__

#include <xc.h>
#include <stdint.h>

/* DMA activity status. */
#define DMA_AVAILABLE       (0u)    // DMA is available for a transaction
#define DMA_BUSY            (0x55u) // DMA is busy executing a trnsaction

/* Defines the completion handler function prototype. */
typedef void (*dmaCompletionHandler)(void);

/**
 * @brief Initialize the DMA for use with SPI.
 * @param handler The DMA completion handler to register.
 */
void dmaSpiInit(dmaCompletionHandler handler);

/**
 * @brief Close the DMA.
 */
void dmaSpiClose(void);

/**
 * @brief Initiate a SPI transaction using the DMA.
 * @param pTx The transmit buffer to submit.
 * @param pRx The receive buffer to submit.
 * @param length The length of the transmit/receive buffers.
 * @return Nonzero for 'now busy', 0 for 'did not start'.
 */
uint8_t dmaSpiStartTransaction(uint8_t *pTx, uint8_t *pRx, uint16_t length);

/**
 * @brief Retrieve the current DMA activity status.
 * @return Nonzero for 'busy', 0 for 'did not start'.
 */
uint8_t dmaSpiGetStatus(void);

#endif	/* __DMASPI_H__ */

