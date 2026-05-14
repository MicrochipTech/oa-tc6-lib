/**
 * INTERRUPT Generated Driver Source File 
 * 
 * @file      interrupt.c
 *            
 * @ingroup   interruptdriver
 *            
 * @brief     This is the generated driver source file for INTERRUPT driver          
 *
 * @skipline @version   PLIB Version 1.1.0
 *            
 * @skipline  Device : dsPIC33AK512MPS512
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

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
#include "../interrupt.h"

// Section: Driver Interface Function Definitions

void INTERRUPT_Initialize(void)
{
    // DMA1: DMA channel 1 interrupt
    // Priority: 1
    IPC9bits.DMA1IP = 1;
    
    // DMA0: DMA channel 0 interrupt
    // Priority: 1
    IPC9bits.DMA0IP = 1;
    
    // I2C2: I2C 2 General interrupt
    // Priority: 1
    IPC11bits.I2C2IP = 1;
    
    // CNE: Change Notice E interrupt
    // Priority: 1
    IPC39bits.CNEIP = 1;
    
    // T1: Timer 1 interrupt
    // Priority: 1
    IPC6bits.T1IP = 1;
    
    // U1EVT: UART 1 event interrupt
    // Priority: 1
    IPC12bits.U1EVTIP = 1;
    
    // U1E: UART 1 error interrupt
    // Priority: 1
    IPC12bits.U1EIP = 1;
    
    // U1TX: UART 1 TX interrupt
    // Priority: 1
    IPC12bits.U1TXIP = 1;
    
    // U1RX: UART 1 RX interrupt
    // Priority: 1
    IPC12bits.U1RXIP = 1;
    
}

void INTERRUPT_Deinitialize(void)
{
    //POR default value of priority
    IPC9bits.DMA1IP = 4;
    IPC9bits.DMA0IP = 4;
    IPC11bits.I2C2IP = 4;
    IPC39bits.CNEIP = 4;
    IPC6bits.T1IP = 4;
    IPC12bits.U1EVTIP = 4;
    IPC12bits.U1EIP = 4;
    IPC12bits.U1TXIP = 4;
    IPC12bits.U1RXIP = 4;
}
