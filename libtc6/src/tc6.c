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
    tc6.c

  Summary:
    Low Level Driver TC6 SPI

  Description:
    This file provides the implementation of the OpenAlliance TC6 protocol
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "tc6-conf.h"
#include "tc6.h"
#include "tc6-queue.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define TC6_MAGIC           (0x48423578ul)
#define TC6_CHUNKS_PER_ISR  (2u)

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                    INTERNAL DEFINES AND VARIABLES                    */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define FLD(bytePos, bitpos, width)  bytePos, bitpos, width

/*
 * TX Data Header: 32-bit SPI TX Data Chunk Command Header
 */


/* Data fields {{{ */

#define HDR_DNC   FLD(0u, 7u, 1u) /* Data, Not Control */
#define HDR_SEQ   FLD(0u, 6u, 1u) /* Data Chunk Sequence */
/*#define HDR_NORX FLD(0u, 5u, 1u)  No Receive */
/*#define HDR_VS  FLD(1u, 6u, 2u)    VS */
#define HDR_DV    FLD(1u, 5u, 1u) /* Data Valid */
#define HDR_SV    FLD(1u, 4u, 1u) /* Start of Frame Valid */
#define HDR_SWO   FLD(1u, 0, 4u) /* Start of Frame Word Offset */
#define HDR_EV    FLD(2u, 6u, 1u) /* End of Frame Valid */
#define HDR_EBO   FLD(2u, 0u, 6u) /* End of Frame Byte Offset */
#define HDR_TSC   FLD(3u, 6u, 2u) /* Transmit Frame Timestamp Capture */
#define HDR_P     FLD(3u, 0u, 1u) /* Header Parity Bit */

/* }}} */

/* Control Transaction fields {{{ */

#define HDR_C_DNC    FLD(0u, 7u, 1u) /* Data, Not Control */
/*#define HDR_C_HDRB FLD(0u, 6u, 1u)  TX Header Bad */
#define HDR_C_WNR    FLD(0u, 5u, 1u) /* Write, Not Read */
#define HDR_C_AID    FLD(0u, 4u, 1u) /* Address Increment Disable */
#define HDR_C_MMS    FLD(0u, 0u, 4u) /* Memory Map Selector */
#define HDR_C_ADDR_HI FLD(1u, 0u, 8u) /* Address Higher Byte */
#define HDR_C_ADDR_LO FLD(2u, 0u, 8u) /* Address Lower Byte */
#define HDR_C_LEN    FLD(3u, 1u, 7u) /* Length */
#define HDR_C_P      FLD(3u, 0u, 1u) /* Parity Bit */

/* }}} */

/*
 * RX Data Footer: 36-bit SPI RX Data Chunk Command Footer
 */

#define FTR_EXST     FLD(0u, 7u, 1u) /* Extended Status */
#define FTR_HDRB     FLD(0u, 6u, 1u) /* TX Header Bad */
#define FTR_SYNC     FLD(0u, 5u, 1u) /* Configuration Synchronized */
#define FTR_RCA      FLD(0u, 0u, 5u) /* Receive Chunks Available */
/*#define FTR_VS     FLD(1u, 6u, 2u)    Vendor Specific */
#define FTR_DV       FLD(1u, 5u, 1u) /* Data Valid */
#define FTR_SV       FLD(1u, 4u, 1u) /* Start of Frame Valid */
#define FTR_SWO      FLD(1u, 0u, 4u) /* Start of Frame Word Offset */
#define FTR_FD       FLD(2u, 7u, 1u) /* Frame Drop */
#define FTR_EV       FLD(2u, 6u, 1u) /* End of Frame Valid */
#define FTR_EBO      FLD(2u, 0u, 6u) /* End of Frame Byte Offset */
#define FTR_RTSA     FLD(3u, 7u, 1u) /* Receive Frame Timestamp Added */
#define FTR_RTSP     FLD(3u, 6u, 1u) /* Receive Frame Timestamp Parity */
#define FTR_TXC      FLD(3u, 1u, 5u) /* Transmit Credits */
/*#define FTR_P      FLD(3u, 0u, 1u)    Footer Parity Bit */

static const uint8_t MASK[9] = { 0x00u, 0x01u, 0x03u, 0x07u, 0x0Fu, 0x1Fu, 0x3Fu, 0x7Fu, 0xFFu };

typedef enum
{ SPI_OP_INVALID,
  SPI_OP_DATA,
  SPI_OP_REG
} SpiOp_t;

/** Integrator needs to allocate this structure. But the elements must not be accessed.
 *  They are getting filled via function calls only.
 */
struct TC6_t
{
    struct qtxeth tx_eth_buffer[TC6_TX_ETH_QSIZE];
    struct qspibuf spiBuf[SPI_FULL_BUFFERS];
    struct qtxeth_queue eth_q;
    struct qspibuf_queue qSpi;
    struct register_operation regop_storage[REG_OP_ARRAY_SIZE];
    struct regop_queue regop_q;
    void *gTag;
    uint64_t ts;
    volatile SpiOp_t currentOp;
    uint32_t magic;
    uint16_t buf_len;
    uint16_t offsetEth;
    uint16_t offsetRx;
    uint16_t segOffset;
    uint8_t segCurr;
    uint8_t instance;
    uint8_t seq_num;
    uint8_t txc;
    uint8_t rca;
    bool alreadyInControlService;
    bool alreadyInDataService;
    bool enableData;
    bool intContext;
    bool synced;
    bool exst_locked;
    bool eth_started;
    bool eth_error;
};

static struct TC6_t m_tc6[TC6_MAX_INSTANCES];
static volatile bool m_tc6Valid[TC6_MAX_INSTANCES] = { 0 };

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      PRIVATE FUNCTION PROTOTYPES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static inline uint8_t GET_VAL(uint8_t bytePos, uint8_t bitpos, uint8_t width, const uint8_t pIn[4]);
static inline void SET_VAL(uint8_t bytePos, uint8_t bitpos, uint8_t width, uint8_t val, uint8_t pOut[4]);
static void initializeSpiEntry(struct qspibuf *newEntry);
static uint16_t getTrail(TC6_t *g, bool enqueueEmpty);
static void addEmptyChunks(TC6_t *g, struct qspibuf *entry, bool enqueueEmpty);
static bool serviceData(TC6_t *g, bool enqueueEmpty);
static bool serviceControl(TC6_t *g);
static bool spiTransaction(TC6_t *g, uint8_t *pTx, uint8_t *pRx, uint16_t len, SpiOp_t op);
static bool modify(TC6_t *g, uint32_t value);
static bool accessRegisters(TC6_t *g, enum register_op_type op, uint32_t addr, uint32_t value,
                            bool secure, uint32_t modifyMask, TC6_RegCallback_t callback, void *tag);
