/*
 * Component description for USBHS
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
#ifndef _SAMV71_USBHS_COMPONENT_H_
#define _SAMV71_USBHS_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR USBHS                                        */
/* ************************************************************************** */

/* -------- USBHS_DEVDMANXTDSC : (USBHS Offset: 0x00) (R/W 32) Device DMA Channel Next Descriptor Address Register -------- */
#define USBHS_DEVDMANXTDSC_NXT_DSC_ADD_Pos    _UINT32_(0)                                          /* (USBHS_DEVDMANXTDSC) Next Descriptor Address Position */
#define USBHS_DEVDMANXTDSC_NXT_DSC_ADD_Msk    (_UINT32_(0xFFFFFFFF) << USBHS_DEVDMANXTDSC_NXT_DSC_ADD_Pos) /* (USBHS_DEVDMANXTDSC) Next Descriptor Address Mask */
#define USBHS_DEVDMANXTDSC_NXT_DSC_ADD(value) (USBHS_DEVDMANXTDSC_NXT_DSC_ADD_Msk & (_UINT32_(value) << USBHS_DEVDMANXTDSC_NXT_DSC_ADD_Pos)) /* Assigment of value for NXT_DSC_ADD in the USBHS_DEVDMANXTDSC register */
#define USBHS_DEVDMANXTDSC_Msk                _UINT32_(0xFFFFFFFF)                                 /* (USBHS_DEVDMANXTDSC) Register Mask  */


/* -------- USBHS_DEVDMAADDRESS : (USBHS Offset: 0x04) (R/W 32) Device DMA Channel Address Register -------- */
#define USBHS_DEVDMAADDRESS_BUFF_ADD_Pos      _UINT32_(0)                                          /* (USBHS_DEVDMAADDRESS) Buffer Address Position */
#define USBHS_DEVDMAADDRESS_BUFF_ADD_Msk      (_UINT32_(0xFFFFFFFF) << USBHS_DEVDMAADDRESS_BUFF_ADD_Pos) /* (USBHS_DEVDMAADDRESS) Buffer Address Mask */
#define USBHS_DEVDMAADDRESS_BUFF_ADD(value)   (USBHS_DEVDMAADDRESS_BUFF_ADD_Msk & (_UINT32_(value) << USBHS_DEVDMAADDRESS_BUFF_ADD_Pos)) /* Assigment of value for BUFF_ADD in the USBHS_DEVDMAADDRESS register */
#define USBHS_DEVDMAADDRESS_Msk               _UINT32_(0xFFFFFFFF)                                 /* (USBHS_DEVDMAADDRESS) Register Mask  */


/* -------- USBHS_DEVDMACONTROL : (USBHS Offset: 0x08) (R/W 32) Device DMA Channel Control Register -------- */
#define USBHS_DEVDMACONTROL_CHANN_ENB_Pos     _UINT32_(0)                                          /* (USBHS_DEVDMACONTROL) Channel Enable Command Position */
#define USBHS_DEVDMACONTROL_CHANN_ENB_Msk     (_UINT32_(0x1) << USBHS_DEVDMACONTROL_CHANN_ENB_Pos) /* (USBHS_DEVDMACONTROL) Channel Enable Command Mask */
#define USBHS_DEVDMACONTROL_CHANN_ENB(value)  (USBHS_DEVDMACONTROL_CHANN_ENB_Msk & (_UINT32_(value) << USBHS_DEVDMACONTROL_CHANN_ENB_Pos)) /* Assigment of value for CHANN_ENB in the USBHS_DEVDMACONTROL register */
#define USBHS_DEVDMACONTROL_LDNXT_DSC_Pos     _UINT32_(1)                                          /* (USBHS_DEVDMACONTROL) Load Next Channel Transfer Descriptor Enable Command Position */
#define USBHS_DEVDMACONTROL_LDNXT_DSC_Msk     (_UINT32_(0x1) << USBHS_DEVDMACONTROL_LDNXT_DSC_Pos) /* (USBHS_DEVDMACONTROL) Load Next Channel Transfer Descriptor Enable Command Mask */
#define USBHS_DEVDMACONTROL_LDNXT_DSC(value)  (USBHS_DEVDMACONTROL_LDNXT_DSC_Msk & (_UINT32_(value) << USBHS_DEVDMACONTROL_LDNXT_DSC_Pos)) /* Assigment of value for LDNXT_DSC in the USBHS_DEVDMACONTROL register */
#define USBHS_DEVDMACONTROL_END_TR_EN_Pos     _UINT32_(2)                                          /* (USBHS_DEVDMACONTROL) End of Transfer Enable Control (OUT transfers only) Position */
#define USBHS_DEVDMACONTROL_END_TR_EN_Msk     (_UINT32_(0x1) << USBHS_DEVDMACONTROL_END_TR_EN_Pos) /* (USBHS_DEVDMACONTROL) End of Transfer Enable Control (OUT transfers only) Mask */
#define USBHS_DEVDMACONTROL_END_TR_EN(value)  (USBHS_DEVDMACONTROL_END_TR_EN_Msk & (_UINT32_(value) << USBHS_DEVDMACONTROL_END_TR_EN_Pos)) /* Assigment of value for END_TR_EN in the USBHS_DEVDMACONTROL register */
#define USBHS_DEVDMACONTROL_END_B_EN_Pos      _UINT32_(3)                                          /* (USBHS_DEVDMACONTROL) End of Buffer Enable Control Position */
#define USBHS_DEVDMACONTROL_END_B_EN_Msk      (_UINT32_(0x1) << USBHS_DEVDMACONTROL_END_B_EN_Pos)  /* (USBHS_DEVDMACONTROL) End of Buffer Enable Control Mask */
#define USBHS_DEVDMACONTROL_END_B_EN(value)   (USBHS_DEVDMACONTROL_END_B_EN_Msk & (_UINT32_(value) << USBHS_DEVDMACONTROL_END_B_EN_Pos)) /* Assigment of value for END_B_EN in the USBHS_DEVDMACONTROL register */
#define USBHS_DEVDMACONTROL_END_TR_IT_Pos     _UINT32_(4)                                          /* (USBHS_DEVDMACONTROL) End of Transfer Interrupt Enable Position */
#define USBHS_DEVDMACONTROL_END_TR_IT_Msk     (_UINT32_(0x1) << USBHS_DEVDMACONTROL_END_TR_IT_Pos) /* (USBHS_DEVDMACONTROL) End of Transfer Interrupt Enable Mask */
#define USBHS_DEVDMACONTROL_END_TR_IT(value)  (USBHS_DEVDMACONTROL_END_TR_IT_Msk & (_UINT32_(value) << USBHS_DEVDMACONTROL_END_TR_IT_Pos)) /* Assigment of value for END_TR_IT in the USBHS_DEVDMACONTROL register */
#define USBHS_DEVDMACONTROL_END_BUFFIT_Pos    _UINT32_(5)                                          /* (USBHS_DEVDMACONTROL) End of Buffer Interrupt Enable Position */
#define USBHS_DEVDMACONTROL_END_BUFFIT_Msk    (_UINT32_(0x1) << USBHS_DEVDMACONTROL_END_BUFFIT_Pos) /* (USBHS_DEVDMACONTROL) End of Buffer Interrupt Enable Mask */
#define USBHS_DEVDMACONTROL_END_BUFFIT(value) (USBHS_DEVDMACONTROL_END_BUFFIT_Msk & (_UINT32_(value) << USBHS_DEVDMACONTROL_END_BUFFIT_Pos)) /* Assigment of value for END_BUFFIT in the USBHS_DEVDMACONTROL register */
#define USBHS_DEVDMACONTROL_DESC_LD_IT_Pos    _UINT32_(6)                                          /* (USBHS_DEVDMACONTROL) Descriptor Loaded Interrupt Enable Position */
#define USBHS_DEVDMACONTROL_DESC_LD_IT_Msk    (_UINT32_(0x1) << USBHS_DEVDMACONTROL_DESC_LD_IT_Pos) /* (USBHS_DEVDMACONTROL) Descriptor Loaded Interrupt Enable Mask */
#define USBHS_DEVDMACONTROL_DESC_LD_IT(value) (USBHS_DEVDMACONTROL_DESC_LD_IT_Msk & (_UINT32_(value) << USBHS_DEVDMACONTROL_DESC_LD_IT_Pos)) /* Assigment of value for DESC_LD_IT in the USBHS_DEVDMACONTROL register */
#define USBHS_DEVDMACONTROL_BURST_LCK_Pos     _UINT32_(7)                                          /* (USBHS_DEVDMACONTROL) Burst Lock Enable Position */
#define USBHS_DEVDMACONTROL_BURST_LCK_Msk     (_UINT32_(0x1) << USBHS_DEVDMACONTROL_BURST_LCK_Pos) /* (USBHS_DEVDMACONTROL) Burst Lock Enable Mask */
#define USBHS_DEVDMACONTROL_BURST_LCK(value)  (USBHS_DEVDMACONTROL_BURST_LCK_Msk & (_UINT32_(value) << USBHS_DEVDMACONTROL_BURST_LCK_Pos)) /* Assigment of value for BURST_LCK in the USBHS_DEVDMACONTROL register */
#define USBHS_DEVDMACONTROL_BUFF_LENGTH_Pos   _UINT32_(16)                                         /* (USBHS_DEVDMACONTROL) Buffer Byte Length (Write-only) Position */
#define USBHS_DEVDMACONTROL_BUFF_LENGTH_Msk   (_UINT32_(0xFFFF) << USBHS_DEVDMACONTROL_BUFF_LENGTH_Pos) /* (USBHS_DEVDMACONTROL) Buffer Byte Length (Write-only) Mask */
#define USBHS_DEVDMACONTROL_BUFF_LENGTH(value) (USBHS_DEVDMACONTROL_BUFF_LENGTH_Msk & (_UINT32_(value) << USBHS_DEVDMACONTROL_BUFF_LENGTH_Pos)) /* Assigment of value for BUFF_LENGTH in the USBHS_DEVDMACONTROL register */
#define USBHS_DEVDMACONTROL_Msk               _UINT32_(0xFFFF00FF)                                 /* (USBHS_DEVDMACONTROL) Register Mask  */


/* -------- USBHS_DEVDMASTATUS : (USBHS Offset: 0x0C) (R/W 32) Device DMA Channel Status Register -------- */
#define USBHS_DEVDMASTATUS_CHANN_ENB_Pos      _UINT32_(0)                                          /* (USBHS_DEVDMASTATUS) Channel Enable Status Position */
#define USBHS_DEVDMASTATUS_CHANN_ENB_Msk      (_UINT32_(0x1) << USBHS_DEVDMASTATUS_CHANN_ENB_Pos)  /* (USBHS_DEVDMASTATUS) Channel Enable Status Mask */
#define USBHS_DEVDMASTATUS_CHANN_ENB(value)   (USBHS_DEVDMASTATUS_CHANN_ENB_Msk & (_UINT32_(value) << USBHS_DEVDMASTATUS_CHANN_ENB_Pos)) /* Assigment of value for CHANN_ENB in the USBHS_DEVDMASTATUS register */
#define USBHS_DEVDMASTATUS_CHANN_ACT_Pos      _UINT32_(1)                                          /* (USBHS_DEVDMASTATUS) Channel Active Status Position */
#define USBHS_DEVDMASTATUS_CHANN_ACT_Msk      (_UINT32_(0x1) << USBHS_DEVDMASTATUS_CHANN_ACT_Pos)  /* (USBHS_DEVDMASTATUS) Channel Active Status Mask */
#define USBHS_DEVDMASTATUS_CHANN_ACT(value)   (USBHS_DEVDMASTATUS_CHANN_ACT_Msk & (_UINT32_(value) << USBHS_DEVDMASTATUS_CHANN_ACT_Pos)) /* Assigment of value for CHANN_ACT in the USBHS_DEVDMASTATUS register */
#define USBHS_DEVDMASTATUS_END_TR_ST_Pos      _UINT32_(4)                                          /* (USBHS_DEVDMASTATUS) End of Channel Transfer Status Position */
#define USBHS_DEVDMASTATUS_END_TR_ST_Msk      (_UINT32_(0x1) << USBHS_DEVDMASTATUS_END_TR_ST_Pos)  /* (USBHS_DEVDMASTATUS) End of Channel Transfer Status Mask */
#define USBHS_DEVDMASTATUS_END_TR_ST(value)   (USBHS_DEVDMASTATUS_END_TR_ST_Msk & (_UINT32_(value) << USBHS_DEVDMASTATUS_END_TR_ST_Pos)) /* Assigment of value for END_TR_ST in the USBHS_DEVDMASTATUS register */
#define USBHS_DEVDMASTATUS_END_BF_ST_Pos      _UINT32_(5)                                          /* (USBHS_DEVDMASTATUS) End of Channel Buffer Status Position */
#define USBHS_DEVDMASTATUS_END_BF_ST_Msk      (_UINT32_(0x1) << USBHS_DEVDMASTATUS_END_BF_ST_Pos)  /* (USBHS_DEVDMASTATUS) End of Channel Buffer Status Mask */
#define USBHS_DEVDMASTATUS_END_BF_ST(value)   (USBHS_DEVDMASTATUS_END_BF_ST_Msk & (_UINT32_(value) << USBHS_DEVDMASTATUS_END_BF_ST_Pos)) /* Assigment of value for END_BF_ST in the USBHS_DEVDMASTATUS register */
#define USBHS_DEVDMASTATUS_DESC_LDST_Pos      _UINT32_(6)                                          /* (USBHS_DEVDMASTATUS) Descriptor Loaded Status Position */
#define USBHS_DEVDMASTATUS_DESC_LDST_Msk      (_UINT32_(0x1) << USBHS_DEVDMASTATUS_DESC_LDST_Pos)  /* (USBHS_DEVDMASTATUS) Descriptor Loaded Status Mask */
#define USBHS_DEVDMASTATUS_DESC_LDST(value)   (USBHS_DEVDMASTATUS_DESC_LDST_Msk & (_UINT32_(value) << USBHS_DEVDMASTATUS_DESC_LDST_Pos)) /* Assigment of value for DESC_LDST in the USBHS_DEVDMASTATUS register */
#define USBHS_DEVDMASTATUS_BUFF_COUNT_Pos     _UINT32_(16)                                         /* (USBHS_DEVDMASTATUS) Buffer Byte Count Position */
#define USBHS_DEVDMASTATUS_BUFF_COUNT_Msk     (_UINT32_(0xFFFF) << USBHS_DEVDMASTATUS_BUFF_COUNT_Pos) /* (USBHS_DEVDMASTATUS) Buffer Byte Count Mask */
#define USBHS_DEVDMASTATUS_BUFF_COUNT(value)  (USBHS_DEVDMASTATUS_BUFF_COUNT_Msk & (_UINT32_(value) << USBHS_DEVDMASTATUS_BUFF_COUNT_Pos)) /* Assigment of value for BUFF_COUNT in the USBHS_DEVDMASTATUS register */
#define USBHS_DEVDMASTATUS_Msk                _UINT32_(0xFFFF0073)                                 /* (USBHS_DEVDMASTATUS) Register Mask  */


/* -------- USBHS_HSTDMANXTDSC : (USBHS Offset: 0x00) (R/W 32) Host DMA Channel Next Descriptor Address Register -------- */
#define USBHS_HSTDMANXTDSC_NXT_DSC_ADD_Pos    _UINT32_(0)                                          /* (USBHS_HSTDMANXTDSC) Next Descriptor Address Position */
#define USBHS_HSTDMANXTDSC_NXT_DSC_ADD_Msk    (_UINT32_(0xFFFFFFFF) << USBHS_HSTDMANXTDSC_NXT_DSC_ADD_Pos) /* (USBHS_HSTDMANXTDSC) Next Descriptor Address Mask */
#define USBHS_HSTDMANXTDSC_NXT_DSC_ADD(value) (USBHS_HSTDMANXTDSC_NXT_DSC_ADD_Msk & (_UINT32_(value) << USBHS_HSTDMANXTDSC_NXT_DSC_ADD_Pos)) /* Assigment of value for NXT_DSC_ADD in the USBHS_HSTDMANXTDSC register */
#define USBHS_HSTDMANXTDSC_Msk                _UINT32_(0xFFFFFFFF)                                 /* (USBHS_HSTDMANXTDSC) Register Mask  */


/* -------- USBHS_HSTDMAADDRESS : (USBHS Offset: 0x04) (R/W 32) Host DMA Channel Address Register -------- */
#define USBHS_HSTDMAADDRESS_BUFF_ADD_Pos      _UINT32_(0)                                          /* (USBHS_HSTDMAADDRESS) Buffer Address Position */
#define USBHS_HSTDMAADDRESS_BUFF_ADD_Msk      (_UINT32_(0xFFFFFFFF) << USBHS_HSTDMAADDRESS_BUFF_ADD_Pos) /* (USBHS_HSTDMAADDRESS) Buffer Address Mask */
#define USBHS_HSTDMAADDRESS_BUFF_ADD(value)   (USBHS_HSTDMAADDRESS_BUFF_ADD_Msk & (_UINT32_(value) << USBHS_HSTDMAADDRESS_BUFF_ADD_Pos)) /* Assigment of value for BUFF_ADD in the USBHS_HSTDMAADDRESS register */
#define USBHS_HSTDMAADDRESS_Msk               _UINT32_(0xFFFFFFFF)                                 /* (USBHS_HSTDMAADDRESS) Register Mask  */


/* -------- USBHS_HSTDMACONTROL : (USBHS Offset: 0x08) (R/W 32) Host DMA Channel Control Register -------- */
#define USBHS_HSTDMACONTROL_CHANN_ENB_Pos     _UINT32_(0)                                          /* (USBHS_HSTDMACONTROL) Channel Enable Command Position */
#define USBHS_HSTDMACONTROL_CHANN_ENB_Msk     (_UINT32_(0x1) << USBHS_HSTDMACONTROL_CHANN_ENB_Pos) /* (USBHS_HSTDMACONTROL) Channel Enable Command Mask */
#define USBHS_HSTDMACONTROL_CHANN_ENB(value)  (USBHS_HSTDMACONTROL_CHANN_ENB_Msk & (_UINT32_(value) << USBHS_HSTDMACONTROL_CHANN_ENB_Pos)) /* Assigment of value for CHANN_ENB in the USBHS_HSTDMACONTROL register */
#define USBHS_HSTDMACONTROL_LDNXT_DSC_Pos     _UINT32_(1)                                          /* (USBHS_HSTDMACONTROL) Load Next Channel Transfer Descriptor Enable Command Position */
#define USBHS_HSTDMACONTROL_LDNXT_DSC_Msk     (_UINT32_(0x1) << USBHS_HSTDMACONTROL_LDNXT_DSC_Pos) /* (USBHS_HSTDMACONTROL) Load Next Channel Transfer Descriptor Enable Command Mask */
#define USBHS_HSTDMACONTROL_LDNXT_DSC(value)  (USBHS_HSTDMACONTROL_LDNXT_DSC_Msk & (_UINT32_(value) << USBHS_HSTDMACONTROL_LDNXT_DSC_Pos)) /* Assigment of value for LDNXT_DSC in the USBHS_HSTDMACONTROL register */
#define USBHS_HSTDMACONTROL_END_TR_EN_Pos     _UINT32_(2)                                          /* (USBHS_HSTDMACONTROL) End of Transfer Enable Control (OUT transfers only) Position */
#define USBHS_HSTDMACONTROL_END_TR_EN_Msk     (_UINT32_(0x1) << USBHS_HSTDMACONTROL_END_TR_EN_Pos) /* (USBHS_HSTDMACONTROL) End of Transfer Enable Control (OUT transfers only) Mask */
#define USBHS_HSTDMACONTROL_END_TR_EN(value)  (USBHS_HSTDMACONTROL_END_TR_EN_Msk & (_UINT32_(value) << USBHS_HSTDMACONTROL_END_TR_EN_Pos)) /* Assigment of value for END_TR_EN in the USBHS_HSTDMACONTROL register */
#define USBHS_HSTDMACONTROL_END_B_EN_Pos      _UINT32_(3)                                          /* (USBHS_HSTDMACONTROL) End of Buffer Enable Control Position */
#define USBHS_HSTDMACONTROL_END_B_EN_Msk      (_UINT32_(0x1) << USBHS_HSTDMACONTROL_END_B_EN_Pos)  /* (USBHS_HSTDMACONTROL) End of Buffer Enable Control Mask */
#define USBHS_HSTDMACONTROL_END_B_EN(value)   (USBHS_HSTDMACONTROL_END_B_EN_Msk & (_UINT32_(value) << USBHS_HSTDMACONTROL_END_B_EN_Pos)) /* Assigment of value for END_B_EN in the USBHS_HSTDMACONTROL register */
#define USBHS_HSTDMACONTROL_END_TR_IT_Pos     _UINT32_(4)                                          /* (USBHS_HSTDMACONTROL) End of Transfer Interrupt Enable Position */
#define USBHS_HSTDMACONTROL_END_TR_IT_Msk     (_UINT32_(0x1) << USBHS_HSTDMACONTROL_END_TR_IT_Pos) /* (USBHS_HSTDMACONTROL) End of Transfer Interrupt Enable Mask */
#define USBHS_HSTDMACONTROL_END_TR_IT(value)  (USBHS_HSTDMACONTROL_END_TR_IT_Msk & (_UINT32_(value) << USBHS_HSTDMACONTROL_END_TR_IT_Pos)) /* Assigment of value for END_TR_IT in the USBHS_HSTDMACONTROL register */
#define USBHS_HSTDMACONTROL_END_BUFFIT_Pos    _UINT32_(5)                                          /* (USBHS_HSTDMACONTROL) End of Buffer Interrupt Enable Position */
#define USBHS_HSTDMACONTROL_END_BUFFIT_Msk    (_UINT32_(0x1) << USBHS_HSTDMACONTROL_END_BUFFIT_Pos) /* (USBHS_HSTDMACONTROL) End of Buffer Interrupt Enable Mask */
#define USBHS_HSTDMACONTROL_END_BUFFIT(value) (USBHS_HSTDMACONTROL_END_BUFFIT_Msk & (_UINT32_(value) << USBHS_HSTDMACONTROL_END_BUFFIT_Pos)) /* Assigment of value for END_BUFFIT in the USBHS_HSTDMACONTROL register */
#define USBHS_HSTDMACONTROL_DESC_LD_IT_Pos    _UINT32_(6)                                          /* (USBHS_HSTDMACONTROL) Descriptor Loaded Interrupt Enable Position */
#define USBHS_HSTDMACONTROL_DESC_LD_IT_Msk    (_UINT32_(0x1) << USBHS_HSTDMACONTROL_DESC_LD_IT_Pos) /* (USBHS_HSTDMACONTROL) Descriptor Loaded Interrupt Enable Mask */
#define USBHS_HSTDMACONTROL_DESC_LD_IT(value) (USBHS_HSTDMACONTROL_DESC_LD_IT_Msk & (_UINT32_(value) << USBHS_HSTDMACONTROL_DESC_LD_IT_Pos)) /* Assigment of value for DESC_LD_IT in the USBHS_HSTDMACONTROL register */
#define USBHS_HSTDMACONTROL_BURST_LCK_Pos     _UINT32_(7)                                          /* (USBHS_HSTDMACONTROL) Burst Lock Enable Position */
#define USBHS_HSTDMACONTROL_BURST_LCK_Msk     (_UINT32_(0x1) << USBHS_HSTDMACONTROL_BURST_LCK_Pos) /* (USBHS_HSTDMACONTROL) Burst Lock Enable Mask */
#define USBHS_HSTDMACONTROL_BURST_LCK(value)  (USBHS_HSTDMACONTROL_BURST_LCK_Msk & (_UINT32_(value) << USBHS_HSTDMACONTROL_BURST_LCK_Pos)) /* Assigment of value for BURST_LCK in the USBHS_HSTDMACONTROL register */
#define USBHS_HSTDMACONTROL_BUFF_LENGTH_Pos   _UINT32_(16)                                         /* (USBHS_HSTDMACONTROL) Buffer Byte Length (Write-only) Position */
#define USBHS_HSTDMACONTROL_BUFF_LENGTH_Msk   (_UINT32_(0xFFFF) << USBHS_HSTDMACONTROL_BUFF_LENGTH_Pos) /* (USBHS_HSTDMACONTROL) Buffer Byte Length (Write-only) Mask */
#define USBHS_HSTDMACONTROL_BUFF_LENGTH(value) (USBHS_HSTDMACONTROL_BUFF_LENGTH_Msk & (_UINT32_(value) << USBHS_HSTDMACONTROL_BUFF_LENGTH_Pos)) /* Assigment of value for BUFF_LENGTH in the USBHS_HSTDMACONTROL register */
#define USBHS_HSTDMACONTROL_Msk               _UINT32_(0xFFFF00FF)                                 /* (USBHS_HSTDMACONTROL) Register Mask  */


/* -------- USBHS_HSTDMASTATUS : (USBHS Offset: 0x0C) (R/W 32) Host DMA Channel Status Register -------- */
#define USBHS_HSTDMASTATUS_CHANN_ENB_Pos      _UINT32_(0)                                          /* (USBHS_HSTDMASTATUS) Channel Enable Status Position */
#define USBHS_HSTDMASTATUS_CHANN_ENB_Msk      (_UINT32_(0x1) << USBHS_HSTDMASTATUS_CHANN_ENB_Pos)  /* (USBHS_HSTDMASTATUS) Channel Enable Status Mask */
#define USBHS_HSTDMASTATUS_CHANN_ENB(value)   (USBHS_HSTDMASTATUS_CHANN_ENB_Msk & (_UINT32_(value) << USBHS_HSTDMASTATUS_CHANN_ENB_Pos)) /* Assigment of value for CHANN_ENB in the USBHS_HSTDMASTATUS register */
#define USBHS_HSTDMASTATUS_CHANN_ACT_Pos      _UINT32_(1)                                          /* (USBHS_HSTDMASTATUS) Channel Active Status Position */
#define USBHS_HSTDMASTATUS_CHANN_ACT_Msk      (_UINT32_(0x1) << USBHS_HSTDMASTATUS_CHANN_ACT_Pos)  /* (USBHS_HSTDMASTATUS) Channel Active Status Mask */
#define USBHS_HSTDMASTATUS_CHANN_ACT(value)   (USBHS_HSTDMASTATUS_CHANN_ACT_Msk & (_UINT32_(value) << USBHS_HSTDMASTATUS_CHANN_ACT_Pos)) /* Assigment of value for CHANN_ACT in the USBHS_HSTDMASTATUS register */
#define USBHS_HSTDMASTATUS_END_TR_ST_Pos      _UINT32_(4)                                          /* (USBHS_HSTDMASTATUS) End of Channel Transfer Status Position */
#define USBHS_HSTDMASTATUS_END_TR_ST_Msk      (_UINT32_(0x1) << USBHS_HSTDMASTATUS_END_TR_ST_Pos)  /* (USBHS_HSTDMASTATUS) End of Channel Transfer Status Mask */
#define USBHS_HSTDMASTATUS_END_TR_ST(value)   (USBHS_HSTDMASTATUS_END_TR_ST_Msk & (_UINT32_(value) << USBHS_HSTDMASTATUS_END_TR_ST_Pos)) /* Assigment of value for END_TR_ST in the USBHS_HSTDMASTATUS register */
#define USBHS_HSTDMASTATUS_END_BF_ST_Pos      _UINT32_(5)                                          /* (USBHS_HSTDMASTATUS) End of Channel Buffer Status Position */
#define USBHS_HSTDMASTATUS_END_BF_ST_Msk      (_UINT32_(0x1) << USBHS_HSTDMASTATUS_END_BF_ST_Pos)  /* (USBHS_HSTDMASTATUS) End of Channel Buffer Status Mask */
#define USBHS_HSTDMASTATUS_END_BF_ST(value)   (USBHS_HSTDMASTATUS_END_BF_ST_Msk & (_UINT32_(value) << USBHS_HSTDMASTATUS_END_BF_ST_Pos)) /* Assigment of value for END_BF_ST in the USBHS_HSTDMASTATUS register */
#define USBHS_HSTDMASTATUS_DESC_LDST_Pos      _UINT32_(6)                                          /* (USBHS_HSTDMASTATUS) Descriptor Loaded Status Position */
#define USBHS_HSTDMASTATUS_DESC_LDST_Msk      (_UINT32_(0x1) << USBHS_HSTDMASTATUS_DESC_LDST_Pos)  /* (USBHS_HSTDMASTATUS) Descriptor Loaded Status Mask */
#define USBHS_HSTDMASTATUS_DESC_LDST(value)   (USBHS_HSTDMASTATUS_DESC_LDST_Msk & (_UINT32_(value) << USBHS_HSTDMASTATUS_DESC_LDST_Pos)) /* Assigment of value for DESC_LDST in the USBHS_HSTDMASTATUS register */
#define USBHS_HSTDMASTATUS_BUFF_COUNT_Pos     _UINT32_(16)                                         /* (USBHS_HSTDMASTATUS) Buffer Byte Count Position */
#define USBHS_HSTDMASTATUS_BUFF_COUNT_Msk     (_UINT32_(0xFFFF) << USBHS_HSTDMASTATUS_BUFF_COUNT_Pos) /* (USBHS_HSTDMASTATUS) Buffer Byte Count Mask */
#define USBHS_HSTDMASTATUS_BUFF_COUNT(value)  (USBHS_HSTDMASTATUS_BUFF_COUNT_Msk & (_UINT32_(value) << USBHS_HSTDMASTATUS_BUFF_COUNT_Pos)) /* Assigment of value for BUFF_COUNT in the USBHS_HSTDMASTATUS register */
#define USBHS_HSTDMASTATUS_Msk                _UINT32_(0xFFFF0073)                                 /* (USBHS_HSTDMASTATUS) Register Mask  */


/* -------- USBHS_DEVCTRL : (USBHS Offset: 0x00) (R/W 32) Device General Control Register -------- */
#define USBHS_DEVCTRL_UADD_Pos                _UINT32_(0)                                          /* (USBHS_DEVCTRL) USB Address Position */
#define USBHS_DEVCTRL_UADD_Msk                (_UINT32_(0x7F) << USBHS_DEVCTRL_UADD_Pos)           /* (USBHS_DEVCTRL) USB Address Mask */
#define USBHS_DEVCTRL_UADD(value)             (USBHS_DEVCTRL_UADD_Msk & (_UINT32_(value) << USBHS_DEVCTRL_UADD_Pos)) /* Assigment of value for UADD in the USBHS_DEVCTRL register */
#define USBHS_DEVCTRL_ADDEN_Pos               _UINT32_(7)                                          /* (USBHS_DEVCTRL) Address Enable Position */
#define USBHS_DEVCTRL_ADDEN_Msk               (_UINT32_(0x1) << USBHS_DEVCTRL_ADDEN_Pos)           /* (USBHS_DEVCTRL) Address Enable Mask */
#define USBHS_DEVCTRL_ADDEN(value)            (USBHS_DEVCTRL_ADDEN_Msk & (_UINT32_(value) << USBHS_DEVCTRL_ADDEN_Pos)) /* Assigment of value for ADDEN in the USBHS_DEVCTRL register */
#define USBHS_DEVCTRL_DETACH_Pos              _UINT32_(8)                                          /* (USBHS_DEVCTRL) Detach Position */
#define USBHS_DEVCTRL_DETACH_Msk              (_UINT32_(0x1) << USBHS_DEVCTRL_DETACH_Pos)          /* (USBHS_DEVCTRL) Detach Mask */
#define USBHS_DEVCTRL_DETACH(value)           (USBHS_DEVCTRL_DETACH_Msk & (_UINT32_(value) << USBHS_DEVCTRL_DETACH_Pos)) /* Assigment of value for DETACH in the USBHS_DEVCTRL register */
#define USBHS_DEVCTRL_RMWKUP_Pos              _UINT32_(9)                                          /* (USBHS_DEVCTRL) Remote Wake-Up Position */
#define USBHS_DEVCTRL_RMWKUP_Msk              (_UINT32_(0x1) << USBHS_DEVCTRL_RMWKUP_Pos)          /* (USBHS_DEVCTRL) Remote Wake-Up Mask */
#define USBHS_DEVCTRL_RMWKUP(value)           (USBHS_DEVCTRL_RMWKUP_Msk & (_UINT32_(value) << USBHS_DEVCTRL_RMWKUP_Pos)) /* Assigment of value for RMWKUP in the USBHS_DEVCTRL register */
#define USBHS_DEVCTRL_SPDCONF_Pos             _UINT32_(10)                                         /* (USBHS_DEVCTRL) Mode Configuration Position */
#define USBHS_DEVCTRL_SPDCONF_Msk             (_UINT32_(0x3) << USBHS_DEVCTRL_SPDCONF_Pos)         /* (USBHS_DEVCTRL) Mode Configuration Mask */
#define USBHS_DEVCTRL_SPDCONF(value)          (USBHS_DEVCTRL_SPDCONF_Msk & (_UINT32_(value) << USBHS_DEVCTRL_SPDCONF_Pos)) /* Assigment of value for SPDCONF in the USBHS_DEVCTRL register */
#define   USBHS_DEVCTRL_SPDCONF_NORMAL_Val    _UINT32_(0x0)                                        /* (USBHS_DEVCTRL) The peripheral starts in Full-speed mode and performs a high-speed reset to switch to High-speed mode if the host is high-speed-capable.  */
#define   USBHS_DEVCTRL_SPDCONF_LOW_POWER_Val _UINT32_(0x1)                                        /* (USBHS_DEVCTRL) For a better consumption, if high speed is not needed.  */
#define   USBHS_DEVCTRL_SPDCONF_HIGH_SPEED_Val _UINT32_(0x2)                                        /* (USBHS_DEVCTRL) Forced high speed.  */
#define   USBHS_DEVCTRL_SPDCONF_FORCED_FS_Val _UINT32_(0x3)                                        /* (USBHS_DEVCTRL) The peripheral remains in Full-speed mode whatever the host speed capability.  */
#define USBHS_DEVCTRL_SPDCONF_NORMAL          (USBHS_DEVCTRL_SPDCONF_NORMAL_Val << USBHS_DEVCTRL_SPDCONF_Pos) /* (USBHS_DEVCTRL) The peripheral starts in Full-speed mode and performs a high-speed reset to switch to High-speed mode if the host is high-speed-capable. Position  */
#define USBHS_DEVCTRL_SPDCONF_LOW_POWER       (USBHS_DEVCTRL_SPDCONF_LOW_POWER_Val << USBHS_DEVCTRL_SPDCONF_Pos) /* (USBHS_DEVCTRL) For a better consumption, if high speed is not needed. Position  */
#define USBHS_DEVCTRL_SPDCONF_HIGH_SPEED      (USBHS_DEVCTRL_SPDCONF_HIGH_SPEED_Val << USBHS_DEVCTRL_SPDCONF_Pos) /* (USBHS_DEVCTRL) Forced high speed. Position  */
#define USBHS_DEVCTRL_SPDCONF_FORCED_FS       (USBHS_DEVCTRL_SPDCONF_FORCED_FS_Val << USBHS_DEVCTRL_SPDCONF_Pos) /* (USBHS_DEVCTRL) The peripheral remains in Full-speed mode whatever the host speed capability. Position  */
#define USBHS_DEVCTRL_LS_Pos                  _UINT32_(12)                                         /* (USBHS_DEVCTRL) Low-Speed Mode Force Position */
#define USBHS_DEVCTRL_LS_Msk                  (_UINT32_(0x1) << USBHS_DEVCTRL_LS_Pos)              /* (USBHS_DEVCTRL) Low-Speed Mode Force Mask */
#define USBHS_DEVCTRL_LS(value)               (USBHS_DEVCTRL_LS_Msk & (_UINT32_(value) << USBHS_DEVCTRL_LS_Pos)) /* Assigment of value for LS in the USBHS_DEVCTRL register */
#define USBHS_DEVCTRL_TSTJ_Pos                _UINT32_(13)                                         /* (USBHS_DEVCTRL) Test mode J Position */
#define USBHS_DEVCTRL_TSTJ_Msk                (_UINT32_(0x1) << USBHS_DEVCTRL_TSTJ_Pos)            /* (USBHS_DEVCTRL) Test mode J Mask */
#define USBHS_DEVCTRL_TSTJ(value)             (USBHS_DEVCTRL_TSTJ_Msk & (_UINT32_(value) << USBHS_DEVCTRL_TSTJ_Pos)) /* Assigment of value for TSTJ in the USBHS_DEVCTRL register */
#define USBHS_DEVCTRL_TSTK_Pos                _UINT32_(14)                                         /* (USBHS_DEVCTRL) Test mode K Position */
#define USBHS_DEVCTRL_TSTK_Msk                (_UINT32_(0x1) << USBHS_DEVCTRL_TSTK_Pos)            /* (USBHS_DEVCTRL) Test mode K Mask */
#define USBHS_DEVCTRL_TSTK(value)             (USBHS_DEVCTRL_TSTK_Msk & (_UINT32_(value) << USBHS_DEVCTRL_TSTK_Pos)) /* Assigment of value for TSTK in the USBHS_DEVCTRL register */
#define USBHS_DEVCTRL_TSTPCKT_Pos             _UINT32_(15)                                         /* (USBHS_DEVCTRL) Test packet mode Position */
#define USBHS_DEVCTRL_TSTPCKT_Msk             (_UINT32_(0x1) << USBHS_DEVCTRL_TSTPCKT_Pos)         /* (USBHS_DEVCTRL) Test packet mode Mask */
#define USBHS_DEVCTRL_TSTPCKT(value)          (USBHS_DEVCTRL_TSTPCKT_Msk & (_UINT32_(value) << USBHS_DEVCTRL_TSTPCKT_Pos)) /* Assigment of value for TSTPCKT in the USBHS_DEVCTRL register */
#define USBHS_DEVCTRL_OPMODE2_Pos             _UINT32_(16)                                         /* (USBHS_DEVCTRL) Specific Operational mode Position */
#define USBHS_DEVCTRL_OPMODE2_Msk             (_UINT32_(0x1) << USBHS_DEVCTRL_OPMODE2_Pos)         /* (USBHS_DEVCTRL) Specific Operational mode Mask */
#define USBHS_DEVCTRL_OPMODE2(value)          (USBHS_DEVCTRL_OPMODE2_Msk & (_UINT32_(value) << USBHS_DEVCTRL_OPMODE2_Pos)) /* Assigment of value for OPMODE2 in the USBHS_DEVCTRL register */
#define USBHS_DEVCTRL_Msk                     _UINT32_(0x0001FFFF)                                 /* (USBHS_DEVCTRL) Register Mask  */

#define USBHS_DEVCTRL_OPMODE_Pos              _UINT32_(16)                                         /* (USBHS_DEVCTRL Position) Specific Operational mode */
#define USBHS_DEVCTRL_OPMODE_Msk              (_UINT32_(0x1) << USBHS_DEVCTRL_OPMODE_Pos)          /* (USBHS_DEVCTRL Mask) OPMODE */
#define USBHS_DEVCTRL_OPMODE(value)           (USBHS_DEVCTRL_OPMODE_Msk & (_UINT32_(value) << USBHS_DEVCTRL_OPMODE_Pos)) 

/* -------- USBHS_DEVISR : (USBHS Offset: 0x04) ( R/ 32) Device Global Interrupt Status Register -------- */
#define USBHS_DEVISR_SUSP_Pos                 _UINT32_(0)                                          /* (USBHS_DEVISR) Suspend Interrupt Position */
#define USBHS_DEVISR_SUSP_Msk                 (_UINT32_(0x1) << USBHS_DEVISR_SUSP_Pos)             /* (USBHS_DEVISR) Suspend Interrupt Mask */
#define USBHS_DEVISR_SUSP(value)              (USBHS_DEVISR_SUSP_Msk & (_UINT32_(value) << USBHS_DEVISR_SUSP_Pos)) /* Assigment of value for SUSP in the USBHS_DEVISR register */
#define USBHS_DEVISR_MSOF_Pos                 _UINT32_(1)                                          /* (USBHS_DEVISR) Micro Start of Frame Interrupt Position */
#define USBHS_DEVISR_MSOF_Msk                 (_UINT32_(0x1) << USBHS_DEVISR_MSOF_Pos)             /* (USBHS_DEVISR) Micro Start of Frame Interrupt Mask */
#define USBHS_DEVISR_MSOF(value)              (USBHS_DEVISR_MSOF_Msk & (_UINT32_(value) << USBHS_DEVISR_MSOF_Pos)) /* Assigment of value for MSOF in the USBHS_DEVISR register */
#define USBHS_DEVISR_SOF_Pos                  _UINT32_(2)                                          /* (USBHS_DEVISR) Start of Frame Interrupt Position */
#define USBHS_DEVISR_SOF_Msk                  (_UINT32_(0x1) << USBHS_DEVISR_SOF_Pos)              /* (USBHS_DEVISR) Start of Frame Interrupt Mask */
#define USBHS_DEVISR_SOF(value)               (USBHS_DEVISR_SOF_Msk & (_UINT32_(value) << USBHS_DEVISR_SOF_Pos)) /* Assigment of value for SOF in the USBHS_DEVISR register */
#define USBHS_DEVISR_EORST_Pos                _UINT32_(3)                                          /* (USBHS_DEVISR) End of Reset Interrupt Position */
#define USBHS_DEVISR_EORST_Msk                (_UINT32_(0x1) << USBHS_DEVISR_EORST_Pos)            /* (USBHS_DEVISR) End of Reset Interrupt Mask */
#define USBHS_DEVISR_EORST(value)             (USBHS_DEVISR_EORST_Msk & (_UINT32_(value) << USBHS_DEVISR_EORST_Pos)) /* Assigment of value for EORST in the USBHS_DEVISR register */
#define USBHS_DEVISR_WAKEUP_Pos               _UINT32_(4)                                          /* (USBHS_DEVISR) Wake-Up Interrupt Position */
#define USBHS_DEVISR_WAKEUP_Msk               (_UINT32_(0x1) << USBHS_DEVISR_WAKEUP_Pos)           /* (USBHS_DEVISR) Wake-Up Interrupt Mask */
#define USBHS_DEVISR_WAKEUP(value)            (USBHS_DEVISR_WAKEUP_Msk & (_UINT32_(value) << USBHS_DEVISR_WAKEUP_Pos)) /* Assigment of value for WAKEUP in the USBHS_DEVISR register */
#define USBHS_DEVISR_EORSM_Pos                _UINT32_(5)                                          /* (USBHS_DEVISR) End of Resume Interrupt Position */
#define USBHS_DEVISR_EORSM_Msk                (_UINT32_(0x1) << USBHS_DEVISR_EORSM_Pos)            /* (USBHS_DEVISR) End of Resume Interrupt Mask */
#define USBHS_DEVISR_EORSM(value)             (USBHS_DEVISR_EORSM_Msk & (_UINT32_(value) << USBHS_DEVISR_EORSM_Pos)) /* Assigment of value for EORSM in the USBHS_DEVISR register */
#define USBHS_DEVISR_UPRSM_Pos                _UINT32_(6)                                          /* (USBHS_DEVISR) Upstream Resume Interrupt Position */
#define USBHS_DEVISR_UPRSM_Msk                (_UINT32_(0x1) << USBHS_DEVISR_UPRSM_Pos)            /* (USBHS_DEVISR) Upstream Resume Interrupt Mask */
#define USBHS_DEVISR_UPRSM(value)             (USBHS_DEVISR_UPRSM_Msk & (_UINT32_(value) << USBHS_DEVISR_UPRSM_Pos)) /* Assigment of value for UPRSM in the USBHS_DEVISR register */
#define USBHS_DEVISR_PEP_0_Pos                _UINT32_(12)                                         /* (USBHS_DEVISR) Endpoint 0 Interrupt Position */
#define USBHS_DEVISR_PEP_0_Msk                (_UINT32_(0x1) << USBHS_DEVISR_PEP_0_Pos)            /* (USBHS_DEVISR) Endpoint 0 Interrupt Mask */
#define USBHS_DEVISR_PEP_0(value)             (USBHS_DEVISR_PEP_0_Msk & (_UINT32_(value) << USBHS_DEVISR_PEP_0_Pos)) /* Assigment of value for PEP_0 in the USBHS_DEVISR register */
#define USBHS_DEVISR_PEP_1_Pos                _UINT32_(13)                                         /* (USBHS_DEVISR) Endpoint 1 Interrupt Position */
#define USBHS_DEVISR_PEP_1_Msk                (_UINT32_(0x1) << USBHS_DEVISR_PEP_1_Pos)            /* (USBHS_DEVISR) Endpoint 1 Interrupt Mask */
#define USBHS_DEVISR_PEP_1(value)             (USBHS_DEVISR_PEP_1_Msk & (_UINT32_(value) << USBHS_DEVISR_PEP_1_Pos)) /* Assigment of value for PEP_1 in the USBHS_DEVISR register */
#define USBHS_DEVISR_PEP_2_Pos                _UINT32_(14)                                         /* (USBHS_DEVISR) Endpoint 2 Interrupt Position */
#define USBHS_DEVISR_PEP_2_Msk                (_UINT32_(0x1) << USBHS_DEVISR_PEP_2_Pos)            /* (USBHS_DEVISR) Endpoint 2 Interrupt Mask */
#define USBHS_DEVISR_PEP_2(value)             (USBHS_DEVISR_PEP_2_Msk & (_UINT32_(value) << USBHS_DEVISR_PEP_2_Pos)) /* Assigment of value for PEP_2 in the USBHS_DEVISR register */
#define USBHS_DEVISR_PEP_3_Pos                _UINT32_(15)                                         /* (USBHS_DEVISR) Endpoint 3 Interrupt Position */
#define USBHS_DEVISR_PEP_3_Msk                (_UINT32_(0x1) << USBHS_DEVISR_PEP_3_Pos)            /* (USBHS_DEVISR) Endpoint 3 Interrupt Mask */
#define USBHS_DEVISR_PEP_3(value)             (USBHS_DEVISR_PEP_3_Msk & (_UINT32_(value) << USBHS_DEVISR_PEP_3_Pos)) /* Assigment of value for PEP_3 in the USBHS_DEVISR register */
#define USBHS_DEVISR_PEP_4_Pos                _UINT32_(16)                                         /* (USBHS_DEVISR) Endpoint 4 Interrupt Position */
#define USBHS_DEVISR_PEP_4_Msk                (_UINT32_(0x1) << USBHS_DEVISR_PEP_4_Pos)            /* (USBHS_DEVISR) Endpoint 4 Interrupt Mask */
#define USBHS_DEVISR_PEP_4(value)             (USBHS_DEVISR_PEP_4_Msk & (_UINT32_(value) << USBHS_DEVISR_PEP_4_Pos)) /* Assigment of value for PEP_4 in the USBHS_DEVISR register */
#define USBHS_DEVISR_PEP_5_Pos                _UINT32_(17)                                         /* (USBHS_DEVISR) Endpoint 5 Interrupt Position */
#define USBHS_DEVISR_PEP_5_Msk                (_UINT32_(0x1) << USBHS_DEVISR_PEP_5_Pos)            /* (USBHS_DEVISR) Endpoint 5 Interrupt Mask */
#define USBHS_DEVISR_PEP_5(value)             (USBHS_DEVISR_PEP_5_Msk & (_UINT32_(value) << USBHS_DEVISR_PEP_5_Pos)) /* Assigment of value for PEP_5 in the USBHS_DEVISR register */
#define USBHS_DEVISR_PEP_6_Pos                _UINT32_(18)                                         /* (USBHS_DEVISR) Endpoint 6 Interrupt Position */
#define USBHS_DEVISR_PEP_6_Msk                (_UINT32_(0x1) << USBHS_DEVISR_PEP_6_Pos)            /* (USBHS_DEVISR) Endpoint 6 Interrupt Mask */
#define USBHS_DEVISR_PEP_6(value)             (USBHS_DEVISR_PEP_6_Msk & (_UINT32_(value) << USBHS_DEVISR_PEP_6_Pos)) /* Assigment of value for PEP_6 in the USBHS_DEVISR register */
#define USBHS_DEVISR_PEP_7_Pos                _UINT32_(19)                                         /* (USBHS_DEVISR) Endpoint 7 Interrupt Position */
#define USBHS_DEVISR_PEP_7_Msk                (_UINT32_(0x1) << USBHS_DEVISR_PEP_7_Pos)            /* (USBHS_DEVISR) Endpoint 7 Interrupt Mask */
#define USBHS_DEVISR_PEP_7(value)             (USBHS_DEVISR_PEP_7_Msk & (_UINT32_(value) << USBHS_DEVISR_PEP_7_Pos)) /* Assigment of value for PEP_7 in the USBHS_DEVISR register */
#define USBHS_DEVISR_PEP_8_Pos                _UINT32_(20)                                         /* (USBHS_DEVISR) Endpoint 8 Interrupt Position */
#define USBHS_DEVISR_PEP_8_Msk                (_UINT32_(0x1) << USBHS_DEVISR_PEP_8_Pos)            /* (USBHS_DEVISR) Endpoint 8 Interrupt Mask */
#define USBHS_DEVISR_PEP_8(value)             (USBHS_DEVISR_PEP_8_Msk & (_UINT32_(value) << USBHS_DEVISR_PEP_8_Pos)) /* Assigment of value for PEP_8 in the USBHS_DEVISR register */
#define USBHS_DEVISR_PEP_9_Pos                _UINT32_(21)                                         /* (USBHS_DEVISR) Endpoint 9 Interrupt Position */
#define USBHS_DEVISR_PEP_9_Msk                (_UINT32_(0x1) << USBHS_DEVISR_PEP_9_Pos)            /* (USBHS_DEVISR) Endpoint 9 Interrupt Mask */
#define USBHS_DEVISR_PEP_9(value)             (USBHS_DEVISR_PEP_9_Msk & (_UINT32_(value) << USBHS_DEVISR_PEP_9_Pos)) /* Assigment of value for PEP_9 in the USBHS_DEVISR register */
#define USBHS_DEVISR_DMA_1_Pos                _UINT32_(25)                                         /* (USBHS_DEVISR) DMA Channel 1 Interrupt Position */
#define USBHS_DEVISR_DMA_1_Msk                (_UINT32_(0x1) << USBHS_DEVISR_DMA_1_Pos)            /* (USBHS_DEVISR) DMA Channel 1 Interrupt Mask */
#define USBHS_DEVISR_DMA_1(value)             (USBHS_DEVISR_DMA_1_Msk & (_UINT32_(value) << USBHS_DEVISR_DMA_1_Pos)) /* Assigment of value for DMA_1 in the USBHS_DEVISR register */
#define USBHS_DEVISR_DMA_2_Pos                _UINT32_(26)                                         /* (USBHS_DEVISR) DMA Channel 2 Interrupt Position */
#define USBHS_DEVISR_DMA_2_Msk                (_UINT32_(0x1) << USBHS_DEVISR_DMA_2_Pos)            /* (USBHS_DEVISR) DMA Channel 2 Interrupt Mask */
#define USBHS_DEVISR_DMA_2(value)             (USBHS_DEVISR_DMA_2_Msk & (_UINT32_(value) << USBHS_DEVISR_DMA_2_Pos)) /* Assigment of value for DMA_2 in the USBHS_DEVISR register */
#define USBHS_DEVISR_DMA_3_Pos                _UINT32_(27)                                         /* (USBHS_DEVISR) DMA Channel 3 Interrupt Position */
#define USBHS_DEVISR_DMA_3_Msk                (_UINT32_(0x1) << USBHS_DEVISR_DMA_3_Pos)            /* (USBHS_DEVISR) DMA Channel 3 Interrupt Mask */
#define USBHS_DEVISR_DMA_3(value)             (USBHS_DEVISR_DMA_3_Msk & (_UINT32_(value) << USBHS_DEVISR_DMA_3_Pos)) /* Assigment of value for DMA_3 in the USBHS_DEVISR register */
#define USBHS_DEVISR_DMA_4_Pos                _UINT32_(28)                                         /* (USBHS_DEVISR) DMA Channel 4 Interrupt Position */
#define USBHS_DEVISR_DMA_4_Msk                (_UINT32_(0x1) << USBHS_DEVISR_DMA_4_Pos)            /* (USBHS_DEVISR) DMA Channel 4 Interrupt Mask */
#define USBHS_DEVISR_DMA_4(value)             (USBHS_DEVISR_DMA_4_Msk & (_UINT32_(value) << USBHS_DEVISR_DMA_4_Pos)) /* Assigment of value for DMA_4 in the USBHS_DEVISR register */
#define USBHS_DEVISR_DMA_5_Pos                _UINT32_(29)                                         /* (USBHS_DEVISR) DMA Channel 5 Interrupt Position */
#define USBHS_DEVISR_DMA_5_Msk                (_UINT32_(0x1) << USBHS_DEVISR_DMA_5_Pos)            /* (USBHS_DEVISR) DMA Channel 5 Interrupt Mask */
#define USBHS_DEVISR_DMA_5(value)             (USBHS_DEVISR_DMA_5_Msk & (_UINT32_(value) << USBHS_DEVISR_DMA_5_Pos)) /* Assigment of value for DMA_5 in the USBHS_DEVISR register */
#define USBHS_DEVISR_DMA_6_Pos                _UINT32_(30)                                         /* (USBHS_DEVISR) DMA Channel 6 Interrupt Position */
#define USBHS_DEVISR_DMA_6_Msk                (_UINT32_(0x1) << USBHS_DEVISR_DMA_6_Pos)            /* (USBHS_DEVISR) DMA Channel 6 Interrupt Mask */
#define USBHS_DEVISR_DMA_6(value)             (USBHS_DEVISR_DMA_6_Msk & (_UINT32_(value) << USBHS_DEVISR_DMA_6_Pos)) /* Assigment of value for DMA_6 in the USBHS_DEVISR register */
#define USBHS_DEVISR_DMA_7_Pos                _UINT32_(31)                                         /* (USBHS_DEVISR) DMA Channel 7 Interrupt Position */
#define USBHS_DEVISR_DMA_7_Msk                (_UINT32_(0x1) << USBHS_DEVISR_DMA_7_Pos)            /* (USBHS_DEVISR) DMA Channel 7 Interrupt Mask */
#define USBHS_DEVISR_DMA_7(value)             (USBHS_DEVISR_DMA_7_Msk & (_UINT32_(value) << USBHS_DEVISR_DMA_7_Pos)) /* Assigment of value for DMA_7 in the USBHS_DEVISR register */
#define USBHS_DEVISR_Msk                      _UINT32_(0xFE3FF07F)                                 /* (USBHS_DEVISR) Register Mask  */

#define USBHS_DEVISR_PEP__Pos                 _UINT32_(12)                                         /* (USBHS_DEVISR Position) Endpoint x Interrupt */
#define USBHS_DEVISR_PEP__Msk                 (_UINT32_(0x3FF) << USBHS_DEVISR_PEP__Pos)           /* (USBHS_DEVISR Mask) PEP_ */
#define USBHS_DEVISR_PEP_(value)              (USBHS_DEVISR_PEP__Msk & (_UINT32_(value) << USBHS_DEVISR_PEP__Pos)) 
#define USBHS_DEVISR_DMA__Pos                 _UINT32_(25)                                         /* (USBHS_DEVISR Position) DMA Channel 7 Interrupt */
#define USBHS_DEVISR_DMA__Msk                 (_UINT32_(0x7F) << USBHS_DEVISR_DMA__Pos)            /* (USBHS_DEVISR Mask) DMA_ */
#define USBHS_DEVISR_DMA_(value)              (USBHS_DEVISR_DMA__Msk & (_UINT32_(value) << USBHS_DEVISR_DMA__Pos)) 

/* -------- USBHS_DEVICR : (USBHS Offset: 0x08) ( /W 32) Device Global Interrupt Clear Register -------- */
#define USBHS_DEVICR_SUSPC_Pos                _UINT32_(0)                                          /* (USBHS_DEVICR) Suspend Interrupt Clear Position */
#define USBHS_DEVICR_SUSPC_Msk                (_UINT32_(0x1) << USBHS_DEVICR_SUSPC_Pos)            /* (USBHS_DEVICR) Suspend Interrupt Clear Mask */
#define USBHS_DEVICR_SUSPC(value)             (USBHS_DEVICR_SUSPC_Msk & (_UINT32_(value) << USBHS_DEVICR_SUSPC_Pos)) /* Assigment of value for SUSPC in the USBHS_DEVICR register */
#define USBHS_DEVICR_MSOFC_Pos                _UINT32_(1)                                          /* (USBHS_DEVICR) Micro Start of Frame Interrupt Clear Position */
#define USBHS_DEVICR_MSOFC_Msk                (_UINT32_(0x1) << USBHS_DEVICR_MSOFC_Pos)            /* (USBHS_DEVICR) Micro Start of Frame Interrupt Clear Mask */
#define USBHS_DEVICR_MSOFC(value)             (USBHS_DEVICR_MSOFC_Msk & (_UINT32_(value) << USBHS_DEVICR_MSOFC_Pos)) /* Assigment of value for MSOFC in the USBHS_DEVICR register */
#define USBHS_DEVICR_SOFC_Pos                 _UINT32_(2)                                          /* (USBHS_DEVICR) Start of Frame Interrupt Clear Position */
#define USBHS_DEVICR_SOFC_Msk                 (_UINT32_(0x1) << USBHS_DEVICR_SOFC_Pos)             /* (USBHS_DEVICR) Start of Frame Interrupt Clear Mask */
#define USBHS_DEVICR_SOFC(value)              (USBHS_DEVICR_SOFC_Msk & (_UINT32_(value) << USBHS_DEVICR_SOFC_Pos)) /* Assigment of value for SOFC in the USBHS_DEVICR register */
#define USBHS_DEVICR_EORSTC_Pos               _UINT32_(3)                                          /* (USBHS_DEVICR) End of Reset Interrupt Clear Position */
#define USBHS_DEVICR_EORSTC_Msk               (_UINT32_(0x1) << USBHS_DEVICR_EORSTC_Pos)           /* (USBHS_DEVICR) End of Reset Interrupt Clear Mask */
#define USBHS_DEVICR_EORSTC(value)            (USBHS_DEVICR_EORSTC_Msk & (_UINT32_(value) << USBHS_DEVICR_EORSTC_Pos)) /* Assigment of value for EORSTC in the USBHS_DEVICR register */
#define USBHS_DEVICR_WAKEUPC_Pos              _UINT32_(4)                                          /* (USBHS_DEVICR) Wake-Up Interrupt Clear Position */
#define USBHS_DEVICR_WAKEUPC_Msk              (_UINT32_(0x1) << USBHS_DEVICR_WAKEUPC_Pos)          /* (USBHS_DEVICR) Wake-Up Interrupt Clear Mask */
#define USBHS_DEVICR_WAKEUPC(value)           (USBHS_DEVICR_WAKEUPC_Msk & (_UINT32_(value) << USBHS_DEVICR_WAKEUPC_Pos)) /* Assigment of value for WAKEUPC in the USBHS_DEVICR register */
#define USBHS_DEVICR_EORSMC_Pos               _UINT32_(5)                                          /* (USBHS_DEVICR) End of Resume Interrupt Clear Position */
#define USBHS_DEVICR_EORSMC_Msk               (_UINT32_(0x1) << USBHS_DEVICR_EORSMC_Pos)           /* (USBHS_DEVICR) End of Resume Interrupt Clear Mask */
#define USBHS_DEVICR_EORSMC(value)            (USBHS_DEVICR_EORSMC_Msk & (_UINT32_(value) << USBHS_DEVICR_EORSMC_Pos)) /* Assigment of value for EORSMC in the USBHS_DEVICR register */
#define USBHS_DEVICR_UPRSMC_Pos               _UINT32_(6)                                          /* (USBHS_DEVICR) Upstream Resume Interrupt Clear Position */
#define USBHS_DEVICR_UPRSMC_Msk               (_UINT32_(0x1) << USBHS_DEVICR_UPRSMC_Pos)           /* (USBHS_DEVICR) Upstream Resume Interrupt Clear Mask */
#define USBHS_DEVICR_UPRSMC(value)            (USBHS_DEVICR_UPRSMC_Msk & (_UINT32_(value) << USBHS_DEVICR_UPRSMC_Pos)) /* Assigment of value for UPRSMC in the USBHS_DEVICR register */
#define USBHS_DEVICR_Msk                      _UINT32_(0x0000007F)                                 /* (USBHS_DEVICR) Register Mask  */


/* -------- USBHS_DEVIFR : (USBHS Offset: 0x0C) ( /W 32) Device Global Interrupt Set Register -------- */
#define USBHS_DEVIFR_SUSPS_Pos                _UINT32_(0)                                          /* (USBHS_DEVIFR) Suspend Interrupt Set Position */
#define USBHS_DEVIFR_SUSPS_Msk                (_UINT32_(0x1) << USBHS_DEVIFR_SUSPS_Pos)            /* (USBHS_DEVIFR) Suspend Interrupt Set Mask */
#define USBHS_DEVIFR_SUSPS(value)             (USBHS_DEVIFR_SUSPS_Msk & (_UINT32_(value) << USBHS_DEVIFR_SUSPS_Pos)) /* Assigment of value for SUSPS in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_MSOFS_Pos                _UINT32_(1)                                          /* (USBHS_DEVIFR) Micro Start of Frame Interrupt Set Position */
#define USBHS_DEVIFR_MSOFS_Msk                (_UINT32_(0x1) << USBHS_DEVIFR_MSOFS_Pos)            /* (USBHS_DEVIFR) Micro Start of Frame Interrupt Set Mask */
#define USBHS_DEVIFR_MSOFS(value)             (USBHS_DEVIFR_MSOFS_Msk & (_UINT32_(value) << USBHS_DEVIFR_MSOFS_Pos)) /* Assigment of value for MSOFS in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_SOFS_Pos                 _UINT32_(2)                                          /* (USBHS_DEVIFR) Start of Frame Interrupt Set Position */
#define USBHS_DEVIFR_SOFS_Msk                 (_UINT32_(0x1) << USBHS_DEVIFR_SOFS_Pos)             /* (USBHS_DEVIFR) Start of Frame Interrupt Set Mask */
#define USBHS_DEVIFR_SOFS(value)              (USBHS_DEVIFR_SOFS_Msk & (_UINT32_(value) << USBHS_DEVIFR_SOFS_Pos)) /* Assigment of value for SOFS in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_EORSTS_Pos               _UINT32_(3)                                          /* (USBHS_DEVIFR) End of Reset Interrupt Set Position */
#define USBHS_DEVIFR_EORSTS_Msk               (_UINT32_(0x1) << USBHS_DEVIFR_EORSTS_Pos)           /* (USBHS_DEVIFR) End of Reset Interrupt Set Mask */
#define USBHS_DEVIFR_EORSTS(value)            (USBHS_DEVIFR_EORSTS_Msk & (_UINT32_(value) << USBHS_DEVIFR_EORSTS_Pos)) /* Assigment of value for EORSTS in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_WAKEUPS_Pos              _UINT32_(4)                                          /* (USBHS_DEVIFR) Wake-Up Interrupt Set Position */
#define USBHS_DEVIFR_WAKEUPS_Msk              (_UINT32_(0x1) << USBHS_DEVIFR_WAKEUPS_Pos)          /* (USBHS_DEVIFR) Wake-Up Interrupt Set Mask */
#define USBHS_DEVIFR_WAKEUPS(value)           (USBHS_DEVIFR_WAKEUPS_Msk & (_UINT32_(value) << USBHS_DEVIFR_WAKEUPS_Pos)) /* Assigment of value for WAKEUPS in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_EORSMS_Pos               _UINT32_(5)                                          /* (USBHS_DEVIFR) End of Resume Interrupt Set Position */
#define USBHS_DEVIFR_EORSMS_Msk               (_UINT32_(0x1) << USBHS_DEVIFR_EORSMS_Pos)           /* (USBHS_DEVIFR) End of Resume Interrupt Set Mask */
#define USBHS_DEVIFR_EORSMS(value)            (USBHS_DEVIFR_EORSMS_Msk & (_UINT32_(value) << USBHS_DEVIFR_EORSMS_Pos)) /* Assigment of value for EORSMS in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_UPRSMS_Pos               _UINT32_(6)                                          /* (USBHS_DEVIFR) Upstream Resume Interrupt Set Position */
#define USBHS_DEVIFR_UPRSMS_Msk               (_UINT32_(0x1) << USBHS_DEVIFR_UPRSMS_Pos)           /* (USBHS_DEVIFR) Upstream Resume Interrupt Set Mask */
#define USBHS_DEVIFR_UPRSMS(value)            (USBHS_DEVIFR_UPRSMS_Msk & (_UINT32_(value) << USBHS_DEVIFR_UPRSMS_Pos)) /* Assigment of value for UPRSMS in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_DMA_1_Pos                _UINT32_(25)                                         /* (USBHS_DEVIFR) DMA Channel 1 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_1_Msk                (_UINT32_(0x1) << USBHS_DEVIFR_DMA_1_Pos)            /* (USBHS_DEVIFR) DMA Channel 1 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_1(value)             (USBHS_DEVIFR_DMA_1_Msk & (_UINT32_(value) << USBHS_DEVIFR_DMA_1_Pos)) /* Assigment of value for DMA_1 in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_DMA_2_Pos                _UINT32_(26)                                         /* (USBHS_DEVIFR) DMA Channel 2 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_2_Msk                (_UINT32_(0x1) << USBHS_DEVIFR_DMA_2_Pos)            /* (USBHS_DEVIFR) DMA Channel 2 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_2(value)             (USBHS_DEVIFR_DMA_2_Msk & (_UINT32_(value) << USBHS_DEVIFR_DMA_2_Pos)) /* Assigment of value for DMA_2 in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_DMA_3_Pos                _UINT32_(27)                                         /* (USBHS_DEVIFR) DMA Channel 3 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_3_Msk                (_UINT32_(0x1) << USBHS_DEVIFR_DMA_3_Pos)            /* (USBHS_DEVIFR) DMA Channel 3 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_3(value)             (USBHS_DEVIFR_DMA_3_Msk & (_UINT32_(value) << USBHS_DEVIFR_DMA_3_Pos)) /* Assigment of value for DMA_3 in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_DMA_4_Pos                _UINT32_(28)                                         /* (USBHS_DEVIFR) DMA Channel 4 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_4_Msk                (_UINT32_(0x1) << USBHS_DEVIFR_DMA_4_Pos)            /* (USBHS_DEVIFR) DMA Channel 4 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_4(value)             (USBHS_DEVIFR_DMA_4_Msk & (_UINT32_(value) << USBHS_DEVIFR_DMA_4_Pos)) /* Assigment of value for DMA_4 in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_DMA_5_Pos                _UINT32_(29)                                         /* (USBHS_DEVIFR) DMA Channel 5 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_5_Msk                (_UINT32_(0x1) << USBHS_DEVIFR_DMA_5_Pos)            /* (USBHS_DEVIFR) DMA Channel 5 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_5(value)             (USBHS_DEVIFR_DMA_5_Msk & (_UINT32_(value) << USBHS_DEVIFR_DMA_5_Pos)) /* Assigment of value for DMA_5 in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_DMA_6_Pos                _UINT32_(30)                                         /* (USBHS_DEVIFR) DMA Channel 6 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_6_Msk                (_UINT32_(0x1) << USBHS_DEVIFR_DMA_6_Pos)            /* (USBHS_DEVIFR) DMA Channel 6 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_6(value)             (USBHS_DEVIFR_DMA_6_Msk & (_UINT32_(value) << USBHS_DEVIFR_DMA_6_Pos)) /* Assigment of value for DMA_6 in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_DMA_7_Pos                _UINT32_(31)                                         /* (USBHS_DEVIFR) DMA Channel 7 Interrupt Set Position */
#define USBHS_DEVIFR_DMA_7_Msk                (_UINT32_(0x1) << USBHS_DEVIFR_DMA_7_Pos)            /* (USBHS_DEVIFR) DMA Channel 7 Interrupt Set Mask */
#define USBHS_DEVIFR_DMA_7(value)             (USBHS_DEVIFR_DMA_7_Msk & (_UINT32_(value) << USBHS_DEVIFR_DMA_7_Pos)) /* Assigment of value for DMA_7 in the USBHS_DEVIFR register */
#define USBHS_DEVIFR_Msk                      _UINT32_(0xFE00007F)                                 /* (USBHS_DEVIFR) Register Mask  */

#define USBHS_DEVIFR_DMA__Pos                 _UINT32_(25)                                         /* (USBHS_DEVIFR Position) DMA Channel 7 Interrupt Set */
#define USBHS_DEVIFR_DMA__Msk                 (_UINT32_(0x7F) << USBHS_DEVIFR_DMA__Pos)            /* (USBHS_DEVIFR Mask) DMA_ */
#define USBHS_DEVIFR_DMA_(value)              (USBHS_DEVIFR_DMA__Msk & (_UINT32_(value) << USBHS_DEVIFR_DMA__Pos)) 

/* -------- USBHS_DEVIMR : (USBHS Offset: 0x10) ( R/ 32) Device Global Interrupt Mask Register -------- */
#define USBHS_DEVIMR_SUSPE_Pos                _UINT32_(0)                                          /* (USBHS_DEVIMR) Suspend Interrupt Mask Position */
#define USBHS_DEVIMR_SUSPE_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_SUSPE_Pos)            /* (USBHS_DEVIMR) Suspend Interrupt Mask Mask */
#define USBHS_DEVIMR_SUSPE(value)             (USBHS_DEVIMR_SUSPE_Msk & (_UINT32_(value) << USBHS_DEVIMR_SUSPE_Pos)) /* Assigment of value for SUSPE in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_MSOFE_Pos                _UINT32_(1)                                          /* (USBHS_DEVIMR) Micro Start of Frame Interrupt Mask Position */
#define USBHS_DEVIMR_MSOFE_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_MSOFE_Pos)            /* (USBHS_DEVIMR) Micro Start of Frame Interrupt Mask Mask */
#define USBHS_DEVIMR_MSOFE(value)             (USBHS_DEVIMR_MSOFE_Msk & (_UINT32_(value) << USBHS_DEVIMR_MSOFE_Pos)) /* Assigment of value for MSOFE in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_SOFE_Pos                 _UINT32_(2)                                          /* (USBHS_DEVIMR) Start of Frame Interrupt Mask Position */
#define USBHS_DEVIMR_SOFE_Msk                 (_UINT32_(0x1) << USBHS_DEVIMR_SOFE_Pos)             /* (USBHS_DEVIMR) Start of Frame Interrupt Mask Mask */
#define USBHS_DEVIMR_SOFE(value)              (USBHS_DEVIMR_SOFE_Msk & (_UINT32_(value) << USBHS_DEVIMR_SOFE_Pos)) /* Assigment of value for SOFE in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_EORSTE_Pos               _UINT32_(3)                                          /* (USBHS_DEVIMR) End of Reset Interrupt Mask Position */
#define USBHS_DEVIMR_EORSTE_Msk               (_UINT32_(0x1) << USBHS_DEVIMR_EORSTE_Pos)           /* (USBHS_DEVIMR) End of Reset Interrupt Mask Mask */
#define USBHS_DEVIMR_EORSTE(value)            (USBHS_DEVIMR_EORSTE_Msk & (_UINT32_(value) << USBHS_DEVIMR_EORSTE_Pos)) /* Assigment of value for EORSTE in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_WAKEUPE_Pos              _UINT32_(4)                                          /* (USBHS_DEVIMR) Wake-Up Interrupt Mask Position */
#define USBHS_DEVIMR_WAKEUPE_Msk              (_UINT32_(0x1) << USBHS_DEVIMR_WAKEUPE_Pos)          /* (USBHS_DEVIMR) Wake-Up Interrupt Mask Mask */
#define USBHS_DEVIMR_WAKEUPE(value)           (USBHS_DEVIMR_WAKEUPE_Msk & (_UINT32_(value) << USBHS_DEVIMR_WAKEUPE_Pos)) /* Assigment of value for WAKEUPE in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_EORSME_Pos               _UINT32_(5)                                          /* (USBHS_DEVIMR) End of Resume Interrupt Mask Position */
#define USBHS_DEVIMR_EORSME_Msk               (_UINT32_(0x1) << USBHS_DEVIMR_EORSME_Pos)           /* (USBHS_DEVIMR) End of Resume Interrupt Mask Mask */
#define USBHS_DEVIMR_EORSME(value)            (USBHS_DEVIMR_EORSME_Msk & (_UINT32_(value) << USBHS_DEVIMR_EORSME_Pos)) /* Assigment of value for EORSME in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_UPRSME_Pos               _UINT32_(6)                                          /* (USBHS_DEVIMR) Upstream Resume Interrupt Mask Position */
#define USBHS_DEVIMR_UPRSME_Msk               (_UINT32_(0x1) << USBHS_DEVIMR_UPRSME_Pos)           /* (USBHS_DEVIMR) Upstream Resume Interrupt Mask Mask */
#define USBHS_DEVIMR_UPRSME(value)            (USBHS_DEVIMR_UPRSME_Msk & (_UINT32_(value) << USBHS_DEVIMR_UPRSME_Pos)) /* Assigment of value for UPRSME in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_PEP_0_Pos                _UINT32_(12)                                         /* (USBHS_DEVIMR) Endpoint 0 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_0_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_PEP_0_Pos)            /* (USBHS_DEVIMR) Endpoint 0 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_0(value)             (USBHS_DEVIMR_PEP_0_Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP_0_Pos)) /* Assigment of value for PEP_0 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_PEP_1_Pos                _UINT32_(13)                                         /* (USBHS_DEVIMR) Endpoint 1 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_1_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_PEP_1_Pos)            /* (USBHS_DEVIMR) Endpoint 1 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_1(value)             (USBHS_DEVIMR_PEP_1_Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP_1_Pos)) /* Assigment of value for PEP_1 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_PEP_2_Pos                _UINT32_(14)                                         /* (USBHS_DEVIMR) Endpoint 2 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_2_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_PEP_2_Pos)            /* (USBHS_DEVIMR) Endpoint 2 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_2(value)             (USBHS_DEVIMR_PEP_2_Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP_2_Pos)) /* Assigment of value for PEP_2 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_PEP_3_Pos                _UINT32_(15)                                         /* (USBHS_DEVIMR) Endpoint 3 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_3_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_PEP_3_Pos)            /* (USBHS_DEVIMR) Endpoint 3 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_3(value)             (USBHS_DEVIMR_PEP_3_Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP_3_Pos)) /* Assigment of value for PEP_3 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_PEP_4_Pos                _UINT32_(16)                                         /* (USBHS_DEVIMR) Endpoint 4 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_4_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_PEP_4_Pos)            /* (USBHS_DEVIMR) Endpoint 4 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_4(value)             (USBHS_DEVIMR_PEP_4_Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP_4_Pos)) /* Assigment of value for PEP_4 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_PEP_5_Pos                _UINT32_(17)                                         /* (USBHS_DEVIMR) Endpoint 5 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_5_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_PEP_5_Pos)            /* (USBHS_DEVIMR) Endpoint 5 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_5(value)             (USBHS_DEVIMR_PEP_5_Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP_5_Pos)) /* Assigment of value for PEP_5 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_PEP_6_Pos                _UINT32_(18)                                         /* (USBHS_DEVIMR) Endpoint 6 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_6_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_PEP_6_Pos)            /* (USBHS_DEVIMR) Endpoint 6 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_6(value)             (USBHS_DEVIMR_PEP_6_Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP_6_Pos)) /* Assigment of value for PEP_6 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_PEP_7_Pos                _UINT32_(19)                                         /* (USBHS_DEVIMR) Endpoint 7 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_7_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_PEP_7_Pos)            /* (USBHS_DEVIMR) Endpoint 7 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_7(value)             (USBHS_DEVIMR_PEP_7_Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP_7_Pos)) /* Assigment of value for PEP_7 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_PEP_8_Pos                _UINT32_(20)                                         /* (USBHS_DEVIMR) Endpoint 8 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_8_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_PEP_8_Pos)            /* (USBHS_DEVIMR) Endpoint 8 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_8(value)             (USBHS_DEVIMR_PEP_8_Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP_8_Pos)) /* Assigment of value for PEP_8 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_PEP_9_Pos                _UINT32_(21)                                         /* (USBHS_DEVIMR) Endpoint 9 Interrupt Mask Position */
#define USBHS_DEVIMR_PEP_9_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_PEP_9_Pos)            /* (USBHS_DEVIMR) Endpoint 9 Interrupt Mask Mask */
#define USBHS_DEVIMR_PEP_9(value)             (USBHS_DEVIMR_PEP_9_Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP_9_Pos)) /* Assigment of value for PEP_9 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_DMA_1_Pos                _UINT32_(25)                                         /* (USBHS_DEVIMR) DMA Channel 1 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_1_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_DMA_1_Pos)            /* (USBHS_DEVIMR) DMA Channel 1 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_1(value)             (USBHS_DEVIMR_DMA_1_Msk & (_UINT32_(value) << USBHS_DEVIMR_DMA_1_Pos)) /* Assigment of value for DMA_1 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_DMA_2_Pos                _UINT32_(26)                                         /* (USBHS_DEVIMR) DMA Channel 2 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_2_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_DMA_2_Pos)            /* (USBHS_DEVIMR) DMA Channel 2 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_2(value)             (USBHS_DEVIMR_DMA_2_Msk & (_UINT32_(value) << USBHS_DEVIMR_DMA_2_Pos)) /* Assigment of value for DMA_2 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_DMA_3_Pos                _UINT32_(27)                                         /* (USBHS_DEVIMR) DMA Channel 3 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_3_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_DMA_3_Pos)            /* (USBHS_DEVIMR) DMA Channel 3 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_3(value)             (USBHS_DEVIMR_DMA_3_Msk & (_UINT32_(value) << USBHS_DEVIMR_DMA_3_Pos)) /* Assigment of value for DMA_3 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_DMA_4_Pos                _UINT32_(28)                                         /* (USBHS_DEVIMR) DMA Channel 4 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_4_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_DMA_4_Pos)            /* (USBHS_DEVIMR) DMA Channel 4 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_4(value)             (USBHS_DEVIMR_DMA_4_Msk & (_UINT32_(value) << USBHS_DEVIMR_DMA_4_Pos)) /* Assigment of value for DMA_4 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_DMA_5_Pos                _UINT32_(29)                                         /* (USBHS_DEVIMR) DMA Channel 5 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_5_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_DMA_5_Pos)            /* (USBHS_DEVIMR) DMA Channel 5 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_5(value)             (USBHS_DEVIMR_DMA_5_Msk & (_UINT32_(value) << USBHS_DEVIMR_DMA_5_Pos)) /* Assigment of value for DMA_5 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_DMA_6_Pos                _UINT32_(30)                                         /* (USBHS_DEVIMR) DMA Channel 6 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_6_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_DMA_6_Pos)            /* (USBHS_DEVIMR) DMA Channel 6 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_6(value)             (USBHS_DEVIMR_DMA_6_Msk & (_UINT32_(value) << USBHS_DEVIMR_DMA_6_Pos)) /* Assigment of value for DMA_6 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_DMA_7_Pos                _UINT32_(31)                                         /* (USBHS_DEVIMR) DMA Channel 7 Interrupt Mask Position */
#define USBHS_DEVIMR_DMA_7_Msk                (_UINT32_(0x1) << USBHS_DEVIMR_DMA_7_Pos)            /* (USBHS_DEVIMR) DMA Channel 7 Interrupt Mask Mask */
#define USBHS_DEVIMR_DMA_7(value)             (USBHS_DEVIMR_DMA_7_Msk & (_UINT32_(value) << USBHS_DEVIMR_DMA_7_Pos)) /* Assigment of value for DMA_7 in the USBHS_DEVIMR register */
#define USBHS_DEVIMR_Msk                      _UINT32_(0xFE3FF07F)                                 /* (USBHS_DEVIMR) Register Mask  */

#define USBHS_DEVIMR_PEP__Pos                 _UINT32_(12)                                         /* (USBHS_DEVIMR Position) Endpoint x Interrupt Mask */
#define USBHS_DEVIMR_PEP__Msk                 (_UINT32_(0x3FF) << USBHS_DEVIMR_PEP__Pos)           /* (USBHS_DEVIMR Mask) PEP_ */
#define USBHS_DEVIMR_PEP_(value)              (USBHS_DEVIMR_PEP__Msk & (_UINT32_(value) << USBHS_DEVIMR_PEP__Pos)) 
#define USBHS_DEVIMR_DMA__Pos                 _UINT32_(25)                                         /* (USBHS_DEVIMR Position) DMA Channel 7 Interrupt Mask */
#define USBHS_DEVIMR_DMA__Msk                 (_UINT32_(0x7F) << USBHS_DEVIMR_DMA__Pos)            /* (USBHS_DEVIMR Mask) DMA_ */
#define USBHS_DEVIMR_DMA_(value)              (USBHS_DEVIMR_DMA__Msk & (_UINT32_(value) << USBHS_DEVIMR_DMA__Pos)) 

/* -------- USBHS_DEVIDR : (USBHS Offset: 0x14) ( /W 32) Device Global Interrupt Disable Register -------- */
#define USBHS_DEVIDR_SUSPEC_Pos               _UINT32_(0)                                          /* (USBHS_DEVIDR) Suspend Interrupt Disable Position */
#define USBHS_DEVIDR_SUSPEC_Msk               (_UINT32_(0x1) << USBHS_DEVIDR_SUSPEC_Pos)           /* (USBHS_DEVIDR) Suspend Interrupt Disable Mask */
#define USBHS_DEVIDR_SUSPEC(value)            (USBHS_DEVIDR_SUSPEC_Msk & (_UINT32_(value) << USBHS_DEVIDR_SUSPEC_Pos)) /* Assigment of value for SUSPEC in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_MSOFEC_Pos               _UINT32_(1)                                          /* (USBHS_DEVIDR) Micro Start of Frame Interrupt Disable Position */
#define USBHS_DEVIDR_MSOFEC_Msk               (_UINT32_(0x1) << USBHS_DEVIDR_MSOFEC_Pos)           /* (USBHS_DEVIDR) Micro Start of Frame Interrupt Disable Mask */
#define USBHS_DEVIDR_MSOFEC(value)            (USBHS_DEVIDR_MSOFEC_Msk & (_UINT32_(value) << USBHS_DEVIDR_MSOFEC_Pos)) /* Assigment of value for MSOFEC in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_SOFEC_Pos                _UINT32_(2)                                          /* (USBHS_DEVIDR) Start of Frame Interrupt Disable Position */
#define USBHS_DEVIDR_SOFEC_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_SOFEC_Pos)            /* (USBHS_DEVIDR) Start of Frame Interrupt Disable Mask */
#define USBHS_DEVIDR_SOFEC(value)             (USBHS_DEVIDR_SOFEC_Msk & (_UINT32_(value) << USBHS_DEVIDR_SOFEC_Pos)) /* Assigment of value for SOFEC in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_EORSTEC_Pos              _UINT32_(3)                                          /* (USBHS_DEVIDR) End of Reset Interrupt Disable Position */
#define USBHS_DEVIDR_EORSTEC_Msk              (_UINT32_(0x1) << USBHS_DEVIDR_EORSTEC_Pos)          /* (USBHS_DEVIDR) End of Reset Interrupt Disable Mask */
#define USBHS_DEVIDR_EORSTEC(value)           (USBHS_DEVIDR_EORSTEC_Msk & (_UINT32_(value) << USBHS_DEVIDR_EORSTEC_Pos)) /* Assigment of value for EORSTEC in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_WAKEUPEC_Pos             _UINT32_(4)                                          /* (USBHS_DEVIDR) Wake-Up Interrupt Disable Position */
#define USBHS_DEVIDR_WAKEUPEC_Msk             (_UINT32_(0x1) << USBHS_DEVIDR_WAKEUPEC_Pos)         /* (USBHS_DEVIDR) Wake-Up Interrupt Disable Mask */
#define USBHS_DEVIDR_WAKEUPEC(value)          (USBHS_DEVIDR_WAKEUPEC_Msk & (_UINT32_(value) << USBHS_DEVIDR_WAKEUPEC_Pos)) /* Assigment of value for WAKEUPEC in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_EORSMEC_Pos              _UINT32_(5)                                          /* (USBHS_DEVIDR) End of Resume Interrupt Disable Position */
#define USBHS_DEVIDR_EORSMEC_Msk              (_UINT32_(0x1) << USBHS_DEVIDR_EORSMEC_Pos)          /* (USBHS_DEVIDR) End of Resume Interrupt Disable Mask */
#define USBHS_DEVIDR_EORSMEC(value)           (USBHS_DEVIDR_EORSMEC_Msk & (_UINT32_(value) << USBHS_DEVIDR_EORSMEC_Pos)) /* Assigment of value for EORSMEC in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_UPRSMEC_Pos              _UINT32_(6)                                          /* (USBHS_DEVIDR) Upstream Resume Interrupt Disable Position */
#define USBHS_DEVIDR_UPRSMEC_Msk              (_UINT32_(0x1) << USBHS_DEVIDR_UPRSMEC_Pos)          /* (USBHS_DEVIDR) Upstream Resume Interrupt Disable Mask */
#define USBHS_DEVIDR_UPRSMEC(value)           (USBHS_DEVIDR_UPRSMEC_Msk & (_UINT32_(value) << USBHS_DEVIDR_UPRSMEC_Pos)) /* Assigment of value for UPRSMEC in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_PEP_0_Pos                _UINT32_(12)                                         /* (USBHS_DEVIDR) Endpoint 0 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_0_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_PEP_0_Pos)            /* (USBHS_DEVIDR) Endpoint 0 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_0(value)             (USBHS_DEVIDR_PEP_0_Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP_0_Pos)) /* Assigment of value for PEP_0 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_PEP_1_Pos                _UINT32_(13)                                         /* (USBHS_DEVIDR) Endpoint 1 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_1_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_PEP_1_Pos)            /* (USBHS_DEVIDR) Endpoint 1 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_1(value)             (USBHS_DEVIDR_PEP_1_Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP_1_Pos)) /* Assigment of value for PEP_1 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_PEP_2_Pos                _UINT32_(14)                                         /* (USBHS_DEVIDR) Endpoint 2 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_2_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_PEP_2_Pos)            /* (USBHS_DEVIDR) Endpoint 2 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_2(value)             (USBHS_DEVIDR_PEP_2_Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP_2_Pos)) /* Assigment of value for PEP_2 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_PEP_3_Pos                _UINT32_(15)                                         /* (USBHS_DEVIDR) Endpoint 3 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_3_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_PEP_3_Pos)            /* (USBHS_DEVIDR) Endpoint 3 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_3(value)             (USBHS_DEVIDR_PEP_3_Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP_3_Pos)) /* Assigment of value for PEP_3 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_PEP_4_Pos                _UINT32_(16)                                         /* (USBHS_DEVIDR) Endpoint 4 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_4_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_PEP_4_Pos)            /* (USBHS_DEVIDR) Endpoint 4 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_4(value)             (USBHS_DEVIDR_PEP_4_Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP_4_Pos)) /* Assigment of value for PEP_4 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_PEP_5_Pos                _UINT32_(17)                                         /* (USBHS_DEVIDR) Endpoint 5 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_5_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_PEP_5_Pos)            /* (USBHS_DEVIDR) Endpoint 5 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_5(value)             (USBHS_DEVIDR_PEP_5_Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP_5_Pos)) /* Assigment of value for PEP_5 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_PEP_6_Pos                _UINT32_(18)                                         /* (USBHS_DEVIDR) Endpoint 6 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_6_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_PEP_6_Pos)            /* (USBHS_DEVIDR) Endpoint 6 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_6(value)             (USBHS_DEVIDR_PEP_6_Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP_6_Pos)) /* Assigment of value for PEP_6 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_PEP_7_Pos                _UINT32_(19)                                         /* (USBHS_DEVIDR) Endpoint 7 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_7_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_PEP_7_Pos)            /* (USBHS_DEVIDR) Endpoint 7 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_7(value)             (USBHS_DEVIDR_PEP_7_Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP_7_Pos)) /* Assigment of value for PEP_7 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_PEP_8_Pos                _UINT32_(20)                                         /* (USBHS_DEVIDR) Endpoint 8 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_8_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_PEP_8_Pos)            /* (USBHS_DEVIDR) Endpoint 8 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_8(value)             (USBHS_DEVIDR_PEP_8_Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP_8_Pos)) /* Assigment of value for PEP_8 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_PEP_9_Pos                _UINT32_(21)                                         /* (USBHS_DEVIDR) Endpoint 9 Interrupt Disable Position */
#define USBHS_DEVIDR_PEP_9_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_PEP_9_Pos)            /* (USBHS_DEVIDR) Endpoint 9 Interrupt Disable Mask */
#define USBHS_DEVIDR_PEP_9(value)             (USBHS_DEVIDR_PEP_9_Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP_9_Pos)) /* Assigment of value for PEP_9 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_DMA_1_Pos                _UINT32_(25)                                         /* (USBHS_DEVIDR) DMA Channel 1 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_1_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_DMA_1_Pos)            /* (USBHS_DEVIDR) DMA Channel 1 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_1(value)             (USBHS_DEVIDR_DMA_1_Msk & (_UINT32_(value) << USBHS_DEVIDR_DMA_1_Pos)) /* Assigment of value for DMA_1 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_DMA_2_Pos                _UINT32_(26)                                         /* (USBHS_DEVIDR) DMA Channel 2 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_2_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_DMA_2_Pos)            /* (USBHS_DEVIDR) DMA Channel 2 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_2(value)             (USBHS_DEVIDR_DMA_2_Msk & (_UINT32_(value) << USBHS_DEVIDR_DMA_2_Pos)) /* Assigment of value for DMA_2 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_DMA_3_Pos                _UINT32_(27)                                         /* (USBHS_DEVIDR) DMA Channel 3 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_3_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_DMA_3_Pos)            /* (USBHS_DEVIDR) DMA Channel 3 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_3(value)             (USBHS_DEVIDR_DMA_3_Msk & (_UINT32_(value) << USBHS_DEVIDR_DMA_3_Pos)) /* Assigment of value for DMA_3 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_DMA_4_Pos                _UINT32_(28)                                         /* (USBHS_DEVIDR) DMA Channel 4 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_4_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_DMA_4_Pos)            /* (USBHS_DEVIDR) DMA Channel 4 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_4(value)             (USBHS_DEVIDR_DMA_4_Msk & (_UINT32_(value) << USBHS_DEVIDR_DMA_4_Pos)) /* Assigment of value for DMA_4 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_DMA_5_Pos                _UINT32_(29)                                         /* (USBHS_DEVIDR) DMA Channel 5 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_5_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_DMA_5_Pos)            /* (USBHS_DEVIDR) DMA Channel 5 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_5(value)             (USBHS_DEVIDR_DMA_5_Msk & (_UINT32_(value) << USBHS_DEVIDR_DMA_5_Pos)) /* Assigment of value for DMA_5 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_DMA_6_Pos                _UINT32_(30)                                         /* (USBHS_DEVIDR) DMA Channel 6 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_6_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_DMA_6_Pos)            /* (USBHS_DEVIDR) DMA Channel 6 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_6(value)             (USBHS_DEVIDR_DMA_6_Msk & (_UINT32_(value) << USBHS_DEVIDR_DMA_6_Pos)) /* Assigment of value for DMA_6 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_DMA_7_Pos                _UINT32_(31)                                         /* (USBHS_DEVIDR) DMA Channel 7 Interrupt Disable Position */
#define USBHS_DEVIDR_DMA_7_Msk                (_UINT32_(0x1) << USBHS_DEVIDR_DMA_7_Pos)            /* (USBHS_DEVIDR) DMA Channel 7 Interrupt Disable Mask */
#define USBHS_DEVIDR_DMA_7(value)             (USBHS_DEVIDR_DMA_7_Msk & (_UINT32_(value) << USBHS_DEVIDR_DMA_7_Pos)) /* Assigment of value for DMA_7 in the USBHS_DEVIDR register */
#define USBHS_DEVIDR_Msk                      _UINT32_(0xFE3FF07F)                                 /* (USBHS_DEVIDR) Register Mask  */

#define USBHS_DEVIDR_PEP__Pos                 _UINT32_(12)                                         /* (USBHS_DEVIDR Position) Endpoint x Interrupt Disable */
#define USBHS_DEVIDR_PEP__Msk                 (_UINT32_(0x3FF) << USBHS_DEVIDR_PEP__Pos)           /* (USBHS_DEVIDR Mask) PEP_ */
#define USBHS_DEVIDR_PEP_(value)              (USBHS_DEVIDR_PEP__Msk & (_UINT32_(value) << USBHS_DEVIDR_PEP__Pos)) 
#define USBHS_DEVIDR_DMA__Pos                 _UINT32_(25)                                         /* (USBHS_DEVIDR Position) DMA Channel 7 Interrupt Disable */
#define USBHS_DEVIDR_DMA__Msk                 (_UINT32_(0x7F) << USBHS_DEVIDR_DMA__Pos)            /* (USBHS_DEVIDR Mask) DMA_ */
#define USBHS_DEVIDR_DMA_(value)              (USBHS_DEVIDR_DMA__Msk & (_UINT32_(value) << USBHS_DEVIDR_DMA__Pos)) 

/* -------- USBHS_DEVIER : (USBHS Offset: 0x18) ( /W 32) Device Global Interrupt Enable Register -------- */
#define USBHS_DEVIER_SUSPES_Pos               _UINT32_(0)                                          /* (USBHS_DEVIER) Suspend Interrupt Enable Position */
#define USBHS_DEVIER_SUSPES_Msk               (_UINT32_(0x1) << USBHS_DEVIER_SUSPES_Pos)           /* (USBHS_DEVIER) Suspend Interrupt Enable Mask */
#define USBHS_DEVIER_SUSPES(value)            (USBHS_DEVIER_SUSPES_Msk & (_UINT32_(value) << USBHS_DEVIER_SUSPES_Pos)) /* Assigment of value for SUSPES in the USBHS_DEVIER register */
#define USBHS_DEVIER_MSOFES_Pos               _UINT32_(1)                                          /* (USBHS_DEVIER) Micro Start of Frame Interrupt Enable Position */
#define USBHS_DEVIER_MSOFES_Msk               (_UINT32_(0x1) << USBHS_DEVIER_MSOFES_Pos)           /* (USBHS_DEVIER) Micro Start of Frame Interrupt Enable Mask */
#define USBHS_DEVIER_MSOFES(value)            (USBHS_DEVIER_MSOFES_Msk & (_UINT32_(value) << USBHS_DEVIER_MSOFES_Pos)) /* Assigment of value for MSOFES in the USBHS_DEVIER register */
#define USBHS_DEVIER_SOFES_Pos                _UINT32_(2)                                          /* (USBHS_DEVIER) Start of Frame Interrupt Enable Position */
#define USBHS_DEVIER_SOFES_Msk                (_UINT32_(0x1) << USBHS_DEVIER_SOFES_Pos)            /* (USBHS_DEVIER) Start of Frame Interrupt Enable Mask */
#define USBHS_DEVIER_SOFES(value)             (USBHS_DEVIER_SOFES_Msk & (_UINT32_(value) << USBHS_DEVIER_SOFES_Pos)) /* Assigment of value for SOFES in the USBHS_DEVIER register */
#define USBHS_DEVIER_EORSTES_Pos              _UINT32_(3)                                          /* (USBHS_DEVIER) End of Reset Interrupt Enable Position */
#define USBHS_DEVIER_EORSTES_Msk              (_UINT32_(0x1) << USBHS_DEVIER_EORSTES_Pos)          /* (USBHS_DEVIER) End of Reset Interrupt Enable Mask */
#define USBHS_DEVIER_EORSTES(value)           (USBHS_DEVIER_EORSTES_Msk & (_UINT32_(value) << USBHS_DEVIER_EORSTES_Pos)) /* Assigment of value for EORSTES in the USBHS_DEVIER register */
#define USBHS_DEVIER_WAKEUPES_Pos             _UINT32_(4)                                          /* (USBHS_DEVIER) Wake-Up Interrupt Enable Position */
#define USBHS_DEVIER_WAKEUPES_Msk             (_UINT32_(0x1) << USBHS_DEVIER_WAKEUPES_Pos)         /* (USBHS_DEVIER) Wake-Up Interrupt Enable Mask */
#define USBHS_DEVIER_WAKEUPES(value)          (USBHS_DEVIER_WAKEUPES_Msk & (_UINT32_(value) << USBHS_DEVIER_WAKEUPES_Pos)) /* Assigment of value for WAKEUPES in the USBHS_DEVIER register */
#define USBHS_DEVIER_EORSMES_Pos              _UINT32_(5)                                          /* (USBHS_DEVIER) End of Resume Interrupt Enable Position */
#define USBHS_DEVIER_EORSMES_Msk              (_UINT32_(0x1) << USBHS_DEVIER_EORSMES_Pos)          /* (USBHS_DEVIER) End of Resume Interrupt Enable Mask */
#define USBHS_DEVIER_EORSMES(value)           (USBHS_DEVIER_EORSMES_Msk & (_UINT32_(value) << USBHS_DEVIER_EORSMES_Pos)) /* Assigment of value for EORSMES in the USBHS_DEVIER register */
#define USBHS_DEVIER_UPRSMES_Pos              _UINT32_(6)                                          /* (USBHS_DEVIER) Upstream Resume Interrupt Enable Position */
#define USBHS_DEVIER_UPRSMES_Msk              (_UINT32_(0x1) << USBHS_DEVIER_UPRSMES_Pos)          /* (USBHS_DEVIER) Upstream Resume Interrupt Enable Mask */
#define USBHS_DEVIER_UPRSMES(value)           (USBHS_DEVIER_UPRSMES_Msk & (_UINT32_(value) << USBHS_DEVIER_UPRSMES_Pos)) /* Assigment of value for UPRSMES in the USBHS_DEVIER register */
#define USBHS_DEVIER_PEP_0_Pos                _UINT32_(12)                                         /* (USBHS_DEVIER) Endpoint 0 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_0_Msk                (_UINT32_(0x1) << USBHS_DEVIER_PEP_0_Pos)            /* (USBHS_DEVIER) Endpoint 0 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_0(value)             (USBHS_DEVIER_PEP_0_Msk & (_UINT32_(value) << USBHS_DEVIER_PEP_0_Pos)) /* Assigment of value for PEP_0 in the USBHS_DEVIER register */
#define USBHS_DEVIER_PEP_1_Pos                _UINT32_(13)                                         /* (USBHS_DEVIER) Endpoint 1 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_1_Msk                (_UINT32_(0x1) << USBHS_DEVIER_PEP_1_Pos)            /* (USBHS_DEVIER) Endpoint 1 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_1(value)             (USBHS_DEVIER_PEP_1_Msk & (_UINT32_(value) << USBHS_DEVIER_PEP_1_Pos)) /* Assigment of value for PEP_1 in the USBHS_DEVIER register */
#define USBHS_DEVIER_PEP_2_Pos                _UINT32_(14)                                         /* (USBHS_DEVIER) Endpoint 2 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_2_Msk                (_UINT32_(0x1) << USBHS_DEVIER_PEP_2_Pos)            /* (USBHS_DEVIER) Endpoint 2 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_2(value)             (USBHS_DEVIER_PEP_2_Msk & (_UINT32_(value) << USBHS_DEVIER_PEP_2_Pos)) /* Assigment of value for PEP_2 in the USBHS_DEVIER register */
#define USBHS_DEVIER_PEP_3_Pos                _UINT32_(15)                                         /* (USBHS_DEVIER) Endpoint 3 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_3_Msk                (_UINT32_(0x1) << USBHS_DEVIER_PEP_3_Pos)            /* (USBHS_DEVIER) Endpoint 3 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_3(value)             (USBHS_DEVIER_PEP_3_Msk & (_UINT32_(value) << USBHS_DEVIER_PEP_3_Pos)) /* Assigment of value for PEP_3 in the USBHS_DEVIER register */
#define USBHS_DEVIER_PEP_4_Pos                _UINT32_(16)                                         /* (USBHS_DEVIER) Endpoint 4 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_4_Msk                (_UINT32_(0x1) << USBHS_DEVIER_PEP_4_Pos)            /* (USBHS_DEVIER) Endpoint 4 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_4(value)             (USBHS_DEVIER_PEP_4_Msk & (_UINT32_(value) << USBHS_DEVIER_PEP_4_Pos)) /* Assigment of value for PEP_4 in the USBHS_DEVIER register */
#define USBHS_DEVIER_PEP_5_Pos                _UINT32_(17)                                         /* (USBHS_DEVIER) Endpoint 5 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_5_Msk                (_UINT32_(0x1) << USBHS_DEVIER_PEP_5_Pos)            /* (USBHS_DEVIER) Endpoint 5 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_5(value)             (USBHS_DEVIER_PEP_5_Msk & (_UINT32_(value) << USBHS_DEVIER_PEP_5_Pos)) /* Assigment of value for PEP_5 in the USBHS_DEVIER register */
#define USBHS_DEVIER_PEP_6_Pos                _UINT32_(18)                                         /* (USBHS_DEVIER) Endpoint 6 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_6_Msk                (_UINT32_(0x1) << USBHS_DEVIER_PEP_6_Pos)            /* (USBHS_DEVIER) Endpoint 6 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_6(value)             (USBHS_DEVIER_PEP_6_Msk & (_UINT32_(value) << USBHS_DEVIER_PEP_6_Pos)) /* Assigment of value for PEP_6 in the USBHS_DEVIER register */
#define USBHS_DEVIER_PEP_7_Pos                _UINT32_(19)                                         /* (USBHS_DEVIER) Endpoint 7 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_7_Msk                (_UINT32_(0x1) << USBHS_DEVIER_PEP_7_Pos)            /* (USBHS_DEVIER) Endpoint 7 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_7(value)             (USBHS_DEVIER_PEP_7_Msk & (_UINT32_(value) << USBHS_DEVIER_PEP_7_Pos)) /* Assigment of value for PEP_7 in the USBHS_DEVIER register */
#define USBHS_DEVIER_PEP_8_Pos                _UINT32_(20)                                         /* (USBHS_DEVIER) Endpoint 8 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_8_Msk                (_UINT32_(0x1) << USBHS_DEVIER_PEP_8_Pos)            /* (USBHS_DEVIER) Endpoint 8 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_8(value)             (USBHS_DEVIER_PEP_8_Msk & (_UINT32_(value) << USBHS_DEVIER_PEP_8_Pos)) /* Assigment of value for PEP_8 in the USBHS_DEVIER register */
#define USBHS_DEVIER_PEP_9_Pos                _UINT32_(21)                                         /* (USBHS_DEVIER) Endpoint 9 Interrupt Enable Position */
#define USBHS_DEVIER_PEP_9_Msk                (_UINT32_(0x1) << USBHS_DEVIER_PEP_9_Pos)            /* (USBHS_DEVIER) Endpoint 9 Interrupt Enable Mask */
#define USBHS_DEVIER_PEP_9(value)             (USBHS_DEVIER_PEP_9_Msk & (_UINT32_(value) << USBHS_DEVIER_PEP_9_Pos)) /* Assigment of value for PEP_9 in the USBHS_DEVIER register */
#define USBHS_DEVIER_DMA_1_Pos                _UINT32_(25)                                         /* (USBHS_DEVIER) DMA Channel 1 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_1_Msk                (_UINT32_(0x1) << USBHS_DEVIER_DMA_1_Pos)            /* (USBHS_DEVIER) DMA Channel 1 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_1(value)             (USBHS_DEVIER_DMA_1_Msk & (_UINT32_(value) << USBHS_DEVIER_DMA_1_Pos)) /* Assigment of value for DMA_1 in the USBHS_DEVIER register */
#define USBHS_DEVIER_DMA_2_Pos                _UINT32_(26)                                         /* (USBHS_DEVIER) DMA Channel 2 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_2_Msk                (_UINT32_(0x1) << USBHS_DEVIER_DMA_2_Pos)            /* (USBHS_DEVIER) DMA Channel 2 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_2(value)             (USBHS_DEVIER_DMA_2_Msk & (_UINT32_(value) << USBHS_DEVIER_DMA_2_Pos)) /* Assigment of value for DMA_2 in the USBHS_DEVIER register */
#define USBHS_DEVIER_DMA_3_Pos                _UINT32_(27)                                         /* (USBHS_DEVIER) DMA Channel 3 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_3_Msk                (_UINT32_(0x1) << USBHS_DEVIER_DMA_3_Pos)            /* (USBHS_DEVIER) DMA Channel 3 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_3(value)             (USBHS_DEVIER_DMA_3_Msk & (_UINT32_(value) << USBHS_DEVIER_DMA_3_Pos)) /* Assigment of value for DMA_3 in the USBHS_DEVIER register */
#define USBHS_DEVIER_DMA_4_Pos                _UINT32_(28)                                         /* (USBHS_DEVIER) DMA Channel 4 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_4_Msk                (_UINT32_(0x1) << USBHS_DEVIER_DMA_4_Pos)            /* (USBHS_DEVIER) DMA Channel 4 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_4(value)             (USBHS_DEVIER_DMA_4_Msk & (_UINT32_(value) << USBHS_DEVIER_DMA_4_Pos)) /* Assigment of value for DMA_4 in the USBHS_DEVIER register */
#define USBHS_DEVIER_DMA_5_Pos                _UINT32_(29)                                         /* (USBHS_DEVIER) DMA Channel 5 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_5_Msk                (_UINT32_(0x1) << USBHS_DEVIER_DMA_5_Pos)            /* (USBHS_DEVIER) DMA Channel 5 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_5(value)             (USBHS_DEVIER_DMA_5_Msk & (_UINT32_(value) << USBHS_DEVIER_DMA_5_Pos)) /* Assigment of value for DMA_5 in the USBHS_DEVIER register */
#define USBHS_DEVIER_DMA_6_Pos                _UINT32_(30)                                         /* (USBHS_DEVIER) DMA Channel 6 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_6_Msk                (_UINT32_(0x1) << USBHS_DEVIER_DMA_6_Pos)            /* (USBHS_DEVIER) DMA Channel 6 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_6(value)             (USBHS_DEVIER_DMA_6_Msk & (_UINT32_(value) << USBHS_DEVIER_DMA_6_Pos)) /* Assigment of value for DMA_6 in the USBHS_DEVIER register */
#define USBHS_DEVIER_DMA_7_Pos                _UINT32_(31)                                         /* (USBHS_DEVIER) DMA Channel 7 Interrupt Enable Position */
#define USBHS_DEVIER_DMA_7_Msk                (_UINT32_(0x1) << USBHS_DEVIER_DMA_7_Pos)            /* (USBHS_DEVIER) DMA Channel 7 Interrupt Enable Mask */
#define USBHS_DEVIER_DMA_7(value)             (USBHS_DEVIER_DMA_7_Msk & (_UINT32_(value) << USBHS_DEVIER_DMA_7_Pos)) /* Assigment of value for DMA_7 in the USBHS_DEVIER register */
#define USBHS_DEVIER_Msk                      _UINT32_(0xFE3FF07F)                                 /* (USBHS_DEVIER) Register Mask  */

#define USBHS_DEVIER_PEP__Pos                 _UINT32_(12)                                         /* (USBHS_DEVIER Position) Endpoint x Interrupt Enable */
#define USBHS_DEVIER_PEP__Msk                 (_UINT32_(0x3FF) << USBHS_DEVIER_PEP__Pos)           /* (USBHS_DEVIER Mask) PEP_ */
#define USBHS_DEVIER_PEP_(value)              (USBHS_DEVIER_PEP__Msk & (_UINT32_(value) << USBHS_DEVIER_PEP__Pos)) 
#define USBHS_DEVIER_DMA__Pos                 _UINT32_(25)                                         /* (USBHS_DEVIER Position) DMA Channel 7 Interrupt Enable */
#define USBHS_DEVIER_DMA__Msk                 (_UINT32_(0x7F) << USBHS_DEVIER_DMA__Pos)            /* (USBHS_DEVIER Mask) DMA_ */
#define USBHS_DEVIER_DMA_(value)              (USBHS_DEVIER_DMA__Msk & (_UINT32_(value) << USBHS_DEVIER_DMA__Pos)) 

/* -------- USBHS_DEVEPT : (USBHS Offset: 0x1C) (R/W 32) Device Endpoint Register -------- */
#define USBHS_DEVEPT_EPEN0_Pos                _UINT32_(0)                                          /* (USBHS_DEVEPT) Endpoint 0 Enable Position */
#define USBHS_DEVEPT_EPEN0_Msk                (_UINT32_(0x1) << USBHS_DEVEPT_EPEN0_Pos)            /* (USBHS_DEVEPT) Endpoint 0 Enable Mask */
#define USBHS_DEVEPT_EPEN0(value)             (USBHS_DEVEPT_EPEN0_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN0_Pos)) /* Assigment of value for EPEN0 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPEN1_Pos                _UINT32_(1)                                          /* (USBHS_DEVEPT) Endpoint 1 Enable Position */
#define USBHS_DEVEPT_EPEN1_Msk                (_UINT32_(0x1) << USBHS_DEVEPT_EPEN1_Pos)            /* (USBHS_DEVEPT) Endpoint 1 Enable Mask */
#define USBHS_DEVEPT_EPEN1(value)             (USBHS_DEVEPT_EPEN1_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN1_Pos)) /* Assigment of value for EPEN1 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPEN2_Pos                _UINT32_(2)                                          /* (USBHS_DEVEPT) Endpoint 2 Enable Position */
#define USBHS_DEVEPT_EPEN2_Msk                (_UINT32_(0x1) << USBHS_DEVEPT_EPEN2_Pos)            /* (USBHS_DEVEPT) Endpoint 2 Enable Mask */
#define USBHS_DEVEPT_EPEN2(value)             (USBHS_DEVEPT_EPEN2_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN2_Pos)) /* Assigment of value for EPEN2 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPEN3_Pos                _UINT32_(3)                                          /* (USBHS_DEVEPT) Endpoint 3 Enable Position */
#define USBHS_DEVEPT_EPEN3_Msk                (_UINT32_(0x1) << USBHS_DEVEPT_EPEN3_Pos)            /* (USBHS_DEVEPT) Endpoint 3 Enable Mask */
#define USBHS_DEVEPT_EPEN3(value)             (USBHS_DEVEPT_EPEN3_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN3_Pos)) /* Assigment of value for EPEN3 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPEN4_Pos                _UINT32_(4)                                          /* (USBHS_DEVEPT) Endpoint 4 Enable Position */
#define USBHS_DEVEPT_EPEN4_Msk                (_UINT32_(0x1) << USBHS_DEVEPT_EPEN4_Pos)            /* (USBHS_DEVEPT) Endpoint 4 Enable Mask */
#define USBHS_DEVEPT_EPEN4(value)             (USBHS_DEVEPT_EPEN4_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN4_Pos)) /* Assigment of value for EPEN4 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPEN5_Pos                _UINT32_(5)                                          /* (USBHS_DEVEPT) Endpoint 5 Enable Position */
#define USBHS_DEVEPT_EPEN5_Msk                (_UINT32_(0x1) << USBHS_DEVEPT_EPEN5_Pos)            /* (USBHS_DEVEPT) Endpoint 5 Enable Mask */
#define USBHS_DEVEPT_EPEN5(value)             (USBHS_DEVEPT_EPEN5_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN5_Pos)) /* Assigment of value for EPEN5 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPEN6_Pos                _UINT32_(6)                                          /* (USBHS_DEVEPT) Endpoint 6 Enable Position */
#define USBHS_DEVEPT_EPEN6_Msk                (_UINT32_(0x1) << USBHS_DEVEPT_EPEN6_Pos)            /* (USBHS_DEVEPT) Endpoint 6 Enable Mask */
#define USBHS_DEVEPT_EPEN6(value)             (USBHS_DEVEPT_EPEN6_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN6_Pos)) /* Assigment of value for EPEN6 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPEN7_Pos                _UINT32_(7)                                          /* (USBHS_DEVEPT) Endpoint 7 Enable Position */
#define USBHS_DEVEPT_EPEN7_Msk                (_UINT32_(0x1) << USBHS_DEVEPT_EPEN7_Pos)            /* (USBHS_DEVEPT) Endpoint 7 Enable Mask */
#define USBHS_DEVEPT_EPEN7(value)             (USBHS_DEVEPT_EPEN7_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN7_Pos)) /* Assigment of value for EPEN7 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPEN8_Pos                _UINT32_(8)                                          /* (USBHS_DEVEPT) Endpoint 8 Enable Position */
#define USBHS_DEVEPT_EPEN8_Msk                (_UINT32_(0x1) << USBHS_DEVEPT_EPEN8_Pos)            /* (USBHS_DEVEPT) Endpoint 8 Enable Mask */
#define USBHS_DEVEPT_EPEN8(value)             (USBHS_DEVEPT_EPEN8_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN8_Pos)) /* Assigment of value for EPEN8 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPEN9_Pos                _UINT32_(9)                                          /* (USBHS_DEVEPT) Endpoint 9 Enable Position */
#define USBHS_DEVEPT_EPEN9_Msk                (_UINT32_(0x1) << USBHS_DEVEPT_EPEN9_Pos)            /* (USBHS_DEVEPT) Endpoint 9 Enable Mask */
#define USBHS_DEVEPT_EPEN9(value)             (USBHS_DEVEPT_EPEN9_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN9_Pos)) /* Assigment of value for EPEN9 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPRST0_Pos               _UINT32_(16)                                         /* (USBHS_DEVEPT) Endpoint 0 Reset Position */
#define USBHS_DEVEPT_EPRST0_Msk               (_UINT32_(0x1) << USBHS_DEVEPT_EPRST0_Pos)           /* (USBHS_DEVEPT) Endpoint 0 Reset Mask */
#define USBHS_DEVEPT_EPRST0(value)            (USBHS_DEVEPT_EPRST0_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST0_Pos)) /* Assigment of value for EPRST0 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPRST1_Pos               _UINT32_(17)                                         /* (USBHS_DEVEPT) Endpoint 1 Reset Position */
#define USBHS_DEVEPT_EPRST1_Msk               (_UINT32_(0x1) << USBHS_DEVEPT_EPRST1_Pos)           /* (USBHS_DEVEPT) Endpoint 1 Reset Mask */
#define USBHS_DEVEPT_EPRST1(value)            (USBHS_DEVEPT_EPRST1_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST1_Pos)) /* Assigment of value for EPRST1 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPRST2_Pos               _UINT32_(18)                                         /* (USBHS_DEVEPT) Endpoint 2 Reset Position */
#define USBHS_DEVEPT_EPRST2_Msk               (_UINT32_(0x1) << USBHS_DEVEPT_EPRST2_Pos)           /* (USBHS_DEVEPT) Endpoint 2 Reset Mask */
#define USBHS_DEVEPT_EPRST2(value)            (USBHS_DEVEPT_EPRST2_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST2_Pos)) /* Assigment of value for EPRST2 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPRST3_Pos               _UINT32_(19)                                         /* (USBHS_DEVEPT) Endpoint 3 Reset Position */
#define USBHS_DEVEPT_EPRST3_Msk               (_UINT32_(0x1) << USBHS_DEVEPT_EPRST3_Pos)           /* (USBHS_DEVEPT) Endpoint 3 Reset Mask */
#define USBHS_DEVEPT_EPRST3(value)            (USBHS_DEVEPT_EPRST3_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST3_Pos)) /* Assigment of value for EPRST3 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPRST4_Pos               _UINT32_(20)                                         /* (USBHS_DEVEPT) Endpoint 4 Reset Position */
#define USBHS_DEVEPT_EPRST4_Msk               (_UINT32_(0x1) << USBHS_DEVEPT_EPRST4_Pos)           /* (USBHS_DEVEPT) Endpoint 4 Reset Mask */
#define USBHS_DEVEPT_EPRST4(value)            (USBHS_DEVEPT_EPRST4_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST4_Pos)) /* Assigment of value for EPRST4 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPRST5_Pos               _UINT32_(21)                                         /* (USBHS_DEVEPT) Endpoint 5 Reset Position */
#define USBHS_DEVEPT_EPRST5_Msk               (_UINT32_(0x1) << USBHS_DEVEPT_EPRST5_Pos)           /* (USBHS_DEVEPT) Endpoint 5 Reset Mask */
#define USBHS_DEVEPT_EPRST5(value)            (USBHS_DEVEPT_EPRST5_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST5_Pos)) /* Assigment of value for EPRST5 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPRST6_Pos               _UINT32_(22)                                         /* (USBHS_DEVEPT) Endpoint 6 Reset Position */
#define USBHS_DEVEPT_EPRST6_Msk               (_UINT32_(0x1) << USBHS_DEVEPT_EPRST6_Pos)           /* (USBHS_DEVEPT) Endpoint 6 Reset Mask */
#define USBHS_DEVEPT_EPRST6(value)            (USBHS_DEVEPT_EPRST6_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST6_Pos)) /* Assigment of value for EPRST6 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPRST7_Pos               _UINT32_(23)                                         /* (USBHS_DEVEPT) Endpoint 7 Reset Position */
#define USBHS_DEVEPT_EPRST7_Msk               (_UINT32_(0x1) << USBHS_DEVEPT_EPRST7_Pos)           /* (USBHS_DEVEPT) Endpoint 7 Reset Mask */
#define USBHS_DEVEPT_EPRST7(value)            (USBHS_DEVEPT_EPRST7_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST7_Pos)) /* Assigment of value for EPRST7 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPRST8_Pos               _UINT32_(24)                                         /* (USBHS_DEVEPT) Endpoint 8 Reset Position */
#define USBHS_DEVEPT_EPRST8_Msk               (_UINT32_(0x1) << USBHS_DEVEPT_EPRST8_Pos)           /* (USBHS_DEVEPT) Endpoint 8 Reset Mask */
#define USBHS_DEVEPT_EPRST8(value)            (USBHS_DEVEPT_EPRST8_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST8_Pos)) /* Assigment of value for EPRST8 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_EPRST9_Pos               _UINT32_(25)                                         /* (USBHS_DEVEPT) Endpoint 9 Reset Position */
#define USBHS_DEVEPT_EPRST9_Msk               (_UINT32_(0x1) << USBHS_DEVEPT_EPRST9_Pos)           /* (USBHS_DEVEPT) Endpoint 9 Reset Mask */
#define USBHS_DEVEPT_EPRST9(value)            (USBHS_DEVEPT_EPRST9_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST9_Pos)) /* Assigment of value for EPRST9 in the USBHS_DEVEPT register */
#define USBHS_DEVEPT_Msk                      _UINT32_(0x03FF03FF)                                 /* (USBHS_DEVEPT) Register Mask  */

#define USBHS_DEVEPT_EPEN_Pos                 _UINT32_(0)                                          /* (USBHS_DEVEPT Position) Endpoint x Enable */
#define USBHS_DEVEPT_EPEN_Msk                 (_UINT32_(0x3FF) << USBHS_DEVEPT_EPEN_Pos)           /* (USBHS_DEVEPT Mask) EPEN */
#define USBHS_DEVEPT_EPEN(value)              (USBHS_DEVEPT_EPEN_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPEN_Pos)) 
#define USBHS_DEVEPT_EPRST_Pos                _UINT32_(16)                                         /* (USBHS_DEVEPT Position) Endpoint 9 Reset */
#define USBHS_DEVEPT_EPRST_Msk                (_UINT32_(0x3FF) << USBHS_DEVEPT_EPRST_Pos)          /* (USBHS_DEVEPT Mask) EPRST */
#define USBHS_DEVEPT_EPRST(value)             (USBHS_DEVEPT_EPRST_Msk & (_UINT32_(value) << USBHS_DEVEPT_EPRST_Pos)) 

/* -------- USBHS_DEVFNUM : (USBHS Offset: 0x20) ( R/ 32) Device Frame Number Register -------- */
#define USBHS_DEVFNUM_MFNUM_Pos               _UINT32_(0)                                          /* (USBHS_DEVFNUM) Micro Frame Number Position */
#define USBHS_DEVFNUM_MFNUM_Msk               (_UINT32_(0x7) << USBHS_DEVFNUM_MFNUM_Pos)           /* (USBHS_DEVFNUM) Micro Frame Number Mask */
#define USBHS_DEVFNUM_MFNUM(value)            (USBHS_DEVFNUM_MFNUM_Msk & (_UINT32_(value) << USBHS_DEVFNUM_MFNUM_Pos)) /* Assigment of value for MFNUM in the USBHS_DEVFNUM register */
#define USBHS_DEVFNUM_FNUM_Pos                _UINT32_(3)                                          /* (USBHS_DEVFNUM) Frame Number Position */
#define USBHS_DEVFNUM_FNUM_Msk                (_UINT32_(0x7FF) << USBHS_DEVFNUM_FNUM_Pos)          /* (USBHS_DEVFNUM) Frame Number Mask */
#define USBHS_DEVFNUM_FNUM(value)             (USBHS_DEVFNUM_FNUM_Msk & (_UINT32_(value) << USBHS_DEVFNUM_FNUM_Pos)) /* Assigment of value for FNUM in the USBHS_DEVFNUM register */
#define USBHS_DEVFNUM_FNCERR_Pos              _UINT32_(15)                                         /* (USBHS_DEVFNUM) Frame Number CRC Error Position */
#define USBHS_DEVFNUM_FNCERR_Msk              (_UINT32_(0x1) << USBHS_DEVFNUM_FNCERR_Pos)          /* (USBHS_DEVFNUM) Frame Number CRC Error Mask */
#define USBHS_DEVFNUM_FNCERR(value)           (USBHS_DEVFNUM_FNCERR_Msk & (_UINT32_(value) << USBHS_DEVFNUM_FNCERR_Pos)) /* Assigment of value for FNCERR in the USBHS_DEVFNUM register */
#define USBHS_DEVFNUM_Msk                     _UINT32_(0x0000BFFF)                                 /* (USBHS_DEVFNUM) Register Mask  */


/* -------- USBHS_DEVEPTCFG : (USBHS Offset: 0x100) (R/W 32) Device Endpoint Configuration Register -------- */
#define USBHS_DEVEPTCFG_ALLOC_Pos             _UINT32_(1)                                          /* (USBHS_DEVEPTCFG) Endpoint Memory Allocate Position */
#define USBHS_DEVEPTCFG_ALLOC_Msk             (_UINT32_(0x1) << USBHS_DEVEPTCFG_ALLOC_Pos)         /* (USBHS_DEVEPTCFG) Endpoint Memory Allocate Mask */
#define USBHS_DEVEPTCFG_ALLOC(value)          (USBHS_DEVEPTCFG_ALLOC_Msk & (_UINT32_(value) << USBHS_DEVEPTCFG_ALLOC_Pos)) /* Assigment of value for ALLOC in the USBHS_DEVEPTCFG register */
#define USBHS_DEVEPTCFG_EPBK_Pos              _UINT32_(2)                                          /* (USBHS_DEVEPTCFG) Endpoint Banks Position */
#define USBHS_DEVEPTCFG_EPBK_Msk              (_UINT32_(0x3) << USBHS_DEVEPTCFG_EPBK_Pos)          /* (USBHS_DEVEPTCFG) Endpoint Banks Mask */
#define USBHS_DEVEPTCFG_EPBK(value)           (USBHS_DEVEPTCFG_EPBK_Msk & (_UINT32_(value) << USBHS_DEVEPTCFG_EPBK_Pos)) /* Assigment of value for EPBK in the USBHS_DEVEPTCFG register */
#define   USBHS_DEVEPTCFG_EPBK_1_BANK_Val     _UINT32_(0x0)                                        /* (USBHS_DEVEPTCFG) Single-bank endpoint  */
#define   USBHS_DEVEPTCFG_EPBK_2_BANK_Val     _UINT32_(0x1)                                        /* (USBHS_DEVEPTCFG) Double-bank endpoint  */
#define   USBHS_DEVEPTCFG_EPBK_3_BANK_Val     _UINT32_(0x2)                                        /* (USBHS_DEVEPTCFG) Triple-bank endpoint  */
#define USBHS_DEVEPTCFG_EPBK_1_BANK           (USBHS_DEVEPTCFG_EPBK_1_BANK_Val << USBHS_DEVEPTCFG_EPBK_Pos) /* (USBHS_DEVEPTCFG) Single-bank endpoint Position  */
#define USBHS_DEVEPTCFG_EPBK_2_BANK           (USBHS_DEVEPTCFG_EPBK_2_BANK_Val << USBHS_DEVEPTCFG_EPBK_Pos) /* (USBHS_DEVEPTCFG) Double-bank endpoint Position  */
#define USBHS_DEVEPTCFG_EPBK_3_BANK           (USBHS_DEVEPTCFG_EPBK_3_BANK_Val << USBHS_DEVEPTCFG_EPBK_Pos) /* (USBHS_DEVEPTCFG) Triple-bank endpoint Position  */
#define USBHS_DEVEPTCFG_EPSIZE_Pos            _UINT32_(4)                                          /* (USBHS_DEVEPTCFG) Endpoint Size Position */
#define USBHS_DEVEPTCFG_EPSIZE_Msk            (_UINT32_(0x7) << USBHS_DEVEPTCFG_EPSIZE_Pos)        /* (USBHS_DEVEPTCFG) Endpoint Size Mask */
#define USBHS_DEVEPTCFG_EPSIZE(value)         (USBHS_DEVEPTCFG_EPSIZE_Msk & (_UINT32_(value) << USBHS_DEVEPTCFG_EPSIZE_Pos)) /* Assigment of value for EPSIZE in the USBHS_DEVEPTCFG register */
#define   USBHS_DEVEPTCFG_EPSIZE_8_BYTE_Val   _UINT32_(0x0)                                        /* (USBHS_DEVEPTCFG) 8 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_16_BYTE_Val  _UINT32_(0x1)                                        /* (USBHS_DEVEPTCFG) 16 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_32_BYTE_Val  _UINT32_(0x2)                                        /* (USBHS_DEVEPTCFG) 32 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_64_BYTE_Val  _UINT32_(0x3)                                        /* (USBHS_DEVEPTCFG) 64 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_128_BYTE_Val _UINT32_(0x4)                                        /* (USBHS_DEVEPTCFG) 128 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_256_BYTE_Val _UINT32_(0x5)                                        /* (USBHS_DEVEPTCFG) 256 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_512_BYTE_Val _UINT32_(0x6)                                        /* (USBHS_DEVEPTCFG) 512 bytes  */
#define   USBHS_DEVEPTCFG_EPSIZE_1024_BYTE_Val _UINT32_(0x7)                                        /* (USBHS_DEVEPTCFG) 1024 bytes  */
#define USBHS_DEVEPTCFG_EPSIZE_8_BYTE         (USBHS_DEVEPTCFG_EPSIZE_8_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos) /* (USBHS_DEVEPTCFG) 8 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_16_BYTE        (USBHS_DEVEPTCFG_EPSIZE_16_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos) /* (USBHS_DEVEPTCFG) 16 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_32_BYTE        (USBHS_DEVEPTCFG_EPSIZE_32_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos) /* (USBHS_DEVEPTCFG) 32 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_64_BYTE        (USBHS_DEVEPTCFG_EPSIZE_64_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos) /* (USBHS_DEVEPTCFG) 64 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_128_BYTE       (USBHS_DEVEPTCFG_EPSIZE_128_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos) /* (USBHS_DEVEPTCFG) 128 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_256_BYTE       (USBHS_DEVEPTCFG_EPSIZE_256_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos) /* (USBHS_DEVEPTCFG) 256 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_512_BYTE       (USBHS_DEVEPTCFG_EPSIZE_512_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos) /* (USBHS_DEVEPTCFG) 512 bytes Position  */
#define USBHS_DEVEPTCFG_EPSIZE_1024_BYTE      (USBHS_DEVEPTCFG_EPSIZE_1024_BYTE_Val << USBHS_DEVEPTCFG_EPSIZE_Pos) /* (USBHS_DEVEPTCFG) 1024 bytes Position  */
#define USBHS_DEVEPTCFG_EPDIR_Pos             _UINT32_(8)                                          /* (USBHS_DEVEPTCFG) Endpoint Direction Position */
#define USBHS_DEVEPTCFG_EPDIR_Msk             (_UINT32_(0x1) << USBHS_DEVEPTCFG_EPDIR_Pos)         /* (USBHS_DEVEPTCFG) Endpoint Direction Mask */
#define USBHS_DEVEPTCFG_EPDIR(value)          (USBHS_DEVEPTCFG_EPDIR_Msk & (_UINT32_(value) << USBHS_DEVEPTCFG_EPDIR_Pos)) /* Assigment of value for EPDIR in the USBHS_DEVEPTCFG register */
#define   USBHS_DEVEPTCFG_EPDIR_OUT_Val       _UINT32_(0x0)                                        /* (USBHS_DEVEPTCFG) The endpoint direction is OUT.  */
#define   USBHS_DEVEPTCFG_EPDIR_IN_Val        _UINT32_(0x1)                                        /* (USBHS_DEVEPTCFG) The endpoint direction is IN (nor for control endpoints).  */
#define USBHS_DEVEPTCFG_EPDIR_OUT             (USBHS_DEVEPTCFG_EPDIR_OUT_Val << USBHS_DEVEPTCFG_EPDIR_Pos) /* (USBHS_DEVEPTCFG) The endpoint direction is OUT. Position  */
#define USBHS_DEVEPTCFG_EPDIR_IN              (USBHS_DEVEPTCFG_EPDIR_IN_Val << USBHS_DEVEPTCFG_EPDIR_Pos) /* (USBHS_DEVEPTCFG) The endpoint direction is IN (nor for control endpoints). Position  */
#define USBHS_DEVEPTCFG_AUTOSW_Pos            _UINT32_(9)                                          /* (USBHS_DEVEPTCFG) Automatic Switch Position */
#define USBHS_DEVEPTCFG_AUTOSW_Msk            (_UINT32_(0x1) << USBHS_DEVEPTCFG_AUTOSW_Pos)        /* (USBHS_DEVEPTCFG) Automatic Switch Mask */
#define USBHS_DEVEPTCFG_AUTOSW(value)         (USBHS_DEVEPTCFG_AUTOSW_Msk & (_UINT32_(value) << USBHS_DEVEPTCFG_AUTOSW_Pos)) /* Assigment of value for AUTOSW in the USBHS_DEVEPTCFG register */
#define USBHS_DEVEPTCFG_EPTYPE_Pos            _UINT32_(11)                                         /* (USBHS_DEVEPTCFG) Endpoint Type Position */
#define USBHS_DEVEPTCFG_EPTYPE_Msk            (_UINT32_(0x3) << USBHS_DEVEPTCFG_EPTYPE_Pos)        /* (USBHS_DEVEPTCFG) Endpoint Type Mask */
#define USBHS_DEVEPTCFG_EPTYPE(value)         (USBHS_DEVEPTCFG_EPTYPE_Msk & (_UINT32_(value) << USBHS_DEVEPTCFG_EPTYPE_Pos)) /* Assigment of value for EPTYPE in the USBHS_DEVEPTCFG register */
#define   USBHS_DEVEPTCFG_EPTYPE_CTRL_Val     _UINT32_(0x0)                                        /* (USBHS_DEVEPTCFG) Control  */
#define   USBHS_DEVEPTCFG_EPTYPE_ISO_Val      _UINT32_(0x1)                                        /* (USBHS_DEVEPTCFG) Isochronous  */
#define   USBHS_DEVEPTCFG_EPTYPE_BLK_Val      _UINT32_(0x2)                                        /* (USBHS_DEVEPTCFG) Bulk  */
#define   USBHS_DEVEPTCFG_EPTYPE_INTRPT_Val   _UINT32_(0x3)                                        /* (USBHS_DEVEPTCFG) Interrupt  */
#define USBHS_DEVEPTCFG_EPTYPE_CTRL           (USBHS_DEVEPTCFG_EPTYPE_CTRL_Val << USBHS_DEVEPTCFG_EPTYPE_Pos) /* (USBHS_DEVEPTCFG) Control Position  */
#define USBHS_DEVEPTCFG_EPTYPE_ISO            (USBHS_DEVEPTCFG_EPTYPE_ISO_Val << USBHS_DEVEPTCFG_EPTYPE_Pos) /* (USBHS_DEVEPTCFG) Isochronous Position  */
#define USBHS_DEVEPTCFG_EPTYPE_BLK            (USBHS_DEVEPTCFG_EPTYPE_BLK_Val << USBHS_DEVEPTCFG_EPTYPE_Pos) /* (USBHS_DEVEPTCFG) Bulk Position  */
#define USBHS_DEVEPTCFG_EPTYPE_INTRPT         (USBHS_DEVEPTCFG_EPTYPE_INTRPT_Val << USBHS_DEVEPTCFG_EPTYPE_Pos) /* (USBHS_DEVEPTCFG) Interrupt Position  */
#define USBHS_DEVEPTCFG_NBTRANS_Pos           _UINT32_(13)                                         /* (USBHS_DEVEPTCFG) Number of transactions per microframe for isochronous endpoint Position */
#define USBHS_DEVEPTCFG_NBTRANS_Msk           (_UINT32_(0x3) << USBHS_DEVEPTCFG_NBTRANS_Pos)       /* (USBHS_DEVEPTCFG) Number of transactions per microframe for isochronous endpoint Mask */
#define USBHS_DEVEPTCFG_NBTRANS(value)        (USBHS_DEVEPTCFG_NBTRANS_Msk & (_UINT32_(value) << USBHS_DEVEPTCFG_NBTRANS_Pos)) /* Assigment of value for NBTRANS in the USBHS_DEVEPTCFG register */
#define   USBHS_DEVEPTCFG_NBTRANS_0_TRANS_Val _UINT32_(0x0)                                        /* (USBHS_DEVEPTCFG) Reserved to endpoint that does not have the high-bandwidth isochronous capability.  */
#define   USBHS_DEVEPTCFG_NBTRANS_1_TRANS_Val _UINT32_(0x1)                                        /* (USBHS_DEVEPTCFG) Default value: one transaction per microframe.  */
#define   USBHS_DEVEPTCFG_NBTRANS_2_TRANS_Val _UINT32_(0x2)                                        /* (USBHS_DEVEPTCFG) Two transactions per microframe. This endpoint should be configured as double-bank.  */
#define   USBHS_DEVEPTCFG_NBTRANS_3_TRANS_Val _UINT32_(0x3)                                        /* (USBHS_DEVEPTCFG) Three transactions per microframe. This endpoint should be configured as triple-bank.  */
#define USBHS_DEVEPTCFG_NBTRANS_0_TRANS       (USBHS_DEVEPTCFG_NBTRANS_0_TRANS_Val << USBHS_DEVEPTCFG_NBTRANS_Pos) /* (USBHS_DEVEPTCFG) Reserved to endpoint that does not have the high-bandwidth isochronous capability. Position  */
#define USBHS_DEVEPTCFG_NBTRANS_1_TRANS       (USBHS_DEVEPTCFG_NBTRANS_1_TRANS_Val << USBHS_DEVEPTCFG_NBTRANS_Pos) /* (USBHS_DEVEPTCFG) Default value: one transaction per microframe. Position  */
#define USBHS_DEVEPTCFG_NBTRANS_2_TRANS       (USBHS_DEVEPTCFG_NBTRANS_2_TRANS_Val << USBHS_DEVEPTCFG_NBTRANS_Pos) /* (USBHS_DEVEPTCFG) Two transactions per microframe. This endpoint should be configured as double-bank. Position  */
#define USBHS_DEVEPTCFG_NBTRANS_3_TRANS       (USBHS_DEVEPTCFG_NBTRANS_3_TRANS_Val << USBHS_DEVEPTCFG_NBTRANS_Pos) /* (USBHS_DEVEPTCFG) Three transactions per microframe. This endpoint should be configured as triple-bank. Position  */
#define USBHS_DEVEPTCFG_Msk                   _UINT32_(0x00007B7E)                                 /* (USBHS_DEVEPTCFG) Register Mask  */


/* -------- USBHS_DEVEPTISR : (USBHS Offset: 0x130) ( R/ 32) Device Endpoint Interrupt Status Register -------- */
#define USBHS_DEVEPTISR_TXINI_Pos             _UINT32_(0)                                          /* (USBHS_DEVEPTISR) Transmitted IN Data Interrupt Position */
#define USBHS_DEVEPTISR_TXINI_Msk             (_UINT32_(0x1) << USBHS_DEVEPTISR_TXINI_Pos)         /* (USBHS_DEVEPTISR) Transmitted IN Data Interrupt Mask */
#define USBHS_DEVEPTISR_TXINI(value)          (USBHS_DEVEPTISR_TXINI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_TXINI_Pos)) /* Assigment of value for TXINI in the USBHS_DEVEPTISR register */
#define USBHS_DEVEPTISR_RXOUTI_Pos            _UINT32_(1)                                          /* (USBHS_DEVEPTISR) Received OUT Data Interrupt Position */
#define USBHS_DEVEPTISR_RXOUTI_Msk            (_UINT32_(0x1) << USBHS_DEVEPTISR_RXOUTI_Pos)        /* (USBHS_DEVEPTISR) Received OUT Data Interrupt Mask */
#define USBHS_DEVEPTISR_RXOUTI(value)         (USBHS_DEVEPTISR_RXOUTI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_RXOUTI_Pos)) /* Assigment of value for RXOUTI in the USBHS_DEVEPTISR register */
#define USBHS_DEVEPTISR_OVERFI_Pos            _UINT32_(5)                                          /* (USBHS_DEVEPTISR) Overflow Interrupt Position */
#define USBHS_DEVEPTISR_OVERFI_Msk            (_UINT32_(0x1) << USBHS_DEVEPTISR_OVERFI_Pos)        /* (USBHS_DEVEPTISR) Overflow Interrupt Mask */
#define USBHS_DEVEPTISR_OVERFI(value)         (USBHS_DEVEPTISR_OVERFI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_OVERFI_Pos)) /* Assigment of value for OVERFI in the USBHS_DEVEPTISR register */
#define USBHS_DEVEPTISR_SHORTPACKET_Pos       _UINT32_(7)                                          /* (USBHS_DEVEPTISR) Short Packet Interrupt Position */
#define USBHS_DEVEPTISR_SHORTPACKET_Msk       (_UINT32_(0x1) << USBHS_DEVEPTISR_SHORTPACKET_Pos)   /* (USBHS_DEVEPTISR) Short Packet Interrupt Mask */
#define USBHS_DEVEPTISR_SHORTPACKET(value)    (USBHS_DEVEPTISR_SHORTPACKET_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_SHORTPACKET_Pos)) /* Assigment of value for SHORTPACKET in the USBHS_DEVEPTISR register */
#define USBHS_DEVEPTISR_DTSEQ_Pos             _UINT32_(8)                                          /* (USBHS_DEVEPTISR) Data Toggle Sequence Position */
#define USBHS_DEVEPTISR_DTSEQ_Msk             (_UINT32_(0x3) << USBHS_DEVEPTISR_DTSEQ_Pos)         /* (USBHS_DEVEPTISR) Data Toggle Sequence Mask */
#define USBHS_DEVEPTISR_DTSEQ(value)          (USBHS_DEVEPTISR_DTSEQ_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_DTSEQ_Pos)) /* Assigment of value for DTSEQ in the USBHS_DEVEPTISR register */
#define   USBHS_DEVEPTISR_DTSEQ_DATA0_Val     _UINT32_(0x0)                                        /* (USBHS_DEVEPTISR) Data0 toggle sequence  */
#define   USBHS_DEVEPTISR_DTSEQ_DATA1_Val     _UINT32_(0x1)                                        /* (USBHS_DEVEPTISR) Data1 toggle sequence  */
#define   USBHS_DEVEPTISR_DTSEQ_DATA2_Val     _UINT32_(0x2)                                        /* (USBHS_DEVEPTISR) Reserved for high-bandwidth isochronous endpoint  */
#define   USBHS_DEVEPTISR_DTSEQ_MDATA_Val     _UINT32_(0x3)                                        /* (USBHS_DEVEPTISR) Reserved for high-bandwidth isochronous endpoint  */
#define USBHS_DEVEPTISR_DTSEQ_DATA0           (USBHS_DEVEPTISR_DTSEQ_DATA0_Val << USBHS_DEVEPTISR_DTSEQ_Pos) /* (USBHS_DEVEPTISR) Data0 toggle sequence Position  */
#define USBHS_DEVEPTISR_DTSEQ_DATA1           (USBHS_DEVEPTISR_DTSEQ_DATA1_Val << USBHS_DEVEPTISR_DTSEQ_Pos) /* (USBHS_DEVEPTISR) Data1 toggle sequence Position  */
#define USBHS_DEVEPTISR_DTSEQ_DATA2           (USBHS_DEVEPTISR_DTSEQ_DATA2_Val << USBHS_DEVEPTISR_DTSEQ_Pos) /* (USBHS_DEVEPTISR) Reserved for high-bandwidth isochronous endpoint Position  */
#define USBHS_DEVEPTISR_DTSEQ_MDATA           (USBHS_DEVEPTISR_DTSEQ_MDATA_Val << USBHS_DEVEPTISR_DTSEQ_Pos) /* (USBHS_DEVEPTISR) Reserved for high-bandwidth isochronous endpoint Position  */
#define USBHS_DEVEPTISR_NBUSYBK_Pos           _UINT32_(12)                                         /* (USBHS_DEVEPTISR) Number of Busy Banks Position */
#define USBHS_DEVEPTISR_NBUSYBK_Msk           (_UINT32_(0x3) << USBHS_DEVEPTISR_NBUSYBK_Pos)       /* (USBHS_DEVEPTISR) Number of Busy Banks Mask */
#define USBHS_DEVEPTISR_NBUSYBK(value)        (USBHS_DEVEPTISR_NBUSYBK_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_NBUSYBK_Pos)) /* Assigment of value for NBUSYBK in the USBHS_DEVEPTISR register */
#define   USBHS_DEVEPTISR_NBUSYBK_0_BUSY_Val  _UINT32_(0x0)                                        /* (USBHS_DEVEPTISR) 0 busy bank (all banks free)  */
#define   USBHS_DEVEPTISR_NBUSYBK_1_BUSY_Val  _UINT32_(0x1)                                        /* (USBHS_DEVEPTISR) 1 busy bank  */
#define   USBHS_DEVEPTISR_NBUSYBK_2_BUSY_Val  _UINT32_(0x2)                                        /* (USBHS_DEVEPTISR) 2 busy banks  */
#define   USBHS_DEVEPTISR_NBUSYBK_3_BUSY_Val  _UINT32_(0x3)                                        /* (USBHS_DEVEPTISR) 3 busy banks  */
#define USBHS_DEVEPTISR_NBUSYBK_0_BUSY        (USBHS_DEVEPTISR_NBUSYBK_0_BUSY_Val << USBHS_DEVEPTISR_NBUSYBK_Pos) /* (USBHS_DEVEPTISR) 0 busy bank (all banks free) Position  */
#define USBHS_DEVEPTISR_NBUSYBK_1_BUSY        (USBHS_DEVEPTISR_NBUSYBK_1_BUSY_Val << USBHS_DEVEPTISR_NBUSYBK_Pos) /* (USBHS_DEVEPTISR) 1 busy bank Position  */
#define USBHS_DEVEPTISR_NBUSYBK_2_BUSY        (USBHS_DEVEPTISR_NBUSYBK_2_BUSY_Val << USBHS_DEVEPTISR_NBUSYBK_Pos) /* (USBHS_DEVEPTISR) 2 busy banks Position  */
#define USBHS_DEVEPTISR_NBUSYBK_3_BUSY        (USBHS_DEVEPTISR_NBUSYBK_3_BUSY_Val << USBHS_DEVEPTISR_NBUSYBK_Pos) /* (USBHS_DEVEPTISR) 3 busy banks Position  */
#define USBHS_DEVEPTISR_CURRBK_Pos            _UINT32_(14)                                         /* (USBHS_DEVEPTISR) Current Bank Position */
#define USBHS_DEVEPTISR_CURRBK_Msk            (_UINT32_(0x3) << USBHS_DEVEPTISR_CURRBK_Pos)        /* (USBHS_DEVEPTISR) Current Bank Mask */
#define USBHS_DEVEPTISR_CURRBK(value)         (USBHS_DEVEPTISR_CURRBK_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_CURRBK_Pos)) /* Assigment of value for CURRBK in the USBHS_DEVEPTISR register */
#define   USBHS_DEVEPTISR_CURRBK_BANK0_Val    _UINT32_(0x0)                                        /* (USBHS_DEVEPTISR) Current bank is bank0  */
#define   USBHS_DEVEPTISR_CURRBK_BANK1_Val    _UINT32_(0x1)                                        /* (USBHS_DEVEPTISR) Current bank is bank1  */
#define   USBHS_DEVEPTISR_CURRBK_BANK2_Val    _UINT32_(0x2)                                        /* (USBHS_DEVEPTISR) Current bank is bank2  */
#define USBHS_DEVEPTISR_CURRBK_BANK0          (USBHS_DEVEPTISR_CURRBK_BANK0_Val << USBHS_DEVEPTISR_CURRBK_Pos) /* (USBHS_DEVEPTISR) Current bank is bank0 Position  */
#define USBHS_DEVEPTISR_CURRBK_BANK1          (USBHS_DEVEPTISR_CURRBK_BANK1_Val << USBHS_DEVEPTISR_CURRBK_Pos) /* (USBHS_DEVEPTISR) Current bank is bank1 Position  */
#define USBHS_DEVEPTISR_CURRBK_BANK2          (USBHS_DEVEPTISR_CURRBK_BANK2_Val << USBHS_DEVEPTISR_CURRBK_Pos) /* (USBHS_DEVEPTISR) Current bank is bank2 Position  */
#define USBHS_DEVEPTISR_RWALL_Pos             _UINT32_(16)                                         /* (USBHS_DEVEPTISR) Read/Write Allowed Position */
#define USBHS_DEVEPTISR_RWALL_Msk             (_UINT32_(0x1) << USBHS_DEVEPTISR_RWALL_Pos)         /* (USBHS_DEVEPTISR) Read/Write Allowed Mask */
#define USBHS_DEVEPTISR_RWALL(value)          (USBHS_DEVEPTISR_RWALL_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_RWALL_Pos)) /* Assigment of value for RWALL in the USBHS_DEVEPTISR register */
#define USBHS_DEVEPTISR_CFGOK_Pos             _UINT32_(18)                                         /* (USBHS_DEVEPTISR) Configuration OK Status Position */
#define USBHS_DEVEPTISR_CFGOK_Msk             (_UINT32_(0x1) << USBHS_DEVEPTISR_CFGOK_Pos)         /* (USBHS_DEVEPTISR) Configuration OK Status Mask */
#define USBHS_DEVEPTISR_CFGOK(value)          (USBHS_DEVEPTISR_CFGOK_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_CFGOK_Pos)) /* Assigment of value for CFGOK in the USBHS_DEVEPTISR register */
#define USBHS_DEVEPTISR_BYCT_Pos              _UINT32_(20)                                         /* (USBHS_DEVEPTISR) Byte Count Position */
#define USBHS_DEVEPTISR_BYCT_Msk              (_UINT32_(0x7FF) << USBHS_DEVEPTISR_BYCT_Pos)        /* (USBHS_DEVEPTISR) Byte Count Mask */
#define USBHS_DEVEPTISR_BYCT(value)           (USBHS_DEVEPTISR_BYCT_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_BYCT_Pos)) /* Assigment of value for BYCT in the USBHS_DEVEPTISR register */
#define USBHS_DEVEPTISR_Msk                   _UINT32_(0x7FF5F3A3)                                 /* (USBHS_DEVEPTISR) Register Mask  */

/* CTRL mode */
#define USBHS_DEVEPTISR_CTRL_RXSTPI_Pos       _UINT32_(2)                                          /* (USBHS_DEVEPTISR) Received SETUP Interrupt Position */
#define USBHS_DEVEPTISR_CTRL_RXSTPI_Msk       (_UINT32_(0x1) << USBHS_DEVEPTISR_CTRL_RXSTPI_Pos)   /* (USBHS_DEVEPTISR) Received SETUP Interrupt Mask */
#define USBHS_DEVEPTISR_CTRL_RXSTPI(value)    (USBHS_DEVEPTISR_CTRL_RXSTPI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_CTRL_RXSTPI_Pos))
#define USBHS_DEVEPTISR_CTRL_NAKOUTI_Pos      _UINT32_(3)                                          /* (USBHS_DEVEPTISR) NAKed OUT Interrupt Position */
#define USBHS_DEVEPTISR_CTRL_NAKOUTI_Msk      (_UINT32_(0x1) << USBHS_DEVEPTISR_CTRL_NAKOUTI_Pos)  /* (USBHS_DEVEPTISR) NAKed OUT Interrupt Mask */
#define USBHS_DEVEPTISR_CTRL_NAKOUTI(value)   (USBHS_DEVEPTISR_CTRL_NAKOUTI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_CTRL_NAKOUTI_Pos))
#define USBHS_DEVEPTISR_CTRL_NAKINI_Pos       _UINT32_(4)                                          /* (USBHS_DEVEPTISR) NAKed IN Interrupt Position */
#define USBHS_DEVEPTISR_CTRL_NAKINI_Msk       (_UINT32_(0x1) << USBHS_DEVEPTISR_CTRL_NAKINI_Pos)   /* (USBHS_DEVEPTISR) NAKed IN Interrupt Mask */
#define USBHS_DEVEPTISR_CTRL_NAKINI(value)    (USBHS_DEVEPTISR_CTRL_NAKINI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_CTRL_NAKINI_Pos))
#define USBHS_DEVEPTISR_CTRL_STALLEDI_Pos     _UINT32_(6)                                          /* (USBHS_DEVEPTISR) STALLed Interrupt Position */
#define USBHS_DEVEPTISR_CTRL_STALLEDI_Msk     (_UINT32_(0x1) << USBHS_DEVEPTISR_CTRL_STALLEDI_Pos) /* (USBHS_DEVEPTISR) STALLed Interrupt Mask */
#define USBHS_DEVEPTISR_CTRL_STALLEDI(value)  (USBHS_DEVEPTISR_CTRL_STALLEDI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_CTRL_STALLEDI_Pos))
#define USBHS_DEVEPTISR_CTRL_CTRLDIR_Pos      _UINT32_(17)                                         /* (USBHS_DEVEPTISR) Control Direction Position */
#define USBHS_DEVEPTISR_CTRL_CTRLDIR_Msk      (_UINT32_(0x1) << USBHS_DEVEPTISR_CTRL_CTRLDIR_Pos)  /* (USBHS_DEVEPTISR) Control Direction Mask */
#define USBHS_DEVEPTISR_CTRL_CTRLDIR(value)   (USBHS_DEVEPTISR_CTRL_CTRLDIR_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_CTRL_CTRLDIR_Pos))
#define USBHS_DEVEPTISR_CTRL_Msk              _UINT32_(0x0002005C)                                  /* (USBHS_DEVEPTISR_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_DEVEPTISR_ISO_UNDERFI_Pos       _UINT32_(2)                                          /* (USBHS_DEVEPTISR) Underflow Interrupt Position */
#define USBHS_DEVEPTISR_ISO_UNDERFI_Msk       (_UINT32_(0x1) << USBHS_DEVEPTISR_ISO_UNDERFI_Pos)   /* (USBHS_DEVEPTISR) Underflow Interrupt Mask */
#define USBHS_DEVEPTISR_ISO_UNDERFI(value)    (USBHS_DEVEPTISR_ISO_UNDERFI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_ISO_UNDERFI_Pos))
#define USBHS_DEVEPTISR_ISO_HBISOINERRI_Pos   _UINT32_(3)                                          /* (USBHS_DEVEPTISR) High Bandwidth Isochronous IN Underflow Error Interrupt Position */
#define USBHS_DEVEPTISR_ISO_HBISOINERRI_Msk   (_UINT32_(0x1) << USBHS_DEVEPTISR_ISO_HBISOINERRI_Pos) /* (USBHS_DEVEPTISR) High Bandwidth Isochronous IN Underflow Error Interrupt Mask */
#define USBHS_DEVEPTISR_ISO_HBISOINERRI(value) (USBHS_DEVEPTISR_ISO_HBISOINERRI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_ISO_HBISOINERRI_Pos))
#define USBHS_DEVEPTISR_ISO_HBISOFLUSHI_Pos   _UINT32_(4)                                          /* (USBHS_DEVEPTISR) High Bandwidth Isochronous IN Flush Interrupt Position */
#define USBHS_DEVEPTISR_ISO_HBISOFLUSHI_Msk   (_UINT32_(0x1) << USBHS_DEVEPTISR_ISO_HBISOFLUSHI_Pos) /* (USBHS_DEVEPTISR) High Bandwidth Isochronous IN Flush Interrupt Mask */
#define USBHS_DEVEPTISR_ISO_HBISOFLUSHI(value) (USBHS_DEVEPTISR_ISO_HBISOFLUSHI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_ISO_HBISOFLUSHI_Pos))
#define USBHS_DEVEPTISR_ISO_CRCERRI_Pos       _UINT32_(6)                                          /* (USBHS_DEVEPTISR) CRC Error Interrupt Position */
#define USBHS_DEVEPTISR_ISO_CRCERRI_Msk       (_UINT32_(0x1) << USBHS_DEVEPTISR_ISO_CRCERRI_Pos)   /* (USBHS_DEVEPTISR) CRC Error Interrupt Mask */
#define USBHS_DEVEPTISR_ISO_CRCERRI(value)    (USBHS_DEVEPTISR_ISO_CRCERRI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_ISO_CRCERRI_Pos))
#define USBHS_DEVEPTISR_ISO_ERRORTRANS_Pos    _UINT32_(10)                                         /* (USBHS_DEVEPTISR) High-bandwidth Isochronous OUT Endpoint Transaction Error Interrupt Position */
#define USBHS_DEVEPTISR_ISO_ERRORTRANS_Msk    (_UINT32_(0x1) << USBHS_DEVEPTISR_ISO_ERRORTRANS_Pos) /* (USBHS_DEVEPTISR) High-bandwidth Isochronous OUT Endpoint Transaction Error Interrupt Mask */
#define USBHS_DEVEPTISR_ISO_ERRORTRANS(value) (USBHS_DEVEPTISR_ISO_ERRORTRANS_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_ISO_ERRORTRANS_Pos))
#define USBHS_DEVEPTISR_ISO_Msk               _UINT32_(0x0000045C)                                  /* (USBHS_DEVEPTISR_ISO) Register Mask  */

/* BLK mode */
#define USBHS_DEVEPTISR_BLK_RXSTPI_Pos        _UINT32_(2)                                          /* (USBHS_DEVEPTISR) Received SETUP Interrupt Position */
#define USBHS_DEVEPTISR_BLK_RXSTPI_Msk        (_UINT32_(0x1) << USBHS_DEVEPTISR_BLK_RXSTPI_Pos)    /* (USBHS_DEVEPTISR) Received SETUP Interrupt Mask */
#define USBHS_DEVEPTISR_BLK_RXSTPI(value)     (USBHS_DEVEPTISR_BLK_RXSTPI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_BLK_RXSTPI_Pos))
#define USBHS_DEVEPTISR_BLK_NAKOUTI_Pos       _UINT32_(3)                                          /* (USBHS_DEVEPTISR) NAKed OUT Interrupt Position */
#define USBHS_DEVEPTISR_BLK_NAKOUTI_Msk       (_UINT32_(0x1) << USBHS_DEVEPTISR_BLK_NAKOUTI_Pos)   /* (USBHS_DEVEPTISR) NAKed OUT Interrupt Mask */
#define USBHS_DEVEPTISR_BLK_NAKOUTI(value)    (USBHS_DEVEPTISR_BLK_NAKOUTI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_BLK_NAKOUTI_Pos))
#define USBHS_DEVEPTISR_BLK_NAKINI_Pos        _UINT32_(4)                                          /* (USBHS_DEVEPTISR) NAKed IN Interrupt Position */
#define USBHS_DEVEPTISR_BLK_NAKINI_Msk        (_UINT32_(0x1) << USBHS_DEVEPTISR_BLK_NAKINI_Pos)    /* (USBHS_DEVEPTISR) NAKed IN Interrupt Mask */
#define USBHS_DEVEPTISR_BLK_NAKINI(value)     (USBHS_DEVEPTISR_BLK_NAKINI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_BLK_NAKINI_Pos))
#define USBHS_DEVEPTISR_BLK_STALLEDI_Pos      _UINT32_(6)                                          /* (USBHS_DEVEPTISR) STALLed Interrupt Position */
#define USBHS_DEVEPTISR_BLK_STALLEDI_Msk      (_UINT32_(0x1) << USBHS_DEVEPTISR_BLK_STALLEDI_Pos)  /* (USBHS_DEVEPTISR) STALLed Interrupt Mask */
#define USBHS_DEVEPTISR_BLK_STALLEDI(value)   (USBHS_DEVEPTISR_BLK_STALLEDI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_BLK_STALLEDI_Pos))
#define USBHS_DEVEPTISR_BLK_CTRLDIR_Pos       _UINT32_(17)                                         /* (USBHS_DEVEPTISR) Control Direction Position */
#define USBHS_DEVEPTISR_BLK_CTRLDIR_Msk       (_UINT32_(0x1) << USBHS_DEVEPTISR_BLK_CTRLDIR_Pos)   /* (USBHS_DEVEPTISR) Control Direction Mask */
#define USBHS_DEVEPTISR_BLK_CTRLDIR(value)    (USBHS_DEVEPTISR_BLK_CTRLDIR_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_BLK_CTRLDIR_Pos))
#define USBHS_DEVEPTISR_BLK_Msk               _UINT32_(0x0002005C)                                  /* (USBHS_DEVEPTISR_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_DEVEPTISR_INTRPT_RXSTPI_Pos     _UINT32_(2)                                          /* (USBHS_DEVEPTISR) Received SETUP Interrupt Position */
#define USBHS_DEVEPTISR_INTRPT_RXSTPI_Msk     (_UINT32_(0x1) << USBHS_DEVEPTISR_INTRPT_RXSTPI_Pos) /* (USBHS_DEVEPTISR) Received SETUP Interrupt Mask */
#define USBHS_DEVEPTISR_INTRPT_RXSTPI(value)  (USBHS_DEVEPTISR_INTRPT_RXSTPI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_INTRPT_RXSTPI_Pos))
#define USBHS_DEVEPTISR_INTRPT_NAKOUTI_Pos    _UINT32_(3)                                          /* (USBHS_DEVEPTISR) NAKed OUT Interrupt Position */
#define USBHS_DEVEPTISR_INTRPT_NAKOUTI_Msk    (_UINT32_(0x1) << USBHS_DEVEPTISR_INTRPT_NAKOUTI_Pos) /* (USBHS_DEVEPTISR) NAKed OUT Interrupt Mask */
#define USBHS_DEVEPTISR_INTRPT_NAKOUTI(value) (USBHS_DEVEPTISR_INTRPT_NAKOUTI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_INTRPT_NAKOUTI_Pos))
#define USBHS_DEVEPTISR_INTRPT_NAKINI_Pos     _UINT32_(4)                                          /* (USBHS_DEVEPTISR) NAKed IN Interrupt Position */
#define USBHS_DEVEPTISR_INTRPT_NAKINI_Msk     (_UINT32_(0x1) << USBHS_DEVEPTISR_INTRPT_NAKINI_Pos) /* (USBHS_DEVEPTISR) NAKed IN Interrupt Mask */
#define USBHS_DEVEPTISR_INTRPT_NAKINI(value)  (USBHS_DEVEPTISR_INTRPT_NAKINI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_INTRPT_NAKINI_Pos))
#define USBHS_DEVEPTISR_INTRPT_STALLEDI_Pos   _UINT32_(6)                                          /* (USBHS_DEVEPTISR) STALLed Interrupt Position */
#define USBHS_DEVEPTISR_INTRPT_STALLEDI_Msk   (_UINT32_(0x1) << USBHS_DEVEPTISR_INTRPT_STALLEDI_Pos) /* (USBHS_DEVEPTISR) STALLed Interrupt Mask */
#define USBHS_DEVEPTISR_INTRPT_STALLEDI(value) (USBHS_DEVEPTISR_INTRPT_STALLEDI_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_INTRPT_STALLEDI_Pos))
#define USBHS_DEVEPTISR_INTRPT_CTRLDIR_Pos    _UINT32_(17)                                         /* (USBHS_DEVEPTISR) Control Direction Position */
#define USBHS_DEVEPTISR_INTRPT_CTRLDIR_Msk    (_UINT32_(0x1) << USBHS_DEVEPTISR_INTRPT_CTRLDIR_Pos) /* (USBHS_DEVEPTISR) Control Direction Mask */
#define USBHS_DEVEPTISR_INTRPT_CTRLDIR(value) (USBHS_DEVEPTISR_INTRPT_CTRLDIR_Msk & (_UINT32_(value) << USBHS_DEVEPTISR_INTRPT_CTRLDIR_Pos))
#define USBHS_DEVEPTISR_INTRPT_Msk            _UINT32_(0x0002005C)                                  /* (USBHS_DEVEPTISR_INTRPT) Register Mask  */


/* -------- USBHS_DEVEPTICR : (USBHS Offset: 0x160) ( /W 32) Device Endpoint Interrupt Clear Register -------- */
#define USBHS_DEVEPTICR_TXINIC_Pos            _UINT32_(0)                                          /* (USBHS_DEVEPTICR) Transmitted IN Data Interrupt Clear Position */
#define USBHS_DEVEPTICR_TXINIC_Msk            (_UINT32_(0x1) << USBHS_DEVEPTICR_TXINIC_Pos)        /* (USBHS_DEVEPTICR) Transmitted IN Data Interrupt Clear Mask */
#define USBHS_DEVEPTICR_TXINIC(value)         (USBHS_DEVEPTICR_TXINIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_TXINIC_Pos)) /* Assigment of value for TXINIC in the USBHS_DEVEPTICR register */
#define USBHS_DEVEPTICR_RXOUTIC_Pos           _UINT32_(1)                                          /* (USBHS_DEVEPTICR) Received OUT Data Interrupt Clear Position */
#define USBHS_DEVEPTICR_RXOUTIC_Msk           (_UINT32_(0x1) << USBHS_DEVEPTICR_RXOUTIC_Pos)       /* (USBHS_DEVEPTICR) Received OUT Data Interrupt Clear Mask */
#define USBHS_DEVEPTICR_RXOUTIC(value)        (USBHS_DEVEPTICR_RXOUTIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_RXOUTIC_Pos)) /* Assigment of value for RXOUTIC in the USBHS_DEVEPTICR register */
#define USBHS_DEVEPTICR_OVERFIC_Pos           _UINT32_(5)                                          /* (USBHS_DEVEPTICR) Overflow Interrupt Clear Position */
#define USBHS_DEVEPTICR_OVERFIC_Msk           (_UINT32_(0x1) << USBHS_DEVEPTICR_OVERFIC_Pos)       /* (USBHS_DEVEPTICR) Overflow Interrupt Clear Mask */
#define USBHS_DEVEPTICR_OVERFIC(value)        (USBHS_DEVEPTICR_OVERFIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_OVERFIC_Pos)) /* Assigment of value for OVERFIC in the USBHS_DEVEPTICR register */
#define USBHS_DEVEPTICR_SHORTPACKETC_Pos      _UINT32_(7)                                          /* (USBHS_DEVEPTICR) Short Packet Interrupt Clear Position */
#define USBHS_DEVEPTICR_SHORTPACKETC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTICR_SHORTPACKETC_Pos)  /* (USBHS_DEVEPTICR) Short Packet Interrupt Clear Mask */
#define USBHS_DEVEPTICR_SHORTPACKETC(value)   (USBHS_DEVEPTICR_SHORTPACKETC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_SHORTPACKETC_Pos)) /* Assigment of value for SHORTPACKETC in the USBHS_DEVEPTICR register */
#define USBHS_DEVEPTICR_Msk                   _UINT32_(0x000000A3)                                 /* (USBHS_DEVEPTICR) Register Mask  */

/* CTRL mode */
#define USBHS_DEVEPTICR_CTRL_RXSTPIC_Pos      _UINT32_(2)                                          /* (USBHS_DEVEPTICR) Received SETUP Interrupt Clear Position */
#define USBHS_DEVEPTICR_CTRL_RXSTPIC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTICR_CTRL_RXSTPIC_Pos)  /* (USBHS_DEVEPTICR) Received SETUP Interrupt Clear Mask */
#define USBHS_DEVEPTICR_CTRL_RXSTPIC(value)   (USBHS_DEVEPTICR_CTRL_RXSTPIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_CTRL_RXSTPIC_Pos))
#define USBHS_DEVEPTICR_CTRL_NAKOUTIC_Pos     _UINT32_(3)                                          /* (USBHS_DEVEPTICR) NAKed OUT Interrupt Clear Position */
#define USBHS_DEVEPTICR_CTRL_NAKOUTIC_Msk     (_UINT32_(0x1) << USBHS_DEVEPTICR_CTRL_NAKOUTIC_Pos) /* (USBHS_DEVEPTICR) NAKed OUT Interrupt Clear Mask */
#define USBHS_DEVEPTICR_CTRL_NAKOUTIC(value)  (USBHS_DEVEPTICR_CTRL_NAKOUTIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_CTRL_NAKOUTIC_Pos))
#define USBHS_DEVEPTICR_CTRL_NAKINIC_Pos      _UINT32_(4)                                          /* (USBHS_DEVEPTICR) NAKed IN Interrupt Clear Position */
#define USBHS_DEVEPTICR_CTRL_NAKINIC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTICR_CTRL_NAKINIC_Pos)  /* (USBHS_DEVEPTICR) NAKed IN Interrupt Clear Mask */
#define USBHS_DEVEPTICR_CTRL_NAKINIC(value)   (USBHS_DEVEPTICR_CTRL_NAKINIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_CTRL_NAKINIC_Pos))
#define USBHS_DEVEPTICR_CTRL_STALLEDIC_Pos    _UINT32_(6)                                          /* (USBHS_DEVEPTICR) STALLed Interrupt Clear Position */
#define USBHS_DEVEPTICR_CTRL_STALLEDIC_Msk    (_UINT32_(0x1) << USBHS_DEVEPTICR_CTRL_STALLEDIC_Pos) /* (USBHS_DEVEPTICR) STALLed Interrupt Clear Mask */
#define USBHS_DEVEPTICR_CTRL_STALLEDIC(value) (USBHS_DEVEPTICR_CTRL_STALLEDIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_CTRL_STALLEDIC_Pos))
#define USBHS_DEVEPTICR_CTRL_Msk              _UINT32_(0x0000005C)                                  /* (USBHS_DEVEPTICR_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_DEVEPTICR_ISO_UNDERFIC_Pos      _UINT32_(2)                                          /* (USBHS_DEVEPTICR) Underflow Interrupt Clear Position */
#define USBHS_DEVEPTICR_ISO_UNDERFIC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTICR_ISO_UNDERFIC_Pos)  /* (USBHS_DEVEPTICR) Underflow Interrupt Clear Mask */
#define USBHS_DEVEPTICR_ISO_UNDERFIC(value)   (USBHS_DEVEPTICR_ISO_UNDERFIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_ISO_UNDERFIC_Pos))
#define USBHS_DEVEPTICR_ISO_HBISOINERRIC_Pos  _UINT32_(3)                                          /* (USBHS_DEVEPTICR) High Bandwidth Isochronous IN Underflow Error Interrupt Clear Position */
#define USBHS_DEVEPTICR_ISO_HBISOINERRIC_Msk  (_UINT32_(0x1) << USBHS_DEVEPTICR_ISO_HBISOINERRIC_Pos) /* (USBHS_DEVEPTICR) High Bandwidth Isochronous IN Underflow Error Interrupt Clear Mask */
#define USBHS_DEVEPTICR_ISO_HBISOINERRIC(value) (USBHS_DEVEPTICR_ISO_HBISOINERRIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_ISO_HBISOINERRIC_Pos))
#define USBHS_DEVEPTICR_ISO_HBISOFLUSHIC_Pos  _UINT32_(4)                                          /* (USBHS_DEVEPTICR) High Bandwidth Isochronous IN Flush Interrupt Clear Position */
#define USBHS_DEVEPTICR_ISO_HBISOFLUSHIC_Msk  (_UINT32_(0x1) << USBHS_DEVEPTICR_ISO_HBISOFLUSHIC_Pos) /* (USBHS_DEVEPTICR) High Bandwidth Isochronous IN Flush Interrupt Clear Mask */
#define USBHS_DEVEPTICR_ISO_HBISOFLUSHIC(value) (USBHS_DEVEPTICR_ISO_HBISOFLUSHIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_ISO_HBISOFLUSHIC_Pos))
#define USBHS_DEVEPTICR_ISO_CRCERRIC_Pos      _UINT32_(6)                                          /* (USBHS_DEVEPTICR) CRC Error Interrupt Clear Position */
#define USBHS_DEVEPTICR_ISO_CRCERRIC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTICR_ISO_CRCERRIC_Pos)  /* (USBHS_DEVEPTICR) CRC Error Interrupt Clear Mask */
#define USBHS_DEVEPTICR_ISO_CRCERRIC(value)   (USBHS_DEVEPTICR_ISO_CRCERRIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_ISO_CRCERRIC_Pos))
#define USBHS_DEVEPTICR_ISO_Msk               _UINT32_(0x0000005C)                                  /* (USBHS_DEVEPTICR_ISO) Register Mask  */

/* BLK mode */
#define USBHS_DEVEPTICR_BLK_RXSTPIC_Pos       _UINT32_(2)                                          /* (USBHS_DEVEPTICR) Received SETUP Interrupt Clear Position */
#define USBHS_DEVEPTICR_BLK_RXSTPIC_Msk       (_UINT32_(0x1) << USBHS_DEVEPTICR_BLK_RXSTPIC_Pos)   /* (USBHS_DEVEPTICR) Received SETUP Interrupt Clear Mask */
#define USBHS_DEVEPTICR_BLK_RXSTPIC(value)    (USBHS_DEVEPTICR_BLK_RXSTPIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_BLK_RXSTPIC_Pos))
#define USBHS_DEVEPTICR_BLK_NAKOUTIC_Pos      _UINT32_(3)                                          /* (USBHS_DEVEPTICR) NAKed OUT Interrupt Clear Position */
#define USBHS_DEVEPTICR_BLK_NAKOUTIC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTICR_BLK_NAKOUTIC_Pos)  /* (USBHS_DEVEPTICR) NAKed OUT Interrupt Clear Mask */
#define USBHS_DEVEPTICR_BLK_NAKOUTIC(value)   (USBHS_DEVEPTICR_BLK_NAKOUTIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_BLK_NAKOUTIC_Pos))
#define USBHS_DEVEPTICR_BLK_NAKINIC_Pos       _UINT32_(4)                                          /* (USBHS_DEVEPTICR) NAKed IN Interrupt Clear Position */
#define USBHS_DEVEPTICR_BLK_NAKINIC_Msk       (_UINT32_(0x1) << USBHS_DEVEPTICR_BLK_NAKINIC_Pos)   /* (USBHS_DEVEPTICR) NAKed IN Interrupt Clear Mask */
#define USBHS_DEVEPTICR_BLK_NAKINIC(value)    (USBHS_DEVEPTICR_BLK_NAKINIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_BLK_NAKINIC_Pos))
#define USBHS_DEVEPTICR_BLK_STALLEDIC_Pos     _UINT32_(6)                                          /* (USBHS_DEVEPTICR) STALLed Interrupt Clear Position */
#define USBHS_DEVEPTICR_BLK_STALLEDIC_Msk     (_UINT32_(0x1) << USBHS_DEVEPTICR_BLK_STALLEDIC_Pos) /* (USBHS_DEVEPTICR) STALLed Interrupt Clear Mask */
#define USBHS_DEVEPTICR_BLK_STALLEDIC(value)  (USBHS_DEVEPTICR_BLK_STALLEDIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_BLK_STALLEDIC_Pos))
#define USBHS_DEVEPTICR_BLK_Msk               _UINT32_(0x0000005C)                                  /* (USBHS_DEVEPTICR_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_DEVEPTICR_INTRPT_RXSTPIC_Pos    _UINT32_(2)                                          /* (USBHS_DEVEPTICR) Received SETUP Interrupt Clear Position */
#define USBHS_DEVEPTICR_INTRPT_RXSTPIC_Msk    (_UINT32_(0x1) << USBHS_DEVEPTICR_INTRPT_RXSTPIC_Pos) /* (USBHS_DEVEPTICR) Received SETUP Interrupt Clear Mask */
#define USBHS_DEVEPTICR_INTRPT_RXSTPIC(value) (USBHS_DEVEPTICR_INTRPT_RXSTPIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_INTRPT_RXSTPIC_Pos))
#define USBHS_DEVEPTICR_INTRPT_NAKOUTIC_Pos   _UINT32_(3)                                          /* (USBHS_DEVEPTICR) NAKed OUT Interrupt Clear Position */
#define USBHS_DEVEPTICR_INTRPT_NAKOUTIC_Msk   (_UINT32_(0x1) << USBHS_DEVEPTICR_INTRPT_NAKOUTIC_Pos) /* (USBHS_DEVEPTICR) NAKed OUT Interrupt Clear Mask */
#define USBHS_DEVEPTICR_INTRPT_NAKOUTIC(value) (USBHS_DEVEPTICR_INTRPT_NAKOUTIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_INTRPT_NAKOUTIC_Pos))
#define USBHS_DEVEPTICR_INTRPT_NAKINIC_Pos    _UINT32_(4)                                          /* (USBHS_DEVEPTICR) NAKed IN Interrupt Clear Position */
#define USBHS_DEVEPTICR_INTRPT_NAKINIC_Msk    (_UINT32_(0x1) << USBHS_DEVEPTICR_INTRPT_NAKINIC_Pos) /* (USBHS_DEVEPTICR) NAKed IN Interrupt Clear Mask */
#define USBHS_DEVEPTICR_INTRPT_NAKINIC(value) (USBHS_DEVEPTICR_INTRPT_NAKINIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_INTRPT_NAKINIC_Pos))
#define USBHS_DEVEPTICR_INTRPT_STALLEDIC_Pos  _UINT32_(6)                                          /* (USBHS_DEVEPTICR) STALLed Interrupt Clear Position */
#define USBHS_DEVEPTICR_INTRPT_STALLEDIC_Msk  (_UINT32_(0x1) << USBHS_DEVEPTICR_INTRPT_STALLEDIC_Pos) /* (USBHS_DEVEPTICR) STALLed Interrupt Clear Mask */
#define USBHS_DEVEPTICR_INTRPT_STALLEDIC(value) (USBHS_DEVEPTICR_INTRPT_STALLEDIC_Msk & (_UINT32_(value) << USBHS_DEVEPTICR_INTRPT_STALLEDIC_Pos))
#define USBHS_DEVEPTICR_INTRPT_Msk            _UINT32_(0x0000005C)                                  /* (USBHS_DEVEPTICR_INTRPT) Register Mask  */


/* -------- USBHS_DEVEPTIFR : (USBHS Offset: 0x190) ( /W 32) Device Endpoint Interrupt Set Register -------- */
#define USBHS_DEVEPTIFR_TXINIS_Pos            _UINT32_(0)                                          /* (USBHS_DEVEPTIFR) Transmitted IN Data Interrupt Set Position */
#define USBHS_DEVEPTIFR_TXINIS_Msk            (_UINT32_(0x1) << USBHS_DEVEPTIFR_TXINIS_Pos)        /* (USBHS_DEVEPTIFR) Transmitted IN Data Interrupt Set Mask */
#define USBHS_DEVEPTIFR_TXINIS(value)         (USBHS_DEVEPTIFR_TXINIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_TXINIS_Pos)) /* Assigment of value for TXINIS in the USBHS_DEVEPTIFR register */
#define USBHS_DEVEPTIFR_RXOUTIS_Pos           _UINT32_(1)                                          /* (USBHS_DEVEPTIFR) Received OUT Data Interrupt Set Position */
#define USBHS_DEVEPTIFR_RXOUTIS_Msk           (_UINT32_(0x1) << USBHS_DEVEPTIFR_RXOUTIS_Pos)       /* (USBHS_DEVEPTIFR) Received OUT Data Interrupt Set Mask */
#define USBHS_DEVEPTIFR_RXOUTIS(value)        (USBHS_DEVEPTIFR_RXOUTIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_RXOUTIS_Pos)) /* Assigment of value for RXOUTIS in the USBHS_DEVEPTIFR register */
#define USBHS_DEVEPTIFR_OVERFIS_Pos           _UINT32_(5)                                          /* (USBHS_DEVEPTIFR) Overflow Interrupt Set Position */
#define USBHS_DEVEPTIFR_OVERFIS_Msk           (_UINT32_(0x1) << USBHS_DEVEPTIFR_OVERFIS_Pos)       /* (USBHS_DEVEPTIFR) Overflow Interrupt Set Mask */
#define USBHS_DEVEPTIFR_OVERFIS(value)        (USBHS_DEVEPTIFR_OVERFIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_OVERFIS_Pos)) /* Assigment of value for OVERFIS in the USBHS_DEVEPTIFR register */
#define USBHS_DEVEPTIFR_SHORTPACKETS_Pos      _UINT32_(7)                                          /* (USBHS_DEVEPTIFR) Short Packet Interrupt Set Position */
#define USBHS_DEVEPTIFR_SHORTPACKETS_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIFR_SHORTPACKETS_Pos)  /* (USBHS_DEVEPTIFR) Short Packet Interrupt Set Mask */
#define USBHS_DEVEPTIFR_SHORTPACKETS(value)   (USBHS_DEVEPTIFR_SHORTPACKETS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_SHORTPACKETS_Pos)) /* Assigment of value for SHORTPACKETS in the USBHS_DEVEPTIFR register */
#define USBHS_DEVEPTIFR_NBUSYBKS_Pos          _UINT32_(12)                                         /* (USBHS_DEVEPTIFR) Number of Busy Banks Interrupt Set Position */
#define USBHS_DEVEPTIFR_NBUSYBKS_Msk          (_UINT32_(0x1) << USBHS_DEVEPTIFR_NBUSYBKS_Pos)      /* (USBHS_DEVEPTIFR) Number of Busy Banks Interrupt Set Mask */
#define USBHS_DEVEPTIFR_NBUSYBKS(value)       (USBHS_DEVEPTIFR_NBUSYBKS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_NBUSYBKS_Pos)) /* Assigment of value for NBUSYBKS in the USBHS_DEVEPTIFR register */
#define USBHS_DEVEPTIFR_Msk                   _UINT32_(0x000010A3)                                 /* (USBHS_DEVEPTIFR) Register Mask  */

/* CTRL mode */
#define USBHS_DEVEPTIFR_CTRL_RXSTPIS_Pos      _UINT32_(2)                                          /* (USBHS_DEVEPTIFR) Received SETUP Interrupt Set Position */
#define USBHS_DEVEPTIFR_CTRL_RXSTPIS_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIFR_CTRL_RXSTPIS_Pos)  /* (USBHS_DEVEPTIFR) Received SETUP Interrupt Set Mask */
#define USBHS_DEVEPTIFR_CTRL_RXSTPIS(value)   (USBHS_DEVEPTIFR_CTRL_RXSTPIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_CTRL_RXSTPIS_Pos))
#define USBHS_DEVEPTIFR_CTRL_NAKOUTIS_Pos     _UINT32_(3)                                          /* (USBHS_DEVEPTIFR) NAKed OUT Interrupt Set Position */
#define USBHS_DEVEPTIFR_CTRL_NAKOUTIS_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIFR_CTRL_NAKOUTIS_Pos) /* (USBHS_DEVEPTIFR) NAKed OUT Interrupt Set Mask */
#define USBHS_DEVEPTIFR_CTRL_NAKOUTIS(value)  (USBHS_DEVEPTIFR_CTRL_NAKOUTIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_CTRL_NAKOUTIS_Pos))
#define USBHS_DEVEPTIFR_CTRL_NAKINIS_Pos      _UINT32_(4)                                          /* (USBHS_DEVEPTIFR) NAKed IN Interrupt Set Position */
#define USBHS_DEVEPTIFR_CTRL_NAKINIS_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIFR_CTRL_NAKINIS_Pos)  /* (USBHS_DEVEPTIFR) NAKed IN Interrupt Set Mask */
#define USBHS_DEVEPTIFR_CTRL_NAKINIS(value)   (USBHS_DEVEPTIFR_CTRL_NAKINIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_CTRL_NAKINIS_Pos))
#define USBHS_DEVEPTIFR_CTRL_STALLEDIS_Pos    _UINT32_(6)                                          /* (USBHS_DEVEPTIFR) STALLed Interrupt Set Position */
#define USBHS_DEVEPTIFR_CTRL_STALLEDIS_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIFR_CTRL_STALLEDIS_Pos) /* (USBHS_DEVEPTIFR) STALLed Interrupt Set Mask */
#define USBHS_DEVEPTIFR_CTRL_STALLEDIS(value) (USBHS_DEVEPTIFR_CTRL_STALLEDIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_CTRL_STALLEDIS_Pos))
#define USBHS_DEVEPTIFR_CTRL_Msk              _UINT32_(0x0000005C)                                  /* (USBHS_DEVEPTIFR_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_DEVEPTIFR_ISO_UNDERFIS_Pos      _UINT32_(2)                                          /* (USBHS_DEVEPTIFR) Underflow Interrupt Set Position */
#define USBHS_DEVEPTIFR_ISO_UNDERFIS_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIFR_ISO_UNDERFIS_Pos)  /* (USBHS_DEVEPTIFR) Underflow Interrupt Set Mask */
#define USBHS_DEVEPTIFR_ISO_UNDERFIS(value)   (USBHS_DEVEPTIFR_ISO_UNDERFIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_ISO_UNDERFIS_Pos))
#define USBHS_DEVEPTIFR_ISO_HBISOINERRIS_Pos  _UINT32_(3)                                          /* (USBHS_DEVEPTIFR) High Bandwidth Isochronous IN Underflow Error Interrupt Set Position */
#define USBHS_DEVEPTIFR_ISO_HBISOINERRIS_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIFR_ISO_HBISOINERRIS_Pos) /* (USBHS_DEVEPTIFR) High Bandwidth Isochronous IN Underflow Error Interrupt Set Mask */
#define USBHS_DEVEPTIFR_ISO_HBISOINERRIS(value) (USBHS_DEVEPTIFR_ISO_HBISOINERRIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_ISO_HBISOINERRIS_Pos))
#define USBHS_DEVEPTIFR_ISO_HBISOFLUSHIS_Pos  _UINT32_(4)                                          /* (USBHS_DEVEPTIFR) High Bandwidth Isochronous IN Flush Interrupt Set Position */
#define USBHS_DEVEPTIFR_ISO_HBISOFLUSHIS_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIFR_ISO_HBISOFLUSHIS_Pos) /* (USBHS_DEVEPTIFR) High Bandwidth Isochronous IN Flush Interrupt Set Mask */
#define USBHS_DEVEPTIFR_ISO_HBISOFLUSHIS(value) (USBHS_DEVEPTIFR_ISO_HBISOFLUSHIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_ISO_HBISOFLUSHIS_Pos))
#define USBHS_DEVEPTIFR_ISO_CRCERRIS_Pos      _UINT32_(6)                                          /* (USBHS_DEVEPTIFR) CRC Error Interrupt Set Position */
#define USBHS_DEVEPTIFR_ISO_CRCERRIS_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIFR_ISO_CRCERRIS_Pos)  /* (USBHS_DEVEPTIFR) CRC Error Interrupt Set Mask */
#define USBHS_DEVEPTIFR_ISO_CRCERRIS(value)   (USBHS_DEVEPTIFR_ISO_CRCERRIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_ISO_CRCERRIS_Pos))
#define USBHS_DEVEPTIFR_ISO_Msk               _UINT32_(0x0000005C)                                  /* (USBHS_DEVEPTIFR_ISO) Register Mask  */

/* BLK mode */
#define USBHS_DEVEPTIFR_BLK_RXSTPIS_Pos       _UINT32_(2)                                          /* (USBHS_DEVEPTIFR) Received SETUP Interrupt Set Position */
#define USBHS_DEVEPTIFR_BLK_RXSTPIS_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIFR_BLK_RXSTPIS_Pos)   /* (USBHS_DEVEPTIFR) Received SETUP Interrupt Set Mask */
#define USBHS_DEVEPTIFR_BLK_RXSTPIS(value)    (USBHS_DEVEPTIFR_BLK_RXSTPIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_BLK_RXSTPIS_Pos))
#define USBHS_DEVEPTIFR_BLK_NAKOUTIS_Pos      _UINT32_(3)                                          /* (USBHS_DEVEPTIFR) NAKed OUT Interrupt Set Position */
#define USBHS_DEVEPTIFR_BLK_NAKOUTIS_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIFR_BLK_NAKOUTIS_Pos)  /* (USBHS_DEVEPTIFR) NAKed OUT Interrupt Set Mask */
#define USBHS_DEVEPTIFR_BLK_NAKOUTIS(value)   (USBHS_DEVEPTIFR_BLK_NAKOUTIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_BLK_NAKOUTIS_Pos))
#define USBHS_DEVEPTIFR_BLK_NAKINIS_Pos       _UINT32_(4)                                          /* (USBHS_DEVEPTIFR) NAKed IN Interrupt Set Position */
#define USBHS_DEVEPTIFR_BLK_NAKINIS_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIFR_BLK_NAKINIS_Pos)   /* (USBHS_DEVEPTIFR) NAKed IN Interrupt Set Mask */
#define USBHS_DEVEPTIFR_BLK_NAKINIS(value)    (USBHS_DEVEPTIFR_BLK_NAKINIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_BLK_NAKINIS_Pos))
#define USBHS_DEVEPTIFR_BLK_STALLEDIS_Pos     _UINT32_(6)                                          /* (USBHS_DEVEPTIFR) STALLed Interrupt Set Position */
#define USBHS_DEVEPTIFR_BLK_STALLEDIS_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIFR_BLK_STALLEDIS_Pos) /* (USBHS_DEVEPTIFR) STALLed Interrupt Set Mask */
#define USBHS_DEVEPTIFR_BLK_STALLEDIS(value)  (USBHS_DEVEPTIFR_BLK_STALLEDIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_BLK_STALLEDIS_Pos))
#define USBHS_DEVEPTIFR_BLK_Msk               _UINT32_(0x0000005C)                                  /* (USBHS_DEVEPTIFR_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_DEVEPTIFR_INTRPT_RXSTPIS_Pos    _UINT32_(2)                                          /* (USBHS_DEVEPTIFR) Received SETUP Interrupt Set Position */
#define USBHS_DEVEPTIFR_INTRPT_RXSTPIS_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIFR_INTRPT_RXSTPIS_Pos) /* (USBHS_DEVEPTIFR) Received SETUP Interrupt Set Mask */
#define USBHS_DEVEPTIFR_INTRPT_RXSTPIS(value) (USBHS_DEVEPTIFR_INTRPT_RXSTPIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_INTRPT_RXSTPIS_Pos))
#define USBHS_DEVEPTIFR_INTRPT_NAKOUTIS_Pos   _UINT32_(3)                                          /* (USBHS_DEVEPTIFR) NAKed OUT Interrupt Set Position */
#define USBHS_DEVEPTIFR_INTRPT_NAKOUTIS_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIFR_INTRPT_NAKOUTIS_Pos) /* (USBHS_DEVEPTIFR) NAKed OUT Interrupt Set Mask */
#define USBHS_DEVEPTIFR_INTRPT_NAKOUTIS(value) (USBHS_DEVEPTIFR_INTRPT_NAKOUTIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_INTRPT_NAKOUTIS_Pos))
#define USBHS_DEVEPTIFR_INTRPT_NAKINIS_Pos    _UINT32_(4)                                          /* (USBHS_DEVEPTIFR) NAKed IN Interrupt Set Position */
#define USBHS_DEVEPTIFR_INTRPT_NAKINIS_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIFR_INTRPT_NAKINIS_Pos) /* (USBHS_DEVEPTIFR) NAKed IN Interrupt Set Mask */
#define USBHS_DEVEPTIFR_INTRPT_NAKINIS(value) (USBHS_DEVEPTIFR_INTRPT_NAKINIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_INTRPT_NAKINIS_Pos))
#define USBHS_DEVEPTIFR_INTRPT_STALLEDIS_Pos  _UINT32_(6)                                          /* (USBHS_DEVEPTIFR) STALLed Interrupt Set Position */
#define USBHS_DEVEPTIFR_INTRPT_STALLEDIS_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIFR_INTRPT_STALLEDIS_Pos) /* (USBHS_DEVEPTIFR) STALLed Interrupt Set Mask */
#define USBHS_DEVEPTIFR_INTRPT_STALLEDIS(value) (USBHS_DEVEPTIFR_INTRPT_STALLEDIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIFR_INTRPT_STALLEDIS_Pos))
#define USBHS_DEVEPTIFR_INTRPT_Msk            _UINT32_(0x0000005C)                                  /* (USBHS_DEVEPTIFR_INTRPT) Register Mask  */


/* -------- USBHS_DEVEPTIMR : (USBHS Offset: 0x1C0) ( R/ 32) Device Endpoint Interrupt Mask Register -------- */
#define USBHS_DEVEPTIMR_TXINE_Pos             _UINT32_(0)                                          /* (USBHS_DEVEPTIMR) Transmitted IN Data Interrupt Position */
#define USBHS_DEVEPTIMR_TXINE_Msk             (_UINT32_(0x1) << USBHS_DEVEPTIMR_TXINE_Pos)         /* (USBHS_DEVEPTIMR) Transmitted IN Data Interrupt Mask */
#define USBHS_DEVEPTIMR_TXINE(value)          (USBHS_DEVEPTIMR_TXINE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_TXINE_Pos)) /* Assigment of value for TXINE in the USBHS_DEVEPTIMR register */
#define USBHS_DEVEPTIMR_RXOUTE_Pos            _UINT32_(1)                                          /* (USBHS_DEVEPTIMR) Received OUT Data Interrupt Position */
#define USBHS_DEVEPTIMR_RXOUTE_Msk            (_UINT32_(0x1) << USBHS_DEVEPTIMR_RXOUTE_Pos)        /* (USBHS_DEVEPTIMR) Received OUT Data Interrupt Mask */
#define USBHS_DEVEPTIMR_RXOUTE(value)         (USBHS_DEVEPTIMR_RXOUTE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_RXOUTE_Pos)) /* Assigment of value for RXOUTE in the USBHS_DEVEPTIMR register */
#define USBHS_DEVEPTIMR_OVERFE_Pos            _UINT32_(5)                                          /* (USBHS_DEVEPTIMR) Overflow Interrupt Position */
#define USBHS_DEVEPTIMR_OVERFE_Msk            (_UINT32_(0x1) << USBHS_DEVEPTIMR_OVERFE_Pos)        /* (USBHS_DEVEPTIMR) Overflow Interrupt Mask */
#define USBHS_DEVEPTIMR_OVERFE(value)         (USBHS_DEVEPTIMR_OVERFE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_OVERFE_Pos)) /* Assigment of value for OVERFE in the USBHS_DEVEPTIMR register */
#define USBHS_DEVEPTIMR_SHORTPACKETE_Pos      _UINT32_(7)                                          /* (USBHS_DEVEPTIMR) Short Packet Interrupt Position */
#define USBHS_DEVEPTIMR_SHORTPACKETE_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIMR_SHORTPACKETE_Pos)  /* (USBHS_DEVEPTIMR) Short Packet Interrupt Mask */
#define USBHS_DEVEPTIMR_SHORTPACKETE(value)   (USBHS_DEVEPTIMR_SHORTPACKETE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_SHORTPACKETE_Pos)) /* Assigment of value for SHORTPACKETE in the USBHS_DEVEPTIMR register */
#define USBHS_DEVEPTIMR_NBUSYBKE_Pos          _UINT32_(12)                                         /* (USBHS_DEVEPTIMR) Number of Busy Banks Interrupt Position */
#define USBHS_DEVEPTIMR_NBUSYBKE_Msk          (_UINT32_(0x1) << USBHS_DEVEPTIMR_NBUSYBKE_Pos)      /* (USBHS_DEVEPTIMR) Number of Busy Banks Interrupt Mask */
#define USBHS_DEVEPTIMR_NBUSYBKE(value)       (USBHS_DEVEPTIMR_NBUSYBKE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_NBUSYBKE_Pos)) /* Assigment of value for NBUSYBKE in the USBHS_DEVEPTIMR register */
#define USBHS_DEVEPTIMR_KILLBK_Pos            _UINT32_(13)                                         /* (USBHS_DEVEPTIMR) Kill IN Bank Position */
#define USBHS_DEVEPTIMR_KILLBK_Msk            (_UINT32_(0x1) << USBHS_DEVEPTIMR_KILLBK_Pos)        /* (USBHS_DEVEPTIMR) Kill IN Bank Mask */
#define USBHS_DEVEPTIMR_KILLBK(value)         (USBHS_DEVEPTIMR_KILLBK_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_KILLBK_Pos)) /* Assigment of value for KILLBK in the USBHS_DEVEPTIMR register */
#define USBHS_DEVEPTIMR_FIFOCON_Pos           _UINT32_(14)                                         /* (USBHS_DEVEPTIMR) FIFO Control Position */
#define USBHS_DEVEPTIMR_FIFOCON_Msk           (_UINT32_(0x1) << USBHS_DEVEPTIMR_FIFOCON_Pos)       /* (USBHS_DEVEPTIMR) FIFO Control Mask */
#define USBHS_DEVEPTIMR_FIFOCON(value)        (USBHS_DEVEPTIMR_FIFOCON_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_FIFOCON_Pos)) /* Assigment of value for FIFOCON in the USBHS_DEVEPTIMR register */
#define USBHS_DEVEPTIMR_EPDISHDMA_Pos         _UINT32_(16)                                         /* (USBHS_DEVEPTIMR) Endpoint Interrupts Disable HDMA Request Position */
#define USBHS_DEVEPTIMR_EPDISHDMA_Msk         (_UINT32_(0x1) << USBHS_DEVEPTIMR_EPDISHDMA_Pos)     /* (USBHS_DEVEPTIMR) Endpoint Interrupts Disable HDMA Request Mask */
#define USBHS_DEVEPTIMR_EPDISHDMA(value)      (USBHS_DEVEPTIMR_EPDISHDMA_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_EPDISHDMA_Pos)) /* Assigment of value for EPDISHDMA in the USBHS_DEVEPTIMR register */
#define USBHS_DEVEPTIMR_RSTDT_Pos             _UINT32_(18)                                         /* (USBHS_DEVEPTIMR) Reset Data Toggle Position */
#define USBHS_DEVEPTIMR_RSTDT_Msk             (_UINT32_(0x1) << USBHS_DEVEPTIMR_RSTDT_Pos)         /* (USBHS_DEVEPTIMR) Reset Data Toggle Mask */
#define USBHS_DEVEPTIMR_RSTDT(value)          (USBHS_DEVEPTIMR_RSTDT_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_RSTDT_Pos)) /* Assigment of value for RSTDT in the USBHS_DEVEPTIMR register */
#define USBHS_DEVEPTIMR_Msk                   _UINT32_(0x000570A3)                                 /* (USBHS_DEVEPTIMR) Register Mask  */

/* CTRL mode */
#define USBHS_DEVEPTIMR_CTRL_RXSTPE_Pos       _UINT32_(2)                                          /* (USBHS_DEVEPTIMR) Received SETUP Interrupt Position */
#define USBHS_DEVEPTIMR_CTRL_RXSTPE_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIMR_CTRL_RXSTPE_Pos)   /* (USBHS_DEVEPTIMR) Received SETUP Interrupt Mask */
#define USBHS_DEVEPTIMR_CTRL_RXSTPE(value)    (USBHS_DEVEPTIMR_CTRL_RXSTPE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_CTRL_RXSTPE_Pos))
#define USBHS_DEVEPTIMR_CTRL_NAKOUTE_Pos      _UINT32_(3)                                          /* (USBHS_DEVEPTIMR) NAKed OUT Interrupt Position */
#define USBHS_DEVEPTIMR_CTRL_NAKOUTE_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIMR_CTRL_NAKOUTE_Pos)  /* (USBHS_DEVEPTIMR) NAKed OUT Interrupt Mask */
#define USBHS_DEVEPTIMR_CTRL_NAKOUTE(value)   (USBHS_DEVEPTIMR_CTRL_NAKOUTE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_CTRL_NAKOUTE_Pos))
#define USBHS_DEVEPTIMR_CTRL_NAKINE_Pos       _UINT32_(4)                                          /* (USBHS_DEVEPTIMR) NAKed IN Interrupt Position */
#define USBHS_DEVEPTIMR_CTRL_NAKINE_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIMR_CTRL_NAKINE_Pos)   /* (USBHS_DEVEPTIMR) NAKed IN Interrupt Mask */
#define USBHS_DEVEPTIMR_CTRL_NAKINE(value)    (USBHS_DEVEPTIMR_CTRL_NAKINE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_CTRL_NAKINE_Pos))
#define USBHS_DEVEPTIMR_CTRL_STALLEDE_Pos     _UINT32_(6)                                          /* (USBHS_DEVEPTIMR) STALLed Interrupt Position */
#define USBHS_DEVEPTIMR_CTRL_STALLEDE_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIMR_CTRL_STALLEDE_Pos) /* (USBHS_DEVEPTIMR) STALLed Interrupt Mask */
#define USBHS_DEVEPTIMR_CTRL_STALLEDE(value)  (USBHS_DEVEPTIMR_CTRL_STALLEDE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_CTRL_STALLEDE_Pos))
#define USBHS_DEVEPTIMR_CTRL_NYETDIS_Pos      _UINT32_(17)                                         /* (USBHS_DEVEPTIMR) NYET Token Disable Position */
#define USBHS_DEVEPTIMR_CTRL_NYETDIS_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIMR_CTRL_NYETDIS_Pos)  /* (USBHS_DEVEPTIMR) NYET Token Disable Mask */
#define USBHS_DEVEPTIMR_CTRL_NYETDIS(value)   (USBHS_DEVEPTIMR_CTRL_NYETDIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_CTRL_NYETDIS_Pos))
#define USBHS_DEVEPTIMR_CTRL_STALLRQ_Pos      _UINT32_(19)                                         /* (USBHS_DEVEPTIMR) STALL Request Position */
#define USBHS_DEVEPTIMR_CTRL_STALLRQ_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIMR_CTRL_STALLRQ_Pos)  /* (USBHS_DEVEPTIMR) STALL Request Mask */
#define USBHS_DEVEPTIMR_CTRL_STALLRQ(value)   (USBHS_DEVEPTIMR_CTRL_STALLRQ_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_CTRL_STALLRQ_Pos))
#define USBHS_DEVEPTIMR_CTRL_Msk              _UINT32_(0x000A005C)                                  /* (USBHS_DEVEPTIMR_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_DEVEPTIMR_ISO_UNDERFE_Pos       _UINT32_(2)                                          /* (USBHS_DEVEPTIMR) Underflow Interrupt Position */
#define USBHS_DEVEPTIMR_ISO_UNDERFE_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIMR_ISO_UNDERFE_Pos)   /* (USBHS_DEVEPTIMR) Underflow Interrupt Mask */
#define USBHS_DEVEPTIMR_ISO_UNDERFE(value)    (USBHS_DEVEPTIMR_ISO_UNDERFE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_ISO_UNDERFE_Pos))
#define USBHS_DEVEPTIMR_ISO_HBISOINERRE_Pos   _UINT32_(3)                                          /* (USBHS_DEVEPTIMR) High Bandwidth Isochronous IN Underflow Error Interrupt Position */
#define USBHS_DEVEPTIMR_ISO_HBISOINERRE_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIMR_ISO_HBISOINERRE_Pos) /* (USBHS_DEVEPTIMR) High Bandwidth Isochronous IN Underflow Error Interrupt Mask */
#define USBHS_DEVEPTIMR_ISO_HBISOINERRE(value) (USBHS_DEVEPTIMR_ISO_HBISOINERRE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_ISO_HBISOINERRE_Pos))
#define USBHS_DEVEPTIMR_ISO_HBISOFLUSHE_Pos   _UINT32_(4)                                          /* (USBHS_DEVEPTIMR) High Bandwidth Isochronous IN Flush Interrupt Position */
#define USBHS_DEVEPTIMR_ISO_HBISOFLUSHE_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIMR_ISO_HBISOFLUSHE_Pos) /* (USBHS_DEVEPTIMR) High Bandwidth Isochronous IN Flush Interrupt Mask */
#define USBHS_DEVEPTIMR_ISO_HBISOFLUSHE(value) (USBHS_DEVEPTIMR_ISO_HBISOFLUSHE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_ISO_HBISOFLUSHE_Pos))
#define USBHS_DEVEPTIMR_ISO_CRCERRE_Pos       _UINT32_(6)                                          /* (USBHS_DEVEPTIMR) CRC Error Interrupt Position */
#define USBHS_DEVEPTIMR_ISO_CRCERRE_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIMR_ISO_CRCERRE_Pos)   /* (USBHS_DEVEPTIMR) CRC Error Interrupt Mask */
#define USBHS_DEVEPTIMR_ISO_CRCERRE(value)    (USBHS_DEVEPTIMR_ISO_CRCERRE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_ISO_CRCERRE_Pos))
#define USBHS_DEVEPTIMR_ISO_MDATAE_Pos        _UINT32_(8)                                          /* (USBHS_DEVEPTIMR) MData Interrupt Position */
#define USBHS_DEVEPTIMR_ISO_MDATAE_Msk        (_UINT32_(0x1) << USBHS_DEVEPTIMR_ISO_MDATAE_Pos)    /* (USBHS_DEVEPTIMR) MData Interrupt Mask */
#define USBHS_DEVEPTIMR_ISO_MDATAE(value)     (USBHS_DEVEPTIMR_ISO_MDATAE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_ISO_MDATAE_Pos))
#define USBHS_DEVEPTIMR_ISO_DATAXE_Pos        _UINT32_(9)                                          /* (USBHS_DEVEPTIMR) DataX Interrupt Position */
#define USBHS_DEVEPTIMR_ISO_DATAXE_Msk        (_UINT32_(0x1) << USBHS_DEVEPTIMR_ISO_DATAXE_Pos)    /* (USBHS_DEVEPTIMR) DataX Interrupt Mask */
#define USBHS_DEVEPTIMR_ISO_DATAXE(value)     (USBHS_DEVEPTIMR_ISO_DATAXE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_ISO_DATAXE_Pos))
#define USBHS_DEVEPTIMR_ISO_ERRORTRANSE_Pos   _UINT32_(10)                                         /* (USBHS_DEVEPTIMR) Transaction Error Interrupt Position */
#define USBHS_DEVEPTIMR_ISO_ERRORTRANSE_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIMR_ISO_ERRORTRANSE_Pos) /* (USBHS_DEVEPTIMR) Transaction Error Interrupt Mask */
#define USBHS_DEVEPTIMR_ISO_ERRORTRANSE(value) (USBHS_DEVEPTIMR_ISO_ERRORTRANSE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_ISO_ERRORTRANSE_Pos))
#define USBHS_DEVEPTIMR_ISO_Msk               _UINT32_(0x0000075C)                                  /* (USBHS_DEVEPTIMR_ISO) Register Mask  */

/* BLK mode */
#define USBHS_DEVEPTIMR_BLK_RXSTPE_Pos        _UINT32_(2)                                          /* (USBHS_DEVEPTIMR) Received SETUP Interrupt Position */
#define USBHS_DEVEPTIMR_BLK_RXSTPE_Msk        (_UINT32_(0x1) << USBHS_DEVEPTIMR_BLK_RXSTPE_Pos)    /* (USBHS_DEVEPTIMR) Received SETUP Interrupt Mask */
#define USBHS_DEVEPTIMR_BLK_RXSTPE(value)     (USBHS_DEVEPTIMR_BLK_RXSTPE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_BLK_RXSTPE_Pos))
#define USBHS_DEVEPTIMR_BLK_NAKOUTE_Pos       _UINT32_(3)                                          /* (USBHS_DEVEPTIMR) NAKed OUT Interrupt Position */
#define USBHS_DEVEPTIMR_BLK_NAKOUTE_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIMR_BLK_NAKOUTE_Pos)   /* (USBHS_DEVEPTIMR) NAKed OUT Interrupt Mask */
#define USBHS_DEVEPTIMR_BLK_NAKOUTE(value)    (USBHS_DEVEPTIMR_BLK_NAKOUTE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_BLK_NAKOUTE_Pos))
#define USBHS_DEVEPTIMR_BLK_NAKINE_Pos        _UINT32_(4)                                          /* (USBHS_DEVEPTIMR) NAKed IN Interrupt Position */
#define USBHS_DEVEPTIMR_BLK_NAKINE_Msk        (_UINT32_(0x1) << USBHS_DEVEPTIMR_BLK_NAKINE_Pos)    /* (USBHS_DEVEPTIMR) NAKed IN Interrupt Mask */
#define USBHS_DEVEPTIMR_BLK_NAKINE(value)     (USBHS_DEVEPTIMR_BLK_NAKINE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_BLK_NAKINE_Pos))
#define USBHS_DEVEPTIMR_BLK_STALLEDE_Pos      _UINT32_(6)                                          /* (USBHS_DEVEPTIMR) STALLed Interrupt Position */
#define USBHS_DEVEPTIMR_BLK_STALLEDE_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIMR_BLK_STALLEDE_Pos)  /* (USBHS_DEVEPTIMR) STALLed Interrupt Mask */
#define USBHS_DEVEPTIMR_BLK_STALLEDE(value)   (USBHS_DEVEPTIMR_BLK_STALLEDE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_BLK_STALLEDE_Pos))
#define USBHS_DEVEPTIMR_BLK_NYETDIS_Pos       _UINT32_(17)                                         /* (USBHS_DEVEPTIMR) NYET Token Disable Position */
#define USBHS_DEVEPTIMR_BLK_NYETDIS_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIMR_BLK_NYETDIS_Pos)   /* (USBHS_DEVEPTIMR) NYET Token Disable Mask */
#define USBHS_DEVEPTIMR_BLK_NYETDIS(value)    (USBHS_DEVEPTIMR_BLK_NYETDIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_BLK_NYETDIS_Pos))
#define USBHS_DEVEPTIMR_BLK_STALLRQ_Pos       _UINT32_(19)                                         /* (USBHS_DEVEPTIMR) STALL Request Position */
#define USBHS_DEVEPTIMR_BLK_STALLRQ_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIMR_BLK_STALLRQ_Pos)   /* (USBHS_DEVEPTIMR) STALL Request Mask */
#define USBHS_DEVEPTIMR_BLK_STALLRQ(value)    (USBHS_DEVEPTIMR_BLK_STALLRQ_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_BLK_STALLRQ_Pos))
#define USBHS_DEVEPTIMR_BLK_Msk               _UINT32_(0x000A005C)                                  /* (USBHS_DEVEPTIMR_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_DEVEPTIMR_INTRPT_RXSTPE_Pos     _UINT32_(2)                                          /* (USBHS_DEVEPTIMR) Received SETUP Interrupt Position */
#define USBHS_DEVEPTIMR_INTRPT_RXSTPE_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIMR_INTRPT_RXSTPE_Pos) /* (USBHS_DEVEPTIMR) Received SETUP Interrupt Mask */
#define USBHS_DEVEPTIMR_INTRPT_RXSTPE(value)  (USBHS_DEVEPTIMR_INTRPT_RXSTPE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_INTRPT_RXSTPE_Pos))
#define USBHS_DEVEPTIMR_INTRPT_NAKOUTE_Pos    _UINT32_(3)                                          /* (USBHS_DEVEPTIMR) NAKed OUT Interrupt Position */
#define USBHS_DEVEPTIMR_INTRPT_NAKOUTE_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIMR_INTRPT_NAKOUTE_Pos) /* (USBHS_DEVEPTIMR) NAKed OUT Interrupt Mask */
#define USBHS_DEVEPTIMR_INTRPT_NAKOUTE(value) (USBHS_DEVEPTIMR_INTRPT_NAKOUTE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_INTRPT_NAKOUTE_Pos))
#define USBHS_DEVEPTIMR_INTRPT_NAKINE_Pos     _UINT32_(4)                                          /* (USBHS_DEVEPTIMR) NAKed IN Interrupt Position */
#define USBHS_DEVEPTIMR_INTRPT_NAKINE_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIMR_INTRPT_NAKINE_Pos) /* (USBHS_DEVEPTIMR) NAKed IN Interrupt Mask */
#define USBHS_DEVEPTIMR_INTRPT_NAKINE(value)  (USBHS_DEVEPTIMR_INTRPT_NAKINE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_INTRPT_NAKINE_Pos))
#define USBHS_DEVEPTIMR_INTRPT_STALLEDE_Pos   _UINT32_(6)                                          /* (USBHS_DEVEPTIMR) STALLed Interrupt Position */
#define USBHS_DEVEPTIMR_INTRPT_STALLEDE_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIMR_INTRPT_STALLEDE_Pos) /* (USBHS_DEVEPTIMR) STALLed Interrupt Mask */
#define USBHS_DEVEPTIMR_INTRPT_STALLEDE(value) (USBHS_DEVEPTIMR_INTRPT_STALLEDE_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_INTRPT_STALLEDE_Pos))
#define USBHS_DEVEPTIMR_INTRPT_NYETDIS_Pos    _UINT32_(17)                                         /* (USBHS_DEVEPTIMR) NYET Token Disable Position */
#define USBHS_DEVEPTIMR_INTRPT_NYETDIS_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIMR_INTRPT_NYETDIS_Pos) /* (USBHS_DEVEPTIMR) NYET Token Disable Mask */
#define USBHS_DEVEPTIMR_INTRPT_NYETDIS(value) (USBHS_DEVEPTIMR_INTRPT_NYETDIS_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_INTRPT_NYETDIS_Pos))
#define USBHS_DEVEPTIMR_INTRPT_STALLRQ_Pos    _UINT32_(19)                                         /* (USBHS_DEVEPTIMR) STALL Request Position */
#define USBHS_DEVEPTIMR_INTRPT_STALLRQ_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIMR_INTRPT_STALLRQ_Pos) /* (USBHS_DEVEPTIMR) STALL Request Mask */
#define USBHS_DEVEPTIMR_INTRPT_STALLRQ(value) (USBHS_DEVEPTIMR_INTRPT_STALLRQ_Msk & (_UINT32_(value) << USBHS_DEVEPTIMR_INTRPT_STALLRQ_Pos))
#define USBHS_DEVEPTIMR_INTRPT_Msk            _UINT32_(0x000A005C)                                  /* (USBHS_DEVEPTIMR_INTRPT) Register Mask  */


/* -------- USBHS_DEVEPTIER : (USBHS Offset: 0x1F0) ( /W 32) Device Endpoint Interrupt Enable Register -------- */
#define USBHS_DEVEPTIER_TXINES_Pos            _UINT32_(0)                                          /* (USBHS_DEVEPTIER) Transmitted IN Data Interrupt Enable Position */
#define USBHS_DEVEPTIER_TXINES_Msk            (_UINT32_(0x1) << USBHS_DEVEPTIER_TXINES_Pos)        /* (USBHS_DEVEPTIER) Transmitted IN Data Interrupt Enable Mask */
#define USBHS_DEVEPTIER_TXINES(value)         (USBHS_DEVEPTIER_TXINES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_TXINES_Pos)) /* Assigment of value for TXINES in the USBHS_DEVEPTIER register */
#define USBHS_DEVEPTIER_RXOUTES_Pos           _UINT32_(1)                                          /* (USBHS_DEVEPTIER) Received OUT Data Interrupt Enable Position */
#define USBHS_DEVEPTIER_RXOUTES_Msk           (_UINT32_(0x1) << USBHS_DEVEPTIER_RXOUTES_Pos)       /* (USBHS_DEVEPTIER) Received OUT Data Interrupt Enable Mask */
#define USBHS_DEVEPTIER_RXOUTES(value)        (USBHS_DEVEPTIER_RXOUTES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_RXOUTES_Pos)) /* Assigment of value for RXOUTES in the USBHS_DEVEPTIER register */
#define USBHS_DEVEPTIER_OVERFES_Pos           _UINT32_(5)                                          /* (USBHS_DEVEPTIER) Overflow Interrupt Enable Position */
#define USBHS_DEVEPTIER_OVERFES_Msk           (_UINT32_(0x1) << USBHS_DEVEPTIER_OVERFES_Pos)       /* (USBHS_DEVEPTIER) Overflow Interrupt Enable Mask */
#define USBHS_DEVEPTIER_OVERFES(value)        (USBHS_DEVEPTIER_OVERFES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_OVERFES_Pos)) /* Assigment of value for OVERFES in the USBHS_DEVEPTIER register */
#define USBHS_DEVEPTIER_SHORTPACKETES_Pos     _UINT32_(7)                                          /* (USBHS_DEVEPTIER) Short Packet Interrupt Enable Position */
#define USBHS_DEVEPTIER_SHORTPACKETES_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIER_SHORTPACKETES_Pos) /* (USBHS_DEVEPTIER) Short Packet Interrupt Enable Mask */
#define USBHS_DEVEPTIER_SHORTPACKETES(value)  (USBHS_DEVEPTIER_SHORTPACKETES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_SHORTPACKETES_Pos)) /* Assigment of value for SHORTPACKETES in the USBHS_DEVEPTIER register */
#define USBHS_DEVEPTIER_NBUSYBKES_Pos         _UINT32_(12)                                         /* (USBHS_DEVEPTIER) Number of Busy Banks Interrupt Enable Position */
#define USBHS_DEVEPTIER_NBUSYBKES_Msk         (_UINT32_(0x1) << USBHS_DEVEPTIER_NBUSYBKES_Pos)     /* (USBHS_DEVEPTIER) Number of Busy Banks Interrupt Enable Mask */
#define USBHS_DEVEPTIER_NBUSYBKES(value)      (USBHS_DEVEPTIER_NBUSYBKES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_NBUSYBKES_Pos)) /* Assigment of value for NBUSYBKES in the USBHS_DEVEPTIER register */
#define USBHS_DEVEPTIER_KILLBKS_Pos           _UINT32_(13)                                         /* (USBHS_DEVEPTIER) Kill IN Bank Position */
#define USBHS_DEVEPTIER_KILLBKS_Msk           (_UINT32_(0x1) << USBHS_DEVEPTIER_KILLBKS_Pos)       /* (USBHS_DEVEPTIER) Kill IN Bank Mask */
#define USBHS_DEVEPTIER_KILLBKS(value)        (USBHS_DEVEPTIER_KILLBKS_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_KILLBKS_Pos)) /* Assigment of value for KILLBKS in the USBHS_DEVEPTIER register */
#define USBHS_DEVEPTIER_FIFOCONS_Pos          _UINT32_(14)                                         /* (USBHS_DEVEPTIER) FIFO Control Position */
#define USBHS_DEVEPTIER_FIFOCONS_Msk          (_UINT32_(0x1) << USBHS_DEVEPTIER_FIFOCONS_Pos)      /* (USBHS_DEVEPTIER) FIFO Control Mask */
#define USBHS_DEVEPTIER_FIFOCONS(value)       (USBHS_DEVEPTIER_FIFOCONS_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_FIFOCONS_Pos)) /* Assigment of value for FIFOCONS in the USBHS_DEVEPTIER register */
#define USBHS_DEVEPTIER_EPDISHDMAS_Pos        _UINT32_(16)                                         /* (USBHS_DEVEPTIER) Endpoint Interrupts Disable HDMA Request Enable Position */
#define USBHS_DEVEPTIER_EPDISHDMAS_Msk        (_UINT32_(0x1) << USBHS_DEVEPTIER_EPDISHDMAS_Pos)    /* (USBHS_DEVEPTIER) Endpoint Interrupts Disable HDMA Request Enable Mask */
#define USBHS_DEVEPTIER_EPDISHDMAS(value)     (USBHS_DEVEPTIER_EPDISHDMAS_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_EPDISHDMAS_Pos)) /* Assigment of value for EPDISHDMAS in the USBHS_DEVEPTIER register */
#define USBHS_DEVEPTIER_RSTDTS_Pos            _UINT32_(18)                                         /* (USBHS_DEVEPTIER) Reset Data Toggle Enable Position */
#define USBHS_DEVEPTIER_RSTDTS_Msk            (_UINT32_(0x1) << USBHS_DEVEPTIER_RSTDTS_Pos)        /* (USBHS_DEVEPTIER) Reset Data Toggle Enable Mask */
#define USBHS_DEVEPTIER_RSTDTS(value)         (USBHS_DEVEPTIER_RSTDTS_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_RSTDTS_Pos)) /* Assigment of value for RSTDTS in the USBHS_DEVEPTIER register */
#define USBHS_DEVEPTIER_Msk                   _UINT32_(0x000570A3)                                 /* (USBHS_DEVEPTIER) Register Mask  */

/* CTRL mode */
#define USBHS_DEVEPTIER_CTRL_RXSTPES_Pos      _UINT32_(2)                                          /* (USBHS_DEVEPTIER) Received SETUP Interrupt Enable Position */
#define USBHS_DEVEPTIER_CTRL_RXSTPES_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIER_CTRL_RXSTPES_Pos)  /* (USBHS_DEVEPTIER) Received SETUP Interrupt Enable Mask */
#define USBHS_DEVEPTIER_CTRL_RXSTPES(value)   (USBHS_DEVEPTIER_CTRL_RXSTPES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_CTRL_RXSTPES_Pos))
#define USBHS_DEVEPTIER_CTRL_NAKOUTES_Pos     _UINT32_(3)                                          /* (USBHS_DEVEPTIER) NAKed OUT Interrupt Enable Position */
#define USBHS_DEVEPTIER_CTRL_NAKOUTES_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIER_CTRL_NAKOUTES_Pos) /* (USBHS_DEVEPTIER) NAKed OUT Interrupt Enable Mask */
#define USBHS_DEVEPTIER_CTRL_NAKOUTES(value)  (USBHS_DEVEPTIER_CTRL_NAKOUTES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_CTRL_NAKOUTES_Pos))
#define USBHS_DEVEPTIER_CTRL_NAKINES_Pos      _UINT32_(4)                                          /* (USBHS_DEVEPTIER) NAKed IN Interrupt Enable Position */
#define USBHS_DEVEPTIER_CTRL_NAKINES_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIER_CTRL_NAKINES_Pos)  /* (USBHS_DEVEPTIER) NAKed IN Interrupt Enable Mask */
#define USBHS_DEVEPTIER_CTRL_NAKINES(value)   (USBHS_DEVEPTIER_CTRL_NAKINES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_CTRL_NAKINES_Pos))
#define USBHS_DEVEPTIER_CTRL_STALLEDES_Pos    _UINT32_(6)                                          /* (USBHS_DEVEPTIER) STALLed Interrupt Enable Position */
#define USBHS_DEVEPTIER_CTRL_STALLEDES_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIER_CTRL_STALLEDES_Pos) /* (USBHS_DEVEPTIER) STALLed Interrupt Enable Mask */
#define USBHS_DEVEPTIER_CTRL_STALLEDES(value) (USBHS_DEVEPTIER_CTRL_STALLEDES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_CTRL_STALLEDES_Pos))
#define USBHS_DEVEPTIER_CTRL_NYETDISS_Pos     _UINT32_(17)                                         /* (USBHS_DEVEPTIER) NYET Token Disable Enable Position */
#define USBHS_DEVEPTIER_CTRL_NYETDISS_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIER_CTRL_NYETDISS_Pos) /* (USBHS_DEVEPTIER) NYET Token Disable Enable Mask */
#define USBHS_DEVEPTIER_CTRL_NYETDISS(value)  (USBHS_DEVEPTIER_CTRL_NYETDISS_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_CTRL_NYETDISS_Pos))
#define USBHS_DEVEPTIER_CTRL_STALLRQS_Pos     _UINT32_(19)                                         /* (USBHS_DEVEPTIER) STALL Request Enable Position */
#define USBHS_DEVEPTIER_CTRL_STALLRQS_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIER_CTRL_STALLRQS_Pos) /* (USBHS_DEVEPTIER) STALL Request Enable Mask */
#define USBHS_DEVEPTIER_CTRL_STALLRQS(value)  (USBHS_DEVEPTIER_CTRL_STALLRQS_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_CTRL_STALLRQS_Pos))
#define USBHS_DEVEPTIER_CTRL_Msk              _UINT32_(0x000A005C)                                  /* (USBHS_DEVEPTIER_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_DEVEPTIER_ISO_UNDERFES_Pos      _UINT32_(2)                                          /* (USBHS_DEVEPTIER) Underflow Interrupt Enable Position */
#define USBHS_DEVEPTIER_ISO_UNDERFES_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIER_ISO_UNDERFES_Pos)  /* (USBHS_DEVEPTIER) Underflow Interrupt Enable Mask */
#define USBHS_DEVEPTIER_ISO_UNDERFES(value)   (USBHS_DEVEPTIER_ISO_UNDERFES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_ISO_UNDERFES_Pos))
#define USBHS_DEVEPTIER_ISO_HBISOINERRES_Pos  _UINT32_(3)                                          /* (USBHS_DEVEPTIER) High Bandwidth Isochronous IN Underflow Error Interrupt Enable Position */
#define USBHS_DEVEPTIER_ISO_HBISOINERRES_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIER_ISO_HBISOINERRES_Pos) /* (USBHS_DEVEPTIER) High Bandwidth Isochronous IN Underflow Error Interrupt Enable Mask */
#define USBHS_DEVEPTIER_ISO_HBISOINERRES(value) (USBHS_DEVEPTIER_ISO_HBISOINERRES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_ISO_HBISOINERRES_Pos))
#define USBHS_DEVEPTIER_ISO_HBISOFLUSHES_Pos  _UINT32_(4)                                          /* (USBHS_DEVEPTIER) High Bandwidth Isochronous IN Flush Interrupt Enable Position */
#define USBHS_DEVEPTIER_ISO_HBISOFLUSHES_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIER_ISO_HBISOFLUSHES_Pos) /* (USBHS_DEVEPTIER) High Bandwidth Isochronous IN Flush Interrupt Enable Mask */
#define USBHS_DEVEPTIER_ISO_HBISOFLUSHES(value) (USBHS_DEVEPTIER_ISO_HBISOFLUSHES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_ISO_HBISOFLUSHES_Pos))
#define USBHS_DEVEPTIER_ISO_CRCERRES_Pos      _UINT32_(6)                                          /* (USBHS_DEVEPTIER) CRC Error Interrupt Enable Position */
#define USBHS_DEVEPTIER_ISO_CRCERRES_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIER_ISO_CRCERRES_Pos)  /* (USBHS_DEVEPTIER) CRC Error Interrupt Enable Mask */
#define USBHS_DEVEPTIER_ISO_CRCERRES(value)   (USBHS_DEVEPTIER_ISO_CRCERRES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_ISO_CRCERRES_Pos))
#define USBHS_DEVEPTIER_ISO_MDATAES_Pos       _UINT32_(8)                                          /* (USBHS_DEVEPTIER) MData Interrupt Enable Position */
#define USBHS_DEVEPTIER_ISO_MDATAES_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIER_ISO_MDATAES_Pos)   /* (USBHS_DEVEPTIER) MData Interrupt Enable Mask */
#define USBHS_DEVEPTIER_ISO_MDATAES(value)    (USBHS_DEVEPTIER_ISO_MDATAES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_ISO_MDATAES_Pos))
#define USBHS_DEVEPTIER_ISO_DATAXES_Pos       _UINT32_(9)                                          /* (USBHS_DEVEPTIER) DataX Interrupt Enable Position */
#define USBHS_DEVEPTIER_ISO_DATAXES_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIER_ISO_DATAXES_Pos)   /* (USBHS_DEVEPTIER) DataX Interrupt Enable Mask */
#define USBHS_DEVEPTIER_ISO_DATAXES(value)    (USBHS_DEVEPTIER_ISO_DATAXES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_ISO_DATAXES_Pos))
#define USBHS_DEVEPTIER_ISO_ERRORTRANSES_Pos  _UINT32_(10)                                         /* (USBHS_DEVEPTIER) Transaction Error Interrupt Enable Position */
#define USBHS_DEVEPTIER_ISO_ERRORTRANSES_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIER_ISO_ERRORTRANSES_Pos) /* (USBHS_DEVEPTIER) Transaction Error Interrupt Enable Mask */
#define USBHS_DEVEPTIER_ISO_ERRORTRANSES(value) (USBHS_DEVEPTIER_ISO_ERRORTRANSES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_ISO_ERRORTRANSES_Pos))
#define USBHS_DEVEPTIER_ISO_Msk               _UINT32_(0x0000075C)                                  /* (USBHS_DEVEPTIER_ISO) Register Mask  */

/* BLK mode */
#define USBHS_DEVEPTIER_BLK_RXSTPES_Pos       _UINT32_(2)                                          /* (USBHS_DEVEPTIER) Received SETUP Interrupt Enable Position */
#define USBHS_DEVEPTIER_BLK_RXSTPES_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIER_BLK_RXSTPES_Pos)   /* (USBHS_DEVEPTIER) Received SETUP Interrupt Enable Mask */
#define USBHS_DEVEPTIER_BLK_RXSTPES(value)    (USBHS_DEVEPTIER_BLK_RXSTPES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_BLK_RXSTPES_Pos))
#define USBHS_DEVEPTIER_BLK_NAKOUTES_Pos      _UINT32_(3)                                          /* (USBHS_DEVEPTIER) NAKed OUT Interrupt Enable Position */
#define USBHS_DEVEPTIER_BLK_NAKOUTES_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIER_BLK_NAKOUTES_Pos)  /* (USBHS_DEVEPTIER) NAKed OUT Interrupt Enable Mask */
#define USBHS_DEVEPTIER_BLK_NAKOUTES(value)   (USBHS_DEVEPTIER_BLK_NAKOUTES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_BLK_NAKOUTES_Pos))
#define USBHS_DEVEPTIER_BLK_NAKINES_Pos       _UINT32_(4)                                          /* (USBHS_DEVEPTIER) NAKed IN Interrupt Enable Position */
#define USBHS_DEVEPTIER_BLK_NAKINES_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIER_BLK_NAKINES_Pos)   /* (USBHS_DEVEPTIER) NAKed IN Interrupt Enable Mask */
#define USBHS_DEVEPTIER_BLK_NAKINES(value)    (USBHS_DEVEPTIER_BLK_NAKINES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_BLK_NAKINES_Pos))
#define USBHS_DEVEPTIER_BLK_STALLEDES_Pos     _UINT32_(6)                                          /* (USBHS_DEVEPTIER) STALLed Interrupt Enable Position */
#define USBHS_DEVEPTIER_BLK_STALLEDES_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIER_BLK_STALLEDES_Pos) /* (USBHS_DEVEPTIER) STALLed Interrupt Enable Mask */
#define USBHS_DEVEPTIER_BLK_STALLEDES(value)  (USBHS_DEVEPTIER_BLK_STALLEDES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_BLK_STALLEDES_Pos))
#define USBHS_DEVEPTIER_BLK_NYETDISS_Pos      _UINT32_(17)                                         /* (USBHS_DEVEPTIER) NYET Token Disable Enable Position */
#define USBHS_DEVEPTIER_BLK_NYETDISS_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIER_BLK_NYETDISS_Pos)  /* (USBHS_DEVEPTIER) NYET Token Disable Enable Mask */
#define USBHS_DEVEPTIER_BLK_NYETDISS(value)   (USBHS_DEVEPTIER_BLK_NYETDISS_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_BLK_NYETDISS_Pos))
#define USBHS_DEVEPTIER_BLK_STALLRQS_Pos      _UINT32_(19)                                         /* (USBHS_DEVEPTIER) STALL Request Enable Position */
#define USBHS_DEVEPTIER_BLK_STALLRQS_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIER_BLK_STALLRQS_Pos)  /* (USBHS_DEVEPTIER) STALL Request Enable Mask */
#define USBHS_DEVEPTIER_BLK_STALLRQS(value)   (USBHS_DEVEPTIER_BLK_STALLRQS_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_BLK_STALLRQS_Pos))
#define USBHS_DEVEPTIER_BLK_Msk               _UINT32_(0x000A005C)                                  /* (USBHS_DEVEPTIER_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_DEVEPTIER_INTRPT_RXSTPES_Pos    _UINT32_(2)                                          /* (USBHS_DEVEPTIER) Received SETUP Interrupt Enable Position */
#define USBHS_DEVEPTIER_INTRPT_RXSTPES_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIER_INTRPT_RXSTPES_Pos) /* (USBHS_DEVEPTIER) Received SETUP Interrupt Enable Mask */
#define USBHS_DEVEPTIER_INTRPT_RXSTPES(value) (USBHS_DEVEPTIER_INTRPT_RXSTPES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_INTRPT_RXSTPES_Pos))
#define USBHS_DEVEPTIER_INTRPT_NAKOUTES_Pos   _UINT32_(3)                                          /* (USBHS_DEVEPTIER) NAKed OUT Interrupt Enable Position */
#define USBHS_DEVEPTIER_INTRPT_NAKOUTES_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIER_INTRPT_NAKOUTES_Pos) /* (USBHS_DEVEPTIER) NAKed OUT Interrupt Enable Mask */
#define USBHS_DEVEPTIER_INTRPT_NAKOUTES(value) (USBHS_DEVEPTIER_INTRPT_NAKOUTES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_INTRPT_NAKOUTES_Pos))
#define USBHS_DEVEPTIER_INTRPT_NAKINES_Pos    _UINT32_(4)                                          /* (USBHS_DEVEPTIER) NAKed IN Interrupt Enable Position */
#define USBHS_DEVEPTIER_INTRPT_NAKINES_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIER_INTRPT_NAKINES_Pos) /* (USBHS_DEVEPTIER) NAKed IN Interrupt Enable Mask */
#define USBHS_DEVEPTIER_INTRPT_NAKINES(value) (USBHS_DEVEPTIER_INTRPT_NAKINES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_INTRPT_NAKINES_Pos))
#define USBHS_DEVEPTIER_INTRPT_STALLEDES_Pos  _UINT32_(6)                                          /* (USBHS_DEVEPTIER) STALLed Interrupt Enable Position */
#define USBHS_DEVEPTIER_INTRPT_STALLEDES_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIER_INTRPT_STALLEDES_Pos) /* (USBHS_DEVEPTIER) STALLed Interrupt Enable Mask */
#define USBHS_DEVEPTIER_INTRPT_STALLEDES(value) (USBHS_DEVEPTIER_INTRPT_STALLEDES_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_INTRPT_STALLEDES_Pos))
#define USBHS_DEVEPTIER_INTRPT_NYETDISS_Pos   _UINT32_(17)                                         /* (USBHS_DEVEPTIER) NYET Token Disable Enable Position */
#define USBHS_DEVEPTIER_INTRPT_NYETDISS_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIER_INTRPT_NYETDISS_Pos) /* (USBHS_DEVEPTIER) NYET Token Disable Enable Mask */
#define USBHS_DEVEPTIER_INTRPT_NYETDISS(value) (USBHS_DEVEPTIER_INTRPT_NYETDISS_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_INTRPT_NYETDISS_Pos))
#define USBHS_DEVEPTIER_INTRPT_STALLRQS_Pos   _UINT32_(19)                                         /* (USBHS_DEVEPTIER) STALL Request Enable Position */
#define USBHS_DEVEPTIER_INTRPT_STALLRQS_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIER_INTRPT_STALLRQS_Pos) /* (USBHS_DEVEPTIER) STALL Request Enable Mask */
#define USBHS_DEVEPTIER_INTRPT_STALLRQS(value) (USBHS_DEVEPTIER_INTRPT_STALLRQS_Msk & (_UINT32_(value) << USBHS_DEVEPTIER_INTRPT_STALLRQS_Pos))
#define USBHS_DEVEPTIER_INTRPT_Msk            _UINT32_(0x000A005C)                                  /* (USBHS_DEVEPTIER_INTRPT) Register Mask  */


/* -------- USBHS_DEVEPTIDR : (USBHS Offset: 0x220) ( /W 32) Device Endpoint Interrupt Disable Register -------- */
#define USBHS_DEVEPTIDR_TXINEC_Pos            _UINT32_(0)                                          /* (USBHS_DEVEPTIDR) Transmitted IN Interrupt Clear Position */
#define USBHS_DEVEPTIDR_TXINEC_Msk            (_UINT32_(0x1) << USBHS_DEVEPTIDR_TXINEC_Pos)        /* (USBHS_DEVEPTIDR) Transmitted IN Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_TXINEC(value)         (USBHS_DEVEPTIDR_TXINEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_TXINEC_Pos)) /* Assigment of value for TXINEC in the USBHS_DEVEPTIDR register */
#define USBHS_DEVEPTIDR_RXOUTEC_Pos           _UINT32_(1)                                          /* (USBHS_DEVEPTIDR) Received OUT Data Interrupt Clear Position */
#define USBHS_DEVEPTIDR_RXOUTEC_Msk           (_UINT32_(0x1) << USBHS_DEVEPTIDR_RXOUTEC_Pos)       /* (USBHS_DEVEPTIDR) Received OUT Data Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_RXOUTEC(value)        (USBHS_DEVEPTIDR_RXOUTEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_RXOUTEC_Pos)) /* Assigment of value for RXOUTEC in the USBHS_DEVEPTIDR register */
#define USBHS_DEVEPTIDR_OVERFEC_Pos           _UINT32_(5)                                          /* (USBHS_DEVEPTIDR) Overflow Interrupt Clear Position */
#define USBHS_DEVEPTIDR_OVERFEC_Msk           (_UINT32_(0x1) << USBHS_DEVEPTIDR_OVERFEC_Pos)       /* (USBHS_DEVEPTIDR) Overflow Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_OVERFEC(value)        (USBHS_DEVEPTIDR_OVERFEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_OVERFEC_Pos)) /* Assigment of value for OVERFEC in the USBHS_DEVEPTIDR register */
#define USBHS_DEVEPTIDR_SHORTPACKETEC_Pos     _UINT32_(7)                                          /* (USBHS_DEVEPTIDR) Shortpacket Interrupt Clear Position */
#define USBHS_DEVEPTIDR_SHORTPACKETEC_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIDR_SHORTPACKETEC_Pos) /* (USBHS_DEVEPTIDR) Shortpacket Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_SHORTPACKETEC(value)  (USBHS_DEVEPTIDR_SHORTPACKETEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_SHORTPACKETEC_Pos)) /* Assigment of value for SHORTPACKETEC in the USBHS_DEVEPTIDR register */
#define USBHS_DEVEPTIDR_NBUSYBKEC_Pos         _UINT32_(12)                                         /* (USBHS_DEVEPTIDR) Number of Busy Banks Interrupt Clear Position */
#define USBHS_DEVEPTIDR_NBUSYBKEC_Msk         (_UINT32_(0x1) << USBHS_DEVEPTIDR_NBUSYBKEC_Pos)     /* (USBHS_DEVEPTIDR) Number of Busy Banks Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_NBUSYBKEC(value)      (USBHS_DEVEPTIDR_NBUSYBKEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_NBUSYBKEC_Pos)) /* Assigment of value for NBUSYBKEC in the USBHS_DEVEPTIDR register */
#define USBHS_DEVEPTIDR_FIFOCONC_Pos          _UINT32_(14)                                         /* (USBHS_DEVEPTIDR) FIFO Control Clear Position */
#define USBHS_DEVEPTIDR_FIFOCONC_Msk          (_UINT32_(0x1) << USBHS_DEVEPTIDR_FIFOCONC_Pos)      /* (USBHS_DEVEPTIDR) FIFO Control Clear Mask */
#define USBHS_DEVEPTIDR_FIFOCONC(value)       (USBHS_DEVEPTIDR_FIFOCONC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_FIFOCONC_Pos)) /* Assigment of value for FIFOCONC in the USBHS_DEVEPTIDR register */
#define USBHS_DEVEPTIDR_EPDISHDMAC_Pos        _UINT32_(16)                                         /* (USBHS_DEVEPTIDR) Endpoint Interrupts Disable HDMA Request Clear Position */
#define USBHS_DEVEPTIDR_EPDISHDMAC_Msk        (_UINT32_(0x1) << USBHS_DEVEPTIDR_EPDISHDMAC_Pos)    /* (USBHS_DEVEPTIDR) Endpoint Interrupts Disable HDMA Request Clear Mask */
#define USBHS_DEVEPTIDR_EPDISHDMAC(value)     (USBHS_DEVEPTIDR_EPDISHDMAC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_EPDISHDMAC_Pos)) /* Assigment of value for EPDISHDMAC in the USBHS_DEVEPTIDR register */
#define USBHS_DEVEPTIDR_Msk                   _UINT32_(0x000150A3)                                 /* (USBHS_DEVEPTIDR) Register Mask  */

/* CTRL mode */
#define USBHS_DEVEPTIDR_CTRL_RXSTPEC_Pos      _UINT32_(2)                                          /* (USBHS_DEVEPTIDR) Received SETUP Interrupt Clear Position */
#define USBHS_DEVEPTIDR_CTRL_RXSTPEC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIDR_CTRL_RXSTPEC_Pos)  /* (USBHS_DEVEPTIDR) Received SETUP Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_CTRL_RXSTPEC(value)   (USBHS_DEVEPTIDR_CTRL_RXSTPEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_CTRL_RXSTPEC_Pos))
#define USBHS_DEVEPTIDR_CTRL_NAKOUTEC_Pos     _UINT32_(3)                                          /* (USBHS_DEVEPTIDR) NAKed OUT Interrupt Clear Position */
#define USBHS_DEVEPTIDR_CTRL_NAKOUTEC_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIDR_CTRL_NAKOUTEC_Pos) /* (USBHS_DEVEPTIDR) NAKed OUT Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_CTRL_NAKOUTEC(value)  (USBHS_DEVEPTIDR_CTRL_NAKOUTEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_CTRL_NAKOUTEC_Pos))
#define USBHS_DEVEPTIDR_CTRL_NAKINEC_Pos      _UINT32_(4)                                          /* (USBHS_DEVEPTIDR) NAKed IN Interrupt Clear Position */
#define USBHS_DEVEPTIDR_CTRL_NAKINEC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIDR_CTRL_NAKINEC_Pos)  /* (USBHS_DEVEPTIDR) NAKed IN Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_CTRL_NAKINEC(value)   (USBHS_DEVEPTIDR_CTRL_NAKINEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_CTRL_NAKINEC_Pos))
#define USBHS_DEVEPTIDR_CTRL_STALLEDEC_Pos    _UINT32_(6)                                          /* (USBHS_DEVEPTIDR) STALLed Interrupt Clear Position */
#define USBHS_DEVEPTIDR_CTRL_STALLEDEC_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIDR_CTRL_STALLEDEC_Pos) /* (USBHS_DEVEPTIDR) STALLed Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_CTRL_STALLEDEC(value) (USBHS_DEVEPTIDR_CTRL_STALLEDEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_CTRL_STALLEDEC_Pos))
#define USBHS_DEVEPTIDR_CTRL_NYETDISC_Pos     _UINT32_(17)                                         /* (USBHS_DEVEPTIDR) NYET Token Disable Clear Position */
#define USBHS_DEVEPTIDR_CTRL_NYETDISC_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIDR_CTRL_NYETDISC_Pos) /* (USBHS_DEVEPTIDR) NYET Token Disable Clear Mask */
#define USBHS_DEVEPTIDR_CTRL_NYETDISC(value)  (USBHS_DEVEPTIDR_CTRL_NYETDISC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_CTRL_NYETDISC_Pos))
#define USBHS_DEVEPTIDR_CTRL_STALLRQC_Pos     _UINT32_(19)                                         /* (USBHS_DEVEPTIDR) STALL Request Clear Position */
#define USBHS_DEVEPTIDR_CTRL_STALLRQC_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIDR_CTRL_STALLRQC_Pos) /* (USBHS_DEVEPTIDR) STALL Request Clear Mask */
#define USBHS_DEVEPTIDR_CTRL_STALLRQC(value)  (USBHS_DEVEPTIDR_CTRL_STALLRQC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_CTRL_STALLRQC_Pos))
#define USBHS_DEVEPTIDR_CTRL_Msk              _UINT32_(0x000A005C)                                  /* (USBHS_DEVEPTIDR_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_DEVEPTIDR_ISO_UNDERFEC_Pos      _UINT32_(2)                                          /* (USBHS_DEVEPTIDR) Underflow Interrupt Clear Position */
#define USBHS_DEVEPTIDR_ISO_UNDERFEC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIDR_ISO_UNDERFEC_Pos)  /* (USBHS_DEVEPTIDR) Underflow Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_ISO_UNDERFEC(value)   (USBHS_DEVEPTIDR_ISO_UNDERFEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_ISO_UNDERFEC_Pos))
#define USBHS_DEVEPTIDR_ISO_HBISOINERREC_Pos  _UINT32_(3)                                          /* (USBHS_DEVEPTIDR) High Bandwidth Isochronous IN Underflow Error Interrupt Clear Position */
#define USBHS_DEVEPTIDR_ISO_HBISOINERREC_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIDR_ISO_HBISOINERREC_Pos) /* (USBHS_DEVEPTIDR) High Bandwidth Isochronous IN Underflow Error Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_ISO_HBISOINERREC(value) (USBHS_DEVEPTIDR_ISO_HBISOINERREC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_ISO_HBISOINERREC_Pos))
#define USBHS_DEVEPTIDR_ISO_HBISOFLUSHEC_Pos  _UINT32_(4)                                          /* (USBHS_DEVEPTIDR) High Bandwidth Isochronous IN Flush Interrupt Clear Position */
#define USBHS_DEVEPTIDR_ISO_HBISOFLUSHEC_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIDR_ISO_HBISOFLUSHEC_Pos) /* (USBHS_DEVEPTIDR) High Bandwidth Isochronous IN Flush Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_ISO_HBISOFLUSHEC(value) (USBHS_DEVEPTIDR_ISO_HBISOFLUSHEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_ISO_HBISOFLUSHEC_Pos))
#define USBHS_DEVEPTIDR_ISO_MDATAEC_Pos       _UINT32_(8)                                          /* (USBHS_DEVEPTIDR) MData Interrupt Clear Position */
#define USBHS_DEVEPTIDR_ISO_MDATAEC_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIDR_ISO_MDATAEC_Pos)   /* (USBHS_DEVEPTIDR) MData Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_ISO_MDATAEC(value)    (USBHS_DEVEPTIDR_ISO_MDATAEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_ISO_MDATAEC_Pos))
#define USBHS_DEVEPTIDR_ISO_DATAXEC_Pos       _UINT32_(9)                                          /* (USBHS_DEVEPTIDR) DataX Interrupt Clear Position */
#define USBHS_DEVEPTIDR_ISO_DATAXEC_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIDR_ISO_DATAXEC_Pos)   /* (USBHS_DEVEPTIDR) DataX Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_ISO_DATAXEC(value)    (USBHS_DEVEPTIDR_ISO_DATAXEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_ISO_DATAXEC_Pos))
#define USBHS_DEVEPTIDR_ISO_ERRORTRANSEC_Pos  _UINT32_(10)                                         /* (USBHS_DEVEPTIDR) Transaction Error Interrupt Clear Position */
#define USBHS_DEVEPTIDR_ISO_ERRORTRANSEC_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIDR_ISO_ERRORTRANSEC_Pos) /* (USBHS_DEVEPTIDR) Transaction Error Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_ISO_ERRORTRANSEC(value) (USBHS_DEVEPTIDR_ISO_ERRORTRANSEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_ISO_ERRORTRANSEC_Pos))
#define USBHS_DEVEPTIDR_ISO_Msk               _UINT32_(0x0000071C)                                  /* (USBHS_DEVEPTIDR_ISO) Register Mask  */

/* BLK mode */
#define USBHS_DEVEPTIDR_BLK_RXSTPEC_Pos       _UINT32_(2)                                          /* (USBHS_DEVEPTIDR) Received SETUP Interrupt Clear Position */
#define USBHS_DEVEPTIDR_BLK_RXSTPEC_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIDR_BLK_RXSTPEC_Pos)   /* (USBHS_DEVEPTIDR) Received SETUP Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_BLK_RXSTPEC(value)    (USBHS_DEVEPTIDR_BLK_RXSTPEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_BLK_RXSTPEC_Pos))
#define USBHS_DEVEPTIDR_BLK_NAKOUTEC_Pos      _UINT32_(3)                                          /* (USBHS_DEVEPTIDR) NAKed OUT Interrupt Clear Position */
#define USBHS_DEVEPTIDR_BLK_NAKOUTEC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIDR_BLK_NAKOUTEC_Pos)  /* (USBHS_DEVEPTIDR) NAKed OUT Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_BLK_NAKOUTEC(value)   (USBHS_DEVEPTIDR_BLK_NAKOUTEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_BLK_NAKOUTEC_Pos))
#define USBHS_DEVEPTIDR_BLK_NAKINEC_Pos       _UINT32_(4)                                          /* (USBHS_DEVEPTIDR) NAKed IN Interrupt Clear Position */
#define USBHS_DEVEPTIDR_BLK_NAKINEC_Msk       (_UINT32_(0x1) << USBHS_DEVEPTIDR_BLK_NAKINEC_Pos)   /* (USBHS_DEVEPTIDR) NAKed IN Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_BLK_NAKINEC(value)    (USBHS_DEVEPTIDR_BLK_NAKINEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_BLK_NAKINEC_Pos))
#define USBHS_DEVEPTIDR_BLK_STALLEDEC_Pos     _UINT32_(6)                                          /* (USBHS_DEVEPTIDR) STALLed Interrupt Clear Position */
#define USBHS_DEVEPTIDR_BLK_STALLEDEC_Msk     (_UINT32_(0x1) << USBHS_DEVEPTIDR_BLK_STALLEDEC_Pos) /* (USBHS_DEVEPTIDR) STALLed Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_BLK_STALLEDEC(value)  (USBHS_DEVEPTIDR_BLK_STALLEDEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_BLK_STALLEDEC_Pos))
#define USBHS_DEVEPTIDR_BLK_NYETDISC_Pos      _UINT32_(17)                                         /* (USBHS_DEVEPTIDR) NYET Token Disable Clear Position */
#define USBHS_DEVEPTIDR_BLK_NYETDISC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIDR_BLK_NYETDISC_Pos)  /* (USBHS_DEVEPTIDR) NYET Token Disable Clear Mask */
#define USBHS_DEVEPTIDR_BLK_NYETDISC(value)   (USBHS_DEVEPTIDR_BLK_NYETDISC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_BLK_NYETDISC_Pos))
#define USBHS_DEVEPTIDR_BLK_STALLRQC_Pos      _UINT32_(19)                                         /* (USBHS_DEVEPTIDR) STALL Request Clear Position */
#define USBHS_DEVEPTIDR_BLK_STALLRQC_Msk      (_UINT32_(0x1) << USBHS_DEVEPTIDR_BLK_STALLRQC_Pos)  /* (USBHS_DEVEPTIDR) STALL Request Clear Mask */
#define USBHS_DEVEPTIDR_BLK_STALLRQC(value)   (USBHS_DEVEPTIDR_BLK_STALLRQC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_BLK_STALLRQC_Pos))
#define USBHS_DEVEPTIDR_BLK_Msk               _UINT32_(0x000A005C)                                  /* (USBHS_DEVEPTIDR_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_DEVEPTIDR_INTRPT_RXSTPEC_Pos    _UINT32_(2)                                          /* (USBHS_DEVEPTIDR) Received SETUP Interrupt Clear Position */
#define USBHS_DEVEPTIDR_INTRPT_RXSTPEC_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIDR_INTRPT_RXSTPEC_Pos) /* (USBHS_DEVEPTIDR) Received SETUP Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_INTRPT_RXSTPEC(value) (USBHS_DEVEPTIDR_INTRPT_RXSTPEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_INTRPT_RXSTPEC_Pos))
#define USBHS_DEVEPTIDR_INTRPT_NAKOUTEC_Pos   _UINT32_(3)                                          /* (USBHS_DEVEPTIDR) NAKed OUT Interrupt Clear Position */
#define USBHS_DEVEPTIDR_INTRPT_NAKOUTEC_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIDR_INTRPT_NAKOUTEC_Pos) /* (USBHS_DEVEPTIDR) NAKed OUT Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_INTRPT_NAKOUTEC(value) (USBHS_DEVEPTIDR_INTRPT_NAKOUTEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_INTRPT_NAKOUTEC_Pos))
#define USBHS_DEVEPTIDR_INTRPT_NAKINEC_Pos    _UINT32_(4)                                          /* (USBHS_DEVEPTIDR) NAKed IN Interrupt Clear Position */
#define USBHS_DEVEPTIDR_INTRPT_NAKINEC_Msk    (_UINT32_(0x1) << USBHS_DEVEPTIDR_INTRPT_NAKINEC_Pos) /* (USBHS_DEVEPTIDR) NAKed IN Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_INTRPT_NAKINEC(value) (USBHS_DEVEPTIDR_INTRPT_NAKINEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_INTRPT_NAKINEC_Pos))
#define USBHS_DEVEPTIDR_INTRPT_STALLEDEC_Pos  _UINT32_(6)                                          /* (USBHS_DEVEPTIDR) STALLed Interrupt Clear Position */
#define USBHS_DEVEPTIDR_INTRPT_STALLEDEC_Msk  (_UINT32_(0x1) << USBHS_DEVEPTIDR_INTRPT_STALLEDEC_Pos) /* (USBHS_DEVEPTIDR) STALLed Interrupt Clear Mask */
#define USBHS_DEVEPTIDR_INTRPT_STALLEDEC(value) (USBHS_DEVEPTIDR_INTRPT_STALLEDEC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_INTRPT_STALLEDEC_Pos))
#define USBHS_DEVEPTIDR_INTRPT_NYETDISC_Pos   _UINT32_(17)                                         /* (USBHS_DEVEPTIDR) NYET Token Disable Clear Position */
#define USBHS_DEVEPTIDR_INTRPT_NYETDISC_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIDR_INTRPT_NYETDISC_Pos) /* (USBHS_DEVEPTIDR) NYET Token Disable Clear Mask */
#define USBHS_DEVEPTIDR_INTRPT_NYETDISC(value) (USBHS_DEVEPTIDR_INTRPT_NYETDISC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_INTRPT_NYETDISC_Pos))
#define USBHS_DEVEPTIDR_INTRPT_STALLRQC_Pos   _UINT32_(19)                                         /* (USBHS_DEVEPTIDR) STALL Request Clear Position */
#define USBHS_DEVEPTIDR_INTRPT_STALLRQC_Msk   (_UINT32_(0x1) << USBHS_DEVEPTIDR_INTRPT_STALLRQC_Pos) /* (USBHS_DEVEPTIDR) STALL Request Clear Mask */
#define USBHS_DEVEPTIDR_INTRPT_STALLRQC(value) (USBHS_DEVEPTIDR_INTRPT_STALLRQC_Msk & (_UINT32_(value) << USBHS_DEVEPTIDR_INTRPT_STALLRQC_Pos))
#define USBHS_DEVEPTIDR_INTRPT_Msk            _UINT32_(0x000A005C)                                  /* (USBHS_DEVEPTIDR_INTRPT) Register Mask  */


/* -------- USBHS_HSTCTRL : (USBHS Offset: 0x400) (R/W 32) Host General Control Register -------- */
#define USBHS_HSTCTRL_SOFE_Pos                _UINT32_(8)                                          /* (USBHS_HSTCTRL) Start of Frame Generation Enable Position */
#define USBHS_HSTCTRL_SOFE_Msk                (_UINT32_(0x1) << USBHS_HSTCTRL_SOFE_Pos)            /* (USBHS_HSTCTRL) Start of Frame Generation Enable Mask */
#define USBHS_HSTCTRL_SOFE(value)             (USBHS_HSTCTRL_SOFE_Msk & (_UINT32_(value) << USBHS_HSTCTRL_SOFE_Pos)) /* Assigment of value for SOFE in the USBHS_HSTCTRL register */
#define USBHS_HSTCTRL_RESET_Pos               _UINT32_(9)                                          /* (USBHS_HSTCTRL) Send USB Reset Position */
#define USBHS_HSTCTRL_RESET_Msk               (_UINT32_(0x1) << USBHS_HSTCTRL_RESET_Pos)           /* (USBHS_HSTCTRL) Send USB Reset Mask */
#define USBHS_HSTCTRL_RESET(value)            (USBHS_HSTCTRL_RESET_Msk & (_UINT32_(value) << USBHS_HSTCTRL_RESET_Pos)) /* Assigment of value for RESET in the USBHS_HSTCTRL register */
#define USBHS_HSTCTRL_RESUME_Pos              _UINT32_(10)                                         /* (USBHS_HSTCTRL) Send USB Resume Position */
#define USBHS_HSTCTRL_RESUME_Msk              (_UINT32_(0x1) << USBHS_HSTCTRL_RESUME_Pos)          /* (USBHS_HSTCTRL) Send USB Resume Mask */
#define USBHS_HSTCTRL_RESUME(value)           (USBHS_HSTCTRL_RESUME_Msk & (_UINT32_(value) << USBHS_HSTCTRL_RESUME_Pos)) /* Assigment of value for RESUME in the USBHS_HSTCTRL register */
#define USBHS_HSTCTRL_SPDCONF_Pos             _UINT32_(12)                                         /* (USBHS_HSTCTRL) Mode Configuration Position */
#define USBHS_HSTCTRL_SPDCONF_Msk             (_UINT32_(0x3) << USBHS_HSTCTRL_SPDCONF_Pos)         /* (USBHS_HSTCTRL) Mode Configuration Mask */
#define USBHS_HSTCTRL_SPDCONF(value)          (USBHS_HSTCTRL_SPDCONF_Msk & (_UINT32_(value) << USBHS_HSTCTRL_SPDCONF_Pos)) /* Assigment of value for SPDCONF in the USBHS_HSTCTRL register */
#define   USBHS_HSTCTRL_SPDCONF_NORMAL_Val    _UINT32_(0x0)                                        /* (USBHS_HSTCTRL) The host starts in Full-speed mode and performs a high-speed reset to switch to High-speed mode if the downstream peripheral is high-speed capable.  */
#define   USBHS_HSTCTRL_SPDCONF_LOW_POWER_Val _UINT32_(0x1)                                        /* (USBHS_HSTCTRL) For a better consumption, if high speed is not needed.  */
#define   USBHS_HSTCTRL_SPDCONF_HIGH_SPEED_Val _UINT32_(0x2)                                        /* (USBHS_HSTCTRL) Forced high speed.  */
#define   USBHS_HSTCTRL_SPDCONF_FORCED_FS_Val _UINT32_(0x3)                                        /* (USBHS_HSTCTRL) The host remains in Full-speed mode whatever the peripheral speed capability.  */
#define USBHS_HSTCTRL_SPDCONF_NORMAL          (USBHS_HSTCTRL_SPDCONF_NORMAL_Val << USBHS_HSTCTRL_SPDCONF_Pos) /* (USBHS_HSTCTRL) The host starts in Full-speed mode and performs a high-speed reset to switch to High-speed mode if the downstream peripheral is high-speed capable. Position  */
#define USBHS_HSTCTRL_SPDCONF_LOW_POWER       (USBHS_HSTCTRL_SPDCONF_LOW_POWER_Val << USBHS_HSTCTRL_SPDCONF_Pos) /* (USBHS_HSTCTRL) For a better consumption, if high speed is not needed. Position  */
#define USBHS_HSTCTRL_SPDCONF_HIGH_SPEED      (USBHS_HSTCTRL_SPDCONF_HIGH_SPEED_Val << USBHS_HSTCTRL_SPDCONF_Pos) /* (USBHS_HSTCTRL) Forced high speed. Position  */
#define USBHS_HSTCTRL_SPDCONF_FORCED_FS       (USBHS_HSTCTRL_SPDCONF_FORCED_FS_Val << USBHS_HSTCTRL_SPDCONF_Pos) /* (USBHS_HSTCTRL) The host remains in Full-speed mode whatever the peripheral speed capability. Position  */
#define USBHS_HSTCTRL_Msk                     _UINT32_(0x00003700)                                 /* (USBHS_HSTCTRL) Register Mask  */


/* -------- USBHS_HSTISR : (USBHS Offset: 0x404) ( R/ 32) Host Global Interrupt Status Register -------- */
#define USBHS_HSTISR_DCONNI_Pos               _UINT32_(0)                                          /* (USBHS_HSTISR) Device Connection Interrupt Position */
#define USBHS_HSTISR_DCONNI_Msk               (_UINT32_(0x1) << USBHS_HSTISR_DCONNI_Pos)           /* (USBHS_HSTISR) Device Connection Interrupt Mask */
#define USBHS_HSTISR_DCONNI(value)            (USBHS_HSTISR_DCONNI_Msk & (_UINT32_(value) << USBHS_HSTISR_DCONNI_Pos)) /* Assigment of value for DCONNI in the USBHS_HSTISR register */
#define USBHS_HSTISR_DDISCI_Pos               _UINT32_(1)                                          /* (USBHS_HSTISR) Device Disconnection Interrupt Position */
#define USBHS_HSTISR_DDISCI_Msk               (_UINT32_(0x1) << USBHS_HSTISR_DDISCI_Pos)           /* (USBHS_HSTISR) Device Disconnection Interrupt Mask */
#define USBHS_HSTISR_DDISCI(value)            (USBHS_HSTISR_DDISCI_Msk & (_UINT32_(value) << USBHS_HSTISR_DDISCI_Pos)) /* Assigment of value for DDISCI in the USBHS_HSTISR register */
#define USBHS_HSTISR_RSTI_Pos                 _UINT32_(2)                                          /* (USBHS_HSTISR) USB Reset Sent Interrupt Position */
#define USBHS_HSTISR_RSTI_Msk                 (_UINT32_(0x1) << USBHS_HSTISR_RSTI_Pos)             /* (USBHS_HSTISR) USB Reset Sent Interrupt Mask */
#define USBHS_HSTISR_RSTI(value)              (USBHS_HSTISR_RSTI_Msk & (_UINT32_(value) << USBHS_HSTISR_RSTI_Pos)) /* Assigment of value for RSTI in the USBHS_HSTISR register */
#define USBHS_HSTISR_RSMEDI_Pos               _UINT32_(3)                                          /* (USBHS_HSTISR) Downstream Resume Sent Interrupt Position */
#define USBHS_HSTISR_RSMEDI_Msk               (_UINT32_(0x1) << USBHS_HSTISR_RSMEDI_Pos)           /* (USBHS_HSTISR) Downstream Resume Sent Interrupt Mask */
#define USBHS_HSTISR_RSMEDI(value)            (USBHS_HSTISR_RSMEDI_Msk & (_UINT32_(value) << USBHS_HSTISR_RSMEDI_Pos)) /* Assigment of value for RSMEDI in the USBHS_HSTISR register */
#define USBHS_HSTISR_RXRSMI_Pos               _UINT32_(4)                                          /* (USBHS_HSTISR) Upstream Resume Received Interrupt Position */
#define USBHS_HSTISR_RXRSMI_Msk               (_UINT32_(0x1) << USBHS_HSTISR_RXRSMI_Pos)           /* (USBHS_HSTISR) Upstream Resume Received Interrupt Mask */
#define USBHS_HSTISR_RXRSMI(value)            (USBHS_HSTISR_RXRSMI_Msk & (_UINT32_(value) << USBHS_HSTISR_RXRSMI_Pos)) /* Assigment of value for RXRSMI in the USBHS_HSTISR register */
#define USBHS_HSTISR_HSOFI_Pos                _UINT32_(5)                                          /* (USBHS_HSTISR) Host Start of Frame Interrupt Position */
#define USBHS_HSTISR_HSOFI_Msk                (_UINT32_(0x1) << USBHS_HSTISR_HSOFI_Pos)            /* (USBHS_HSTISR) Host Start of Frame Interrupt Mask */
#define USBHS_HSTISR_HSOFI(value)             (USBHS_HSTISR_HSOFI_Msk & (_UINT32_(value) << USBHS_HSTISR_HSOFI_Pos)) /* Assigment of value for HSOFI in the USBHS_HSTISR register */
#define USBHS_HSTISR_HWUPI_Pos                _UINT32_(6)                                          /* (USBHS_HSTISR) Host Wake-Up Interrupt Position */
#define USBHS_HSTISR_HWUPI_Msk                (_UINT32_(0x1) << USBHS_HSTISR_HWUPI_Pos)            /* (USBHS_HSTISR) Host Wake-Up Interrupt Mask */
#define USBHS_HSTISR_HWUPI(value)             (USBHS_HSTISR_HWUPI_Msk & (_UINT32_(value) << USBHS_HSTISR_HWUPI_Pos)) /* Assigment of value for HWUPI in the USBHS_HSTISR register */
#define USBHS_HSTISR_PEP_0_Pos                _UINT32_(8)                                          /* (USBHS_HSTISR) Pipe 0 Interrupt Position */
#define USBHS_HSTISR_PEP_0_Msk                (_UINT32_(0x1) << USBHS_HSTISR_PEP_0_Pos)            /* (USBHS_HSTISR) Pipe 0 Interrupt Mask */
#define USBHS_HSTISR_PEP_0(value)             (USBHS_HSTISR_PEP_0_Msk & (_UINT32_(value) << USBHS_HSTISR_PEP_0_Pos)) /* Assigment of value for PEP_0 in the USBHS_HSTISR register */
#define USBHS_HSTISR_PEP_1_Pos                _UINT32_(9)                                          /* (USBHS_HSTISR) Pipe 1 Interrupt Position */
#define USBHS_HSTISR_PEP_1_Msk                (_UINT32_(0x1) << USBHS_HSTISR_PEP_1_Pos)            /* (USBHS_HSTISR) Pipe 1 Interrupt Mask */
#define USBHS_HSTISR_PEP_1(value)             (USBHS_HSTISR_PEP_1_Msk & (_UINT32_(value) << USBHS_HSTISR_PEP_1_Pos)) /* Assigment of value for PEP_1 in the USBHS_HSTISR register */
#define USBHS_HSTISR_PEP_2_Pos                _UINT32_(10)                                         /* (USBHS_HSTISR) Pipe 2 Interrupt Position */
#define USBHS_HSTISR_PEP_2_Msk                (_UINT32_(0x1) << USBHS_HSTISR_PEP_2_Pos)            /* (USBHS_HSTISR) Pipe 2 Interrupt Mask */
#define USBHS_HSTISR_PEP_2(value)             (USBHS_HSTISR_PEP_2_Msk & (_UINT32_(value) << USBHS_HSTISR_PEP_2_Pos)) /* Assigment of value for PEP_2 in the USBHS_HSTISR register */
#define USBHS_HSTISR_PEP_3_Pos                _UINT32_(11)                                         /* (USBHS_HSTISR) Pipe 3 Interrupt Position */
#define USBHS_HSTISR_PEP_3_Msk                (_UINT32_(0x1) << USBHS_HSTISR_PEP_3_Pos)            /* (USBHS_HSTISR) Pipe 3 Interrupt Mask */
#define USBHS_HSTISR_PEP_3(value)             (USBHS_HSTISR_PEP_3_Msk & (_UINT32_(value) << USBHS_HSTISR_PEP_3_Pos)) /* Assigment of value for PEP_3 in the USBHS_HSTISR register */
#define USBHS_HSTISR_PEP_4_Pos                _UINT32_(12)                                         /* (USBHS_HSTISR) Pipe 4 Interrupt Position */
#define USBHS_HSTISR_PEP_4_Msk                (_UINT32_(0x1) << USBHS_HSTISR_PEP_4_Pos)            /* (USBHS_HSTISR) Pipe 4 Interrupt Mask */
#define USBHS_HSTISR_PEP_4(value)             (USBHS_HSTISR_PEP_4_Msk & (_UINT32_(value) << USBHS_HSTISR_PEP_4_Pos)) /* Assigment of value for PEP_4 in the USBHS_HSTISR register */
#define USBHS_HSTISR_PEP_5_Pos                _UINT32_(13)                                         /* (USBHS_HSTISR) Pipe 5 Interrupt Position */
#define USBHS_HSTISR_PEP_5_Msk                (_UINT32_(0x1) << USBHS_HSTISR_PEP_5_Pos)            /* (USBHS_HSTISR) Pipe 5 Interrupt Mask */
#define USBHS_HSTISR_PEP_5(value)             (USBHS_HSTISR_PEP_5_Msk & (_UINT32_(value) << USBHS_HSTISR_PEP_5_Pos)) /* Assigment of value for PEP_5 in the USBHS_HSTISR register */
#define USBHS_HSTISR_PEP_6_Pos                _UINT32_(14)                                         /* (USBHS_HSTISR) Pipe 6 Interrupt Position */
#define USBHS_HSTISR_PEP_6_Msk                (_UINT32_(0x1) << USBHS_HSTISR_PEP_6_Pos)            /* (USBHS_HSTISR) Pipe 6 Interrupt Mask */
#define USBHS_HSTISR_PEP_6(value)             (USBHS_HSTISR_PEP_6_Msk & (_UINT32_(value) << USBHS_HSTISR_PEP_6_Pos)) /* Assigment of value for PEP_6 in the USBHS_HSTISR register */
#define USBHS_HSTISR_PEP_7_Pos                _UINT32_(15)                                         /* (USBHS_HSTISR) Pipe 7 Interrupt Position */
#define USBHS_HSTISR_PEP_7_Msk                (_UINT32_(0x1) << USBHS_HSTISR_PEP_7_Pos)            /* (USBHS_HSTISR) Pipe 7 Interrupt Mask */
#define USBHS_HSTISR_PEP_7(value)             (USBHS_HSTISR_PEP_7_Msk & (_UINT32_(value) << USBHS_HSTISR_PEP_7_Pos)) /* Assigment of value for PEP_7 in the USBHS_HSTISR register */
#define USBHS_HSTISR_PEP_8_Pos                _UINT32_(16)                                         /* (USBHS_HSTISR) Pipe 8 Interrupt Position */
#define USBHS_HSTISR_PEP_8_Msk                (_UINT32_(0x1) << USBHS_HSTISR_PEP_8_Pos)            /* (USBHS_HSTISR) Pipe 8 Interrupt Mask */
#define USBHS_HSTISR_PEP_8(value)             (USBHS_HSTISR_PEP_8_Msk & (_UINT32_(value) << USBHS_HSTISR_PEP_8_Pos)) /* Assigment of value for PEP_8 in the USBHS_HSTISR register */
#define USBHS_HSTISR_PEP_9_Pos                _UINT32_(17)                                         /* (USBHS_HSTISR) Pipe 9 Interrupt Position */
#define USBHS_HSTISR_PEP_9_Msk                (_UINT32_(0x1) << USBHS_HSTISR_PEP_9_Pos)            /* (USBHS_HSTISR) Pipe 9 Interrupt Mask */
#define USBHS_HSTISR_PEP_9(value)             (USBHS_HSTISR_PEP_9_Msk & (_UINT32_(value) << USBHS_HSTISR_PEP_9_Pos)) /* Assigment of value for PEP_9 in the USBHS_HSTISR register */
#define USBHS_HSTISR_DMA_1_Pos                _UINT32_(25)                                         /* (USBHS_HSTISR) DMA Channel 0 Interrupt Position */
#define USBHS_HSTISR_DMA_1_Msk                (_UINT32_(0x1) << USBHS_HSTISR_DMA_1_Pos)            /* (USBHS_HSTISR) DMA Channel 0 Interrupt Mask */
#define USBHS_HSTISR_DMA_1(value)             (USBHS_HSTISR_DMA_1_Msk & (_UINT32_(value) << USBHS_HSTISR_DMA_1_Pos)) /* Assigment of value for DMA_1 in the USBHS_HSTISR register */
#define USBHS_HSTISR_DMA_2_Pos                _UINT32_(26)                                         /* (USBHS_HSTISR) DMA Channel 1 Interrupt Position */
#define USBHS_HSTISR_DMA_2_Msk                (_UINT32_(0x1) << USBHS_HSTISR_DMA_2_Pos)            /* (USBHS_HSTISR) DMA Channel 1 Interrupt Mask */
#define USBHS_HSTISR_DMA_2(value)             (USBHS_HSTISR_DMA_2_Msk & (_UINT32_(value) << USBHS_HSTISR_DMA_2_Pos)) /* Assigment of value for DMA_2 in the USBHS_HSTISR register */
#define USBHS_HSTISR_DMA_3_Pos                _UINT32_(27)                                         /* (USBHS_HSTISR) DMA Channel 2 Interrupt Position */
#define USBHS_HSTISR_DMA_3_Msk                (_UINT32_(0x1) << USBHS_HSTISR_DMA_3_Pos)            /* (USBHS_HSTISR) DMA Channel 2 Interrupt Mask */
#define USBHS_HSTISR_DMA_3(value)             (USBHS_HSTISR_DMA_3_Msk & (_UINT32_(value) << USBHS_HSTISR_DMA_3_Pos)) /* Assigment of value for DMA_3 in the USBHS_HSTISR register */
#define USBHS_HSTISR_DMA_4_Pos                _UINT32_(28)                                         /* (USBHS_HSTISR) DMA Channel 3 Interrupt Position */
#define USBHS_HSTISR_DMA_4_Msk                (_UINT32_(0x1) << USBHS_HSTISR_DMA_4_Pos)            /* (USBHS_HSTISR) DMA Channel 3 Interrupt Mask */
#define USBHS_HSTISR_DMA_4(value)             (USBHS_HSTISR_DMA_4_Msk & (_UINT32_(value) << USBHS_HSTISR_DMA_4_Pos)) /* Assigment of value for DMA_4 in the USBHS_HSTISR register */
#define USBHS_HSTISR_DMA_5_Pos                _UINT32_(29)                                         /* (USBHS_HSTISR) DMA Channel 4 Interrupt Position */
#define USBHS_HSTISR_DMA_5_Msk                (_UINT32_(0x1) << USBHS_HSTISR_DMA_5_Pos)            /* (USBHS_HSTISR) DMA Channel 4 Interrupt Mask */
#define USBHS_HSTISR_DMA_5(value)             (USBHS_HSTISR_DMA_5_Msk & (_UINT32_(value) << USBHS_HSTISR_DMA_5_Pos)) /* Assigment of value for DMA_5 in the USBHS_HSTISR register */
#define USBHS_HSTISR_DMA_6_Pos                _UINT32_(30)                                         /* (USBHS_HSTISR) DMA Channel 5 Interrupt Position */
#define USBHS_HSTISR_DMA_6_Msk                (_UINT32_(0x1) << USBHS_HSTISR_DMA_6_Pos)            /* (USBHS_HSTISR) DMA Channel 5 Interrupt Mask */
#define USBHS_HSTISR_DMA_6(value)             (USBHS_HSTISR_DMA_6_Msk & (_UINT32_(value) << USBHS_HSTISR_DMA_6_Pos)) /* Assigment of value for DMA_6 in the USBHS_HSTISR register */
#define USBHS_HSTISR_DMA_7_Pos                _UINT32_(31)                                         /* (USBHS_HSTISR) DMA Channel 6 Interrupt Position */
#define USBHS_HSTISR_DMA_7_Msk                (_UINT32_(0x1) << USBHS_HSTISR_DMA_7_Pos)            /* (USBHS_HSTISR) DMA Channel 6 Interrupt Mask */
#define USBHS_HSTISR_DMA_7(value)             (USBHS_HSTISR_DMA_7_Msk & (_UINT32_(value) << USBHS_HSTISR_DMA_7_Pos)) /* Assigment of value for DMA_7 in the USBHS_HSTISR register */
#define USBHS_HSTISR_Msk                      _UINT32_(0xFE03FF7F)                                 /* (USBHS_HSTISR) Register Mask  */

#define USBHS_HSTISR_PEP__Pos                 _UINT32_(8)                                          /* (USBHS_HSTISR Position) Pipe x Interrupt */
#define USBHS_HSTISR_PEP__Msk                 (_UINT32_(0x3FF) << USBHS_HSTISR_PEP__Pos)           /* (USBHS_HSTISR Mask) PEP_ */
#define USBHS_HSTISR_PEP_(value)              (USBHS_HSTISR_PEP__Msk & (_UINT32_(value) << USBHS_HSTISR_PEP__Pos)) 
#define USBHS_HSTISR_DMA__Pos                 _UINT32_(25)                                         /* (USBHS_HSTISR Position) DMA Channel 6 Interrupt */
#define USBHS_HSTISR_DMA__Msk                 (_UINT32_(0x7F) << USBHS_HSTISR_DMA__Pos)            /* (USBHS_HSTISR Mask) DMA_ */
#define USBHS_HSTISR_DMA_(value)              (USBHS_HSTISR_DMA__Msk & (_UINT32_(value) << USBHS_HSTISR_DMA__Pos)) 

/* -------- USBHS_HSTICR : (USBHS Offset: 0x408) ( /W 32) Host Global Interrupt Clear Register -------- */
#define USBHS_HSTICR_DCONNIC_Pos              _UINT32_(0)                                          /* (USBHS_HSTICR) Device Connection Interrupt Clear Position */
#define USBHS_HSTICR_DCONNIC_Msk              (_UINT32_(0x1) << USBHS_HSTICR_DCONNIC_Pos)          /* (USBHS_HSTICR) Device Connection Interrupt Clear Mask */
#define USBHS_HSTICR_DCONNIC(value)           (USBHS_HSTICR_DCONNIC_Msk & (_UINT32_(value) << USBHS_HSTICR_DCONNIC_Pos)) /* Assigment of value for DCONNIC in the USBHS_HSTICR register */
#define USBHS_HSTICR_DDISCIC_Pos              _UINT32_(1)                                          /* (USBHS_HSTICR) Device Disconnection Interrupt Clear Position */
#define USBHS_HSTICR_DDISCIC_Msk              (_UINT32_(0x1) << USBHS_HSTICR_DDISCIC_Pos)          /* (USBHS_HSTICR) Device Disconnection Interrupt Clear Mask */
#define USBHS_HSTICR_DDISCIC(value)           (USBHS_HSTICR_DDISCIC_Msk & (_UINT32_(value) << USBHS_HSTICR_DDISCIC_Pos)) /* Assigment of value for DDISCIC in the USBHS_HSTICR register */
#define USBHS_HSTICR_RSTIC_Pos                _UINT32_(2)                                          /* (USBHS_HSTICR) USB Reset Sent Interrupt Clear Position */
#define USBHS_HSTICR_RSTIC_Msk                (_UINT32_(0x1) << USBHS_HSTICR_RSTIC_Pos)            /* (USBHS_HSTICR) USB Reset Sent Interrupt Clear Mask */
#define USBHS_HSTICR_RSTIC(value)             (USBHS_HSTICR_RSTIC_Msk & (_UINT32_(value) << USBHS_HSTICR_RSTIC_Pos)) /* Assigment of value for RSTIC in the USBHS_HSTICR register */
#define USBHS_HSTICR_RSMEDIC_Pos              _UINT32_(3)                                          /* (USBHS_HSTICR) Downstream Resume Sent Interrupt Clear Position */
#define USBHS_HSTICR_RSMEDIC_Msk              (_UINT32_(0x1) << USBHS_HSTICR_RSMEDIC_Pos)          /* (USBHS_HSTICR) Downstream Resume Sent Interrupt Clear Mask */
#define USBHS_HSTICR_RSMEDIC(value)           (USBHS_HSTICR_RSMEDIC_Msk & (_UINT32_(value) << USBHS_HSTICR_RSMEDIC_Pos)) /* Assigment of value for RSMEDIC in the USBHS_HSTICR register */
#define USBHS_HSTICR_RXRSMIC_Pos              _UINT32_(4)                                          /* (USBHS_HSTICR) Upstream Resume Received Interrupt Clear Position */
#define USBHS_HSTICR_RXRSMIC_Msk              (_UINT32_(0x1) << USBHS_HSTICR_RXRSMIC_Pos)          /* (USBHS_HSTICR) Upstream Resume Received Interrupt Clear Mask */
#define USBHS_HSTICR_RXRSMIC(value)           (USBHS_HSTICR_RXRSMIC_Msk & (_UINT32_(value) << USBHS_HSTICR_RXRSMIC_Pos)) /* Assigment of value for RXRSMIC in the USBHS_HSTICR register */
#define USBHS_HSTICR_HSOFIC_Pos               _UINT32_(5)                                          /* (USBHS_HSTICR) Host Start of Frame Interrupt Clear Position */
#define USBHS_HSTICR_HSOFIC_Msk               (_UINT32_(0x1) << USBHS_HSTICR_HSOFIC_Pos)           /* (USBHS_HSTICR) Host Start of Frame Interrupt Clear Mask */
#define USBHS_HSTICR_HSOFIC(value)            (USBHS_HSTICR_HSOFIC_Msk & (_UINT32_(value) << USBHS_HSTICR_HSOFIC_Pos)) /* Assigment of value for HSOFIC in the USBHS_HSTICR register */
#define USBHS_HSTICR_HWUPIC_Pos               _UINT32_(6)                                          /* (USBHS_HSTICR) Host Wake-Up Interrupt Clear Position */
#define USBHS_HSTICR_HWUPIC_Msk               (_UINT32_(0x1) << USBHS_HSTICR_HWUPIC_Pos)           /* (USBHS_HSTICR) Host Wake-Up Interrupt Clear Mask */
#define USBHS_HSTICR_HWUPIC(value)            (USBHS_HSTICR_HWUPIC_Msk & (_UINT32_(value) << USBHS_HSTICR_HWUPIC_Pos)) /* Assigment of value for HWUPIC in the USBHS_HSTICR register */
#define USBHS_HSTICR_Msk                      _UINT32_(0x0000007F)                                 /* (USBHS_HSTICR) Register Mask  */


/* -------- USBHS_HSTIFR : (USBHS Offset: 0x40C) ( /W 32) Host Global Interrupt Set Register -------- */
#define USBHS_HSTIFR_DCONNIS_Pos              _UINT32_(0)                                          /* (USBHS_HSTIFR) Device Connection Interrupt Set Position */
#define USBHS_HSTIFR_DCONNIS_Msk              (_UINT32_(0x1) << USBHS_HSTIFR_DCONNIS_Pos)          /* (USBHS_HSTIFR) Device Connection Interrupt Set Mask */
#define USBHS_HSTIFR_DCONNIS(value)           (USBHS_HSTIFR_DCONNIS_Msk & (_UINT32_(value) << USBHS_HSTIFR_DCONNIS_Pos)) /* Assigment of value for DCONNIS in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_DDISCIS_Pos              _UINT32_(1)                                          /* (USBHS_HSTIFR) Device Disconnection Interrupt Set Position */
#define USBHS_HSTIFR_DDISCIS_Msk              (_UINT32_(0x1) << USBHS_HSTIFR_DDISCIS_Pos)          /* (USBHS_HSTIFR) Device Disconnection Interrupt Set Mask */
#define USBHS_HSTIFR_DDISCIS(value)           (USBHS_HSTIFR_DDISCIS_Msk & (_UINT32_(value) << USBHS_HSTIFR_DDISCIS_Pos)) /* Assigment of value for DDISCIS in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_RSTIS_Pos                _UINT32_(2)                                          /* (USBHS_HSTIFR) USB Reset Sent Interrupt Set Position */
#define USBHS_HSTIFR_RSTIS_Msk                (_UINT32_(0x1) << USBHS_HSTIFR_RSTIS_Pos)            /* (USBHS_HSTIFR) USB Reset Sent Interrupt Set Mask */
#define USBHS_HSTIFR_RSTIS(value)             (USBHS_HSTIFR_RSTIS_Msk & (_UINT32_(value) << USBHS_HSTIFR_RSTIS_Pos)) /* Assigment of value for RSTIS in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_RSMEDIS_Pos              _UINT32_(3)                                          /* (USBHS_HSTIFR) Downstream Resume Sent Interrupt Set Position */
#define USBHS_HSTIFR_RSMEDIS_Msk              (_UINT32_(0x1) << USBHS_HSTIFR_RSMEDIS_Pos)          /* (USBHS_HSTIFR) Downstream Resume Sent Interrupt Set Mask */
#define USBHS_HSTIFR_RSMEDIS(value)           (USBHS_HSTIFR_RSMEDIS_Msk & (_UINT32_(value) << USBHS_HSTIFR_RSMEDIS_Pos)) /* Assigment of value for RSMEDIS in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_RXRSMIS_Pos              _UINT32_(4)                                          /* (USBHS_HSTIFR) Upstream Resume Received Interrupt Set Position */
#define USBHS_HSTIFR_RXRSMIS_Msk              (_UINT32_(0x1) << USBHS_HSTIFR_RXRSMIS_Pos)          /* (USBHS_HSTIFR) Upstream Resume Received Interrupt Set Mask */
#define USBHS_HSTIFR_RXRSMIS(value)           (USBHS_HSTIFR_RXRSMIS_Msk & (_UINT32_(value) << USBHS_HSTIFR_RXRSMIS_Pos)) /* Assigment of value for RXRSMIS in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_HSOFIS_Pos               _UINT32_(5)                                          /* (USBHS_HSTIFR) Host Start of Frame Interrupt Set Position */
#define USBHS_HSTIFR_HSOFIS_Msk               (_UINT32_(0x1) << USBHS_HSTIFR_HSOFIS_Pos)           /* (USBHS_HSTIFR) Host Start of Frame Interrupt Set Mask */
#define USBHS_HSTIFR_HSOFIS(value)            (USBHS_HSTIFR_HSOFIS_Msk & (_UINT32_(value) << USBHS_HSTIFR_HSOFIS_Pos)) /* Assigment of value for HSOFIS in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_HWUPIS_Pos               _UINT32_(6)                                          /* (USBHS_HSTIFR) Host Wake-Up Interrupt Set Position */
#define USBHS_HSTIFR_HWUPIS_Msk               (_UINT32_(0x1) << USBHS_HSTIFR_HWUPIS_Pos)           /* (USBHS_HSTIFR) Host Wake-Up Interrupt Set Mask */
#define USBHS_HSTIFR_HWUPIS(value)            (USBHS_HSTIFR_HWUPIS_Msk & (_UINT32_(value) << USBHS_HSTIFR_HWUPIS_Pos)) /* Assigment of value for HWUPIS in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_DMA_1_Pos                _UINT32_(25)                                         /* (USBHS_HSTIFR) DMA Channel 0 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_1_Msk                (_UINT32_(0x1) << USBHS_HSTIFR_DMA_1_Pos)            /* (USBHS_HSTIFR) DMA Channel 0 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_1(value)             (USBHS_HSTIFR_DMA_1_Msk & (_UINT32_(value) << USBHS_HSTIFR_DMA_1_Pos)) /* Assigment of value for DMA_1 in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_DMA_2_Pos                _UINT32_(26)                                         /* (USBHS_HSTIFR) DMA Channel 1 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_2_Msk                (_UINT32_(0x1) << USBHS_HSTIFR_DMA_2_Pos)            /* (USBHS_HSTIFR) DMA Channel 1 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_2(value)             (USBHS_HSTIFR_DMA_2_Msk & (_UINT32_(value) << USBHS_HSTIFR_DMA_2_Pos)) /* Assigment of value for DMA_2 in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_DMA_3_Pos                _UINT32_(27)                                         /* (USBHS_HSTIFR) DMA Channel 2 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_3_Msk                (_UINT32_(0x1) << USBHS_HSTIFR_DMA_3_Pos)            /* (USBHS_HSTIFR) DMA Channel 2 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_3(value)             (USBHS_HSTIFR_DMA_3_Msk & (_UINT32_(value) << USBHS_HSTIFR_DMA_3_Pos)) /* Assigment of value for DMA_3 in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_DMA_4_Pos                _UINT32_(28)                                         /* (USBHS_HSTIFR) DMA Channel 3 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_4_Msk                (_UINT32_(0x1) << USBHS_HSTIFR_DMA_4_Pos)            /* (USBHS_HSTIFR) DMA Channel 3 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_4(value)             (USBHS_HSTIFR_DMA_4_Msk & (_UINT32_(value) << USBHS_HSTIFR_DMA_4_Pos)) /* Assigment of value for DMA_4 in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_DMA_5_Pos                _UINT32_(29)                                         /* (USBHS_HSTIFR) DMA Channel 4 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_5_Msk                (_UINT32_(0x1) << USBHS_HSTIFR_DMA_5_Pos)            /* (USBHS_HSTIFR) DMA Channel 4 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_5(value)             (USBHS_HSTIFR_DMA_5_Msk & (_UINT32_(value) << USBHS_HSTIFR_DMA_5_Pos)) /* Assigment of value for DMA_5 in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_DMA_6_Pos                _UINT32_(30)                                         /* (USBHS_HSTIFR) DMA Channel 5 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_6_Msk                (_UINT32_(0x1) << USBHS_HSTIFR_DMA_6_Pos)            /* (USBHS_HSTIFR) DMA Channel 5 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_6(value)             (USBHS_HSTIFR_DMA_6_Msk & (_UINT32_(value) << USBHS_HSTIFR_DMA_6_Pos)) /* Assigment of value for DMA_6 in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_DMA_7_Pos                _UINT32_(31)                                         /* (USBHS_HSTIFR) DMA Channel 6 Interrupt Set Position */
#define USBHS_HSTIFR_DMA_7_Msk                (_UINT32_(0x1) << USBHS_HSTIFR_DMA_7_Pos)            /* (USBHS_HSTIFR) DMA Channel 6 Interrupt Set Mask */
#define USBHS_HSTIFR_DMA_7(value)             (USBHS_HSTIFR_DMA_7_Msk & (_UINT32_(value) << USBHS_HSTIFR_DMA_7_Pos)) /* Assigment of value for DMA_7 in the USBHS_HSTIFR register */
#define USBHS_HSTIFR_Msk                      _UINT32_(0xFE00007F)                                 /* (USBHS_HSTIFR) Register Mask  */

#define USBHS_HSTIFR_DMA__Pos                 _UINT32_(25)                                         /* (USBHS_HSTIFR Position) DMA Channel 6 Interrupt Set */
#define USBHS_HSTIFR_DMA__Msk                 (_UINT32_(0x7F) << USBHS_HSTIFR_DMA__Pos)            /* (USBHS_HSTIFR Mask) DMA_ */
#define USBHS_HSTIFR_DMA_(value)              (USBHS_HSTIFR_DMA__Msk & (_UINT32_(value) << USBHS_HSTIFR_DMA__Pos)) 

/* -------- USBHS_HSTIMR : (USBHS Offset: 0x410) ( R/ 32) Host Global Interrupt Mask Register -------- */
#define USBHS_HSTIMR_DCONNIE_Pos              _UINT32_(0)                                          /* (USBHS_HSTIMR) Device Connection Interrupt Enable Position */
#define USBHS_HSTIMR_DCONNIE_Msk              (_UINT32_(0x1) << USBHS_HSTIMR_DCONNIE_Pos)          /* (USBHS_HSTIMR) Device Connection Interrupt Enable Mask */
#define USBHS_HSTIMR_DCONNIE(value)           (USBHS_HSTIMR_DCONNIE_Msk & (_UINT32_(value) << USBHS_HSTIMR_DCONNIE_Pos)) /* Assigment of value for DCONNIE in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_DDISCIE_Pos              _UINT32_(1)                                          /* (USBHS_HSTIMR) Device Disconnection Interrupt Enable Position */
#define USBHS_HSTIMR_DDISCIE_Msk              (_UINT32_(0x1) << USBHS_HSTIMR_DDISCIE_Pos)          /* (USBHS_HSTIMR) Device Disconnection Interrupt Enable Mask */
#define USBHS_HSTIMR_DDISCIE(value)           (USBHS_HSTIMR_DDISCIE_Msk & (_UINT32_(value) << USBHS_HSTIMR_DDISCIE_Pos)) /* Assigment of value for DDISCIE in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_RSTIE_Pos                _UINT32_(2)                                          /* (USBHS_HSTIMR) USB Reset Sent Interrupt Enable Position */
#define USBHS_HSTIMR_RSTIE_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_RSTIE_Pos)            /* (USBHS_HSTIMR) USB Reset Sent Interrupt Enable Mask */
#define USBHS_HSTIMR_RSTIE(value)             (USBHS_HSTIMR_RSTIE_Msk & (_UINT32_(value) << USBHS_HSTIMR_RSTIE_Pos)) /* Assigment of value for RSTIE in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_RSMEDIE_Pos              _UINT32_(3)                                          /* (USBHS_HSTIMR) Downstream Resume Sent Interrupt Enable Position */
#define USBHS_HSTIMR_RSMEDIE_Msk              (_UINT32_(0x1) << USBHS_HSTIMR_RSMEDIE_Pos)          /* (USBHS_HSTIMR) Downstream Resume Sent Interrupt Enable Mask */
#define USBHS_HSTIMR_RSMEDIE(value)           (USBHS_HSTIMR_RSMEDIE_Msk & (_UINT32_(value) << USBHS_HSTIMR_RSMEDIE_Pos)) /* Assigment of value for RSMEDIE in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_RXRSMIE_Pos              _UINT32_(4)                                          /* (USBHS_HSTIMR) Upstream Resume Received Interrupt Enable Position */
#define USBHS_HSTIMR_RXRSMIE_Msk              (_UINT32_(0x1) << USBHS_HSTIMR_RXRSMIE_Pos)          /* (USBHS_HSTIMR) Upstream Resume Received Interrupt Enable Mask */
#define USBHS_HSTIMR_RXRSMIE(value)           (USBHS_HSTIMR_RXRSMIE_Msk & (_UINT32_(value) << USBHS_HSTIMR_RXRSMIE_Pos)) /* Assigment of value for RXRSMIE in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_HSOFIE_Pos               _UINT32_(5)                                          /* (USBHS_HSTIMR) Host Start of Frame Interrupt Enable Position */
#define USBHS_HSTIMR_HSOFIE_Msk               (_UINT32_(0x1) << USBHS_HSTIMR_HSOFIE_Pos)           /* (USBHS_HSTIMR) Host Start of Frame Interrupt Enable Mask */
#define USBHS_HSTIMR_HSOFIE(value)            (USBHS_HSTIMR_HSOFIE_Msk & (_UINT32_(value) << USBHS_HSTIMR_HSOFIE_Pos)) /* Assigment of value for HSOFIE in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_HWUPIE_Pos               _UINT32_(6)                                          /* (USBHS_HSTIMR) Host Wake-Up Interrupt Enable Position */
#define USBHS_HSTIMR_HWUPIE_Msk               (_UINT32_(0x1) << USBHS_HSTIMR_HWUPIE_Pos)           /* (USBHS_HSTIMR) Host Wake-Up Interrupt Enable Mask */
#define USBHS_HSTIMR_HWUPIE(value)            (USBHS_HSTIMR_HWUPIE_Msk & (_UINT32_(value) << USBHS_HSTIMR_HWUPIE_Pos)) /* Assigment of value for HWUPIE in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_PEP_0_Pos                _UINT32_(8)                                          /* (USBHS_HSTIMR) Pipe 0 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_0_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_PEP_0_Pos)            /* (USBHS_HSTIMR) Pipe 0 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_0(value)             (USBHS_HSTIMR_PEP_0_Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP_0_Pos)) /* Assigment of value for PEP_0 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_PEP_1_Pos                _UINT32_(9)                                          /* (USBHS_HSTIMR) Pipe 1 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_1_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_PEP_1_Pos)            /* (USBHS_HSTIMR) Pipe 1 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_1(value)             (USBHS_HSTIMR_PEP_1_Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP_1_Pos)) /* Assigment of value for PEP_1 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_PEP_2_Pos                _UINT32_(10)                                         /* (USBHS_HSTIMR) Pipe 2 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_2_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_PEP_2_Pos)            /* (USBHS_HSTIMR) Pipe 2 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_2(value)             (USBHS_HSTIMR_PEP_2_Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP_2_Pos)) /* Assigment of value for PEP_2 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_PEP_3_Pos                _UINT32_(11)                                         /* (USBHS_HSTIMR) Pipe 3 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_3_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_PEP_3_Pos)            /* (USBHS_HSTIMR) Pipe 3 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_3(value)             (USBHS_HSTIMR_PEP_3_Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP_3_Pos)) /* Assigment of value for PEP_3 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_PEP_4_Pos                _UINT32_(12)                                         /* (USBHS_HSTIMR) Pipe 4 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_4_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_PEP_4_Pos)            /* (USBHS_HSTIMR) Pipe 4 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_4(value)             (USBHS_HSTIMR_PEP_4_Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP_4_Pos)) /* Assigment of value for PEP_4 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_PEP_5_Pos                _UINT32_(13)                                         /* (USBHS_HSTIMR) Pipe 5 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_5_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_PEP_5_Pos)            /* (USBHS_HSTIMR) Pipe 5 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_5(value)             (USBHS_HSTIMR_PEP_5_Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP_5_Pos)) /* Assigment of value for PEP_5 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_PEP_6_Pos                _UINT32_(14)                                         /* (USBHS_HSTIMR) Pipe 6 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_6_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_PEP_6_Pos)            /* (USBHS_HSTIMR) Pipe 6 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_6(value)             (USBHS_HSTIMR_PEP_6_Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP_6_Pos)) /* Assigment of value for PEP_6 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_PEP_7_Pos                _UINT32_(15)                                         /* (USBHS_HSTIMR) Pipe 7 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_7_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_PEP_7_Pos)            /* (USBHS_HSTIMR) Pipe 7 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_7(value)             (USBHS_HSTIMR_PEP_7_Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP_7_Pos)) /* Assigment of value for PEP_7 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_PEP_8_Pos                _UINT32_(16)                                         /* (USBHS_HSTIMR) Pipe 8 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_8_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_PEP_8_Pos)            /* (USBHS_HSTIMR) Pipe 8 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_8(value)             (USBHS_HSTIMR_PEP_8_Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP_8_Pos)) /* Assigment of value for PEP_8 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_PEP_9_Pos                _UINT32_(17)                                         /* (USBHS_HSTIMR) Pipe 9 Interrupt Enable Position */
#define USBHS_HSTIMR_PEP_9_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_PEP_9_Pos)            /* (USBHS_HSTIMR) Pipe 9 Interrupt Enable Mask */
#define USBHS_HSTIMR_PEP_9(value)             (USBHS_HSTIMR_PEP_9_Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP_9_Pos)) /* Assigment of value for PEP_9 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_DMA_1_Pos                _UINT32_(25)                                         /* (USBHS_HSTIMR) DMA Channel 0 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_1_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_DMA_1_Pos)            /* (USBHS_HSTIMR) DMA Channel 0 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_1(value)             (USBHS_HSTIMR_DMA_1_Msk & (_UINT32_(value) << USBHS_HSTIMR_DMA_1_Pos)) /* Assigment of value for DMA_1 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_DMA_2_Pos                _UINT32_(26)                                         /* (USBHS_HSTIMR) DMA Channel 1 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_2_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_DMA_2_Pos)            /* (USBHS_HSTIMR) DMA Channel 1 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_2(value)             (USBHS_HSTIMR_DMA_2_Msk & (_UINT32_(value) << USBHS_HSTIMR_DMA_2_Pos)) /* Assigment of value for DMA_2 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_DMA_3_Pos                _UINT32_(27)                                         /* (USBHS_HSTIMR) DMA Channel 2 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_3_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_DMA_3_Pos)            /* (USBHS_HSTIMR) DMA Channel 2 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_3(value)             (USBHS_HSTIMR_DMA_3_Msk & (_UINT32_(value) << USBHS_HSTIMR_DMA_3_Pos)) /* Assigment of value for DMA_3 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_DMA_4_Pos                _UINT32_(28)                                         /* (USBHS_HSTIMR) DMA Channel 3 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_4_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_DMA_4_Pos)            /* (USBHS_HSTIMR) DMA Channel 3 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_4(value)             (USBHS_HSTIMR_DMA_4_Msk & (_UINT32_(value) << USBHS_HSTIMR_DMA_4_Pos)) /* Assigment of value for DMA_4 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_DMA_5_Pos                _UINT32_(29)                                         /* (USBHS_HSTIMR) DMA Channel 4 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_5_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_DMA_5_Pos)            /* (USBHS_HSTIMR) DMA Channel 4 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_5(value)             (USBHS_HSTIMR_DMA_5_Msk & (_UINT32_(value) << USBHS_HSTIMR_DMA_5_Pos)) /* Assigment of value for DMA_5 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_DMA_6_Pos                _UINT32_(30)                                         /* (USBHS_HSTIMR) DMA Channel 5 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_6_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_DMA_6_Pos)            /* (USBHS_HSTIMR) DMA Channel 5 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_6(value)             (USBHS_HSTIMR_DMA_6_Msk & (_UINT32_(value) << USBHS_HSTIMR_DMA_6_Pos)) /* Assigment of value for DMA_6 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_DMA_7_Pos                _UINT32_(31)                                         /* (USBHS_HSTIMR) DMA Channel 6 Interrupt Enable Position */
#define USBHS_HSTIMR_DMA_7_Msk                (_UINT32_(0x1) << USBHS_HSTIMR_DMA_7_Pos)            /* (USBHS_HSTIMR) DMA Channel 6 Interrupt Enable Mask */
#define USBHS_HSTIMR_DMA_7(value)             (USBHS_HSTIMR_DMA_7_Msk & (_UINT32_(value) << USBHS_HSTIMR_DMA_7_Pos)) /* Assigment of value for DMA_7 in the USBHS_HSTIMR register */
#define USBHS_HSTIMR_Msk                      _UINT32_(0xFE03FF7F)                                 /* (USBHS_HSTIMR) Register Mask  */

#define USBHS_HSTIMR_PEP__Pos                 _UINT32_(8)                                          /* (USBHS_HSTIMR Position) Pipe x Interrupt Enable */
#define USBHS_HSTIMR_PEP__Msk                 (_UINT32_(0x3FF) << USBHS_HSTIMR_PEP__Pos)           /* (USBHS_HSTIMR Mask) PEP_ */
#define USBHS_HSTIMR_PEP_(value)              (USBHS_HSTIMR_PEP__Msk & (_UINT32_(value) << USBHS_HSTIMR_PEP__Pos)) 
#define USBHS_HSTIMR_DMA__Pos                 _UINT32_(25)                                         /* (USBHS_HSTIMR Position) DMA Channel 6 Interrupt Enable */
#define USBHS_HSTIMR_DMA__Msk                 (_UINT32_(0x7F) << USBHS_HSTIMR_DMA__Pos)            /* (USBHS_HSTIMR Mask) DMA_ */
#define USBHS_HSTIMR_DMA_(value)              (USBHS_HSTIMR_DMA__Msk & (_UINT32_(value) << USBHS_HSTIMR_DMA__Pos)) 

/* -------- USBHS_HSTIDR : (USBHS Offset: 0x414) ( /W 32) Host Global Interrupt Disable Register -------- */
#define USBHS_HSTIDR_DCONNIEC_Pos             _UINT32_(0)                                          /* (USBHS_HSTIDR) Device Connection Interrupt Disable Position */
#define USBHS_HSTIDR_DCONNIEC_Msk             (_UINT32_(0x1) << USBHS_HSTIDR_DCONNIEC_Pos)         /* (USBHS_HSTIDR) Device Connection Interrupt Disable Mask */
#define USBHS_HSTIDR_DCONNIEC(value)          (USBHS_HSTIDR_DCONNIEC_Msk & (_UINT32_(value) << USBHS_HSTIDR_DCONNIEC_Pos)) /* Assigment of value for DCONNIEC in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_DDISCIEC_Pos             _UINT32_(1)                                          /* (USBHS_HSTIDR) Device Disconnection Interrupt Disable Position */
#define USBHS_HSTIDR_DDISCIEC_Msk             (_UINT32_(0x1) << USBHS_HSTIDR_DDISCIEC_Pos)         /* (USBHS_HSTIDR) Device Disconnection Interrupt Disable Mask */
#define USBHS_HSTIDR_DDISCIEC(value)          (USBHS_HSTIDR_DDISCIEC_Msk & (_UINT32_(value) << USBHS_HSTIDR_DDISCIEC_Pos)) /* Assigment of value for DDISCIEC in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_RSTIEC_Pos               _UINT32_(2)                                          /* (USBHS_HSTIDR) USB Reset Sent Interrupt Disable Position */
#define USBHS_HSTIDR_RSTIEC_Msk               (_UINT32_(0x1) << USBHS_HSTIDR_RSTIEC_Pos)           /* (USBHS_HSTIDR) USB Reset Sent Interrupt Disable Mask */
#define USBHS_HSTIDR_RSTIEC(value)            (USBHS_HSTIDR_RSTIEC_Msk & (_UINT32_(value) << USBHS_HSTIDR_RSTIEC_Pos)) /* Assigment of value for RSTIEC in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_RSMEDIEC_Pos             _UINT32_(3)                                          /* (USBHS_HSTIDR) Downstream Resume Sent Interrupt Disable Position */
#define USBHS_HSTIDR_RSMEDIEC_Msk             (_UINT32_(0x1) << USBHS_HSTIDR_RSMEDIEC_Pos)         /* (USBHS_HSTIDR) Downstream Resume Sent Interrupt Disable Mask */
#define USBHS_HSTIDR_RSMEDIEC(value)          (USBHS_HSTIDR_RSMEDIEC_Msk & (_UINT32_(value) << USBHS_HSTIDR_RSMEDIEC_Pos)) /* Assigment of value for RSMEDIEC in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_RXRSMIEC_Pos             _UINT32_(4)                                          /* (USBHS_HSTIDR) Upstream Resume Received Interrupt Disable Position */
#define USBHS_HSTIDR_RXRSMIEC_Msk             (_UINT32_(0x1) << USBHS_HSTIDR_RXRSMIEC_Pos)         /* (USBHS_HSTIDR) Upstream Resume Received Interrupt Disable Mask */
#define USBHS_HSTIDR_RXRSMIEC(value)          (USBHS_HSTIDR_RXRSMIEC_Msk & (_UINT32_(value) << USBHS_HSTIDR_RXRSMIEC_Pos)) /* Assigment of value for RXRSMIEC in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_HSOFIEC_Pos              _UINT32_(5)                                          /* (USBHS_HSTIDR) Host Start of Frame Interrupt Disable Position */
#define USBHS_HSTIDR_HSOFIEC_Msk              (_UINT32_(0x1) << USBHS_HSTIDR_HSOFIEC_Pos)          /* (USBHS_HSTIDR) Host Start of Frame Interrupt Disable Mask */
#define USBHS_HSTIDR_HSOFIEC(value)           (USBHS_HSTIDR_HSOFIEC_Msk & (_UINT32_(value) << USBHS_HSTIDR_HSOFIEC_Pos)) /* Assigment of value for HSOFIEC in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_HWUPIEC_Pos              _UINT32_(6)                                          /* (USBHS_HSTIDR) Host Wake-Up Interrupt Disable Position */
#define USBHS_HSTIDR_HWUPIEC_Msk              (_UINT32_(0x1) << USBHS_HSTIDR_HWUPIEC_Pos)          /* (USBHS_HSTIDR) Host Wake-Up Interrupt Disable Mask */
#define USBHS_HSTIDR_HWUPIEC(value)           (USBHS_HSTIDR_HWUPIEC_Msk & (_UINT32_(value) << USBHS_HSTIDR_HWUPIEC_Pos)) /* Assigment of value for HWUPIEC in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_PEP_0_Pos                _UINT32_(8)                                          /* (USBHS_HSTIDR) Pipe 0 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_0_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_PEP_0_Pos)            /* (USBHS_HSTIDR) Pipe 0 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_0(value)             (USBHS_HSTIDR_PEP_0_Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP_0_Pos)) /* Assigment of value for PEP_0 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_PEP_1_Pos                _UINT32_(9)                                          /* (USBHS_HSTIDR) Pipe 1 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_1_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_PEP_1_Pos)            /* (USBHS_HSTIDR) Pipe 1 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_1(value)             (USBHS_HSTIDR_PEP_1_Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP_1_Pos)) /* Assigment of value for PEP_1 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_PEP_2_Pos                _UINT32_(10)                                         /* (USBHS_HSTIDR) Pipe 2 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_2_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_PEP_2_Pos)            /* (USBHS_HSTIDR) Pipe 2 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_2(value)             (USBHS_HSTIDR_PEP_2_Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP_2_Pos)) /* Assigment of value for PEP_2 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_PEP_3_Pos                _UINT32_(11)                                         /* (USBHS_HSTIDR) Pipe 3 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_3_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_PEP_3_Pos)            /* (USBHS_HSTIDR) Pipe 3 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_3(value)             (USBHS_HSTIDR_PEP_3_Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP_3_Pos)) /* Assigment of value for PEP_3 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_PEP_4_Pos                _UINT32_(12)                                         /* (USBHS_HSTIDR) Pipe 4 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_4_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_PEP_4_Pos)            /* (USBHS_HSTIDR) Pipe 4 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_4(value)             (USBHS_HSTIDR_PEP_4_Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP_4_Pos)) /* Assigment of value for PEP_4 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_PEP_5_Pos                _UINT32_(13)                                         /* (USBHS_HSTIDR) Pipe 5 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_5_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_PEP_5_Pos)            /* (USBHS_HSTIDR) Pipe 5 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_5(value)             (USBHS_HSTIDR_PEP_5_Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP_5_Pos)) /* Assigment of value for PEP_5 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_PEP_6_Pos                _UINT32_(14)                                         /* (USBHS_HSTIDR) Pipe 6 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_6_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_PEP_6_Pos)            /* (USBHS_HSTIDR) Pipe 6 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_6(value)             (USBHS_HSTIDR_PEP_6_Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP_6_Pos)) /* Assigment of value for PEP_6 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_PEP_7_Pos                _UINT32_(15)                                         /* (USBHS_HSTIDR) Pipe 7 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_7_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_PEP_7_Pos)            /* (USBHS_HSTIDR) Pipe 7 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_7(value)             (USBHS_HSTIDR_PEP_7_Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP_7_Pos)) /* Assigment of value for PEP_7 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_PEP_8_Pos                _UINT32_(16)                                         /* (USBHS_HSTIDR) Pipe 8 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_8_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_PEP_8_Pos)            /* (USBHS_HSTIDR) Pipe 8 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_8(value)             (USBHS_HSTIDR_PEP_8_Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP_8_Pos)) /* Assigment of value for PEP_8 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_PEP_9_Pos                _UINT32_(17)                                         /* (USBHS_HSTIDR) Pipe 9 Interrupt Disable Position */
#define USBHS_HSTIDR_PEP_9_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_PEP_9_Pos)            /* (USBHS_HSTIDR) Pipe 9 Interrupt Disable Mask */
#define USBHS_HSTIDR_PEP_9(value)             (USBHS_HSTIDR_PEP_9_Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP_9_Pos)) /* Assigment of value for PEP_9 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_DMA_1_Pos                _UINT32_(25)                                         /* (USBHS_HSTIDR) DMA Channel 0 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_1_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_DMA_1_Pos)            /* (USBHS_HSTIDR) DMA Channel 0 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_1(value)             (USBHS_HSTIDR_DMA_1_Msk & (_UINT32_(value) << USBHS_HSTIDR_DMA_1_Pos)) /* Assigment of value for DMA_1 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_DMA_2_Pos                _UINT32_(26)                                         /* (USBHS_HSTIDR) DMA Channel 1 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_2_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_DMA_2_Pos)            /* (USBHS_HSTIDR) DMA Channel 1 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_2(value)             (USBHS_HSTIDR_DMA_2_Msk & (_UINT32_(value) << USBHS_HSTIDR_DMA_2_Pos)) /* Assigment of value for DMA_2 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_DMA_3_Pos                _UINT32_(27)                                         /* (USBHS_HSTIDR) DMA Channel 2 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_3_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_DMA_3_Pos)            /* (USBHS_HSTIDR) DMA Channel 2 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_3(value)             (USBHS_HSTIDR_DMA_3_Msk & (_UINT32_(value) << USBHS_HSTIDR_DMA_3_Pos)) /* Assigment of value for DMA_3 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_DMA_4_Pos                _UINT32_(28)                                         /* (USBHS_HSTIDR) DMA Channel 3 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_4_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_DMA_4_Pos)            /* (USBHS_HSTIDR) DMA Channel 3 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_4(value)             (USBHS_HSTIDR_DMA_4_Msk & (_UINT32_(value) << USBHS_HSTIDR_DMA_4_Pos)) /* Assigment of value for DMA_4 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_DMA_5_Pos                _UINT32_(29)                                         /* (USBHS_HSTIDR) DMA Channel 4 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_5_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_DMA_5_Pos)            /* (USBHS_HSTIDR) DMA Channel 4 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_5(value)             (USBHS_HSTIDR_DMA_5_Msk & (_UINT32_(value) << USBHS_HSTIDR_DMA_5_Pos)) /* Assigment of value for DMA_5 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_DMA_6_Pos                _UINT32_(30)                                         /* (USBHS_HSTIDR) DMA Channel 5 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_6_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_DMA_6_Pos)            /* (USBHS_HSTIDR) DMA Channel 5 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_6(value)             (USBHS_HSTIDR_DMA_6_Msk & (_UINT32_(value) << USBHS_HSTIDR_DMA_6_Pos)) /* Assigment of value for DMA_6 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_DMA_7_Pos                _UINT32_(31)                                         /* (USBHS_HSTIDR) DMA Channel 6 Interrupt Disable Position */
#define USBHS_HSTIDR_DMA_7_Msk                (_UINT32_(0x1) << USBHS_HSTIDR_DMA_7_Pos)            /* (USBHS_HSTIDR) DMA Channel 6 Interrupt Disable Mask */
#define USBHS_HSTIDR_DMA_7(value)             (USBHS_HSTIDR_DMA_7_Msk & (_UINT32_(value) << USBHS_HSTIDR_DMA_7_Pos)) /* Assigment of value for DMA_7 in the USBHS_HSTIDR register */
#define USBHS_HSTIDR_Msk                      _UINT32_(0xFE03FF7F)                                 /* (USBHS_HSTIDR) Register Mask  */

#define USBHS_HSTIDR_PEP__Pos                 _UINT32_(8)                                          /* (USBHS_HSTIDR Position) Pipe x Interrupt Disable */
#define USBHS_HSTIDR_PEP__Msk                 (_UINT32_(0x3FF) << USBHS_HSTIDR_PEP__Pos)           /* (USBHS_HSTIDR Mask) PEP_ */
#define USBHS_HSTIDR_PEP_(value)              (USBHS_HSTIDR_PEP__Msk & (_UINT32_(value) << USBHS_HSTIDR_PEP__Pos)) 
#define USBHS_HSTIDR_DMA__Pos                 _UINT32_(25)                                         /* (USBHS_HSTIDR Position) DMA Channel 6 Interrupt Disable */
#define USBHS_HSTIDR_DMA__Msk                 (_UINT32_(0x7F) << USBHS_HSTIDR_DMA__Pos)            /* (USBHS_HSTIDR Mask) DMA_ */
#define USBHS_HSTIDR_DMA_(value)              (USBHS_HSTIDR_DMA__Msk & (_UINT32_(value) << USBHS_HSTIDR_DMA__Pos)) 

/* -------- USBHS_HSTIER : (USBHS Offset: 0x418) ( /W 32) Host Global Interrupt Enable Register -------- */
#define USBHS_HSTIER_DCONNIES_Pos             _UINT32_(0)                                          /* (USBHS_HSTIER) Device Connection Interrupt Enable Position */
#define USBHS_HSTIER_DCONNIES_Msk             (_UINT32_(0x1) << USBHS_HSTIER_DCONNIES_Pos)         /* (USBHS_HSTIER) Device Connection Interrupt Enable Mask */
#define USBHS_HSTIER_DCONNIES(value)          (USBHS_HSTIER_DCONNIES_Msk & (_UINT32_(value) << USBHS_HSTIER_DCONNIES_Pos)) /* Assigment of value for DCONNIES in the USBHS_HSTIER register */
#define USBHS_HSTIER_DDISCIES_Pos             _UINT32_(1)                                          /* (USBHS_HSTIER) Device Disconnection Interrupt Enable Position */
#define USBHS_HSTIER_DDISCIES_Msk             (_UINT32_(0x1) << USBHS_HSTIER_DDISCIES_Pos)         /* (USBHS_HSTIER) Device Disconnection Interrupt Enable Mask */
#define USBHS_HSTIER_DDISCIES(value)          (USBHS_HSTIER_DDISCIES_Msk & (_UINT32_(value) << USBHS_HSTIER_DDISCIES_Pos)) /* Assigment of value for DDISCIES in the USBHS_HSTIER register */
#define USBHS_HSTIER_RSTIES_Pos               _UINT32_(2)                                          /* (USBHS_HSTIER) USB Reset Sent Interrupt Enable Position */
#define USBHS_HSTIER_RSTIES_Msk               (_UINT32_(0x1) << USBHS_HSTIER_RSTIES_Pos)           /* (USBHS_HSTIER) USB Reset Sent Interrupt Enable Mask */
#define USBHS_HSTIER_RSTIES(value)            (USBHS_HSTIER_RSTIES_Msk & (_UINT32_(value) << USBHS_HSTIER_RSTIES_Pos)) /* Assigment of value for RSTIES in the USBHS_HSTIER register */
#define USBHS_HSTIER_RSMEDIES_Pos             _UINT32_(3)                                          /* (USBHS_HSTIER) Downstream Resume Sent Interrupt Enable Position */
#define USBHS_HSTIER_RSMEDIES_Msk             (_UINT32_(0x1) << USBHS_HSTIER_RSMEDIES_Pos)         /* (USBHS_HSTIER) Downstream Resume Sent Interrupt Enable Mask */
#define USBHS_HSTIER_RSMEDIES(value)          (USBHS_HSTIER_RSMEDIES_Msk & (_UINT32_(value) << USBHS_HSTIER_RSMEDIES_Pos)) /* Assigment of value for RSMEDIES in the USBHS_HSTIER register */
#define USBHS_HSTIER_RXRSMIES_Pos             _UINT32_(4)                                          /* (USBHS_HSTIER) Upstream Resume Received Interrupt Enable Position */
#define USBHS_HSTIER_RXRSMIES_Msk             (_UINT32_(0x1) << USBHS_HSTIER_RXRSMIES_Pos)         /* (USBHS_HSTIER) Upstream Resume Received Interrupt Enable Mask */
#define USBHS_HSTIER_RXRSMIES(value)          (USBHS_HSTIER_RXRSMIES_Msk & (_UINT32_(value) << USBHS_HSTIER_RXRSMIES_Pos)) /* Assigment of value for RXRSMIES in the USBHS_HSTIER register */
#define USBHS_HSTIER_HSOFIES_Pos              _UINT32_(5)                                          /* (USBHS_HSTIER) Host Start of Frame Interrupt Enable Position */
#define USBHS_HSTIER_HSOFIES_Msk              (_UINT32_(0x1) << USBHS_HSTIER_HSOFIES_Pos)          /* (USBHS_HSTIER) Host Start of Frame Interrupt Enable Mask */
#define USBHS_HSTIER_HSOFIES(value)           (USBHS_HSTIER_HSOFIES_Msk & (_UINT32_(value) << USBHS_HSTIER_HSOFIES_Pos)) /* Assigment of value for HSOFIES in the USBHS_HSTIER register */
#define USBHS_HSTIER_HWUPIES_Pos              _UINT32_(6)                                          /* (USBHS_HSTIER) Host Wake-Up Interrupt Enable Position */
#define USBHS_HSTIER_HWUPIES_Msk              (_UINT32_(0x1) << USBHS_HSTIER_HWUPIES_Pos)          /* (USBHS_HSTIER) Host Wake-Up Interrupt Enable Mask */
#define USBHS_HSTIER_HWUPIES(value)           (USBHS_HSTIER_HWUPIES_Msk & (_UINT32_(value) << USBHS_HSTIER_HWUPIES_Pos)) /* Assigment of value for HWUPIES in the USBHS_HSTIER register */
#define USBHS_HSTIER_PEP_0_Pos                _UINT32_(8)                                          /* (USBHS_HSTIER) Pipe 0 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_0_Msk                (_UINT32_(0x1) << USBHS_HSTIER_PEP_0_Pos)            /* (USBHS_HSTIER) Pipe 0 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_0(value)             (USBHS_HSTIER_PEP_0_Msk & (_UINT32_(value) << USBHS_HSTIER_PEP_0_Pos)) /* Assigment of value for PEP_0 in the USBHS_HSTIER register */
#define USBHS_HSTIER_PEP_1_Pos                _UINT32_(9)                                          /* (USBHS_HSTIER) Pipe 1 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_1_Msk                (_UINT32_(0x1) << USBHS_HSTIER_PEP_1_Pos)            /* (USBHS_HSTIER) Pipe 1 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_1(value)             (USBHS_HSTIER_PEP_1_Msk & (_UINT32_(value) << USBHS_HSTIER_PEP_1_Pos)) /* Assigment of value for PEP_1 in the USBHS_HSTIER register */
#define USBHS_HSTIER_PEP_2_Pos                _UINT32_(10)                                         /* (USBHS_HSTIER) Pipe 2 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_2_Msk                (_UINT32_(0x1) << USBHS_HSTIER_PEP_2_Pos)            /* (USBHS_HSTIER) Pipe 2 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_2(value)             (USBHS_HSTIER_PEP_2_Msk & (_UINT32_(value) << USBHS_HSTIER_PEP_2_Pos)) /* Assigment of value for PEP_2 in the USBHS_HSTIER register */
#define USBHS_HSTIER_PEP_3_Pos                _UINT32_(11)                                         /* (USBHS_HSTIER) Pipe 3 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_3_Msk                (_UINT32_(0x1) << USBHS_HSTIER_PEP_3_Pos)            /* (USBHS_HSTIER) Pipe 3 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_3(value)             (USBHS_HSTIER_PEP_3_Msk & (_UINT32_(value) << USBHS_HSTIER_PEP_3_Pos)) /* Assigment of value for PEP_3 in the USBHS_HSTIER register */
#define USBHS_HSTIER_PEP_4_Pos                _UINT32_(12)                                         /* (USBHS_HSTIER) Pipe 4 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_4_Msk                (_UINT32_(0x1) << USBHS_HSTIER_PEP_4_Pos)            /* (USBHS_HSTIER) Pipe 4 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_4(value)             (USBHS_HSTIER_PEP_4_Msk & (_UINT32_(value) << USBHS_HSTIER_PEP_4_Pos)) /* Assigment of value for PEP_4 in the USBHS_HSTIER register */
#define USBHS_HSTIER_PEP_5_Pos                _UINT32_(13)                                         /* (USBHS_HSTIER) Pipe 5 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_5_Msk                (_UINT32_(0x1) << USBHS_HSTIER_PEP_5_Pos)            /* (USBHS_HSTIER) Pipe 5 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_5(value)             (USBHS_HSTIER_PEP_5_Msk & (_UINT32_(value) << USBHS_HSTIER_PEP_5_Pos)) /* Assigment of value for PEP_5 in the USBHS_HSTIER register */
#define USBHS_HSTIER_PEP_6_Pos                _UINT32_(14)                                         /* (USBHS_HSTIER) Pipe 6 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_6_Msk                (_UINT32_(0x1) << USBHS_HSTIER_PEP_6_Pos)            /* (USBHS_HSTIER) Pipe 6 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_6(value)             (USBHS_HSTIER_PEP_6_Msk & (_UINT32_(value) << USBHS_HSTIER_PEP_6_Pos)) /* Assigment of value for PEP_6 in the USBHS_HSTIER register */
#define USBHS_HSTIER_PEP_7_Pos                _UINT32_(15)                                         /* (USBHS_HSTIER) Pipe 7 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_7_Msk                (_UINT32_(0x1) << USBHS_HSTIER_PEP_7_Pos)            /* (USBHS_HSTIER) Pipe 7 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_7(value)             (USBHS_HSTIER_PEP_7_Msk & (_UINT32_(value) << USBHS_HSTIER_PEP_7_Pos)) /* Assigment of value for PEP_7 in the USBHS_HSTIER register */
#define USBHS_HSTIER_PEP_8_Pos                _UINT32_(16)                                         /* (USBHS_HSTIER) Pipe 8 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_8_Msk                (_UINT32_(0x1) << USBHS_HSTIER_PEP_8_Pos)            /* (USBHS_HSTIER) Pipe 8 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_8(value)             (USBHS_HSTIER_PEP_8_Msk & (_UINT32_(value) << USBHS_HSTIER_PEP_8_Pos)) /* Assigment of value for PEP_8 in the USBHS_HSTIER register */
#define USBHS_HSTIER_PEP_9_Pos                _UINT32_(17)                                         /* (USBHS_HSTIER) Pipe 9 Interrupt Enable Position */
#define USBHS_HSTIER_PEP_9_Msk                (_UINT32_(0x1) << USBHS_HSTIER_PEP_9_Pos)            /* (USBHS_HSTIER) Pipe 9 Interrupt Enable Mask */
#define USBHS_HSTIER_PEP_9(value)             (USBHS_HSTIER_PEP_9_Msk & (_UINT32_(value) << USBHS_HSTIER_PEP_9_Pos)) /* Assigment of value for PEP_9 in the USBHS_HSTIER register */
#define USBHS_HSTIER_DMA_1_Pos                _UINT32_(25)                                         /* (USBHS_HSTIER) DMA Channel 0 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_1_Msk                (_UINT32_(0x1) << USBHS_HSTIER_DMA_1_Pos)            /* (USBHS_HSTIER) DMA Channel 0 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_1(value)             (USBHS_HSTIER_DMA_1_Msk & (_UINT32_(value) << USBHS_HSTIER_DMA_1_Pos)) /* Assigment of value for DMA_1 in the USBHS_HSTIER register */
#define USBHS_HSTIER_DMA_2_Pos                _UINT32_(26)                                         /* (USBHS_HSTIER) DMA Channel 1 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_2_Msk                (_UINT32_(0x1) << USBHS_HSTIER_DMA_2_Pos)            /* (USBHS_HSTIER) DMA Channel 1 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_2(value)             (USBHS_HSTIER_DMA_2_Msk & (_UINT32_(value) << USBHS_HSTIER_DMA_2_Pos)) /* Assigment of value for DMA_2 in the USBHS_HSTIER register */
#define USBHS_HSTIER_DMA_3_Pos                _UINT32_(27)                                         /* (USBHS_HSTIER) DMA Channel 2 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_3_Msk                (_UINT32_(0x1) << USBHS_HSTIER_DMA_3_Pos)            /* (USBHS_HSTIER) DMA Channel 2 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_3(value)             (USBHS_HSTIER_DMA_3_Msk & (_UINT32_(value) << USBHS_HSTIER_DMA_3_Pos)) /* Assigment of value for DMA_3 in the USBHS_HSTIER register */
#define USBHS_HSTIER_DMA_4_Pos                _UINT32_(28)                                         /* (USBHS_HSTIER) DMA Channel 3 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_4_Msk                (_UINT32_(0x1) << USBHS_HSTIER_DMA_4_Pos)            /* (USBHS_HSTIER) DMA Channel 3 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_4(value)             (USBHS_HSTIER_DMA_4_Msk & (_UINT32_(value) << USBHS_HSTIER_DMA_4_Pos)) /* Assigment of value for DMA_4 in the USBHS_HSTIER register */
#define USBHS_HSTIER_DMA_5_Pos                _UINT32_(29)                                         /* (USBHS_HSTIER) DMA Channel 4 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_5_Msk                (_UINT32_(0x1) << USBHS_HSTIER_DMA_5_Pos)            /* (USBHS_HSTIER) DMA Channel 4 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_5(value)             (USBHS_HSTIER_DMA_5_Msk & (_UINT32_(value) << USBHS_HSTIER_DMA_5_Pos)) /* Assigment of value for DMA_5 in the USBHS_HSTIER register */
#define USBHS_HSTIER_DMA_6_Pos                _UINT32_(30)                                         /* (USBHS_HSTIER) DMA Channel 5 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_6_Msk                (_UINT32_(0x1) << USBHS_HSTIER_DMA_6_Pos)            /* (USBHS_HSTIER) DMA Channel 5 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_6(value)             (USBHS_HSTIER_DMA_6_Msk & (_UINT32_(value) << USBHS_HSTIER_DMA_6_Pos)) /* Assigment of value for DMA_6 in the USBHS_HSTIER register */
#define USBHS_HSTIER_DMA_7_Pos                _UINT32_(31)                                         /* (USBHS_HSTIER) DMA Channel 6 Interrupt Enable Position */
#define USBHS_HSTIER_DMA_7_Msk                (_UINT32_(0x1) << USBHS_HSTIER_DMA_7_Pos)            /* (USBHS_HSTIER) DMA Channel 6 Interrupt Enable Mask */
#define USBHS_HSTIER_DMA_7(value)             (USBHS_HSTIER_DMA_7_Msk & (_UINT32_(value) << USBHS_HSTIER_DMA_7_Pos)) /* Assigment of value for DMA_7 in the USBHS_HSTIER register */
#define USBHS_HSTIER_Msk                      _UINT32_(0xFE03FF7F)                                 /* (USBHS_HSTIER) Register Mask  */

#define USBHS_HSTIER_PEP__Pos                 _UINT32_(8)                                          /* (USBHS_HSTIER Position) Pipe x Interrupt Enable */
#define USBHS_HSTIER_PEP__Msk                 (_UINT32_(0x3FF) << USBHS_HSTIER_PEP__Pos)           /* (USBHS_HSTIER Mask) PEP_ */
#define USBHS_HSTIER_PEP_(value)              (USBHS_HSTIER_PEP__Msk & (_UINT32_(value) << USBHS_HSTIER_PEP__Pos)) 
#define USBHS_HSTIER_DMA__Pos                 _UINT32_(25)                                         /* (USBHS_HSTIER Position) DMA Channel 6 Interrupt Enable */
#define USBHS_HSTIER_DMA__Msk                 (_UINT32_(0x7F) << USBHS_HSTIER_DMA__Pos)            /* (USBHS_HSTIER Mask) DMA_ */
#define USBHS_HSTIER_DMA_(value)              (USBHS_HSTIER_DMA__Msk & (_UINT32_(value) << USBHS_HSTIER_DMA__Pos)) 

/* -------- USBHS_HSTPIP : (USBHS Offset: 0x41C) (R/W 32) Host Pipe Register -------- */
#define USBHS_HSTPIP_PEN0_Pos                 _UINT32_(0)                                          /* (USBHS_HSTPIP) Pipe 0 Enable Position */
#define USBHS_HSTPIP_PEN0_Msk                 (_UINT32_(0x1) << USBHS_HSTPIP_PEN0_Pos)             /* (USBHS_HSTPIP) Pipe 0 Enable Mask */
#define USBHS_HSTPIP_PEN0(value)              (USBHS_HSTPIP_PEN0_Msk & (_UINT32_(value) << USBHS_HSTPIP_PEN0_Pos)) /* Assigment of value for PEN0 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PEN1_Pos                 _UINT32_(1)                                          /* (USBHS_HSTPIP) Pipe 1 Enable Position */
#define USBHS_HSTPIP_PEN1_Msk                 (_UINT32_(0x1) << USBHS_HSTPIP_PEN1_Pos)             /* (USBHS_HSTPIP) Pipe 1 Enable Mask */
#define USBHS_HSTPIP_PEN1(value)              (USBHS_HSTPIP_PEN1_Msk & (_UINT32_(value) << USBHS_HSTPIP_PEN1_Pos)) /* Assigment of value for PEN1 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PEN2_Pos                 _UINT32_(2)                                          /* (USBHS_HSTPIP) Pipe 2 Enable Position */
#define USBHS_HSTPIP_PEN2_Msk                 (_UINT32_(0x1) << USBHS_HSTPIP_PEN2_Pos)             /* (USBHS_HSTPIP) Pipe 2 Enable Mask */
#define USBHS_HSTPIP_PEN2(value)              (USBHS_HSTPIP_PEN2_Msk & (_UINT32_(value) << USBHS_HSTPIP_PEN2_Pos)) /* Assigment of value for PEN2 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PEN3_Pos                 _UINT32_(3)                                          /* (USBHS_HSTPIP) Pipe 3 Enable Position */
#define USBHS_HSTPIP_PEN3_Msk                 (_UINT32_(0x1) << USBHS_HSTPIP_PEN3_Pos)             /* (USBHS_HSTPIP) Pipe 3 Enable Mask */
#define USBHS_HSTPIP_PEN3(value)              (USBHS_HSTPIP_PEN3_Msk & (_UINT32_(value) << USBHS_HSTPIP_PEN3_Pos)) /* Assigment of value for PEN3 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PEN4_Pos                 _UINT32_(4)                                          /* (USBHS_HSTPIP) Pipe 4 Enable Position */
#define USBHS_HSTPIP_PEN4_Msk                 (_UINT32_(0x1) << USBHS_HSTPIP_PEN4_Pos)             /* (USBHS_HSTPIP) Pipe 4 Enable Mask */
#define USBHS_HSTPIP_PEN4(value)              (USBHS_HSTPIP_PEN4_Msk & (_UINT32_(value) << USBHS_HSTPIP_PEN4_Pos)) /* Assigment of value for PEN4 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PEN5_Pos                 _UINT32_(5)                                          /* (USBHS_HSTPIP) Pipe 5 Enable Position */
#define USBHS_HSTPIP_PEN5_Msk                 (_UINT32_(0x1) << USBHS_HSTPIP_PEN5_Pos)             /* (USBHS_HSTPIP) Pipe 5 Enable Mask */
#define USBHS_HSTPIP_PEN5(value)              (USBHS_HSTPIP_PEN5_Msk & (_UINT32_(value) << USBHS_HSTPIP_PEN5_Pos)) /* Assigment of value for PEN5 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PEN6_Pos                 _UINT32_(6)                                          /* (USBHS_HSTPIP) Pipe 6 Enable Position */
#define USBHS_HSTPIP_PEN6_Msk                 (_UINT32_(0x1) << USBHS_HSTPIP_PEN6_Pos)             /* (USBHS_HSTPIP) Pipe 6 Enable Mask */
#define USBHS_HSTPIP_PEN6(value)              (USBHS_HSTPIP_PEN6_Msk & (_UINT32_(value) << USBHS_HSTPIP_PEN6_Pos)) /* Assigment of value for PEN6 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PEN7_Pos                 _UINT32_(7)                                          /* (USBHS_HSTPIP) Pipe 7 Enable Position */
#define USBHS_HSTPIP_PEN7_Msk                 (_UINT32_(0x1) << USBHS_HSTPIP_PEN7_Pos)             /* (USBHS_HSTPIP) Pipe 7 Enable Mask */
#define USBHS_HSTPIP_PEN7(value)              (USBHS_HSTPIP_PEN7_Msk & (_UINT32_(value) << USBHS_HSTPIP_PEN7_Pos)) /* Assigment of value for PEN7 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PEN8_Pos                 _UINT32_(8)                                          /* (USBHS_HSTPIP) Pipe 8 Enable Position */
#define USBHS_HSTPIP_PEN8_Msk                 (_UINT32_(0x1) << USBHS_HSTPIP_PEN8_Pos)             /* (USBHS_HSTPIP) Pipe 8 Enable Mask */
#define USBHS_HSTPIP_PEN8(value)              (USBHS_HSTPIP_PEN8_Msk & (_UINT32_(value) << USBHS_HSTPIP_PEN8_Pos)) /* Assigment of value for PEN8 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PRST0_Pos                _UINT32_(16)                                         /* (USBHS_HSTPIP) Pipe 0 Reset Position */
#define USBHS_HSTPIP_PRST0_Msk                (_UINT32_(0x1) << USBHS_HSTPIP_PRST0_Pos)            /* (USBHS_HSTPIP) Pipe 0 Reset Mask */
#define USBHS_HSTPIP_PRST0(value)             (USBHS_HSTPIP_PRST0_Msk & (_UINT32_(value) << USBHS_HSTPIP_PRST0_Pos)) /* Assigment of value for PRST0 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PRST1_Pos                _UINT32_(17)                                         /* (USBHS_HSTPIP) Pipe 1 Reset Position */
#define USBHS_HSTPIP_PRST1_Msk                (_UINT32_(0x1) << USBHS_HSTPIP_PRST1_Pos)            /* (USBHS_HSTPIP) Pipe 1 Reset Mask */
#define USBHS_HSTPIP_PRST1(value)             (USBHS_HSTPIP_PRST1_Msk & (_UINT32_(value) << USBHS_HSTPIP_PRST1_Pos)) /* Assigment of value for PRST1 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PRST2_Pos                _UINT32_(18)                                         /* (USBHS_HSTPIP) Pipe 2 Reset Position */
#define USBHS_HSTPIP_PRST2_Msk                (_UINT32_(0x1) << USBHS_HSTPIP_PRST2_Pos)            /* (USBHS_HSTPIP) Pipe 2 Reset Mask */
#define USBHS_HSTPIP_PRST2(value)             (USBHS_HSTPIP_PRST2_Msk & (_UINT32_(value) << USBHS_HSTPIP_PRST2_Pos)) /* Assigment of value for PRST2 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PRST3_Pos                _UINT32_(19)                                         /* (USBHS_HSTPIP) Pipe 3 Reset Position */
#define USBHS_HSTPIP_PRST3_Msk                (_UINT32_(0x1) << USBHS_HSTPIP_PRST3_Pos)            /* (USBHS_HSTPIP) Pipe 3 Reset Mask */
#define USBHS_HSTPIP_PRST3(value)             (USBHS_HSTPIP_PRST3_Msk & (_UINT32_(value) << USBHS_HSTPIP_PRST3_Pos)) /* Assigment of value for PRST3 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PRST4_Pos                _UINT32_(20)                                         /* (USBHS_HSTPIP) Pipe 4 Reset Position */
#define USBHS_HSTPIP_PRST4_Msk                (_UINT32_(0x1) << USBHS_HSTPIP_PRST4_Pos)            /* (USBHS_HSTPIP) Pipe 4 Reset Mask */
#define USBHS_HSTPIP_PRST4(value)             (USBHS_HSTPIP_PRST4_Msk & (_UINT32_(value) << USBHS_HSTPIP_PRST4_Pos)) /* Assigment of value for PRST4 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PRST5_Pos                _UINT32_(21)                                         /* (USBHS_HSTPIP) Pipe 5 Reset Position */
#define USBHS_HSTPIP_PRST5_Msk                (_UINT32_(0x1) << USBHS_HSTPIP_PRST5_Pos)            /* (USBHS_HSTPIP) Pipe 5 Reset Mask */
#define USBHS_HSTPIP_PRST5(value)             (USBHS_HSTPIP_PRST5_Msk & (_UINT32_(value) << USBHS_HSTPIP_PRST5_Pos)) /* Assigment of value for PRST5 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PRST6_Pos                _UINT32_(22)                                         /* (USBHS_HSTPIP) Pipe 6 Reset Position */
#define USBHS_HSTPIP_PRST6_Msk                (_UINT32_(0x1) << USBHS_HSTPIP_PRST6_Pos)            /* (USBHS_HSTPIP) Pipe 6 Reset Mask */
#define USBHS_HSTPIP_PRST6(value)             (USBHS_HSTPIP_PRST6_Msk & (_UINT32_(value) << USBHS_HSTPIP_PRST6_Pos)) /* Assigment of value for PRST6 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PRST7_Pos                _UINT32_(23)                                         /* (USBHS_HSTPIP) Pipe 7 Reset Position */
#define USBHS_HSTPIP_PRST7_Msk                (_UINT32_(0x1) << USBHS_HSTPIP_PRST7_Pos)            /* (USBHS_HSTPIP) Pipe 7 Reset Mask */
#define USBHS_HSTPIP_PRST7(value)             (USBHS_HSTPIP_PRST7_Msk & (_UINT32_(value) << USBHS_HSTPIP_PRST7_Pos)) /* Assigment of value for PRST7 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_PRST8_Pos                _UINT32_(24)                                         /* (USBHS_HSTPIP) Pipe 8 Reset Position */
#define USBHS_HSTPIP_PRST8_Msk                (_UINT32_(0x1) << USBHS_HSTPIP_PRST8_Pos)            /* (USBHS_HSTPIP) Pipe 8 Reset Mask */
#define USBHS_HSTPIP_PRST8(value)             (USBHS_HSTPIP_PRST8_Msk & (_UINT32_(value) << USBHS_HSTPIP_PRST8_Pos)) /* Assigment of value for PRST8 in the USBHS_HSTPIP register */
#define USBHS_HSTPIP_Msk                      _UINT32_(0x01FF01FF)                                 /* (USBHS_HSTPIP) Register Mask  */

#define USBHS_HSTPIP_PEN_Pos                  _UINT32_(0)                                          /* (USBHS_HSTPIP Position) Pipe x Enable */
#define USBHS_HSTPIP_PEN_Msk                  (_UINT32_(0x1FF) << USBHS_HSTPIP_PEN_Pos)            /* (USBHS_HSTPIP Mask) PEN */
#define USBHS_HSTPIP_PEN(value)               (USBHS_HSTPIP_PEN_Msk & (_UINT32_(value) << USBHS_HSTPIP_PEN_Pos)) 
#define USBHS_HSTPIP_PRST_Pos                 _UINT32_(16)                                         /* (USBHS_HSTPIP Position) Pipe 8 Reset */
#define USBHS_HSTPIP_PRST_Msk                 (_UINT32_(0x1FF) << USBHS_HSTPIP_PRST_Pos)           /* (USBHS_HSTPIP Mask) PRST */
#define USBHS_HSTPIP_PRST(value)              (USBHS_HSTPIP_PRST_Msk & (_UINT32_(value) << USBHS_HSTPIP_PRST_Pos)) 

/* -------- USBHS_HSTFNUM : (USBHS Offset: 0x420) (R/W 32) Host Frame Number Register -------- */
#define USBHS_HSTFNUM_MFNUM_Pos               _UINT32_(0)                                          /* (USBHS_HSTFNUM) Micro Frame Number Position */
#define USBHS_HSTFNUM_MFNUM_Msk               (_UINT32_(0x7) << USBHS_HSTFNUM_MFNUM_Pos)           /* (USBHS_HSTFNUM) Micro Frame Number Mask */
#define USBHS_HSTFNUM_MFNUM(value)            (USBHS_HSTFNUM_MFNUM_Msk & (_UINT32_(value) << USBHS_HSTFNUM_MFNUM_Pos)) /* Assigment of value for MFNUM in the USBHS_HSTFNUM register */
#define USBHS_HSTFNUM_FNUM_Pos                _UINT32_(3)                                          /* (USBHS_HSTFNUM) Frame Number Position */
#define USBHS_HSTFNUM_FNUM_Msk                (_UINT32_(0x7FF) << USBHS_HSTFNUM_FNUM_Pos)          /* (USBHS_HSTFNUM) Frame Number Mask */
#define USBHS_HSTFNUM_FNUM(value)             (USBHS_HSTFNUM_FNUM_Msk & (_UINT32_(value) << USBHS_HSTFNUM_FNUM_Pos)) /* Assigment of value for FNUM in the USBHS_HSTFNUM register */
#define USBHS_HSTFNUM_FLENHIGH_Pos            _UINT32_(16)                                         /* (USBHS_HSTFNUM) Frame Length Position */
#define USBHS_HSTFNUM_FLENHIGH_Msk            (_UINT32_(0xFF) << USBHS_HSTFNUM_FLENHIGH_Pos)       /* (USBHS_HSTFNUM) Frame Length Mask */
#define USBHS_HSTFNUM_FLENHIGH(value)         (USBHS_HSTFNUM_FLENHIGH_Msk & (_UINT32_(value) << USBHS_HSTFNUM_FLENHIGH_Pos)) /* Assigment of value for FLENHIGH in the USBHS_HSTFNUM register */
#define USBHS_HSTFNUM_Msk                     _UINT32_(0x00FF3FFF)                                 /* (USBHS_HSTFNUM) Register Mask  */


/* -------- USBHS_HSTADDR1 : (USBHS Offset: 0x424) (R/W 32) Host Address 1 Register -------- */
#define USBHS_HSTADDR1_HSTADDRP0_Pos          _UINT32_(0)                                          /* (USBHS_HSTADDR1) USB Host Address Position */
#define USBHS_HSTADDR1_HSTADDRP0_Msk          (_UINT32_(0x7F) << USBHS_HSTADDR1_HSTADDRP0_Pos)     /* (USBHS_HSTADDR1) USB Host Address Mask */
#define USBHS_HSTADDR1_HSTADDRP0(value)       (USBHS_HSTADDR1_HSTADDRP0_Msk & (_UINT32_(value) << USBHS_HSTADDR1_HSTADDRP0_Pos)) /* Assigment of value for HSTADDRP0 in the USBHS_HSTADDR1 register */
#define USBHS_HSTADDR1_HSTADDRP1_Pos          _UINT32_(8)                                          /* (USBHS_HSTADDR1) USB Host Address Position */
#define USBHS_HSTADDR1_HSTADDRP1_Msk          (_UINT32_(0x7F) << USBHS_HSTADDR1_HSTADDRP1_Pos)     /* (USBHS_HSTADDR1) USB Host Address Mask */
#define USBHS_HSTADDR1_HSTADDRP1(value)       (USBHS_HSTADDR1_HSTADDRP1_Msk & (_UINT32_(value) << USBHS_HSTADDR1_HSTADDRP1_Pos)) /* Assigment of value for HSTADDRP1 in the USBHS_HSTADDR1 register */
#define USBHS_HSTADDR1_HSTADDRP2_Pos          _UINT32_(16)                                         /* (USBHS_HSTADDR1) USB Host Address Position */
#define USBHS_HSTADDR1_HSTADDRP2_Msk          (_UINT32_(0x7F) << USBHS_HSTADDR1_HSTADDRP2_Pos)     /* (USBHS_HSTADDR1) USB Host Address Mask */
#define USBHS_HSTADDR1_HSTADDRP2(value)       (USBHS_HSTADDR1_HSTADDRP2_Msk & (_UINT32_(value) << USBHS_HSTADDR1_HSTADDRP2_Pos)) /* Assigment of value for HSTADDRP2 in the USBHS_HSTADDR1 register */
#define USBHS_HSTADDR1_HSTADDRP3_Pos          _UINT32_(24)                                         /* (USBHS_HSTADDR1) USB Host Address Position */
#define USBHS_HSTADDR1_HSTADDRP3_Msk          (_UINT32_(0x7F) << USBHS_HSTADDR1_HSTADDRP3_Pos)     /* (USBHS_HSTADDR1) USB Host Address Mask */
#define USBHS_HSTADDR1_HSTADDRP3(value)       (USBHS_HSTADDR1_HSTADDRP3_Msk & (_UINT32_(value) << USBHS_HSTADDR1_HSTADDRP3_Pos)) /* Assigment of value for HSTADDRP3 in the USBHS_HSTADDR1 register */
#define USBHS_HSTADDR1_Msk                    _UINT32_(0x7F7F7F7F)                                 /* (USBHS_HSTADDR1) Register Mask  */


/* -------- USBHS_HSTADDR2 : (USBHS Offset: 0x428) (R/W 32) Host Address 2 Register -------- */
#define USBHS_HSTADDR2_HSTADDRP4_Pos          _UINT32_(0)                                          /* (USBHS_HSTADDR2) USB Host Address Position */
#define USBHS_HSTADDR2_HSTADDRP4_Msk          (_UINT32_(0x7F) << USBHS_HSTADDR2_HSTADDRP4_Pos)     /* (USBHS_HSTADDR2) USB Host Address Mask */
#define USBHS_HSTADDR2_HSTADDRP4(value)       (USBHS_HSTADDR2_HSTADDRP4_Msk & (_UINT32_(value) << USBHS_HSTADDR2_HSTADDRP4_Pos)) /* Assigment of value for HSTADDRP4 in the USBHS_HSTADDR2 register */
#define USBHS_HSTADDR2_HSTADDRP5_Pos          _UINT32_(8)                                          /* (USBHS_HSTADDR2) USB Host Address Position */
#define USBHS_HSTADDR2_HSTADDRP5_Msk          (_UINT32_(0x7F) << USBHS_HSTADDR2_HSTADDRP5_Pos)     /* (USBHS_HSTADDR2) USB Host Address Mask */
#define USBHS_HSTADDR2_HSTADDRP5(value)       (USBHS_HSTADDR2_HSTADDRP5_Msk & (_UINT32_(value) << USBHS_HSTADDR2_HSTADDRP5_Pos)) /* Assigment of value for HSTADDRP5 in the USBHS_HSTADDR2 register */
#define USBHS_HSTADDR2_HSTADDRP6_Pos          _UINT32_(16)                                         /* (USBHS_HSTADDR2) USB Host Address Position */
#define USBHS_HSTADDR2_HSTADDRP6_Msk          (_UINT32_(0x7F) << USBHS_HSTADDR2_HSTADDRP6_Pos)     /* (USBHS_HSTADDR2) USB Host Address Mask */
#define USBHS_HSTADDR2_HSTADDRP6(value)       (USBHS_HSTADDR2_HSTADDRP6_Msk & (_UINT32_(value) << USBHS_HSTADDR2_HSTADDRP6_Pos)) /* Assigment of value for HSTADDRP6 in the USBHS_HSTADDR2 register */
#define USBHS_HSTADDR2_HSTADDRP7_Pos          _UINT32_(24)                                         /* (USBHS_HSTADDR2) USB Host Address Position */
#define USBHS_HSTADDR2_HSTADDRP7_Msk          (_UINT32_(0x7F) << USBHS_HSTADDR2_HSTADDRP7_Pos)     /* (USBHS_HSTADDR2) USB Host Address Mask */
#define USBHS_HSTADDR2_HSTADDRP7(value)       (USBHS_HSTADDR2_HSTADDRP7_Msk & (_UINT32_(value) << USBHS_HSTADDR2_HSTADDRP7_Pos)) /* Assigment of value for HSTADDRP7 in the USBHS_HSTADDR2 register */
#define USBHS_HSTADDR2_Msk                    _UINT32_(0x7F7F7F7F)                                 /* (USBHS_HSTADDR2) Register Mask  */


/* -------- USBHS_HSTADDR3 : (USBHS Offset: 0x42C) (R/W 32) Host Address 3 Register -------- */
#define USBHS_HSTADDR3_HSTADDRP8_Pos          _UINT32_(0)                                          /* (USBHS_HSTADDR3) USB Host Address Position */
#define USBHS_HSTADDR3_HSTADDRP8_Msk          (_UINT32_(0x7F) << USBHS_HSTADDR3_HSTADDRP8_Pos)     /* (USBHS_HSTADDR3) USB Host Address Mask */
#define USBHS_HSTADDR3_HSTADDRP8(value)       (USBHS_HSTADDR3_HSTADDRP8_Msk & (_UINT32_(value) << USBHS_HSTADDR3_HSTADDRP8_Pos)) /* Assigment of value for HSTADDRP8 in the USBHS_HSTADDR3 register */
#define USBHS_HSTADDR3_HSTADDRP9_Pos          _UINT32_(8)                                          /* (USBHS_HSTADDR3) USB Host Address Position */
#define USBHS_HSTADDR3_HSTADDRP9_Msk          (_UINT32_(0x7F) << USBHS_HSTADDR3_HSTADDRP9_Pos)     /* (USBHS_HSTADDR3) USB Host Address Mask */
#define USBHS_HSTADDR3_HSTADDRP9(value)       (USBHS_HSTADDR3_HSTADDRP9_Msk & (_UINT32_(value) << USBHS_HSTADDR3_HSTADDRP9_Pos)) /* Assigment of value for HSTADDRP9 in the USBHS_HSTADDR3 register */
#define USBHS_HSTADDR3_Msk                    _UINT32_(0x00007F7F)                                 /* (USBHS_HSTADDR3) Register Mask  */


/* -------- USBHS_HSTPIPCFG : (USBHS Offset: 0x500) (R/W 32) Host Pipe Configuration Register -------- */
#define USBHS_HSTPIPCFG_ALLOC_Pos             _UINT32_(1)                                          /* (USBHS_HSTPIPCFG) Pipe Memory Allocate Position */
#define USBHS_HSTPIPCFG_ALLOC_Msk             (_UINT32_(0x1) << USBHS_HSTPIPCFG_ALLOC_Pos)         /* (USBHS_HSTPIPCFG) Pipe Memory Allocate Mask */
#define USBHS_HSTPIPCFG_ALLOC(value)          (USBHS_HSTPIPCFG_ALLOC_Msk & (_UINT32_(value) << USBHS_HSTPIPCFG_ALLOC_Pos)) /* Assigment of value for ALLOC in the USBHS_HSTPIPCFG register */
#define USBHS_HSTPIPCFG_PBK_Pos               _UINT32_(2)                                          /* (USBHS_HSTPIPCFG) Pipe Banks Position */
#define USBHS_HSTPIPCFG_PBK_Msk               (_UINT32_(0x3) << USBHS_HSTPIPCFG_PBK_Pos)           /* (USBHS_HSTPIPCFG) Pipe Banks Mask */
#define USBHS_HSTPIPCFG_PBK(value)            (USBHS_HSTPIPCFG_PBK_Msk & (_UINT32_(value) << USBHS_HSTPIPCFG_PBK_Pos)) /* Assigment of value for PBK in the USBHS_HSTPIPCFG register */
#define   USBHS_HSTPIPCFG_PBK_1_BANK_Val      _UINT32_(0x0)                                        /* (USBHS_HSTPIPCFG) Single-bank pipe  */
#define   USBHS_HSTPIPCFG_PBK_2_BANK_Val      _UINT32_(0x1)                                        /* (USBHS_HSTPIPCFG) Double-bank pipe  */
#define   USBHS_HSTPIPCFG_PBK_3_BANK_Val      _UINT32_(0x2)                                        /* (USBHS_HSTPIPCFG) Triple-bank pipe  */
#define USBHS_HSTPIPCFG_PBK_1_BANK            (USBHS_HSTPIPCFG_PBK_1_BANK_Val << USBHS_HSTPIPCFG_PBK_Pos) /* (USBHS_HSTPIPCFG) Single-bank pipe Position  */
#define USBHS_HSTPIPCFG_PBK_2_BANK            (USBHS_HSTPIPCFG_PBK_2_BANK_Val << USBHS_HSTPIPCFG_PBK_Pos) /* (USBHS_HSTPIPCFG) Double-bank pipe Position  */
#define USBHS_HSTPIPCFG_PBK_3_BANK            (USBHS_HSTPIPCFG_PBK_3_BANK_Val << USBHS_HSTPIPCFG_PBK_Pos) /* (USBHS_HSTPIPCFG) Triple-bank pipe Position  */
#define USBHS_HSTPIPCFG_PSIZE_Pos             _UINT32_(4)                                          /* (USBHS_HSTPIPCFG) Pipe Size Position */
#define USBHS_HSTPIPCFG_PSIZE_Msk             (_UINT32_(0x7) << USBHS_HSTPIPCFG_PSIZE_Pos)         /* (USBHS_HSTPIPCFG) Pipe Size Mask */
#define USBHS_HSTPIPCFG_PSIZE(value)          (USBHS_HSTPIPCFG_PSIZE_Msk & (_UINT32_(value) << USBHS_HSTPIPCFG_PSIZE_Pos)) /* Assigment of value for PSIZE in the USBHS_HSTPIPCFG register */
#define   USBHS_HSTPIPCFG_PSIZE_8_BYTE_Val    _UINT32_(0x0)                                        /* (USBHS_HSTPIPCFG) 8 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_16_BYTE_Val   _UINT32_(0x1)                                        /* (USBHS_HSTPIPCFG) 16 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_32_BYTE_Val   _UINT32_(0x2)                                        /* (USBHS_HSTPIPCFG) 32 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_64_BYTE_Val   _UINT32_(0x3)                                        /* (USBHS_HSTPIPCFG) 64 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_128_BYTE_Val  _UINT32_(0x4)                                        /* (USBHS_HSTPIPCFG) 128 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_256_BYTE_Val  _UINT32_(0x5)                                        /* (USBHS_HSTPIPCFG) 256 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_512_BYTE_Val  _UINT32_(0x6)                                        /* (USBHS_HSTPIPCFG) 512 bytes  */
#define   USBHS_HSTPIPCFG_PSIZE_1024_BYTE_Val _UINT32_(0x7)                                        /* (USBHS_HSTPIPCFG) 1024 bytes  */
#define USBHS_HSTPIPCFG_PSIZE_8_BYTE          (USBHS_HSTPIPCFG_PSIZE_8_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos) /* (USBHS_HSTPIPCFG) 8 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_16_BYTE         (USBHS_HSTPIPCFG_PSIZE_16_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos) /* (USBHS_HSTPIPCFG) 16 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_32_BYTE         (USBHS_HSTPIPCFG_PSIZE_32_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos) /* (USBHS_HSTPIPCFG) 32 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_64_BYTE         (USBHS_HSTPIPCFG_PSIZE_64_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos) /* (USBHS_HSTPIPCFG) 64 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_128_BYTE        (USBHS_HSTPIPCFG_PSIZE_128_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos) /* (USBHS_HSTPIPCFG) 128 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_256_BYTE        (USBHS_HSTPIPCFG_PSIZE_256_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos) /* (USBHS_HSTPIPCFG) 256 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_512_BYTE        (USBHS_HSTPIPCFG_PSIZE_512_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos) /* (USBHS_HSTPIPCFG) 512 bytes Position  */
#define USBHS_HSTPIPCFG_PSIZE_1024_BYTE       (USBHS_HSTPIPCFG_PSIZE_1024_BYTE_Val << USBHS_HSTPIPCFG_PSIZE_Pos) /* (USBHS_HSTPIPCFG) 1024 bytes Position  */
#define USBHS_HSTPIPCFG_PTOKEN_Pos            _UINT32_(8)                                          /* (USBHS_HSTPIPCFG) Pipe Token Position */
#define USBHS_HSTPIPCFG_PTOKEN_Msk            (_UINT32_(0x3) << USBHS_HSTPIPCFG_PTOKEN_Pos)        /* (USBHS_HSTPIPCFG) Pipe Token Mask */
#define USBHS_HSTPIPCFG_PTOKEN(value)         (USBHS_HSTPIPCFG_PTOKEN_Msk & (_UINT32_(value) << USBHS_HSTPIPCFG_PTOKEN_Pos)) /* Assigment of value for PTOKEN in the USBHS_HSTPIPCFG register */
#define   USBHS_HSTPIPCFG_PTOKEN_SETUP_Val    _UINT32_(0x0)                                        /* (USBHS_HSTPIPCFG) SETUP  */
#define   USBHS_HSTPIPCFG_PTOKEN_IN_Val       _UINT32_(0x1)                                        /* (USBHS_HSTPIPCFG) IN  */
#define   USBHS_HSTPIPCFG_PTOKEN_OUT_Val      _UINT32_(0x2)                                        /* (USBHS_HSTPIPCFG) OUT  */
#define USBHS_HSTPIPCFG_PTOKEN_SETUP          (USBHS_HSTPIPCFG_PTOKEN_SETUP_Val << USBHS_HSTPIPCFG_PTOKEN_Pos) /* (USBHS_HSTPIPCFG) SETUP Position  */
#define USBHS_HSTPIPCFG_PTOKEN_IN             (USBHS_HSTPIPCFG_PTOKEN_IN_Val << USBHS_HSTPIPCFG_PTOKEN_Pos) /* (USBHS_HSTPIPCFG) IN Position  */
#define USBHS_HSTPIPCFG_PTOKEN_OUT            (USBHS_HSTPIPCFG_PTOKEN_OUT_Val << USBHS_HSTPIPCFG_PTOKEN_Pos) /* (USBHS_HSTPIPCFG) OUT Position  */
#define USBHS_HSTPIPCFG_AUTOSW_Pos            _UINT32_(10)                                         /* (USBHS_HSTPIPCFG) Automatic Switch Position */
#define USBHS_HSTPIPCFG_AUTOSW_Msk            (_UINT32_(0x1) << USBHS_HSTPIPCFG_AUTOSW_Pos)        /* (USBHS_HSTPIPCFG) Automatic Switch Mask */
#define USBHS_HSTPIPCFG_AUTOSW(value)         (USBHS_HSTPIPCFG_AUTOSW_Msk & (_UINT32_(value) << USBHS_HSTPIPCFG_AUTOSW_Pos)) /* Assigment of value for AUTOSW in the USBHS_HSTPIPCFG register */
#define USBHS_HSTPIPCFG_PTYPE_Pos             _UINT32_(12)                                         /* (USBHS_HSTPIPCFG) Pipe Type Position */
#define USBHS_HSTPIPCFG_PTYPE_Msk             (_UINT32_(0x3) << USBHS_HSTPIPCFG_PTYPE_Pos)         /* (USBHS_HSTPIPCFG) Pipe Type Mask */
#define USBHS_HSTPIPCFG_PTYPE(value)          (USBHS_HSTPIPCFG_PTYPE_Msk & (_UINT32_(value) << USBHS_HSTPIPCFG_PTYPE_Pos)) /* Assigment of value for PTYPE in the USBHS_HSTPIPCFG register */
#define   USBHS_HSTPIPCFG_PTYPE_CTRL_Val      _UINT32_(0x0)                                        /* (USBHS_HSTPIPCFG) Control  */
#define   USBHS_HSTPIPCFG_PTYPE_ISO_Val       _UINT32_(0x1)                                        /* (USBHS_HSTPIPCFG) Isochronous  */
#define   USBHS_HSTPIPCFG_PTYPE_BLK_Val       _UINT32_(0x2)                                        /* (USBHS_HSTPIPCFG) Bulk  */
#define   USBHS_HSTPIPCFG_PTYPE_INTRPT_Val    _UINT32_(0x3)                                        /* (USBHS_HSTPIPCFG) Interrupt  */
#define USBHS_HSTPIPCFG_PTYPE_CTRL            (USBHS_HSTPIPCFG_PTYPE_CTRL_Val << USBHS_HSTPIPCFG_PTYPE_Pos) /* (USBHS_HSTPIPCFG) Control Position  */
#define USBHS_HSTPIPCFG_PTYPE_ISO             (USBHS_HSTPIPCFG_PTYPE_ISO_Val << USBHS_HSTPIPCFG_PTYPE_Pos) /* (USBHS_HSTPIPCFG) Isochronous Position  */
#define USBHS_HSTPIPCFG_PTYPE_BLK             (USBHS_HSTPIPCFG_PTYPE_BLK_Val << USBHS_HSTPIPCFG_PTYPE_Pos) /* (USBHS_HSTPIPCFG) Bulk Position  */
#define USBHS_HSTPIPCFG_PTYPE_INTRPT          (USBHS_HSTPIPCFG_PTYPE_INTRPT_Val << USBHS_HSTPIPCFG_PTYPE_Pos) /* (USBHS_HSTPIPCFG) Interrupt Position  */
#define USBHS_HSTPIPCFG_PEPNUM_Pos            _UINT32_(16)                                         /* (USBHS_HSTPIPCFG) Pipe Endpoint Number Position */
#define USBHS_HSTPIPCFG_PEPNUM_Msk            (_UINT32_(0xF) << USBHS_HSTPIPCFG_PEPNUM_Pos)        /* (USBHS_HSTPIPCFG) Pipe Endpoint Number Mask */
#define USBHS_HSTPIPCFG_PEPNUM(value)         (USBHS_HSTPIPCFG_PEPNUM_Msk & (_UINT32_(value) << USBHS_HSTPIPCFG_PEPNUM_Pos)) /* Assigment of value for PEPNUM in the USBHS_HSTPIPCFG register */
#define USBHS_HSTPIPCFG_INTFRQ_Pos            _UINT32_(24)                                         /* (USBHS_HSTPIPCFG) Pipe Interrupt Request Frequency Position */
#define USBHS_HSTPIPCFG_INTFRQ_Msk            (_UINT32_(0xFF) << USBHS_HSTPIPCFG_INTFRQ_Pos)       /* (USBHS_HSTPIPCFG) Pipe Interrupt Request Frequency Mask */
#define USBHS_HSTPIPCFG_INTFRQ(value)         (USBHS_HSTPIPCFG_INTFRQ_Msk & (_UINT32_(value) << USBHS_HSTPIPCFG_INTFRQ_Pos)) /* Assigment of value for INTFRQ in the USBHS_HSTPIPCFG register */
#define USBHS_HSTPIPCFG_Msk                   _UINT32_(0xFF0F377E)                                 /* (USBHS_HSTPIPCFG) Register Mask  */

/* CTRL_BULK mode */
#define USBHS_HSTPIPCFG_CTRL_BULK_PINGEN_Pos  _UINT32_(20)                                         /* (USBHS_HSTPIPCFG) Ping Enable Position */
#define USBHS_HSTPIPCFG_CTRL_BULK_PINGEN_Msk  (_UINT32_(0x1) << USBHS_HSTPIPCFG_CTRL_BULK_PINGEN_Pos) /* (USBHS_HSTPIPCFG) Ping Enable Mask */
#define USBHS_HSTPIPCFG_CTRL_BULK_PINGEN(value) (USBHS_HSTPIPCFG_CTRL_BULK_PINGEN_Msk & (_UINT32_(value) << USBHS_HSTPIPCFG_CTRL_BULK_PINGEN_Pos))
#define USBHS_HSTPIPCFG_CTRL_BULK_BINTERVAL_Pos _UINT32_(24)                                         /* (USBHS_HSTPIPCFG) bInterval Parameter for the Bulk-Out/Ping Transaction Position */
#define USBHS_HSTPIPCFG_CTRL_BULK_BINTERVAL_Msk (_UINT32_(0xFF) << USBHS_HSTPIPCFG_CTRL_BULK_BINTERVAL_Pos) /* (USBHS_HSTPIPCFG) bInterval Parameter for the Bulk-Out/Ping Transaction Mask */
#define USBHS_HSTPIPCFG_CTRL_BULK_BINTERVAL(value) (USBHS_HSTPIPCFG_CTRL_BULK_BINTERVAL_Msk & (_UINT32_(value) << USBHS_HSTPIPCFG_CTRL_BULK_BINTERVAL_Pos))
#define USBHS_HSTPIPCFG_CTRL_BULK_Msk         _UINT32_(0xFF100000)                                  /* (USBHS_HSTPIPCFG_CTRL_BULK) Register Mask  */


/* -------- USBHS_HSTPIPISR : (USBHS Offset: 0x530) ( R/ 32) Host Pipe Status Register -------- */
#define USBHS_HSTPIPISR_RXINI_Pos             _UINT32_(0)                                          /* (USBHS_HSTPIPISR) Received IN Data Interrupt Position */
#define USBHS_HSTPIPISR_RXINI_Msk             (_UINT32_(0x1) << USBHS_HSTPIPISR_RXINI_Pos)         /* (USBHS_HSTPIPISR) Received IN Data Interrupt Mask */
#define USBHS_HSTPIPISR_RXINI(value)          (USBHS_HSTPIPISR_RXINI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_RXINI_Pos)) /* Assigment of value for RXINI in the USBHS_HSTPIPISR register */
#define USBHS_HSTPIPISR_TXOUTI_Pos            _UINT32_(1)                                          /* (USBHS_HSTPIPISR) Transmitted OUT Data Interrupt Position */
#define USBHS_HSTPIPISR_TXOUTI_Msk            (_UINT32_(0x1) << USBHS_HSTPIPISR_TXOUTI_Pos)        /* (USBHS_HSTPIPISR) Transmitted OUT Data Interrupt Mask */
#define USBHS_HSTPIPISR_TXOUTI(value)         (USBHS_HSTPIPISR_TXOUTI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_TXOUTI_Pos)) /* Assigment of value for TXOUTI in the USBHS_HSTPIPISR register */
#define USBHS_HSTPIPISR_PERRI_Pos             _UINT32_(3)                                          /* (USBHS_HSTPIPISR) Pipe Error Interrupt Position */
#define USBHS_HSTPIPISR_PERRI_Msk             (_UINT32_(0x1) << USBHS_HSTPIPISR_PERRI_Pos)         /* (USBHS_HSTPIPISR) Pipe Error Interrupt Mask */
#define USBHS_HSTPIPISR_PERRI(value)          (USBHS_HSTPIPISR_PERRI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_PERRI_Pos)) /* Assigment of value for PERRI in the USBHS_HSTPIPISR register */
#define USBHS_HSTPIPISR_NAKEDI_Pos            _UINT32_(4)                                          /* (USBHS_HSTPIPISR) NAKed Interrupt Position */
#define USBHS_HSTPIPISR_NAKEDI_Msk            (_UINT32_(0x1) << USBHS_HSTPIPISR_NAKEDI_Pos)        /* (USBHS_HSTPIPISR) NAKed Interrupt Mask */
#define USBHS_HSTPIPISR_NAKEDI(value)         (USBHS_HSTPIPISR_NAKEDI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_NAKEDI_Pos)) /* Assigment of value for NAKEDI in the USBHS_HSTPIPISR register */
#define USBHS_HSTPIPISR_OVERFI_Pos            _UINT32_(5)                                          /* (USBHS_HSTPIPISR) Overflow Interrupt Position */
#define USBHS_HSTPIPISR_OVERFI_Msk            (_UINT32_(0x1) << USBHS_HSTPIPISR_OVERFI_Pos)        /* (USBHS_HSTPIPISR) Overflow Interrupt Mask */
#define USBHS_HSTPIPISR_OVERFI(value)         (USBHS_HSTPIPISR_OVERFI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_OVERFI_Pos)) /* Assigment of value for OVERFI in the USBHS_HSTPIPISR register */
#define USBHS_HSTPIPISR_SHORTPACKETI_Pos      _UINT32_(7)                                          /* (USBHS_HSTPIPISR) Short Packet Interrupt Position */
#define USBHS_HSTPIPISR_SHORTPACKETI_Msk      (_UINT32_(0x1) << USBHS_HSTPIPISR_SHORTPACKETI_Pos)  /* (USBHS_HSTPIPISR) Short Packet Interrupt Mask */
#define USBHS_HSTPIPISR_SHORTPACKETI(value)   (USBHS_HSTPIPISR_SHORTPACKETI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_SHORTPACKETI_Pos)) /* Assigment of value for SHORTPACKETI in the USBHS_HSTPIPISR register */
#define USBHS_HSTPIPISR_DTSEQ_Pos             _UINT32_(8)                                          /* (USBHS_HSTPIPISR) Data Toggle Sequence Position */
#define USBHS_HSTPIPISR_DTSEQ_Msk             (_UINT32_(0x3) << USBHS_HSTPIPISR_DTSEQ_Pos)         /* (USBHS_HSTPIPISR) Data Toggle Sequence Mask */
#define USBHS_HSTPIPISR_DTSEQ(value)          (USBHS_HSTPIPISR_DTSEQ_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_DTSEQ_Pos)) /* Assigment of value for DTSEQ in the USBHS_HSTPIPISR register */
#define   USBHS_HSTPIPISR_DTSEQ_DATA0_Val     _UINT32_(0x0)                                        /* (USBHS_HSTPIPISR) Data0 toggle sequence  */
#define   USBHS_HSTPIPISR_DTSEQ_DATA1_Val     _UINT32_(0x1)                                        /* (USBHS_HSTPIPISR) Data1 toggle sequence  */
#define USBHS_HSTPIPISR_DTSEQ_DATA0           (USBHS_HSTPIPISR_DTSEQ_DATA0_Val << USBHS_HSTPIPISR_DTSEQ_Pos) /* (USBHS_HSTPIPISR) Data0 toggle sequence Position  */
#define USBHS_HSTPIPISR_DTSEQ_DATA1           (USBHS_HSTPIPISR_DTSEQ_DATA1_Val << USBHS_HSTPIPISR_DTSEQ_Pos) /* (USBHS_HSTPIPISR) Data1 toggle sequence Position  */
#define USBHS_HSTPIPISR_NBUSYBK_Pos           _UINT32_(12)                                         /* (USBHS_HSTPIPISR) Number of Busy Banks Position */
#define USBHS_HSTPIPISR_NBUSYBK_Msk           (_UINT32_(0x3) << USBHS_HSTPIPISR_NBUSYBK_Pos)       /* (USBHS_HSTPIPISR) Number of Busy Banks Mask */
#define USBHS_HSTPIPISR_NBUSYBK(value)        (USBHS_HSTPIPISR_NBUSYBK_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_NBUSYBK_Pos)) /* Assigment of value for NBUSYBK in the USBHS_HSTPIPISR register */
#define   USBHS_HSTPIPISR_NBUSYBK_0_BUSY_Val  _UINT32_(0x0)                                        /* (USBHS_HSTPIPISR) 0 busy bank (all banks free)  */
#define   USBHS_HSTPIPISR_NBUSYBK_1_BUSY_Val  _UINT32_(0x1)                                        /* (USBHS_HSTPIPISR) 1 busy bank  */
#define   USBHS_HSTPIPISR_NBUSYBK_2_BUSY_Val  _UINT32_(0x2)                                        /* (USBHS_HSTPIPISR) 2 busy banks  */
#define   USBHS_HSTPIPISR_NBUSYBK_3_BUSY_Val  _UINT32_(0x3)                                        /* (USBHS_HSTPIPISR) 3 busy banks  */
#define USBHS_HSTPIPISR_NBUSYBK_0_BUSY        (USBHS_HSTPIPISR_NBUSYBK_0_BUSY_Val << USBHS_HSTPIPISR_NBUSYBK_Pos) /* (USBHS_HSTPIPISR) 0 busy bank (all banks free) Position  */
#define USBHS_HSTPIPISR_NBUSYBK_1_BUSY        (USBHS_HSTPIPISR_NBUSYBK_1_BUSY_Val << USBHS_HSTPIPISR_NBUSYBK_Pos) /* (USBHS_HSTPIPISR) 1 busy bank Position  */
#define USBHS_HSTPIPISR_NBUSYBK_2_BUSY        (USBHS_HSTPIPISR_NBUSYBK_2_BUSY_Val << USBHS_HSTPIPISR_NBUSYBK_Pos) /* (USBHS_HSTPIPISR) 2 busy banks Position  */
#define USBHS_HSTPIPISR_NBUSYBK_3_BUSY        (USBHS_HSTPIPISR_NBUSYBK_3_BUSY_Val << USBHS_HSTPIPISR_NBUSYBK_Pos) /* (USBHS_HSTPIPISR) 3 busy banks Position  */
#define USBHS_HSTPIPISR_CURRBK_Pos            _UINT32_(14)                                         /* (USBHS_HSTPIPISR) Current Bank Position */
#define USBHS_HSTPIPISR_CURRBK_Msk            (_UINT32_(0x3) << USBHS_HSTPIPISR_CURRBK_Pos)        /* (USBHS_HSTPIPISR) Current Bank Mask */
#define USBHS_HSTPIPISR_CURRBK(value)         (USBHS_HSTPIPISR_CURRBK_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_CURRBK_Pos)) /* Assigment of value for CURRBK in the USBHS_HSTPIPISR register */
#define   USBHS_HSTPIPISR_CURRBK_BANK0_Val    _UINT32_(0x0)                                        /* (USBHS_HSTPIPISR) Current bank is bank0  */
#define   USBHS_HSTPIPISR_CURRBK_BANK1_Val    _UINT32_(0x1)                                        /* (USBHS_HSTPIPISR) Current bank is bank1  */
#define   USBHS_HSTPIPISR_CURRBK_BANK2_Val    _UINT32_(0x2)                                        /* (USBHS_HSTPIPISR) Current bank is bank2  */
#define USBHS_HSTPIPISR_CURRBK_BANK0          (USBHS_HSTPIPISR_CURRBK_BANK0_Val << USBHS_HSTPIPISR_CURRBK_Pos) /* (USBHS_HSTPIPISR) Current bank is bank0 Position  */
#define USBHS_HSTPIPISR_CURRBK_BANK1          (USBHS_HSTPIPISR_CURRBK_BANK1_Val << USBHS_HSTPIPISR_CURRBK_Pos) /* (USBHS_HSTPIPISR) Current bank is bank1 Position  */
#define USBHS_HSTPIPISR_CURRBK_BANK2          (USBHS_HSTPIPISR_CURRBK_BANK2_Val << USBHS_HSTPIPISR_CURRBK_Pos) /* (USBHS_HSTPIPISR) Current bank is bank2 Position  */
#define USBHS_HSTPIPISR_RWALL_Pos             _UINT32_(16)                                         /* (USBHS_HSTPIPISR) Read/Write Allowed Position */
#define USBHS_HSTPIPISR_RWALL_Msk             (_UINT32_(0x1) << USBHS_HSTPIPISR_RWALL_Pos)         /* (USBHS_HSTPIPISR) Read/Write Allowed Mask */
#define USBHS_HSTPIPISR_RWALL(value)          (USBHS_HSTPIPISR_RWALL_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_RWALL_Pos)) /* Assigment of value for RWALL in the USBHS_HSTPIPISR register */
#define USBHS_HSTPIPISR_CFGOK_Pos             _UINT32_(18)                                         /* (USBHS_HSTPIPISR) Configuration OK Status Position */
#define USBHS_HSTPIPISR_CFGOK_Msk             (_UINT32_(0x1) << USBHS_HSTPIPISR_CFGOK_Pos)         /* (USBHS_HSTPIPISR) Configuration OK Status Mask */
#define USBHS_HSTPIPISR_CFGOK(value)          (USBHS_HSTPIPISR_CFGOK_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_CFGOK_Pos)) /* Assigment of value for CFGOK in the USBHS_HSTPIPISR register */
#define USBHS_HSTPIPISR_PBYCT_Pos             _UINT32_(20)                                         /* (USBHS_HSTPIPISR) Pipe Byte Count Position */
#define USBHS_HSTPIPISR_PBYCT_Msk             (_UINT32_(0x7FF) << USBHS_HSTPIPISR_PBYCT_Pos)       /* (USBHS_HSTPIPISR) Pipe Byte Count Mask */
#define USBHS_HSTPIPISR_PBYCT(value)          (USBHS_HSTPIPISR_PBYCT_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_PBYCT_Pos)) /* Assigment of value for PBYCT in the USBHS_HSTPIPISR register */
#define USBHS_HSTPIPISR_Msk                   _UINT32_(0x7FF5F3BB)                                 /* (USBHS_HSTPIPISR) Register Mask  */

/* CTRL mode */
#define USBHS_HSTPIPISR_CTRL_TXSTPI_Pos       _UINT32_(2)                                          /* (USBHS_HSTPIPISR) Transmitted SETUP Interrupt Position */
#define USBHS_HSTPIPISR_CTRL_TXSTPI_Msk       (_UINT32_(0x1) << USBHS_HSTPIPISR_CTRL_TXSTPI_Pos)   /* (USBHS_HSTPIPISR) Transmitted SETUP Interrupt Mask */
#define USBHS_HSTPIPISR_CTRL_TXSTPI(value)    (USBHS_HSTPIPISR_CTRL_TXSTPI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_CTRL_TXSTPI_Pos))
#define USBHS_HSTPIPISR_CTRL_RXSTALLDI_Pos    _UINT32_(6)                                          /* (USBHS_HSTPIPISR) Received STALLed Interrupt Position */
#define USBHS_HSTPIPISR_CTRL_RXSTALLDI_Msk    (_UINT32_(0x1) << USBHS_HSTPIPISR_CTRL_RXSTALLDI_Pos) /* (USBHS_HSTPIPISR) Received STALLed Interrupt Mask */
#define USBHS_HSTPIPISR_CTRL_RXSTALLDI(value) (USBHS_HSTPIPISR_CTRL_RXSTALLDI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_CTRL_RXSTALLDI_Pos))
#define USBHS_HSTPIPISR_CTRL_Msk              _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPISR_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_HSTPIPISR_ISO_UNDERFI_Pos       _UINT32_(2)                                          /* (USBHS_HSTPIPISR) Underflow Interrupt Position */
#define USBHS_HSTPIPISR_ISO_UNDERFI_Msk       (_UINT32_(0x1) << USBHS_HSTPIPISR_ISO_UNDERFI_Pos)   /* (USBHS_HSTPIPISR) Underflow Interrupt Mask */
#define USBHS_HSTPIPISR_ISO_UNDERFI(value)    (USBHS_HSTPIPISR_ISO_UNDERFI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_ISO_UNDERFI_Pos))
#define USBHS_HSTPIPISR_ISO_CRCERRI_Pos       _UINT32_(6)                                          /* (USBHS_HSTPIPISR) CRC Error Interrupt Position */
#define USBHS_HSTPIPISR_ISO_CRCERRI_Msk       (_UINT32_(0x1) << USBHS_HSTPIPISR_ISO_CRCERRI_Pos)   /* (USBHS_HSTPIPISR) CRC Error Interrupt Mask */
#define USBHS_HSTPIPISR_ISO_CRCERRI(value)    (USBHS_HSTPIPISR_ISO_CRCERRI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_ISO_CRCERRI_Pos))
#define USBHS_HSTPIPISR_ISO_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPISR_ISO) Register Mask  */

/* BLK mode */
#define USBHS_HSTPIPISR_BLK_TXSTPI_Pos        _UINT32_(2)                                          /* (USBHS_HSTPIPISR) Transmitted SETUP Interrupt Position */
#define USBHS_HSTPIPISR_BLK_TXSTPI_Msk        (_UINT32_(0x1) << USBHS_HSTPIPISR_BLK_TXSTPI_Pos)    /* (USBHS_HSTPIPISR) Transmitted SETUP Interrupt Mask */
#define USBHS_HSTPIPISR_BLK_TXSTPI(value)     (USBHS_HSTPIPISR_BLK_TXSTPI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_BLK_TXSTPI_Pos))
#define USBHS_HSTPIPISR_BLK_RXSTALLDI_Pos     _UINT32_(6)                                          /* (USBHS_HSTPIPISR) Received STALLed Interrupt Position */
#define USBHS_HSTPIPISR_BLK_RXSTALLDI_Msk     (_UINT32_(0x1) << USBHS_HSTPIPISR_BLK_RXSTALLDI_Pos) /* (USBHS_HSTPIPISR) Received STALLed Interrupt Mask */
#define USBHS_HSTPIPISR_BLK_RXSTALLDI(value)  (USBHS_HSTPIPISR_BLK_RXSTALLDI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_BLK_RXSTALLDI_Pos))
#define USBHS_HSTPIPISR_BLK_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPISR_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_HSTPIPISR_INTRPT_UNDERFI_Pos    _UINT32_(2)                                          /* (USBHS_HSTPIPISR) Underflow Interrupt Position */
#define USBHS_HSTPIPISR_INTRPT_UNDERFI_Msk    (_UINT32_(0x1) << USBHS_HSTPIPISR_INTRPT_UNDERFI_Pos) /* (USBHS_HSTPIPISR) Underflow Interrupt Mask */
#define USBHS_HSTPIPISR_INTRPT_UNDERFI(value) (USBHS_HSTPIPISR_INTRPT_UNDERFI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_INTRPT_UNDERFI_Pos))
#define USBHS_HSTPIPISR_INTRPT_RXSTALLDI_Pos  _UINT32_(6)                                          /* (USBHS_HSTPIPISR) Received STALLed Interrupt Position */
#define USBHS_HSTPIPISR_INTRPT_RXSTALLDI_Msk  (_UINT32_(0x1) << USBHS_HSTPIPISR_INTRPT_RXSTALLDI_Pos) /* (USBHS_HSTPIPISR) Received STALLed Interrupt Mask */
#define USBHS_HSTPIPISR_INTRPT_RXSTALLDI(value) (USBHS_HSTPIPISR_INTRPT_RXSTALLDI_Msk & (_UINT32_(value) << USBHS_HSTPIPISR_INTRPT_RXSTALLDI_Pos))
#define USBHS_HSTPIPISR_INTRPT_Msk            _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPISR_INTRPT) Register Mask  */


/* -------- USBHS_HSTPIPICR : (USBHS Offset: 0x560) ( /W 32) Host Pipe Clear Register -------- */
#define USBHS_HSTPIPICR_RXINIC_Pos            _UINT32_(0)                                          /* (USBHS_HSTPIPICR) Received IN Data Interrupt Clear Position */
#define USBHS_HSTPIPICR_RXINIC_Msk            (_UINT32_(0x1) << USBHS_HSTPIPICR_RXINIC_Pos)        /* (USBHS_HSTPIPICR) Received IN Data Interrupt Clear Mask */
#define USBHS_HSTPIPICR_RXINIC(value)         (USBHS_HSTPIPICR_RXINIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_RXINIC_Pos)) /* Assigment of value for RXINIC in the USBHS_HSTPIPICR register */
#define USBHS_HSTPIPICR_TXOUTIC_Pos           _UINT32_(1)                                          /* (USBHS_HSTPIPICR) Transmitted OUT Data Interrupt Clear Position */
#define USBHS_HSTPIPICR_TXOUTIC_Msk           (_UINT32_(0x1) << USBHS_HSTPIPICR_TXOUTIC_Pos)       /* (USBHS_HSTPIPICR) Transmitted OUT Data Interrupt Clear Mask */
#define USBHS_HSTPIPICR_TXOUTIC(value)        (USBHS_HSTPIPICR_TXOUTIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_TXOUTIC_Pos)) /* Assigment of value for TXOUTIC in the USBHS_HSTPIPICR register */
#define USBHS_HSTPIPICR_NAKEDIC_Pos           _UINT32_(4)                                          /* (USBHS_HSTPIPICR) NAKed Interrupt Clear Position */
#define USBHS_HSTPIPICR_NAKEDIC_Msk           (_UINT32_(0x1) << USBHS_HSTPIPICR_NAKEDIC_Pos)       /* (USBHS_HSTPIPICR) NAKed Interrupt Clear Mask */
#define USBHS_HSTPIPICR_NAKEDIC(value)        (USBHS_HSTPIPICR_NAKEDIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_NAKEDIC_Pos)) /* Assigment of value for NAKEDIC in the USBHS_HSTPIPICR register */
#define USBHS_HSTPIPICR_OVERFIC_Pos           _UINT32_(5)                                          /* (USBHS_HSTPIPICR) Overflow Interrupt Clear Position */
#define USBHS_HSTPIPICR_OVERFIC_Msk           (_UINT32_(0x1) << USBHS_HSTPIPICR_OVERFIC_Pos)       /* (USBHS_HSTPIPICR) Overflow Interrupt Clear Mask */
#define USBHS_HSTPIPICR_OVERFIC(value)        (USBHS_HSTPIPICR_OVERFIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_OVERFIC_Pos)) /* Assigment of value for OVERFIC in the USBHS_HSTPIPICR register */
#define USBHS_HSTPIPICR_SHORTPACKETIC_Pos     _UINT32_(7)                                          /* (USBHS_HSTPIPICR) Short Packet Interrupt Clear Position */
#define USBHS_HSTPIPICR_SHORTPACKETIC_Msk     (_UINT32_(0x1) << USBHS_HSTPIPICR_SHORTPACKETIC_Pos) /* (USBHS_HSTPIPICR) Short Packet Interrupt Clear Mask */
#define USBHS_HSTPIPICR_SHORTPACKETIC(value)  (USBHS_HSTPIPICR_SHORTPACKETIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_SHORTPACKETIC_Pos)) /* Assigment of value for SHORTPACKETIC in the USBHS_HSTPIPICR register */
#define USBHS_HSTPIPICR_Msk                   _UINT32_(0x000000B3)                                 /* (USBHS_HSTPIPICR) Register Mask  */

/* CTRL mode */
#define USBHS_HSTPIPICR_CTRL_TXSTPIC_Pos      _UINT32_(2)                                          /* (USBHS_HSTPIPICR) Transmitted SETUP Interrupt Clear Position */
#define USBHS_HSTPIPICR_CTRL_TXSTPIC_Msk      (_UINT32_(0x1) << USBHS_HSTPIPICR_CTRL_TXSTPIC_Pos)  /* (USBHS_HSTPIPICR) Transmitted SETUP Interrupt Clear Mask */
#define USBHS_HSTPIPICR_CTRL_TXSTPIC(value)   (USBHS_HSTPIPICR_CTRL_TXSTPIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_CTRL_TXSTPIC_Pos))
#define USBHS_HSTPIPICR_CTRL_RXSTALLDIC_Pos   _UINT32_(6)                                          /* (USBHS_HSTPIPICR) Received STALLed Interrupt Clear Position */
#define USBHS_HSTPIPICR_CTRL_RXSTALLDIC_Msk   (_UINT32_(0x1) << USBHS_HSTPIPICR_CTRL_RXSTALLDIC_Pos) /* (USBHS_HSTPIPICR) Received STALLed Interrupt Clear Mask */
#define USBHS_HSTPIPICR_CTRL_RXSTALLDIC(value) (USBHS_HSTPIPICR_CTRL_RXSTALLDIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_CTRL_RXSTALLDIC_Pos))
#define USBHS_HSTPIPICR_CTRL_Msk              _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPICR_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_HSTPIPICR_ISO_UNDERFIC_Pos      _UINT32_(2)                                          /* (USBHS_HSTPIPICR) Underflow Interrupt Clear Position */
#define USBHS_HSTPIPICR_ISO_UNDERFIC_Msk      (_UINT32_(0x1) << USBHS_HSTPIPICR_ISO_UNDERFIC_Pos)  /* (USBHS_HSTPIPICR) Underflow Interrupt Clear Mask */
#define USBHS_HSTPIPICR_ISO_UNDERFIC(value)   (USBHS_HSTPIPICR_ISO_UNDERFIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_ISO_UNDERFIC_Pos))
#define USBHS_HSTPIPICR_ISO_CRCERRIC_Pos      _UINT32_(6)                                          /* (USBHS_HSTPIPICR) CRC Error Interrupt Clear Position */
#define USBHS_HSTPIPICR_ISO_CRCERRIC_Msk      (_UINT32_(0x1) << USBHS_HSTPIPICR_ISO_CRCERRIC_Pos)  /* (USBHS_HSTPIPICR) CRC Error Interrupt Clear Mask */
#define USBHS_HSTPIPICR_ISO_CRCERRIC(value)   (USBHS_HSTPIPICR_ISO_CRCERRIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_ISO_CRCERRIC_Pos))
#define USBHS_HSTPIPICR_ISO_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPICR_ISO) Register Mask  */

/* BLK mode */
#define USBHS_HSTPIPICR_BLK_TXSTPIC_Pos       _UINT32_(2)                                          /* (USBHS_HSTPIPICR) Transmitted SETUP Interrupt Clear Position */
#define USBHS_HSTPIPICR_BLK_TXSTPIC_Msk       (_UINT32_(0x1) << USBHS_HSTPIPICR_BLK_TXSTPIC_Pos)   /* (USBHS_HSTPIPICR) Transmitted SETUP Interrupt Clear Mask */
#define USBHS_HSTPIPICR_BLK_TXSTPIC(value)    (USBHS_HSTPIPICR_BLK_TXSTPIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_BLK_TXSTPIC_Pos))
#define USBHS_HSTPIPICR_BLK_RXSTALLDIC_Pos    _UINT32_(6)                                          /* (USBHS_HSTPIPICR) Received STALLed Interrupt Clear Position */
#define USBHS_HSTPIPICR_BLK_RXSTALLDIC_Msk    (_UINT32_(0x1) << USBHS_HSTPIPICR_BLK_RXSTALLDIC_Pos) /* (USBHS_HSTPIPICR) Received STALLed Interrupt Clear Mask */
#define USBHS_HSTPIPICR_BLK_RXSTALLDIC(value) (USBHS_HSTPIPICR_BLK_RXSTALLDIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_BLK_RXSTALLDIC_Pos))
#define USBHS_HSTPIPICR_BLK_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPICR_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_HSTPIPICR_INTRPT_UNDERFIC_Pos   _UINT32_(2)                                          /* (USBHS_HSTPIPICR) Underflow Interrupt Clear Position */
#define USBHS_HSTPIPICR_INTRPT_UNDERFIC_Msk   (_UINT32_(0x1) << USBHS_HSTPIPICR_INTRPT_UNDERFIC_Pos) /* (USBHS_HSTPIPICR) Underflow Interrupt Clear Mask */
#define USBHS_HSTPIPICR_INTRPT_UNDERFIC(value) (USBHS_HSTPIPICR_INTRPT_UNDERFIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_INTRPT_UNDERFIC_Pos))
#define USBHS_HSTPIPICR_INTRPT_RXSTALLDIC_Pos _UINT32_(6)                                          /* (USBHS_HSTPIPICR) Received STALLed Interrupt Clear Position */
#define USBHS_HSTPIPICR_INTRPT_RXSTALLDIC_Msk (_UINT32_(0x1) << USBHS_HSTPIPICR_INTRPT_RXSTALLDIC_Pos) /* (USBHS_HSTPIPICR) Received STALLed Interrupt Clear Mask */
#define USBHS_HSTPIPICR_INTRPT_RXSTALLDIC(value) (USBHS_HSTPIPICR_INTRPT_RXSTALLDIC_Msk & (_UINT32_(value) << USBHS_HSTPIPICR_INTRPT_RXSTALLDIC_Pos))
#define USBHS_HSTPIPICR_INTRPT_Msk            _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPICR_INTRPT) Register Mask  */


/* -------- USBHS_HSTPIPIFR : (USBHS Offset: 0x590) ( /W 32) Host Pipe Set Register -------- */
#define USBHS_HSTPIPIFR_RXINIS_Pos            _UINT32_(0)                                          /* (USBHS_HSTPIPIFR) Received IN Data Interrupt Set Position */
#define USBHS_HSTPIPIFR_RXINIS_Msk            (_UINT32_(0x1) << USBHS_HSTPIPIFR_RXINIS_Pos)        /* (USBHS_HSTPIPIFR) Received IN Data Interrupt Set Mask */
#define USBHS_HSTPIPIFR_RXINIS(value)         (USBHS_HSTPIPIFR_RXINIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_RXINIS_Pos)) /* Assigment of value for RXINIS in the USBHS_HSTPIPIFR register */
#define USBHS_HSTPIPIFR_TXOUTIS_Pos           _UINT32_(1)                                          /* (USBHS_HSTPIPIFR) Transmitted OUT Data Interrupt Set Position */
#define USBHS_HSTPIPIFR_TXOUTIS_Msk           (_UINT32_(0x1) << USBHS_HSTPIPIFR_TXOUTIS_Pos)       /* (USBHS_HSTPIPIFR) Transmitted OUT Data Interrupt Set Mask */
#define USBHS_HSTPIPIFR_TXOUTIS(value)        (USBHS_HSTPIPIFR_TXOUTIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_TXOUTIS_Pos)) /* Assigment of value for TXOUTIS in the USBHS_HSTPIPIFR register */
#define USBHS_HSTPIPIFR_PERRIS_Pos            _UINT32_(3)                                          /* (USBHS_HSTPIPIFR) Pipe Error Interrupt Set Position */
#define USBHS_HSTPIPIFR_PERRIS_Msk            (_UINT32_(0x1) << USBHS_HSTPIPIFR_PERRIS_Pos)        /* (USBHS_HSTPIPIFR) Pipe Error Interrupt Set Mask */
#define USBHS_HSTPIPIFR_PERRIS(value)         (USBHS_HSTPIPIFR_PERRIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_PERRIS_Pos)) /* Assigment of value for PERRIS in the USBHS_HSTPIPIFR register */
#define USBHS_HSTPIPIFR_NAKEDIS_Pos           _UINT32_(4)                                          /* (USBHS_HSTPIPIFR) NAKed Interrupt Set Position */
#define USBHS_HSTPIPIFR_NAKEDIS_Msk           (_UINT32_(0x1) << USBHS_HSTPIPIFR_NAKEDIS_Pos)       /* (USBHS_HSTPIPIFR) NAKed Interrupt Set Mask */
#define USBHS_HSTPIPIFR_NAKEDIS(value)        (USBHS_HSTPIPIFR_NAKEDIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_NAKEDIS_Pos)) /* Assigment of value for NAKEDIS in the USBHS_HSTPIPIFR register */
#define USBHS_HSTPIPIFR_OVERFIS_Pos           _UINT32_(5)                                          /* (USBHS_HSTPIPIFR) Overflow Interrupt Set Position */
#define USBHS_HSTPIPIFR_OVERFIS_Msk           (_UINT32_(0x1) << USBHS_HSTPIPIFR_OVERFIS_Pos)       /* (USBHS_HSTPIPIFR) Overflow Interrupt Set Mask */
#define USBHS_HSTPIPIFR_OVERFIS(value)        (USBHS_HSTPIPIFR_OVERFIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_OVERFIS_Pos)) /* Assigment of value for OVERFIS in the USBHS_HSTPIPIFR register */
#define USBHS_HSTPIPIFR_SHORTPACKETIS_Pos     _UINT32_(7)                                          /* (USBHS_HSTPIPIFR) Short Packet Interrupt Set Position */
#define USBHS_HSTPIPIFR_SHORTPACKETIS_Msk     (_UINT32_(0x1) << USBHS_HSTPIPIFR_SHORTPACKETIS_Pos) /* (USBHS_HSTPIPIFR) Short Packet Interrupt Set Mask */
#define USBHS_HSTPIPIFR_SHORTPACKETIS(value)  (USBHS_HSTPIPIFR_SHORTPACKETIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_SHORTPACKETIS_Pos)) /* Assigment of value for SHORTPACKETIS in the USBHS_HSTPIPIFR register */
#define USBHS_HSTPIPIFR_NBUSYBKS_Pos          _UINT32_(12)                                         /* (USBHS_HSTPIPIFR) Number of Busy Banks Set Position */
#define USBHS_HSTPIPIFR_NBUSYBKS_Msk          (_UINT32_(0x1) << USBHS_HSTPIPIFR_NBUSYBKS_Pos)      /* (USBHS_HSTPIPIFR) Number of Busy Banks Set Mask */
#define USBHS_HSTPIPIFR_NBUSYBKS(value)       (USBHS_HSTPIPIFR_NBUSYBKS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_NBUSYBKS_Pos)) /* Assigment of value for NBUSYBKS in the USBHS_HSTPIPIFR register */
#define USBHS_HSTPIPIFR_Msk                   _UINT32_(0x000010BB)                                 /* (USBHS_HSTPIPIFR) Register Mask  */

/* CTRL mode */
#define USBHS_HSTPIPIFR_CTRL_TXSTPIS_Pos      _UINT32_(2)                                          /* (USBHS_HSTPIPIFR) Transmitted SETUP Interrupt Set Position */
#define USBHS_HSTPIPIFR_CTRL_TXSTPIS_Msk      (_UINT32_(0x1) << USBHS_HSTPIPIFR_CTRL_TXSTPIS_Pos)  /* (USBHS_HSTPIPIFR) Transmitted SETUP Interrupt Set Mask */
#define USBHS_HSTPIPIFR_CTRL_TXSTPIS(value)   (USBHS_HSTPIPIFR_CTRL_TXSTPIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_CTRL_TXSTPIS_Pos))
#define USBHS_HSTPIPIFR_CTRL_RXSTALLDIS_Pos   _UINT32_(6)                                          /* (USBHS_HSTPIPIFR) Received STALLed Interrupt Set Position */
#define USBHS_HSTPIPIFR_CTRL_RXSTALLDIS_Msk   (_UINT32_(0x1) << USBHS_HSTPIPIFR_CTRL_RXSTALLDIS_Pos) /* (USBHS_HSTPIPIFR) Received STALLed Interrupt Set Mask */
#define USBHS_HSTPIPIFR_CTRL_RXSTALLDIS(value) (USBHS_HSTPIPIFR_CTRL_RXSTALLDIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_CTRL_RXSTALLDIS_Pos))
#define USBHS_HSTPIPIFR_CTRL_Msk              _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIFR_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_HSTPIPIFR_ISO_UNDERFIS_Pos      _UINT32_(2)                                          /* (USBHS_HSTPIPIFR) Underflow Interrupt Set Position */
#define USBHS_HSTPIPIFR_ISO_UNDERFIS_Msk      (_UINT32_(0x1) << USBHS_HSTPIPIFR_ISO_UNDERFIS_Pos)  /* (USBHS_HSTPIPIFR) Underflow Interrupt Set Mask */
#define USBHS_HSTPIPIFR_ISO_UNDERFIS(value)   (USBHS_HSTPIPIFR_ISO_UNDERFIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_ISO_UNDERFIS_Pos))
#define USBHS_HSTPIPIFR_ISO_CRCERRIS_Pos      _UINT32_(6)                                          /* (USBHS_HSTPIPIFR) CRC Error Interrupt Set Position */
#define USBHS_HSTPIPIFR_ISO_CRCERRIS_Msk      (_UINT32_(0x1) << USBHS_HSTPIPIFR_ISO_CRCERRIS_Pos)  /* (USBHS_HSTPIPIFR) CRC Error Interrupt Set Mask */
#define USBHS_HSTPIPIFR_ISO_CRCERRIS(value)   (USBHS_HSTPIPIFR_ISO_CRCERRIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_ISO_CRCERRIS_Pos))
#define USBHS_HSTPIPIFR_ISO_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIFR_ISO) Register Mask  */

/* BLK mode */
#define USBHS_HSTPIPIFR_BLK_TXSTPIS_Pos       _UINT32_(2)                                          /* (USBHS_HSTPIPIFR) Transmitted SETUP Interrupt Set Position */
#define USBHS_HSTPIPIFR_BLK_TXSTPIS_Msk       (_UINT32_(0x1) << USBHS_HSTPIPIFR_BLK_TXSTPIS_Pos)   /* (USBHS_HSTPIPIFR) Transmitted SETUP Interrupt Set Mask */
#define USBHS_HSTPIPIFR_BLK_TXSTPIS(value)    (USBHS_HSTPIPIFR_BLK_TXSTPIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_BLK_TXSTPIS_Pos))
#define USBHS_HSTPIPIFR_BLK_RXSTALLDIS_Pos    _UINT32_(6)                                          /* (USBHS_HSTPIPIFR) Received STALLed Interrupt Set Position */
#define USBHS_HSTPIPIFR_BLK_RXSTALLDIS_Msk    (_UINT32_(0x1) << USBHS_HSTPIPIFR_BLK_RXSTALLDIS_Pos) /* (USBHS_HSTPIPIFR) Received STALLed Interrupt Set Mask */
#define USBHS_HSTPIPIFR_BLK_RXSTALLDIS(value) (USBHS_HSTPIPIFR_BLK_RXSTALLDIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_BLK_RXSTALLDIS_Pos))
#define USBHS_HSTPIPIFR_BLK_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIFR_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_HSTPIPIFR_INTRPT_UNDERFIS_Pos   _UINT32_(2)                                          /* (USBHS_HSTPIPIFR) Underflow Interrupt Set Position */
#define USBHS_HSTPIPIFR_INTRPT_UNDERFIS_Msk   (_UINT32_(0x1) << USBHS_HSTPIPIFR_INTRPT_UNDERFIS_Pos) /* (USBHS_HSTPIPIFR) Underflow Interrupt Set Mask */
#define USBHS_HSTPIPIFR_INTRPT_UNDERFIS(value) (USBHS_HSTPIPIFR_INTRPT_UNDERFIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_INTRPT_UNDERFIS_Pos))
#define USBHS_HSTPIPIFR_INTRPT_RXSTALLDIS_Pos _UINT32_(6)                                          /* (USBHS_HSTPIPIFR) Received STALLed Interrupt Set Position */
#define USBHS_HSTPIPIFR_INTRPT_RXSTALLDIS_Msk (_UINT32_(0x1) << USBHS_HSTPIPIFR_INTRPT_RXSTALLDIS_Pos) /* (USBHS_HSTPIPIFR) Received STALLed Interrupt Set Mask */
#define USBHS_HSTPIPIFR_INTRPT_RXSTALLDIS(value) (USBHS_HSTPIPIFR_INTRPT_RXSTALLDIS_Msk & (_UINT32_(value) << USBHS_HSTPIPIFR_INTRPT_RXSTALLDIS_Pos))
#define USBHS_HSTPIPIFR_INTRPT_Msk            _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIFR_INTRPT) Register Mask  */


/* -------- USBHS_HSTPIPIMR : (USBHS Offset: 0x5C0) ( R/ 32) Host Pipe Mask Register -------- */
#define USBHS_HSTPIPIMR_RXINE_Pos             _UINT32_(0)                                          /* (USBHS_HSTPIPIMR) Received IN Data Interrupt Enable Position */
#define USBHS_HSTPIPIMR_RXINE_Msk             (_UINT32_(0x1) << USBHS_HSTPIPIMR_RXINE_Pos)         /* (USBHS_HSTPIPIMR) Received IN Data Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_RXINE(value)          (USBHS_HSTPIPIMR_RXINE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_RXINE_Pos)) /* Assigment of value for RXINE in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_TXOUTE_Pos            _UINT32_(1)                                          /* (USBHS_HSTPIPIMR) Transmitted OUT Data Interrupt Enable Position */
#define USBHS_HSTPIPIMR_TXOUTE_Msk            (_UINT32_(0x1) << USBHS_HSTPIPIMR_TXOUTE_Pos)        /* (USBHS_HSTPIPIMR) Transmitted OUT Data Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_TXOUTE(value)         (USBHS_HSTPIPIMR_TXOUTE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_TXOUTE_Pos)) /* Assigment of value for TXOUTE in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_PERRE_Pos             _UINT32_(3)                                          /* (USBHS_HSTPIPIMR) Pipe Error Interrupt Enable Position */
#define USBHS_HSTPIPIMR_PERRE_Msk             (_UINT32_(0x1) << USBHS_HSTPIPIMR_PERRE_Pos)         /* (USBHS_HSTPIPIMR) Pipe Error Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_PERRE(value)          (USBHS_HSTPIPIMR_PERRE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_PERRE_Pos)) /* Assigment of value for PERRE in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_NAKEDE_Pos            _UINT32_(4)                                          /* (USBHS_HSTPIPIMR) NAKed Interrupt Enable Position */
#define USBHS_HSTPIPIMR_NAKEDE_Msk            (_UINT32_(0x1) << USBHS_HSTPIPIMR_NAKEDE_Pos)        /* (USBHS_HSTPIPIMR) NAKed Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_NAKEDE(value)         (USBHS_HSTPIPIMR_NAKEDE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_NAKEDE_Pos)) /* Assigment of value for NAKEDE in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_OVERFIE_Pos           _UINT32_(5)                                          /* (USBHS_HSTPIPIMR) Overflow Interrupt Enable Position */
#define USBHS_HSTPIPIMR_OVERFIE_Msk           (_UINT32_(0x1) << USBHS_HSTPIPIMR_OVERFIE_Pos)       /* (USBHS_HSTPIPIMR) Overflow Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_OVERFIE(value)        (USBHS_HSTPIPIMR_OVERFIE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_OVERFIE_Pos)) /* Assigment of value for OVERFIE in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_SHORTPACKETIE_Pos     _UINT32_(7)                                          /* (USBHS_HSTPIPIMR) Short Packet Interrupt Enable Position */
#define USBHS_HSTPIPIMR_SHORTPACKETIE_Msk     (_UINT32_(0x1) << USBHS_HSTPIPIMR_SHORTPACKETIE_Pos) /* (USBHS_HSTPIPIMR) Short Packet Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_SHORTPACKETIE(value)  (USBHS_HSTPIPIMR_SHORTPACKETIE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_SHORTPACKETIE_Pos)) /* Assigment of value for SHORTPACKETIE in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_NBUSYBKE_Pos          _UINT32_(12)                                         /* (USBHS_HSTPIPIMR) Number of Busy Banks Interrupt Enable Position */
#define USBHS_HSTPIPIMR_NBUSYBKE_Msk          (_UINT32_(0x1) << USBHS_HSTPIPIMR_NBUSYBKE_Pos)      /* (USBHS_HSTPIPIMR) Number of Busy Banks Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_NBUSYBKE(value)       (USBHS_HSTPIPIMR_NBUSYBKE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_NBUSYBKE_Pos)) /* Assigment of value for NBUSYBKE in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_FIFOCON_Pos           _UINT32_(14)                                         /* (USBHS_HSTPIPIMR) FIFO Control Position */
#define USBHS_HSTPIPIMR_FIFOCON_Msk           (_UINT32_(0x1) << USBHS_HSTPIPIMR_FIFOCON_Pos)       /* (USBHS_HSTPIPIMR) FIFO Control Mask */
#define USBHS_HSTPIPIMR_FIFOCON(value)        (USBHS_HSTPIPIMR_FIFOCON_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_FIFOCON_Pos)) /* Assigment of value for FIFOCON in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_PDISHDMA_Pos          _UINT32_(16)                                         /* (USBHS_HSTPIPIMR) Pipe Interrupts Disable HDMA Request Enable Position */
#define USBHS_HSTPIPIMR_PDISHDMA_Msk          (_UINT32_(0x1) << USBHS_HSTPIPIMR_PDISHDMA_Pos)      /* (USBHS_HSTPIPIMR) Pipe Interrupts Disable HDMA Request Enable Mask */
#define USBHS_HSTPIPIMR_PDISHDMA(value)       (USBHS_HSTPIPIMR_PDISHDMA_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_PDISHDMA_Pos)) /* Assigment of value for PDISHDMA in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_PFREEZE_Pos           _UINT32_(17)                                         /* (USBHS_HSTPIPIMR) Pipe Freeze Position */
#define USBHS_HSTPIPIMR_PFREEZE_Msk           (_UINT32_(0x1) << USBHS_HSTPIPIMR_PFREEZE_Pos)       /* (USBHS_HSTPIPIMR) Pipe Freeze Mask */
#define USBHS_HSTPIPIMR_PFREEZE(value)        (USBHS_HSTPIPIMR_PFREEZE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_PFREEZE_Pos)) /* Assigment of value for PFREEZE in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_RSTDT_Pos             _UINT32_(18)                                         /* (USBHS_HSTPIPIMR) Reset Data Toggle Position */
#define USBHS_HSTPIPIMR_RSTDT_Msk             (_UINT32_(0x1) << USBHS_HSTPIPIMR_RSTDT_Pos)         /* (USBHS_HSTPIPIMR) Reset Data Toggle Mask */
#define USBHS_HSTPIPIMR_RSTDT(value)          (USBHS_HSTPIPIMR_RSTDT_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_RSTDT_Pos)) /* Assigment of value for RSTDT in the USBHS_HSTPIPIMR register */
#define USBHS_HSTPIPIMR_Msk                   _UINT32_(0x000750BB)                                 /* (USBHS_HSTPIPIMR) Register Mask  */

/* CTRL mode */
#define USBHS_HSTPIPIMR_CTRL_TXSTPE_Pos       _UINT32_(2)                                          /* (USBHS_HSTPIPIMR) Transmitted SETUP Interrupt Enable Position */
#define USBHS_HSTPIPIMR_CTRL_TXSTPE_Msk       (_UINT32_(0x1) << USBHS_HSTPIPIMR_CTRL_TXSTPE_Pos)   /* (USBHS_HSTPIPIMR) Transmitted SETUP Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_CTRL_TXSTPE(value)    (USBHS_HSTPIPIMR_CTRL_TXSTPE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_CTRL_TXSTPE_Pos))
#define USBHS_HSTPIPIMR_CTRL_RXSTALLDE_Pos    _UINT32_(6)                                          /* (USBHS_HSTPIPIMR) Received STALLed Interrupt Enable Position */
#define USBHS_HSTPIPIMR_CTRL_RXSTALLDE_Msk    (_UINT32_(0x1) << USBHS_HSTPIPIMR_CTRL_RXSTALLDE_Pos) /* (USBHS_HSTPIPIMR) Received STALLed Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_CTRL_RXSTALLDE(value) (USBHS_HSTPIPIMR_CTRL_RXSTALLDE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_CTRL_RXSTALLDE_Pos))
#define USBHS_HSTPIPIMR_CTRL_Msk              _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIMR_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_HSTPIPIMR_ISO_UNDERFIE_Pos      _UINT32_(2)                                          /* (USBHS_HSTPIPIMR) Underflow Interrupt Enable Position */
#define USBHS_HSTPIPIMR_ISO_UNDERFIE_Msk      (_UINT32_(0x1) << USBHS_HSTPIPIMR_ISO_UNDERFIE_Pos)  /* (USBHS_HSTPIPIMR) Underflow Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_ISO_UNDERFIE(value)   (USBHS_HSTPIPIMR_ISO_UNDERFIE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_ISO_UNDERFIE_Pos))
#define USBHS_HSTPIPIMR_ISO_CRCERRE_Pos       _UINT32_(6)                                          /* (USBHS_HSTPIPIMR) CRC Error Interrupt Enable Position */
#define USBHS_HSTPIPIMR_ISO_CRCERRE_Msk       (_UINT32_(0x1) << USBHS_HSTPIPIMR_ISO_CRCERRE_Pos)   /* (USBHS_HSTPIPIMR) CRC Error Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_ISO_CRCERRE(value)    (USBHS_HSTPIPIMR_ISO_CRCERRE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_ISO_CRCERRE_Pos))
#define USBHS_HSTPIPIMR_ISO_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIMR_ISO) Register Mask  */

/* BLK mode */
#define USBHS_HSTPIPIMR_BLK_TXSTPE_Pos        _UINT32_(2)                                          /* (USBHS_HSTPIPIMR) Transmitted SETUP Interrupt Enable Position */
#define USBHS_HSTPIPIMR_BLK_TXSTPE_Msk        (_UINT32_(0x1) << USBHS_HSTPIPIMR_BLK_TXSTPE_Pos)    /* (USBHS_HSTPIPIMR) Transmitted SETUP Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_BLK_TXSTPE(value)     (USBHS_HSTPIPIMR_BLK_TXSTPE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_BLK_TXSTPE_Pos))
#define USBHS_HSTPIPIMR_BLK_RXSTALLDE_Pos     _UINT32_(6)                                          /* (USBHS_HSTPIPIMR) Received STALLed Interrupt Enable Position */
#define USBHS_HSTPIPIMR_BLK_RXSTALLDE_Msk     (_UINT32_(0x1) << USBHS_HSTPIPIMR_BLK_RXSTALLDE_Pos) /* (USBHS_HSTPIPIMR) Received STALLed Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_BLK_RXSTALLDE(value)  (USBHS_HSTPIPIMR_BLK_RXSTALLDE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_BLK_RXSTALLDE_Pos))
#define USBHS_HSTPIPIMR_BLK_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIMR_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_HSTPIPIMR_INTRPT_UNDERFIE_Pos   _UINT32_(2)                                          /* (USBHS_HSTPIPIMR) Underflow Interrupt Enable Position */
#define USBHS_HSTPIPIMR_INTRPT_UNDERFIE_Msk   (_UINT32_(0x1) << USBHS_HSTPIPIMR_INTRPT_UNDERFIE_Pos) /* (USBHS_HSTPIPIMR) Underflow Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_INTRPT_UNDERFIE(value) (USBHS_HSTPIPIMR_INTRPT_UNDERFIE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_INTRPT_UNDERFIE_Pos))
#define USBHS_HSTPIPIMR_INTRPT_RXSTALLDE_Pos  _UINT32_(6)                                          /* (USBHS_HSTPIPIMR) Received STALLed Interrupt Enable Position */
#define USBHS_HSTPIPIMR_INTRPT_RXSTALLDE_Msk  (_UINT32_(0x1) << USBHS_HSTPIPIMR_INTRPT_RXSTALLDE_Pos) /* (USBHS_HSTPIPIMR) Received STALLed Interrupt Enable Mask */
#define USBHS_HSTPIPIMR_INTRPT_RXSTALLDE(value) (USBHS_HSTPIPIMR_INTRPT_RXSTALLDE_Msk & (_UINT32_(value) << USBHS_HSTPIPIMR_INTRPT_RXSTALLDE_Pos))
#define USBHS_HSTPIPIMR_INTRPT_Msk            _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIMR_INTRPT) Register Mask  */


/* -------- USBHS_HSTPIPIER : (USBHS Offset: 0x5F0) ( /W 32) Host Pipe Enable Register -------- */
#define USBHS_HSTPIPIER_RXINES_Pos            _UINT32_(0)                                          /* (USBHS_HSTPIPIER) Received IN Data Interrupt Enable Position */
#define USBHS_HSTPIPIER_RXINES_Msk            (_UINT32_(0x1) << USBHS_HSTPIPIER_RXINES_Pos)        /* (USBHS_HSTPIPIER) Received IN Data Interrupt Enable Mask */
#define USBHS_HSTPIPIER_RXINES(value)         (USBHS_HSTPIPIER_RXINES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_RXINES_Pos)) /* Assigment of value for RXINES in the USBHS_HSTPIPIER register */
#define USBHS_HSTPIPIER_TXOUTES_Pos           _UINT32_(1)                                          /* (USBHS_HSTPIPIER) Transmitted OUT Data Interrupt Enable Position */
#define USBHS_HSTPIPIER_TXOUTES_Msk           (_UINT32_(0x1) << USBHS_HSTPIPIER_TXOUTES_Pos)       /* (USBHS_HSTPIPIER) Transmitted OUT Data Interrupt Enable Mask */
#define USBHS_HSTPIPIER_TXOUTES(value)        (USBHS_HSTPIPIER_TXOUTES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_TXOUTES_Pos)) /* Assigment of value for TXOUTES in the USBHS_HSTPIPIER register */
#define USBHS_HSTPIPIER_PERRES_Pos            _UINT32_(3)                                          /* (USBHS_HSTPIPIER) Pipe Error Interrupt Enable Position */
#define USBHS_HSTPIPIER_PERRES_Msk            (_UINT32_(0x1) << USBHS_HSTPIPIER_PERRES_Pos)        /* (USBHS_HSTPIPIER) Pipe Error Interrupt Enable Mask */
#define USBHS_HSTPIPIER_PERRES(value)         (USBHS_HSTPIPIER_PERRES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_PERRES_Pos)) /* Assigment of value for PERRES in the USBHS_HSTPIPIER register */
#define USBHS_HSTPIPIER_NAKEDES_Pos           _UINT32_(4)                                          /* (USBHS_HSTPIPIER) NAKed Interrupt Enable Position */
#define USBHS_HSTPIPIER_NAKEDES_Msk           (_UINT32_(0x1) << USBHS_HSTPIPIER_NAKEDES_Pos)       /* (USBHS_HSTPIPIER) NAKed Interrupt Enable Mask */
#define USBHS_HSTPIPIER_NAKEDES(value)        (USBHS_HSTPIPIER_NAKEDES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_NAKEDES_Pos)) /* Assigment of value for NAKEDES in the USBHS_HSTPIPIER register */
#define USBHS_HSTPIPIER_OVERFIES_Pos          _UINT32_(5)                                          /* (USBHS_HSTPIPIER) Overflow Interrupt Enable Position */
#define USBHS_HSTPIPIER_OVERFIES_Msk          (_UINT32_(0x1) << USBHS_HSTPIPIER_OVERFIES_Pos)      /* (USBHS_HSTPIPIER) Overflow Interrupt Enable Mask */
#define USBHS_HSTPIPIER_OVERFIES(value)       (USBHS_HSTPIPIER_OVERFIES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_OVERFIES_Pos)) /* Assigment of value for OVERFIES in the USBHS_HSTPIPIER register */
#define USBHS_HSTPIPIER_SHORTPACKETIES_Pos    _UINT32_(7)                                          /* (USBHS_HSTPIPIER) Short Packet Interrupt Enable Position */
#define USBHS_HSTPIPIER_SHORTPACKETIES_Msk    (_UINT32_(0x1) << USBHS_HSTPIPIER_SHORTPACKETIES_Pos) /* (USBHS_HSTPIPIER) Short Packet Interrupt Enable Mask */
#define USBHS_HSTPIPIER_SHORTPACKETIES(value) (USBHS_HSTPIPIER_SHORTPACKETIES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_SHORTPACKETIES_Pos)) /* Assigment of value for SHORTPACKETIES in the USBHS_HSTPIPIER register */
#define USBHS_HSTPIPIER_NBUSYBKES_Pos         _UINT32_(12)                                         /* (USBHS_HSTPIPIER) Number of Busy Banks Enable Position */
#define USBHS_HSTPIPIER_NBUSYBKES_Msk         (_UINT32_(0x1) << USBHS_HSTPIPIER_NBUSYBKES_Pos)     /* (USBHS_HSTPIPIER) Number of Busy Banks Enable Mask */
#define USBHS_HSTPIPIER_NBUSYBKES(value)      (USBHS_HSTPIPIER_NBUSYBKES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_NBUSYBKES_Pos)) /* Assigment of value for NBUSYBKES in the USBHS_HSTPIPIER register */
#define USBHS_HSTPIPIER_PDISHDMAS_Pos         _UINT32_(16)                                         /* (USBHS_HSTPIPIER) Pipe Interrupts Disable HDMA Request Enable Position */
#define USBHS_HSTPIPIER_PDISHDMAS_Msk         (_UINT32_(0x1) << USBHS_HSTPIPIER_PDISHDMAS_Pos)     /* (USBHS_HSTPIPIER) Pipe Interrupts Disable HDMA Request Enable Mask */
#define USBHS_HSTPIPIER_PDISHDMAS(value)      (USBHS_HSTPIPIER_PDISHDMAS_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_PDISHDMAS_Pos)) /* Assigment of value for PDISHDMAS in the USBHS_HSTPIPIER register */
#define USBHS_HSTPIPIER_PFREEZES_Pos          _UINT32_(17)                                         /* (USBHS_HSTPIPIER) Pipe Freeze Enable Position */
#define USBHS_HSTPIPIER_PFREEZES_Msk          (_UINT32_(0x1) << USBHS_HSTPIPIER_PFREEZES_Pos)      /* (USBHS_HSTPIPIER) Pipe Freeze Enable Mask */
#define USBHS_HSTPIPIER_PFREEZES(value)       (USBHS_HSTPIPIER_PFREEZES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_PFREEZES_Pos)) /* Assigment of value for PFREEZES in the USBHS_HSTPIPIER register */
#define USBHS_HSTPIPIER_RSTDTS_Pos            _UINT32_(18)                                         /* (USBHS_HSTPIPIER) Reset Data Toggle Enable Position */
#define USBHS_HSTPIPIER_RSTDTS_Msk            (_UINT32_(0x1) << USBHS_HSTPIPIER_RSTDTS_Pos)        /* (USBHS_HSTPIPIER) Reset Data Toggle Enable Mask */
#define USBHS_HSTPIPIER_RSTDTS(value)         (USBHS_HSTPIPIER_RSTDTS_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_RSTDTS_Pos)) /* Assigment of value for RSTDTS in the USBHS_HSTPIPIER register */
#define USBHS_HSTPIPIER_Msk                   _UINT32_(0x000710BB)                                 /* (USBHS_HSTPIPIER) Register Mask  */

/* CTRL mode */
#define USBHS_HSTPIPIER_CTRL_TXSTPES_Pos      _UINT32_(2)                                          /* (USBHS_HSTPIPIER) Transmitted SETUP Interrupt Enable Position */
#define USBHS_HSTPIPIER_CTRL_TXSTPES_Msk      (_UINT32_(0x1) << USBHS_HSTPIPIER_CTRL_TXSTPES_Pos)  /* (USBHS_HSTPIPIER) Transmitted SETUP Interrupt Enable Mask */
#define USBHS_HSTPIPIER_CTRL_TXSTPES(value)   (USBHS_HSTPIPIER_CTRL_TXSTPES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_CTRL_TXSTPES_Pos))
#define USBHS_HSTPIPIER_CTRL_RXSTALLDES_Pos   _UINT32_(6)                                          /* (USBHS_HSTPIPIER) Received STALLed Interrupt Enable Position */
#define USBHS_HSTPIPIER_CTRL_RXSTALLDES_Msk   (_UINT32_(0x1) << USBHS_HSTPIPIER_CTRL_RXSTALLDES_Pos) /* (USBHS_HSTPIPIER) Received STALLed Interrupt Enable Mask */
#define USBHS_HSTPIPIER_CTRL_RXSTALLDES(value) (USBHS_HSTPIPIER_CTRL_RXSTALLDES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_CTRL_RXSTALLDES_Pos))
#define USBHS_HSTPIPIER_CTRL_Msk              _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIER_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_HSTPIPIER_ISO_UNDERFIES_Pos     _UINT32_(2)                                          /* (USBHS_HSTPIPIER) Underflow Interrupt Enable Position */
#define USBHS_HSTPIPIER_ISO_UNDERFIES_Msk     (_UINT32_(0x1) << USBHS_HSTPIPIER_ISO_UNDERFIES_Pos) /* (USBHS_HSTPIPIER) Underflow Interrupt Enable Mask */
#define USBHS_HSTPIPIER_ISO_UNDERFIES(value)  (USBHS_HSTPIPIER_ISO_UNDERFIES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_ISO_UNDERFIES_Pos))
#define USBHS_HSTPIPIER_ISO_CRCERRES_Pos      _UINT32_(6)                                          /* (USBHS_HSTPIPIER) CRC Error Interrupt Enable Position */
#define USBHS_HSTPIPIER_ISO_CRCERRES_Msk      (_UINT32_(0x1) << USBHS_HSTPIPIER_ISO_CRCERRES_Pos)  /* (USBHS_HSTPIPIER) CRC Error Interrupt Enable Mask */
#define USBHS_HSTPIPIER_ISO_CRCERRES(value)   (USBHS_HSTPIPIER_ISO_CRCERRES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_ISO_CRCERRES_Pos))
#define USBHS_HSTPIPIER_ISO_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIER_ISO) Register Mask  */

/* BLK mode */
#define USBHS_HSTPIPIER_BLK_TXSTPES_Pos       _UINT32_(2)                                          /* (USBHS_HSTPIPIER) Transmitted SETUP Interrupt Enable Position */
#define USBHS_HSTPIPIER_BLK_TXSTPES_Msk       (_UINT32_(0x1) << USBHS_HSTPIPIER_BLK_TXSTPES_Pos)   /* (USBHS_HSTPIPIER) Transmitted SETUP Interrupt Enable Mask */
#define USBHS_HSTPIPIER_BLK_TXSTPES(value)    (USBHS_HSTPIPIER_BLK_TXSTPES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_BLK_TXSTPES_Pos))
#define USBHS_HSTPIPIER_BLK_RXSTALLDES_Pos    _UINT32_(6)                                          /* (USBHS_HSTPIPIER) Received STALLed Interrupt Enable Position */
#define USBHS_HSTPIPIER_BLK_RXSTALLDES_Msk    (_UINT32_(0x1) << USBHS_HSTPIPIER_BLK_RXSTALLDES_Pos) /* (USBHS_HSTPIPIER) Received STALLed Interrupt Enable Mask */
#define USBHS_HSTPIPIER_BLK_RXSTALLDES(value) (USBHS_HSTPIPIER_BLK_RXSTALLDES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_BLK_RXSTALLDES_Pos))
#define USBHS_HSTPIPIER_BLK_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIER_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_HSTPIPIER_INTRPT_UNDERFIES_Pos  _UINT32_(2)                                          /* (USBHS_HSTPIPIER) Underflow Interrupt Enable Position */
#define USBHS_HSTPIPIER_INTRPT_UNDERFIES_Msk  (_UINT32_(0x1) << USBHS_HSTPIPIER_INTRPT_UNDERFIES_Pos) /* (USBHS_HSTPIPIER) Underflow Interrupt Enable Mask */
#define USBHS_HSTPIPIER_INTRPT_UNDERFIES(value) (USBHS_HSTPIPIER_INTRPT_UNDERFIES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_INTRPT_UNDERFIES_Pos))
#define USBHS_HSTPIPIER_INTRPT_RXSTALLDES_Pos _UINT32_(6)                                          /* (USBHS_HSTPIPIER) Received STALLed Interrupt Enable Position */
#define USBHS_HSTPIPIER_INTRPT_RXSTALLDES_Msk (_UINT32_(0x1) << USBHS_HSTPIPIER_INTRPT_RXSTALLDES_Pos) /* (USBHS_HSTPIPIER) Received STALLed Interrupt Enable Mask */
#define USBHS_HSTPIPIER_INTRPT_RXSTALLDES(value) (USBHS_HSTPIPIER_INTRPT_RXSTALLDES_Msk & (_UINT32_(value) << USBHS_HSTPIPIER_INTRPT_RXSTALLDES_Pos))
#define USBHS_HSTPIPIER_INTRPT_Msk            _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIER_INTRPT) Register Mask  */


/* -------- USBHS_HSTPIPIDR : (USBHS Offset: 0x620) ( /W 32) Host Pipe Disable Register -------- */
#define USBHS_HSTPIPIDR_RXINEC_Pos            _UINT32_(0)                                          /* (USBHS_HSTPIPIDR) Received IN Data Interrupt Disable Position */
#define USBHS_HSTPIPIDR_RXINEC_Msk            (_UINT32_(0x1) << USBHS_HSTPIPIDR_RXINEC_Pos)        /* (USBHS_HSTPIPIDR) Received IN Data Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_RXINEC(value)         (USBHS_HSTPIPIDR_RXINEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_RXINEC_Pos)) /* Assigment of value for RXINEC in the USBHS_HSTPIPIDR register */
#define USBHS_HSTPIPIDR_TXOUTEC_Pos           _UINT32_(1)                                          /* (USBHS_HSTPIPIDR) Transmitted OUT Data Interrupt Disable Position */
#define USBHS_HSTPIPIDR_TXOUTEC_Msk           (_UINT32_(0x1) << USBHS_HSTPIPIDR_TXOUTEC_Pos)       /* (USBHS_HSTPIPIDR) Transmitted OUT Data Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_TXOUTEC(value)        (USBHS_HSTPIPIDR_TXOUTEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_TXOUTEC_Pos)) /* Assigment of value for TXOUTEC in the USBHS_HSTPIPIDR register */
#define USBHS_HSTPIPIDR_PERREC_Pos            _UINT32_(3)                                          /* (USBHS_HSTPIPIDR) Pipe Error Interrupt Disable Position */
#define USBHS_HSTPIPIDR_PERREC_Msk            (_UINT32_(0x1) << USBHS_HSTPIPIDR_PERREC_Pos)        /* (USBHS_HSTPIPIDR) Pipe Error Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_PERREC(value)         (USBHS_HSTPIPIDR_PERREC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_PERREC_Pos)) /* Assigment of value for PERREC in the USBHS_HSTPIPIDR register */
#define USBHS_HSTPIPIDR_NAKEDEC_Pos           _UINT32_(4)                                          /* (USBHS_HSTPIPIDR) NAKed Interrupt Disable Position */
#define USBHS_HSTPIPIDR_NAKEDEC_Msk           (_UINT32_(0x1) << USBHS_HSTPIPIDR_NAKEDEC_Pos)       /* (USBHS_HSTPIPIDR) NAKed Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_NAKEDEC(value)        (USBHS_HSTPIPIDR_NAKEDEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_NAKEDEC_Pos)) /* Assigment of value for NAKEDEC in the USBHS_HSTPIPIDR register */
#define USBHS_HSTPIPIDR_OVERFIEC_Pos          _UINT32_(5)                                          /* (USBHS_HSTPIPIDR) Overflow Interrupt Disable Position */
#define USBHS_HSTPIPIDR_OVERFIEC_Msk          (_UINT32_(0x1) << USBHS_HSTPIPIDR_OVERFIEC_Pos)      /* (USBHS_HSTPIPIDR) Overflow Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_OVERFIEC(value)       (USBHS_HSTPIPIDR_OVERFIEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_OVERFIEC_Pos)) /* Assigment of value for OVERFIEC in the USBHS_HSTPIPIDR register */
#define USBHS_HSTPIPIDR_SHORTPACKETIEC_Pos    _UINT32_(7)                                          /* (USBHS_HSTPIPIDR) Short Packet Interrupt Disable Position */
#define USBHS_HSTPIPIDR_SHORTPACKETIEC_Msk    (_UINT32_(0x1) << USBHS_HSTPIPIDR_SHORTPACKETIEC_Pos) /* (USBHS_HSTPIPIDR) Short Packet Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_SHORTPACKETIEC(value) (USBHS_HSTPIPIDR_SHORTPACKETIEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_SHORTPACKETIEC_Pos)) /* Assigment of value for SHORTPACKETIEC in the USBHS_HSTPIPIDR register */
#define USBHS_HSTPIPIDR_NBUSYBKEC_Pos         _UINT32_(12)                                         /* (USBHS_HSTPIPIDR) Number of Busy Banks Disable Position */
#define USBHS_HSTPIPIDR_NBUSYBKEC_Msk         (_UINT32_(0x1) << USBHS_HSTPIPIDR_NBUSYBKEC_Pos)     /* (USBHS_HSTPIPIDR) Number of Busy Banks Disable Mask */
#define USBHS_HSTPIPIDR_NBUSYBKEC(value)      (USBHS_HSTPIPIDR_NBUSYBKEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_NBUSYBKEC_Pos)) /* Assigment of value for NBUSYBKEC in the USBHS_HSTPIPIDR register */
#define USBHS_HSTPIPIDR_FIFOCONC_Pos          _UINT32_(14)                                         /* (USBHS_HSTPIPIDR) FIFO Control Disable Position */
#define USBHS_HSTPIPIDR_FIFOCONC_Msk          (_UINT32_(0x1) << USBHS_HSTPIPIDR_FIFOCONC_Pos)      /* (USBHS_HSTPIPIDR) FIFO Control Disable Mask */
#define USBHS_HSTPIPIDR_FIFOCONC(value)       (USBHS_HSTPIPIDR_FIFOCONC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_FIFOCONC_Pos)) /* Assigment of value for FIFOCONC in the USBHS_HSTPIPIDR register */
#define USBHS_HSTPIPIDR_PDISHDMAC_Pos         _UINT32_(16)                                         /* (USBHS_HSTPIPIDR) Pipe Interrupts Disable HDMA Request Disable Position */
#define USBHS_HSTPIPIDR_PDISHDMAC_Msk         (_UINT32_(0x1) << USBHS_HSTPIPIDR_PDISHDMAC_Pos)     /* (USBHS_HSTPIPIDR) Pipe Interrupts Disable HDMA Request Disable Mask */
#define USBHS_HSTPIPIDR_PDISHDMAC(value)      (USBHS_HSTPIPIDR_PDISHDMAC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_PDISHDMAC_Pos)) /* Assigment of value for PDISHDMAC in the USBHS_HSTPIPIDR register */
#define USBHS_HSTPIPIDR_PFREEZEC_Pos          _UINT32_(17)                                         /* (USBHS_HSTPIPIDR) Pipe Freeze Disable Position */
#define USBHS_HSTPIPIDR_PFREEZEC_Msk          (_UINT32_(0x1) << USBHS_HSTPIPIDR_PFREEZEC_Pos)      /* (USBHS_HSTPIPIDR) Pipe Freeze Disable Mask */
#define USBHS_HSTPIPIDR_PFREEZEC(value)       (USBHS_HSTPIPIDR_PFREEZEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_PFREEZEC_Pos)) /* Assigment of value for PFREEZEC in the USBHS_HSTPIPIDR register */
#define USBHS_HSTPIPIDR_Msk                   _UINT32_(0x000350BB)                                 /* (USBHS_HSTPIPIDR) Register Mask  */

/* CTRL mode */
#define USBHS_HSTPIPIDR_CTRL_TXSTPEC_Pos      _UINT32_(2)                                          /* (USBHS_HSTPIPIDR) Transmitted SETUP Interrupt Disable Position */
#define USBHS_HSTPIPIDR_CTRL_TXSTPEC_Msk      (_UINT32_(0x1) << USBHS_HSTPIPIDR_CTRL_TXSTPEC_Pos)  /* (USBHS_HSTPIPIDR) Transmitted SETUP Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_CTRL_TXSTPEC(value)   (USBHS_HSTPIPIDR_CTRL_TXSTPEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_CTRL_TXSTPEC_Pos))
#define USBHS_HSTPIPIDR_CTRL_RXSTALLDEC_Pos   _UINT32_(6)                                          /* (USBHS_HSTPIPIDR) Received STALLed Interrupt Disable Position */
#define USBHS_HSTPIPIDR_CTRL_RXSTALLDEC_Msk   (_UINT32_(0x1) << USBHS_HSTPIPIDR_CTRL_RXSTALLDEC_Pos) /* (USBHS_HSTPIPIDR) Received STALLed Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_CTRL_RXSTALLDEC(value) (USBHS_HSTPIPIDR_CTRL_RXSTALLDEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_CTRL_RXSTALLDEC_Pos))
#define USBHS_HSTPIPIDR_CTRL_Msk              _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIDR_CTRL) Register Mask  */

/* ISO mode */
#define USBHS_HSTPIPIDR_ISO_UNDERFIEC_Pos     _UINT32_(2)                                          /* (USBHS_HSTPIPIDR) Underflow Interrupt Disable Position */
#define USBHS_HSTPIPIDR_ISO_UNDERFIEC_Msk     (_UINT32_(0x1) << USBHS_HSTPIPIDR_ISO_UNDERFIEC_Pos) /* (USBHS_HSTPIPIDR) Underflow Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_ISO_UNDERFIEC(value)  (USBHS_HSTPIPIDR_ISO_UNDERFIEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_ISO_UNDERFIEC_Pos))
#define USBHS_HSTPIPIDR_ISO_CRCERREC_Pos      _UINT32_(6)                                          /* (USBHS_HSTPIPIDR) CRC Error Interrupt Disable Position */
#define USBHS_HSTPIPIDR_ISO_CRCERREC_Msk      (_UINT32_(0x1) << USBHS_HSTPIPIDR_ISO_CRCERREC_Pos)  /* (USBHS_HSTPIPIDR) CRC Error Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_ISO_CRCERREC(value)   (USBHS_HSTPIPIDR_ISO_CRCERREC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_ISO_CRCERREC_Pos))
#define USBHS_HSTPIPIDR_ISO_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIDR_ISO) Register Mask  */

/* BLK mode */
#define USBHS_HSTPIPIDR_BLK_TXSTPEC_Pos       _UINT32_(2)                                          /* (USBHS_HSTPIPIDR) Transmitted SETUP Interrupt Disable Position */
#define USBHS_HSTPIPIDR_BLK_TXSTPEC_Msk       (_UINT32_(0x1) << USBHS_HSTPIPIDR_BLK_TXSTPEC_Pos)   /* (USBHS_HSTPIPIDR) Transmitted SETUP Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_BLK_TXSTPEC(value)    (USBHS_HSTPIPIDR_BLK_TXSTPEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_BLK_TXSTPEC_Pos))
#define USBHS_HSTPIPIDR_BLK_RXSTALLDEC_Pos    _UINT32_(6)                                          /* (USBHS_HSTPIPIDR) Received STALLed Interrupt Disable Position */
#define USBHS_HSTPIPIDR_BLK_RXSTALLDEC_Msk    (_UINT32_(0x1) << USBHS_HSTPIPIDR_BLK_RXSTALLDEC_Pos) /* (USBHS_HSTPIPIDR) Received STALLed Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_BLK_RXSTALLDEC(value) (USBHS_HSTPIPIDR_BLK_RXSTALLDEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_BLK_RXSTALLDEC_Pos))
#define USBHS_HSTPIPIDR_BLK_Msk               _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIDR_BLK) Register Mask  */

/* INTRPT mode */
#define USBHS_HSTPIPIDR_INTRPT_UNDERFIEC_Pos  _UINT32_(2)                                          /* (USBHS_HSTPIPIDR) Underflow Interrupt Disable Position */
#define USBHS_HSTPIPIDR_INTRPT_UNDERFIEC_Msk  (_UINT32_(0x1) << USBHS_HSTPIPIDR_INTRPT_UNDERFIEC_Pos) /* (USBHS_HSTPIPIDR) Underflow Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_INTRPT_UNDERFIEC(value) (USBHS_HSTPIPIDR_INTRPT_UNDERFIEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_INTRPT_UNDERFIEC_Pos))
#define USBHS_HSTPIPIDR_INTRPT_RXSTALLDEC_Pos _UINT32_(6)                                          /* (USBHS_HSTPIPIDR) Received STALLed Interrupt Disable Position */
#define USBHS_HSTPIPIDR_INTRPT_RXSTALLDEC_Msk (_UINT32_(0x1) << USBHS_HSTPIPIDR_INTRPT_RXSTALLDEC_Pos) /* (USBHS_HSTPIPIDR) Received STALLed Interrupt Disable Mask */
#define USBHS_HSTPIPIDR_INTRPT_RXSTALLDEC(value) (USBHS_HSTPIPIDR_INTRPT_RXSTALLDEC_Msk & (_UINT32_(value) << USBHS_HSTPIPIDR_INTRPT_RXSTALLDEC_Pos))
#define USBHS_HSTPIPIDR_INTRPT_Msk            _UINT32_(0x00000044)                                  /* (USBHS_HSTPIPIDR_INTRPT) Register Mask  */


/* -------- USBHS_HSTPIPINRQ : (USBHS Offset: 0x650) (R/W 32) Host Pipe IN Request Register -------- */
#define USBHS_HSTPIPINRQ_INRQ_Pos             _UINT32_(0)                                          /* (USBHS_HSTPIPINRQ) IN Request Number before Freeze Position */
#define USBHS_HSTPIPINRQ_INRQ_Msk             (_UINT32_(0xFF) << USBHS_HSTPIPINRQ_INRQ_Pos)        /* (USBHS_HSTPIPINRQ) IN Request Number before Freeze Mask */
#define USBHS_HSTPIPINRQ_INRQ(value)          (USBHS_HSTPIPINRQ_INRQ_Msk & (_UINT32_(value) << USBHS_HSTPIPINRQ_INRQ_Pos)) /* Assigment of value for INRQ in the USBHS_HSTPIPINRQ register */
#define USBHS_HSTPIPINRQ_INMODE_Pos           _UINT32_(8)                                          /* (USBHS_HSTPIPINRQ) IN Request Mode Position */
#define USBHS_HSTPIPINRQ_INMODE_Msk           (_UINT32_(0x1) << USBHS_HSTPIPINRQ_INMODE_Pos)       /* (USBHS_HSTPIPINRQ) IN Request Mode Mask */
#define USBHS_HSTPIPINRQ_INMODE(value)        (USBHS_HSTPIPINRQ_INMODE_Msk & (_UINT32_(value) << USBHS_HSTPIPINRQ_INMODE_Pos)) /* Assigment of value for INMODE in the USBHS_HSTPIPINRQ register */
#define USBHS_HSTPIPINRQ_Msk                  _UINT32_(0x000001FF)                                 /* (USBHS_HSTPIPINRQ) Register Mask  */


/* -------- USBHS_HSTPIPERR : (USBHS Offset: 0x680) (R/W 32) Host Pipe Error Register -------- */
#define USBHS_HSTPIPERR_DATATGL_Pos           _UINT32_(0)                                          /* (USBHS_HSTPIPERR) Data Toggle Error Position */
#define USBHS_HSTPIPERR_DATATGL_Msk           (_UINT32_(0x1) << USBHS_HSTPIPERR_DATATGL_Pos)       /* (USBHS_HSTPIPERR) Data Toggle Error Mask */
#define USBHS_HSTPIPERR_DATATGL(value)        (USBHS_HSTPIPERR_DATATGL_Msk & (_UINT32_(value) << USBHS_HSTPIPERR_DATATGL_Pos)) /* Assigment of value for DATATGL in the USBHS_HSTPIPERR register */
#define USBHS_HSTPIPERR_DATAPID_Pos           _UINT32_(1)                                          /* (USBHS_HSTPIPERR) Data PID Error Position */
#define USBHS_HSTPIPERR_DATAPID_Msk           (_UINT32_(0x1) << USBHS_HSTPIPERR_DATAPID_Pos)       /* (USBHS_HSTPIPERR) Data PID Error Mask */
#define USBHS_HSTPIPERR_DATAPID(value)        (USBHS_HSTPIPERR_DATAPID_Msk & (_UINT32_(value) << USBHS_HSTPIPERR_DATAPID_Pos)) /* Assigment of value for DATAPID in the USBHS_HSTPIPERR register */
#define USBHS_HSTPIPERR_PID_Pos               _UINT32_(2)                                          /* (USBHS_HSTPIPERR) Data PID Error Position */
#define USBHS_HSTPIPERR_PID_Msk               (_UINT32_(0x1) << USBHS_HSTPIPERR_PID_Pos)           /* (USBHS_HSTPIPERR) Data PID Error Mask */
#define USBHS_HSTPIPERR_PID(value)            (USBHS_HSTPIPERR_PID_Msk & (_UINT32_(value) << USBHS_HSTPIPERR_PID_Pos)) /* Assigment of value for PID in the USBHS_HSTPIPERR register */
#define USBHS_HSTPIPERR_TIMEOUT_Pos           _UINT32_(3)                                          /* (USBHS_HSTPIPERR) Time-Out Error Position */
#define USBHS_HSTPIPERR_TIMEOUT_Msk           (_UINT32_(0x1) << USBHS_HSTPIPERR_TIMEOUT_Pos)       /* (USBHS_HSTPIPERR) Time-Out Error Mask */
#define USBHS_HSTPIPERR_TIMEOUT(value)        (USBHS_HSTPIPERR_TIMEOUT_Msk & (_UINT32_(value) << USBHS_HSTPIPERR_TIMEOUT_Pos)) /* Assigment of value for TIMEOUT in the USBHS_HSTPIPERR register */
#define USBHS_HSTPIPERR_CRC16_Pos             _UINT32_(4)                                          /* (USBHS_HSTPIPERR) CRC16 Error Position */
#define USBHS_HSTPIPERR_CRC16_Msk             (_UINT32_(0x1) << USBHS_HSTPIPERR_CRC16_Pos)         /* (USBHS_HSTPIPERR) CRC16 Error Mask */
#define USBHS_HSTPIPERR_CRC16(value)          (USBHS_HSTPIPERR_CRC16_Msk & (_UINT32_(value) << USBHS_HSTPIPERR_CRC16_Pos)) /* Assigment of value for CRC16 in the USBHS_HSTPIPERR register */
#define USBHS_HSTPIPERR_COUNTER_Pos           _UINT32_(5)                                          /* (USBHS_HSTPIPERR) Error Counter Position */
#define USBHS_HSTPIPERR_COUNTER_Msk           (_UINT32_(0x3) << USBHS_HSTPIPERR_COUNTER_Pos)       /* (USBHS_HSTPIPERR) Error Counter Mask */
#define USBHS_HSTPIPERR_COUNTER(value)        (USBHS_HSTPIPERR_COUNTER_Msk & (_UINT32_(value) << USBHS_HSTPIPERR_COUNTER_Pos)) /* Assigment of value for COUNTER in the USBHS_HSTPIPERR register */
#define USBHS_HSTPIPERR_Msk                   _UINT32_(0x0000007F)                                 /* (USBHS_HSTPIPERR) Register Mask  */

#define USBHS_HSTPIPERR_CRC_Pos               _UINT32_(4)                                          /* (USBHS_HSTPIPERR Position) CRCx6 Error */
#define USBHS_HSTPIPERR_CRC_Msk               (_UINT32_(0x1) << USBHS_HSTPIPERR_CRC_Pos)           /* (USBHS_HSTPIPERR Mask) CRC */
#define USBHS_HSTPIPERR_CRC(value)            (USBHS_HSTPIPERR_CRC_Msk & (_UINT32_(value) << USBHS_HSTPIPERR_CRC_Pos)) 

/* -------- USBHS_CTRL : (USBHS Offset: 0x800) (R/W 32) General Control Register -------- */
#define USBHS_CTRL_RDERRE_Pos                 _UINT32_(4)                                          /* (USBHS_CTRL) Remote Device Connection Error Interrupt Enable Position */
#define USBHS_CTRL_RDERRE_Msk                 (_UINT32_(0x1) << USBHS_CTRL_RDERRE_Pos)             /* (USBHS_CTRL) Remote Device Connection Error Interrupt Enable Mask */
#define USBHS_CTRL_RDERRE(value)              (USBHS_CTRL_RDERRE_Msk & (_UINT32_(value) << USBHS_CTRL_RDERRE_Pos)) /* Assigment of value for RDERRE in the USBHS_CTRL register */
#define USBHS_CTRL_VBUSHWC_Pos                _UINT32_(8)                                          /* (USBHS_CTRL) VBUS Hardware Control Position */
#define USBHS_CTRL_VBUSHWC_Msk                (_UINT32_(0x1) << USBHS_CTRL_VBUSHWC_Pos)            /* (USBHS_CTRL) VBUS Hardware Control Mask */
#define USBHS_CTRL_VBUSHWC(value)             (USBHS_CTRL_VBUSHWC_Msk & (_UINT32_(value) << USBHS_CTRL_VBUSHWC_Pos)) /* Assigment of value for VBUSHWC in the USBHS_CTRL register */
#define USBHS_CTRL_FRZCLK_Pos                 _UINT32_(14)                                         /* (USBHS_CTRL) Freeze USB Clock Position */
#define USBHS_CTRL_FRZCLK_Msk                 (_UINT32_(0x1) << USBHS_CTRL_FRZCLK_Pos)             /* (USBHS_CTRL) Freeze USB Clock Mask */
#define USBHS_CTRL_FRZCLK(value)              (USBHS_CTRL_FRZCLK_Msk & (_UINT32_(value) << USBHS_CTRL_FRZCLK_Pos)) /* Assigment of value for FRZCLK in the USBHS_CTRL register */
#define USBHS_CTRL_USBE_Pos                   _UINT32_(15)                                         /* (USBHS_CTRL) USBHS Enable Position */
#define USBHS_CTRL_USBE_Msk                   (_UINT32_(0x1) << USBHS_CTRL_USBE_Pos)               /* (USBHS_CTRL) USBHS Enable Mask */
#define USBHS_CTRL_USBE(value)                (USBHS_CTRL_USBE_Msk & (_UINT32_(value) << USBHS_CTRL_USBE_Pos)) /* Assigment of value for USBE in the USBHS_CTRL register */
#define USBHS_CTRL_UID_Pos                    _UINT32_(24)                                         /* (USBHS_CTRL) UID Pin Enable Position */
#define USBHS_CTRL_UID_Msk                    (_UINT32_(0x1) << USBHS_CTRL_UID_Pos)                /* (USBHS_CTRL) UID Pin Enable Mask */
#define USBHS_CTRL_UID(value)                 (USBHS_CTRL_UID_Msk & (_UINT32_(value) << USBHS_CTRL_UID_Pos)) /* Assigment of value for UID in the USBHS_CTRL register */
#define USBHS_CTRL_UIMOD_Pos                  _UINT32_(25)                                         /* (USBHS_CTRL) USBHS Mode Position */
#define USBHS_CTRL_UIMOD_Msk                  (_UINT32_(0x1) << USBHS_CTRL_UIMOD_Pos)              /* (USBHS_CTRL) USBHS Mode Mask */
#define USBHS_CTRL_UIMOD(value)               (USBHS_CTRL_UIMOD_Msk & (_UINT32_(value) << USBHS_CTRL_UIMOD_Pos)) /* Assigment of value for UIMOD in the USBHS_CTRL register */
#define   USBHS_CTRL_UIMOD_HOST_Val           _UINT32_(0x0)                                        /* (USBHS_CTRL) The module is in USB Host mode.  */
#define   USBHS_CTRL_UIMOD_DEVICE_Val         _UINT32_(0x1)                                        /* (USBHS_CTRL) The module is in USB Device mode.  */
#define USBHS_CTRL_UIMOD_HOST                 (USBHS_CTRL_UIMOD_HOST_Val << USBHS_CTRL_UIMOD_Pos)  /* (USBHS_CTRL) The module is in USB Host mode. Position  */
#define USBHS_CTRL_UIMOD_DEVICE               (USBHS_CTRL_UIMOD_DEVICE_Val << USBHS_CTRL_UIMOD_Pos) /* (USBHS_CTRL) The module is in USB Device mode. Position  */
#define USBHS_CTRL_Msk                        _UINT32_(0x0300C110)                                 /* (USBHS_CTRL) Register Mask  */


/* -------- USBHS_SR : (USBHS Offset: 0x804) ( R/ 32) General Status Register -------- */
#define USBHS_SR_RDERRI_Pos                   _UINT32_(4)                                          /* (USBHS_SR) Remote Device Connection Error Interrupt (Host mode only) Position */
#define USBHS_SR_RDERRI_Msk                   (_UINT32_(0x1) << USBHS_SR_RDERRI_Pos)               /* (USBHS_SR) Remote Device Connection Error Interrupt (Host mode only) Mask */
#define USBHS_SR_RDERRI(value)                (USBHS_SR_RDERRI_Msk & (_UINT32_(value) << USBHS_SR_RDERRI_Pos)) /* Assigment of value for RDERRI in the USBHS_SR register */
#define USBHS_SR_SPEED_Pos                    _UINT32_(12)                                         /* (USBHS_SR) Speed Status (Device mode only) Position */
#define USBHS_SR_SPEED_Msk                    (_UINT32_(0x3) << USBHS_SR_SPEED_Pos)                /* (USBHS_SR) Speed Status (Device mode only) Mask */
#define USBHS_SR_SPEED(value)                 (USBHS_SR_SPEED_Msk & (_UINT32_(value) << USBHS_SR_SPEED_Pos)) /* Assigment of value for SPEED in the USBHS_SR register */
#define   USBHS_SR_SPEED_FULL_SPEED_Val       _UINT32_(0x0)                                        /* (USBHS_SR) Full-Speed mode  */
#define   USBHS_SR_SPEED_HIGH_SPEED_Val       _UINT32_(0x1)                                        /* (USBHS_SR) High-Speed mode  */
#define   USBHS_SR_SPEED_LOW_SPEED_Val        _UINT32_(0x2)                                        /* (USBHS_SR) Low-Speed mode  */
#define USBHS_SR_SPEED_FULL_SPEED             (USBHS_SR_SPEED_FULL_SPEED_Val << USBHS_SR_SPEED_Pos) /* (USBHS_SR) Full-Speed mode Position  */
#define USBHS_SR_SPEED_HIGH_SPEED             (USBHS_SR_SPEED_HIGH_SPEED_Val << USBHS_SR_SPEED_Pos) /* (USBHS_SR) High-Speed mode Position  */
#define USBHS_SR_SPEED_LOW_SPEED              (USBHS_SR_SPEED_LOW_SPEED_Val << USBHS_SR_SPEED_Pos) /* (USBHS_SR) Low-Speed mode Position  */
#define USBHS_SR_CLKUSABLE_Pos                _UINT32_(14)                                         /* (USBHS_SR) UTMI Clock Usable Position */
#define USBHS_SR_CLKUSABLE_Msk                (_UINT32_(0x1) << USBHS_SR_CLKUSABLE_Pos)            /* (USBHS_SR) UTMI Clock Usable Mask */
#define USBHS_SR_CLKUSABLE(value)             (USBHS_SR_CLKUSABLE_Msk & (_UINT32_(value) << USBHS_SR_CLKUSABLE_Pos)) /* Assigment of value for CLKUSABLE in the USBHS_SR register */
#define USBHS_SR_Msk                          _UINT32_(0x00007010)                                 /* (USBHS_SR) Register Mask  */


/* -------- USBHS_SCR : (USBHS Offset: 0x808) ( /W 32) General Status Clear Register -------- */
#define USBHS_SCR_RDERRIC_Pos                 _UINT32_(4)                                          /* (USBHS_SCR) Remote Device Connection Error Interrupt Clear Position */
#define USBHS_SCR_RDERRIC_Msk                 (_UINT32_(0x1) << USBHS_SCR_RDERRIC_Pos)             /* (USBHS_SCR) Remote Device Connection Error Interrupt Clear Mask */
#define USBHS_SCR_RDERRIC(value)              (USBHS_SCR_RDERRIC_Msk & (_UINT32_(value) << USBHS_SCR_RDERRIC_Pos)) /* Assigment of value for RDERRIC in the USBHS_SCR register */
#define USBHS_SCR_Msk                         _UINT32_(0x00000010)                                 /* (USBHS_SCR) Register Mask  */


/* -------- USBHS_SFR : (USBHS Offset: 0x80C) ( /W 32) General Status Set Register -------- */
#define USBHS_SFR_RDERRIS_Pos                 _UINT32_(4)                                          /* (USBHS_SFR) Remote Device Connection Error Interrupt Set Position */
#define USBHS_SFR_RDERRIS_Msk                 (_UINT32_(0x1) << USBHS_SFR_RDERRIS_Pos)             /* (USBHS_SFR) Remote Device Connection Error Interrupt Set Mask */
#define USBHS_SFR_RDERRIS(value)              (USBHS_SFR_RDERRIS_Msk & (_UINT32_(value) << USBHS_SFR_RDERRIS_Pos)) /* Assigment of value for RDERRIS in the USBHS_SFR register */
#define USBHS_SFR_VBUSRQS_Pos                 _UINT32_(9)                                          /* (USBHS_SFR) VBUS Request Set Position */
#define USBHS_SFR_VBUSRQS_Msk                 (_UINT32_(0x1) << USBHS_SFR_VBUSRQS_Pos)             /* (USBHS_SFR) VBUS Request Set Mask */
#define USBHS_SFR_VBUSRQS(value)              (USBHS_SFR_VBUSRQS_Msk & (_UINT32_(value) << USBHS_SFR_VBUSRQS_Pos)) /* Assigment of value for VBUSRQS in the USBHS_SFR register */
#define USBHS_SFR_Msk                         _UINT32_(0x00000210)                                 /* (USBHS_SFR) Register Mask  */


/** \brief USBHS register offsets definitions */
#define USBHS_DEVDMANXTDSC_REG_OFST    _UINT32_(0x00)      /* (USBHS_DEVDMANXTDSC) Device DMA Channel Next Descriptor Address Register Offset */
#define USBHS_DEVDMAADDRESS_REG_OFST   _UINT32_(0x04)      /* (USBHS_DEVDMAADDRESS) Device DMA Channel Address Register Offset */
#define USBHS_DEVDMACONTROL_REG_OFST   _UINT32_(0x08)      /* (USBHS_DEVDMACONTROL) Device DMA Channel Control Register Offset */
#define USBHS_DEVDMASTATUS_REG_OFST    _UINT32_(0x0C)      /* (USBHS_DEVDMASTATUS) Device DMA Channel Status Register Offset */
#define USBHS_HSTDMANXTDSC_REG_OFST    _UINT32_(0x00)      /* (USBHS_HSTDMANXTDSC) Host DMA Channel Next Descriptor Address Register Offset */
#define USBHS_HSTDMAADDRESS_REG_OFST   _UINT32_(0x04)      /* (USBHS_HSTDMAADDRESS) Host DMA Channel Address Register Offset */
#define USBHS_HSTDMACONTROL_REG_OFST   _UINT32_(0x08)      /* (USBHS_HSTDMACONTROL) Host DMA Channel Control Register Offset */
#define USBHS_HSTDMASTATUS_REG_OFST    _UINT32_(0x0C)      /* (USBHS_HSTDMASTATUS) Host DMA Channel Status Register Offset */
#define USBHS_DEVCTRL_REG_OFST         _UINT32_(0x00)      /* (USBHS_DEVCTRL) Device General Control Register Offset */
#define USBHS_DEVISR_REG_OFST          _UINT32_(0x04)      /* (USBHS_DEVISR) Device Global Interrupt Status Register Offset */
#define USBHS_DEVICR_REG_OFST          _UINT32_(0x08)      /* (USBHS_DEVICR) Device Global Interrupt Clear Register Offset */
#define USBHS_DEVIFR_REG_OFST          _UINT32_(0x0C)      /* (USBHS_DEVIFR) Device Global Interrupt Set Register Offset */
#define USBHS_DEVIMR_REG_OFST          _UINT32_(0x10)      /* (USBHS_DEVIMR) Device Global Interrupt Mask Register Offset */
#define USBHS_DEVIDR_REG_OFST          _UINT32_(0x14)      /* (USBHS_DEVIDR) Device Global Interrupt Disable Register Offset */
#define USBHS_DEVIER_REG_OFST          _UINT32_(0x18)      /* (USBHS_DEVIER) Device Global Interrupt Enable Register Offset */
#define USBHS_DEVEPT_REG_OFST          _UINT32_(0x1C)      /* (USBHS_DEVEPT) Device Endpoint Register Offset */
#define USBHS_DEVFNUM_REG_OFST         _UINT32_(0x20)      /* (USBHS_DEVFNUM) Device Frame Number Register Offset */
#define USBHS_DEVEPTCFG_REG_OFST       _UINT32_(0x100)     /* (USBHS_DEVEPTCFG) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTCFG0_REG_OFST      _UINT32_(0x100)     /* (USBHS_DEVEPTCFG0) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTCFG1_REG_OFST      _UINT32_(0x104)     /* (USBHS_DEVEPTCFG1) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTCFG2_REG_OFST      _UINT32_(0x108)     /* (USBHS_DEVEPTCFG2) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTCFG3_REG_OFST      _UINT32_(0x10C)     /* (USBHS_DEVEPTCFG3) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTCFG4_REG_OFST      _UINT32_(0x110)     /* (USBHS_DEVEPTCFG4) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTCFG5_REG_OFST      _UINT32_(0x114)     /* (USBHS_DEVEPTCFG5) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTCFG6_REG_OFST      _UINT32_(0x118)     /* (USBHS_DEVEPTCFG6) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTCFG7_REG_OFST      _UINT32_(0x11C)     /* (USBHS_DEVEPTCFG7) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTCFG8_REG_OFST      _UINT32_(0x120)     /* (USBHS_DEVEPTCFG8) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTCFG9_REG_OFST      _UINT32_(0x124)     /* (USBHS_DEVEPTCFG9) Device Endpoint Configuration Register Offset */
#define USBHS_DEVEPTISR_REG_OFST       _UINT32_(0x130)     /* (USBHS_DEVEPTISR) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTISR0_REG_OFST      _UINT32_(0x130)     /* (USBHS_DEVEPTISR0) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTISR1_REG_OFST      _UINT32_(0x134)     /* (USBHS_DEVEPTISR1) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTISR2_REG_OFST      _UINT32_(0x138)     /* (USBHS_DEVEPTISR2) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTISR3_REG_OFST      _UINT32_(0x13C)     /* (USBHS_DEVEPTISR3) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTISR4_REG_OFST      _UINT32_(0x140)     /* (USBHS_DEVEPTISR4) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTISR5_REG_OFST      _UINT32_(0x144)     /* (USBHS_DEVEPTISR5) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTISR6_REG_OFST      _UINT32_(0x148)     /* (USBHS_DEVEPTISR6) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTISR7_REG_OFST      _UINT32_(0x14C)     /* (USBHS_DEVEPTISR7) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTISR8_REG_OFST      _UINT32_(0x150)     /* (USBHS_DEVEPTISR8) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTISR9_REG_OFST      _UINT32_(0x154)     /* (USBHS_DEVEPTISR9) Device Endpoint Interrupt Status Register Offset */
#define USBHS_DEVEPTICR_REG_OFST       _UINT32_(0x160)     /* (USBHS_DEVEPTICR) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTICR0_REG_OFST      _UINT32_(0x160)     /* (USBHS_DEVEPTICR0) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTICR1_REG_OFST      _UINT32_(0x164)     /* (USBHS_DEVEPTICR1) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTICR2_REG_OFST      _UINT32_(0x168)     /* (USBHS_DEVEPTICR2) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTICR3_REG_OFST      _UINT32_(0x16C)     /* (USBHS_DEVEPTICR3) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTICR4_REG_OFST      _UINT32_(0x170)     /* (USBHS_DEVEPTICR4) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTICR5_REG_OFST      _UINT32_(0x174)     /* (USBHS_DEVEPTICR5) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTICR6_REG_OFST      _UINT32_(0x178)     /* (USBHS_DEVEPTICR6) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTICR7_REG_OFST      _UINT32_(0x17C)     /* (USBHS_DEVEPTICR7) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTICR8_REG_OFST      _UINT32_(0x180)     /* (USBHS_DEVEPTICR8) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTICR9_REG_OFST      _UINT32_(0x184)     /* (USBHS_DEVEPTICR9) Device Endpoint Interrupt Clear Register Offset */
#define USBHS_DEVEPTIFR_REG_OFST       _UINT32_(0x190)     /* (USBHS_DEVEPTIFR) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIFR0_REG_OFST      _UINT32_(0x190)     /* (USBHS_DEVEPTIFR0) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIFR1_REG_OFST      _UINT32_(0x194)     /* (USBHS_DEVEPTIFR1) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIFR2_REG_OFST      _UINT32_(0x198)     /* (USBHS_DEVEPTIFR2) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIFR3_REG_OFST      _UINT32_(0x19C)     /* (USBHS_DEVEPTIFR3) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIFR4_REG_OFST      _UINT32_(0x1A0)     /* (USBHS_DEVEPTIFR4) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIFR5_REG_OFST      _UINT32_(0x1A4)     /* (USBHS_DEVEPTIFR5) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIFR6_REG_OFST      _UINT32_(0x1A8)     /* (USBHS_DEVEPTIFR6) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIFR7_REG_OFST      _UINT32_(0x1AC)     /* (USBHS_DEVEPTIFR7) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIFR8_REG_OFST      _UINT32_(0x1B0)     /* (USBHS_DEVEPTIFR8) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIFR9_REG_OFST      _UINT32_(0x1B4)     /* (USBHS_DEVEPTIFR9) Device Endpoint Interrupt Set Register Offset */
#define USBHS_DEVEPTIMR_REG_OFST       _UINT32_(0x1C0)     /* (USBHS_DEVEPTIMR) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIMR0_REG_OFST      _UINT32_(0x1C0)     /* (USBHS_DEVEPTIMR0) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIMR1_REG_OFST      _UINT32_(0x1C4)     /* (USBHS_DEVEPTIMR1) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIMR2_REG_OFST      _UINT32_(0x1C8)     /* (USBHS_DEVEPTIMR2) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIMR3_REG_OFST      _UINT32_(0x1CC)     /* (USBHS_DEVEPTIMR3) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIMR4_REG_OFST      _UINT32_(0x1D0)     /* (USBHS_DEVEPTIMR4) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIMR5_REG_OFST      _UINT32_(0x1D4)     /* (USBHS_DEVEPTIMR5) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIMR6_REG_OFST      _UINT32_(0x1D8)     /* (USBHS_DEVEPTIMR6) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIMR7_REG_OFST      _UINT32_(0x1DC)     /* (USBHS_DEVEPTIMR7) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIMR8_REG_OFST      _UINT32_(0x1E0)     /* (USBHS_DEVEPTIMR8) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIMR9_REG_OFST      _UINT32_(0x1E4)     /* (USBHS_DEVEPTIMR9) Device Endpoint Interrupt Mask Register Offset */
#define USBHS_DEVEPTIER_REG_OFST       _UINT32_(0x1F0)     /* (USBHS_DEVEPTIER) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIER0_REG_OFST      _UINT32_(0x1F0)     /* (USBHS_DEVEPTIER0) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIER1_REG_OFST      _UINT32_(0x1F4)     /* (USBHS_DEVEPTIER1) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIER2_REG_OFST      _UINT32_(0x1F8)     /* (USBHS_DEVEPTIER2) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIER3_REG_OFST      _UINT32_(0x1FC)     /* (USBHS_DEVEPTIER3) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIER4_REG_OFST      _UINT32_(0x200)     /* (USBHS_DEVEPTIER4) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIER5_REG_OFST      _UINT32_(0x204)     /* (USBHS_DEVEPTIER5) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIER6_REG_OFST      _UINT32_(0x208)     /* (USBHS_DEVEPTIER6) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIER7_REG_OFST      _UINT32_(0x20C)     /* (USBHS_DEVEPTIER7) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIER8_REG_OFST      _UINT32_(0x210)     /* (USBHS_DEVEPTIER8) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIER9_REG_OFST      _UINT32_(0x214)     /* (USBHS_DEVEPTIER9) Device Endpoint Interrupt Enable Register Offset */
#define USBHS_DEVEPTIDR_REG_OFST       _UINT32_(0x220)     /* (USBHS_DEVEPTIDR) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_DEVEPTIDR0_REG_OFST      _UINT32_(0x220)     /* (USBHS_DEVEPTIDR0) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_DEVEPTIDR1_REG_OFST      _UINT32_(0x224)     /* (USBHS_DEVEPTIDR1) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_DEVEPTIDR2_REG_OFST      _UINT32_(0x228)     /* (USBHS_DEVEPTIDR2) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_DEVEPTIDR3_REG_OFST      _UINT32_(0x22C)     /* (USBHS_DEVEPTIDR3) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_DEVEPTIDR4_REG_OFST      _UINT32_(0x230)     /* (USBHS_DEVEPTIDR4) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_DEVEPTIDR5_REG_OFST      _UINT32_(0x234)     /* (USBHS_DEVEPTIDR5) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_DEVEPTIDR6_REG_OFST      _UINT32_(0x238)     /* (USBHS_DEVEPTIDR6) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_DEVEPTIDR7_REG_OFST      _UINT32_(0x23C)     /* (USBHS_DEVEPTIDR7) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_DEVEPTIDR8_REG_OFST      _UINT32_(0x240)     /* (USBHS_DEVEPTIDR8) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_DEVEPTIDR9_REG_OFST      _UINT32_(0x244)     /* (USBHS_DEVEPTIDR9) Device Endpoint Interrupt Disable Register Offset */
#define USBHS_HSTCTRL_REG_OFST         _UINT32_(0x400)     /* (USBHS_HSTCTRL) Host General Control Register Offset */
#define USBHS_HSTISR_REG_OFST          _UINT32_(0x404)     /* (USBHS_HSTISR) Host Global Interrupt Status Register Offset */
#define USBHS_HSTICR_REG_OFST          _UINT32_(0x408)     /* (USBHS_HSTICR) Host Global Interrupt Clear Register Offset */
#define USBHS_HSTIFR_REG_OFST          _UINT32_(0x40C)     /* (USBHS_HSTIFR) Host Global Interrupt Set Register Offset */
#define USBHS_HSTIMR_REG_OFST          _UINT32_(0x410)     /* (USBHS_HSTIMR) Host Global Interrupt Mask Register Offset */
#define USBHS_HSTIDR_REG_OFST          _UINT32_(0x414)     /* (USBHS_HSTIDR) Host Global Interrupt Disable Register Offset */
#define USBHS_HSTIER_REG_OFST          _UINT32_(0x418)     /* (USBHS_HSTIER) Host Global Interrupt Enable Register Offset */
#define USBHS_HSTPIP_REG_OFST          _UINT32_(0x41C)     /* (USBHS_HSTPIP) Host Pipe Register Offset */
#define USBHS_HSTFNUM_REG_OFST         _UINT32_(0x420)     /* (USBHS_HSTFNUM) Host Frame Number Register Offset */
#define USBHS_HSTADDR1_REG_OFST        _UINT32_(0x424)     /* (USBHS_HSTADDR1) Host Address 1 Register Offset */
#define USBHS_HSTADDR2_REG_OFST        _UINT32_(0x428)     /* (USBHS_HSTADDR2) Host Address 2 Register Offset */
#define USBHS_HSTADDR3_REG_OFST        _UINT32_(0x42C)     /* (USBHS_HSTADDR3) Host Address 3 Register Offset */
#define USBHS_HSTPIPCFG_REG_OFST       _UINT32_(0x500)     /* (USBHS_HSTPIPCFG) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPCFG0_REG_OFST      _UINT32_(0x500)     /* (USBHS_HSTPIPCFG0) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPCFG1_REG_OFST      _UINT32_(0x504)     /* (USBHS_HSTPIPCFG1) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPCFG2_REG_OFST      _UINT32_(0x508)     /* (USBHS_HSTPIPCFG2) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPCFG3_REG_OFST      _UINT32_(0x50C)     /* (USBHS_HSTPIPCFG3) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPCFG4_REG_OFST      _UINT32_(0x510)     /* (USBHS_HSTPIPCFG4) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPCFG5_REG_OFST      _UINT32_(0x514)     /* (USBHS_HSTPIPCFG5) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPCFG6_REG_OFST      _UINT32_(0x518)     /* (USBHS_HSTPIPCFG6) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPCFG7_REG_OFST      _UINT32_(0x51C)     /* (USBHS_HSTPIPCFG7) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPCFG8_REG_OFST      _UINT32_(0x520)     /* (USBHS_HSTPIPCFG8) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPCFG9_REG_OFST      _UINT32_(0x524)     /* (USBHS_HSTPIPCFG9) Host Pipe Configuration Register Offset */
#define USBHS_HSTPIPISR_REG_OFST       _UINT32_(0x530)     /* (USBHS_HSTPIPISR) Host Pipe Status Register Offset */
#define USBHS_HSTPIPISR0_REG_OFST      _UINT32_(0x530)     /* (USBHS_HSTPIPISR0) Host Pipe Status Register Offset */
#define USBHS_HSTPIPISR1_REG_OFST      _UINT32_(0x534)     /* (USBHS_HSTPIPISR1) Host Pipe Status Register Offset */
#define USBHS_HSTPIPISR2_REG_OFST      _UINT32_(0x538)     /* (USBHS_HSTPIPISR2) Host Pipe Status Register Offset */
#define USBHS_HSTPIPISR3_REG_OFST      _UINT32_(0x53C)     /* (USBHS_HSTPIPISR3) Host Pipe Status Register Offset */
#define USBHS_HSTPIPISR4_REG_OFST      _UINT32_(0x540)     /* (USBHS_HSTPIPISR4) Host Pipe Status Register Offset */
#define USBHS_HSTPIPISR5_REG_OFST      _UINT32_(0x544)     /* (USBHS_HSTPIPISR5) Host Pipe Status Register Offset */
#define USBHS_HSTPIPISR6_REG_OFST      _UINT32_(0x548)     /* (USBHS_HSTPIPISR6) Host Pipe Status Register Offset */
#define USBHS_HSTPIPISR7_REG_OFST      _UINT32_(0x54C)     /* (USBHS_HSTPIPISR7) Host Pipe Status Register Offset */
#define USBHS_HSTPIPISR8_REG_OFST      _UINT32_(0x550)     /* (USBHS_HSTPIPISR8) Host Pipe Status Register Offset */
#define USBHS_HSTPIPISR9_REG_OFST      _UINT32_(0x554)     /* (USBHS_HSTPIPISR9) Host Pipe Status Register Offset */
#define USBHS_HSTPIPICR_REG_OFST       _UINT32_(0x560)     /* (USBHS_HSTPIPICR) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPICR0_REG_OFST      _UINT32_(0x560)     /* (USBHS_HSTPIPICR0) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPICR1_REG_OFST      _UINT32_(0x564)     /* (USBHS_HSTPIPICR1) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPICR2_REG_OFST      _UINT32_(0x568)     /* (USBHS_HSTPIPICR2) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPICR3_REG_OFST      _UINT32_(0x56C)     /* (USBHS_HSTPIPICR3) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPICR4_REG_OFST      _UINT32_(0x570)     /* (USBHS_HSTPIPICR4) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPICR5_REG_OFST      _UINT32_(0x574)     /* (USBHS_HSTPIPICR5) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPICR6_REG_OFST      _UINT32_(0x578)     /* (USBHS_HSTPIPICR6) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPICR7_REG_OFST      _UINT32_(0x57C)     /* (USBHS_HSTPIPICR7) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPICR8_REG_OFST      _UINT32_(0x580)     /* (USBHS_HSTPIPICR8) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPICR9_REG_OFST      _UINT32_(0x584)     /* (USBHS_HSTPIPICR9) Host Pipe Clear Register Offset */
#define USBHS_HSTPIPIFR_REG_OFST       _UINT32_(0x590)     /* (USBHS_HSTPIPIFR) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIFR0_REG_OFST      _UINT32_(0x590)     /* (USBHS_HSTPIPIFR0) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIFR1_REG_OFST      _UINT32_(0x594)     /* (USBHS_HSTPIPIFR1) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIFR2_REG_OFST      _UINT32_(0x598)     /* (USBHS_HSTPIPIFR2) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIFR3_REG_OFST      _UINT32_(0x59C)     /* (USBHS_HSTPIPIFR3) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIFR4_REG_OFST      _UINT32_(0x5A0)     /* (USBHS_HSTPIPIFR4) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIFR5_REG_OFST      _UINT32_(0x5A4)     /* (USBHS_HSTPIPIFR5) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIFR6_REG_OFST      _UINT32_(0x5A8)     /* (USBHS_HSTPIPIFR6) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIFR7_REG_OFST      _UINT32_(0x5AC)     /* (USBHS_HSTPIPIFR7) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIFR8_REG_OFST      _UINT32_(0x5B0)     /* (USBHS_HSTPIPIFR8) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIFR9_REG_OFST      _UINT32_(0x5B4)     /* (USBHS_HSTPIPIFR9) Host Pipe Set Register Offset */
#define USBHS_HSTPIPIMR_REG_OFST       _UINT32_(0x5C0)     /* (USBHS_HSTPIPIMR) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIMR0_REG_OFST      _UINT32_(0x5C0)     /* (USBHS_HSTPIPIMR0) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIMR1_REG_OFST      _UINT32_(0x5C4)     /* (USBHS_HSTPIPIMR1) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIMR2_REG_OFST      _UINT32_(0x5C8)     /* (USBHS_HSTPIPIMR2) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIMR3_REG_OFST      _UINT32_(0x5CC)     /* (USBHS_HSTPIPIMR3) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIMR4_REG_OFST      _UINT32_(0x5D0)     /* (USBHS_HSTPIPIMR4) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIMR5_REG_OFST      _UINT32_(0x5D4)     /* (USBHS_HSTPIPIMR5) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIMR6_REG_OFST      _UINT32_(0x5D8)     /* (USBHS_HSTPIPIMR6) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIMR7_REG_OFST      _UINT32_(0x5DC)     /* (USBHS_HSTPIPIMR7) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIMR8_REG_OFST      _UINT32_(0x5E0)     /* (USBHS_HSTPIPIMR8) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIMR9_REG_OFST      _UINT32_(0x5E4)     /* (USBHS_HSTPIPIMR9) Host Pipe Mask Register Offset */
#define USBHS_HSTPIPIER_REG_OFST       _UINT32_(0x5F0)     /* (USBHS_HSTPIPIER) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIER0_REG_OFST      _UINT32_(0x5F0)     /* (USBHS_HSTPIPIER0) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIER1_REG_OFST      _UINT32_(0x5F4)     /* (USBHS_HSTPIPIER1) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIER2_REG_OFST      _UINT32_(0x5F8)     /* (USBHS_HSTPIPIER2) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIER3_REG_OFST      _UINT32_(0x5FC)     /* (USBHS_HSTPIPIER3) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIER4_REG_OFST      _UINT32_(0x600)     /* (USBHS_HSTPIPIER4) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIER5_REG_OFST      _UINT32_(0x604)     /* (USBHS_HSTPIPIER5) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIER6_REG_OFST      _UINT32_(0x608)     /* (USBHS_HSTPIPIER6) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIER7_REG_OFST      _UINT32_(0x60C)     /* (USBHS_HSTPIPIER7) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIER8_REG_OFST      _UINT32_(0x610)     /* (USBHS_HSTPIPIER8) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIER9_REG_OFST      _UINT32_(0x614)     /* (USBHS_HSTPIPIER9) Host Pipe Enable Register Offset */
#define USBHS_HSTPIPIDR_REG_OFST       _UINT32_(0x620)     /* (USBHS_HSTPIPIDR) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPIDR0_REG_OFST      _UINT32_(0x620)     /* (USBHS_HSTPIPIDR0) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPIDR1_REG_OFST      _UINT32_(0x624)     /* (USBHS_HSTPIPIDR1) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPIDR2_REG_OFST      _UINT32_(0x628)     /* (USBHS_HSTPIPIDR2) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPIDR3_REG_OFST      _UINT32_(0x62C)     /* (USBHS_HSTPIPIDR3) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPIDR4_REG_OFST      _UINT32_(0x630)     /* (USBHS_HSTPIPIDR4) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPIDR5_REG_OFST      _UINT32_(0x634)     /* (USBHS_HSTPIPIDR5) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPIDR6_REG_OFST      _UINT32_(0x638)     /* (USBHS_HSTPIPIDR6) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPIDR7_REG_OFST      _UINT32_(0x63C)     /* (USBHS_HSTPIPIDR7) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPIDR8_REG_OFST      _UINT32_(0x640)     /* (USBHS_HSTPIPIDR8) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPIDR9_REG_OFST      _UINT32_(0x644)     /* (USBHS_HSTPIPIDR9) Host Pipe Disable Register Offset */
#define USBHS_HSTPIPINRQ_REG_OFST      _UINT32_(0x650)     /* (USBHS_HSTPIPINRQ) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPINRQ0_REG_OFST     _UINT32_(0x650)     /* (USBHS_HSTPIPINRQ0) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPINRQ1_REG_OFST     _UINT32_(0x654)     /* (USBHS_HSTPIPINRQ1) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPINRQ2_REG_OFST     _UINT32_(0x658)     /* (USBHS_HSTPIPINRQ2) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPINRQ3_REG_OFST     _UINT32_(0x65C)     /* (USBHS_HSTPIPINRQ3) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPINRQ4_REG_OFST     _UINT32_(0x660)     /* (USBHS_HSTPIPINRQ4) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPINRQ5_REG_OFST     _UINT32_(0x664)     /* (USBHS_HSTPIPINRQ5) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPINRQ6_REG_OFST     _UINT32_(0x668)     /* (USBHS_HSTPIPINRQ6) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPINRQ7_REG_OFST     _UINT32_(0x66C)     /* (USBHS_HSTPIPINRQ7) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPINRQ8_REG_OFST     _UINT32_(0x670)     /* (USBHS_HSTPIPINRQ8) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPINRQ9_REG_OFST     _UINT32_(0x674)     /* (USBHS_HSTPIPINRQ9) Host Pipe IN Request Register Offset */
#define USBHS_HSTPIPERR_REG_OFST       _UINT32_(0x680)     /* (USBHS_HSTPIPERR) Host Pipe Error Register Offset */
#define USBHS_HSTPIPERR0_REG_OFST      _UINT32_(0x680)     /* (USBHS_HSTPIPERR0) Host Pipe Error Register Offset */
#define USBHS_HSTPIPERR1_REG_OFST      _UINT32_(0x684)     /* (USBHS_HSTPIPERR1) Host Pipe Error Register Offset */
#define USBHS_HSTPIPERR2_REG_OFST      _UINT32_(0x688)     /* (USBHS_HSTPIPERR2) Host Pipe Error Register Offset */
#define USBHS_HSTPIPERR3_REG_OFST      _UINT32_(0x68C)     /* (USBHS_HSTPIPERR3) Host Pipe Error Register Offset */
#define USBHS_HSTPIPERR4_REG_OFST      _UINT32_(0x690)     /* (USBHS_HSTPIPERR4) Host Pipe Error Register Offset */
#define USBHS_HSTPIPERR5_REG_OFST      _UINT32_(0x694)     /* (USBHS_HSTPIPERR5) Host Pipe Error Register Offset */
#define USBHS_HSTPIPERR6_REG_OFST      _UINT32_(0x698)     /* (USBHS_HSTPIPERR6) Host Pipe Error Register Offset */
#define USBHS_HSTPIPERR7_REG_OFST      _UINT32_(0x69C)     /* (USBHS_HSTPIPERR7) Host Pipe Error Register Offset */
#define USBHS_HSTPIPERR8_REG_OFST      _UINT32_(0x6A0)     /* (USBHS_HSTPIPERR8) Host Pipe Error Register Offset */
#define USBHS_HSTPIPERR9_REG_OFST      _UINT32_(0x6A4)     /* (USBHS_HSTPIPERR9) Host Pipe Error Register Offset */
#define USBHS_CTRL_REG_OFST            _UINT32_(0x800)     /* (USBHS_CTRL) General Control Register Offset */
#define USBHS_SR_REG_OFST              _UINT32_(0x804)     /* (USBHS_SR) General Status Register Offset */
#define USBHS_SCR_REG_OFST             _UINT32_(0x808)     /* (USBHS_SCR) General Status Clear Register Offset */
#define USBHS_SFR_REG_OFST             _UINT32_(0x80C)     /* (USBHS_SFR) General Status Set Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief USBHS_DEVDMA register API structure */
typedef struct
{
  __IO  uint32_t                       USBHS_DEVDMANXTDSC; /**< Offset: 0x00 (R/W  32) Device DMA Channel Next Descriptor Address Register */
  __IO  uint32_t                       USBHS_DEVDMAADDRESS; /**< Offset: 0x04 (R/W  32) Device DMA Channel Address Register */
  __IO  uint32_t                       USBHS_DEVDMACONTROL; /**< Offset: 0x08 (R/W  32) Device DMA Channel Control Register */
  __IO  uint32_t                       USBHS_DEVDMASTATUS; /**< Offset: 0x0C (R/W  32) Device DMA Channel Status Register */
} usbhs_devdma_registers_t;

/** \brief USBHS_HSTDMA register API structure */
typedef struct
{
  __IO  uint32_t                       USBHS_HSTDMANXTDSC; /**< Offset: 0x00 (R/W  32) Host DMA Channel Next Descriptor Address Register */
  __IO  uint32_t                       USBHS_HSTDMAADDRESS; /**< Offset: 0x04 (R/W  32) Host DMA Channel Address Register */
  __IO  uint32_t                       USBHS_HSTDMACONTROL; /**< Offset: 0x08 (R/W  32) Host DMA Channel Control Register */
  __IO  uint32_t                       USBHS_HSTDMASTATUS; /**< Offset: 0x0C (R/W  32) Host DMA Channel Status Register */
} usbhs_hstdma_registers_t;

#define USBHS_DEVDMA_NUMBER 7

#define USBHS_HSTDMA_NUMBER 7

/** \brief USBHS register API structure */
typedef struct
{
  __IO  uint32_t                       USBHS_DEVCTRL;      /**< Offset: 0x00 (R/W  32) Device General Control Register */
  __I   uint32_t                       USBHS_DEVISR;       /**< Offset: 0x04 (R/   32) Device Global Interrupt Status Register */
  __O   uint32_t                       USBHS_DEVICR;       /**< Offset: 0x08 ( /W  32) Device Global Interrupt Clear Register */
  __O   uint32_t                       USBHS_DEVIFR;       /**< Offset: 0x0C ( /W  32) Device Global Interrupt Set Register */
  __I   uint32_t                       USBHS_DEVIMR;       /**< Offset: 0x10 (R/   32) Device Global Interrupt Mask Register */
  __O   uint32_t                       USBHS_DEVIDR;       /**< Offset: 0x14 ( /W  32) Device Global Interrupt Disable Register */
  __O   uint32_t                       USBHS_DEVIER;       /**< Offset: 0x18 ( /W  32) Device Global Interrupt Enable Register */
  __IO  uint32_t                       USBHS_DEVEPT;       /**< Offset: 0x1C (R/W  32) Device Endpoint Register */
  __I   uint32_t                       USBHS_DEVFNUM;      /**< Offset: 0x20 (R/   32) Device Frame Number Register */
  __I   uint8_t                        Reserved1[0xDC];
  __IO  uint32_t                       USBHS_DEVEPTCFG[10]; /**< Offset: 0x100 (R/W  32) Device Endpoint Configuration Register */
  __I   uint8_t                        Reserved2[0x08];
  __I   uint32_t                       USBHS_DEVEPTISR[10]; /**< Offset: 0x130 (R/   32) Device Endpoint Interrupt Status Register */
  __I   uint8_t                        Reserved3[0x08];
  __O   uint32_t                       USBHS_DEVEPTICR[10]; /**< Offset: 0x160 ( /W  32) Device Endpoint Interrupt Clear Register */
  __I   uint8_t                        Reserved4[0x08];
  __O   uint32_t                       USBHS_DEVEPTIFR[10]; /**< Offset: 0x190 ( /W  32) Device Endpoint Interrupt Set Register */
  __I   uint8_t                        Reserved5[0x08];
  __I   uint32_t                       USBHS_DEVEPTIMR[10]; /**< Offset: 0x1C0 (R/   32) Device Endpoint Interrupt Mask Register */
  __I   uint8_t                        Reserved6[0x08];
  __O   uint32_t                       USBHS_DEVEPTIER[10]; /**< Offset: 0x1F0 ( /W  32) Device Endpoint Interrupt Enable Register */
  __I   uint8_t                        Reserved7[0x08];
  __O   uint32_t                       USBHS_DEVEPTIDR[10]; /**< Offset: 0x220 ( /W  32) Device Endpoint Interrupt Disable Register */
  __I   uint8_t                        Reserved8[0xC8];
        usbhs_devdma_registers_t       USBHS_DEVDMA[USBHS_DEVDMA_NUMBER]; /**< Offset: 0x310 Device DMA Channel Next Descriptor Address Register */
  __I   uint8_t                        Reserved9[0x80];
  __IO  uint32_t                       USBHS_HSTCTRL;      /**< Offset: 0x400 (R/W  32) Host General Control Register */
  __I   uint32_t                       USBHS_HSTISR;       /**< Offset: 0x404 (R/   32) Host Global Interrupt Status Register */
  __O   uint32_t                       USBHS_HSTICR;       /**< Offset: 0x408 ( /W  32) Host Global Interrupt Clear Register */
  __O   uint32_t                       USBHS_HSTIFR;       /**< Offset: 0x40C ( /W  32) Host Global Interrupt Set Register */
  __I   uint32_t                       USBHS_HSTIMR;       /**< Offset: 0x410 (R/   32) Host Global Interrupt Mask Register */
  __O   uint32_t                       USBHS_HSTIDR;       /**< Offset: 0x414 ( /W  32) Host Global Interrupt Disable Register */
  __O   uint32_t                       USBHS_HSTIER;       /**< Offset: 0x418 ( /W  32) Host Global Interrupt Enable Register */
  __IO  uint32_t                       USBHS_HSTPIP;       /**< Offset: 0x41C (R/W  32) Host Pipe Register */
  __IO  uint32_t                       USBHS_HSTFNUM;      /**< Offset: 0x420 (R/W  32) Host Frame Number Register */
  __IO  uint32_t                       USBHS_HSTADDR1;     /**< Offset: 0x424 (R/W  32) Host Address 1 Register */
  __IO  uint32_t                       USBHS_HSTADDR2;     /**< Offset: 0x428 (R/W  32) Host Address 2 Register */
  __IO  uint32_t                       USBHS_HSTADDR3;     /**< Offset: 0x42C (R/W  32) Host Address 3 Register */
  __I   uint8_t                        Reserved10[0xD0];
  __IO  uint32_t                       USBHS_HSTPIPCFG[10]; /**< Offset: 0x500 (R/W  32) Host Pipe Configuration Register */
  __I   uint8_t                        Reserved11[0x08];
  __I   uint32_t                       USBHS_HSTPIPISR[10]; /**< Offset: 0x530 (R/   32) Host Pipe Status Register */
  __I   uint8_t                        Reserved12[0x08];
  __O   uint32_t                       USBHS_HSTPIPICR[10]; /**< Offset: 0x560 ( /W  32) Host Pipe Clear Register */
  __I   uint8_t                        Reserved13[0x08];
  __O   uint32_t                       USBHS_HSTPIPIFR[10]; /**< Offset: 0x590 ( /W  32) Host Pipe Set Register */
  __I   uint8_t                        Reserved14[0x08];
  __I   uint32_t                       USBHS_HSTPIPIMR[10]; /**< Offset: 0x5C0 (R/   32) Host Pipe Mask Register */
  __I   uint8_t                        Reserved15[0x08];
  __O   uint32_t                       USBHS_HSTPIPIER[10]; /**< Offset: 0x5F0 ( /W  32) Host Pipe Enable Register */
  __I   uint8_t                        Reserved16[0x08];
  __O   uint32_t                       USBHS_HSTPIPIDR[10]; /**< Offset: 0x620 ( /W  32) Host Pipe Disable Register */
  __I   uint8_t                        Reserved17[0x08];
  __IO  uint32_t                       USBHS_HSTPIPINRQ[10]; /**< Offset: 0x650 (R/W  32) Host Pipe IN Request Register */
  __I   uint8_t                        Reserved18[0x08];
  __IO  uint32_t                       USBHS_HSTPIPERR[10]; /**< Offset: 0x680 (R/W  32) Host Pipe Error Register */
  __I   uint8_t                        Reserved19[0x68];
        usbhs_hstdma_registers_t       USBHS_HSTDMA[USBHS_HSTDMA_NUMBER]; /**< Offset: 0x710 Host DMA Channel Next Descriptor Address Register */
  __I   uint8_t                        Reserved20[0x80];
  __IO  uint32_t                       USBHS_CTRL;         /**< Offset: 0x800 (R/W  32) General Control Register */
  __I   uint32_t                       USBHS_SR;           /**< Offset: 0x804 (R/   32) General Status Register */
  __O   uint32_t                       USBHS_SCR;          /**< Offset: 0x808 ( /W  32) General Status Clear Register */
  __O   uint32_t                       USBHS_SFR;          /**< Offset: 0x80C ( /W  32) General Status Set Register */
} usbhs_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMV71_USBHS_COMPONENT_H_ */
