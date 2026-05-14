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
/*******************************************************************************
  lwIP Interface Driver for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol

  Company:
    Microchip Technology Inc.

  File Name:
    tc6-lwip.h

  Summary:
    lwIP Interface Driver for 10BASE-T1S MAC PHY

  Description:
    This file acts as a bridge between the TC6 library and the lwIP TCP/IP stack
*******************************************************************************/

#ifndef TC6_LWIP_H_
#define TC6_LWIP_H_

#include <stdint.h>
#include <stdbool.h>
#include "tc6.h"

#ifdef __cplusplus
extern "C" {
#endif

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define TC6LwIP_MTU                 (1518u) // Max MTU size including FCS
#define TC6LwIP_HOSTNAME            "tc6"
#define TC6LwIP_DHCP                (false)
#define TC6LwIP_NETMASK             "255.255.255.0"
#define TC6LwIP_GATEWAY             "192.168.0.1"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                            PUBLIC API                                */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/** \brief Initializes the lwIP Interface Driver for TC6.
 *  \note Must be called before any other functions of this component.
 *  \param ip - The 4 Byte ipV4 address.
 *  \enablePlca - true, if PLCA shall be enabled. false, PLCA is off, then nodeId, NodeCount, burstCount and burstTimer are getting ignored.
 *  \nodeId - When PLCA is enabled, this variable sets the PLCA Node Id.
 *  \nodeCount - When PLCA is enabled, this variable sets the PLCA Max Node Id.
 *  \burstCount - When PLCA is enabled, this variable sets the PLCA Burst Counter.
 *  \burstTimer - When PLCA is enabled, this variable sets the PLCA Burst Timer.
 *  \promiscuous - true, when RX MAC filter shall be turned off, then all messages are getting received (sniffing). false, filter is active, only messages with matching MACs (and broadcast/multicast) are getting received.
 *  \txCutThrough - true, when TX cut through shall be active, this helps improving speed further. Note that in that case the MCU/MPU must be able to send at full network speed. false, activates TX store and forward mode.
 *  \rxCutThrough - true, when RX cut through shall be active, this helps improving speed further. Note that in that case the MCU/MPU must be able to receive at full network speed. false, activates RX store and forward mode.
 *  \return The instance number of the current TC6LwIP driver. Starting at 0 and incrementing by one for any further call. Returns -1 when a instance can not be initialized, increase TC6_MAX_INSTANCES.
 */
int8_t TC6LwIP_Init(const uint8_t ip[4], bool enablePlca, uint8_t nodeId, uint8_t nodeCount, uint8_t burstCount, uint8_t burstTimer, bool promiscuous, bool txCutThrough, bool rxCutThrough);

/** \brief Services the hardware and the protocol stack.
 *  \note Must be called cyclic. The faster the better.
 */
void TC6LwIP_Service(void);

/** \brief Indicates the TC6 reset is complete and can be used.
 */
bool TC6_CB_ResetComplete(uint8_t tc6Instance);

/**
 * \brief Callback to the .
 * \note This function may be implemented by the integrator and passed as argument with TC6_SendRawEthernetPacket().
 * \param idx - The instance number as returned from the TC6LwIP_Init() function.
 * \param success - true, when the status could be successful retrieved. false, there was an error. plcaStatus variable may not reflect the real state.
 * \param plcaStatus - On success, this variable holds the current status of the PLCA. true, PLCA mode is active. false, running CSMA/CD mode
  */
typedef void (*TC6LwIP_On_PlcaStatus)(int8_t idx, bool success, bool plcaStatus);

/** \brief Queries the current PLCA status
 *  \param idx - The instance number as returned from the TC6LwIP_Init() function.
 *  \param pStatusCallback - Callback which holds the result. Must not be NULL.
 *  \return true, if request could be enqueued, the given callback will be called later. false, queue is full, callback will not be called, try again later.
 */
bool TC6LwIP_GetPlcaStatus(int8_t idx, TC6LwIP_On_PlcaStatus pStatusCallback);

/** \brief Checks if sending out an Ethernet message would block.
 *  \note This function is meant to be used to improve performance of an application. The socket application can use this function to quickly check if there is back pressure from the network.
 *  \param idx - The instance number as returned from the TC6LwIP_Init() function.
 *  \return true, the next sending attempt would fail because of back pressure from the network. false, sending will be successful.
 */
bool TC6LwIP_SendWouldBlock(int8_t idx);

/** \brief Get the MAC address of the given interface instance.
 *  \param idx - The instance number as returned from the TC6LwIP_Init() function.
 *  \param mac - Pointer to an 6 Byte array. The MAC address will be written to that.
 */
void TC6LwIP_GetMac(int8_t idx, uint8_t *mac[6]);

/** \brief Get the MAC address of the given interface instance.
 *  \param idx - The instance number as returned from the TC6LwIP_Init() function.
 */
struct netif *TC6LwIP_GetNetIf(int8_t idx);

/** \brief Sets the PLCA Node ID and the PLCA Node Count and can enable/disable PLCA.
 *  \param idx - The instance number as returned from the TC6LwIP_Init() function.
 *  \param plcaEnable - true, if PLCA shall be enabled. false, if CSMA/CD mode shall be used.
 *  \param nodeId - The new Node ID
 *  \param nodeCount - The new Node Count
 *  \return true, if request could be enqueued, the PLCA parameters will be changed soon. false, request failed, no change.
 */
bool TC6LwIP_SetPlca(int8_t idx, bool plcaEnable, uint8_t nodeId, uint8_t nodeCount);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                 Callback implementations from TC6 library            */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/**
 * \brief Callback when ever a slice of an Ethernet packet was received.
 * \note In most cases this function will not give an entire Ethernet frame. It will be only a piece of it. The integrator needs to combine it.
 * \param pInst - The pointer returned by TC6_Init.
 * \param pRx - Filled byte array holding the received Ethernet packet
 * \param offset - 0, if this is the start of a new Ethernet frame. Otherwise the offset to which this slide of payload belongs to.
 * \param len - Length of the byte array.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
void TC6_CB_OnRxEthernetSlice(TC6_t *pInst, const uint8_t *pRx, uint16_t offset, uint16_t len, void *pGlobalTag);

/**
 * \brief Callback when ever an Ethernet packet was received. This will notify the integrator, that now all chunks very reported by TC6_CB_OnRxEthernetPacket and the data can be processed.
 * \param pInst - The pointer returned by TC6_Init.
 * \param success - true, if the received Ethernet frame was received without errors. false, if there were errors.
 * \param len - Length of the entire Ethernet frame. This is all length reported TC6_CB_OnRxEthernetPacket combined.
 * \param rxTimestamp - Pointer to the receive timestamp, if there was any. NULL, otherwise. Pointer will be invalid after returning out of the callback!
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
void TC6_CB_OnRxEthernetPacket(TC6_t *pInst, bool success, uint16_t len, uint64_t *rxTimestamp, void *pGlobalTag);

/**
 * \brief Callback when ever an error occurred.
 * \param pInst - The pointer returned by TC6_Init.
 * \param err - Enumeration value holding the actual error condition.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
void TC6_CB_OnError(TC6_t *pInst, TC6_Error_t err, void *pGlobalTag);

/**
 * \brief Call to SPI driver to do bidirectional data transfer.
 * \param tc6instance - The instance number of the hardware. Starting with 0 for the first.
 * \param pTx - Pointer to the MOSI data. The pointer stays valid until user calls TC6_SpiBufferDone()
 * \param pRx - Pointer to the MISO Buffer. The pointer stays valid until user calls TC6_SpiBufferDone()
 * \param len - The length of both buffers (pTx and pRx). The entire length must be transfered via SPI.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 * \return true, if the SPI data was enqueued/transfered. false, there was an error.
 */
bool TC6_CB_OnSpiTransaction(uint8_t tc6instance, uint8_t *pTx, uint8_t *pRx, uint16_t len, void *pGlobalTag);

#ifdef __cplusplus
}
#endif
#endif /* TC6_LWIP_H_ */