static void processDataRx(TC6_t *g);

/* Protocol Implementation */
static uint16_t mk_ctrl_req(bool wnr, bool aid, uint32_t addr, uint8_t num_regs, const uint32_t *regs, uint8_t *buff, uint16_t size_of_buff);
static uint16_t mk_secure_ctrl_req(bool wnr, bool aid, uint32_t addr, uint8_t num_regs, const uint32_t *regs, uint8_t *buff, uint16_t size_of_buff);
static uint16_t read_rx_ctrl_buffer(const uint8_t *rx_buf, uint16_t rx_buf_size, uint32_t *regs_buf, uint8_t regs_buf_size, bool secure);
static uint16_t mk_data_tx(TC6_t *g, uint8_t *tx_buf, uint16_t tx_buf_len);
static void enqueue_rx_spi(TC6_t *g, const uint8_t *buff, uint16_t buf_len);
static void update_credit_cnt(TC6_t *g, const uint8_t *buff, uint16_t buf_len);

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PUBLIC FUNCTIONS                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

TC6_t *TC6_Init(void *pGlobalTag)
{
    uint8_t i;
    struct TC6_t *g = NULL;
    for (i = 0; i < TC6_MAX_INSTANCES; i++) {
        if (!m_tc6Valid[i]) {
            /* Setup memory */
            m_tc6Valid[i] = true;
            g = &m_tc6[i];
            (void)memset(g, 0, sizeof(TC6_t));
            g->instance = i;
            g->magic = TC6_MAGIC;
            g->txc = 24;
            g->gTag = pGlobalTag;
            init_qtxeth_queue(&g->eth_q, g->tx_eth_buffer, TC6_TX_ETH_QSIZE);
            init_qspibuf_queue(&g->qSpi, g->spiBuf, SPI_FULL_BUFFERS);
            init_regop_queue(&g->regop_q, g->regop_storage, REG_OP_ARRAY_SIZE);
            break;
        }
    }
    if (!g) {
        TC6_ASSERT(false);
    }
    return g;
}

void TC6_Destroy(TC6_t *g)
{
    uint8_t i;
    TC6_Reset(g);
    for (i = 0; i < TC6_MAX_INSTANCES; i++) {
        if (g == &m_tc6[i]) {
            m_tc6Valid[i] = false;
            break;
        }
    }
}

void TC6_Reset(TC6_t *g)
{
    struct qtxeth_queue *qEth = &g->eth_q;
    struct regop_queue *qReg = &g->regop_q;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));

    /* Wait for pending SPI transactions */
    while(SPI_OP_INVALID != g->currentOp) {};

    /* Callback Ethernet Data Event listeners */
    while (qtxeth_stage2_convert_ready(qEth)) {
        struct qtxeth *entry = qtxeth_stage2_convert_ptr(qEth);
        if (NULL != entry->txCallback) {
            entry->txCallback(g, entry->ethSegs[0].pEth, entry->ethSegs[0].segLen, entry->priv, g->gTag);
        }
        qtxeth_stage2_convert_done(qEth);
    }
    while(regop_stage2_send_ready(qReg)) {
        regop_stage2_send_done(qReg);
    }
    while(regop_stage3_int_ready(qReg)) {
        regop_stage3_int_done(qReg);
    }
    while(regop_stage4_modify_ready(qReg)) {
        regop_stage4_modify_done(qReg);
    }
    while(regop_stage5_send_ready(qReg)) {
        regop_stage5_send_done(qReg);
    }
    while(regop_stage6_int_ready(qReg)) {
        regop_stage6_int_done(qReg);
    }
    while(regop_stage7_event_ready(qReg)) {
        struct register_operation *entry = regop_stage7_event_ptr(qReg);
        if (NULL != entry->callback) {
           entry->callback(g, false, entry->regAddr, 0u, entry->tag, g->gTag);
        }
        regop_stage7_event_done(qReg);
    }
    if (g->eth_started) {
        TC6_CB_OnRxEthernetPacket(g, false, 0, NULL, g->gTag);
    }

    /* Set protocol defaults */
    g->txc = 24u;
    g->enableData = false;
    g->synced = false;
}

bool TC6_Service(TC6_t *g, bool interruptLevel)
{
    bool intPending = false;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    if (!g->intContext) {
        if (serviceControl(g)) {
           if (!interruptLevel) {
               intPending = true;
           }
        } else if (g->enableData) {
            processDataRx(g);
            if (!serviceData(g, !interruptLevel)) {
                if (!interruptLevel) {
                   intPending = true;
                }
            }
            processDataRx(g);
        } else if (!interruptLevel) {
            intPending = true;
        } else {} /* MISRA enforced termination */
    }
    return !intPending;
}

void TC6_EnableData(TC6_t *g, bool enable)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    g->enableData = enable;
    if (g->enableData && !g->intContext) {
        (void)serviceData(g, true);
    }
}

uint8_t TC6_GetInstance(TC6_t *g)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    return g ? g->instance : 0xFFu;
}

void TC6_GetState(TC6_t *g, uint8_t *pTxCredit, uint8_t *pRxCredit, bool *pSynced)
{
   TC6_ASSERT(g && (TC6_MAGIC == g->magic));
   if (NULL != pTxCredit) {
      *pTxCredit = g->txc;
   }
   if (NULL != pRxCredit) {
      *pRxCredit = g->rca;
   }
   if (NULL != pSynced) {
      *pSynced = g->synced;
   }
}

bool TC6_SendRawEthernetPacket(TC6_t *g, const uint8_t *pTx, uint16_t len, uint8_t tsc, TC6_RawTxCallback_t txCallback, void *pTag)
{
    bool success = true;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    if (!g || !pTx || !len) {
        TC6_ASSERT(false);
        success = false;
    }
    if (success && g->enableData) {
        struct qtxeth_queue *q = &g->eth_q;

        success = false;
        if (qtxeth_stage1_enqueue_ready(q)) {
            struct qtxeth *entry = qtxeth_stage1_enqueue_ptr(q);
            entry->ethSegs[0].pEth = pTx;
            entry->ethSegs[0].segLen = len;
            entry->totalLen = len;
            entry->segCount = 1;
            entry->tsc = tsc;
            entry->txCallback = txCallback;
            entry->priv = pTag;
            qtxeth_stage1_enqueue_done(q);

            if (!g->intContext) {
                (void)serviceData(g, false);
            }
            success = true;
        }
    } else {
        success = false;
    }
    return success;
}

