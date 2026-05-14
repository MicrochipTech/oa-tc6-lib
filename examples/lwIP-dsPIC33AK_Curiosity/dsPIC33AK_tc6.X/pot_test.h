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
  Potentiometer test header file.

  Company:
    Microchip Technology Inc.

  File Name:
    pot_test.h

  Summary:
    Potentiometer test header file

  Description:
    The potentiometer test that sends UDP messages to devices capable of
    interpreting them, and those devices control their 3-color LED based on the
    values received from the sender.
*******************************************************************************/

#ifndef POT_TEST_H_
#define POT_TEST_H_

#include <stdint.h>
#include <stdbool.h>
#include "lwip/ip4_addr.h"

#ifdef __cplusplus
extern "C" {
#endif

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                          USER ADJUSTABLE                             */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

#define POT_TEST_UDP_PORT           (5150)

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                            PUBLIC API                                */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/// @brief Start the potentiometer test.
/// @param addr The IP address of the destination (which can be broadcast).
/// @param port The UDP port on which to communicate.
/// @param quiet If TRUE, run without printing any output.
void pot_test_start(ip4_addr_t addr, uint16_t port, bool quiet);

/// @brief Stop the potentiometer test.
void pot_test_stop(void);

#ifdef __cplusplus
}
#endif
#endif /* POT_TEST_H_ */
