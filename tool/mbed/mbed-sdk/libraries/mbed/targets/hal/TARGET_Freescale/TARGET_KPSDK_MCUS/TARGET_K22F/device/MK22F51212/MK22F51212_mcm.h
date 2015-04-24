/*
** ###################################################################
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    K22P121M120SF7RM, Rev. 1, March 24, 2014
**     Version:             rev. 2.5, 2014-05-06
**     Build:               b140604
**
**     Abstract:
**         Extension to the CMSIS register access layer header.
**
**     Copyright (c) 2014 Freescale Semiconductor, Inc.
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2013-07-23)
**         Initial version.
**     - rev. 1.1 (2013-09-17)
**         RM rev. 0.4 update.
**     - rev. 2.0 (2013-10-29)
**         Register accessor macros added to the memory map.
**         Symbols for Processor Expert memory map compatibility added to the memory map.
**         Startup file for gcc has been updated according to CMSIS 3.2.
**         System initialization updated.
**     - rev. 2.1 (2013-10-30)
**         Definition of BITBAND macros updated to support peripherals with 32-bit acces disabled.
**     - rev. 2.2 (2013-12-20)
**         Update according to reference manual rev. 0.6,
**     - rev. 2.3 (2014-01-13)
**         Update according to reference manual rev. 0.61,
**     - rev. 2.4 (2014-02-10)
**         The declaration of clock configurations has been moved to separate header file system_MK22F51212.h
**     - rev. 2.5 (2014-05-06)
**         Update according to reference manual rev. 1.0,
**         Update of system and startup files.
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**
** ###################################################################
*/

/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_MCM_REGISTERS_H__
#define __HW_MCM_REGISTERS_H__

#include "MK22F51212.h"
#include "fsl_bitaccess.h"

/*
 * MK22F51212 MCM
 *
 * Core Platform Miscellaneous Control Module
 *
 * Registers defined in this header file:
 * - HW_MCM_PLASC - Crossbar Switch (AXBS) Slave Configuration
 * - HW_MCM_PLAMC - Crossbar Switch (AXBS) Master Configuration
 * - HW_MCM_PLACR - Crossbar Switch (AXBS) Control Register
 * - HW_MCM_ISCR - Interrupt Status and Control Register
 * - HW_MCM_CPO - Compute Operation Control Register
 *
 * - hw_mcm_t - Struct containing all module registers.
 */

#define HW_MCM_INSTANCE_COUNT (1U) /*!< Number of instances of the MCM module. */

/*******************************************************************************
 * HW_MCM_PLASC - Crossbar Switch (AXBS) Slave Configuration
 ******************************************************************************/

/*!
 * @brief HW_MCM_PLASC - Crossbar Switch (AXBS) Slave Configuration (RO)
 *
 * Reset value: 0x001FU
 *
 * PLASC is a 16-bit read-only register identifying the presence/absence of bus
 * slave connections to the device's crossbar switch.
 */
typedef union _hw_mcm_plasc
{
    uint16_t U;
    struct _hw_mcm_plasc_bitfields
    {
        uint16_t ASC : 8;              /*!< [7:0] Each bit in the ASC field indicates
                                        * whether there is a corresponding connection to the crossbar switch's slave
                                        * input port. */
        uint16_t RESERVED0 : 8;        /*!< [15:8]  */
    } B;
} hw_mcm_plasc_t;

/*!
 * @name Constants and macros for entire MCM_PLASC register
 */
/*@{*/
#define HW_MCM_PLASC_ADDR(x)     ((x) + 0x8U)

#define HW_MCM_PLASC(x)          (*(__I hw_mcm_plasc_t *) HW_MCM_PLASC_ADDR(x))
#define HW_MCM_PLASC_RD(x)       (HW_MCM_PLASC(x).U)
/*@}*/

/*
 * Constants & macros for individual MCM_PLASC bitfields
 */

/*!
 * @name Register MCM_PLASC, field ASC[7:0] (RO)
 *
 * Values:
 * - 0 - A bus slave connection to AXBS input port n is absent
 * - 1 - A bus slave connection to AXBS input port n is present
 */
