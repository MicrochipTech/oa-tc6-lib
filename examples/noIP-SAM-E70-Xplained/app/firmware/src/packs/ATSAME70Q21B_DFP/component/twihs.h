/*
 * Component description for TWIHS
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
#ifndef _SAME70_TWIHS_COMPONENT_H_
#define _SAME70_TWIHS_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR TWIHS                                        */
/* ************************************************************************** */

/* -------- TWIHS_CR : (TWIHS Offset: 0x00) ( /W 32) Control Register -------- */
#define TWIHS_CR_START_Pos                    _UINT32_(0)                                          /* (TWIHS_CR) Send a START Condition Position */
#define TWIHS_CR_START_Msk                    (_UINT32_(0x1) << TWIHS_CR_START_Pos)                /* (TWIHS_CR) Send a START Condition Mask */
#define TWIHS_CR_START(value)                 (TWIHS_CR_START_Msk & (_UINT32_(value) << TWIHS_CR_START_Pos)) /* Assigment of value for START in the TWIHS_CR register */
#define TWIHS_CR_STOP_Pos                     _UINT32_(1)                                          /* (TWIHS_CR) Send a STOP Condition Position */
#define TWIHS_CR_STOP_Msk                     (_UINT32_(0x1) << TWIHS_CR_STOP_Pos)                 /* (TWIHS_CR) Send a STOP Condition Mask */
#define TWIHS_CR_STOP(value)                  (TWIHS_CR_STOP_Msk & (_UINT32_(value) << TWIHS_CR_STOP_Pos)) /* Assigment of value for STOP in the TWIHS_CR register */
#define TWIHS_CR_MSEN_Pos                     _UINT32_(2)                                          /* (TWIHS_CR) TWIHS Master Mode Enabled Position */
#define TWIHS_CR_MSEN_Msk                     (_UINT32_(0x1) << TWIHS_CR_MSEN_Pos)                 /* (TWIHS_CR) TWIHS Master Mode Enabled Mask */
#define TWIHS_CR_MSEN(value)                  (TWIHS_CR_MSEN_Msk & (_UINT32_(value) << TWIHS_CR_MSEN_Pos)) /* Assigment of value for MSEN in the TWIHS_CR register */
#define TWIHS_CR_MSDIS_Pos                    _UINT32_(3)                                          /* (TWIHS_CR) TWIHS Master Mode Disabled Position */
#define TWIHS_CR_MSDIS_Msk                    (_UINT32_(0x1) << TWIHS_CR_MSDIS_Pos)                /* (TWIHS_CR) TWIHS Master Mode Disabled Mask */
#define TWIHS_CR_MSDIS(value)                 (TWIHS_CR_MSDIS_Msk & (_UINT32_(value) << TWIHS_CR_MSDIS_Pos)) /* Assigment of value for MSDIS in the TWIHS_CR register */
#define TWIHS_CR_SVEN_Pos                     _UINT32_(4)                                          /* (TWIHS_CR) TWIHS Slave Mode Enabled Position */
#define TWIHS_CR_SVEN_Msk                     (_UINT32_(0x1) << TWIHS_CR_SVEN_Pos)                 /* (TWIHS_CR) TWIHS Slave Mode Enabled Mask */
#define TWIHS_CR_SVEN(value)                  (TWIHS_CR_SVEN_Msk & (_UINT32_(value) << TWIHS_CR_SVEN_Pos)) /* Assigment of value for SVEN in the TWIHS_CR register */
#define TWIHS_CR_SVDIS_Pos                    _UINT32_(5)                                          /* (TWIHS_CR) TWIHS Slave Mode Disabled Position */
#define TWIHS_CR_SVDIS_Msk                    (_UINT32_(0x1) << TWIHS_CR_SVDIS_Pos)                /* (TWIHS_CR) TWIHS Slave Mode Disabled Mask */
#define TWIHS_CR_SVDIS(value)                 (TWIHS_CR_SVDIS_Msk & (_UINT32_(value) << TWIHS_CR_SVDIS_Pos)) /* Assigment of value for SVDIS in the TWIHS_CR register */
#define TWIHS_CR_QUICK_Pos                    _UINT32_(6)                                          /* (TWIHS_CR) SMBus Quick Command Position */
#define TWIHS_CR_QUICK_Msk                    (_UINT32_(0x1) << TWIHS_CR_QUICK_Pos)                /* (TWIHS_CR) SMBus Quick Command Mask */
#define TWIHS_CR_QUICK(value)                 (TWIHS_CR_QUICK_Msk & (_UINT32_(value) << TWIHS_CR_QUICK_Pos)) /* Assigment of value for QUICK in the TWIHS_CR register */
#define TWIHS_CR_SWRST_Pos                    _UINT32_(7)                                          /* (TWIHS_CR) Software Reset Position */
#define TWIHS_CR_SWRST_Msk                    (_UINT32_(0x1) << TWIHS_CR_SWRST_Pos)                /* (TWIHS_CR) Software Reset Mask */
#define TWIHS_CR_SWRST(value)                 (TWIHS_CR_SWRST_Msk & (_UINT32_(value) << TWIHS_CR_SWRST_Pos)) /* Assigment of value for SWRST in the TWIHS_CR register */
#define TWIHS_CR_HSEN_Pos                     _UINT32_(8)                                          /* (TWIHS_CR) TWIHS High-Speed Mode Enabled Position */
#define TWIHS_CR_HSEN_Msk                     (_UINT32_(0x1) << TWIHS_CR_HSEN_Pos)                 /* (TWIHS_CR) TWIHS High-Speed Mode Enabled Mask */
#define TWIHS_CR_HSEN(value)                  (TWIHS_CR_HSEN_Msk & (_UINT32_(value) << TWIHS_CR_HSEN_Pos)) /* Assigment of value for HSEN in the TWIHS_CR register */
#define TWIHS_CR_HSDIS_Pos                    _UINT32_(9)                                          /* (TWIHS_CR) TWIHS High-Speed Mode Disabled Position */
#define TWIHS_CR_HSDIS_Msk                    (_UINT32_(0x1) << TWIHS_CR_HSDIS_Pos)                /* (TWIHS_CR) TWIHS High-Speed Mode Disabled Mask */
#define TWIHS_CR_HSDIS(value)                 (TWIHS_CR_HSDIS_Msk & (_UINT32_(value) << TWIHS_CR_HSDIS_Pos)) /* Assigment of value for HSDIS in the TWIHS_CR register */
#define TWIHS_CR_SMBEN_Pos                    _UINT32_(10)                                         /* (TWIHS_CR) SMBus Mode Enabled Position */
#define TWIHS_CR_SMBEN_Msk                    (_UINT32_(0x1) << TWIHS_CR_SMBEN_Pos)                /* (TWIHS_CR) SMBus Mode Enabled Mask */
#define TWIHS_CR_SMBEN(value)                 (TWIHS_CR_SMBEN_Msk & (_UINT32_(value) << TWIHS_CR_SMBEN_Pos)) /* Assigment of value for SMBEN in the TWIHS_CR register */
#define TWIHS_CR_SMBDIS_Pos                   _UINT32_(11)                                         /* (TWIHS_CR) SMBus Mode Disabled Position */
#define TWIHS_CR_SMBDIS_Msk                   (_UINT32_(0x1) << TWIHS_CR_SMBDIS_Pos)               /* (TWIHS_CR) SMBus Mode Disabled Mask */
#define TWIHS_CR_SMBDIS(value)                (TWIHS_CR_SMBDIS_Msk & (_UINT32_(value) << TWIHS_CR_SMBDIS_Pos)) /* Assigment of value for SMBDIS in the TWIHS_CR register */
#define TWIHS_CR_PECEN_Pos                    _UINT32_(12)                                         /* (TWIHS_CR) Packet Error Checking Enable Position */
#define TWIHS_CR_PECEN_Msk                    (_UINT32_(0x1) << TWIHS_CR_PECEN_Pos)                /* (TWIHS_CR) Packet Error Checking Enable Mask */
#define TWIHS_CR_PECEN(value)                 (TWIHS_CR_PECEN_Msk & (_UINT32_(value) << TWIHS_CR_PECEN_Pos)) /* Assigment of value for PECEN in the TWIHS_CR register */
#define TWIHS_CR_PECDIS_Pos                   _UINT32_(13)                                         /* (TWIHS_CR) Packet Error Checking Disable Position */
#define TWIHS_CR_PECDIS_Msk                   (_UINT32_(0x1) << TWIHS_CR_PECDIS_Pos)               /* (TWIHS_CR) Packet Error Checking Disable Mask */
#define TWIHS_CR_PECDIS(value)                (TWIHS_CR_PECDIS_Msk & (_UINT32_(value) << TWIHS_CR_PECDIS_Pos)) /* Assigment of value for PECDIS in the TWIHS_CR register */
#define TWIHS_CR_PECRQ_Pos                    _UINT32_(14)                                         /* (TWIHS_CR) PEC Request Position */
#define TWIHS_CR_PECRQ_Msk                    (_UINT32_(0x1) << TWIHS_CR_PECRQ_Pos)                /* (TWIHS_CR) PEC Request Mask */
#define TWIHS_CR_PECRQ(value)                 (TWIHS_CR_PECRQ_Msk & (_UINT32_(value) << TWIHS_CR_PECRQ_Pos)) /* Assigment of value for PECRQ in the TWIHS_CR register */
#define TWIHS_CR_CLEAR_Pos                    _UINT32_(15)                                         /* (TWIHS_CR) Bus CLEAR Command Position */
#define TWIHS_CR_CLEAR_Msk                    (_UINT32_(0x1) << TWIHS_CR_CLEAR_Pos)                /* (TWIHS_CR) Bus CLEAR Command Mask */
#define TWIHS_CR_CLEAR(value)                 (TWIHS_CR_CLEAR_Msk & (_UINT32_(value) << TWIHS_CR_CLEAR_Pos)) /* Assigment of value for CLEAR in the TWIHS_CR register */
#define TWIHS_CR_ACMEN_Pos                    _UINT32_(16)                                         /* (TWIHS_CR) Alternative Command Mode Enable Position */
#define TWIHS_CR_ACMEN_Msk                    (_UINT32_(0x1) << TWIHS_CR_ACMEN_Pos)                /* (TWIHS_CR) Alternative Command Mode Enable Mask */
#define TWIHS_CR_ACMEN(value)                 (TWIHS_CR_ACMEN_Msk & (_UINT32_(value) << TWIHS_CR_ACMEN_Pos)) /* Assigment of value for ACMEN in the TWIHS_CR register */
#define TWIHS_CR_ACMDIS_Pos                   _UINT32_(17)                                         /* (TWIHS_CR) Alternative Command Mode Disable Position */
#define TWIHS_CR_ACMDIS_Msk                   (_UINT32_(0x1) << TWIHS_CR_ACMDIS_Pos)               /* (TWIHS_CR) Alternative Command Mode Disable Mask */
#define TWIHS_CR_ACMDIS(value)                (TWIHS_CR_ACMDIS_Msk & (_UINT32_(value) << TWIHS_CR_ACMDIS_Pos)) /* Assigment of value for ACMDIS in the TWIHS_CR register */
#define TWIHS_CR_THRCLR_Pos                   _UINT32_(24)                                         /* (TWIHS_CR) Transmit Holding Register Clear Position */
#define TWIHS_CR_THRCLR_Msk                   (_UINT32_(0x1) << TWIHS_CR_THRCLR_Pos)               /* (TWIHS_CR) Transmit Holding Register Clear Mask */
#define TWIHS_CR_THRCLR(value)                (TWIHS_CR_THRCLR_Msk & (_UINT32_(value) << TWIHS_CR_THRCLR_Pos)) /* Assigment of value for THRCLR in the TWIHS_CR register */
#define TWIHS_CR_LOCKCLR_Pos                  _UINT32_(26)                                         /* (TWIHS_CR) Lock Clear Position */
#define TWIHS_CR_LOCKCLR_Msk                  (_UINT32_(0x1) << TWIHS_CR_LOCKCLR_Pos)              /* (TWIHS_CR) Lock Clear Mask */
#define TWIHS_CR_LOCKCLR(value)               (TWIHS_CR_LOCKCLR_Msk & (_UINT32_(value) << TWIHS_CR_LOCKCLR_Pos)) /* Assigment of value for LOCKCLR in the TWIHS_CR register */
#define TWIHS_CR_FIFOEN_Pos                   _UINT32_(28)                                         /* (TWIHS_CR) FIFO Enable Position */
#define TWIHS_CR_FIFOEN_Msk                   (_UINT32_(0x1) << TWIHS_CR_FIFOEN_Pos)               /* (TWIHS_CR) FIFO Enable Mask */
#define TWIHS_CR_FIFOEN(value)                (TWIHS_CR_FIFOEN_Msk & (_UINT32_(value) << TWIHS_CR_FIFOEN_Pos)) /* Assigment of value for FIFOEN in the TWIHS_CR register */
#define TWIHS_CR_FIFODIS_Pos                  _UINT32_(29)                                         /* (TWIHS_CR) FIFO Disable Position */
#define TWIHS_CR_FIFODIS_Msk                  (_UINT32_(0x1) << TWIHS_CR_FIFODIS_Pos)              /* (TWIHS_CR) FIFO Disable Mask */
#define TWIHS_CR_FIFODIS(value)               (TWIHS_CR_FIFODIS_Msk & (_UINT32_(value) << TWIHS_CR_FIFODIS_Pos)) /* Assigment of value for FIFODIS in the TWIHS_CR register */
#define TWIHS_CR_Msk                          _UINT32_(0x3503FFFF)                                 /* (TWIHS_CR) Register Mask  */


