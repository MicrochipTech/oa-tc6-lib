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
  Low Level Driver for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol

  Company:
    Microchip Technology Inc.

  File Name:
    tc6.h

  Summary:
    Low Level Driver TC6 SPI

  Description:
    This file provides the implementation of the OpenAlliance TC6 protocol
*******************************************************************************/

#ifndef TC6_H_
#define TC6_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                            DEFINITIONS                               */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define TC6_LIB_VER_MAJOR  (3U)
#define TC6_LIB_VER_MINOR  (1U)
#define TC6_LIB_VER_BUGFIX (3U)
#define TC6_LIB_VER_STRING "V3.1.3"

struct TC6_t;
typedef struct TC6_t TC6_t;

typedef enum
{
    TC6Error_Succeeded,         /** No error occurred */
    TC6Error_NoHardware,        /** MISO data implies that there is no MACPHY hardware available */
    TC6Error_UnexpectedSv,      /** Unexpected Start Valid Flag  */
    TC6Error_UnexpectedDvEv,    /** Unexpected Data Valid or End Valid Flag  */
    TC6Error_BadChecksum,       /** Checksum in footer is wrong */
    TC6Error_UnexpectedCtrl,    /** Unexpected control packet received */
    TC6Error_BadTxData,         /** Header Bad Flag received */
    TC6Error_SyncLost,          /** Sync Flag is no longer set */
    TC6Error_SpiError,          /** SPI transaction failed */
    TC6Error_ControlTxFail,     /** Control TX failure */
} TC6_Error_t;

typedef struct
{
    const uint8_t *pEth;        /** Pointer to the Ethernet packet segment */
    uint16_t segLen;            /** Length of the Ethernet packet segment */
} TC6_RawTxSegment;

/**
 * \brief Callback when ever a transmission of RAW Ethernet packet was finished.
 * \note This function may be implemented by the integrator and passed as argument with TC6_SendRawEthernetPacket().
 * \param pInst - The pointer returned by TC6_Init.
 * \param pTx - Exact the same pointer as has been given along with the TC6_SendRawEthernetPacket function.
 * \param len - Exact the same length as has been given along with the TC6_SendRawEthernetPacket function.
 * \param pTag - Tag pointer which was given along TC6_SendRawEthernetPacket function.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
typedef void (*TC6_RawTxCallback_t)(TC6_t *pInst, const uint8_t *pTx, uint16_t len, void *pTag, void *pGlobalTag);

/**
 * \brief Callback when ever a register access was finished.
 * \note This function may be implemented by the integrator and passed as argument with TC6_ReadRegister() or TC6_WriteRegister() or TC6_ReadModifyWriteRegister().
 * \note It is safe inside this callback to call again TC6_ReadRegister() or TC6_WriteRegister() or TC6_ReadModifyWriteRegister().
 * \param pInst - The pointer returned by TC6_Init.
 * \param success - true, if the register could be accessed without errors. false, there was an error while trying to access the register.
 * \param addr - The register address, as passed a long with TC6_ReadRegister() or TC6_WriteRegister() or TC6_ReadModifyWriteRegister().
 * \param value - The register value. If this belongs to a write request, it is the same value as given along with TC6_WriteRegister(). In case of a read, this holds the register read value. In case of TC6_ReadModifyWriteRegister() it holds the final value, which was written back into the MAC/PHY.
 * \param pTag - Tag pointer which was given along with the register access functions.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
typedef void (*TC6_RegCallback_t)(TC6_t *pInst, bool success, uint32_t addr, uint32_t value, void *pTag, void *pGlobalTag);

typedef enum {
    MemOp_Write = 0,
    MemOp_ReadModifyWrite = 1,
    MemOp_Read = 2
} MemoryOp_t;

/**
 * \brief Structure holding a register read/write
 */
typedef struct {
    uint32_t address;
    uint32_t value;
    uint32_t mask;
    MemoryOp_t op;
    bool secure;
} MemoryMap_t;

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PUBLIC API  (mandatory)                         */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/** \brief Initializes the lwIP Interface Driver for TC6.
 *  \param pGlobalTag - This pointer will be returned back with any callback of this component. Maybe set to NULL.
 *  \note Must be called before any other functions of this component.
 *  \return Filled structure for further usage with other functions of this component. Or NULL, if there was an error.
 */
