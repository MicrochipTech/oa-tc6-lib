/*
 * Component description for SMC
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

/* file generated from device description version 2022-04-21T07:53:48Z */
#ifndef _SAME70_SMC_COMPONENT_H_
#define _SAME70_SMC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR SMC                                          */
/* ************************************************************************** */

/* -------- SMC_SETUP : (SMC Offset: 0x00) (R/W 32) SMC Setup Register -------- */
#define SMC_SETUP_NWE_SETUP_Pos               _UINT32_(0)                                          /* (SMC_SETUP) NWE Setup Length Position */
#define SMC_SETUP_NWE_SETUP_Msk               (_UINT32_(0x3F) << SMC_SETUP_NWE_SETUP_Pos)          /* (SMC_SETUP) NWE Setup Length Mask */
#define SMC_SETUP_NWE_SETUP(value)            (SMC_SETUP_NWE_SETUP_Msk & (_UINT32_(value) << SMC_SETUP_NWE_SETUP_Pos)) /* Assigment of value for NWE_SETUP in the SMC_SETUP register */
#define SMC_SETUP_NCS_WR_SETUP_Pos            _UINT32_(8)                                          /* (SMC_SETUP) NCS Setup Length in WRITE Access Position */
#define SMC_SETUP_NCS_WR_SETUP_Msk            (_UINT32_(0x3F) << SMC_SETUP_NCS_WR_SETUP_Pos)       /* (SMC_SETUP) NCS Setup Length in WRITE Access Mask */
#define SMC_SETUP_NCS_WR_SETUP(value)         (SMC_SETUP_NCS_WR_SETUP_Msk & (_UINT32_(value) << SMC_SETUP_NCS_WR_SETUP_Pos)) /* Assigment of value for NCS_WR_SETUP in the SMC_SETUP register */
#define SMC_SETUP_NRD_SETUP_Pos               _UINT32_(16)                                         /* (SMC_SETUP) NRD Setup Length Position */
#define SMC_SETUP_NRD_SETUP_Msk               (_UINT32_(0x3F) << SMC_SETUP_NRD_SETUP_Pos)          /* (SMC_SETUP) NRD Setup Length Mask */
#define SMC_SETUP_NRD_SETUP(value)            (SMC_SETUP_NRD_SETUP_Msk & (_UINT32_(value) << SMC_SETUP_NRD_SETUP_Pos)) /* Assigment of value for NRD_SETUP in the SMC_SETUP register */
#define SMC_SETUP_NCS_RD_SETUP_Pos            _UINT32_(24)                                         /* (SMC_SETUP) NCS Setup Length in READ Access Position */
#define SMC_SETUP_NCS_RD_SETUP_Msk            (_UINT32_(0x3F) << SMC_SETUP_NCS_RD_SETUP_Pos)       /* (SMC_SETUP) NCS Setup Length in READ Access Mask */
#define SMC_SETUP_NCS_RD_SETUP(value)         (SMC_SETUP_NCS_RD_SETUP_Msk & (_UINT32_(value) << SMC_SETUP_NCS_RD_SETUP_Pos)) /* Assigment of value for NCS_RD_SETUP in the SMC_SETUP register */
#define SMC_SETUP_Msk                         _UINT32_(0x3F3F3F3F)                                 /* (SMC_SETUP) Register Mask  */