/* -------- TWIHS_MMR : (TWIHS Offset: 0x04) (R/W 32) Master Mode Register -------- */
#define TWIHS_MMR_IADRSZ_Pos                  _UINT32_(8)                                          /* (TWIHS_MMR) Internal Device Address Size Position */
#define TWIHS_MMR_IADRSZ_Msk                  (_UINT32_(0x3) << TWIHS_MMR_IADRSZ_Pos)              /* (TWIHS_MMR) Internal Device Address Size Mask */
#define TWIHS_MMR_IADRSZ(value)               (TWIHS_MMR_IADRSZ_Msk & (_UINT32_(value) << TWIHS_MMR_IADRSZ_Pos)) /* Assigment of value for IADRSZ in the TWIHS_MMR register */
#define   TWIHS_MMR_IADRSZ_NONE_Val           _UINT32_(0x0)                                        /* (TWIHS_MMR) No internal device address  */
#define   TWIHS_MMR_IADRSZ_1_BYTE_Val         _UINT32_(0x1)                                        /* (TWIHS_MMR) One-byte internal device address  */
#define   TWIHS_MMR_IADRSZ_2_BYTE_Val         _UINT32_(0x2)                                        /* (TWIHS_MMR) Two-byte internal device address  */
#define   TWIHS_MMR_IADRSZ_3_BYTE_Val         _UINT32_(0x3)                                        /* (TWIHS_MMR) Three-byte internal device address  */
#define TWIHS_MMR_IADRSZ_NONE                 (TWIHS_MMR_IADRSZ_NONE_Val << TWIHS_MMR_IADRSZ_Pos)  /* (TWIHS_MMR) No internal device address Position  */
#define TWIHS_MMR_IADRSZ_1_BYTE               (TWIHS_MMR_IADRSZ_1_BYTE_Val << TWIHS_MMR_IADRSZ_Pos) /* (TWIHS_MMR) One-byte internal device address Position  */
#define TWIHS_MMR_IADRSZ_2_BYTE               (TWIHS_MMR_IADRSZ_2_BYTE_Val << TWIHS_MMR_IADRSZ_Pos) /* (TWIHS_MMR) Two-byte internal device address Position  */
#define TWIHS_MMR_IADRSZ_3_BYTE               (TWIHS_MMR_IADRSZ_3_BYTE_Val << TWIHS_MMR_IADRSZ_Pos) /* (TWIHS_MMR) Three-byte internal device address Position  */
#define TWIHS_MMR_MREAD_Pos                   _UINT32_(12)                                         /* (TWIHS_MMR) Master Read Direction Position */
#define TWIHS_MMR_MREAD_Msk                   (_UINT32_(0x1) << TWIHS_MMR_MREAD_Pos)               /* (TWIHS_MMR) Master Read Direction Mask */
#define TWIHS_MMR_MREAD(value)                (TWIHS_MMR_MREAD_Msk & (_UINT32_(value) << TWIHS_MMR_MREAD_Pos)) /* Assigment of value for MREAD in the TWIHS_MMR register */
#define TWIHS_MMR_DADR_Pos                    _UINT32_(16)                                         /* (TWIHS_MMR) Device Address Position */
#define TWIHS_MMR_DADR_Msk                    (_UINT32_(0x7F) << TWIHS_MMR_DADR_Pos)               /* (TWIHS_MMR) Device Address Mask */
#define TWIHS_MMR_DADR(value)                 (TWIHS_MMR_DADR_Msk & (_UINT32_(value) << TWIHS_MMR_DADR_Pos)) /* Assigment of value for DADR in the TWIHS_MMR register */
#define TWIHS_MMR_Msk                         _UINT32_(0x007F1300)                                 /* (TWIHS_MMR) Register Mask  */


/* -------- TWIHS_SMR : (TWIHS Offset: 0x08) (R/W 32) Slave Mode Register -------- */
#define TWIHS_SMR_NACKEN_Pos                  _UINT32_(0)                                          /* (TWIHS_SMR) Slave Receiver Data Phase NACK enable Position */
#define TWIHS_SMR_NACKEN_Msk                  (_UINT32_(0x1) << TWIHS_SMR_NACKEN_Pos)              /* (TWIHS_SMR) Slave Receiver Data Phase NACK enable Mask */
#define TWIHS_SMR_NACKEN(value)               (TWIHS_SMR_NACKEN_Msk & (_UINT32_(value) << TWIHS_SMR_NACKEN_Pos)) /* Assigment of value for NACKEN in the TWIHS_SMR register */
#define TWIHS_SMR_SMDA_Pos                    _UINT32_(2)                                          /* (TWIHS_SMR) SMBus Default Address Position */
#define TWIHS_SMR_SMDA_Msk                    (_UINT32_(0x1) << TWIHS_SMR_SMDA_Pos)                /* (TWIHS_SMR) SMBus Default Address Mask */
#define TWIHS_SMR_SMDA(value)                 (TWIHS_SMR_SMDA_Msk & (_UINT32_(value) << TWIHS_SMR_SMDA_Pos)) /* Assigment of value for SMDA in the TWIHS_SMR register */
#define TWIHS_SMR_SMHH_Pos                    _UINT32_(3)                                          /* (TWIHS_SMR) SMBus Host Header Position */
#define TWIHS_SMR_SMHH_Msk                    (_UINT32_(0x1) << TWIHS_SMR_SMHH_Pos)                /* (TWIHS_SMR) SMBus Host Header Mask */
#define TWIHS_SMR_SMHH(value)                 (TWIHS_SMR_SMHH_Msk & (_UINT32_(value) << TWIHS_SMR_SMHH_Pos)) /* Assigment of value for SMHH in the TWIHS_SMR register */
#define TWIHS_SMR_SCLWSDIS_Pos                _UINT32_(6)                                          /* (TWIHS_SMR) Clock Wait State Disable Position */
#define TWIHS_SMR_SCLWSDIS_Msk                (_UINT32_(0x1) << TWIHS_SMR_SCLWSDIS_Pos)            /* (TWIHS_SMR) Clock Wait State Disable Mask */
#define TWIHS_SMR_SCLWSDIS(value)             (TWIHS_SMR_SCLWSDIS_Msk & (_UINT32_(value) << TWIHS_SMR_SCLWSDIS_Pos)) /* Assigment of value for SCLWSDIS in the TWIHS_SMR register */
#define TWIHS_SMR_MASK_Pos                    _UINT32_(8)                                          /* (TWIHS_SMR) Slave Address Mask Position */
#define TWIHS_SMR_MASK_Msk                    (_UINT32_(0x7F) << TWIHS_SMR_MASK_Pos)               /* (TWIHS_SMR) Slave Address Mask Mask */
#define TWIHS_SMR_MASK(value)                 (TWIHS_SMR_MASK_Msk & (_UINT32_(value) << TWIHS_SMR_MASK_Pos)) /* Assigment of value for MASK in the TWIHS_SMR register */
#define TWIHS_SMR_SADR_Pos                    _UINT32_(16)                                         /* (TWIHS_SMR) Slave Address Position */
#define TWIHS_SMR_SADR_Msk                    (_UINT32_(0x7F) << TWIHS_SMR_SADR_Pos)               /* (TWIHS_SMR) Slave Address Mask */
#define TWIHS_SMR_SADR(value)                 (TWIHS_SMR_SADR_Msk & (_UINT32_(value) << TWIHS_SMR_SADR_Pos)) /* Assigment of value for SADR in the TWIHS_SMR register */
#define TWIHS_SMR_SADR1EN_Pos                 _UINT32_(28)                                         /* (TWIHS_SMR) Slave Address 1 Enable Position */
#define TWIHS_SMR_SADR1EN_Msk                 (_UINT32_(0x1) << TWIHS_SMR_SADR1EN_Pos)             /* (TWIHS_SMR) Slave Address 1 Enable Mask */
#define TWIHS_SMR_SADR1EN(value)              (TWIHS_SMR_SADR1EN_Msk & (_UINT32_(value) << TWIHS_SMR_SADR1EN_Pos)) /* Assigment of value for SADR1EN in the TWIHS_SMR register */
#define TWIHS_SMR_SADR2EN_Pos                 _UINT32_(29)                                         /* (TWIHS_SMR) Slave Address 2 Enable Position */
#define TWIHS_SMR_SADR2EN_Msk                 (_UINT32_(0x1) << TWIHS_SMR_SADR2EN_Pos)             /* (TWIHS_SMR) Slave Address 2 Enable Mask */
#define TWIHS_SMR_SADR2EN(value)              (TWIHS_SMR_SADR2EN_Msk & (_UINT32_(value) << TWIHS_SMR_SADR2EN_Pos)) /* Assigment of value for SADR2EN in the TWIHS_SMR register */
#define TWIHS_SMR_SADR3EN_Pos                 _UINT32_(30)                                         /* (TWIHS_SMR) Slave Address 3 Enable Position */
#define TWIHS_SMR_SADR3EN_Msk                 (_UINT32_(0x1) << TWIHS_SMR_SADR3EN_Pos)             /* (TWIHS_SMR) Slave Address 3 Enable Mask */
#define TWIHS_SMR_SADR3EN(value)              (TWIHS_SMR_SADR3EN_Msk & (_UINT32_(value) << TWIHS_SMR_SADR3EN_Pos)) /* Assigment of value for SADR3EN in the TWIHS_SMR register */
#define TWIHS_SMR_DATAMEN_Pos                 _UINT32_(31)                                         /* (TWIHS_SMR) Data Matching Enable Position */
#define TWIHS_SMR_DATAMEN_Msk                 (_UINT32_(0x1) << TWIHS_SMR_DATAMEN_Pos)             /* (TWIHS_SMR) Data Matching Enable Mask */
#define TWIHS_SMR_DATAMEN(value)              (TWIHS_SMR_DATAMEN_Msk & (_UINT32_(value) << TWIHS_SMR_DATAMEN_Pos)) /* Assigment of value for DATAMEN in the TWIHS_SMR register */
#define TWIHS_SMR_Msk                         _UINT32_(0xF07F7F4D)                                 /* (TWIHS_SMR) Register Mask  */