/*@{*/
#define BP_MCM_PLASC_ASC     (0U)          /*!< Bit position for MCM_PLASC_ASC. */
#define BM_MCM_PLASC_ASC     (0x00FFU)     /*!< Bit mask for MCM_PLASC_ASC. */
#define BS_MCM_PLASC_ASC     (8U)          /*!< Bit field size in bits for MCM_PLASC_ASC. */

/*! @brief Read current value of the MCM_PLASC_ASC field. */
#define BR_MCM_PLASC_ASC(x)  (HW_MCM_PLASC(x).B.ASC)
/*@}*/

/*******************************************************************************
 * HW_MCM_PLAMC - Crossbar Switch (AXBS) Master Configuration
 ******************************************************************************/

/*!
 * @brief HW_MCM_PLAMC - Crossbar Switch (AXBS) Master Configuration (RO)
 *
 * Reset value: 0x0017U
 *
 * PLAMC is a 16-bit read-only register identifying the presence/absence of bus
 * master connections to the device's crossbar switch.
 */
typedef union _hw_mcm_plamc
{
    uint16_t U;
    struct _hw_mcm_plamc_bitfields
    {
        uint16_t AMC : 8;              /*!< [7:0] Each bit in the AMC field indicates
                                        * whether there is a corresponding connection to the AXBS master input port. */
        uint16_t RESERVED0 : 8;        /*!< [15:8]  */
    } B;
} hw_mcm_plamc_t;

/*!
 * @name Constants and macros for entire MCM_PLAMC register
 */
/*@{*/
#define HW_MCM_PLAMC_ADDR(x)     ((x) + 0xAU)

#define HW_MCM_PLAMC(x)          (*(__I hw_mcm_plamc_t *) HW_MCM_PLAMC_ADDR(x))
#define HW_MCM_PLAMC_RD(x)       (HW_MCM_PLAMC(x).U)
/*@}*/

/*
 * Constants & macros for individual MCM_PLAMC bitfields
 */

/*!
 * @name Register MCM_PLAMC, field AMC[7:0] (RO)
 *
 * Values:
 * - 0 - A bus master connection to AXBS input port n is absent
 * - 1 - A bus master connection to AXBS input port n is present
 */
/*@{*/
#define BP_MCM_PLAMC_AMC     (0U)          /*!< Bit position for MCM_PLAMC_AMC. */
#define BM_MCM_PLAMC_AMC     (0x00FFU)     /*!< Bit mask for MCM_PLAMC_AMC. */
#define BS_MCM_PLAMC_AMC     (8U)          /*!< Bit field size in bits for MCM_PLAMC_AMC. */

/*! @brief Read current value of the MCM_PLAMC_AMC field. */
#define BR_MCM_PLAMC_AMC(x)  (HW_MCM_PLAMC(x).B.AMC)
/*@}*/

/*******************************************************************************
 * HW_MCM_PLACR - Crossbar Switch (AXBS) Control Register
 ******************************************************************************/

/*!
 * @brief HW_MCM_PLACR - Crossbar Switch (AXBS) Control Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * The PLACR register selects the arbitration policy for the crossbar masters.
 */
typedef union _hw_mcm_placr
{
    uint32_t U;
    struct _hw_mcm_placr_bitfields
    {
        uint32_t RESERVED0 : 9;        /*!< [8:0]  */
        uint32_t ARB : 1;              /*!< [9] Arbitration select */
        uint32_t RESERVED1 : 22;       /*!< [31:10]  */
    } B;
} hw_mcm_placr_t;

/*!
 * @name Constants and macros for entire MCM_PLACR register
 */
/*@{*/
#define HW_MCM_PLACR_ADDR(x)     ((x) + 0xCU)

#define HW_MCM_PLACR(x)          (*(__IO hw_mcm_placr_t *) HW_MCM_PLACR_ADDR(x))
#define HW_MCM_PLACR_RD(x)       (HW_MCM_PLACR(x).U)
#define HW_MCM_PLACR_WR(x, v)    (HW_MCM_PLACR(x).U = (v))
#define HW_MCM_PLACR_SET(x, v)   (HW_MCM_PLACR_WR(x, HW_MCM_PLACR_RD(x) |  (v)))
#define HW_MCM_PLACR_CLR(x, v)   (HW_MCM_PLACR_WR(x, HW_MCM_PLACR_RD(x) & ~(v)))
#define HW_MCM_PLACR_TOG(x, v)   (HW_MCM_PLACR_WR(x, HW_MCM_PLACR_RD(x) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual MCM_PLACR bitfields
 */

