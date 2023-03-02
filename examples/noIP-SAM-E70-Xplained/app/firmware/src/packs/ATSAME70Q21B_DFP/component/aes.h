/*
 * Component description for AES
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
#ifndef _SAME70_AES_COMPONENT_H_
#define _SAME70_AES_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR AES                                          */
/* ************************************************************************** */

/* -------- AES_CR : (AES Offset: 0x00) ( /W 32) Control Register -------- */
#define AES_CR_START_Pos                      _UINT32_(0)                                          /* (AES_CR) Start Processing Position */
#define AES_CR_START_Msk                      (_UINT32_(0x1) << AES_CR_START_Pos)                  /* (AES_CR) Start Processing Mask */
#define AES_CR_START(value)                   (AES_CR_START_Msk & (_UINT32_(value) << AES_CR_START_Pos)) /* Assigment of value for START in the AES_CR register */
#define AES_CR_SWRST_Pos                      _UINT32_(8)                                          /* (AES_CR) Software Reset Position */
#define AES_CR_SWRST_Msk                      (_UINT32_(0x1) << AES_CR_SWRST_Pos)                  /* (AES_CR) Software Reset Mask */
#define AES_CR_SWRST(value)                   (AES_CR_SWRST_Msk & (_UINT32_(value) << AES_CR_SWRST_Pos)) /* Assigment of value for SWRST in the AES_CR register */
#define AES_CR_LOADSEED_Pos                   _UINT32_(16)                                         /* (AES_CR) Random Number Generator Seed Loading Position */
#define AES_CR_LOADSEED_Msk                   (_UINT32_(0x1) << AES_CR_LOADSEED_Pos)               /* (AES_CR) Random Number Generator Seed Loading Mask */
#define AES_CR_LOADSEED(value)                (AES_CR_LOADSEED_Msk & (_UINT32_(value) << AES_CR_LOADSEED_Pos)) /* Assigment of value for LOADSEED in the AES_CR register */
#define AES_CR_Msk                            _UINT32_(0x00010101)                                 /* (AES_CR) Register Mask  */