uint8_t TC6_GetRawSegments(TC6_t *g, TC6_RawTxSegment **pSegments)
{
    bool success = false;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic) && pSegments);
    if (g->enableData) {
        struct qtxeth_queue *q = &g->eth_q;
        struct qtxeth *entry;
        if (qtxeth_stage1_enqueue_ready(q)) {
            entry = qtxeth_stage1_enqueue_ptr(q);
#ifdef DEBUG
            (void)memset(entry, 0xCDu, sizeof(struct qtxeth));
#endif
            *pSegments = entry->ethSegs;
            success = true;
        }
    }
    return (success ? TC6_TX_ETH_MAX_SEGMENTS : 0u);
}

bool TC6_SendRawEthernetSegments(TC6_t *g, const TC6_RawTxSegment *pSegments, uint8_t segmentCount, uint16_t totalLen, uint8_t tsc, TC6_RawTxCallback_t txCallback, void *pTag)
{
    struct qtxeth_queue *q = &g->eth_q;
    bool success = false;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    TC6_ASSERT(segmentCount && pSegments && (segmentCount <= TC6_TX_ETH_MAX_SEGMENTS) && qtxeth_stage1_enqueue_ready(q));
    (void)pSegments;
    if (g->enableData) {
        struct qtxeth *entry = qtxeth_stage1_enqueue_ptr(q);

        TC6_ASSERT(entry->ethSegs == pSegments);
        entry->segCount = segmentCount;
        entry->totalLen = totalLen;
        entry->tsc = tsc;
        entry->txCallback = txCallback;
        entry->priv = pTag;
        qtxeth_stage1_enqueue_done(q);
        if (!g->intContext) {
            (void)serviceData(g, false);
        }
        success = true;
    }
    return success;
}

bool TC6_ReadRegister(TC6_t *g, uint32_t addr, bool secure, TC6_RegCallback_t rxCallback, void *tag)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    return accessRegisters(g, REGISTER_OP_READ, addr
        , 0    /* value */
        , secure
        , 0    /* mask */
        , rxCallback
        , tag);
}

bool TC6_WriteRegister(TC6_t *g, uint32_t addr, uint32_t value, bool secure, TC6_RegCallback_t txCallback, void *tag)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    return accessRegisters(g, REGISTER_OP_WRITE, addr
        , value
        , secure
        , 0    /* mask */
        , txCallback
        , tag);
}

bool TC6_ReadModifyWriteRegister(TC6_t *g, uint32_t addr, uint32_t value, uint32_t mask, bool secure, TC6_RegCallback_t modifyCallback, void *tag)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    return accessRegisters(g, REGISTER_OP_READWRITE_STAGE1, addr
        , value
        , secure
        , mask
        , modifyCallback
        , tag);
}

uint16_t TC6_MultipleRegisterAccess(TC6_t *g, const MemoryMap_t *pMap, uint16_t mapLength, TC6_RegCallback_t multipleCallback, void *pTag)
{
    uint16_t i = 0;
    uint16_t t = 0;
    bool full = false;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    for (; (i < mapLength) && !full; i++) {
        switch(pMap[i].op) {
        case MemOp_Write:
            if (accessRegisters(g, REGISTER_OP_WRITE, pMap[i].address
                , pMap[i].value
                , pMap[i].secure
                , 0                 /* mask */
                , multipleCallback
                , pTag))
            {
                t++;
            } else {
                full = true;
            }
            break;
        case MemOp_ReadModifyWrite:
            if (accessRegisters(g, REGISTER_OP_READWRITE_STAGE1, pMap[i].address
                , pMap[i].value
                , pMap[i].secure
                , pMap[i].mask
                , multipleCallback
                , pTag))
            {
                t++;
            } else {
                full = true;
            }
            break;
        case MemOp_Read:
            if (accessRegisters(g, REGISTER_OP_READ, pMap[i].address
                , 0                 /* value */
                , pMap[i].secure
                , 0                 /* mask */
                , multipleCallback
                , pTag))
            {
                t++;
            } else {
                full = true;
            }
            break;
        default:
            TC6_ASSERT(false);
            i = 0;
            full = true;
            break;
        }
    }
    return t;
}

