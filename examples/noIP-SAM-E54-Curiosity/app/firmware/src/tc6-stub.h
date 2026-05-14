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
  MCU specific stub code for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol

  Company:
    Microchip Technology Inc.

  File Name:
    tc6-stub.h

  Summary:
    MCU specifc stub code

  Description:
    This file acts as a bridge between the TC6 library and the Board Support Package
    for the dedicated MCU
*******************************************************************************/

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                             PUBLIC API                               */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/** \brief Initializes the Hardware depended stub driver
 *  \note Must be called before any other functions of this component.
 *  \param idx - The instance number of the hardware. Starting with 0 for the first hardware.
 *  \pMac - When Init was successful, the MAC address from the hardware will be written to this pointer.
 *  \return true, if the hardware was initialized successful. false, otherwise.
 */
bool TC6Stub_Init(uint8_t idx, uint8_t pMac[6]);

/** \brief Checks if the LAN865x Int Pin was active. The information stays sticky until TC6Stub_ReleaseInt() is getting called.
 *  \param idx - The instance number of the hardware. Starting with 0 for the first hardware.
 *  \return true, the Int Pin has been seen active. false, Int Pin was not active.
 */
bool TC6Stub_IntActive(uint8_t idx);

/** \brief Clear the sticky Int Pin information.
 *  \note This function shall only be called, when TC6Stub_IntActive() had reported true.
 *  \param idx - The instance number of the hardware. Starting with 0 for the first hardware.
 */
void TC6Stub_ReleaseInt(uint8_t idx);

/** \brief Gets the current system time in milliseconds.
 * \return System ticks in milliseconds.
 */
uint32_t TC6Stub_GetTick(void);

/**
 * \brief Hardware implementation of SPI transfer function.
 * \param idx - The instance number of the hardware. Starting with 0 for the first hardware.
 * \param pTx - Pointer to the MOSI data. The pointer stays valid until user calls TC6_SpiBufferDone()
 * \param pRx - Pointer to the MISO Buffer. The pointer stays valid until user calls TC6_SpiBufferDone()
 * \param len - The length of both buffers (pTx and pRx). The entire length must be transfered via SPI.
 * \return true, if the SPI data was enqueued/transfered. false, there was an error.
 */
bool TC6Stub_SpiTransaction(uint8_t idx, uint8_t *pTx, uint8_t *pRx, uint16_t len);