/*!
 * @name Register MCM_PLACR, field ARB[9] (RW)
 *
 * Values:
 * - 0 - Fixed-priority arbitration for the crossbar masters
 * - 1 - Round-robin arbitration for the crossbar masters
 */
/*@{*/
#define BP_MCM_PLACR_ARB     (9U)          /*!< Bit position for MCM_PLACR_ARB. */
#define BM_MCM_PLACR_ARB     (0x00000200U) /*!< Bit mask for MCM_PLACR_ARB. */
#define BS_MCM_PLACR_ARB     (1U)          /*!< Bit field size in bits for MCM_PLACR_ARB. */

/*! @brief Read current value of the MCM_PLACR_ARB field. */
#define BR_MCM_PLACR_ARB(x)  (HW_MCM_PLACR(x).B.ARB)

/*! @brief Format value for bitfield MCM_PLACR_ARB. */
#define BF_MCM_PLACR_ARB(v)  ((uint32_t)((uint32_t)(v) << BP_MCM_PLACR_ARB) & BM_MCM_PLACR_ARB)

/*! @brief Set the ARB field to a new value. */
#define BW_MCM_PLACR_ARB(x, v) (HW_MCM_PLACR_WR(x, (HW_MCM_PLACR_RD(x) & ~BM_MCM_PLACR_ARB) | BF_MCM_PLACR_ARB(v)))
/*@}*/

/*******************************************************************************
 * HW_MCM_ISCR - Interrupt Status and Control Register
 ******************************************************************************/

/*!
 * @brief HW_MCM_ISCR - Interrupt Status and Control Register (RW)
 *
 * Reset value: 0x00020000U
 *
 * The MCM_ISCR register includes the enable and status bits associated with the
 * core's floating-point exceptions. The individual event indicators are first
 * qualified with their exception enables and then logically summed to form an
 * interrupt request sent to the core's NVIC. Bits 15-8 are read-only indicator
 * flags based on the processor's FPSCR register. Attempted writes to these bits are
 * ignored. Once set, the flags remain asserted until software clears the
 * corresponding FPSCR bit.
 */
typedef union _hw_mcm_iscr
{
    uint32_t U;
    struct _hw_mcm_iscr_bitfields
    {
        uint32_t RESERVED0 : 8;        /*!< [7:0]  */
        uint32_t FIOC : 1;             /*!< [8] FPU invalid operation interrupt status */
        uint32_t FDZC : 1;             /*!< [9] FPU divide-by-zero interrupt status */
        uint32_t FOFC : 1;             /*!< [10] FPU overflow interrupt status */
        uint32_t FUFC : 1;             /*!< [11] FPU underflow interrupt status */
        uint32_t FIXC : 1;             /*!< [12] FPU inexact interrupt status */
        uint32_t RESERVED1 : 2;        /*!< [14:13]  */
        uint32_t FIDC : 1;             /*!< [15] FPU input denormal interrupt status */
        uint32_t RESERVED2 : 8;        /*!< [23:16]  */
        uint32_t FIOCE : 1;            /*!< [24] FPU invalid operation interrupt enable
                                        * */
        uint32_t FDZCE : 1;            /*!< [25] FPU divide-by-zero interrupt enable */
        uint32_t FOFCE : 1;            /*!< [26] FPU overflow interrupt enable */
        uint32_t FUFCE : 1;            /*!< [27] FPU underflow interrupt enable */
        uint32_t FIXCE : 1;            /*!< [28] FPU inexact interrupt enable */
        uint32_t RESERVED3 : 2;        /*!< [30:29]  */
        uint32_t FIDCE : 1;            /*!< [31] FPU input denormal interrupt enable */
    } B;
} hw_mcm_iscr_t;

/*!
 * @name Constants and macros for entire MCM_ISCR register
 */
/*@{*/
#define HW_MCM_ISCR_ADDR(x)      ((x) + 0x10U)