TC6_t *TC6_Init(void *pGlobalTag);

/** \brief Services the hardware and the protocol stack.
 *  \note Must be called when a) TC6 Interrupt became active (level triggered) or b) when the TC6_CB_OnNeedService() callback was raised.
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param interruptLevel - The level of the interrupt pin. false is interpreted as interrupt active. true is interpreted as currently no interrupt issued.
 *  \return true, if all pending work has been done. false, there is still work to do, but currently not possible.
 */
bool TC6_Service(TC6_t *pInst, bool interruptLevel);

/** \brief Enables or disables outgoing / incoming data traffic.
 *  \note It make sense to enable data transfer, when configuring the registers is done.
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param interruptLevel - The level of the interrupt pin. false is interpreted as interrupt active. true is interpreted as currently no interrupt issued.
 */
void TC6_EnableData(TC6_t *pInst, bool enable);

/** \brief Sends a raw Ethernet packet.
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param pTx - Filled byte array holding an entire Ethernet packet. Warning, the buffer must stay valid until TC6_CB_OnTxRawEthernetPacket callback with this pointer as parameter was called.
 *  \param len - Length of the byte array.
 *  \param tsc - A TSC field value of zero indicates to the MACPHY that it shall not capture a timestamp for this packet.
 *               If TSC is [1..3], a timestamp will be captured for this packet will be captured into the corresponding TTSCAx register.
 *  \param txCallback - Callback function if desired, NULL otherwise.
 *  \param pTag - Any pointer the integrator wants to give. It will be returned in TC6_CB_OnTxRawEthernetPacket.
 *  \return true, on success. false, otherwise.
 */
bool TC6_SendRawEthernetPacket(TC6_t *pInst, const uint8_t *pTx, uint16_t len, uint8_t tsc, TC6_RawTxCallback_t txCallback, void *pTag);

/** \brief Delivers an array of raw segments. Integrator can link all Ethernet segments to form an entire Ethernet frame.
 *  \note  After filling out the array structure call TC6_SendRawEthernetSegments to send out all segments at once.
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param pSegments - Pointer of the raw segments will be written to the given address. NULL if there is no buffer available.
 *  \return TC6_TX_ETH_MAX_SEGMENTS if send buffer is available. 0, otherwise.
 */
uint8_t TC6_GetRawSegments(TC6_t *pInst, TC6_RawTxSegment **pSegments);

/** \brief Sends a raw Ethernet packet out of several Ethernet segments.
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param pSegments - Filled raw segment array, initial got by calling TC6_GetSendRawSegments function.
 *  \param segmentCount - Amount of Ethernet segments. At least 1, maximum TC6_TX_ETH_MAX_SEGMENTS.
 *  \param totalLen - Total length of entire Ethernet frame.
 *  \param tsc - A TSC field value of zero indicates to the MACPHY that it shall not capture a timestamp for this packet.
 *               If TSC is [1..3], a timestamp will be captured for this packet will be captured into the corresponding TTSCAx register.
 *  \param txCallback - Callback function if desired, NULL otherwise. Note, callback TX pointer will point to the first segment only.
 *  \param pTag - Any pointer the integrator wants to give. It will be returned in TC6_CB_OnTxRawEthernetPacket.
 *  \return true, on success. false, otherwise.
 */
bool TC6_SendRawEthernetSegments(TC6_t *pInst, const TC6_RawTxSegment *pSegments, uint8_t segmentCount, uint16_t totalLen, uint8_t tsc, TC6_RawTxCallback_t txCallback, void *pTag);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*          PUBLIC API (but not needed when using tc6-regs API)         */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/** \brief Reads from MAC / Phy registers
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param addr - The 32 Bit register offset.
 *  \param secure - true, enables protected control data transmission (normal + inverted data). false, no protection feature is used.
 *  \param rxCallback - Pointer to a callback handler. May left NULL.
 *  \param pTag - Any pointer. Will be given back in given rxCallback. May left NULL.
 *  \return true, on success. false, otherwise.
 */
