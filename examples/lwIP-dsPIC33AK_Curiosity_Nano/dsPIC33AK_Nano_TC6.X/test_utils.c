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
 Utilities functions.

  Company:
    Microchip Technology Inc.

  File Name:
    test_utils.c

  Summary:
    Utilities functions.

  Description:
    Utilities functions.
*******************************************************************************/

#include <stddef.h>                     // Defines NULL
#include <stdint.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <string.h>
#include "test_utils.h"

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*                      DEFINES AND LOCAL VARIABLES                     */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

uint16_t get_short(uint16_t *shortval)
{
    uint16_t val = 0U;
    uint8_t *v = (uint8_t *)shortval;

    for (uint16_t i = 0U; i < sizeof(uint16_t); i++)
    {
        val |= (uint16_t)*v << (i * 8U);
        v++;
    }

    return val;
}

uint32_t get_long(uint32_t *longval)
{
    uint32_t val = 0UL;
    uint8_t *v = (uint8_t *)longval;

    for (uint32_t i = 0U; i < sizeof(uint32_t); i++)
    {
        val |= (uint32_t)*v << (i * 8UL);
        v++;
    }

    return val;
}

bool compare_shorts(uint16_t *v1, uint16_t *v2)
{
    bool retval = true;

    uint8_t *vv1 = (uint8_t *)v1;
    uint8_t *vv2 = (uint8_t *)v2;

    for (uint8_t i = 0U; i < sizeof(uint16_t); i++)
    {
        if (*vv1 != *vv2)
        {
            retval = false;
            break;
        };

        vv1++;
        vv2++;
    }

    return retval;
}

bool compare_longs(uint32_t *v1, uint32_t *v2)
{
    bool retval = true;
    uint8_t *vv1 = (uint8_t *)v1;
    uint8_t *vv2 = (uint8_t *)v2;

    for (uint8_t i = 0U; i < sizeof(uint32_t); i++)
    {
        if (*vv1 != *vv2)
        {
            retval = false;
            break;
        };

        vv1++;
        vv2++;
    }

    return retval;
}

void build_ip_string(char *ip, ip4_addr_t *addr)
{
    snprintf(ip, 16, "%d.%d.%d.%d", ip4_addr1(addr), ip4_addr2(addr), ip4_addr3(addr), ip4_addr4(addr));
}