#define HW_MCM_ISCR(x)           (*(__IO hw_mcm_iscr_t *) HW_MCM_ISCR_ADDR(x))
#define HW_MCM_ISCR_RD(x)        (HW_MCM_ISCR(x).U)
#define HW_MCM_ISCR_WR(x, v)     (HW_MCM_ISCR(x).U = (v))
#define HW_MCM_ISCR_SET(x, v)    (HW_MCM_ISCR_WR(x, HW_MCM_ISCR_RD(x) |  (v)))
#define HW_MCM_ISCR_CLR(x, v)    (HW_MCM_ISCR_WR(x, HW_MCM_ISCR_RD(x) & ~(v)))
#define HW_MCM_ISCR_TOG(x, v)    (HW_MCM_ISCR_WR(x, HW_MCM_ISCR_RD(x) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual MCM_ISCR bitfields
 */

/*!
 * @name Register MCM_ISCR, field FIOC[8] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[IOC] bit and signals an
 * illegal operation has been detected in the processor's FPU. Once set, this bit
 * remains set until software clears the FPSCR[IOC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
/*@{*/
#define BP_MCM_ISCR_FIOC     (8U)          /*!< Bit position for MCM_ISCR_FIOC. */
#define BM_MCM_ISCR_FIOC     (0x00000100U) /*!< Bit mask for MCM_ISCR_FIOC. */
#define BS_MCM_ISCR_FIOC     (1U)          /*!< Bit field size in bits for MCM_ISCR_FIOC. */

/*! @brief Read current value of the MCM_ISCR_FIOC field. */
#define BR_MCM_ISCR_FIOC(x)  (HW_MCM_ISCR(x).B.FIOC)
/*@}*/

/*!
 * @name Register MCM_ISCR, field FDZC[9] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[DZC] bit and signals a
 * divide by zero has been detected in the processor's FPU. Once set, this bit remains
 * set until software clears the FPSCR[DZC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
/*@{*/
#define BP_MCM_ISCR_FDZC     (9U)          /*!< Bit position for MCM_ISCR_FDZC. */
#define BM_MCM_ISCR_FDZC     (0x00000200U) /*!< Bit mask for MCM_ISCR_FDZC. */
#define BS_MCM_ISCR_FDZC     (1U)          /*!< Bit field size in bits for MCM_ISCR_FDZC. */

/*! @brief Read current value of the MCM_ISCR_FDZC field. */
#define BR_MCM_ISCR_FDZC(x)  (HW_MCM_ISCR(x).B.FDZC)
/*@}*/

/*!
 * @name Register MCM_ISCR, field FOFC[10] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[OFC] bit and signals an
 * overflow has been detected in the processor's FPU. Once set, this bit remains set
 * until software clears the FPSCR[OFC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
/*@{*/
#define BP_MCM_ISCR_FOFC     (10U)         /*!< Bit position for MCM_ISCR_FOFC. */
#define BM_MCM_ISCR_FOFC     (0x00000400U) /*!< Bit mask for MCM_ISCR_FOFC. */
#define BS_MCM_ISCR_FOFC     (1U)          /*!< Bit field size in bits for MCM_ISCR_FOFC. */

/*! @brief Read current value of the MCM_ISCR_FOFC field. */
#define BR_MCM_ISCR_FOFC(x)  (HW_MCM_ISCR(x).B.FOFC)
/*@}*/

/*!
 * @name Register MCM_ISCR, field FUFC[11] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[UFC] bit and signals an
 * underflow has been detected in the processor's FPU. Once set, this bit remains set
 * until software clears the FPSCR[UFC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
/*@{*/
#define BP_MCM_ISCR_FUFC     (11U)         /*!< Bit position for MCM_ISCR_FUFC. */
#define BM_MCM_ISCR_FUFC     (0x00000800U) /*!< Bit mask for MCM_ISCR_FUFC. */
#define BS_MCM_ISCR_FUFC     (1U)          /*!< Bit field size in bits for MCM_ISCR_FUFC. */

/*! @brief Read current value of the MCM_ISCR_FUFC field. */
#define BR_MCM_ISCR_FUFC(x)  (HW_MCM_ISCR(x).B.FUFC)
/*@}*/