/* -------- SMC_PULSE : (SMC Offset: 0x04) (R/W 32) SMC Pulse Register -------- */
#define SMC_PULSE_NWE_PULSE_Pos               _UINT32_(0)                                          /* (SMC_PULSE) NWE Pulse Length Position */
#define SMC_PULSE_NWE_PULSE_Msk               (_UINT32_(0x7F) << SMC_PULSE_NWE_PULSE_Pos)          /* (SMC_PULSE) NWE Pulse Length Mask */
#define SMC_PULSE_NWE_PULSE(value)            (SMC_PULSE_NWE_PULSE_Msk & (_UINT32_(value) << SMC_PULSE_NWE_PULSE_Pos)) /* Assigment of value for NWE_PULSE in the SMC_PULSE register */
#define SMC_PULSE_NCS_WR_PULSE_Pos            _UINT32_(8)                                          /* (SMC_PULSE) NCS Pulse Length in WRITE Access Position */
#define SMC_PULSE_NCS_WR_PULSE_Msk            (_UINT32_(0x7F) << SMC_PULSE_NCS_WR_PULSE_Pos)       /* (SMC_PULSE) NCS Pulse Length in WRITE Access Mask */
#define SMC_PULSE_NCS_WR_PULSE(value)         (SMC_PULSE_NCS_WR_PULSE_Msk & (_UINT32_(value) << SMC_PULSE_NCS_WR_PULSE_Pos)) /* Assigment of value for NCS_WR_PULSE in the SMC_PULSE register */
#define SMC_PULSE_NRD_PULSE_Pos               _UINT32_(16)                                         /* (SMC_PULSE) NRD Pulse Length Position */
#define SMC_PULSE_NRD_PULSE_Msk               (_UINT32_(0x7F) << SMC_PULSE_NRD_PULSE_Pos)          /* (SMC_PULSE) NRD Pulse Length Mask */
#define SMC_PULSE_NRD_PULSE(value)            (SMC_PULSE_NRD_PULSE_Msk & (_UINT32_(value) << SMC_PULSE_NRD_PULSE_Pos)) /* Assigment of value for NRD_PULSE in the SMC_PULSE register */
#define SMC_PULSE_NCS_RD_PULSE_Pos            _UINT32_(24)                                         /* (SMC_PULSE) NCS Pulse Length in READ Access Position */
#define SMC_PULSE_NCS_RD_PULSE_Msk            (_UINT32_(0x7F) << SMC_PULSE_NCS_RD_PULSE_Pos)       /* (SMC_PULSE) NCS Pulse Length in READ Access Mask */
#define SMC_PULSE_NCS_RD_PULSE(value)         (SMC_PULSE_NCS_RD_PULSE_Msk & (_UINT32_(value) << SMC_PULSE_NCS_RD_PULSE_Pos)) /* Assigment of value for NCS_RD_PULSE in the SMC_PULSE register */
#define SMC_PULSE_Msk                         _UINT32_(0x7F7F7F7F)                                 /* (SMC_PULSE) Register Mask  */


/* -------- SMC_CYCLE : (SMC Offset: 0x08) (R/W 32) SMC Cycle Register -------- */
#define SMC_CYCLE_NWE_CYCLE_Pos               _UINT32_(0)                                          /* (SMC_CYCLE) Total Write Cycle Length Position */
#define SMC_CYCLE_NWE_CYCLE_Msk               (_UINT32_(0x1FF) << SMC_CYCLE_NWE_CYCLE_Pos)         /* (SMC_CYCLE) Total Write Cycle Length Mask */
#define SMC_CYCLE_NWE_CYCLE(value)            (SMC_CYCLE_NWE_CYCLE_Msk & (_UINT32_(value) << SMC_CYCLE_NWE_CYCLE_Pos)) /* Assigment of value for NWE_CYCLE in the SMC_CYCLE register */
#define SMC_CYCLE_NRD_CYCLE_Pos               _UINT32_(16)                                         /* (SMC_CYCLE) Total Read Cycle Length Position */
#define SMC_CYCLE_NRD_CYCLE_Msk               (_UINT32_(0x1FF) << SMC_CYCLE_NRD_CYCLE_Pos)         /* (SMC_CYCLE) Total Read Cycle Length Mask */
#define SMC_CYCLE_NRD_CYCLE(value)            (SMC_CYCLE_NRD_CYCLE_Msk & (_UINT32_(value) << SMC_CYCLE_NRD_CYCLE_Pos)) /* Assigment of value for NRD_CYCLE in the SMC_CYCLE register */
#define SMC_CYCLE_Msk                         _UINT32_(0x01FF01FF)                                 /* (SMC_CYCLE) Register Mask  */


