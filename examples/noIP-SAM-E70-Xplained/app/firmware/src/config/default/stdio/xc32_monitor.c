/*******************************************************************************
 Debug Console Source file

  Company:
    Microchip Technology Inc.

  File Name:
    xc32_monitor.c

  Summary:
    debug console Source File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
#include <stddef.h>
#include <string.h>
#include "definitions.h"

#define BUF_CNT (DRV_USART_QUEUE_SIZE_IDX0)
#define BUF_LEN (128)

extern int read(int handle, void *buffer, unsigned int len);
extern int write(int handle, void * buffer, size_t count);

static DRV_HANDLE m_handle = DRV_HANDLE_INVALID;
static uint8_t m_buf[BUF_CNT][BUF_LEN];
static volatile uint8_t m_pos = 0;

int read(int handle, void *buffer, unsigned int len)
{
   return -1;
}

int write(int handle, void * buffer, size_t count)
{
    int result = -1;
    if (DRV_HANDLE_INVALID == m_handle) {
        m_handle = DRV_USART_Open(0u, DRV_IO_INTENT_EXCLUSIVE);
    }
    if (DRV_HANDLE_INVALID != m_handle) {
        DRV_USART_BUFFER_HANDLE transferHandle = DRV_USART_BUFFER_HANDLE_INVALID;
        uint16_t cpyLen = count;
        if (cpyLen > BUF_LEN) {
            cpyLen = BUF_LEN;
        }
        memcpy(m_buf[m_pos], buffer, cpyLen);
        DRV_USART_WriteBufferAdd(m_handle, m_buf[m_pos], cpyLen, &transferHandle);
        if (transferHandle != DRV_USART_BUFFER_HANDLE_INVALID) {
            m_pos = (m_pos + 1) % BUF_CNT;
            result = cpyLen;
        }
    }
    return result;
}