bool TC6_ReadRegister(TC6_t *pInst, uint32_t addr, bool secure, TC6_RegCallback_t rxCallback, void *pTag);

/** \brief Writes to MAC / Phy registers
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param addr - The 32 Bit register offset.
 *  \param value - The new 32 Bit register value.
 *  \param secure - true, enables protected control data transmission (normal + inverted data). false, no protection feature is used.
 *  \param txCallback - Pointer to a callback handler. May left NULL.
 *  \param pTag - Any pointer. Will be given back in given txCallback. May left NULL.
 *  \return true, on success. false, otherwise.
 */
bool TC6_WriteRegister(TC6_t *pInst, uint32_t addr, uint32_t value, bool secure, TC6_RegCallback_t txCallback, void *pTag);

/** \brief Reads, modifies and writes back the changed value to MAC / Phy registers
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param addr - The 32 Bit register offset.
 *  \param value - The 32 Bit register bit values to be changed. This value will be set to register only if mask on the corresponding position is set to 1.
 *  \param mask - The 32 Bit register bit mask. Only Bits set to 1 will be changed accordingly to value.
 *  \param secure - true, enables protected control data transmission (normal + inverted data). false, no protection feature is used.
 *  \param modifyCallback - Pointer to a callback handler. May left NULL.
 *  \param pTag - Any pointer. Will be given back in given modifyCallback. May left NULL.
 *  \return true, on success. false, otherwise.
 */
bool TC6_ReadModifyWriteRegister(TC6_t *pInst, uint32_t addr, uint32_t value, uint32_t mask, bool secure, TC6_RegCallback_t modifyCallback, void *pTag);

/** \brief Execute a list of register commands
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param pMap - Array of memory commands
 *  \param mapLength - The length of the given array.
 *  \param multipleCallback - Pointer to a callback handler, it will be called for every single entry of the memory map. May left NULL.
 *  \param pTag - Any pointer. Will be given back in given modifyCallback. May left NULL.
 *  \return The amount of register commands enqueued. May return 0 when queue is total full. May return less then mapLength when queue is partly full.
 */
uint16_t TC6_MultipleRegisterAccess(TC6_t *pInst, const MemoryMap_t *pMap, uint16_t mapLength, TC6_RegCallback_t multipleCallback, void *pTag);


/** \brief Reenable the reporting of extended status flag via TC6_CB_OnExtendedStatus() callback.
 *  \note This feature was introduced to not trigger thousands of extended status callbacks, when there is a lot of traffic ongoing.
 *  \param pInst - The pointer returned by TC6_Init.
 */
void TC6_UnlockExtendedStatus(TC6_t *pInst);

/**
 * \brief The user must call this function once the SPI transaction is finished.
 * \note This function may be called direct in the implementation of TC6_CB_OnSpiTransaction, or any timer later and also from interrupt context.
 * \param tc6instance - The instance number of the hardware. Starting with 0 for the first.
 * \param success - true, if SPI transaction was successful. false, otherwise.
 */
void TC6_SpiBufferDone(uint8_t tc6instance, bool success);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PUBLIC API  (optional)                          */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/** \brief Destroy the given TC6 instance and release resources allocated by it.
 *  \param pInst - The pointer returned by TC6_Init.
 */
void TC6_Destroy(TC6_t *pInst);

/** \brief Reset all internal state machines and queues
 *  \param pInst - The pointer returned by TC6_Init.
 */
void TC6_Reset(TC6_t *pInst);

/** \brief Returns the TC6 related status variables such as TX and RX credit counter and if the controller is in sync state.
 *  \param pInst - The pointer returned by TC6_Init.
 *  \param pTxCredit - Pointer to a TX credit variable. This function writes the current TX credit value into this variable. NULL pointer is accepted.
 *  \param pRxCredit - Pointer to a RX credit variable. This function writes the current RX value into this variable. NULL pointer is accepted.
 *  \param pSynced - Pointer to a synced variable. This function writes the current synced state into this variable. NULL pointer is accepted.
 */
void TC6_GetState(TC6_t *pInst, uint8_t *pTxCredit, uint8_t *pRxCredit, bool *pSynced);