/* -------- AES_MR : (AES Offset: 0x04) (R/W 32) Mode Register -------- */
#define AES_MR_CIPHER_Pos                     _UINT32_(0)                                          /* (AES_MR) Processing Mode Position */
#define AES_MR_CIPHER_Msk                     (_UINT32_(0x1) << AES_MR_CIPHER_Pos)                 /* (AES_MR) Processing Mode Mask */
#define AES_MR_CIPHER(value)                  (AES_MR_CIPHER_Msk & (_UINT32_(value) << AES_MR_CIPHER_Pos)) /* Assigment of value for CIPHER in the AES_MR register */
#define AES_MR_GTAGEN_Pos                     _UINT32_(1)                                          /* (AES_MR) GCM Automatic Tag Generation Enable Position */
#define AES_MR_GTAGEN_Msk                     (_UINT32_(0x1) << AES_MR_GTAGEN_Pos)                 /* (AES_MR) GCM Automatic Tag Generation Enable Mask */
#define AES_MR_GTAGEN(value)                  (AES_MR_GTAGEN_Msk & (_UINT32_(value) << AES_MR_GTAGEN_Pos)) /* Assigment of value for GTAGEN in the AES_MR register */
#define AES_MR_DUALBUFF_Pos                   _UINT32_(3)                                          /* (AES_MR) Dual Input Buffer Position */
#define AES_MR_DUALBUFF_Msk                   (_UINT32_(0x1) << AES_MR_DUALBUFF_Pos)               /* (AES_MR) Dual Input Buffer Mask */
#define AES_MR_DUALBUFF(value)                (AES_MR_DUALBUFF_Msk & (_UINT32_(value) << AES_MR_DUALBUFF_Pos)) /* Assigment of value for DUALBUFF in the AES_MR register */
#define   AES_MR_DUALBUFF_INACTIVE_Val        _UINT32_(0x0)                                        /* (AES_MR) AES_IDATARx cannot be written during processing of previous block.  */
#define   AES_MR_DUALBUFF_ACTIVE_Val          _UINT32_(0x1)                                        /* (AES_MR) AES_IDATARx can be written during processing of previous block when SMOD = 2. It speeds up the overall runtime of large files.  */
#define AES_MR_DUALBUFF_INACTIVE              (AES_MR_DUALBUFF_INACTIVE_Val << AES_MR_DUALBUFF_Pos) /* (AES_MR) AES_IDATARx cannot be written during processing of previous block. Position  */
#define AES_MR_DUALBUFF_ACTIVE                (AES_MR_DUALBUFF_ACTIVE_Val << AES_MR_DUALBUFF_Pos)  /* (AES_MR) AES_IDATARx can be written during processing of previous block when SMOD = 2. It speeds up the overall runtime of large files. Position  */
#define AES_MR_PROCDLY_Pos                    _UINT32_(4)                                          /* (AES_MR) Processing Delay Position */
#define AES_MR_PROCDLY_Msk                    (_UINT32_(0xF) << AES_MR_PROCDLY_Pos)                /* (AES_MR) Processing Delay Mask */
#define AES_MR_PROCDLY(value)                 (AES_MR_PROCDLY_Msk & (_UINT32_(value) << AES_MR_PROCDLY_Pos)) /* Assigment of value for PROCDLY in the AES_MR register */
#define AES_MR_SMOD_Pos                       _UINT32_(8)                                          /* (AES_MR) Start Mode Position */
#define AES_MR_SMOD_Msk                       (_UINT32_(0x3) << AES_MR_SMOD_Pos)                   /* (AES_MR) Start Mode Mask */
#define AES_MR_SMOD(value)                    (AES_MR_SMOD_Msk & (_UINT32_(value) << AES_MR_SMOD_Pos)) /* Assigment of value for SMOD in the AES_MR register */
#define   AES_MR_SMOD_MANUAL_START_Val        _UINT32_(0x0)                                        /* (AES_MR) Manual Mode  */
#define   AES_MR_SMOD_AUTO_START_Val          _UINT32_(0x1)                                        /* (AES_MR) Auto Mode  */
#define   AES_MR_SMOD_IDATAR0_START_Val       _UINT32_(0x2)                                        /* (AES_MR) AES_IDATAR0 access only Auto Mode (DMA)  */
#define AES_MR_SMOD_MANUAL_START              (AES_MR_SMOD_MANUAL_START_Val << AES_MR_SMOD_Pos)    /* (AES_MR) Manual Mode Position  */
#define AES_MR_SMOD_AUTO_START                (AES_MR_SMOD_AUTO_START_Val << AES_MR_SMOD_Pos)      /* (AES_MR) Auto Mode Position  */
#define AES_MR_SMOD_IDATAR0_START             (AES_MR_SMOD_IDATAR0_START_Val << AES_MR_SMOD_Pos)   /* (AES_MR) AES_IDATAR0 access only Auto Mode (DMA) Position  */
#define AES_MR_KEYSIZE_Pos                    _UINT32_(10)                                         /* (AES_MR) Key Size Position */
#define AES_MR_KEYSIZE_Msk                    (_UINT32_(0x3) << AES_MR_KEYSIZE_Pos)                /* (AES_MR) Key Size Mask */
#define AES_MR_KEYSIZE(value)                 (AES_MR_KEYSIZE_Msk & (_UINT32_(value) << AES_MR_KEYSIZE_Pos)) /* Assigment of value for KEYSIZE in the AES_MR register */
#define   AES_MR_KEYSIZE_AES128_Val           _UINT32_(0x0)                                        /* (AES_MR) AES Key Size is 128 bits  */
#define   AES_MR_KEYSIZE_AES192_Val           _UINT32_(0x1)                                        /* (AES_MR) AES Key Size is 192 bits  */
#define   AES_MR_KEYSIZE_AES256_Val           _UINT32_(0x2)                                        /* (AES_MR) AES Key Size is 256 bits  */
#define AES_MR_KEYSIZE_AES128                 (AES_MR_KEYSIZE_AES128_Val << AES_MR_KEYSIZE_Pos)    /* (AES_MR) AES Key Size is 128 bits Position  */
#define AES_MR_KEYSIZE_AES192                 (AES_MR_KEYSIZE_AES192_Val << AES_MR_KEYSIZE_Pos)    /* (AES_MR) AES Key Size is 192 bits Position  */
#define AES_MR_KEYSIZE_AES256                 (AES_MR_KEYSIZE_AES256_Val << AES_MR_KEYSIZE_Pos)    /* (AES_MR) AES Key Size is 256 bits Position  */
#define AES_MR_OPMOD_Pos                      _UINT32_(12)                                         /* (AES_MR) Operating Mode Position */
#define AES_MR_OPMOD_Msk                      (_UINT32_(0x7) << AES_MR_OPMOD_Pos)                  /* (AES_MR) Operating Mode Mask */
#define AES_MR_OPMOD(value)                   (AES_MR_OPMOD_Msk & (_UINT32_(value) << AES_MR_OPMOD_Pos)) /* Assigment of value for OPMOD in the AES_MR register */
#define   AES_MR_OPMOD_ECB_Val                _UINT32_(0x0)                                        /* (AES_MR) ECB: Electronic Code Book mode  */
#define   AES_MR_OPMOD_CBC_Val                _UINT32_(0x1)                                        /* (AES_MR) CBC: Cipher Block Chaining mode  */
#define   AES_MR_OPMOD_OFB_Val                _UINT32_(0x2)                                        /* (AES_MR) OFB: Output Feedback mode  */
#define   AES_MR_OPMOD_CFB_Val                _UINT32_(0x3)                                        /* (AES_MR) CFB: Cipher Feedback mode  */
#define   AES_MR_OPMOD_CTR_Val                _UINT32_(0x4)                                        /* (AES_MR) CTR: Counter mode (16-bit internal counter)  */
#define   AES_MR_OPMOD_GCM_Val                _UINT32_(0x5)                                        /* (AES_MR) GCM: Galois/Counter mode  */
#define AES_MR_OPMOD_ECB                      (AES_MR_OPMOD_ECB_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) ECB: Electronic Code Book mode Position  */
#define AES_MR_OPMOD_CBC                      (AES_MR_OPMOD_CBC_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) CBC: Cipher Block Chaining mode Position  */
#define AES_MR_OPMOD_OFB                      (AES_MR_OPMOD_OFB_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) OFB: Output Feedback mode Position  */
#define AES_MR_OPMOD_CFB                      (AES_MR_OPMOD_CFB_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) CFB: Cipher Feedback mode Position  */
#define AES_MR_OPMOD_CTR                      (AES_MR_OPMOD_CTR_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) CTR: Counter mode (16-bit internal counter) Position  */
#define AES_MR_OPMOD_GCM                      (AES_MR_OPMOD_GCM_Val << AES_MR_OPMOD_Pos)           /* (AES_MR) GCM: Galois/Counter mode Position  */
#define AES_MR_LOD_Pos                        _UINT32_(15)                                         /* (AES_MR) Last Output Data Mode Position */
#define AES_MR_LOD_Msk                        (_UINT32_(0x1) << AES_MR_LOD_Pos)                    /* (AES_MR) Last Output Data Mode Mask */
#define AES_MR_LOD(value)                     (AES_MR_LOD_Msk & (_UINT32_(value) << AES_MR_LOD_Pos)) /* Assigment of value for LOD in the AES_MR register */
#define AES_MR_CFBS_Pos                       _UINT32_(16)                                         /* (AES_MR) Cipher Feedback Data Size Position */
#define AES_MR_CFBS_Msk                       (_UINT32_(0x7) << AES_MR_CFBS_Pos)                   /* (AES_MR) Cipher Feedback Data Size Mask */
#define AES_MR_CFBS(value)                    (AES_MR_CFBS_Msk & (_UINT32_(value) << AES_MR_CFBS_Pos)) /* Assigment of value for CFBS in the AES_MR register */
#define   AES_MR_CFBS_SIZE_128BIT_Val         _UINT32_(0x0)                                        /* (AES_MR) 128-bit  */
#define   AES_MR_CFBS_SIZE_64BIT_Val          _UINT32_(0x1)                                        /* (AES_MR) 64-bit  */
#define   AES_MR_CFBS_SIZE_32BIT_Val          _UINT32_(0x2)                                        /* (AES_MR) 32-bit  */
#define   AES_MR_CFBS_SIZE_16BIT_Val          _UINT32_(0x3)                                        /* (AES_MR) 16-bit  */
#define   AES_MR_CFBS_SIZE_8BIT_Val           _UINT32_(0x4)                                        /* (AES_MR) 8-bit  */
#define AES_MR_CFBS_SIZE_128BIT               (AES_MR_CFBS_SIZE_128BIT_Val << AES_MR_CFBS_Pos)     /* (AES_MR) 128-bit Position  */
#define AES_MR_CFBS_SIZE_64BIT                (AES_MR_CFBS_SIZE_64BIT_Val << AES_MR_CFBS_Pos)      /* (AES_MR) 64-bit Position  */
#define AES_MR_CFBS_SIZE_32BIT                (AES_MR_CFBS_SIZE_32BIT_Val << AES_MR_CFBS_Pos)      /* (AES_MR) 32-bit Position  */
#define AES_MR_CFBS_SIZE_16BIT                (AES_MR_CFBS_SIZE_16BIT_Val << AES_MR_CFBS_Pos)      /* (AES_MR) 16-bit Position  */
#define AES_MR_CFBS_SIZE_8BIT                 (AES_MR_CFBS_SIZE_8BIT_Val << AES_MR_CFBS_Pos)       /* (AES_MR) 8-bit Position  */
#define AES_MR_CKEY_Pos                       _UINT32_(20)                                         /* (AES_MR) Countermeasure Key Position */
#define AES_MR_CKEY_Msk                       (_UINT32_(0xF) << AES_MR_CKEY_Pos)                   /* (AES_MR) Countermeasure Key Mask */
#define AES_MR_CKEY(value)                    (AES_MR_CKEY_Msk & (_UINT32_(value) << AES_MR_CKEY_Pos)) /* Assigment of value for CKEY in the AES_MR register */
#define   AES_MR_CKEY_PASSWD_Val              _UINT32_(0xE)                                        /* (AES_MR) This field must be written with 0xE to allow CMTYPx bit configuration changes. Any other values will abort the write operation in CMTYPx bits.Always reads as 0.  */
#define AES_MR_CKEY_PASSWD                    (AES_MR_CKEY_PASSWD_Val << AES_MR_CKEY_Pos)          /* (AES_MR) This field must be written with 0xE to allow CMTYPx bit configuration changes. Any other values will abort the write operation in CMTYPx bits.Always reads as 0. Position  */
#define AES_MR_Msk                            _UINT32_(0x00F7FFFB)                                 /* (AES_MR) Register Mask  */