/* -------- TWIHS_IADR : (TWIHS Offset: 0x0C) (R/W 32) Internal Address Register -------- */
#define TWIHS_IADR_IADR_Pos                   _UINT32_(0)                                          /* (TWIHS_IADR) Internal Address Position */
#define TWIHS_IADR_IADR_Msk                   (_UINT32_(0xFFFFFF) << TWIHS_IADR_IADR_Pos)          /* (TWIHS_IADR) Internal Address Mask */
#define TWIHS_IADR_IADR(value)                (TWIHS_IADR_IADR_Msk & (_UINT32_(value) << TWIHS_IADR_IADR_Pos)) /* Assigment of value for IADR in the TWIHS_IADR register */
#define TWIHS_IADR_Msk                        _UINT32_(0x00FFFFFF)                                 /* (TWIHS_IADR) Register Mask  */


/* -------- TWIHS_CWGR : (TWIHS Offset: 0x10) (R/W 32) Clock Waveform Generator Register -------- */
#define TWIHS_CWGR_CLDIV_Pos                  _UINT32_(0)                                          /* (TWIHS_CWGR) Clock Low Divider Position */
#define TWIHS_CWGR_CLDIV_Msk                  (_UINT32_(0xFF) << TWIHS_CWGR_CLDIV_Pos)             /* (TWIHS_CWGR) Clock Low Divider Mask */
#define TWIHS_CWGR_CLDIV(value)               (TWIHS_CWGR_CLDIV_Msk & (_UINT32_(value) << TWIHS_CWGR_CLDIV_Pos)) /* Assigment of value for CLDIV in the TWIHS_CWGR register */
#define TWIHS_CWGR_CHDIV_Pos                  _UINT32_(8)                                          /* (TWIHS_CWGR) Clock High Divider Position */
#define TWIHS_CWGR_CHDIV_Msk                  (_UINT32_(0xFF) << TWIHS_CWGR_CHDIV_Pos)             /* (TWIHS_CWGR) Clock High Divider Mask */
#define TWIHS_CWGR_CHDIV(value)               (TWIHS_CWGR_CHDIV_Msk & (_UINT32_(value) << TWIHS_CWGR_CHDIV_Pos)) /* Assigment of value for CHDIV in the TWIHS_CWGR register */
#define TWIHS_CWGR_CKDIV_Pos                  _UINT32_(16)                                         /* (TWIHS_CWGR) Clock Divider Position */
#define TWIHS_CWGR_CKDIV_Msk                  (_UINT32_(0x7) << TWIHS_CWGR_CKDIV_Pos)              /* (TWIHS_CWGR) Clock Divider Mask */
#define TWIHS_CWGR_CKDIV(value)               (TWIHS_CWGR_CKDIV_Msk & (_UINT32_(value) << TWIHS_CWGR_CKDIV_Pos)) /* Assigment of value for CKDIV in the TWIHS_CWGR register */
#define TWIHS_CWGR_HOLD_Pos                   _UINT32_(24)                                         /* (TWIHS_CWGR) TWD Hold Time Versus TWCK Falling Position */
#define TWIHS_CWGR_HOLD_Msk                   (_UINT32_(0x3F) << TWIHS_CWGR_HOLD_Pos)              /* (TWIHS_CWGR) TWD Hold Time Versus TWCK Falling Mask */
#define TWIHS_CWGR_HOLD(value)                (TWIHS_CWGR_HOLD_Msk & (_UINT32_(value) << TWIHS_CWGR_HOLD_Pos)) /* Assigment of value for HOLD in the TWIHS_CWGR register */
#define TWIHS_CWGR_Msk                        _UINT32_(0x3F07FFFF)                                 /* (TWIHS_CWGR) Register Mask  */


