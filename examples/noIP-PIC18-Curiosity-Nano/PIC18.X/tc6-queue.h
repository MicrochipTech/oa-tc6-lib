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

#ifndef TC6_QUEUE_
#define TC6_QUEUE_

/* DO NOT MODIFY: generated from tc6-queue.conf */
/*------------------------------------------------------------------------------------------------*/
/* Low Level Driver for OpenAlliance TC6 10BASE-T1S MACPHY via SPI protocol                       */
/*------------------------------------------------------------------------------------------------*/

#include <stdint.h>
#include <stdbool.h>

struct qtxeth {
    void *priv;
    TC6_RawTxCallback_t txCallback;
    TC6_RawTxSegment ethSegs[TC6_TX_ETH_MAX_SEGMENTS];
    uint16_t totalLen;
    uint8_t segCount;
    uint8_t tsc;
};

#define TC6_CNTRL_BUF_SIZE  ((2u + (TC6_MAX_CNTRL_VARS * 2u)) * 4u)
#define TC6_SPI_BUF_SIZE    (TC6_CHUNKS_XACT * TC6_CHUNK_BUF_SIZE)

struct qspibuf {
    uint8_t txBuff[TC6_SPI_BUF_SIZE];
    uint8_t rxBuff[TC6_SPI_BUF_SIZE];
    uint16_t length;
};

enum register_op_type
{
    REGISTER_OP_INVALLID,
    REGISTER_OP_WRITE,
    REGISTER_OP_READ,
    REGISTER_OP_READWRITE_STAGE1,
    REGISTER_OP_READWRITE_STAGE2
};

struct register_operation {
    uint8_t tx_buf[TC6_CNTRL_BUF_SIZE];
    uint8_t rx_buf[TC6_CNTRL_BUF_SIZE];
    TC6_RegCallback_t callback;
    void *tag;
    enum register_op_type op;
    uint32_t modifyValue;
    uint32_t modifyMask;
    uint32_t regAddr;
    uint16_t length;
    bool secure;
};

/*
 * namespace: qtxeth
 * type: "struct qtxeth"
 * stages: stage1_enqueue stage2_convert
 */

#ifdef __cplusplus
extern "C" {
#endif

struct qtxeth_queue {
    struct qtxeth *buffer_;
    uint8_t size_;
    uint8_t stage1_enqueue_;
    uint8_t stage2_convert_;
};

static inline void init_qtxeth_queue(struct qtxeth_queue *q, struct qtxeth *buffer, uint8_t size)
    { q->buffer_ = buffer; q->size_ = size; q->stage1_enqueue_ = 0u; q->stage2_convert_ = 0u; }

/* stage1_enqueue */
static inline bool qtxeth_stage1_enqueue_ready(struct qtxeth_queue const *q) {
    return 0u != ((uint8_t)(q->stage1_enqueue_ - q->stage2_convert_) < q->size_); }
static inline struct qtxeth *qtxeth_stage1_enqueue_ptr(struct qtxeth_queue const *q) {
    return &q->buffer_[(q->stage1_enqueue_ & (q->size_ - 1u))]; }
static inline void qtxeth_stage1_enqueue_done(struct qtxeth_queue *q) {
    ++q->stage1_enqueue_; }
static inline void qtxeth_stage1_enqueue_undo(struct qtxeth_queue *q) {
    --q->stage1_enqueue_; }
static inline uint8_t qtxeth_stage1_enqueue_cap(struct qtxeth_queue const *q) {
    return q->stage2_convert_ + q->size_ - q->stage1_enqueue_; }

/* stage2_convert */
static inline bool qtxeth_stage2_convert_ready(struct qtxeth_queue const *q) {
    return ((uint8_t)(q->stage1_enqueue_ - q->stage2_convert_ - 1u)) < q->size_; }
static inline struct qtxeth *qtxeth_stage2_convert_ptr(struct qtxeth_queue const *q) {
    return &q->buffer_[(q->stage2_convert_ & (q->size_ - 1u))]; }
static inline void qtxeth_stage2_convert_done(struct qtxeth_queue *q) {
    ++q->stage2_convert_; }
static inline void qtxeth_stage2_convert_undo(struct qtxeth_queue *q) {
    --q->stage2_convert_; }
static inline uint8_t qtxeth_stage2_convert_cap(struct qtxeth_queue const *q) {
    return q->stage1_enqueue_ - q->stage2_convert_; }

#ifdef __cplusplus
}
#endif

/*
 * namespace: qspibuf
 * type: "struct qspibuf"
 * stages: stage1_transfer stage2_int stage3_process
 */