/* -------- AES_IER : (AES Offset: 0x10) ( /W 32) Interrupt Enable Register -------- */
#define AES_IER_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_IER) Data Ready Interrupt Enable Position */
#define AES_IER_DATRDY_Msk                    (_UINT32_(0x1) << AES_IER_DATRDY_Pos)                /* (AES_IER) Data Ready Interrupt Enable Mask */
#define AES_IER_DATRDY(value)                 (AES_IER_DATRDY_Msk & (_UINT32_(value) << AES_IER_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_IER register */
#define AES_IER_URAD_Pos                      _UINT32_(8)                                          /* (AES_IER) Unspecified Register Access Detection Interrupt Enable Position */
#define AES_IER_URAD_Msk                      (_UINT32_(0x1) << AES_IER_URAD_Pos)                  /* (AES_IER) Unspecified Register Access Detection Interrupt Enable Mask */
#define AES_IER_URAD(value)                   (AES_IER_URAD_Msk & (_UINT32_(value) << AES_IER_URAD_Pos)) /* Assigment of value for URAD in the AES_IER register */
#define AES_IER_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_IER) GCM Tag Ready Interrupt Enable Position */
#define AES_IER_TAGRDY_Msk                    (_UINT32_(0x1) << AES_IER_TAGRDY_Pos)                /* (AES_IER) GCM Tag Ready Interrupt Enable Mask */
#define AES_IER_TAGRDY(value)                 (AES_IER_TAGRDY_Msk & (_UINT32_(value) << AES_IER_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_IER register */
#define AES_IER_Msk                           _UINT32_(0x00010101)                                 /* (AES_IER) Register Mask  */


