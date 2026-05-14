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
  Utility functions header file.

  Company:
    Microchip Technology Inc.

  File Name:
    test_utils.h

  Summary:
    Utility functions header file

  Description:
    Utility functions header file.
*******************************************************************************/

#ifndef TEST_UTILS_H_
#define TEST_UTILS_H_

#include <stdint.h>
#include <stdbool.h>
#include "lwip/ip4_addr.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ESC_CLEAR_TERMINAL          "\033[2J"
#define ESC_CURSOR_X1Y1             "\033[1;1H"
#define ESC_HIDE_CURSOR             "\033[?25l"
#define ESC_CLEAR_LINE              "\033[2K"
#define ESC_RESETCOLOR              "\033[0m"
#define ESC_GREEN                   "\033[0;32m"
#define ESC_RED                     "\033[0;31m"
#define ESC_YELLOW                  "\033[1;33m"
#define ESC_BLUE                    "\033[0;36m"

#define PRINT(...)                  printf(__VA_ARGS__)

#define TEST_BROADCAST_ADDRESS      (0xFFFFFFFFUL)
#define TEST_UNICAST_ADDRESS_1      (0xC0A80064UL) // 192.168.0.100
#define TEST_UNICAST_ADDRESS_2      (0xC0A80065UL) // 192.168.0.101

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                            PUBLIC API                                */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

/// @brief Gets the 16 bit value at a given address.
///        This allows for fetch without regard to byte alignment.
/// @param shortval The pointer to the 16-bit value.
/// @return The 16-bit value at the given address.
uint16_t get_short(uint16_t *shortval);

/// @brief Gets the 32 bit value at a given address.
///        This allows for fetch without regard to byte alignment.
/// @param longval The pointer to the 16-bit value.
/// @return The 32-bit value at the given address.
uint32_t get_long(uint32_t *longval);

/// @brief Compare two 16 bit values in a byte stream.
///        This allows for compare without regard to byte alignment.
/// @param v1 The first value to compare.
/// @param v2 The second value to compare.
/// @return TRUE if the values are equal, FALSE if not.
bool compare_shorts(uint16_t *v1, uint16_t *v2);

/// @brief Compare two 32 bit values in a byte stream.
///        This allows for compare without regard to byte alignment.
/// @param v1 The first value to compare.
/// @param v2 The second value to compare.
/// @return TRUE if the values are equal, FALSE if not.
bool compare_longs(uint32_t *v1, uint32_t *v2);

/// @brief Build a IP string from an IP address.
/// @param ip The string into which to build the IP address.
/// @param addr The IP4 address value.
void build_ip_string(char *ip, ip4_addr_t *addr);

#ifdef __cplusplus
}
#endif
#endif /* TEST_UTILS_H_ */