/*!
 * @name Register MCM_ISCR, field FIXC[12] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[IXC] bit and signals an
 * inexact number has been detected in the processor's FPU. Once set, this bit
 * remains set until software clears the FPSCR[IXC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
/*@{*/
#define BP_MCM_ISCR_FIXC     (12U)         /*!< Bit position for MCM_ISCR_FIXC. */
#define BM_MCM_ISCR_FIXC     (0x00001000U) /*!< Bit mask for MCM_ISCR_FIXC. */
#define BS_MCM_ISCR_FIXC     (1U)          /*!< Bit field size in bits for MCM_ISCR_FIXC. */

/*! @brief Read current value of the MCM_ISCR_FIXC field. */
#define BR_MCM_ISCR_FIXC(x)  (HW_MCM_ISCR(x).B.FIXC)
/*@}*/

/*!
 * @name Register MCM_ISCR, field FIDC[15] (RO)
 *
 * This read-only bit is a copy of the core's FPSCR[IDC] bit and signals input
 * denormalized number has been detected in the processor's FPU. Once set, this
 * bit remains set until software clears the FPSCR[IDC] bit.
 *
 * Values:
 * - 0 - No interrupt
 * - 1 - Interrupt occurred
 */
/*@{*/
#define BP_MCM_ISCR_FIDC     (15U)         /*!< Bit position for MCM_ISCR_FIDC. */
#define BM_MCM_ISCR_FIDC     (0x00008000U) /*!< Bit mask for MCM_ISCR_FIDC. */
#define BS_MCM_ISCR_FIDC     (1U)          /*!< Bit field size in bits for MCM_ISCR_FIDC. */

/*! @brief Read current value of the MCM_ISCR_FIDC field. */
#define BR_MCM_ISCR_FIDC(x)  (HW_MCM_ISCR(x).B.FIDC)
/*@}*/

/*!
 * @name Register MCM_ISCR, field FIOCE[24] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
/*@{*/
#define BP_MCM_ISCR_FIOCE    (24U)         /*!< Bit position for MCM_ISCR_FIOCE. */
#define BM_MCM_ISCR_FIOCE    (0x01000000U) /*!< Bit mask for MCM_ISCR_FIOCE. */
#define BS_MCM_ISCR_FIOCE    (1U)          /*!< Bit field size in bits for MCM_ISCR_FIOCE. */

/*! @brief Read current value of the MCM_ISCR_FIOCE field. */
#define BR_MCM_ISCR_FIOCE(x) (HW_MCM_ISCR(x).B.FIOCE)

/*! @brief Format value for bitfield MCM_ISCR_FIOCE. */
#define BF_MCM_ISCR_FIOCE(v) ((uint32_t)((uint32_t)(v) << BP_MCM_ISCR_FIOCE) & BM_MCM_ISCR_FIOCE)

/*! @brief Set the FIOCE field to a new value. */
#define BW_MCM_ISCR_FIOCE(x, v) (HW_MCM_ISCR_WR(x, (HW_MCM_ISCR_RD(x) & ~BM_MCM_ISCR_FIOCE) | BF_MCM_ISCR_FIOCE(v)))
/*@}*/

/*!
 * @name Register MCM_ISCR, field FDZCE[25] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
/*@{*/
#define BP_MCM_ISCR_FDZCE    (25U)         /*!< Bit position for MCM_ISCR_FDZCE. */
#define BM_MCM_ISCR_FDZCE    (0x02000000U) /*!< Bit mask for MCM_ISCR_FDZCE. */
#define BS_MCM_ISCR_FDZCE    (1U)          /*!< Bit field size in bits for MCM_ISCR_FDZCE. */

/*! @brief Read current value of the MCM_ISCR_FDZCE field. */
#define BR_MCM_ISCR_FDZCE(x) (HW_MCM_ISCR(x).B.FDZCE)

/*! @brief Format value for bitfield MCM_ISCR_FDZCE. */
#define BF_MCM_ISCR_FDZCE(v) ((uint32_t)((uint32_t)(v) << BP_MCM_ISCR_FDZCE) & BM_MCM_ISCR_FDZCE)