/* -------- AES_IDR : (AES Offset: 0x14) ( /W 32) Interrupt Disable Register -------- */
#define AES_IDR_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_IDR) Data Ready Interrupt Disable Position */
#define AES_IDR_DATRDY_Msk                    (_UINT32_(0x1) << AES_IDR_DATRDY_Pos)                /* (AES_IDR) Data Ready Interrupt Disable Mask */
#define AES_IDR_DATRDY(value)                 (AES_IDR_DATRDY_Msk & (_UINT32_(value) << AES_IDR_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_IDR register */
#define AES_IDR_URAD_Pos                      _UINT32_(8)                                          /* (AES_IDR) Unspecified Register Access Detection Interrupt Disable Position */
#define AES_IDR_URAD_Msk                      (_UINT32_(0x1) << AES_IDR_URAD_Pos)                  /* (AES_IDR) Unspecified Register Access Detection Interrupt Disable Mask */
#define AES_IDR_URAD(value)                   (AES_IDR_URAD_Msk & (_UINT32_(value) << AES_IDR_URAD_Pos)) /* Assigment of value for URAD in the AES_IDR register */
#define AES_IDR_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_IDR) GCM Tag Ready Interrupt Disable Position */
#define AES_IDR_TAGRDY_Msk                    (_UINT32_(0x1) << AES_IDR_TAGRDY_Pos)                /* (AES_IDR) GCM Tag Ready Interrupt Disable Mask */
#define AES_IDR_TAGRDY(value)                 (AES_IDR_TAGRDY_Msk & (_UINT32_(value) << AES_IDR_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_IDR register */
#define AES_IDR_Msk                           _UINT32_(0x00010101)                                 /* (AES_IDR) Register Mask  */


/* -------- AES_IMR : (AES Offset: 0x18) ( R/ 32) Interrupt Mask Register -------- */
#define AES_IMR_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_IMR) Data Ready Interrupt Mask Position */
#define AES_IMR_DATRDY_Msk                    (_UINT32_(0x1) << AES_IMR_DATRDY_Pos)                /* (AES_IMR) Data Ready Interrupt Mask Mask */
#define AES_IMR_DATRDY(value)                 (AES_IMR_DATRDY_Msk & (_UINT32_(value) << AES_IMR_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_IMR register */
#define AES_IMR_URAD_Pos                      _UINT32_(8)                                          /* (AES_IMR) Unspecified Register Access Detection Interrupt Mask Position */
#define AES_IMR_URAD_Msk                      (_UINT32_(0x1) << AES_IMR_URAD_Pos)                  /* (AES_IMR) Unspecified Register Access Detection Interrupt Mask Mask */
#define AES_IMR_URAD(value)                   (AES_IMR_URAD_Msk & (_UINT32_(value) << AES_IMR_URAD_Pos)) /* Assigment of value for URAD in the AES_IMR register */
#define AES_IMR_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_IMR) GCM Tag Ready Interrupt Mask Position */
#define AES_IMR_TAGRDY_Msk                    (_UINT32_(0x1) << AES_IMR_TAGRDY_Pos)                /* (AES_IMR) GCM Tag Ready Interrupt Mask Mask */
#define AES_IMR_TAGRDY(value)                 (AES_IMR_TAGRDY_Msk & (_UINT32_(value) << AES_IMR_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_IMR register */
#define AES_IMR_Msk                           _UINT32_(0x00010101)                                 /* (AES_IMR) Register Mask  */


