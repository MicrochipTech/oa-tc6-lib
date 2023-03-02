;/*******************************************************************************
;
;DMT Generated Driver Header File
; 
; @file      dmt_asm.s
; 
; @defgroup  dmtdriver DMT Driver
; 
; @brief     Assembly language optimized helper routines required for calibration
;
; @version   Driver Version 1.1.0
;
; @skipline  Device : dsPIC33CK256MP508
;
;*******************************************************************************/
;
;// DOM-IGNORE-BEGIN
;/*******************************************************************************
;  Copyright (C) 2016 Microchip Technology Inc.
;
;  MICROCHIP SOFTWARE NOTICE AND DISCLAIMER:  You may use this software, and any
;  derivatives created by any person or entity by or on your behalf, exclusively
;  with Microchip's products.  Microchip and its licensors retain all ownership
;  and intellectual property rights in the accompanying software and in all
;  derivatives here to.
;
;  This software and any accompanying information is for suggestion only.  It
;  does not modify Microchip's standard warranty for its products.  You agree
;  that you are solely responsible for testing the software and determining its
;  suitability.  Microchip has no obligation to modify, test, certify, or
;  support the software.
;
;  THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER
;  EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
;  WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR
;  PURPOSE APPLY TO THIS SOFTWARE, ITS INTERACTION WITH MICROCHIP'S PRODUCTS,
;  COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
;
;  IN NO EVENT, WILL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, WARRANTY, TORT
;  (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT LIABILITY,
;  INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE,
;  EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF
;  ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWSOEVER CAUSED, EVEN IF
;  MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.
;  TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
;  CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF
;  FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
;
;  MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
;  TERMS.
;*******************************************************************************/


/**
 * ;uint32_t  DMT_CalibratedCounterGet(void);
 * Gets the count of DMT counter just before calling CalibratedCounterGet function
 *
 * @return   32-bit (unsigned long) caliberated count
 *                      
 *   Registers used:  w0 w1 w2
 *
 */

    .global         _DMT_CounterGet
    .global         _DMT_CalibratedCounterGet
    .global	        _calibOffset
    .type           _DMT_CalibratedCounterGet, @function
    reset
    
 _DMT_CalibratedCounterGet:
        rcall _DMT_CounterGet
        push w2
        mov _calibOffset, w2
        SUBR w2, w0, w0
        mov #0x0, w2
        SUBBR w2, w1, w1
        pop w2
        return
    
/**
 * ;void  DMT_Calibrate(void);
 * Calculates and stores offset value during DMT_CounterGet function call
 *                      
 *   Registers used:  w0 w1 w2
 *
 */    
    
    .global         _DMT_CounterGet
    .global         _DMT_Calibrate
    .global	        _calibOffset
    .type           _DMT_Calibrate, @function
    .extern         DMTCNTL
    reset
    
 _DMT_Calibrate:
		push w0
		push w1
		push w2
		mov DMTCNTL, w0
		push w0
		rcall _DMT_CounterGet
		pop w2
		sub w0, w2, w2
		dec w2, w2
		mov w2, _calibOffset
		pop w2
		pop w1
		pop w0
		return;