/* -------- TWIHS_SR : (TWIHS Offset: 0x20) ( R/ 32) Status Register -------- */
#define TWIHS_SR_TXCOMP_Pos                   _UINT32_(0)                                          /* (TWIHS_SR) Transmission Completed (cleared by writing TWIHS_THR) Position */
#define TWIHS_SR_TXCOMP_Msk                   (_UINT32_(0x1) << TWIHS_SR_TXCOMP_Pos)               /* (TWIHS_SR) Transmission Completed (cleared by writing TWIHS_THR) Mask */
#define TWIHS_SR_TXCOMP(value)                (TWIHS_SR_TXCOMP_Msk & (_UINT32_(value) << TWIHS_SR_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the TWIHS_SR register */
#define TWIHS_SR_RXRDY_Pos                    _UINT32_(1)                                          /* (TWIHS_SR) Receive Holding Register Ready (cleared by reading TWIHS_RHR) Position */
#define TWIHS_SR_RXRDY_Msk                    (_UINT32_(0x1) << TWIHS_SR_RXRDY_Pos)                /* (TWIHS_SR) Receive Holding Register Ready (cleared by reading TWIHS_RHR) Mask */
#define TWIHS_SR_RXRDY(value)                 (TWIHS_SR_RXRDY_Msk & (_UINT32_(value) << TWIHS_SR_RXRDY_Pos)) /* Assigment of value for RXRDY in the TWIHS_SR register */
#define TWIHS_SR_TXRDY_Pos                    _UINT32_(2)                                          /* (TWIHS_SR) Transmit Holding Register Ready (cleared by writing TWIHS_THR) Position */
#define TWIHS_SR_TXRDY_Msk                    (_UINT32_(0x1) << TWIHS_SR_TXRDY_Pos)                /* (TWIHS_SR) Transmit Holding Register Ready (cleared by writing TWIHS_THR) Mask */
#define TWIHS_SR_TXRDY(value)                 (TWIHS_SR_TXRDY_Msk & (_UINT32_(value) << TWIHS_SR_TXRDY_Pos)) /* Assigment of value for TXRDY in the TWIHS_SR register */
#define TWIHS_SR_SVREAD_Pos                   _UINT32_(3)                                          /* (TWIHS_SR) Slave Read Position */
#define TWIHS_SR_SVREAD_Msk                   (_UINT32_(0x1) << TWIHS_SR_SVREAD_Pos)               /* (TWIHS_SR) Slave Read Mask */
#define TWIHS_SR_SVREAD(value)                (TWIHS_SR_SVREAD_Msk & (_UINT32_(value) << TWIHS_SR_SVREAD_Pos)) /* Assigment of value for SVREAD in the TWIHS_SR register */
#define TWIHS_SR_SVACC_Pos                    _UINT32_(4)                                          /* (TWIHS_SR) Slave Access Position */
#define TWIHS_SR_SVACC_Msk                    (_UINT32_(0x1) << TWIHS_SR_SVACC_Pos)                /* (TWIHS_SR) Slave Access Mask */
#define TWIHS_SR_SVACC(value)                 (TWIHS_SR_SVACC_Msk & (_UINT32_(value) << TWIHS_SR_SVACC_Pos)) /* Assigment of value for SVACC in the TWIHS_SR register */
#define TWIHS_SR_GACC_Pos                     _UINT32_(5)                                          /* (TWIHS_SR) General Call Access (cleared on read) Position */
#define TWIHS_SR_GACC_Msk                     (_UINT32_(0x1) << TWIHS_SR_GACC_Pos)                 /* (TWIHS_SR) General Call Access (cleared on read) Mask */
#define TWIHS_SR_GACC(value)                  (TWIHS_SR_GACC_Msk & (_UINT32_(value) << TWIHS_SR_GACC_Pos)) /* Assigment of value for GACC in the TWIHS_SR register */
#define TWIHS_SR_OVRE_Pos                     _UINT32_(6)                                          /* (TWIHS_SR) Overrun Error (cleared on read) Position */
#define TWIHS_SR_OVRE_Msk                     (_UINT32_(0x1) << TWIHS_SR_OVRE_Pos)                 /* (TWIHS_SR) Overrun Error (cleared on read) Mask */
#define TWIHS_SR_OVRE(value)                  (TWIHS_SR_OVRE_Msk & (_UINT32_(value) << TWIHS_SR_OVRE_Pos)) /* Assigment of value for OVRE in the TWIHS_SR register */
#define TWIHS_SR_UNRE_Pos                     _UINT32_(7)                                          /* (TWIHS_SR) Underrun Error (cleared on read) Position */
#define TWIHS_SR_UNRE_Msk                     (_UINT32_(0x1) << TWIHS_SR_UNRE_Pos)                 /* (TWIHS_SR) Underrun Error (cleared on read) Mask */
#define TWIHS_SR_UNRE(value)                  (TWIHS_SR_UNRE_Msk & (_UINT32_(value) << TWIHS_SR_UNRE_Pos)) /* Assigment of value for UNRE in the TWIHS_SR register */
#define TWIHS_SR_NACK_Pos                     _UINT32_(8)                                          /* (TWIHS_SR) Not Acknowledged (cleared on read) Position */
#define TWIHS_SR_NACK_Msk                     (_UINT32_(0x1) << TWIHS_SR_NACK_Pos)                 /* (TWIHS_SR) Not Acknowledged (cleared on read) Mask */
#define TWIHS_SR_NACK(value)                  (TWIHS_SR_NACK_Msk & (_UINT32_(value) << TWIHS_SR_NACK_Pos)) /* Assigment of value for NACK in the TWIHS_SR register */
#define TWIHS_SR_ARBLST_Pos                   _UINT32_(9)                                          /* (TWIHS_SR) Arbitration Lost (cleared on read) Position */
#define TWIHS_SR_ARBLST_Msk                   (_UINT32_(0x1) << TWIHS_SR_ARBLST_Pos)               /* (TWIHS_SR) Arbitration Lost (cleared on read) Mask */
#define TWIHS_SR_ARBLST(value)                (TWIHS_SR_ARBLST_Msk & (_UINT32_(value) << TWIHS_SR_ARBLST_Pos)) /* Assigment of value for ARBLST in the TWIHS_SR register */
#define TWIHS_SR_SCLWS_Pos                    _UINT32_(10)                                         /* (TWIHS_SR) Clock Wait State Position */
#define TWIHS_SR_SCLWS_Msk                    (_UINT32_(0x1) << TWIHS_SR_SCLWS_Pos)                /* (TWIHS_SR) Clock Wait State Mask */
#define TWIHS_SR_SCLWS(value)                 (TWIHS_SR_SCLWS_Msk & (_UINT32_(value) << TWIHS_SR_SCLWS_Pos)) /* Assigment of value for SCLWS in the TWIHS_SR register */
#define TWIHS_SR_EOSACC_Pos                   _UINT32_(11)                                         /* (TWIHS_SR) End Of Slave Access (cleared on read) Position */
#define TWIHS_SR_EOSACC_Msk                   (_UINT32_(0x1) << TWIHS_SR_EOSACC_Pos)               /* (TWIHS_SR) End Of Slave Access (cleared on read) Mask */
#define TWIHS_SR_EOSACC(value)                (TWIHS_SR_EOSACC_Msk & (_UINT32_(value) << TWIHS_SR_EOSACC_Pos)) /* Assigment of value for EOSACC in the TWIHS_SR register */
#define TWIHS_SR_MCACK_Pos                    _UINT32_(16)                                         /* (TWIHS_SR) Master Code Acknowledge (cleared on read) Position */
#define TWIHS_SR_MCACK_Msk                    (_UINT32_(0x1) << TWIHS_SR_MCACK_Pos)                /* (TWIHS_SR) Master Code Acknowledge (cleared on read) Mask */
#define TWIHS_SR_MCACK(value)                 (TWIHS_SR_MCACK_Msk & (_UINT32_(value) << TWIHS_SR_MCACK_Pos)) /* Assigment of value for MCACK in the TWIHS_SR register */
#define TWIHS_SR_TOUT_Pos                     _UINT32_(18)                                         /* (TWIHS_SR) Timeout Error (cleared on read) Position */
#define TWIHS_SR_TOUT_Msk                     (_UINT32_(0x1) << TWIHS_SR_TOUT_Pos)                 /* (TWIHS_SR) Timeout Error (cleared on read) Mask */
#define TWIHS_SR_TOUT(value)                  (TWIHS_SR_TOUT_Msk & (_UINT32_(value) << TWIHS_SR_TOUT_Pos)) /* Assigment of value for TOUT in the TWIHS_SR register */
#define TWIHS_SR_PECERR_Pos                   _UINT32_(19)                                         /* (TWIHS_SR) PEC Error (cleared on read) Position */
#define TWIHS_SR_PECERR_Msk                   (_UINT32_(0x1) << TWIHS_SR_PECERR_Pos)               /* (TWIHS_SR) PEC Error (cleared on read) Mask */
#define TWIHS_SR_PECERR(value)                (TWIHS_SR_PECERR_Msk & (_UINT32_(value) << TWIHS_SR_PECERR_Pos)) /* Assigment of value for PECERR in the TWIHS_SR register */
#define TWIHS_SR_SMBDAM_Pos                   _UINT32_(20)                                         /* (TWIHS_SR) SMBus Default Address Match (cleared on read) Position */
#define TWIHS_SR_SMBDAM_Msk                   (_UINT32_(0x1) << TWIHS_SR_SMBDAM_Pos)               /* (TWIHS_SR) SMBus Default Address Match (cleared on read) Mask */
#define TWIHS_SR_SMBDAM(value)                (TWIHS_SR_SMBDAM_Msk & (_UINT32_(value) << TWIHS_SR_SMBDAM_Pos)) /* Assigment of value for SMBDAM in the TWIHS_SR register */
#define TWIHS_SR_SMBHHM_Pos                   _UINT32_(21)                                         /* (TWIHS_SR) SMBus Host Header Address Match (cleared on read) Position */
#define TWIHS_SR_SMBHHM_Msk                   (_UINT32_(0x1) << TWIHS_SR_SMBHHM_Pos)               /* (TWIHS_SR) SMBus Host Header Address Match (cleared on read) Mask */
#define TWIHS_SR_SMBHHM(value)                (TWIHS_SR_SMBHHM_Msk & (_UINT32_(value) << TWIHS_SR_SMBHHM_Pos)) /* Assigment of value for SMBHHM in the TWIHS_SR register */
#define TWIHS_SR_SCL_Pos                      _UINT32_(24)                                         /* (TWIHS_SR) SCL Line Value Position */
#define TWIHS_SR_SCL_Msk                      (_UINT32_(0x1) << TWIHS_SR_SCL_Pos)                  /* (TWIHS_SR) SCL Line Value Mask */
#define TWIHS_SR_SCL(value)                   (TWIHS_SR_SCL_Msk & (_UINT32_(value) << TWIHS_SR_SCL_Pos)) /* Assigment of value for SCL in the TWIHS_SR register */
#define TWIHS_SR_SDA_Pos                      _UINT32_(25)                                         /* (TWIHS_SR) SDA Line Value Position */
#define TWIHS_SR_SDA_Msk                      (_UINT32_(0x1) << TWIHS_SR_SDA_Pos)                  /* (TWIHS_SR) SDA Line Value Mask */
#define TWIHS_SR_SDA(value)                   (TWIHS_SR_SDA_Msk & (_UINT32_(value) << TWIHS_SR_SDA_Pos)) /* Assigment of value for SDA in the TWIHS_SR register */
#define TWIHS_SR_Msk                          _UINT32_(0x033D0FFF)                                 /* (TWIHS_SR) Register Mask  */