/* -------- SMC_MODE : (SMC Offset: 0x0C) (R/W 32) SMC Mode Register -------- */
#define SMC_MODE_READ_MODE_Pos                _UINT32_(0)                                          /* (SMC_MODE) Read Mode Position */
#define SMC_MODE_READ_MODE_Msk                (_UINT32_(0x1) << SMC_MODE_READ_MODE_Pos)            /* (SMC_MODE) Read Mode Mask */
#define SMC_MODE_READ_MODE(value)             (SMC_MODE_READ_MODE_Msk & (_UINT32_(value) << SMC_MODE_READ_MODE_Pos)) /* Assigment of value for READ_MODE in the SMC_MODE register */
#define SMC_MODE_WRITE_MODE_Pos               _UINT32_(1)                                          /* (SMC_MODE) Write Mode Position */
#define SMC_MODE_WRITE_MODE_Msk               (_UINT32_(0x1) << SMC_MODE_WRITE_MODE_Pos)           /* (SMC_MODE) Write Mode Mask */
#define SMC_MODE_WRITE_MODE(value)            (SMC_MODE_WRITE_MODE_Msk & (_UINT32_(value) << SMC_MODE_WRITE_MODE_Pos)) /* Assigment of value for WRITE_MODE in the SMC_MODE register */
#define SMC_MODE_EXNW_MODE_Pos                _UINT32_(4)                                          /* (SMC_MODE) NWAIT Mode Position */
#define SMC_MODE_EXNW_MODE_Msk                (_UINT32_(0x3) << SMC_MODE_EXNW_MODE_Pos)            /* (SMC_MODE) NWAIT Mode Mask */
#define SMC_MODE_EXNW_MODE(value)             (SMC_MODE_EXNW_MODE_Msk & (_UINT32_(value) << SMC_MODE_EXNW_MODE_Pos)) /* Assigment of value for EXNW_MODE in the SMC_MODE register */
#define   SMC_MODE_EXNW_MODE_DISABLED_Val     _UINT32_(0x0)                                        /* (SMC_MODE) Disabled-The NWAIT input signal is ignored on the corresponding chip select.  */
#define   SMC_MODE_EXNW_MODE_FROZEN_Val       _UINT32_(0x2)                                        /* (SMC_MODE) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.  */
#define   SMC_MODE_EXNW_MODE_READY_Val        _UINT32_(0x3)                                        /* (SMC_MODE) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.  */
#define SMC_MODE_EXNW_MODE_DISABLED           (SMC_MODE_EXNW_MODE_DISABLED_Val << SMC_MODE_EXNW_MODE_Pos) /* (SMC_MODE) Disabled-The NWAIT input signal is ignored on the corresponding chip select. Position  */
#define SMC_MODE_EXNW_MODE_FROZEN             (SMC_MODE_EXNW_MODE_FROZEN_Val << SMC_MODE_EXNW_MODE_Pos) /* (SMC_MODE) Frozen Mode-If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped. Position  */
#define SMC_MODE_EXNW_MODE_READY              (SMC_MODE_EXNW_MODE_READY_Val << SMC_MODE_EXNW_MODE_Pos) /* (SMC_MODE) Ready Mode-The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high. Position  */
#define SMC_MODE_BAT_Pos                      _UINT32_(8)                                          /* (SMC_MODE) Byte Access Type Position */
#define SMC_MODE_BAT_Msk                      (_UINT32_(0x1) << SMC_MODE_BAT_Pos)                  /* (SMC_MODE) Byte Access Type Mask */
#define SMC_MODE_BAT(value)                   (SMC_MODE_BAT_Msk & (_UINT32_(value) << SMC_MODE_BAT_Pos)) /* Assigment of value for BAT in the SMC_MODE register */
#define   SMC_MODE_BAT_BYTE_SELECT_Val        _UINT32_(0x0)                                        /* (SMC_MODE) Byte select access type:- Write operation is controlled using NCS, NWE, NBS0, NBS1.- Read operation is controlled using NCS, NRD, NBS0, NBS1.  */
#define   SMC_MODE_BAT_BYTE_WRITE_Val         _UINT32_(0x1)                                        /* (SMC_MODE) Byte write access type:- Write operation is controlled using NCS, NWR0, NWR1.- Read operation is controlled using NCS and NRD.  */
#define SMC_MODE_BAT_BYTE_SELECT              (SMC_MODE_BAT_BYTE_SELECT_Val << SMC_MODE_BAT_Pos)   /* (SMC_MODE) Byte select access type:- Write operation is controlled using NCS, NWE, NBS0, NBS1.- Read operation is controlled using NCS, NRD, NBS0, NBS1. Position  */
#define SMC_MODE_BAT_BYTE_WRITE               (SMC_MODE_BAT_BYTE_WRITE_Val << SMC_MODE_BAT_Pos)    /* (SMC_MODE) Byte write access type:- Write operation is controlled using NCS, NWR0, NWR1.- Read operation is controlled using NCS and NRD. Position  */
#define SMC_MODE_DBW_Pos                      _UINT32_(12)                                         /* (SMC_MODE) Data Bus Width Position */
#define SMC_MODE_DBW_Msk                      (_UINT32_(0x1) << SMC_MODE_DBW_Pos)                  /* (SMC_MODE) Data Bus Width Mask */
#define SMC_MODE_DBW(value)                   (SMC_MODE_DBW_Msk & (_UINT32_(value) << SMC_MODE_DBW_Pos)) /* Assigment of value for DBW in the SMC_MODE register */
#define   SMC_MODE_DBW_8_BIT_Val              _UINT32_(0x0)                                        /* (SMC_MODE) 8-bit Data Bus  */
#define   SMC_MODE_DBW_16_BIT_Val             _UINT32_(0x1)                                        /* (SMC_MODE) 16-bit Data Bus  */
#define SMC_MODE_DBW_8_BIT                    (SMC_MODE_DBW_8_BIT_Val << SMC_MODE_DBW_Pos)         /* (SMC_MODE) 8-bit Data Bus Position  */
#define SMC_MODE_DBW_16_BIT                   (SMC_MODE_DBW_16_BIT_Val << SMC_MODE_DBW_Pos)        /* (SMC_MODE) 16-bit Data Bus Position  */
#define SMC_MODE_TDF_CYCLES_Pos               _UINT32_(16)                                         /* (SMC_MODE) Data Float Time Position */
#define SMC_MODE_TDF_CYCLES_Msk               (_UINT32_(0xF) << SMC_MODE_TDF_CYCLES_Pos)           /* (SMC_MODE) Data Float Time Mask */
#define SMC_MODE_TDF_CYCLES(value)            (SMC_MODE_TDF_CYCLES_Msk & (_UINT32_(value) << SMC_MODE_TDF_CYCLES_Pos)) /* Assigment of value for TDF_CYCLES in the SMC_MODE register */
#define SMC_MODE_TDF_MODE_Pos                 _UINT32_(20)                                         /* (SMC_MODE) TDF Optimization Position */
#define SMC_MODE_TDF_MODE_Msk                 (_UINT32_(0x1) << SMC_MODE_TDF_MODE_Pos)             /* (SMC_MODE) TDF Optimization Mask */
#define SMC_MODE_TDF_MODE(value)              (SMC_MODE_TDF_MODE_Msk & (_UINT32_(value) << SMC_MODE_TDF_MODE_Pos)) /* Assigment of value for TDF_MODE in the SMC_MODE register */
#define SMC_MODE_PMEN_Pos                     _UINT32_(24)                                         /* (SMC_MODE) Page Mode Enabled Position */
#define SMC_MODE_PMEN_Msk                     (_UINT32_(0x1) << SMC_MODE_PMEN_Pos)                 /* (SMC_MODE) Page Mode Enabled Mask */
#define SMC_MODE_PMEN(value)                  (SMC_MODE_PMEN_Msk & (_UINT32_(value) << SMC_MODE_PMEN_Pos)) /* Assigment of value for PMEN in the SMC_MODE register */
#define SMC_MODE_PS_Pos                       _UINT32_(28)                                         /* (SMC_MODE) Page Size Position */
#define SMC_MODE_PS_Msk                       (_UINT32_(0x3) << SMC_MODE_PS_Pos)                   /* (SMC_MODE) Page Size Mask */
#define SMC_MODE_PS(value)                    (SMC_MODE_PS_Msk & (_UINT32_(value) << SMC_MODE_PS_Pos)) /* Assigment of value for PS in the SMC_MODE register */
#define   SMC_MODE_PS_4_BYTE_Val              _UINT32_(0x0)                                        /* (SMC_MODE) 4-byte page  */
#define   SMC_MODE_PS_8_BYTE_Val              _UINT32_(0x1)                                        /* (SMC_MODE) 8-byte page  */
#define   SMC_MODE_PS_16_BYTE_Val             _UINT32_(0x2)                                        /* (SMC_MODE) 16-byte page  */
#define   SMC_MODE_PS_32_BYTE_Val             _UINT32_(0x3)                                        /* (SMC_MODE) 32-byte page  */
#define SMC_MODE_PS_4_BYTE                    (SMC_MODE_PS_4_BYTE_Val << SMC_MODE_PS_Pos)          /* (SMC_MODE) 4-byte page Position  */
#define SMC_MODE_PS_8_BYTE                    (SMC_MODE_PS_8_BYTE_Val << SMC_MODE_PS_Pos)          /* (SMC_MODE) 8-byte page Position  */
#define SMC_MODE_PS_16_BYTE                   (SMC_MODE_PS_16_BYTE_Val << SMC_MODE_PS_Pos)         /* (SMC_MODE) 16-byte page Position  */
#define SMC_MODE_PS_32_BYTE                   (SMC_MODE_PS_32_BYTE_Val << SMC_MODE_PS_Pos)         /* (SMC_MODE) 32-byte page Position  */
#define SMC_MODE_Msk                          _UINT32_(0x311F1133)                                 /* (SMC_MODE) Register Mask  */


