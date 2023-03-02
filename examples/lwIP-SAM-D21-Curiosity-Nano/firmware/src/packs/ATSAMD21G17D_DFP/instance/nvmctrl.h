/*
 * Instance header file for ATSAMD21J17D
 *
 * Copyright (c) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2020-11-19T13:00:05Z */
#ifndef _SAMD21_NVMCTRL_INSTANCE_
#define _SAMD21_NVMCTRL_INSTANCE_


/* ========== Instance Parameter definitions for NVMCTRL peripheral ========== */
#define NVMCTRL_FACTORY_WORD_IMPLEMENTED_MASK    (0xC0000007FFFFFFFF) 
#define NVMCTRL_PMSB                             (3)        
#define NVMCTRL_PSZ_BITS                         (6)        
#define NVMCTRL_ROW_PAGES                        (4)        
#define NVMCTRL_USER_PAGE_OFFSET                 (0x00800000) 
#define NVMCTRL_USER_WORD_IMPLEMENTED_MASK       (0xC01FFFFFFFFFFFFF) 
#define NVMCTRL_RWWEE_PAGES                      (64)       /* Page size */
#define NVMCTRL_RWWEE_ROW_SIZE                   (256)      
#define NVMCTRL_RWW_EEPROM_ADDR                  (0x00400000) /* Start address of the WWR EEPROM area */
#define NVMCTRL_RWW_EEPROM_SIZE                  (4096)     /* Byte size of the WWR EEPROM area */
#define NVMCTRL_FLASH_SIZE                       (131072)   
#define NVMCTRL_PAGE_SIZE                        (64)       
#define NVMCTRL_PAGES                            (2048)     
#define NVMCTRL_PAGES_PR_REGION                  (128)      
#define NVMCTRL_ROW_SIZE                         (256)      
#define NVMCTRL_PSM_0_FRMFW_FWS_1_MAX_FREQ       (12000000) 
#define NVMCTRL_PSM_0_FRMLP_FWS_0_MAX_FREQ       (18000000) 
#define NVMCTRL_PSM_0_FRMLP_FWS_1_MAX_FREQ       (36000000) 
#define NVMCTRL_PSM_0_FRMHS_FWS_0_MAX_FREQ       (25000000) 
#define NVMCTRL_PSM_0_FRMHS_FWS_1_MAX_FREQ       (50000000) 
#define NVMCTRL_PSM_1_FRMFW_FWS_1_MAX_FREQ       (12000000) 
#define NVMCTRL_PSM_1_FRMLP_FWS_0_MAX_FREQ       (8000000)  
#define NVMCTRL_PSM_1_FRMLP_FWS_1_MAX_FREQ       (12000000) 
#define NVMCTRL_INSTANCE_ID                      (34)       

#endif /* _SAMD21_NVMCTRL_INSTANCE_ */