/*! @brief Set the FDZCE field to a new value. */
#define BW_MCM_ISCR_FDZCE(x, v) (HW_MCM_ISCR_WR(x, (HW_MCM_ISCR_RD(x) & ~BM_MCM_ISCR_FDZCE) | BF_MCM_ISCR_FDZCE(v)))
/*@}*/

/*!
 * @name Register MCM_ISCR, field FOFCE[26] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
/*@{*/
#define BP_MCM_ISCR_FOFCE    (26U)         /*!< Bit position for MCM_ISCR_FOFCE. */
#define BM_MCM_ISCR_FOFCE    (0x04000000U) /*!< Bit mask for MCM_ISCR_FOFCE. */
#define BS_MCM_ISCR_FOFCE    (1U)          /*!< Bit field size in bits for MCM_ISCR_FOFCE. */

/*! @brief Read current value of the MCM_ISCR_FOFCE field. */
#define BR_MCM_ISCR_FOFCE(x) (HW_MCM_ISCR(x).B.FOFCE)

/*! @brief Format value for bitfield MCM_ISCR_FOFCE. */
#define BF_MCM_ISCR_FOFCE(v) ((uint32_t)((uint32_t)(v) << BP_MCM_ISCR_FOFCE) & BM_MCM_ISCR_FOFCE)

/*! @brief Set the FOFCE field to a new value. */
#define BW_MCM_ISCR_FOFCE(x, v) (HW_MCM_ISCR_WR(x, (HW_MCM_ISCR_RD(x) & ~BM_MCM_ISCR_FOFCE) | BF_MCM_ISCR_FOFCE(v)))
/*@}*/

/*!
 * @name Register MCM_ISCR, field FUFCE[27] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
/*@{*/
#define BP_MCM_ISCR_FUFCE    (27U)         /*!< Bit position for MCM_ISCR_FUFCE. */
#define BM_MCM_ISCR_FUFCE    (0x08000000U) /*!< Bit mask for MCM_ISCR_FUFCE. */
#define BS_MCM_ISCR_FUFCE    (1U)          /*!< Bit field size in bits for MCM_ISCR_FUFCE. */

/*! @brief Read current value of the MCM_ISCR_FUFCE field. */
#define BR_MCM_ISCR_FUFCE(x) (HW_MCM_ISCR(x).B.FUFCE)

/*! @brief Format value for bitfield MCM_ISCR_FUFCE. */
#define BF_MCM_ISCR_FUFCE(v) ((uint32_t)((uint32_t)(v) << BP_MCM_ISCR_FUFCE) & BM_MCM_ISCR_FUFCE)

/*! @brief Set the FUFCE field to a new value. */
#define BW_MCM_ISCR_FUFCE(x, v) (HW_MCM_ISCR_WR(x, (HW_MCM_ISCR_RD(x) & ~BM_MCM_ISCR_FUFCE) | BF_MCM_ISCR_FUFCE(v)))
/*@}*/

/*!
 * @name Register MCM_ISCR, field FIXCE[28] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
/*@{*/
#define BP_MCM_ISCR_FIXCE    (28U)         /*!< Bit position for MCM_ISCR_FIXCE. */
#define BM_MCM_ISCR_FIXCE    (0x10000000U) /*!< Bit mask for MCM_ISCR_FIXCE. */
#define BS_MCM_ISCR_FIXCE    (1U)          /*!< Bit field size in bits for MCM_ISCR_FIXCE. */

/*! @brief Read current value of the MCM_ISCR_FIXCE field. */
#define BR_MCM_ISCR_FIXCE(x) (HW_MCM_ISCR(x).B.FIXCE)

/*! @brief Format value for bitfield MCM_ISCR_FIXCE. */
#define BF_MCM_ISCR_FIXCE(v) ((uint32_t)((uint32_t)(v) << BP_MCM_ISCR_FIXCE) & BM_MCM_ISCR_FIXCE)

/*! @brief Set the FIXCE field to a new value. */
#define BW_MCM_ISCR_FIXCE(x, v) (HW_MCM_ISCR_WR(x, (HW_MCM_ISCR_RD(x) & ~BM_MCM_ISCR_FIXCE) | BF_MCM_ISCR_FIXCE(v)))
/*@}*/

