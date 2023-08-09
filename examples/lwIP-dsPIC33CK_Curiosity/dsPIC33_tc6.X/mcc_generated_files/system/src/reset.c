/**
 * RESET Generated Driver Source File
 * 
 * @file      reset.c
 *            
 * @ingroup   resetdriver
 *            
 * @brief     This is the generated driver source file for RESET driver
 *            
 * @version   Driver Version 1.0.0
 *            
 * @skipline  Device : dsPIC33CK256MP508
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

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

#include <stdbool.h>
#include <stdint.h>
#include <xc.h>
#include "../reset.h"

// Section: File specific functions


/**
 @ingroup  resetdriver
 @static   RESET cause from trap
 @brief    RESET cause from trap
*/
static bool RESET_CauseFromTrap(uint16_t resetCause)
{
    bool resetStatus = false;
    
    if((uint16_t)(resetCause & (uint16_t) RESET_MASK_TRAPR) == (uint16_t) RESET_MASK_TRAPR)
    { 
        resetStatus = true; 
    }
    
    return resetStatus;
}

/**
 @ingroup  resetdriver
 @static   RESET cause from Illegal Opcode
 @brief    RESET cause from Illegal Opcode   
*/
static bool RESET_CauseFromIllegalOpcode(uint16_t resetCause)
{
    bool resetStatus = false;
    
    if((uint16_t)(resetCause & (uint16_t) RESET_MASK_IOPUWR) == (uint16_t) RESET_MASK_IOPUWR)
    { 
        resetStatus = true; 
    }
    
    return resetStatus;
}

/**
 @ingroup  resetdriver
 @static   RESET cause from Configuration Mismatch
 @brief    RESET cause from Configuration Mismatch  
*/
static bool RESET_CauseFromConfigurationMismatch(uint16_t resetCause)
{
    bool resetStatus = false;
    
    if((uint16_t)(resetCause & (uint16_t) RESET_MASK_CM) == (uint16_t) RESET_MASK_CM)
    { 
        resetStatus = true; 
    }
    
    return resetStatus;
}

/**
 @ingroup  resetdriver
 @static   RESET cause from External
 @brief    RESET cause from External  
*/
static bool RESET_CauseFromExternal(uint16_t resetCause)
{
    bool resetStatus = false;
    
    if((uint16_t)(resetCause & (uint16_t) RESET_MASK_EXTR) == (uint16_t) RESET_MASK_EXTR)
    { 
        resetStatus = true; 
    }
    
    return resetStatus;
}

/**
 @ingroup  resetdriver
 @static   RESET cause from Software
 @brief    RESET cause from Software     
*/
static bool RESET_CauseFromSoftware(uint16_t resetCause)
{
    bool resetStatus = false;
    
    if((uint16_t)(resetCause & (uint16_t) RESET_MASK_SWR) == (uint16_t) RESET_MASK_SWR)
    { 
        resetStatus = true; 
    }
    
    return resetStatus;
}

/**
 @ingroup  resetdriver
 @static   RESET cause from Watchdog Time
 @brief    RESET cause from Watchdog Time  
*/
static bool RESET_CauseFromWatchdogTimer(uint16_t resetCause)
{
    bool resetStatus = false;
    
    if((uint16_t)(resetCause & (uint16_t) RESET_MASK_WDTO) == (uint16_t) RESET_MASK_WDTO)
    { 
      resetStatus = true;
    }
    
    return resetStatus;
}

/**
 @ingroup  resetdriver
 @static   RESET cause from Clear
 @brief    RESET cause from Clear    
*/
static void RESET_CauseClear(enum RESET_MASKS resetFlagMask)
{ 
     RCON = RCON & (~resetFlagMask); 
} 

uint16_t RESET_CauseGet(void)
{
    return RCON;
}

void __attribute__ ((weak)) RESET_CauseHandler(void)
{
    uint16_t resetCause = RESET_CauseGet();
    
    if(RESET_CauseFromTrap(resetCause))
    { 
        RESET_CauseClear(RESET_MASK_TRAPR);
    }
    
    if(RESET_CauseFromIllegalOpcode(resetCause))
    { 
        RESET_CauseClear(RESET_MASK_IOPUWR); 
    }
    
    if(RESET_CauseFromConfigurationMismatch(resetCause))
    { 
        RESET_CauseClear(RESET_MASK_CM); 
    }
    
    if(RESET_CauseFromExternal(resetCause))
    { 
        RESET_CauseClear(RESET_MASK_EXTR); 
    }
    
    if(RESET_CauseFromSoftware(resetCause))
    { 
        RESET_CauseClear(RESET_MASK_SWR); 
    }
    
    if(RESET_CauseFromWatchdogTimer(resetCause))
    { 
        RESET_CauseClear(RESET_MASK_WDTO); 
    }
}

void RESET_CauseClearAll()
{ 
    RCON = 0x00; 
}
/**
 End of File
*/
