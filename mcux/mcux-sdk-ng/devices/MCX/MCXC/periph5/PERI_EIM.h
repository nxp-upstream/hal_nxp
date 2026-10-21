/*
** ###################################################################
**     Processors:          MCXC163VFM
**                          MCXC163VFT
**                          MCXC163VLF
**                          MCXC163VLH
**                          MCXC163VLK
**                          MCXC163VMP
**                          MCXC164VFM
**                          MCXC164VFT
**                          MCXC164VLF
**                          MCXC164VLH
**                          MCXC164VLK
**                          MCXC164VMP
**                          MCXC453VFM
**                          MCXC453VFT
**                          MCXC453VLF
**                          MCXC453VLH
**                          MCXC453VLK
**                          MCXC453VMP
**                          MCXC454VFM
**                          MCXC454VFT
**                          MCXC454VLF
**                          MCXC454VLH
**                          MCXC454VLK
**                          MCXC454VMP
**
**     Version:             rev. 1.0, 2026-03-13
**     Build:               b260917
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2026-03-13)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_EIM.h
 * @version 1.0
 * @date 2026-03-13
 * @brief CMSIS Peripheral Access Layer for EIM
 *
 * CMSIS Peripheral Access Layer for EIM
 */

#if !defined(PERI_EIM_H_)
#define PERI_EIM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC163VFM) || defined(CPU_MCXC163VFT) || defined(CPU_MCXC163VLF) || defined(CPU_MCXC163VLH) || defined(CPU_MCXC163VLK) || defined(CPU_MCXC163VMP))
#include "MCXC163_COMMON.h"
#elif (defined(CPU_MCXC164VFM) || defined(CPU_MCXC164VFT) || defined(CPU_MCXC164VLF) || defined(CPU_MCXC164VLH) || defined(CPU_MCXC164VLK) || defined(CPU_MCXC164VMP))
#include "MCXC164_COMMON.h"
#elif (defined(CPU_MCXC453VFM) || defined(CPU_MCXC453VFT) || defined(CPU_MCXC453VLF) || defined(CPU_MCXC453VLH) || defined(CPU_MCXC453VLK) || defined(CPU_MCXC453VMP))
#include "MCXC453_COMMON.h"
#elif (defined(CPU_MCXC454VFM) || defined(CPU_MCXC454VFT) || defined(CPU_MCXC454VLF) || defined(CPU_MCXC454VLH) || defined(CPU_MCXC454VLK) || defined(CPU_MCXC454VMP))
#include "MCXC454_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Peripheral_Access_Layer EIM Peripheral Access Layer
 * @{
 */

/** EIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t EIMCR;                             /**< Error Injection Module Configuration Register, offset: 0x0 */
  __IO uint32_t EICHEN;                            /**< Error Injection Channel Enable register, offset: 0x4 */
       uint8_t RESERVED_0[248];
  __IO uint32_t EICHD0_WORD0;                      /**< Error Injection Channel Descriptor 0, Word0, offset: 0x100 */
  __IO uint32_t EICHD0_WORD1;                      /**< Error Injection Channel Descriptor 0, Word1, offset: 0x104 */
} EIM_Type;

/* ----------------------------------------------------------------------------
   -- EIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Register_Masks EIM Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define EIM_EIMCR_GEIEN_MASK                     (0x1U)
#define EIM_EIMCR_GEIEN_SHIFT                    (0U)
/*! GEIEN - Global Error Injection Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EIM_EIMCR_GEIEN(x)                       (((uint32_t)(((uint32_t)(x)) << EIM_EIMCR_GEIEN_SHIFT)) & EIM_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define EIM_EICHEN_EICH0EN_MASK                  (0x80000000U)
#define EIM_EICHEN_EICH0EN_SHIFT                 (31U)
/*! EICH0EN - Error Injection Channel 0 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 0
 *  0b1..Error injection is enabled on Error Injection Channel 0
 */
#define EIM_EICHEN_EICH0EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH0EN_SHIFT)) & EIM_EICHEN_EICH0EN_MASK)
/*! @} */

/*! @name EICHD0_WORD0 - Error Injection Channel Descriptor 0, Word0 */
/*! @{ */

#define EIM_EICHD0_WORD0_CHKBIT_MASK_MASK        (0xFE000000U)
#define EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT       (25U)
/*! CHKBIT_MASK - Checkbit Mask */
#define EIM_EICHD0_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD0_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT     (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define EIM_EICHD0_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group EIM_Register_Masks */


/*!
 * @}
 */ /* end of group EIM_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_EIM_H_ */