#ifdef __cplusplus
extern "C" {
#endif

struct qspibuf_queue {
    struct qspibuf *buffer_;
    uint8_t size_;
    uint8_t stage1_transfer_;
    uint8_t stage2_int_;
    uint8_t stage3_process_;
};

static inline void init_qspibuf_queue(struct qspibuf_queue *q, struct qspibuf *buffer, uint8_t size)
    { q->buffer_ = buffer; q->size_ = size; q->stage1_transfer_ = 0u; q->stage2_int_ = 0u; q->stage3_process_ = 0u; }

/* stage1_transfer */
static inline bool qspibuf_stage1_transfer_ready(struct qspibuf_queue const *q) {
    return 0u != ((uint8_t)(q->stage1_transfer_ - q->stage3_process_) < q->size_); }
static inline struct qspibuf *qspibuf_stage1_transfer_ptr(struct qspibuf_queue const *q) {
    return &q->buffer_[(q->stage1_transfer_ & (q->size_ - 1u))]; }
static inline void qspibuf_stage1_transfer_done(struct qspibuf_queue *q) {
    ++q->stage1_transfer_; }
static inline void qspibuf_stage1_transfer_undo(struct qspibuf_queue *q) {
    --q->stage1_transfer_; }
static inline uint8_t qspibuf_stage1_transfer_cap(struct qspibuf_queue const *q) {
    return q->stage3_process_ + q->size_ - q->stage1_transfer_; }

/* stage2_int */
static inline bool qspibuf_stage2_int_ready(struct qspibuf_queue const *q) {
    return ((uint8_t)(q->stage1_transfer_ - q->stage2_int_ - 1u)) < q->size_; }
static inline struct qspibuf *qspibuf_stage2_int_ptr(struct qspibuf_queue const *q) {
    return &q->buffer_[(q->stage2_int_ & (q->size_ - 1u))]; }
static inline void qspibuf_stage2_int_done(struct qspibuf_queue *q) {
    ++q->stage2_int_; }
static inline void qspibuf_stage2_int_undo(struct qspibuf_queue *q) {
    --q->stage2_int_; }
static inline uint8_t qspibuf_stage2_int_cap(struct qspibuf_queue const *q) {
    return q->stage1_transfer_ - q->stage2_int_; }

/* stage3_process */
static inline bool qspibuf_stage3_process_ready(struct qspibuf_queue const *q) {
    return ((uint8_t)(q->stage2_int_ - q->stage3_process_ - 1u)) < q->size_; }
static inline struct qspibuf *qspibuf_stage3_process_ptr(struct qspibuf_queue const *q) {
    return &q->buffer_[(q->stage3_process_ & (q->size_ - 1u))]; }
static inline void qspibuf_stage3_process_done(struct qspibuf_queue *q) {
    ++q->stage3_process_; }
static inline void qspibuf_stage3_process_undo(struct qspibuf_queue *q) {
    --q->stage3_process_; }
static inline uint8_t qspibuf_stage3_process_cap(struct qspibuf_queue const *q) {
    return q->stage2_int_ - q->stage3_process_; }

#ifdef __cplusplus
}
#endif

/*
 * namespace: regop
 * type: "struct register_operation"
 * stages: stage1_enqueue stage2_send stage3_int stage4_modify stage5_send stage6_int stage7_event
 */