/* -------- TWIHS_IER : (TWIHS Offset: 0x24) ( /W 32) Interrupt Enable Register -------- */
#define TWIHS_IER_TXCOMP_Pos                  _UINT32_(0)                                          /* (TWIHS_IER) Transmission Completed Interrupt Enable Position */
#define TWIHS_IER_TXCOMP_Msk                  (_UINT32_(0x1) << TWIHS_IER_TXCOMP_Pos)              /* (TWIHS_IER) Transmission Completed Interrupt Enable Mask */
#define TWIHS_IER_TXCOMP(value)               (TWIHS_IER_TXCOMP_Msk & (_UINT32_(value) << TWIHS_IER_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the TWIHS_IER register */
#define TWIHS_IER_RXRDY_Pos                   _UINT32_(1)                                          /* (TWIHS_IER) Receive Holding Register Ready Interrupt Enable Position */
#define TWIHS_IER_RXRDY_Msk                   (_UINT32_(0x1) << TWIHS_IER_RXRDY_Pos)               /* (TWIHS_IER) Receive Holding Register Ready Interrupt Enable Mask */
#define TWIHS_IER_RXRDY(value)                (TWIHS_IER_RXRDY_Msk & (_UINT32_(value) << TWIHS_IER_RXRDY_Pos)) /* Assigment of value for RXRDY in the TWIHS_IER register */
#define TWIHS_IER_TXRDY_Pos                   _UINT32_(2)                                          /* (TWIHS_IER) Transmit Holding Register Ready Interrupt Enable Position */
#define TWIHS_IER_TXRDY_Msk                   (_UINT32_(0x1) << TWIHS_IER_TXRDY_Pos)               /* (TWIHS_IER) Transmit Holding Register Ready Interrupt Enable Mask */
#define TWIHS_IER_TXRDY(value)                (TWIHS_IER_TXRDY_Msk & (_UINT32_(value) << TWIHS_IER_TXRDY_Pos)) /* Assigment of value for TXRDY in the TWIHS_IER register */
#define TWIHS_IER_SVACC_Pos                   _UINT32_(4)                                          /* (TWIHS_IER) Slave Access Interrupt Enable Position */
#define TWIHS_IER_SVACC_Msk                   (_UINT32_(0x1) << TWIHS_IER_SVACC_Pos)               /* (TWIHS_IER) Slave Access Interrupt Enable Mask */
#define TWIHS_IER_SVACC(value)                (TWIHS_IER_SVACC_Msk & (_UINT32_(value) << TWIHS_IER_SVACC_Pos)) /* Assigment of value for SVACC in the TWIHS_IER register */
#define TWIHS_IER_GACC_Pos                    _UINT32_(5)                                          /* (TWIHS_IER) General Call Access Interrupt Enable Position */
#define TWIHS_IER_GACC_Msk                    (_UINT32_(0x1) << TWIHS_IER_GACC_Pos)                /* (TWIHS_IER) General Call Access Interrupt Enable Mask */
#define TWIHS_IER_GACC(value)                 (TWIHS_IER_GACC_Msk & (_UINT32_(value) << TWIHS_IER_GACC_Pos)) /* Assigment of value for GACC in the TWIHS_IER register */
#define TWIHS_IER_OVRE_Pos                    _UINT32_(6)                                          /* (TWIHS_IER) Overrun Error Interrupt Enable Position */
#define TWIHS_IER_OVRE_Msk                    (_UINT32_(0x1) << TWIHS_IER_OVRE_Pos)                /* (TWIHS_IER) Overrun Error Interrupt Enable Mask */
#define TWIHS_IER_OVRE(value)                 (TWIHS_IER_OVRE_Msk & (_UINT32_(value) << TWIHS_IER_OVRE_Pos)) /* Assigment of value for OVRE in the TWIHS_IER register */
#define TWIHS_IER_UNRE_Pos                    _UINT32_(7)                                          /* (TWIHS_IER) Underrun Error Interrupt Enable Position */
#define TWIHS_IER_UNRE_Msk                    (_UINT32_(0x1) << TWIHS_IER_UNRE_Pos)                /* (TWIHS_IER) Underrun Error Interrupt Enable Mask */
#define TWIHS_IER_UNRE(value)                 (TWIHS_IER_UNRE_Msk & (_UINT32_(value) << TWIHS_IER_UNRE_Pos)) /* Assigment of value for UNRE in the TWIHS_IER register */
#define TWIHS_IER_NACK_Pos                    _UINT32_(8)                                          /* (TWIHS_IER) Not Acknowledge Interrupt Enable Position */
#define TWIHS_IER_NACK_Msk                    (_UINT32_(0x1) << TWIHS_IER_NACK_Pos)                /* (TWIHS_IER) Not Acknowledge Interrupt Enable Mask */
#define TWIHS_IER_NACK(value)                 (TWIHS_IER_NACK_Msk & (_UINT32_(value) << TWIHS_IER_NACK_Pos)) /* Assigment of value for NACK in the TWIHS_IER register */
#define TWIHS_IER_ARBLST_Pos                  _UINT32_(9)                                          /* (TWIHS_IER) Arbitration Lost Interrupt Enable Position */
#define TWIHS_IER_ARBLST_Msk                  (_UINT32_(0x1) << TWIHS_IER_ARBLST_Pos)              /* (TWIHS_IER) Arbitration Lost Interrupt Enable Mask */
#define TWIHS_IER_ARBLST(value)               (TWIHS_IER_ARBLST_Msk & (_UINT32_(value) << TWIHS_IER_ARBLST_Pos)) /* Assigment of value for ARBLST in the TWIHS_IER register */
#define TWIHS_IER_SCL_WS_Pos                  _UINT32_(10)                                         /* (TWIHS_IER) Clock Wait State Interrupt Enable Position */
#define TWIHS_IER_SCL_WS_Msk                  (_UINT32_(0x1) << TWIHS_IER_SCL_WS_Pos)              /* (TWIHS_IER) Clock Wait State Interrupt Enable Mask */
#define TWIHS_IER_SCL_WS(value)               (TWIHS_IER_SCL_WS_Msk & (_UINT32_(value) << TWIHS_IER_SCL_WS_Pos)) /* Assigment of value for SCL_WS in the TWIHS_IER register */
#define TWIHS_IER_EOSACC_Pos                  _UINT32_(11)                                         /* (TWIHS_IER) End Of Slave Access Interrupt Enable Position */
#define TWIHS_IER_EOSACC_Msk                  (_UINT32_(0x1) << TWIHS_IER_EOSACC_Pos)              /* (TWIHS_IER) End Of Slave Access Interrupt Enable Mask */
#define TWIHS_IER_EOSACC(value)               (TWIHS_IER_EOSACC_Msk & (_UINT32_(value) << TWIHS_IER_EOSACC_Pos)) /* Assigment of value for EOSACC in the TWIHS_IER register */
#define TWIHS_IER_MCACK_Pos                   _UINT32_(16)                                         /* (TWIHS_IER) Master Code Acknowledge Interrupt Enable Position */
#define TWIHS_IER_MCACK_Msk                   (_UINT32_(0x1) << TWIHS_IER_MCACK_Pos)               /* (TWIHS_IER) Master Code Acknowledge Interrupt Enable Mask */
#define TWIHS_IER_MCACK(value)                (TWIHS_IER_MCACK_Msk & (_UINT32_(value) << TWIHS_IER_MCACK_Pos)) /* Assigment of value for MCACK in the TWIHS_IER register */
#define TWIHS_IER_TOUT_Pos                    _UINT32_(18)                                         /* (TWIHS_IER) Timeout Error Interrupt Enable Position */
#define TWIHS_IER_TOUT_Msk                    (_UINT32_(0x1) << TWIHS_IER_TOUT_Pos)                /* (TWIHS_IER) Timeout Error Interrupt Enable Mask */
#define TWIHS_IER_TOUT(value)                 (TWIHS_IER_TOUT_Msk & (_UINT32_(value) << TWIHS_IER_TOUT_Pos)) /* Assigment of value for TOUT in the TWIHS_IER register */
#define TWIHS_IER_PECERR_Pos                  _UINT32_(19)                                         /* (TWIHS_IER) PEC Error Interrupt Enable Position */
#define TWIHS_IER_PECERR_Msk                  (_UINT32_(0x1) << TWIHS_IER_PECERR_Pos)              /* (TWIHS_IER) PEC Error Interrupt Enable Mask */
#define TWIHS_IER_PECERR(value)               (TWIHS_IER_PECERR_Msk & (_UINT32_(value) << TWIHS_IER_PECERR_Pos)) /* Assigment of value for PECERR in the TWIHS_IER register */
#define TWIHS_IER_SMBDAM_Pos                  _UINT32_(20)                                         /* (TWIHS_IER) SMBus Default Address Match Interrupt Enable Position */
#define TWIHS_IER_SMBDAM_Msk                  (_UINT32_(0x1) << TWIHS_IER_SMBDAM_Pos)              /* (TWIHS_IER) SMBus Default Address Match Interrupt Enable Mask */
#define TWIHS_IER_SMBDAM(value)               (TWIHS_IER_SMBDAM_Msk & (_UINT32_(value) << TWIHS_IER_SMBDAM_Pos)) /* Assigment of value for SMBDAM in the TWIHS_IER register */
#define TWIHS_IER_SMBHHM_Pos                  _UINT32_(21)                                         /* (TWIHS_IER) SMBus Host Header Address Match Interrupt Enable Position */
#define TWIHS_IER_SMBHHM_Msk                  (_UINT32_(0x1) << TWIHS_IER_SMBHHM_Pos)              /* (TWIHS_IER) SMBus Host Header Address Match Interrupt Enable Mask */
#define TWIHS_IER_SMBHHM(value)               (TWIHS_IER_SMBHHM_Msk & (_UINT32_(value) << TWIHS_IER_SMBHHM_Pos)) /* Assigment of value for SMBHHM in the TWIHS_IER register */
#define TWIHS_IER_Msk                         _UINT32_(0x003D0FF7)                                 /* (TWIHS_IER) Register Mask  */


/* -------- TWIHS_IDR : (TWIHS Offset: 0x28) ( /W 32) Interrupt Disable Register -------- */
#define TWIHS_IDR_TXCOMP_Pos                  _UINT32_(0)                                          /* (TWIHS_IDR) Transmission Completed Interrupt Disable Position */
#define TWIHS_IDR_TXCOMP_Msk                  (_UINT32_(0x1) << TWIHS_IDR_TXCOMP_Pos)              /* (TWIHS_IDR) Transmission Completed Interrupt Disable Mask */
#define TWIHS_IDR_TXCOMP(value)               (TWIHS_IDR_TXCOMP_Msk & (_UINT32_(value) << TWIHS_IDR_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the TWIHS_IDR register */
#define TWIHS_IDR_RXRDY_Pos                   _UINT32_(1)                                          /* (TWIHS_IDR) Receive Holding Register Ready Interrupt Disable Position */
#define TWIHS_IDR_RXRDY_Msk                   (_UINT32_(0x1) << TWIHS_IDR_RXRDY_Pos)               /* (TWIHS_IDR) Receive Holding Register Ready Interrupt Disable Mask */
#define TWIHS_IDR_RXRDY(value)                (TWIHS_IDR_RXRDY_Msk & (_UINT32_(value) << TWIHS_IDR_RXRDY_Pos)) /* Assigment of value for RXRDY in the TWIHS_IDR register */
#define TWIHS_IDR_TXRDY_Pos                   _UINT32_(2)                                          /* (TWIHS_IDR) Transmit Holding Register Ready Interrupt Disable Position */
#define TWIHS_IDR_TXRDY_Msk                   (_UINT32_(0x1) << TWIHS_IDR_TXRDY_Pos)               /* (TWIHS_IDR) Transmit Holding Register Ready Interrupt Disable Mask */
#define TWIHS_IDR_TXRDY(value)                (TWIHS_IDR_TXRDY_Msk & (_UINT32_(value) << TWIHS_IDR_TXRDY_Pos)) /* Assigment of value for TXRDY in the TWIHS_IDR register */
#define TWIHS_IDR_SVACC_Pos                   _UINT32_(4)                                          /* (TWIHS_IDR) Slave Access Interrupt Disable Position */
#define TWIHS_IDR_SVACC_Msk                   (_UINT32_(0x1) << TWIHS_IDR_SVACC_Pos)               /* (TWIHS_IDR) Slave Access Interrupt Disable Mask */
#define TWIHS_IDR_SVACC(value)                (TWIHS_IDR_SVACC_Msk & (_UINT32_(value) << TWIHS_IDR_SVACC_Pos)) /* Assigment of value for SVACC in the TWIHS_IDR register */
#define TWIHS_IDR_GACC_Pos                    _UINT32_(5)                                          /* (TWIHS_IDR) General Call Access Interrupt Disable Position */
#define TWIHS_IDR_GACC_Msk                    (_UINT32_(0x1) << TWIHS_IDR_GACC_Pos)                /* (TWIHS_IDR) General Call Access Interrupt Disable Mask */
#define TWIHS_IDR_GACC(value)                 (TWIHS_IDR_GACC_Msk & (_UINT32_(value) << TWIHS_IDR_GACC_Pos)) /* Assigment of value for GACC in the TWIHS_IDR register */
#define TWIHS_IDR_OVRE_Pos                    _UINT32_(6)                                          /* (TWIHS_IDR) Overrun Error Interrupt Disable Position */
#define TWIHS_IDR_OVRE_Msk                    (_UINT32_(0x1) << TWIHS_IDR_OVRE_Pos)                /* (TWIHS_IDR) Overrun Error Interrupt Disable Mask */
#define TWIHS_IDR_OVRE(value)                 (TWIHS_IDR_OVRE_Msk & (_UINT32_(value) << TWIHS_IDR_OVRE_Pos)) /* Assigment of value for OVRE in the TWIHS_IDR register */
#define TWIHS_IDR_UNRE_Pos                    _UINT32_(7)                                          /* (TWIHS_IDR) Underrun Error Interrupt Disable Position */
#define TWIHS_IDR_UNRE_Msk                    (_UINT32_(0x1) << TWIHS_IDR_UNRE_Pos)                /* (TWIHS_IDR) Underrun Error Interrupt Disable Mask */
#define TWIHS_IDR_UNRE(value)                 (TWIHS_IDR_UNRE_Msk & (_UINT32_(value) << TWIHS_IDR_UNRE_Pos)) /* Assigment of value for UNRE in the TWIHS_IDR register */
#define TWIHS_IDR_NACK_Pos                    _UINT32_(8)                                          /* (TWIHS_IDR) Not Acknowledge Interrupt Disable Position */
#define TWIHS_IDR_NACK_Msk                    (_UINT32_(0x1) << TWIHS_IDR_NACK_Pos)                /* (TWIHS_IDR) Not Acknowledge Interrupt Disable Mask */
#define TWIHS_IDR_NACK(value)                 (TWIHS_IDR_NACK_Msk & (_UINT32_(value) << TWIHS_IDR_NACK_Pos)) /* Assigment of value for NACK in the TWIHS_IDR register */
#define TWIHS_IDR_ARBLST_Pos                  _UINT32_(9)                                          /* (TWIHS_IDR) Arbitration Lost Interrupt Disable Position */
#define TWIHS_IDR_ARBLST_Msk                  (_UINT32_(0x1) << TWIHS_IDR_ARBLST_Pos)              /* (TWIHS_IDR) Arbitration Lost Interrupt Disable Mask */
#define TWIHS_IDR_ARBLST(value)               (TWIHS_IDR_ARBLST_Msk & (_UINT32_(value) << TWIHS_IDR_ARBLST_Pos)) /* Assigment of value for ARBLST in the TWIHS_IDR register */
#define TWIHS_IDR_SCL_WS_Pos                  _UINT32_(10)                                         /* (TWIHS_IDR) Clock Wait State Interrupt Disable Position */
#define TWIHS_IDR_SCL_WS_Msk                  (_UINT32_(0x1) << TWIHS_IDR_SCL_WS_Pos)              /* (TWIHS_IDR) Clock Wait State Interrupt Disable Mask */
#define TWIHS_IDR_SCL_WS(value)               (TWIHS_IDR_SCL_WS_Msk & (_UINT32_(value) << TWIHS_IDR_SCL_WS_Pos)) /* Assigment of value for SCL_WS in the TWIHS_IDR register */
#define TWIHS_IDR_EOSACC_Pos                  _UINT32_(11)                                         /* (TWIHS_IDR) End Of Slave Access Interrupt Disable Position */
#define TWIHS_IDR_EOSACC_Msk                  (_UINT32_(0x1) << TWIHS_IDR_EOSACC_Pos)              /* (TWIHS_IDR) End Of Slave Access Interrupt Disable Mask */
#define TWIHS_IDR_EOSACC(value)               (TWIHS_IDR_EOSACC_Msk & (_UINT32_(value) << TWIHS_IDR_EOSACC_Pos)) /* Assigment of value for EOSACC in the TWIHS_IDR register */
#define TWIHS_IDR_MCACK_Pos                   _UINT32_(16)                                         /* (TWIHS_IDR) Master Code Acknowledge Interrupt Disable Position */
#define TWIHS_IDR_MCACK_Msk                   (_UINT32_(0x1) << TWIHS_IDR_MCACK_Pos)               /* (TWIHS_IDR) Master Code Acknowledge Interrupt Disable Mask */
#define TWIHS_IDR_MCACK(value)                (TWIHS_IDR_MCACK_Msk & (_UINT32_(value) << TWIHS_IDR_MCACK_Pos)) /* Assigment of value for MCACK in the TWIHS_IDR register */
#define TWIHS_IDR_TOUT_Pos                    _UINT32_(18)                                         /* (TWIHS_IDR) Timeout Error Interrupt Disable Position */
#define TWIHS_IDR_TOUT_Msk                    (_UINT32_(0x1) << TWIHS_IDR_TOUT_Pos)                /* (TWIHS_IDR) Timeout Error Interrupt Disable Mask */
#define TWIHS_IDR_TOUT(value)                 (TWIHS_IDR_TOUT_Msk & (_UINT32_(value) << TWIHS_IDR_TOUT_Pos)) /* Assigment of value for TOUT in the TWIHS_IDR register */
#define TWIHS_IDR_PECERR_Pos                  _UINT32_(19)                                         /* (TWIHS_IDR) PEC Error Interrupt Disable Position */
#define TWIHS_IDR_PECERR_Msk                  (_UINT32_(0x1) << TWIHS_IDR_PECERR_Pos)              /* (TWIHS_IDR) PEC Error Interrupt Disable Mask */
#define TWIHS_IDR_PECERR(value)               (TWIHS_IDR_PECERR_Msk & (_UINT32_(value) << TWIHS_IDR_PECERR_Pos)) /* Assigment of value for PECERR in the TWIHS_IDR register */
#define TWIHS_IDR_SMBDAM_Pos                  _UINT32_(20)                                         /* (TWIHS_IDR) SMBus Default Address Match Interrupt Disable Position */
#define TWIHS_IDR_SMBDAM_Msk                  (_UINT32_(0x1) << TWIHS_IDR_SMBDAM_Pos)              /* (TWIHS_IDR) SMBus Default Address Match Interrupt Disable Mask */
#define TWIHS_IDR_SMBDAM(value)               (TWIHS_IDR_SMBDAM_Msk & (_UINT32_(value) << TWIHS_IDR_SMBDAM_Pos)) /* Assigment of value for SMBDAM in the TWIHS_IDR register */
#define TWIHS_IDR_SMBHHM_Pos                  _UINT32_(21)                                         /* (TWIHS_IDR) SMBus Host Header Address Match Interrupt Disable Position */
#define TWIHS_IDR_SMBHHM_Msk                  (_UINT32_(0x1) << TWIHS_IDR_SMBHHM_Pos)              /* (TWIHS_IDR) SMBus Host Header Address Match Interrupt Disable Mask */
#define TWIHS_IDR_SMBHHM(value)               (TWIHS_IDR_SMBHHM_Msk & (_UINT32_(value) << TWIHS_IDR_SMBHHM_Pos)) /* Assigment of value for SMBHHM in the TWIHS_IDR register */
#define TWIHS_IDR_Msk                         _UINT32_(0x003D0FF7)                                 /* (TWIHS_IDR) Register Mask  */