/* -------- SMC_OCMS : (SMC Offset: 0x80) (R/W 32) SMC Off-Chip Memory Scrambling Register -------- */
#define SMC_OCMS_SMSE_Pos                     _UINT32_(0)                                          /* (SMC_OCMS) Static Memory Controller Scrambling Enable Position */
#define SMC_OCMS_SMSE_Msk                     (_UINT32_(0x1) << SMC_OCMS_SMSE_Pos)                 /* (SMC_OCMS) Static Memory Controller Scrambling Enable Mask */
#define SMC_OCMS_SMSE(value)                  (SMC_OCMS_SMSE_Msk & (_UINT32_(value) << SMC_OCMS_SMSE_Pos)) /* Assigment of value for SMSE in the SMC_OCMS register */
#define SMC_OCMS_CS0SE_Pos                    _UINT32_(8)                                          /* (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable Position */
#define SMC_OCMS_CS0SE_Msk                    (_UINT32_(0x1) << SMC_OCMS_CS0SE_Pos)                /* (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable Mask */
#define SMC_OCMS_CS0SE(value)                 (SMC_OCMS_CS0SE_Msk & (_UINT32_(value) << SMC_OCMS_CS0SE_Pos)) /* Assigment of value for CS0SE in the SMC_OCMS register */
#define SMC_OCMS_CS1SE_Pos                    _UINT32_(9)                                          /* (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable Position */
#define SMC_OCMS_CS1SE_Msk                    (_UINT32_(0x1) << SMC_OCMS_CS1SE_Pos)                /* (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable Mask */
#define SMC_OCMS_CS1SE(value)                 (SMC_OCMS_CS1SE_Msk & (_UINT32_(value) << SMC_OCMS_CS1SE_Pos)) /* Assigment of value for CS1SE in the SMC_OCMS register */
#define SMC_OCMS_CS2SE_Pos                    _UINT32_(10)                                         /* (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable Position */
#define SMC_OCMS_CS2SE_Msk                    (_UINT32_(0x1) << SMC_OCMS_CS2SE_Pos)                /* (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable Mask */
#define SMC_OCMS_CS2SE(value)                 (SMC_OCMS_CS2SE_Msk & (_UINT32_(value) << SMC_OCMS_CS2SE_Pos)) /* Assigment of value for CS2SE in the SMC_OCMS register */
#define SMC_OCMS_CS3SE_Pos                    _UINT32_(11)                                         /* (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable Position */
#define SMC_OCMS_CS3SE_Msk                    (_UINT32_(0x1) << SMC_OCMS_CS3SE_Pos)                /* (SMC_OCMS) Chip Select (x = 0 to 3) Scrambling Enable Mask */
#define SMC_OCMS_CS3SE(value)                 (SMC_OCMS_CS3SE_Msk & (_UINT32_(value) << SMC_OCMS_CS3SE_Pos)) /* Assigment of value for CS3SE in the SMC_OCMS register */
#define SMC_OCMS_Msk                          _UINT32_(0x00000F01)                                 /* (SMC_OCMS) Register Mask  */