/* -------- AES_ISR : (AES Offset: 0x1C) ( R/ 32) Interrupt Status Register -------- */
#define AES_ISR_DATRDY_Pos                    _UINT32_(0)                                          /* (AES_ISR) Data Ready (cleared by setting bit START or bit SWRST in AES_CR or by reading AES_ODATARx) Position */
#define AES_ISR_DATRDY_Msk                    (_UINT32_(0x1) << AES_ISR_DATRDY_Pos)                /* (AES_ISR) Data Ready (cleared by setting bit START or bit SWRST in AES_CR or by reading AES_ODATARx) Mask */
#define AES_ISR_DATRDY(value)                 (AES_ISR_DATRDY_Msk & (_UINT32_(value) << AES_ISR_DATRDY_Pos)) /* Assigment of value for DATRDY in the AES_ISR register */
#define AES_ISR_URAD_Pos                      _UINT32_(8)                                          /* (AES_ISR) Unspecified Register Access Detection Status (cleared by writing SWRST in AES_CR) Position */
#define AES_ISR_URAD_Msk                      (_UINT32_(0x1) << AES_ISR_URAD_Pos)                  /* (AES_ISR) Unspecified Register Access Detection Status (cleared by writing SWRST in AES_CR) Mask */
#define AES_ISR_URAD(value)                   (AES_ISR_URAD_Msk & (_UINT32_(value) << AES_ISR_URAD_Pos)) /* Assigment of value for URAD in the AES_ISR register */
#define AES_ISR_URAT_Pos                      _UINT32_(12)                                         /* (AES_ISR) Unspecified Register Access (cleared by writing SWRST in AES_CR) Position */
#define AES_ISR_URAT_Msk                      (_UINT32_(0xF) << AES_ISR_URAT_Pos)                  /* (AES_ISR) Unspecified Register Access (cleared by writing SWRST in AES_CR) Mask */
#define AES_ISR_URAT(value)                   (AES_ISR_URAT_Msk & (_UINT32_(value) << AES_ISR_URAT_Pos)) /* Assigment of value for URAT in the AES_ISR register */
#define   AES_ISR_URAT_IDR_WR_PROCESSING_Val  _UINT32_(0x0)                                        /* (AES_ISR) Input Data Register written during the data processing when SMOD = 0x2 mode.  */
#define   AES_ISR_URAT_ODR_RD_PROCESSING_Val  _UINT32_(0x1)                                        /* (AES_ISR) Output Data Register read during the data processing.  */
#define   AES_ISR_URAT_MR_WR_PROCESSING_Val   _UINT32_(0x2)                                        /* (AES_ISR) Mode Register written during the data processing.  */
#define   AES_ISR_URAT_ODR_RD_SUBKGEN_Val     _UINT32_(0x3)                                        /* (AES_ISR) Output Data Register read during the sub-keys generation.  */
#define   AES_ISR_URAT_MR_WR_SUBKGEN_Val      _UINT32_(0x4)                                        /* (AES_ISR) Mode Register written during the sub-keys generation.  */
#define   AES_ISR_URAT_WOR_RD_ACCESS_Val      _UINT32_(0x5)                                        /* (AES_ISR) Write-only register read access.  */
#define AES_ISR_URAT_IDR_WR_PROCESSING        (AES_ISR_URAT_IDR_WR_PROCESSING_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Input Data Register written during the data processing when SMOD = 0x2 mode. Position  */
#define AES_ISR_URAT_ODR_RD_PROCESSING        (AES_ISR_URAT_ODR_RD_PROCESSING_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Output Data Register read during the data processing. Position  */
#define AES_ISR_URAT_MR_WR_PROCESSING         (AES_ISR_URAT_MR_WR_PROCESSING_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Mode Register written during the data processing. Position  */
#define AES_ISR_URAT_ODR_RD_SUBKGEN           (AES_ISR_URAT_ODR_RD_SUBKGEN_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Output Data Register read during the sub-keys generation. Position  */
#define AES_ISR_URAT_MR_WR_SUBKGEN            (AES_ISR_URAT_MR_WR_SUBKGEN_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Mode Register written during the sub-keys generation. Position  */
#define AES_ISR_URAT_WOR_RD_ACCESS            (AES_ISR_URAT_WOR_RD_ACCESS_Val << AES_ISR_URAT_Pos) /* (AES_ISR) Write-only register read access. Position  */
#define AES_ISR_TAGRDY_Pos                    _UINT32_(16)                                         /* (AES_ISR) GCM Tag Ready Position */
#define AES_ISR_TAGRDY_Msk                    (_UINT32_(0x1) << AES_ISR_TAGRDY_Pos)                /* (AES_ISR) GCM Tag Ready Mask */
#define AES_ISR_TAGRDY(value)                 (AES_ISR_TAGRDY_Msk & (_UINT32_(value) << AES_ISR_TAGRDY_Pos)) /* Assigment of value for TAGRDY in the AES_ISR register */
#define AES_ISR_Msk                           _UINT32_(0x0001F101)                                 /* (AES_ISR) Register Mask  */


/* -------- AES_KEYWR : (AES Offset: 0x20) ( /W 32) Key Word Register -------- */
#define AES_KEYWR_KEYW_Pos                    _UINT32_(0)                                          /* (AES_KEYWR) Key Word Position */
#define AES_KEYWR_KEYW_Msk                    (_UINT32_(0xFFFFFFFF) << AES_KEYWR_KEYW_Pos)         /* (AES_KEYWR) Key Word Mask */
#define AES_KEYWR_KEYW(value)                 (AES_KEYWR_KEYW_Msk & (_UINT32_(value) << AES_KEYWR_KEYW_Pos)) /* Assigment of value for KEYW in the AES_KEYWR register */
#define AES_KEYWR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (AES_KEYWR) Register Mask  */