/*!
 * @name Register MCM_ISCR, field FIDCE[31] (RW)
 *
 * Values:
 * - 0 - Disable interrupt
 * - 1 - Enable interrupt
 */
/*@{*/
#define BP_MCM_ISCR_FIDCE    (31U)         /*!< Bit position for MCM_ISCR_FIDCE. */
#define BM_MCM_ISCR_FIDCE    (0x80000000U) /*!< Bit mask for MCM_ISCR_FIDCE. */
#define BS_MCM_ISCR_FIDCE    (1U)          /*!< Bit field size in bits for MCM_ISCR_FIDCE. */

/*! @brief Read current value of the MCM_ISCR_FIDCE field. */
#define BR_MCM_ISCR_FIDCE(x) (HW_MCM_ISCR(x).B.FIDCE)

/*! @brief Format value for bitfield MCM_ISCR_FIDCE. */
#define BF_MCM_ISCR_FIDCE(v) ((uint32_t)((uint32_t)(v) << BP_MCM_ISCR_FIDCE) & BM_MCM_ISCR_FIDCE)

/*! @brief Set the FIDCE field to a new value. */
#define BW_MCM_ISCR_FIDCE(x, v) (HW_MCM_ISCR_WR(x, (HW_MCM_ISCR_RD(x) & ~BM_MCM_ISCR_FIDCE) | BF_MCM_ISCR_FIDCE(v)))
/*@}*/

/*******************************************************************************
 * HW_MCM_CPO - Compute Operation Control Register
 ******************************************************************************/

/*!
 * @brief HW_MCM_CPO - Compute Operation Control Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * This register controls the Compute Operation.
 */
typedef union _hw_mcm_cpo
{
    uint32_t U;
    struct _hw_mcm_cpo_bitfields
    {
        uint32_t CPOREQ : 1;           /*!< [0] Compute Operation request */
        uint32_t CPOACK : 1;           /*!< [1] Compute Operation acknowledge */
        uint32_t CPOWOI : 1;           /*!< [2] Compute Operation wakeup on interrupt */
        uint32_t RESERVED0 : 29;       /*!< [31:3]  */
    } B;
} hw_mcm_cpo_t;

/*!
 * @name Constants and macros for entire MCM_CPO register
 */
/*@{*/
#define HW_MCM_CPO_ADDR(x)       ((x) + 0x40U)

#define HW_MCM_CPO(x)            (*(__IO hw_mcm_cpo_t *) HW_MCM_CPO_ADDR(x))
#define HW_MCM_CPO_RD(x)         (HW_MCM_CPO(x).U)
#define HW_MCM_CPO_WR(x, v)      (HW_MCM_CPO(x).U = (v))
#define HW_MCM_CPO_SET(x, v)     (HW_MCM_CPO_WR(x, HW_MCM_CPO_RD(x) |  (v)))
#define HW_MCM_CPO_CLR(x, v)     (HW_MCM_CPO_WR(x, HW_MCM_CPO_RD(x) & ~(v)))
#define HW_MCM_CPO_TOG(x, v)     (HW_MCM_CPO_WR(x, HW_MCM_CPO_RD(x) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual MCM_CPO bitfields
 */

/*!
 * @name Register MCM_CPO, field CPOREQ[0] (RW)
 *
 * This bit is auto-cleared by vector fetching if CPOWOI = 1.
 *
 * Values:
 * - 0 - Request is cleared.
 * - 1 - Request Compute Operation.
 */
/*@{*/
#define BP_MCM_CPO_CPOREQ    (0U)          /*!< Bit position for MCM_CPO_CPOREQ. */
#define BM_MCM_CPO_CPOREQ    (0x00000001U) /*!< Bit mask for MCM_CPO_CPOREQ. */
#define BS_MCM_CPO_CPOREQ    (1U)          /*!< Bit field size in bits for MCM_CPO_CPOREQ. */

/*! @brief Read current value of the MCM_CPO_CPOREQ field. */
#define BR_MCM_CPO_CPOREQ(x) (HW_MCM_CPO(x).B.CPOREQ)

