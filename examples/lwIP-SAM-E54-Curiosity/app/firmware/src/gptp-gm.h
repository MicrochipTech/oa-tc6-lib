#ifndef GPTP_GM_H_
#define GPTP_GM_H_

#include <stdint.h>
#include <stdbool.h>

/*>>>>>>>>>>>>>>>>>>>>>>>> USER ADJUSTABLE >>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#define GPTP_GM_DOMAIN_NUMBER        (0u)   /* gPTP domain 0 */
#define GPTP_GM_LOG_SYNC_INTERVAL    (-3)   /* 2^-3 s = 125 ms (Automotive default) */
#define GPTP_GM_SYNC_INTERVAL_MS     (125u) /* must equal 1000 * 2^GPTP_GM_LOG_SYNC_INTERVAL */
/*<<<<<<<<<<<<<<<<<<<<<<<< USER ADJUSTABLE <<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/** \brief Initializes the gPTP Automotive-profile Grand Master for an instance.
 *  \note Call after TC6LwIP_Init() succeeds. Fails if timestamping is unsupported.
 *  \param idx - instance index returned by TC6LwIP_Init()
 *  \return true on success */
bool gPTP_GM_Init(int8_t idx);

/** \brief Drives the GM scheduler. Call from the main loop next to TC6LwIP_Service(). */
void gPTP_GM_Service(void);

/** \brief Delivers a captured TX timestamp for a previously sent Sync frame.
 *  \note Called by tc6-lwip.c's OnTxTimestamp handler. Triggers Follow_Up send.
 *  \param idx - instance index
 *  \param success - true if the timestamp read succeeded
 *  \param tsc - capture slot (1/2/3) that was used for the Sync
 *  \param timestamp - 64-bit capture: seconds in high 32 bits, nanoseconds in low 32 */
void gPTP_GM_OnTxTimestamp(int8_t idx, bool success, uint8_t tsc, uint64_t timestamp);

#endif /* GPTP_GM_H_ */