/* -------- SMC_KEY1 : (SMC Offset: 0x84) ( /W 32) SMC Off-Chip Memory Scrambling KEY1 Register -------- */
#define SMC_KEY1_KEY1_Pos                     _UINT32_(0)                                          /* (SMC_KEY1) Off-Chip Memory Scrambling (OCMS) Key Part 1 Position */
#define SMC_KEY1_KEY1_Msk                     (_UINT32_(0xFFFFFFFF) << SMC_KEY1_KEY1_Pos)          /* (SMC_KEY1) Off-Chip Memory Scrambling (OCMS) Key Part 1 Mask */
#define SMC_KEY1_KEY1(value)                  (SMC_KEY1_KEY1_Msk & (_UINT32_(value) << SMC_KEY1_KEY1_Pos)) /* Assigment of value for KEY1 in the SMC_KEY1 register */
#define SMC_KEY1_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (SMC_KEY1) Register Mask  */


/* -------- SMC_KEY2 : (SMC Offset: 0x88) ( /W 32) SMC Off-Chip Memory Scrambling KEY2 Register -------- */
#define SMC_KEY2_KEY2_Pos                     _UINT32_(0)                                          /* (SMC_KEY2) Off-Chip Memory Scrambling (OCMS) Key Part 2 Position */
#define SMC_KEY2_KEY2_Msk                     (_UINT32_(0xFFFFFFFF) << SMC_KEY2_KEY2_Pos)          /* (SMC_KEY2) Off-Chip Memory Scrambling (OCMS) Key Part 2 Mask */
#define SMC_KEY2_KEY2(value)                  (SMC_KEY2_KEY2_Msk & (_UINT32_(value) << SMC_KEY2_KEY2_Pos)) /* Assigment of value for KEY2 in the SMC_KEY2 register */
#define SMC_KEY2_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (SMC_KEY2) Register Mask  */