/** \brief Returns the current instance number of the given TC6 pointer
 *  \param pInst - The pointer returned by TC6_Init.
 *  \return Instance number, starting with 0 for the first instance
 */
uint8_t TC6_GetInstance(TC6_t *pInst);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                        CALLBACK SECTION                              */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/**
 * \brief Callback when ever this component needs to be serviced by calling TC6_Service()
 * \note This function must be implemented by the integrator.
 * \note Do not call TC6_Service() within this callback! Set a flag or raise an event to do it in the cyclic task context.
 * \warning !! THIS FUNCTION MAY GET CALLED FROM TASK AND INTERRUPT CONTEXT !!
 * \param pInst - The pointer returned by TC6_Init.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
extern void TC6_CB_OnNeedService(TC6_t *pInst, void *pGlobalTag);

/**
 * \brief Callback when ever a slice of an Ethernet packet was received.
 * \note This function must be implemented by the integrator.
 * \note In most cases this function will not give an entire Ethernet frame. It will be only a piece of it. The integrator needs to combine it.
 * \param pInst - The pointer returned by TC6_Init.
 * \param pRx - Filled byte array holding the received Ethernet packet
 * \param offset - 0, if this is the start of a new Ethernet frame. Otherwise the offset to which this slide of payload belongs to.
 * \param len - Length of the byte array.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
extern void TC6_CB_OnRxEthernetSlice(TC6_t *pInst, const uint8_t *pRx, uint16_t offset, uint16_t len, void *pGlobalTag);

/**
 * \brief Callback when ever an Ethernet packet was received. This will notify the integrator, that now all chunks very reported by TC6_CB_OnRxEthernetPacket and the data can be processed.
 * \note This function must be implemented by the integrator.
 * \param pInst - The pointer returned by TC6_Init.
 * \param success - true, if the received Ethernet frame was received without errors. false, if there were errors.
 * \param len - Length of the entire Ethernet frame. This is all length reported TC6_CB_OnRxEthernetPacket combined.
 * \param rxTimestamp - Pointer to the receive timestamp, if there was any. NULL, otherwise. Pointer will be invalid after returning out of the callback!
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
extern void TC6_CB_OnRxEthernetPacket(TC6_t *pInst, bool success, uint16_t len, uint64_t *rxTimestamp, void *pGlobalTag);

/**
 * \brief Callback when ever an error occurred.
 * \note This function must be implemented by the integrator.
 * \param pInst - The pointer returned by TC6_Init.
 * \param err - Enumeration value holding the actual error condition.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
extern void TC6_CB_OnError(TC6_t *pInst, TC6_Error_t err, void *pGlobalTag);

/**
 * \brief Callback when ever TC6 packet was received, which had the extended flag set. This means, that the user should read (and clear) at least Status0 and Status1 registers.
 * \note The integrator MUST call TC6_UnlockExtendedStatus() whenever he is ready to process the next extended status flag. Reenabling it to early may trigger thousands of events per second.
 * \note This function must be implemented by the integrator.
 * \param pInst - The pointer returned by TC6_Init.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 */
extern void TC6_CB_OnExtendedStatus(TC6_t *pInst, void *pGlobalTag);

/**
 * \brief Users implementation of SPI transfer function.
 * \note The implementation may be synchronous or asynchronous. But in any case the TC6_SpiBufferDone() must be called, when the SPI transaction is over!
 * \param tc6instance - The instance number of the hardware. Starting with 0 for the first.
 * \param pTx - Pointer to the MOSI data. The pointer stays valid until user calls TC6_SpiBufferDone()
 * \param pRx - Pointer to the MISO Buffer. The pointer stays valid until user calls TC6_SpiBufferDone()
 * \param len - The length of both buffers (pTx and pRx). The entire length must be transfered via SPI.
 * \param pGlobalTag - The exact same pointer, which was given along with the TC6_Init() function.
 * \return true, if the SPI data was enqueued/transfered. false, there was an error.
 */
extern bool TC6_CB_OnSpiTransaction(uint8_t tc6instance, uint8_t *pTx, uint8_t *pRx, uint16_t len, void *pGlobalTag);

#ifdef __cplusplus
}
#endif
#endif /* TC6_H_ */