/*! @brief Format value for bitfield MCM_CPO_CPOREQ. */
#define BF_MCM_CPO_CPOREQ(v) ((uint32_t)((uint32_t)(v) << BP_MCM_CPO_CPOREQ) & BM_MCM_CPO_CPOREQ)

/*! @brief Set the CPOREQ field to a new value. */
#define BW_MCM_CPO_CPOREQ(x, v) (HW_MCM_CPO_WR(x, (HW_MCM_CPO_RD(x) & ~BM_MCM_CPO_CPOREQ) | BF_MCM_CPO_CPOREQ(v)))
/*@}*/

/*!
 * @name Register MCM_CPO, field CPOACK[1] (RO)
 *
 * Values:
 * - 0 - Compute operation entry has not completed or compute operation exit has
 *     completed.
 * - 1 - Compute operation entry has completed or compute operation exit has not
 *     completed.
 */
/*@{*/
#define BP_MCM_CPO_CPOACK    (1U)          /*!< Bit position for MCM_CPO_CPOACK. */
#define BM_MCM_CPO_CPOACK    (0x00000002U) /*!< Bit mask for MCM_CPO_CPOACK. */
#define BS_MCM_CPO_CPOACK    (1U)          /*!< Bit field size in bits for MCM_CPO_CPOACK. */

/*! @brief Read current value of the MCM_CPO_CPOACK field. */
#define BR_MCM_CPO_CPOACK(x) (HW_MCM_CPO(x).B.CPOACK)
/*@}*/

/*!
 * @name Register MCM_CPO, field CPOWOI[2] (RW)
 *
 * Values:
 * - 0 - No effect.
 * - 1 - When set, the CPOREQ is cleared on any interrupt or exception vector
 *     fetch.
 */
/*@{*/
#define BP_MCM_CPO_CPOWOI    (2U)          /*!< Bit position for MCM_CPO_CPOWOI. */
#define BM_MCM_CPO_CPOWOI    (0x00000004U) /*!< Bit mask for MCM_CPO_CPOWOI. */
#define BS_MCM_CPO_CPOWOI    (1U)          /*!< Bit field size in bits for MCM_CPO_CPOWOI. */

/*! @brief Read current value of the MCM_CPO_CPOWOI field. */
#define BR_MCM_CPO_CPOWOI(x) (HW_MCM_CPO(x).B.CPOWOI)

/*! @brief Format value for bitfield MCM_CPO_CPOWOI. */
#define BF_MCM_CPO_CPOWOI(v) ((uint32_t)((uint32_t)(v) << BP_MCM_CPO_CPOWOI) & BM_MCM_CPO_CPOWOI)

/*! @brief Set the CPOWOI field to a new value. */
#define BW_MCM_CPO_CPOWOI(x, v) (HW_MCM_CPO_WR(x, (HW_MCM_CPO_RD(x) & ~BM_MCM_CPO_CPOWOI) | BF_MCM_CPO_CPOWOI(v)))
/*@}*/

/*******************************************************************************
 * hw_mcm_t - module struct
 ******************************************************************************/
/*!
 * @brief All MCM module registers.
 */
#pragma pack(1)
typedef struct _hw_mcm
{
    uint8_t _reserved0[8];
    __I hw_mcm_plasc_t PLASC;              /*!< [0x8] Crossbar Switch (AXBS) Slave Configuration */
    __I hw_mcm_plamc_t PLAMC;              /*!< [0xA] Crossbar Switch (AXBS) Master Configuration */
    __IO hw_mcm_placr_t PLACR;             /*!< [0xC] Crossbar Switch (AXBS) Control Register */
    __IO hw_mcm_iscr_t ISCR;               /*!< [0x10] Interrupt Status and Control Register */
    uint8_t _reserved1[44];
    __IO hw_mcm_cpo_t CPO;                 /*!< [0x40] Compute Operation Control Register */
} hw_mcm_t;
#pragma pack()

/*! @brief Macro to access all MCM registers. */
/*! @param x MCM module instance base address. */
/*! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
 *     use the '&' operator, like <code>&HW_MCM(MCM_BASE)</code>. */
#define HW_MCM(x)      (*(hw_mcm_t *)(x))

#endif /* __HW_MCM_REGISTERS_H__ */
/* EOF */