/* -------- SMC_WPMR : (SMC Offset: 0xE4) (R/W 32) SMC Write Protection Mode Register -------- */
#define SMC_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (SMC_WPMR) Write Protect Enable Position */
#define SMC_WPMR_WPEN_Msk                     (_UINT32_(0x1) << SMC_WPMR_WPEN_Pos)                 /* (SMC_WPMR) Write Protect Enable Mask */
#define SMC_WPMR_WPEN(value)                  (SMC_WPMR_WPEN_Msk & (_UINT32_(value) << SMC_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the SMC_WPMR register */
#define SMC_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (SMC_WPMR) Write Protection Key Position */
#define SMC_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << SMC_WPMR_WPKEY_Pos)           /* (SMC_WPMR) Write Protection Key Mask */
#define SMC_WPMR_WPKEY(value)                 (SMC_WPMR_WPKEY_Msk & (_UINT32_(value) << SMC_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the SMC_WPMR register */
#define   SMC_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x534D43)                                   /* (SMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0.  */
#define SMC_WPMR_WPKEY_PASSWD                 (SMC_WPMR_WPKEY_PASSWD_Val << SMC_WPMR_WPKEY_Pos)    /* (SMC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit. Always reads as 0. Position  */
#define SMC_WPMR_Msk                          _UINT32_(0xFFFFFF01)                                 /* (SMC_WPMR) Register Mask  */