/* -------- TWIHS_IMR : (TWIHS Offset: 0x2C) ( R/ 32) Interrupt Mask Register -------- */
#define TWIHS_IMR_TXCOMP_Pos                  _UINT32_(0)                                          /* (TWIHS_IMR) Transmission Completed Interrupt Mask Position */
#define TWIHS_IMR_TXCOMP_Msk                  (_UINT32_(0x1) << TWIHS_IMR_TXCOMP_Pos)              /* (TWIHS_IMR) Transmission Completed Interrupt Mask Mask */
#define TWIHS_IMR_TXCOMP(value)               (TWIHS_IMR_TXCOMP_Msk & (_UINT32_(value) << TWIHS_IMR_TXCOMP_Pos)) /* Assigment of value for TXCOMP in the TWIHS_IMR register */
#define TWIHS_IMR_RXRDY_Pos                   _UINT32_(1)                                          /* (TWIHS_IMR) Receive Holding Register Ready Interrupt Mask Position */
#define TWIHS_IMR_RXRDY_Msk                   (_UINT32_(0x1) << TWIHS_IMR_RXRDY_Pos)               /* (TWIHS_IMR) Receive Holding Register Ready Interrupt Mask Mask */
#define TWIHS_IMR_RXRDY(value)                (TWIHS_IMR_RXRDY_Msk & (_UINT32_(value) << TWIHS_IMR_RXRDY_Pos)) /* Assigment of value for RXRDY in the TWIHS_IMR register */
#define TWIHS_IMR_TXRDY_Pos                   _UINT32_(2)                                          /* (TWIHS_IMR) Transmit Holding Register Ready Interrupt Mask Position */
#define TWIHS_IMR_TXRDY_Msk                   (_UINT32_(0x1) << TWIHS_IMR_TXRDY_Pos)               /* (TWIHS_IMR) Transmit Holding Register Ready Interrupt Mask Mask */
#define TWIHS_IMR_TXRDY(value)                (TWIHS_IMR_TXRDY_Msk & (_UINT32_(value) << TWIHS_IMR_TXRDY_Pos)) /* Assigment of value for TXRDY in the TWIHS_IMR register */
#define TWIHS_IMR_SVACC_Pos                   _UINT32_(4)                                          /* (TWIHS_IMR) Slave Access Interrupt Mask Position */
#define TWIHS_IMR_SVACC_Msk                   (_UINT32_(0x1) << TWIHS_IMR_SVACC_Pos)               /* (TWIHS_IMR) Slave Access Interrupt Mask Mask */
#define TWIHS_IMR_SVACC(value)                (TWIHS_IMR_SVACC_Msk & (_UINT32_(value) << TWIHS_IMR_SVACC_Pos)) /* Assigment of value for SVACC in the TWIHS_IMR register */
#define TWIHS_IMR_GACC_Pos                    _UINT32_(5)                                          /* (TWIHS_IMR) General Call Access Interrupt Mask Position */
#define TWIHS_IMR_GACC_Msk                    (_UINT32_(0x1) << TWIHS_IMR_GACC_Pos)                /* (TWIHS_IMR) General Call Access Interrupt Mask Mask */
#define TWIHS_IMR_GACC(value)                 (TWIHS_IMR_GACC_Msk & (_UINT32_(value) << TWIHS_IMR_GACC_Pos)) /* Assigment of value for GACC in the TWIHS_IMR register */
#define TWIHS_IMR_OVRE_Pos                    _UINT32_(6)                                          /* (TWIHS_IMR) Overrun Error Interrupt Mask Position */
#define TWIHS_IMR_OVRE_Msk                    (_UINT32_(0x1) << TWIHS_IMR_OVRE_Pos)                /* (TWIHS_IMR) Overrun Error Interrupt Mask Mask */
#define TWIHS_IMR_OVRE(value)                 (TWIHS_IMR_OVRE_Msk & (_UINT32_(value) << TWIHS_IMR_OVRE_Pos)) /* Assigment of value for OVRE in the TWIHS_IMR register */
#define TWIHS_IMR_UNRE_Pos                    _UINT32_(7)                                          /* (TWIHS_IMR) Underrun Error Interrupt Mask Position */
#define TWIHS_IMR_UNRE_Msk                    (_UINT32_(0x1) << TWIHS_IMR_UNRE_Pos)                /* (TWIHS_IMR) Underrun Error Interrupt Mask Mask */
#define TWIHS_IMR_UNRE(value)                 (TWIHS_IMR_UNRE_Msk & (_UINT32_(value) << TWIHS_IMR_UNRE_Pos)) /* Assigment of value for UNRE in the TWIHS_IMR register */
#define TWIHS_IMR_NACK_Pos                    _UINT32_(8)                                          /* (TWIHS_IMR) Not Acknowledge Interrupt Mask Position */
#define TWIHS_IMR_NACK_Msk                    (_UINT32_(0x1) << TWIHS_IMR_NACK_Pos)                /* (TWIHS_IMR) Not Acknowledge Interrupt Mask Mask */
#define TWIHS_IMR_NACK(value)                 (TWIHS_IMR_NACK_Msk & (_UINT32_(value) << TWIHS_IMR_NACK_Pos)) /* Assigment of value for NACK in the TWIHS_IMR register */
#define TWIHS_IMR_ARBLST_Pos                  _UINT32_(9)                                          /* (TWIHS_IMR) Arbitration Lost Interrupt Mask Position */
#define TWIHS_IMR_ARBLST_Msk                  (_UINT32_(0x1) << TWIHS_IMR_ARBLST_Pos)              /* (TWIHS_IMR) Arbitration Lost Interrupt Mask Mask */
#define TWIHS_IMR_ARBLST(value)               (TWIHS_IMR_ARBLST_Msk & (_UINT32_(value) << TWIHS_IMR_ARBLST_Pos)) /* Assigment of value for ARBLST in the TWIHS_IMR register */
#define TWIHS_IMR_SCL_WS_Pos                  _UINT32_(10)                                         /* (TWIHS_IMR) Clock Wait State Interrupt Mask Position */
#define TWIHS_IMR_SCL_WS_Msk                  (_UINT32_(0x1) << TWIHS_IMR_SCL_WS_Pos)              /* (TWIHS_IMR) Clock Wait State Interrupt Mask Mask */
#define TWIHS_IMR_SCL_WS(value)               (TWIHS_IMR_SCL_WS_Msk & (_UINT32_(value) << TWIHS_IMR_SCL_WS_Pos)) /* Assigment of value for SCL_WS in the TWIHS_IMR register */
#define TWIHS_IMR_EOSACC_Pos                  _UINT32_(11)                                         /* (TWIHS_IMR) End Of Slave Access Interrupt Mask Position */
#define TWIHS_IMR_EOSACC_Msk                  (_UINT32_(0x1) << TWIHS_IMR_EOSACC_Pos)              /* (TWIHS_IMR) End Of Slave Access Interrupt Mask Mask */
#define TWIHS_IMR_EOSACC(value)               (TWIHS_IMR_EOSACC_Msk & (_UINT32_(value) << TWIHS_IMR_EOSACC_Pos)) /* Assigment of value for EOSACC in the TWIHS_IMR register */
#define TWIHS_IMR_MCACK_Pos                   _UINT32_(16)                                         /* (TWIHS_IMR) Master Code Acknowledge Interrupt Mask Position */
#define TWIHS_IMR_MCACK_Msk                   (_UINT32_(0x1) << TWIHS_IMR_MCACK_Pos)               /* (TWIHS_IMR) Master Code Acknowledge Interrupt Mask Mask */
#define TWIHS_IMR_MCACK(value)                (TWIHS_IMR_MCACK_Msk & (_UINT32_(value) << TWIHS_IMR_MCACK_Pos)) /* Assigment of value for MCACK in the TWIHS_IMR register */
#define TWIHS_IMR_TOUT_Pos                    _UINT32_(18)                                         /* (TWIHS_IMR) Timeout Error Interrupt Mask Position */
#define TWIHS_IMR_TOUT_Msk                    (_UINT32_(0x1) << TWIHS_IMR_TOUT_Pos)                /* (TWIHS_IMR) Timeout Error Interrupt Mask Mask */
#define TWIHS_IMR_TOUT(value)                 (TWIHS_IMR_TOUT_Msk & (_UINT32_(value) << TWIHS_IMR_TOUT_Pos)) /* Assigment of value for TOUT in the TWIHS_IMR register */
#define TWIHS_IMR_PECERR_Pos                  _UINT32_(19)                                         /* (TWIHS_IMR) PEC Error Interrupt Mask Position */
#define TWIHS_IMR_PECERR_Msk                  (_UINT32_(0x1) << TWIHS_IMR_PECERR_Pos)              /* (TWIHS_IMR) PEC Error Interrupt Mask Mask */
#define TWIHS_IMR_PECERR(value)               (TWIHS_IMR_PECERR_Msk & (_UINT32_(value) << TWIHS_IMR_PECERR_Pos)) /* Assigment of value for PECERR in the TWIHS_IMR register */
#define TWIHS_IMR_SMBDAM_Pos                  _UINT32_(20)                                         /* (TWIHS_IMR) SMBus Default Address Match Interrupt Mask Position */
#define TWIHS_IMR_SMBDAM_Msk                  (_UINT32_(0x1) << TWIHS_IMR_SMBDAM_Pos)              /* (TWIHS_IMR) SMBus Default Address Match Interrupt Mask Mask */
#define TWIHS_IMR_SMBDAM(value)               (TWIHS_IMR_SMBDAM_Msk & (_UINT32_(value) << TWIHS_IMR_SMBDAM_Pos)) /* Assigment of value for SMBDAM in the TWIHS_IMR register */
#define TWIHS_IMR_SMBHHM_Pos                  _UINT32_(21)                                         /* (TWIHS_IMR) SMBus Host Header Address Match Interrupt Mask Position */
#define TWIHS_IMR_SMBHHM_Msk                  (_UINT32_(0x1) << TWIHS_IMR_SMBHHM_Pos)              /* (TWIHS_IMR) SMBus Host Header Address Match Interrupt Mask Mask */
#define TWIHS_IMR_SMBHHM(value)               (TWIHS_IMR_SMBHHM_Msk & (_UINT32_(value) << TWIHS_IMR_SMBHHM_Pos)) /* Assigment of value for SMBHHM in the TWIHS_IMR register */
#define TWIHS_IMR_Msk                         _UINT32_(0x003D0FF7)                                 /* (TWIHS_IMR) Register Mask  */