/* -------- AES_IDATAR : (AES Offset: 0x40) ( /W 32) Input Data Register -------- */
#define AES_IDATAR_IDATA_Pos                  _UINT32_(0)                                          /* (AES_IDATAR) Input Data Word Position */
#define AES_IDATAR_IDATA_Msk                  (_UINT32_(0xFFFFFFFF) << AES_IDATAR_IDATA_Pos)       /* (AES_IDATAR) Input Data Word Mask */
#define AES_IDATAR_IDATA(value)               (AES_IDATAR_IDATA_Msk & (_UINT32_(value) << AES_IDATAR_IDATA_Pos)) /* Assigment of value for IDATA in the AES_IDATAR register */
#define AES_IDATAR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (AES_IDATAR) Register Mask  */


/* -------- AES_ODATAR : (AES Offset: 0x50) ( R/ 32) Output Data Register -------- */
#define AES_ODATAR_ODATA_Pos                  _UINT32_(0)                                          /* (AES_ODATAR) Output Data Position */
#define AES_ODATAR_ODATA_Msk                  (_UINT32_(0xFFFFFFFF) << AES_ODATAR_ODATA_Pos)       /* (AES_ODATAR) Output Data Mask */
#define AES_ODATAR_ODATA(value)               (AES_ODATAR_ODATA_Msk & (_UINT32_(value) << AES_ODATAR_ODATA_Pos)) /* Assigment of value for ODATA in the AES_ODATAR register */
#define AES_ODATAR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (AES_ODATAR) Register Mask  */


/* -------- AES_IVR : (AES Offset: 0x60) ( /W 32) Initialization Vector Register -------- */
#define AES_IVR_IV_Pos                        _UINT32_(0)                                          /* (AES_IVR) Initialization Vector Position */
#define AES_IVR_IV_Msk                        (_UINT32_(0xFFFFFFFF) << AES_IVR_IV_Pos)             /* (AES_IVR) Initialization Vector Mask */
#define AES_IVR_IV(value)                     (AES_IVR_IV_Msk & (_UINT32_(value) << AES_IVR_IV_Pos)) /* Assigment of value for IV in the AES_IVR register */
#define AES_IVR_Msk                           _UINT32_(0xFFFFFFFF)                                 /* (AES_IVR) Register Mask  */


/* -------- AES_AADLENR : (AES Offset: 0x70) (R/W 32) Additional Authenticated Data Length Register -------- */
#define AES_AADLENR_AADLEN_Pos                _UINT32_(0)                                          /* (AES_AADLENR) Additional Authenticated Data Length Position */
#define AES_AADLENR_AADLEN_Msk                (_UINT32_(0xFFFFFFFF) << AES_AADLENR_AADLEN_Pos)     /* (AES_AADLENR) Additional Authenticated Data Length Mask */
#define AES_AADLENR_AADLEN(value)             (AES_AADLENR_AADLEN_Msk & (_UINT32_(value) << AES_AADLENR_AADLEN_Pos)) /* Assigment of value for AADLEN in the AES_AADLENR register */
#define AES_AADLENR_Msk                       _UINT32_(0xFFFFFFFF)                                 /* (AES_AADLENR) Register Mask  */


/* -------- AES_CLENR : (AES Offset: 0x74) (R/W 32) Plaintext/Ciphertext Length Register -------- */
#define AES_CLENR_CLEN_Pos                    _UINT32_(0)                                          /* (AES_CLENR) Plaintext/Ciphertext Length Position */
#define AES_CLENR_CLEN_Msk                    (_UINT32_(0xFFFFFFFF) << AES_CLENR_CLEN_Pos)         /* (AES_CLENR) Plaintext/Ciphertext Length Mask */
#define AES_CLENR_CLEN(value)                 (AES_CLENR_CLEN_Msk & (_UINT32_(value) << AES_CLENR_CLEN_Pos)) /* Assigment of value for CLEN in the AES_CLENR register */
#define AES_CLENR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (AES_CLENR) Register Mask  */


/* -------- AES_GHASHR : (AES Offset: 0x78) (R/W 32) GCM Intermediate Hash Word Register -------- */
#define AES_GHASHR_GHASH_Pos                  _UINT32_(0)                                          /* (AES_GHASHR) Intermediate GCM Hash Word x Position */
#define AES_GHASHR_GHASH_Msk                  (_UINT32_(0xFFFFFFFF) << AES_GHASHR_GHASH_Pos)       /* (AES_GHASHR) Intermediate GCM Hash Word x Mask */
#define AES_GHASHR_GHASH(value)               (AES_GHASHR_GHASH_Msk & (_UINT32_(value) << AES_GHASHR_GHASH_Pos)) /* Assigment of value for GHASH in the AES_GHASHR register */
#define AES_GHASHR_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (AES_GHASHR) Register Mask  */


/* -------- AES_TAGR : (AES Offset: 0x88) ( R/ 32) GCM Authentication Tag Word Register -------- */
#define AES_TAGR_TAG_Pos                      _UINT32_(0)                                          /* (AES_TAGR) GCM Authentication Tag x Position */
#define AES_TAGR_TAG_Msk                      (_UINT32_(0xFFFFFFFF) << AES_TAGR_TAG_Pos)           /* (AES_TAGR) GCM Authentication Tag x Mask */
#define AES_TAGR_TAG(value)                   (AES_TAGR_TAG_Msk & (_UINT32_(value) << AES_TAGR_TAG_Pos)) /* Assigment of value for TAG in the AES_TAGR register */
#define AES_TAGR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (AES_TAGR) Register Mask  */