/* -------- SMC_WPSR : (SMC Offset: 0xE8) ( R/ 32) SMC Write Protection Status Register -------- */
#define SMC_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (SMC_WPSR) Write Protection Violation Status Position */
#define SMC_WPSR_WPVS_Msk                     (_UINT32_(0x1) << SMC_WPSR_WPVS_Pos)                 /* (SMC_WPSR) Write Protection Violation Status Mask */
#define SMC_WPSR_WPVS(value)                  (SMC_WPSR_WPVS_Msk & (_UINT32_(value) << SMC_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the SMC_WPSR register */
#define SMC_WPSR_WPVSRC_Pos                   _UINT32_(8)                                          /* (SMC_WPSR) Write Protection Violation Source Position */
#define SMC_WPSR_WPVSRC_Msk                   (_UINT32_(0xFFFF) << SMC_WPSR_WPVSRC_Pos)            /* (SMC_WPSR) Write Protection Violation Source Mask */
#define SMC_WPSR_WPVSRC(value)                (SMC_WPSR_WPVSRC_Msk & (_UINT32_(value) << SMC_WPSR_WPVSRC_Pos)) /* Assigment of value for WPVSRC in the SMC_WPSR register */
#define SMC_WPSR_Msk                          _UINT32_(0x00FFFF01)                                 /* (SMC_WPSR) Register Mask  */


/** \brief SMC register offsets definitions */
#define SMC_SETUP_REG_OFST             _UINT32_(0x00)      /* (SMC_SETUP) SMC Setup Register Offset */
#define SMC_PULSE_REG_OFST             _UINT32_(0x04)      /* (SMC_PULSE) SMC Pulse Register Offset */
#define SMC_CYCLE_REG_OFST             _UINT32_(0x08)      /* (SMC_CYCLE) SMC Cycle Register Offset */
#define SMC_MODE_REG_OFST              _UINT32_(0x0C)      /* (SMC_MODE) SMC Mode Register Offset */
#define SMC_OCMS_REG_OFST              _UINT32_(0x80)      /* (SMC_OCMS) SMC Off-Chip Memory Scrambling Register Offset */
#define SMC_KEY1_REG_OFST              _UINT32_(0x84)      /* (SMC_KEY1) SMC Off-Chip Memory Scrambling KEY1 Register Offset */
#define SMC_KEY2_REG_OFST              _UINT32_(0x88)      /* (SMC_KEY2) SMC Off-Chip Memory Scrambling KEY2 Register Offset */
#define SMC_WPMR_REG_OFST              _UINT32_(0xE4)      /* (SMC_WPMR) SMC Write Protection Mode Register Offset */
#define SMC_WPSR_REG_OFST              _UINT32_(0xE8)      /* (SMC_WPSR) SMC Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief SMC_CS_NUMBER register API structure */
typedef struct
{
  __IO  uint32_t                       SMC_SETUP;          /**< Offset: 0x00 (R/W  32) SMC Setup Register */
  __IO  uint32_t                       SMC_PULSE;          /**< Offset: 0x04 (R/W  32) SMC Pulse Register */
  __IO  uint32_t                       SMC_CYCLE;          /**< Offset: 0x08 (R/W  32) SMC Cycle Register */
  __IO  uint32_t                       SMC_MODE;           /**< Offset: 0x0C (R/W  32) SMC Mode Register */
} smc_cs_number_registers_t;

#define SMC_CS_NUMBER_NUMBER 4

/** \brief SMC register API structure */
typedef struct
{
        smc_cs_number_registers_t      SMC_CS_NUMBER[SMC_CS_NUMBER_NUMBER]; /**< Offset: 0x00 SMC Setup Register */
  __I   uint8_t                        Reserved1[0x40];
  __IO  uint32_t                       SMC_OCMS;           /**< Offset: 0x80 (R/W  32) SMC Off-Chip Memory Scrambling Register */
  __O   uint32_t                       SMC_KEY1;           /**< Offset: 0x84 ( /W  32) SMC Off-Chip Memory Scrambling KEY1 Register */
  __O   uint32_t                       SMC_KEY2;           /**< Offset: 0x88 ( /W  32) SMC Off-Chip Memory Scrambling KEY2 Register */
  __I   uint8_t                        Reserved2[0x58];
  __IO  uint32_t                       SMC_WPMR;           /**< Offset: 0xE4 (R/W  32) SMC Write Protection Mode Register */
  __I   uint32_t                       SMC_WPSR;           /**< Offset: 0xE8 (R/   32) SMC Write Protection Status Register */
} smc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME70_SMC_COMPONENT_H_ */