#ifdef __cplusplus
extern "C" {
#endif

struct regop_queue {
    struct register_operation *buffer_;
    uint8_t size_;
    uint8_t stage1_enqueue_;
    uint8_t stage2_send_;
    uint8_t stage3_int_;
    uint8_t stage4_modify_;
    uint8_t stage5_send_;
    uint8_t stage6_int_;
    uint8_t stage7_event_;
};

static inline void init_regop_queue(struct regop_queue *q, struct register_operation *buffer, uint8_t size)
    { q->buffer_ = buffer; q->size_ = size; q->stage1_enqueue_ = 0u; q->stage2_send_ = 0u; q->stage3_int_ = 0u; q->stage4_modify_ = 0u; q->stage5_send_ = 0u; q->stage6_int_ = 0u; q->stage7_event_ = 0u; }

/* stage1_enqueue */
static inline bool regop_stage1_enqueue_ready(struct regop_queue const *q) {
    return 0u != ((uint8_t)(q->stage1_enqueue_ - q->stage7_event_) < q->size_); }
static inline struct register_operation *regop_stage1_enqueue_ptr(struct regop_queue const *q) {
    return &q->buffer_[(q->stage1_enqueue_ & (q->size_ - 1u))]; }
static inline void regop_stage1_enqueue_done(struct regop_queue *q) {
    ++q->stage1_enqueue_; }
static inline void regop_stage1_enqueue_undo(struct regop_queue *q) {
    --q->stage1_enqueue_; }
static inline uint8_t regop_stage1_enqueue_cap(struct regop_queue const *q) {
    return q->stage7_event_ + q->size_ - q->stage1_enqueue_; }

/* stage2_send */
static inline bool regop_stage2_send_ready(struct regop_queue const *q) {
    return ((uint8_t)(q->stage1_enqueue_ - q->stage2_send_ - 1u)) < q->size_; }
static inline struct register_operation *regop_stage2_send_ptr(struct regop_queue const *q) {
    return &q->buffer_[(q->stage2_send_ & (q->size_ - 1u))]; }
static inline void regop_stage2_send_done(struct regop_queue *q) {
    ++q->stage2_send_; }
static inline void regop_stage2_send_undo(struct regop_queue *q) {
    --q->stage2_send_; }
static inline uint8_t regop_stage2_send_cap(struct regop_queue const *q) {
    return q->stage1_enqueue_ - q->stage2_send_; }

/* stage3_int */
static inline bool regop_stage3_int_ready(struct regop_queue const *q) {
    return ((uint8_t)(q->stage2_send_ - q->stage3_int_ - 1u)) < q->size_; }
static inline struct register_operation *regop_stage3_int_ptr(struct regop_queue const *q) {
    return &q->buffer_[(q->stage3_int_ & (q->size_ - 1u))]; }
static inline void regop_stage3_int_done(struct regop_queue *q) {
    ++q->stage3_int_; }
static inline void regop_stage3_int_undo(struct regop_queue *q) {
    --q->stage3_int_; }
static inline uint8_t regop_stage3_int_cap(struct regop_queue const *q) {
    return q->stage2_send_ - q->stage3_int_; }

/* stage4_modify */
static inline bool regop_stage4_modify_ready(struct regop_queue const *q) {
    return ((uint8_t)(q->stage3_int_ - q->stage4_modify_ - 1u)) < q->size_; }
static inline struct register_operation *regop_stage4_modify_ptr(struct regop_queue const *q) {
    return &q->buffer_[(q->stage4_modify_ & (q->size_ - 1u))]; }
static inline void regop_stage4_modify_done(struct regop_queue *q) {
    ++q->stage4_modify_; }
static inline void regop_stage4_modify_undo(struct regop_queue *q) {
    --q->stage4_modify_; }
static inline uint8_t regop_stage4_modify_cap(struct regop_queue const *q) {
    return q->stage3_int_ - q->stage4_modify_; }

/* stage5_send */
static inline bool regop_stage5_send_ready(struct regop_queue const *q) {
    return ((uint8_t)(q->stage4_modify_ - q->stage5_send_ - 1u)) < q->size_; }
static inline struct register_operation *regop_stage5_send_ptr(struct regop_queue const *q) {
    return &q->buffer_[(q->stage5_send_ & (q->size_ - 1u))]; }
static inline void regop_stage5_send_done(struct regop_queue *q) {
    ++q->stage5_send_; }
static inline void regop_stage5_send_undo(struct regop_queue *q) {
    --q->stage5_send_; }
static inline uint8_t regop_stage5_send_cap(struct regop_queue const *q) {
    return q->stage4_modify_ - q->stage5_send_; }

/* stage6_int */
static inline bool regop_stage6_int_ready(struct regop_queue const *q) {
    return ((uint8_t)(q->stage5_send_ - q->stage6_int_ - 1u)) < q->size_; }
static inline struct register_operation *regop_stage6_int_ptr(struct regop_queue const *q) {
    return &q->buffer_[(q->stage6_int_ & (q->size_ - 1u))]; }
static inline void regop_stage6_int_done(struct regop_queue *q) {
    ++q->stage6_int_; }
static inline void regop_stage6_int_undo(struct regop_queue *q) {
    --q->stage6_int_; }
static inline uint8_t regop_stage6_int_cap(struct regop_queue const *q) {
    return q->stage5_send_ - q->stage6_int_; }

/* stage7_event */
static inline bool regop_stage7_event_ready(struct regop_queue const *q) {
    return ((uint8_t)(q->stage6_int_ - q->stage7_event_ - 1u)) < q->size_; }
static inline struct register_operation *regop_stage7_event_ptr(struct regop_queue const *q) {
    return &q->buffer_[(q->stage7_event_ & (q->size_ - 1u))]; }
static inline void regop_stage7_event_done(struct regop_queue *q) {
    ++q->stage7_event_; }
static inline void regop_stage7_event_undo(struct regop_queue *q) {
    --q->stage7_event_; }
static inline uint8_t regop_stage7_event_cap(struct regop_queue const *q) {
    return q->stage6_int_ - q->stage7_event_; }

#ifdef __cplusplus
}
#endif

#endif /* TC6_QUEUE_ */