/* -------- AES_CTRR : (AES Offset: 0x98) ( R/ 32) GCM Encryption Counter Value Register -------- */
#define AES_CTRR_CTR_Pos                      _UINT32_(0)                                          /* (AES_CTRR) GCM Encryption Counter Position */
#define AES_CTRR_CTR_Msk                      (_UINT32_(0xFFFFFFFF) << AES_CTRR_CTR_Pos)           /* (AES_CTRR) GCM Encryption Counter Mask */
#define AES_CTRR_CTR(value)                   (AES_CTRR_CTR_Msk & (_UINT32_(value) << AES_CTRR_CTR_Pos)) /* Assigment of value for CTR in the AES_CTRR register */
#define AES_CTRR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (AES_CTRR) Register Mask  */


/* -------- AES_GCMHR : (AES Offset: 0x9C) (R/W 32) GCM H Word Register -------- */
#define AES_GCMHR_H_Pos                       _UINT32_(0)                                          /* (AES_GCMHR) GCM H Word x Position */
#define AES_GCMHR_H_Msk                       (_UINT32_(0xFFFFFFFF) << AES_GCMHR_H_Pos)            /* (AES_GCMHR) GCM H Word x Mask */
#define AES_GCMHR_H(value)                    (AES_GCMHR_H_Msk & (_UINT32_(value) << AES_GCMHR_H_Pos)) /* Assigment of value for H in the AES_GCMHR register */
#define AES_GCMHR_Msk                         _UINT32_(0xFFFFFFFF)                                 /* (AES_GCMHR) Register Mask  */