/* -------- TWIHS_RHR : (TWIHS Offset: 0x30) ( R/ 32) Receive Holding Register -------- */
#define TWIHS_RHR_RXDATA_Pos                  _UINT32_(0)                                          /* (TWIHS_RHR) Master or Slave Receive Holding Data Position */
#define TWIHS_RHR_RXDATA_Msk                  (_UINT32_(0xFF) << TWIHS_RHR_RXDATA_Pos)             /* (TWIHS_RHR) Master or Slave Receive Holding Data Mask */
#define TWIHS_RHR_RXDATA(value)               (TWIHS_RHR_RXDATA_Msk & (_UINT32_(value) << TWIHS_RHR_RXDATA_Pos)) /* Assigment of value for RXDATA in the TWIHS_RHR register */
#define TWIHS_RHR_Msk                         _UINT32_(0x000000FF)                                 /* (TWIHS_RHR) Register Mask  */


/* -------- TWIHS_THR : (TWIHS Offset: 0x34) ( /W 32) Transmit Holding Register -------- */
#define TWIHS_THR_TXDATA_Pos                  _UINT32_(0)                                          /* (TWIHS_THR) Master or Slave Transmit Holding Data Position */
#define TWIHS_THR_TXDATA_Msk                  (_UINT32_(0xFF) << TWIHS_THR_TXDATA_Pos)             /* (TWIHS_THR) Master or Slave Transmit Holding Data Mask */
#define TWIHS_THR_TXDATA(value)               (TWIHS_THR_TXDATA_Msk & (_UINT32_(value) << TWIHS_THR_TXDATA_Pos)) /* Assigment of value for TXDATA in the TWIHS_THR register */
#define TWIHS_THR_Msk                         _UINT32_(0x000000FF)                                 /* (TWIHS_THR) Register Mask  */


/* -------- TWIHS_SMBTR : (TWIHS Offset: 0x38) (R/W 32) SMBus Timing Register -------- */
#define TWIHS_SMBTR_PRESC_Pos                 _UINT32_(0)                                          /* (TWIHS_SMBTR) SMBus Clock Prescaler Position */
#define TWIHS_SMBTR_PRESC_Msk                 (_UINT32_(0xF) << TWIHS_SMBTR_PRESC_Pos)             /* (TWIHS_SMBTR) SMBus Clock Prescaler Mask */
#define TWIHS_SMBTR_PRESC(value)              (TWIHS_SMBTR_PRESC_Msk & (_UINT32_(value) << TWIHS_SMBTR_PRESC_Pos)) /* Assigment of value for PRESC in the TWIHS_SMBTR register */
#define TWIHS_SMBTR_TLOWS_Pos                 _UINT32_(8)                                          /* (TWIHS_SMBTR) Slave Clock Stretch Maximum Cycles Position */
#define TWIHS_SMBTR_TLOWS_Msk                 (_UINT32_(0xFF) << TWIHS_SMBTR_TLOWS_Pos)            /* (TWIHS_SMBTR) Slave Clock Stretch Maximum Cycles Mask */
#define TWIHS_SMBTR_TLOWS(value)              (TWIHS_SMBTR_TLOWS_Msk & (_UINT32_(value) << TWIHS_SMBTR_TLOWS_Pos)) /* Assigment of value for TLOWS in the TWIHS_SMBTR register */
#define TWIHS_SMBTR_TLOWM_Pos                 _UINT32_(16)                                         /* (TWIHS_SMBTR) Master Clock Stretch Maximum Cycles Position */
#define TWIHS_SMBTR_TLOWM_Msk                 (_UINT32_(0xFF) << TWIHS_SMBTR_TLOWM_Pos)            /* (TWIHS_SMBTR) Master Clock Stretch Maximum Cycles Mask */
#define TWIHS_SMBTR_TLOWM(value)              (TWIHS_SMBTR_TLOWM_Msk & (_UINT32_(value) << TWIHS_SMBTR_TLOWM_Pos)) /* Assigment of value for TLOWM in the TWIHS_SMBTR register */
#define TWIHS_SMBTR_THMAX_Pos                 _UINT32_(24)                                         /* (TWIHS_SMBTR) Clock High Maximum Cycles Position */
#define TWIHS_SMBTR_THMAX_Msk                 (_UINT32_(0xFF) << TWIHS_SMBTR_THMAX_Pos)            /* (TWIHS_SMBTR) Clock High Maximum Cycles Mask */
#define TWIHS_SMBTR_THMAX(value)              (TWIHS_SMBTR_THMAX_Msk & (_UINT32_(value) << TWIHS_SMBTR_THMAX_Pos)) /* Assigment of value for THMAX in the TWIHS_SMBTR register */
#define TWIHS_SMBTR_Msk                       _UINT32_(0xFFFFFF0F)                                 /* (TWIHS_SMBTR) Register Mask  */


/* -------- TWIHS_FILTR : (TWIHS Offset: 0x44) (R/W 32) Filter Register -------- */
#define TWIHS_FILTR_FILT_Pos                  _UINT32_(0)                                          /* (TWIHS_FILTR) RX Digital Filter Position */
#define TWIHS_FILTR_FILT_Msk                  (_UINT32_(0x1) << TWIHS_FILTR_FILT_Pos)              /* (TWIHS_FILTR) RX Digital Filter Mask */
#define TWIHS_FILTR_FILT(value)               (TWIHS_FILTR_FILT_Msk & (_UINT32_(value) << TWIHS_FILTR_FILT_Pos)) /* Assigment of value for FILT in the TWIHS_FILTR register */
#define TWIHS_FILTR_PADFEN_Pos                _UINT32_(1)                                          /* (TWIHS_FILTR) PAD Filter Enable Position */
#define TWIHS_FILTR_PADFEN_Msk                (_UINT32_(0x1) << TWIHS_FILTR_PADFEN_Pos)            /* (TWIHS_FILTR) PAD Filter Enable Mask */
#define TWIHS_FILTR_PADFEN(value)             (TWIHS_FILTR_PADFEN_Msk & (_UINT32_(value) << TWIHS_FILTR_PADFEN_Pos)) /* Assigment of value for PADFEN in the TWIHS_FILTR register */
#define TWIHS_FILTR_PADFCFG_Pos               _UINT32_(2)                                          /* (TWIHS_FILTR) PAD Filter Config Position */
#define TWIHS_FILTR_PADFCFG_Msk               (_UINT32_(0x1) << TWIHS_FILTR_PADFCFG_Pos)           /* (TWIHS_FILTR) PAD Filter Config Mask */
#define TWIHS_FILTR_PADFCFG(value)            (TWIHS_FILTR_PADFCFG_Msk & (_UINT32_(value) << TWIHS_FILTR_PADFCFG_Pos)) /* Assigment of value for PADFCFG in the TWIHS_FILTR register */
#define TWIHS_FILTR_THRES_Pos                 _UINT32_(8)                                          /* (TWIHS_FILTR) Digital Filter Threshold Position */
#define TWIHS_FILTR_THRES_Msk                 (_UINT32_(0x7) << TWIHS_FILTR_THRES_Pos)             /* (TWIHS_FILTR) Digital Filter Threshold Mask */
#define TWIHS_FILTR_THRES(value)              (TWIHS_FILTR_THRES_Msk & (_UINT32_(value) << TWIHS_FILTR_THRES_Pos)) /* Assigment of value for THRES in the TWIHS_FILTR register */
#define TWIHS_FILTR_Msk                       _UINT32_(0x00000707)                                 /* (TWIHS_FILTR) Register Mask  */


