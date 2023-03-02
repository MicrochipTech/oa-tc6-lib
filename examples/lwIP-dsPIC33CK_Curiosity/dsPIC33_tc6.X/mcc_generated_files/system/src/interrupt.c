/**
 * INTERRUPT Generated Driver Source File 
 * 
 * @file      interrupt.c
 *            
 * @ingroup   interruptdriver
 *            
 * @brief     This is the generated driver source file for INTERRUPT driver
 *            
 * @version   Driver Version 1.1.0
 *            
 * @skipline  Device : dsPIC33CK256MP508
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

// Section: Includes
#include <xc.h>
#include "../interrupt.h"

// Section: Driver Interface Function Definitions

void INTERRUPT_Initialize(void)
{
    // DMA1: DMA Channel 1
    // Priority: 1
    IPC2bits.DMA1IP = 1;
    
    // DMA0: DMA Channel 0
    // Priority: 1
    IPC1bits.DMA0IP = 1;
    
    // DMT: Dead Man Timer
    // Priority: 1
    IPC11bits.DMTIP = 1;
    
    // CNE: Change Notification E
    // Priority: 1
    IPC19bits.CNEIP = 1;
    
    // CCT1: CCP1 Timer Event
    // Priority: 1
    IPC1bits.CCT1IP = 1;
    
    // U1EVT: UART1 Event
    // Priority: 1
    IPC47bits.U1EVTIP = 1;
    
    // U1E: UART1 Error
    // Priority: 1
    IPC12bits.U1EIP = 1;
    
    // U1TX: UART1 TX
    // Priority: 1
    IPC3bits.U1TXIP = 1;
    
    // U1RX: UART1 RX
    // Priority: 1
    IPC2bits.U1RXIP = 1;
    
}

void INTERRUPT_Deinitialize(void)
{
    //POR default value of priority
    IPC2bits.DMA1IP = 4;
    IPC1bits.DMA0IP = 4;
    IPC11bits.DMTIP = 4;
    IPC19bits.CNEIP = 4;
    IPC1bits.CCT1IP = 4;
    IPC47bits.U1EVTIP = 4;
    IPC12bits.U1EIP = 4;
    IPC3bits.U1TXIP = 4;
    IPC2bits.U1RXIP = 4;
}
