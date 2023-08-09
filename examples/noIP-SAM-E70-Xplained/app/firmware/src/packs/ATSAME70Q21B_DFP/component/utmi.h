/*
 * Component description for UTMI
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
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

/* file generated from device description version 2023-03-27T04:09:33Z */
#ifndef _SAME70_UTMI_COMPONENT_H_
#define _SAME70_UTMI_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR UTMI                                         */
/* ************************************************************************** */

/* -------- UTMI_OHCIICR : (UTMI Offset: 0x10) (R/W 32) OHCI Interrupt Configuration Register -------- */
#define UTMI_OHCIICR_RES0_Pos                 _UINT32_(0)                                          /* (UTMI_OHCIICR) USB PORTx Reset Position */
#define UTMI_OHCIICR_RES0_Msk                 (_UINT32_(0x1) << UTMI_OHCIICR_RES0_Pos)             /* (UTMI_OHCIICR) USB PORTx Reset Mask */
#define UTMI_OHCIICR_RES0(value)              (UTMI_OHCIICR_RES0_Msk & (_UINT32_(value) << UTMI_OHCIICR_RES0_Pos)) /* Assigment of value for RES0 in the UTMI_OHCIICR register */
#define UTMI_OHCIICR_ARIE_Pos                 _UINT32_(4)                                          /* (UTMI_OHCIICR) OHCI Asynchronous Resume Interrupt Enable Position */
#define UTMI_OHCIICR_ARIE_Msk                 (_UINT32_(0x1) << UTMI_OHCIICR_ARIE_Pos)             /* (UTMI_OHCIICR) OHCI Asynchronous Resume Interrupt Enable Mask */
#define UTMI_OHCIICR_ARIE(value)              (UTMI_OHCIICR_ARIE_Msk & (_UINT32_(value) << UTMI_OHCIICR_ARIE_Pos)) /* Assigment of value for ARIE in the UTMI_OHCIICR register */
#define UTMI_OHCIICR_APPSTART_Pos             _UINT32_(5)                                          /* (UTMI_OHCIICR) Reserved Position */
#define UTMI_OHCIICR_APPSTART_Msk             (_UINT32_(0x1) << UTMI_OHCIICR_APPSTART_Pos)         /* (UTMI_OHCIICR) Reserved Mask */
#define UTMI_OHCIICR_APPSTART(value)          (UTMI_OHCIICR_APPSTART_Msk & (_UINT32_(value) << UTMI_OHCIICR_APPSTART_Pos)) /* Assigment of value for APPSTART in the UTMI_OHCIICR register */
#define UTMI_OHCIICR_UDPPUDIS_Pos             _UINT32_(23)                                         /* (UTMI_OHCIICR) USB Device Pull-up Disable Position */
#define UTMI_OHCIICR_UDPPUDIS_Msk             (_UINT32_(0x1) << UTMI_OHCIICR_UDPPUDIS_Pos)         /* (UTMI_OHCIICR) USB Device Pull-up Disable Mask */
#define UTMI_OHCIICR_UDPPUDIS(value)          (UTMI_OHCIICR_UDPPUDIS_Msk & (_UINT32_(value) << UTMI_OHCIICR_UDPPUDIS_Pos)) /* Assigment of value for UDPPUDIS in the UTMI_OHCIICR register */
#define UTMI_OHCIICR_Msk                      _UINT32_(0x00800031)                                 /* (UTMI_OHCIICR) Register Mask  */

#define UTMI_OHCIICR_RES_Pos                  _UINT32_(0)                                          /* (UTMI_OHCIICR Position) USB PORTx Reset */
#define UTMI_OHCIICR_RES_Msk                  (_UINT32_(0x1) << UTMI_OHCIICR_RES_Pos)              /* (UTMI_OHCIICR Mask) RES */
#define UTMI_OHCIICR_RES(value)               (UTMI_OHCIICR_RES_Msk & (_UINT32_(value) << UTMI_OHCIICR_RES_Pos)) 

/* -------- UTMI_CKTRIM : (UTMI Offset: 0x30) (R/W 32) UTMI Clock Trimming Register -------- */
#define UTMI_CKTRIM_FREQ_Pos                  _UINT32_(0)                                          /* (UTMI_CKTRIM) UTMI Reference Clock Frequency Position */
#define UTMI_CKTRIM_FREQ_Msk                  (_UINT32_(0x3) << UTMI_CKTRIM_FREQ_Pos)              /* (UTMI_CKTRIM) UTMI Reference Clock Frequency Mask */
#define UTMI_CKTRIM_FREQ(value)               (UTMI_CKTRIM_FREQ_Msk & (_UINT32_(value) << UTMI_CKTRIM_FREQ_Pos)) /* Assigment of value for FREQ in the UTMI_CKTRIM register */
#define   UTMI_CKTRIM_FREQ_XTAL12_Val         _UINT32_(0x0)                                        /* (UTMI_CKTRIM) 12 MHz reference clock  */
#define   UTMI_CKTRIM_FREQ_XTAL16_Val         _UINT32_(0x1)                                        /* (UTMI_CKTRIM) 16 MHz reference clock  */
#define UTMI_CKTRIM_FREQ_XTAL12               (UTMI_CKTRIM_FREQ_XTAL12_Val << UTMI_CKTRIM_FREQ_Pos) /* (UTMI_CKTRIM) 12 MHz reference clock Position  */
#define UTMI_CKTRIM_FREQ_XTAL16               (UTMI_CKTRIM_FREQ_XTAL16_Val << UTMI_CKTRIM_FREQ_Pos) /* (UTMI_CKTRIM) 16 MHz reference clock Position  */
#define UTMI_CKTRIM_Msk                       _UINT32_(0x00000003)                                 /* (UTMI_CKTRIM) Register Mask  */


/** \brief UTMI register offsets definitions */
#define UTMI_OHCIICR_REG_OFST          _UINT32_(0x10)      /* (UTMI_OHCIICR) OHCI Interrupt Configuration Register Offset */
#define UTMI_CKTRIM_REG_OFST           _UINT32_(0x30)      /* (UTMI_CKTRIM) UTMI Clock Trimming Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief UTMI register API structure */
typedef struct
{
  __I   uint8_t                        Reserved1[0x10];
  __IO  uint32_t                       UTMI_OHCIICR;       /**< Offset: 0x10 (R/W  32) OHCI Interrupt Configuration Register */
  __I   uint8_t                        Reserved2[0x1C];
  __IO  uint32_t                       UTMI_CKTRIM;        /**< Offset: 0x30 (R/W  32) UTMI Clock Trimming Register */
} utmi_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME70_UTMI_COMPONENT_H_ */
