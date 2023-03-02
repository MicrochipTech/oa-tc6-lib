/*
 * Component description for FUSES
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

/* file generated from device description version 2022-04-21T07:58:40Z */
#ifndef _SAMV71_FUSES_COMPONENT_H_
#define _SAMV71_FUSES_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR FUSES                                        */
/* ************************************************************************** */

/* -------- FUSES_GPNVMBITS : (FUSES Offset: 0x00) (R/W 16) GPNVM Bits -------- */
#define FUSES_GPNVMBITS_SECURITY_BIT_Pos      _UINT16_(0)                                          /* (FUSES_GPNVMBITS) Security Bit Position */
#define FUSES_GPNVMBITS_SECURITY_BIT_Msk      (_UINT16_(0x1) << FUSES_GPNVMBITS_SECURITY_BIT_Pos)  /* (FUSES_GPNVMBITS) Security Bit Mask */
#define FUSES_GPNVMBITS_SECURITY_BIT(value)   (FUSES_GPNVMBITS_SECURITY_BIT_Msk & (_UINT16_(value) << FUSES_GPNVMBITS_SECURITY_BIT_Pos)) /* Assigment of value for SECURITY_BIT in the FUSES_GPNVMBITS register */
#define FUSES_GPNVMBITS_BOOT_MODE_Pos         _UINT16_(1)                                          /* (FUSES_GPNVMBITS) Boot Mode Selection Position */
#define FUSES_GPNVMBITS_BOOT_MODE_Msk         (_UINT16_(0x1) << FUSES_GPNVMBITS_BOOT_MODE_Pos)     /* (FUSES_GPNVMBITS) Boot Mode Selection Mask */
#define FUSES_GPNVMBITS_BOOT_MODE(value)      (FUSES_GPNVMBITS_BOOT_MODE_Msk & (_UINT16_(value) << FUSES_GPNVMBITS_BOOT_MODE_Pos)) /* Assigment of value for BOOT_MODE in the FUSES_GPNVMBITS register */
#define FUSES_GPNVMBITS_TCM_CONFIGURATION_Pos _UINT16_(7)                                          /* (FUSES_GPNVMBITS) TCM Configuration Position */
#define FUSES_GPNVMBITS_TCM_CONFIGURATION_Msk (_UINT16_(0x3) << FUSES_GPNVMBITS_TCM_CONFIGURATION_Pos) /* (FUSES_GPNVMBITS) TCM Configuration Mask */
#define FUSES_GPNVMBITS_TCM_CONFIGURATION(value) (FUSES_GPNVMBITS_TCM_CONFIGURATION_Msk & (_UINT16_(value) << FUSES_GPNVMBITS_TCM_CONFIGURATION_Pos)) /* Assigment of value for TCM_CONFIGURATION in the FUSES_GPNVMBITS register */
#define FUSES_GPNVMBITS_Msk                   _UINT16_(0x0183)                                     /* (FUSES_GPNVMBITS) Register Mask  */


/** \brief FUSES register offsets definitions */
#define FUSES_GPNVMBITS_REG_OFST       _UINT32_(0x00)      /* (FUSES_GPNVMBITS) GPNVM Bits Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief GPNVMBITS register API structure */
typedef struct
{  /* GPNVM Bits */
  __IO  uint16_t                       FUSES_GPNVMBITS;    /**< Offset: 0x00 (R/W  16) GPNVM Bits */
} fuses_gpnvmbits_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMV71_FUSES_COMPONENT_H_ */