/* -------- TWIHS_SWMR : (TWIHS Offset: 0x4C) (R/W 32) SleepWalking Matching Register -------- */
#define TWIHS_SWMR_SADR1_Pos                  _UINT32_(0)                                          /* (TWIHS_SWMR) Slave Address 1 Position */
#define TWIHS_SWMR_SADR1_Msk                  (_UINT32_(0x7F) << TWIHS_SWMR_SADR1_Pos)             /* (TWIHS_SWMR) Slave Address 1 Mask */
#define TWIHS_SWMR_SADR1(value)               (TWIHS_SWMR_SADR1_Msk & (_UINT32_(value) << TWIHS_SWMR_SADR1_Pos)) /* Assigment of value for SADR1 in the TWIHS_SWMR register */
#define TWIHS_SWMR_SADR2_Pos                  _UINT32_(8)                                          /* (TWIHS_SWMR) Slave Address 2 Position */
#define TWIHS_SWMR_SADR2_Msk                  (_UINT32_(0x7F) << TWIHS_SWMR_SADR2_Pos)             /* (TWIHS_SWMR) Slave Address 2 Mask */
#define TWIHS_SWMR_SADR2(value)               (TWIHS_SWMR_SADR2_Msk & (_UINT32_(value) << TWIHS_SWMR_SADR2_Pos)) /* Assigment of value for SADR2 in the TWIHS_SWMR register */
#define TWIHS_SWMR_SADR3_Pos                  _UINT32_(16)                                         /* (TWIHS_SWMR) Slave Address 3 Position */
#define TWIHS_SWMR_SADR3_Msk                  (_UINT32_(0x7F) << TWIHS_SWMR_SADR3_Pos)             /* (TWIHS_SWMR) Slave Address 3 Mask */
#define TWIHS_SWMR_SADR3(value)               (TWIHS_SWMR_SADR3_Msk & (_UINT32_(value) << TWIHS_SWMR_SADR3_Pos)) /* Assigment of value for SADR3 in the TWIHS_SWMR register */
#define TWIHS_SWMR_DATAM_Pos                  _UINT32_(24)                                         /* (TWIHS_SWMR) Data Match Position */
#define TWIHS_SWMR_DATAM_Msk                  (_UINT32_(0xFF) << TWIHS_SWMR_DATAM_Pos)             /* (TWIHS_SWMR) Data Match Mask */
#define TWIHS_SWMR_DATAM(value)               (TWIHS_SWMR_DATAM_Msk & (_UINT32_(value) << TWIHS_SWMR_DATAM_Pos)) /* Assigment of value for DATAM in the TWIHS_SWMR register */
#define TWIHS_SWMR_Msk                        _UINT32_(0xFF7F7F7F)                                 /* (TWIHS_SWMR) Register Mask  */


/* -------- TWIHS_WPMR : (TWIHS Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define TWIHS_WPMR_WPEN_Pos                   _UINT32_(0)                                          /* (TWIHS_WPMR) Write Protection Enable Position */
#define TWIHS_WPMR_WPEN_Msk                   (_UINT32_(0x1) << TWIHS_WPMR_WPEN_Pos)               /* (TWIHS_WPMR) Write Protection Enable Mask */
#define TWIHS_WPMR_WPEN(value)                (TWIHS_WPMR_WPEN_Msk & (_UINT32_(value) << TWIHS_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the TWIHS_WPMR register */
#define TWIHS_WPMR_WPKEY_Pos                  _UINT32_(8)                                          /* (TWIHS_WPMR) Write Protection Key Position */
#define TWIHS_WPMR_WPKEY_Msk                  (_UINT32_(0xFFFFFF) << TWIHS_WPMR_WPKEY_Pos)         /* (TWIHS_WPMR) Write Protection Key Mask */
#define TWIHS_WPMR_WPKEY(value)               (TWIHS_WPMR_WPKEY_Msk & (_UINT32_(value) << TWIHS_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the TWIHS_WPMR register */
#define   TWIHS_WPMR_WPKEY_PASSWD_Val         _UINT32_(0x545749)                                   /* (TWIHS_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0  */
#define TWIHS_WPMR_WPKEY_PASSWD               (TWIHS_WPMR_WPKEY_PASSWD_Val << TWIHS_WPMR_WPKEY_Pos) /* (TWIHS_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0 Position  */
#define TWIHS_WPMR_Msk                        _UINT32_(0xFFFFFF01)                                 /* (TWIHS_WPMR) Register Mask  */


/* -------- TWIHS_WPSR : (TWIHS Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define TWIHS_WPSR_WPVS_Pos                   _UINT32_(0)                                          /* (TWIHS_WPSR) Write Protection Violation Status Position */
#define TWIHS_WPSR_WPVS_Msk                   (_UINT32_(0x1) << TWIHS_WPSR_WPVS_Pos)               /* (TWIHS_WPSR) Write Protection Violation Status Mask */
#define TWIHS_WPSR_WPVS(value)                (TWIHS_WPSR_WPVS_Msk & (_UINT32_(value) << TWIHS_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the TWIHS_WPSR register */
#define TWIHS_WPSR_WPVSRC_Pos                 _UINT32_(8)                                          /* (TWIHS_WPSR) Write Protection Violation Source Position */
#define TWIHS_WPSR_WPVSRC_Msk                 (_UINT32_(0xFFFFFF) << TWIHS_WPSR_WPVSRC_Pos)        /* (TWIHS_WPSR) Write Protection Violation Source Mask */
#define TWIHS_WPSR_WPVSRC(value)              (TWIHS_WPSR_WPVSRC_Msk & (_UINT32_(value) << TWIHS_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the TWIHS_WPSR register */
#define TWIHS_WPSR_Msk                        _UINT32_(0xFFFFFF01)                                 /* (TWIHS_WPSR) Register Mask  */


/** \brief TWIHS register offsets definitions */
#define TWIHS_CR_REG_OFST              _UINT32_(0x00)      /* (TWIHS_CR) Control Register Offset */
#define TWIHS_MMR_REG_OFST             _UINT32_(0x04)      /* (TWIHS_MMR) Master Mode Register Offset */
#define TWIHS_SMR_REG_OFST             _UINT32_(0x08)      /* (TWIHS_SMR) Slave Mode Register Offset */
#define TWIHS_IADR_REG_OFST            _UINT32_(0x0C)      /* (TWIHS_IADR) Internal Address Register Offset */
#define TWIHS_CWGR_REG_OFST            _UINT32_(0x10)      /* (TWIHS_CWGR) Clock Waveform Generator Register Offset */
#define TWIHS_SR_REG_OFST              _UINT32_(0x20)      /* (TWIHS_SR) Status Register Offset */
#define TWIHS_IER_REG_OFST             _UINT32_(0x24)      /* (TWIHS_IER) Interrupt Enable Register Offset */
#define TWIHS_IDR_REG_OFST             _UINT32_(0x28)      /* (TWIHS_IDR) Interrupt Disable Register Offset */
#define TWIHS_IMR_REG_OFST             _UINT32_(0x2C)      /* (TWIHS_IMR) Interrupt Mask Register Offset */
#define TWIHS_RHR_REG_OFST             _UINT32_(0x30)      /* (TWIHS_RHR) Receive Holding Register Offset */
#define TWIHS_THR_REG_OFST             _UINT32_(0x34)      /* (TWIHS_THR) Transmit Holding Register Offset */
#define TWIHS_SMBTR_REG_OFST           _UINT32_(0x38)      /* (TWIHS_SMBTR) SMBus Timing Register Offset */
#define TWIHS_FILTR_REG_OFST           _UINT32_(0x44)      /* (TWIHS_FILTR) Filter Register Offset */
#define TWIHS_SWMR_REG_OFST            _UINT32_(0x4C)      /* (TWIHS_SWMR) SleepWalking Matching Register Offset */
#define TWIHS_WPMR_REG_OFST            _UINT32_(0xE4)      /* (TWIHS_WPMR) Write Protection Mode Register Offset */
#define TWIHS_WPSR_REG_OFST            _UINT32_(0xE8)      /* (TWIHS_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief TWIHS register API structure */
typedef struct
{
  __O   uint32_t                       TWIHS_CR;           /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       TWIHS_MMR;          /**< Offset: 0x04 (R/W  32) Master Mode Register */
  __IO  uint32_t                       TWIHS_SMR;          /**< Offset: 0x08 (R/W  32) Slave Mode Register */
  __IO  uint32_t                       TWIHS_IADR;         /**< Offset: 0x0C (R/W  32) Internal Address Register */
  __IO  uint32_t                       TWIHS_CWGR;         /**< Offset: 0x10 (R/W  32) Clock Waveform Generator Register */
  __I   uint8_t                        Reserved1[0x0C];
  __I   uint32_t                       TWIHS_SR;           /**< Offset: 0x20 (R/   32) Status Register */
  __O   uint32_t                       TWIHS_IER;          /**< Offset: 0x24 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       TWIHS_IDR;          /**< Offset: 0x28 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       TWIHS_IMR;          /**< Offset: 0x2C (R/   32) Interrupt Mask Register */
  __I   uint32_t                       TWIHS_RHR;          /**< Offset: 0x30 (R/   32) Receive Holding Register */
  __O   uint32_t                       TWIHS_THR;          /**< Offset: 0x34 ( /W  32) Transmit Holding Register */
  __IO  uint32_t                       TWIHS_SMBTR;        /**< Offset: 0x38 (R/W  32) SMBus Timing Register */
  __I   uint8_t                        Reserved2[0x08];
  __IO  uint32_t                       TWIHS_FILTR;        /**< Offset: 0x44 (R/W  32) Filter Register */
  __I   uint8_t                        Reserved3[0x04];
  __IO  uint32_t                       TWIHS_SWMR;         /**< Offset: 0x4C (R/W  32) SleepWalking Matching Register */
  __I   uint8_t                        Reserved4[0x94];
  __IO  uint32_t                       TWIHS_WPMR;         /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       TWIHS_WPSR;         /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} twihs_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME70_TWIHS_COMPONENT_H_ */