/** \brief AES register offsets definitions */
#define AES_CR_REG_OFST                _UINT32_(0x00)      /* (AES_CR) Control Register Offset */
#define AES_MR_REG_OFST                _UINT32_(0x04)      /* (AES_MR) Mode Register Offset */
#define AES_IER_REG_OFST               _UINT32_(0x10)      /* (AES_IER) Interrupt Enable Register Offset */
#define AES_IDR_REG_OFST               _UINT32_(0x14)      /* (AES_IDR) Interrupt Disable Register Offset */
#define AES_IMR_REG_OFST               _UINT32_(0x18)      /* (AES_IMR) Interrupt Mask Register Offset */
#define AES_ISR_REG_OFST               _UINT32_(0x1C)      /* (AES_ISR) Interrupt Status Register Offset */
#define AES_KEYWR_REG_OFST             _UINT32_(0x20)      /* (AES_KEYWR) Key Word Register Offset */
#define AES_KEYWR0_REG_OFST            _UINT32_(0x20)      /* (AES_KEYWR0) Key Word Register Offset */
#define AES_KEYWR1_REG_OFST            _UINT32_(0x24)      /* (AES_KEYWR1) Key Word Register Offset */
#define AES_KEYWR2_REG_OFST            _UINT32_(0x28)      /* (AES_KEYWR2) Key Word Register Offset */
#define AES_KEYWR3_REG_OFST            _UINT32_(0x2C)      /* (AES_KEYWR3) Key Word Register Offset */
#define AES_KEYWR4_REG_OFST            _UINT32_(0x30)      /* (AES_KEYWR4) Key Word Register Offset */
#define AES_KEYWR5_REG_OFST            _UINT32_(0x34)      /* (AES_KEYWR5) Key Word Register Offset */
#define AES_KEYWR6_REG_OFST            _UINT32_(0x38)      /* (AES_KEYWR6) Key Word Register Offset */
#define AES_KEYWR7_REG_OFST            _UINT32_(0x3C)      /* (AES_KEYWR7) Key Word Register Offset */
#define AES_IDATAR_REG_OFST            _UINT32_(0x40)      /* (AES_IDATAR) Input Data Register Offset */
#define AES_IDATAR0_REG_OFST           _UINT32_(0x40)      /* (AES_IDATAR0) Input Data Register Offset */
#define AES_IDATAR1_REG_OFST           _UINT32_(0x44)      /* (AES_IDATAR1) Input Data Register Offset */
#define AES_IDATAR2_REG_OFST           _UINT32_(0x48)      /* (AES_IDATAR2) Input Data Register Offset */
#define AES_IDATAR3_REG_OFST           _UINT32_(0x4C)      /* (AES_IDATAR3) Input Data Register Offset */
#define AES_ODATAR_REG_OFST            _UINT32_(0x50)      /* (AES_ODATAR) Output Data Register Offset */
#define AES_ODATAR0_REG_OFST           _UINT32_(0x50)      /* (AES_ODATAR0) Output Data Register Offset */
#define AES_ODATAR1_REG_OFST           _UINT32_(0x54)      /* (AES_ODATAR1) Output Data Register Offset */
#define AES_ODATAR2_REG_OFST           _UINT32_(0x58)      /* (AES_ODATAR2) Output Data Register Offset */
#define AES_ODATAR3_REG_OFST           _UINT32_(0x5C)      /* (AES_ODATAR3) Output Data Register Offset */
#define AES_IVR_REG_OFST               _UINT32_(0x60)      /* (AES_IVR) Initialization Vector Register Offset */
#define AES_IVR0_REG_OFST              _UINT32_(0x60)      /* (AES_IVR0) Initialization Vector Register Offset */
#define AES_IVR1_REG_OFST              _UINT32_(0x64)      /* (AES_IVR1) Initialization Vector Register Offset */
#define AES_IVR2_REG_OFST              _UINT32_(0x68)      /* (AES_IVR2) Initialization Vector Register Offset */
#define AES_IVR3_REG_OFST              _UINT32_(0x6C)      /* (AES_IVR3) Initialization Vector Register Offset */
#define AES_AADLENR_REG_OFST           _UINT32_(0x70)      /* (AES_AADLENR) Additional Authenticated Data Length Register Offset */
#define AES_CLENR_REG_OFST             _UINT32_(0x74)      /* (AES_CLENR) Plaintext/Ciphertext Length Register Offset */
#define AES_GHASHR_REG_OFST            _UINT32_(0x78)      /* (AES_GHASHR) GCM Intermediate Hash Word Register Offset */
#define AES_GHASHR0_REG_OFST           _UINT32_(0x78)      /* (AES_GHASHR0) GCM Intermediate Hash Word Register Offset */
#define AES_GHASHR1_REG_OFST           _UINT32_(0x7C)      /* (AES_GHASHR1) GCM Intermediate Hash Word Register Offset */
#define AES_GHASHR2_REG_OFST           _UINT32_(0x80)      /* (AES_GHASHR2) GCM Intermediate Hash Word Register Offset */
#define AES_GHASHR3_REG_OFST           _UINT32_(0x84)      /* (AES_GHASHR3) GCM Intermediate Hash Word Register Offset */
#define AES_TAGR_REG_OFST              _UINT32_(0x88)      /* (AES_TAGR) GCM Authentication Tag Word Register Offset */
#define AES_TAGR0_REG_OFST             _UINT32_(0x88)      /* (AES_TAGR0) GCM Authentication Tag Word Register Offset */
#define AES_TAGR1_REG_OFST             _UINT32_(0x8C)      /* (AES_TAGR1) GCM Authentication Tag Word Register Offset */
#define AES_TAGR2_REG_OFST             _UINT32_(0x90)      /* (AES_TAGR2) GCM Authentication Tag Word Register Offset */
#define AES_TAGR3_REG_OFST             _UINT32_(0x94)      /* (AES_TAGR3) GCM Authentication Tag Word Register Offset */
#define AES_CTRR_REG_OFST              _UINT32_(0x98)      /* (AES_CTRR) GCM Encryption Counter Value Register Offset */
#define AES_GCMHR_REG_OFST             _UINT32_(0x9C)      /* (AES_GCMHR) GCM H Word Register Offset */
#define AES_GCMHR0_REG_OFST            _UINT32_(0x9C)      /* (AES_GCMHR0) GCM H Word Register Offset */
#define AES_GCMHR1_REG_OFST            _UINT32_(0xA0)      /* (AES_GCMHR1) GCM H Word Register Offset */
#define AES_GCMHR2_REG_OFST            _UINT32_(0xA4)      /* (AES_GCMHR2) GCM H Word Register Offset */
#define AES_GCMHR3_REG_OFST            _UINT32_(0xA8)      /* (AES_GCMHR3) GCM H Word Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief AES register API structure */
typedef struct
{
  __O   uint32_t                       AES_CR;             /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       AES_MR;             /**< Offset: 0x04 (R/W  32) Mode Register */
  __I   uint8_t                        Reserved1[0x08];
  __O   uint32_t                       AES_IER;            /**< Offset: 0x10 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       AES_IDR;            /**< Offset: 0x14 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       AES_IMR;            /**< Offset: 0x18 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       AES_ISR;            /**< Offset: 0x1C (R/   32) Interrupt Status Register */
  __O   uint32_t                       AES_KEYWR[8];       /**< Offset: 0x20 ( /W  32) Key Word Register */
  __O   uint32_t                       AES_IDATAR[4];      /**< Offset: 0x40 ( /W  32) Input Data Register */
  __I   uint32_t                       AES_ODATAR[4];      /**< Offset: 0x50 (R/   32) Output Data Register */
  __O   uint32_t                       AES_IVR[4];         /**< Offset: 0x60 ( /W  32) Initialization Vector Register */
  __IO  uint32_t                       AES_AADLENR;        /**< Offset: 0x70 (R/W  32) Additional Authenticated Data Length Register */
  __IO  uint32_t                       AES_CLENR;          /**< Offset: 0x74 (R/W  32) Plaintext/Ciphertext Length Register */
  __IO  uint32_t                       AES_GHASHR[4];      /**< Offset: 0x78 (R/W  32) GCM Intermediate Hash Word Register */
  __I   uint32_t                       AES_TAGR[4];        /**< Offset: 0x88 (R/   32) GCM Authentication Tag Word Register */
  __I   uint32_t                       AES_CTRR;           /**< Offset: 0x98 (R/   32) GCM Encryption Counter Value Register */
  __IO  uint32_t                       AES_GCMHR[4];       /**< Offset: 0x9C (R/W  32) GCM H Word Register */
} aes_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAME70_AES_COMPONENT_H_ */
