/**
 * DMT Generated Driver Source File
 * 
 * @file      dmt.c
 * 
 * @ingroup   dmtdriver
 * 
 * @brief     This is the generated driver source file for DMT driver
 *
 * @skipline @version   PLIB Version 1.0.1
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

// Section: Included Files
#include <xc.h>
#include <stddef.h>
#include "../dmt.h"
#include "../interrupt.h"

// Section: Private Variable Definitions
static bool bPreCleared = false;
uint32_t calibOffset = 0;

// Section: File specific functions

void DMT_Calibrate(void);

// Section: DMT Module APIs
void DMT_Initialize(void)
{ 
	// Instruction fetch counter limit = 0x0
	PSCNT = 0x0UL;
	
	// Window interval limit =  0x0
	PSINTV = 0x0UL;
	
}

void DMT_Enable(void)
{   
    // Set the Bit ON = 1
    DMTCON = 0x8000UL;
	
	INTERRUPT_GlobalDisable();
    DMT_Calibrate();
    INTERRUPT_GlobalEnable();
}

void DMT_PreClear(void)
{
    DMTPRECLR =  0x4000UL;  
  
    // To keep track of Preclear operation is performed
    bPreCleared = true;
}

void DMT_Clear(void)
{
    bPreCleared = false;
    while((DMTSTAT & 0x0001) != 0x0001)
    {
    }
    
    DMTCLR = 0x0008UL;
}

bool DMT_IsWindowOpen(void)
{
    bool status = false;
    
    if((DMTSTAT & 0x0001) == 0x0001)
    {
        status = true;
    }
    
    return status;    
}

bool DMT_IsPreCleared(void)
{
    return bPreCleared;
}

void DMT_PostEventClear(void)
{
	PPPC = 0x4100UL;
	PPC = 0x88UL;
}

uint32_t DMT_TimeoutCounterGet(void)
{  
    return PSCNT;
}

uint32_t DMT_WindowTimeoutCounterGet(void) 
{       
    return PSINTV;
}

uint32_t DMT_StatusGet(void) 
{   
    uint32_t status = 0;
    status = (uint32_t)(DMTSTAT & 0xE1);
    return status;
}

uint32_t DMT_CounterGet(void)
{   
    return DMTCNT;
}

/**
 End of File
*/