void TC6_UnlockExtendedStatus(TC6_t *g)
{
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    g->exst_locked = false;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                  PRIVATE FUNCTION IMPLEMENTATIONS                    */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static inline uint8_t GET_VAL(uint8_t bytePos, uint8_t bitpos, uint8_t width, const uint8_t pIn[4])
{
    TC6_ASSERT(NULL != pIn);
    TC6_ASSERT(bytePos < 4u);
    TC6_ASSERT(bitpos < 8u);
    TC6_ASSERT(width != 0u);
    TC6_ASSERT(width <= 8u);
    uint8_t val = (pIn[bytePos] >> bitpos) & MASK[width];
    return val;
}

static inline void CLEAR_HEADER(uint8_t pOut[4])
{
    (void)memset(pOut, 0u, 4u);
}

static inline void SET_VAL(uint8_t bytePos, uint8_t bitpos, uint8_t width, uint8_t val, uint8_t pOut[4])
{
    TC6_ASSERT(NULL != pOut);
    TC6_ASSERT(bytePos < 4u);
    TC6_ASSERT(bitpos < 8u);
    TC6_ASSERT(width != 0u);
    TC6_ASSERT(width <= 8u);
    pOut[bytePos] |= (val & MASK[width]) << bitpos;
}

static void initializeSpiEntry(struct qspibuf *newEntry)
{
    TC6_ASSERT(newEntry);
    newEntry->length = 0;
#ifdef DEBUG
    (void)memset(newEntry->txBuff, 0xCCu, sizeof(newEntry->txBuff));
    (void)memset(newEntry->rxBuff, 0xCDu, sizeof(newEntry->rxBuff));
#endif
}

static uint16_t getTrail(TC6_t *g, bool enqueueEmpty)
{
    uint16_t  trail = 0;
    if (0u != g->rca) {
        trail = (g->rca * TC6_CHUNK_SIZE);
    } else if (enqueueEmpty) {
        if (0u == g->txc) {
            trail = TC6_CHUNK_SIZE;
        } else {
            trail = (TC6_CHUNKS_PER_ISR * TC6_CHUNK_SIZE);
        }
    } else {
    } /* MISRA enforced termination */
    return trail;
}

static void addEmptyChunks(TC6_t *g, struct qspibuf *entry, bool enqueueEmpty)
{
    uint16_t trail = getTrail(g, enqueueEmpty);
    if (trail > 0u) {
        uint16_t i = 0;
        /* Fill up buffer with empty chunks, so RX gets the opportunity to transmit quicker */
        for (; (i < trail) && (entry->length < sizeof(entry->txBuff)); i += TC6_CHUNK_SIZE) {
            uint8_t *p = &entry->txBuff[entry->length];
            p[0] = 0x80u;
            p[1] = 0x0u;
            p[2] = 0x0u;
            p[3] = 0x0u;
            (void)memset(&p[4], 0x00, TC6_CHUNK_SIZE);
            entry->length += TC6_CHUNK_BUF_SIZE;
        }
    }
    TC6_ASSERT(!enqueueEmpty || entry->length);
    TC6_ASSERT(entry->length <= sizeof(entry->rxBuff));
}

static bool serviceData(TC6_t *g, bool sendEmpty)
{
    bool dataSent = false;
    bool enqueueEmpty = sendEmpty;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    if (!g->alreadyInDataService) {
        /* Protect against reentrant call */
        g->alreadyInDataService = true;

        if (g->enableData && (SPI_OP_INVALID == g->currentOp) && (qspibuf_stage1_transfer_ready(&g->qSpi))) {
            uint16_t maxTxLen;
            /**********************************/
            /* Try to enqueue Ethernet chunks */
            /**********************************/
            struct qspibuf *entry = qspibuf_stage1_transfer_ptr(&g->qSpi);
            initializeSpiEntry(entry);

            /**************************************/
            /* TX Data is getting generated here: */
            /**************************************/
            maxTxLen = g->txc * TC6_CHUNK_BUF_SIZE;
            if (maxTxLen > sizeof(entry->txBuff)) {
                maxTxLen = sizeof(entry->txBuff);
            }
            entry->length = mk_data_tx(g, entry->txBuff, maxTxLen);
            if (0u != entry->length) {
                enqueueEmpty = false;
            }
            addEmptyChunks(g, entry, (enqueueEmpty || g->rca));

            if (0u != entry->length) {
                TC6_ASSERT(0u == (entry->length % TC6_CHUNK_BUF_SIZE));
                /* Call enqueue before actual SPI transfer to avoid race error with Interrupt handler */
                qspibuf_stage1_transfer_done(&g->qSpi);
                dataSent = true;
                if (!spiTransaction(g, entry->txBuff, entry->rxBuff, entry->length, SPI_OP_DATA)) {
                    /* SPI driver is currently busy, restore previous states */
                    qspibuf_stage1_transfer_undo(&g->qSpi);
                    dataSent = false;
                }
            }
        }
        g->alreadyInDataService = false;
    }
    return dataSent;
}

static bool serviceControl(TC6_t *g)
{
    bool sentControl = false;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    if (!g->alreadyInControlService) {
        /* Protect against reentrant call */
        g->alreadyInControlService = true;

        /****************************************/
        /* CONTROL RX and callback higher layer */
        /****************************************/
        while(regop_stage4_modify_ready(&g->regop_q)) {
            struct register_operation *reg_op = NULL;
            uint32_t regVal = 0xFFFFFFFFu;
            uint16_t num;
            reg_op = regop_stage4_modify_ptr(&g->regop_q);
            num = read_rx_ctrl_buffer(reg_op->rx_buf, reg_op->length, &regVal, sizeof(regVal), reg_op->secure);
            if ((0u == num)
                || (REGISTER_OP_READWRITE_STAGE1 != reg_op->op)
                || !modify(g, regVal))
            {
                /* Not a read modify write command (or it failed), proceed direct to stage 7*/
                regop_stage4_modify_done(&g->regop_q);
                regop_stage5_send_done(&g->regop_q);
                regop_stage6_int_done(&g->regop_q);
            }
        }
        while(regop_stage7_event_ready(&g->regop_q)) {
            struct register_operation *reg_op = NULL;
            TC6_RegCallback_t callback;
            void *tag;
            uint32_t regVal = 0xFFFFFFFFu;
            uint32_t regAddr;
            uint16_t num;
            bool success;

            reg_op = regop_stage7_event_ptr(&g->regop_q);
            num = read_rx_ctrl_buffer(reg_op->rx_buf, reg_op->length, &regVal, sizeof(regVal), reg_op->secure);
            callback = reg_op->callback;
            regAddr = reg_op->regAddr;
            tag = reg_op->tag;
            success = (0u != num);
            regop_stage7_event_done(&g->regop_q);
            if (NULL != callback) {
                reg_op->callback(g, success, regAddr, regVal, tag, g->gTag);
            } else if (!success) {
                TC6_CB_OnError(g, TC6Error_NoHardware, g->gTag);
            } else {} /* MISRA enforced termination */
        }

        /***************/
        /* Control TX  */
        /***************/
        if ((SPI_OP_INVALID == g->currentOp) && regop_stage5_send_ready(&g->regop_q)) {
            /*********************/
            /* MODIFY CONTROL TX */
            /*********************/
            struct register_operation *reg_op = regop_stage5_send_ptr(&g->regop_q);

            /* Call enqueue before actual SPI transfer to avoid race error with Interrupt handler */
            regop_stage5_send_done(&g->regop_q);

            g->currentOp = SPI_OP_REG;
            sentControl = true;
            if (!TC6_CB_OnSpiTransaction(g->instance, reg_op->tx_buf, reg_op->rx_buf, reg_op->length, g->gTag)) {
                g->currentOp = SPI_OP_INVALID;
                sentControl = false;
                regop_stage5_send_undo(&g->regop_q);
            }
        }
        if ((SPI_OP_INVALID == g->currentOp) && regop_stage2_send_ready(&g->regop_q)) {
            /*********************/
            /* NORMAL CONTROL TX */
            /*********************/
            struct register_operation *reg_op = regop_stage2_send_ptr(&g->regop_q);

            /* Call enqueue before actual SPI transfer to avoid race error with Interrupt handler */
            regop_stage2_send_done(&g->regop_q);

            TC6_ASSERT(SPI_OP_INVALID == g->currentOp);
            g->currentOp = SPI_OP_REG;
            sentControl = true;
            if (!TC6_CB_OnSpiTransaction(g->instance, reg_op->tx_buf, reg_op->rx_buf, reg_op->length, g->gTag)) {
                g->currentOp = SPI_OP_INVALID;
                sentControl = false;
                regop_stage2_send_undo(&g->regop_q);
            }
        }
        g->alreadyInControlService = false;
    }
    return sentControl;
}

static bool spiTransaction(TC6_t *g, uint8_t *pTx, uint8_t *pRx, uint16_t len, SpiOp_t op)
{
    bool success = false;
    if (g->currentOp == SPI_OP_INVALID) {
        g->currentOp = op;
        success = TC6_CB_OnSpiTransaction(g->instance, pTx, pRx, len, g->gTag);
        if (!success) {
            g->currentOp = SPI_OP_INVALID;
        }
    }
    return success;
}

static bool modify(TC6_t *g, uint32_t value)
{
    struct register_operation *reg_op;
    uint32_t val;
    bool success = false;
    TC6_ASSERT(regop_stage4_modify_ready(&g->regop_q));
    reg_op = regop_stage4_modify_ptr(&g->regop_q);
    reg_op->op = REGISTER_OP_READWRITE_STAGE2;
    val = (value & ~reg_op->modifyMask) | reg_op->modifyValue;
    (void)memset(reg_op->tx_buf, 0x00, sizeof(reg_op->tx_buf));
    if (reg_op->secure) {
        reg_op->length = mk_secure_ctrl_req(true /*write */, false /* autoIncrement */, reg_op->regAddr, 1 /* Array Len */, &val, reg_op->tx_buf, sizeof(reg_op->tx_buf));
    } else {
        reg_op->length = mk_ctrl_req(true /*write */, false /* autoIncrement */, reg_op->regAddr, 1 /* Array Len */, &val, reg_op->tx_buf, sizeof(reg_op->tx_buf));
    }
    if (0u != reg_op->length) {
        regop_stage4_modify_done(&g->regop_q);
        success = true;
    } else {
        TC6_CB_OnError(g, TC6Error_ControlTxFail, g->gTag);
        TC6_ASSERT(false);
    }
    return success;
}

static bool accessRegisters(TC6_t *g, enum register_op_type op, uint32_t addr, uint32_t value, bool secure, uint32_t modifyMask, TC6_RegCallback_t callback, void *tag)
{
    struct register_operation *reg_op = NULL;
    uint16_t payloadSize = 0;
    bool write = true;
    bool success = false;
    TC6_ASSERT(g && (TC6_MAGIC == g->magic));
    TC6_ASSERT(REGISTER_OP_INVALLID != op);
    if (regop_stage1_enqueue_ready(&g->regop_q)) {
        success = true;
        switch(op) {
        case REGISTER_OP_WRITE:
            write = true;
            break;
        case REGISTER_OP_READ:
            write = false;
            break;
        case REGISTER_OP_READWRITE_STAGE1:
            write = false;
            break;
        case REGISTER_OP_READWRITE_STAGE2:
            write = true;
            break;
        case REGISTER_OP_INVALLID:
        default:
            TC6_ASSERT(false);
            success = false;
            break;
        }
    }
    if (success) {
        reg_op = regop_stage1_enqueue_ptr(&g->regop_q);
#ifdef DEBUG
        (void)memset(reg_op, 0xCCu, sizeof(struct register_operation));
#endif
        (void)memset(reg_op->tx_buf, 0x00, sizeof(reg_op->tx_buf));
        if (secure) {
            payloadSize = mk_secure_ctrl_req(write, false /* autoIncrement */, addr, 1 /* Array Len */, &value, reg_op->tx_buf, sizeof(reg_op->tx_buf));
        } else {
            payloadSize = mk_ctrl_req(write, false /* autoIncrement */, addr, 1 /* Array Len */, &value, reg_op->tx_buf, sizeof(reg_op->tx_buf));
        }
        if (payloadSize == 0u) {
            TC6_CB_OnError(g, TC6Error_ControlTxFail, g->gTag);
            TC6_ASSERT(false);
            success = false;
        }
    }
    if (success) {
        TC6_ASSERT(payloadSize <= sizeof(reg_op->tx_buf));
        reg_op->regAddr = addr;
        reg_op->length = payloadSize;
        reg_op->op = op;
        reg_op->secure = secure;
        reg_op->callback = callback;
        reg_op->tag = tag;
        reg_op->modifyValue = value;
        reg_op->modifyMask = modifyMask;

        regop_stage1_enqueue_done(&g->regop_q);
        TC6_CB_OnNeedService(g, g->gTag);
    }
    return success;
}

static void processDataRx(TC6_t *g)
{
    /*******************************/
    /* DATA RX & Free up SPI Queue */
    /*******************************/
    while (qspibuf_stage3_process_ready(&g->qSpi)) {
        struct qspibuf *entry = qspibuf_stage3_process_ptr(&g->qSpi);
        TC6_ASSERT(0u == (entry->length % TC6_CHUNK_BUF_SIZE));
        enqueue_rx_spi(g, entry->rxBuff, entry->length);
        qspibuf_stage3_process_done(&g->qSpi);
    }
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*              CALLBACK FUNCTION FROM PROTOCOL STATEMACHINE            */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static void on_tx_eth_done(TC6_t *g, const uint8_t *ptr, uint16_t len, TC6_RawTxCallback_t txCallback, void *priv)
{
    TC6_ASSERT(ptr && len);

    if (NULL != txCallback) {
        txCallback(g, ptr, len, priv, g->gTag);
    }
}

static void on_rx_slice(TC6_t *g, const uint8_t *pBuf, uint16_t offset, uint16_t bufLen, bool rtsa, bool rtsp)
{
    const uint8_t *buff = pBuf; /* Because of MISRA warning */
    uint16_t buf_len = bufLen;  /* Because of MISRA warning */
    /* TODO: handle timestamp (RTSP) */
    (void)rtsp;

    if (offset == 0u) {
        g->buf_len = 0;
        g->ts = 0;
    }

    /* handle timestamp (RTSA) */
    /* ToDo: get timestamp according to selected timestamp length (32bit or 64bit) */
    if (rtsa) {
        g->ts = ((uint64_t)buff[0] << 56) |
                ((uint64_t)buff[1] << 48) |
                ((uint64_t)buff[2] << 40) |
                ((uint64_t)buff[3] << 32) |
                ((uint64_t)buff[4] << 24) |
                ((uint64_t)buff[5] << 16) |
                ((uint64_t)buff[6] << 8)  |
                ((uint64_t)buff[7]);

        buff = &buff[8];
        buf_len -= 8u;
    }

    g->buf_len += buf_len;
    TC6_CB_OnRxEthernetSlice(g, buff, offset, buf_len, g->gTag);
}

static void on_rx_done(TC6_t *g, uint16_t buf_len, bool mfd)
{
    bool success = !mfd && !g->eth_error;
    (void)buf_len;
    g->eth_error = false;
    if (success) {
        uint64_t *pTS = (0u != g->ts) ? &g->ts : NULL;
        TC6_CB_OnRxEthernetPacket(g, true, g->buf_len, pTS, g->gTag);
    } else {
        TC6_CB_OnRxEthernetPacket(g, false, 0, NULL, g->gTag);
    }
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                         PROTOCOL STATEMACHINE                        */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

static inline void value2net(uint32_t value, uint8_t *buf)
{
    buf[0] = (uint8_t)(value >> 24);
    buf[1] = (uint8_t)(value >> 16);
    buf[2] = (uint8_t)(value >> 8);
    buf[3] = (uint8_t)value;
}

static inline uint32_t net2value(const uint8_t *buf)
{
    return ((uint32_t)buf[0] << 24) | ((uint32_t)buf[1] << 16) | ((uint32_t)buf[2] << 8) | ((uint32_t)buf[3]);
}

static uint8_t get_parity(const uint8_t *pVal)
{
    uint8_t val = 0u;

#if UINT_MAX == UINT32_MAX
    /* 32 Bit machine */
    uint32_t v = pVal[0] | (pVal[1] << 8) | (pVal[2] << 16) | (pVal[3] << 24);
    v ^= v >> 16;
    v ^= v >> 8;
    v ^= v >> 4;
    v ^= v >> 2;
    v ^= v >> 1;

    v = ~v & 1u;       /* odd parity */
    val = (uint8_t)v;  /* MISRA c2012-10.3 */
#else
    /* 16 Bit machine */
    uint16_t h = *((const uint16_t*)&pVal[0]);
    uint16_t l = *((const uint16_t*)&pVal[2]);
    h ^= h >> 8;
    h ^= h >> 4;
    h ^= h >> 2;
    h ^= h >> 1;

    l ^= l >> 8;
    l ^= l >> 4;
    l ^= l >> 2;
    l ^= l >> 1;

    val =  ~(h ^ l) & 1u;
#endif    

    return val;
}

/* Control Transaction API {{{ */

/*
 * The functions below create regular or secure control transaction buffer
 * ready for an SPI Tx transfer.  The register values for the 'write' operation
 * are taken from the 'tx_buf'.  The content for the SPI transfer is generated
 * into the 'tx_buf'.
 *
 * @wnr: Write, not read.
 * @aid: Disable address increment.
 * @addr:
 *     Upper 16 bit: Memory map selector (MMS).
 *     Lower 16 bit: Address.
 * @num_regs: Number of registers to read or write.
 * @tx_buf: Buffer for SPI Tx transfer.
 *     If operation is 'write', then the first 'num_regs' elements of the
 *     'tx_buf' must contain values to write.
 * @tx_buf_size: size of the 'tx_buf' in bytes.
 *
 * Returns number of the 'tx_buf' bytes to be sent using the SPI Tx transfer.
 * In case of error the function returns 0 and the buffer remains unchanged.
 *
 * SECURITY NOTE:
 *
 * The places for turn-around- or other gaps in the 'tx_buf' are kept
 * unchanged.  If needed, the application must clean up the buffer before
 * transfer it to the function.
 */

static uint16_t mk_ctrl_req(bool wnr, bool aid, uint32_t addr,
        uint8_t num_regs, const uint32_t *regs,
        uint8_t *tx_buf, uint16_t tx_buf_size)
{
    bool success = true;

    if ((num_regs < 1u) || (num_regs > 128u)) {
        success = false;
    }

    if ((num_regs + 2u) > (tx_buf_size / 4u)) {
        success = false;
    }

    if (success) {
        if (wnr) {
            uint8_t *dst = tx_buf;
            uint16_t i;

            dst = &dst[num_regs * 4u];
            for (i = num_regs; i > 0u; i--) {
                uint32_t v = regs[i - 1u];

                value2net(v, dst);
                dst = &dst[-4];
            }
        }

        CLEAR_HEADER(tx_buf);
        SET_VAL(HDR_C_DNC, 0, tx_buf);
        SET_VAL(HDR_C_WNR, wnr, tx_buf);
        SET_VAL(HDR_C_AID, aid, tx_buf);
        SET_VAL(HDR_C_MMS, (uint8_t)(addr >> 16), tx_buf);
        SET_VAL(HDR_C_ADDR_HI, (uint8_t)(addr >> 8), tx_buf);
        SET_VAL(HDR_C_ADDR_LO, (uint8_t)addr, tx_buf);
        SET_VAL(HDR_C_LEN, (num_regs - 1u), tx_buf);
        SET_VAL(HDR_C_P, get_parity(tx_buf), tx_buf);
    }
    return success ? ((num_regs * 4u) + 8u) : 0u;
}

static uint16_t mk_secure_ctrl_req(bool wnr, bool aid, uint32_t addr,
        uint8_t num_regs, const uint32_t *regs,
        uint8_t *tx_buf, uint16_t tx_buf_size)
{
    bool success = true;

    if ((num_regs < 1u) || (num_regs > 128u)) {
        success = false;
    }

    if (success && (((num_regs * 2u) + 2u) > (tx_buf_size / 4u))) {
        success = false;
    }

    if (success) {
        if (wnr) {
            uint16_t i;
            uint8_t *dst = tx_buf;

            dst = &dst[num_regs * 8u];
            for (i = num_regs; i > 0u; i--) {
                uint32_t v = regs[i - 1u];

                value2net(~v, dst);
                value2net(v, &dst[-4]);
                dst = &dst[-8];
            }
        }

        CLEAR_HEADER(tx_buf);
        SET_VAL(HDR_C_DNC, 0, tx_buf);
        SET_VAL(HDR_C_WNR, wnr, tx_buf);
        SET_VAL(HDR_C_AID, aid, tx_buf);
        SET_VAL(HDR_C_MMS, (uint8_t)(addr >> 16), tx_buf);
        SET_VAL(HDR_C_ADDR_HI, (uint8_t)(addr >> 8), tx_buf);
        SET_VAL(HDR_C_ADDR_LO, (uint8_t)addr, tx_buf);
        SET_VAL(HDR_C_LEN, (num_regs - 1u), tx_buf);
        SET_VAL(HDR_C_P, get_parity(tx_buf), tx_buf);
    }
    return success ? ((num_regs * 8u) + 8u) : 0u;
}

static uint16_t read_rx_ctrl_buffer(const uint8_t *rx_buf, uint16_t rx_buf_size,
        uint32_t *regs_buf, uint8_t regs_buf_size, bool secure)
{
    uint16_t i;
    uint16_t num = 0;
    const uint8_t *src;

    if (secure) {
        if ((0u == (rx_buf_size % 8u)) && ((rx_buf_size / 8u) >= 2u)) {
            num = (rx_buf_size / 8u) - 1u;
            if ((regs_buf_size / 4u) < num) {
                num = 0;
            }
        }

        src = rx_buf;
        for (i = 0; i < num; i++) {
            src = &src[8];
            if (net2value(src) != ~net2value(&src[4])) {
                num = 0;
            }
        }
        src = rx_buf;
        for (i = 0; i < num; i++) {
            src = &src[8];
            regs_buf[i] = net2value(src);
        }
    } else {
        num = (rx_buf_size - 8u) / 4u;
        if ((regs_buf_size / 4u) < num) {
            num = 0;
        } else {
            src = &rx_buf[8];
            for (i = 0; i < num; i++) {
                regs_buf[i] = net2value(src);
                src = &src[4];
            }
        }
    }
    return num;
}

/* }}} */

/* Tx API {{{ */

/*
 * Maps longest possible slice from unprocessed ETH payload onto a free SPI
 * chunk space.
 */
static uint16_t process_tx(TC6_t *g, uint8_t *tx_buf)
{
    struct qtxeth_queue *q = &g->eth_q;
    struct qtxeth *entry;
    uint16_t tocopy_len;
    uint16_t padded_len;
    uint16_t retVal = 0u;
    uint16_t copy_pos = 0u;
    bool sv = false;

    if (qtxeth_stage2_convert_ready(q)) {
        entry = qtxeth_stage2_convert_ptr(q);
#ifdef DEBUG
        (void)memset(tx_buf, 0xCDu, TC6_CHUNK_BUF_SIZE);
#endif
        CLEAR_HEADER(tx_buf);
        SET_VAL(HDR_DNC, 1u, tx_buf);
        SET_VAL(HDR_DV, 1u, tx_buf);
        TC6_ASSERT(g->offsetEth <= entry->totalLen);

        SET_VAL(HDR_SEQ, g->seq_num++, tx_buf);
        if (!g->offsetEth) {
            SET_VAL(HDR_SV, 1u, tx_buf);
            SET_VAL(HDR_SWO, 0u, tx_buf);
            sv = true;
            if (0u != entry->tsc) {
                SET_VAL(HDR_TSC, entry->tsc, tx_buf);
            }
        }
        if (0u == g->offsetEth) {
            TC6_ASSERT((0u == g->segCurr) && (0u == g->segOffset));
        }
        tocopy_len = entry->totalLen - g->offsetEth;
        tocopy_len = (tocopy_len <= TC6_CHUNK_SIZE) ? tocopy_len : TC6_CHUNK_SIZE;
        padded_len = TC6_CHUNK_SIZE - tocopy_len;
        while(copy_pos < tocopy_len) {
            const uint8_t *pBuf = &entry->ethSegs[g->segCurr].pEth[g->segOffset];
            uint16_t len = entry->ethSegs[g->segCurr].segLen - g->segOffset;
            uint16_t diff = (tocopy_len - copy_pos);
            if (len > diff) {
                len = diff;
            }
            (void)memcpy(&tx_buf[TC6_HEADER_SIZE + copy_pos], pBuf, len);
            copy_pos += len;
            g->segOffset += len;
            TC6_ASSERT(g->segOffset <= entry->ethSegs[g->segCurr].segLen);
            if (g->segOffset == entry->ethSegs[g->segCurr].segLen) {
                g->segOffset = 0;
                g->segCurr++;
                TC6_ASSERT(g->segCurr <= entry->segCount);
                if (g->segCurr == entry->segCount) {
                    g->segCurr = 0;
                }
            }
        }
        TC6_ASSERT(copy_pos == tocopy_len);
        if (0u != padded_len) {
            (void)memset(&tx_buf[TC6_HEADER_SIZE + tocopy_len], 0x0u, padded_len);
        }
        g->offsetEth += tocopy_len;
        TC6_ASSERT(g->offsetEth <= entry->totalLen);
        if (g->offsetEth == entry->totalLen) {
            SET_VAL(HDR_EV, 1u, tx_buf);
            SET_VAL(HDR_EBO, (uint8_t)(tocopy_len - 1u), tx_buf);
            g->offsetEth = 0;
            on_tx_eth_done(g, entry->ethSegs[0].pEth, entry->totalLen, entry->txCallback, entry->priv);
            qtxeth_stage2_convert_done(q);
            /* Current Ethernet frame is fully enqueued, try to attach the beginning of the next Ethernet frame */
            if (!sv && qtxeth_stage2_convert_ready(q)) {
                tocopy_len = (tocopy_len + 3u) >> 2u << 2u;
                entry = qtxeth_stage2_convert_ptr(q);
                if (entry->totalLen <= TC6_CONCAT_THRESHOLD) {
                    uint16_t remaining_len = TC6_CHUNK_SIZE - tocopy_len;
                    /* Make sure, that next packet does not end in the same chunk (TC6 does not support two "end valid") */
                    if (remaining_len && (entry->totalLen > remaining_len)) {
                        SET_VAL(HDR_SV, 1, tx_buf);
                        SET_VAL(HDR_SWO, (uint8_t)(tocopy_len / 4u), tx_buf);
                        if (0u != entry->tsc) {
                            SET_VAL(HDR_TSC, entry->tsc, tx_buf);
                        }
                        copy_pos = 0;
                        while(copy_pos < remaining_len) {
                            const uint8_t *pBuf = &entry->ethSegs[g->segCurr].pEth[g->segOffset];
                            uint16_t len = entry->ethSegs[g->segCurr].segLen - g->segOffset;
                            uint16_t diff = (remaining_len - copy_pos);
                            if (len > diff) {
                                len = diff;
                            }
                            (void)memcpy(&tx_buf[TC6_HEADER_SIZE + tocopy_len + copy_pos], pBuf, len);
                            g->offsetEth += len;
                            copy_pos += len;
                            g->segOffset += len;
                            TC6_ASSERT(g->segOffset <= entry->ethSegs[g->segCurr].segLen);
                            if (g->segOffset == entry->ethSegs[g->segCurr].segLen) {
                                g->segOffset = 0;
                                g->segCurr++;
                                TC6_ASSERT(g->segCurr <= entry->segCount);
                                if (g->segCurr == entry->segCount) {
                                    g->segCurr = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        SET_VAL(HDR_P, get_parity(tx_buf), tx_buf);
        retVal = TC6_CHUNK_BUF_SIZE;
    }
    return retVal;
}

static uint16_t mk_data_tx(TC6_t *g, uint8_t *tx_buf, uint16_t tx_buf_len)
{
    uint16_t pos = 0;
    while (pos < tx_buf_len) {
        uint16_t result = process_tx(g, &tx_buf[pos]);
        TC6_ASSERT(0u == (result % TC6_CHUNK_BUF_SIZE));
        if (!result) {
            break;
        }
        pos += result;
    }
    return pos;
}

/* }}} */

/* Rx API {{{ */

static inline void signal_rx_error(TC6_t *g, TC6_Error_t err)
{
    g->eth_error = true;
    g->eth_started = false;
    g->offsetRx = 0;
    TC6_CB_OnError(g, err, g->gTag);
}

static inline void process_rx(TC6_t *g, const uint8_t *buff, uint16_t buf_len)
{
    const uint8_t *fptr = &buff[buf_len - TC6_HEADER_SIZE];

    if (GET_VAL(FTR_SV, fptr) ||
        GET_VAL(FTR_DV, fptr) ||
        GET_VAL(FTR_EV, fptr))
    {
        uint16_t len;
        uint8_t sv;
        uint8_t ev;
        uint8_t rtsa = 0;
        uint8_t rtsp = 0;
        uint8_t mfd;
        uint8_t sbo;
        uint8_t ebo;
        bool twoFrames;
        bool success = true;

        sv = GET_VAL(FTR_SV, fptr);
        sbo = sv ? (GET_VAL(FTR_SWO, fptr) * 4u) : 0u;

        ev = GET_VAL(FTR_EV, fptr);
        ebo = ev ? (GET_VAL(FTR_EBO, fptr) + 1u) : TC6_CHUNK_SIZE;

        mfd = GET_VAL(FTR_FD, fptr);
        twoFrames = (ebo <= sbo);

        if (twoFrames) {
            /* Two ETH frames in chunk */
            on_rx_slice(g, buff, g->offsetRx, (uint16_t)ebo, rtsa, rtsp);
            on_rx_done(g, (uint16_t)(g->offsetRx + ebo), mfd);
            g->offsetRx = 0;
            len = (uint16_t)(TC6_CHUNK_SIZE - sbo);
        } else {
            /* Single Eth frame in chunk */
            len = ((uint16_t)ebo - (uint16_t)sbo);
        }

        if (!twoFrames && sv && g->eth_started) {
            signal_rx_error(g, TC6Error_UnexpectedSv);
            success = false;
        }

        if (success && !g->eth_started && !g->eth_error && !sv) {
            signal_rx_error(g, TC6Error_UnexpectedDvEv);
            success = false;
        }

        if ((!sv || twoFrames) && g->eth_error) {
            /* Wait for next start valid flag to clear error flag */
            success = false;
        }

        if (success) {
            if (0u != sv) {
                rtsa = GET_VAL(FTR_RTSA, fptr);
                rtsp = GET_VAL(FTR_RTSP, fptr);
            }

            g->eth_started = true;
            g->eth_error = false;
            on_rx_slice(g, &buff[sbo], g->offsetRx, len, rtsa, rtsp);

            /* ToDo: adjust length according to length of timestamp (32bit or 64bit) */
            if (0u != rtsa) {
                len -= 8u;
            }

            if (!twoFrames && ev) {
                uint16_t offset = g->offsetRx;
                g->eth_started = false;
                g->offsetRx = 0;
                on_rx_done(g, offset + len, mfd);
            } else {
                g->offsetRx += len;
            }
        }
    } else {
        g->eth_error = false;
    }
}

static void enqueue_rx_spi(TC6_t *g, const uint8_t *buff, uint16_t buf_len)
{
    uint32_t processed;
    bool success = true;
    if (!buf_len || (buf_len % TC6_CHUNK_BUF_SIZE)) {
        TC6_ASSERT(false); /* integration error */
        success = false;
    }
    for (processed = 0; success && (processed < buf_len); processed += TC6_CHUNK_BUF_SIZE) {
        const uint8_t *pFooter = &buff[processed + TC6_CHUNK_SIZE];

        if (((0x0u == pFooter[0]) && (0x0u == pFooter[1]) && (0x0u == pFooter[2]) && (0x0u == pFooter[3])) ||
            ((0xFFu == pFooter[0]) && (0xFFu == pFooter[1]) && (0xFFu == pFooter[2]) && (0xFFu == pFooter[3])))
        {
            signal_rx_error(g, TC6Error_NoHardware);
            success = false;
        }
        if (success && get_parity(pFooter)) {
            signal_rx_error(g, TC6Error_BadChecksum);
            success = false;
        }
        if (success && GET_VAL(FTR_HDRB, pFooter)) {
            signal_rx_error(g, TC6Error_BadTxData);
            success = false;
        }
        g->synced = GET_VAL(FTR_SYNC, pFooter);
        if (success && !g->synced) {
            signal_rx_error(g, TC6Error_SyncLost);
            success = false;
        }
        if (success && GET_VAL(FTR_FD, pFooter)) {
            TC6_CB_OnRxEthernetPacket(g, false, 0, NULL, g->gTag);
            success = false;
        }
        if (success) {
            if (!g->exst_locked) {
                if (0u != GET_VAL(FTR_EXST, pFooter)) {
                    g->exst_locked = true;
                    TC6_CB_OnExtendedStatus(g, g->gTag);
                }
            }
            process_rx(g, &buff[processed], TC6_CHUNK_BUF_SIZE);
        } else {
            g->offsetRx = 0;
            g->eth_error = false;
        }
    }
}

static void update_credit_cnt(TC6_t *g, const uint8_t *buff, uint16_t buf_len)
{
    const uint8_t *const pFooter = &buff[buf_len - TC6_HEADER_SIZE];
    bool success = true;

    TC6_ASSERT(buf_len && (0u == (buf_len % TC6_CHUNK_BUF_SIZE)));

    if (success && GET_VAL(FTR_HDRB, pFooter)) {
        success = false;
    }
    if (success && !GET_VAL(FTR_SYNC, pFooter)) {
        success = false;
    }
    if (success) {
        g->txc = GET_VAL(FTR_TXC, pFooter);
        g->rca = GET_VAL(FTR_RCA, pFooter);
    }
}

/* }}} */

/*
 * This function might be called from the interrupt.
 */
void TC6_SpiBufferDone(uint8_t tc6instance, bool success)
{
    TC6_t *g;
    if (tc6instance < TC6_MAX_INSTANCES) {
        struct qspibuf *entry;
        g = &m_tc6[tc6instance];
        g->intContext = true;
        if (!success) {
            signal_rx_error(g, TC6Error_SpiError);
        }
        switch (g->currentOp) {
        case SPI_OP_DATA:
            if (!qspibuf_stage2_int_ready(&g->qSpi)) {
                TC6_ASSERT(false);
                break;
            }
            entry = qspibuf_stage2_int_ptr(&g->qSpi);
            update_credit_cnt(g, entry->rxBuff, entry->length);
            qspibuf_stage2_int_done(&g->qSpi);
            break;
        case SPI_OP_REG:
            TC6_ASSERT(regop_stage3_int_ready(&g->regop_q) || regop_stage6_int_ready(&g->regop_q));
            if(regop_stage3_int_ready(&g->regop_q)) {
               regop_stage3_int_done(&g->regop_q);
            }
            if(regop_stage6_int_ready(&g->regop_q)) {
               regop_stage6_int_done(&g->regop_q);
            }
            break;
        case SPI_OP_INVALID:
        default:
            TC6_ASSERT(false);
            break;
        }
        g->currentOp = SPI_OP_INVALID;
        g->intContext = false;
        TC6_CB_OnNeedService(g, g->gTag);
    } else {
        TC6_ASSERT(false);
    }
}
