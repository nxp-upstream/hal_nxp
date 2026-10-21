/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_ROMAPI_H_
#define FSL_ROMAPI_H_

#include "fsl_common.h"

/*!
 * @addtogroup romapi
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.romapi"
#endif

/*! @name Driver version */
/*@{*/

/*! @brief romapi driver version 2.0.0. */
#define FSL_ROMAPI_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @name Flash status
 * @{
 */
/*! @brief Flash driver status group. */
#if defined(kStatusGroup_FlashDriver)
#define kStatusGroupGeneric     kStatusGroup_Generic
#define kStatusGroupFlashDriver kStatusGroup_FlashDriver
#elif defined(kStatusGroup_FLASHIAP)
#define kStatusGroupGeneric     kStatusGroup_Generic
#define kStatusGroupFlashDriver kStatusGroup_FLASH
#else
#define kStatusGroupGeneric     0
#define kStatusGroupFlashDriver 1
#endif

/*! @brief Constructs a status code value from a group and a code number. */
#if !defined(MAKE_STATUS)
#define MAKE_STATUS(group, code) ((((group) * 100) + (code)))
#endif

/*!
 * @brief Flash driver status codes.
 */
enum
{
    kStatus_FLASH_Success         = MAKE_STATUS(kStatusGroupGeneric, 0),     /*!< API is executed successfully*/
    kStatus_FLASH_InvalidArgument = MAKE_STATUS(kStatusGroupGeneric, 4),     /*!< Invalid argument*/
    kStatus_FLASH_SizeError       = MAKE_STATUS(kStatusGroupFlashDriver, 0), /*!< Error size*/
    kStatus_FLASH_AlignmentError =
        MAKE_STATUS(kStatusGroupFlashDriver, 1), /*!< Parameter is not aligned with the specified baseline*/
    kStatus_FLASH_AddressError = MAKE_STATUS(kStatusGroupFlashDriver, 2), /*!< Address is out of range */
    kStatus_FLASH_AccessError =
        MAKE_STATUS(kStatusGroupFlashDriver, 3), /*!< Invalid instruction codes and out-of bound addresses */
    kStatus_FLASH_ProtectionViolation = MAKE_STATUS(
        kStatusGroupFlashDriver, 4), /*!< The program/erase operation is requested to execute on protected areas */
    kStatus_FLASH_CommandFailure =
        MAKE_STATUS(kStatusGroupFlashDriver, 5), /*!< Run-time error during command execution. */
    kStatus_FLASH_UnknownProperty = MAKE_STATUS(kStatusGroupFlashDriver, 6), /*!< Unknown property.*/
    kStatus_FLASH_EraseKeyError   = MAKE_STATUS(kStatusGroupFlashDriver, 7)  /*!< API erase key is invalid.*/
};
/*@}*/

/*!
 * @brief Enumeration for various flash properties.
 *
 * @note kFLASH_PropertyPflashPageSize is not provided by the ROM, it is returned by
 *       FLASH_GetProperty() from the device feature definition.
 */
typedef enum _flash_property_tag
{
    kFLASH_PropertyPflashSectorSize    = 0x00U, /*!< Pflash sector size property.*/
    kFLASH_PropertyPflashTotalSize     = 0x01U, /*!< Pflash total size property.*/
    kFLASH_PropertyPflashBlockSize     = 0x02U, /*!< Pflash block size property.*/
    kFLASH_PropertyPflashBlockCount    = 0x03U, /*!< Pflash block count property.*/
    kFLASH_PropertyPflashBlockBaseAddr = 0x04U, /*!< Pflash block base address property.*/
    kFLASH_PropertyPflashPageSize      = 0x30U, /*!< Pflash page size property.*/
    kFLASH_PropertyFfrSectorSize       = 0x40U, /*!< IFR0 sector size property.*/
    kFLASH_PropertyFfrTotalSize        = 0x41U, /*!< IFR0 total size property.*/
    kFLASH_PropertyFfrBlockBaseAddr    = 0x42U, /*!< IFR0 block base address property.*/
    kFLASH_PropertyFfrPageSize         = 0x43U, /*!< IFR0 page size property.*/
} flash_property_tag_t;

/*! @brief Flash memory descriptor. */
typedef struct _flash_mem_descriptor
{
    uint32_t blockBase;  /*!< Base address of the flash block. */
    uint32_t totalSize;  /*!< The size of the flash block. */
    uint32_t blockCount; /*!< A number of flash blocks. */
} flash_mem_desc_t;

/*! @brief Flash IFR0 descriptor. */
typedef struct _flash_ifr_desc
{
    uint32_t pflashIfr0Start;      /*!< IFR0 start address. */
    uint32_t pflashIfr0MemSize;    /*!< IFR0 total size. */
    uint32_t pflashIfr0sectorSize; /*!< IFR0 sector size. */
    uint32_t pflashIfr0PageSize;   /*!< IFR0 page size. */
} flash_ifr_desc_t;

/*! @brief MSF1 flash controller configuration. */
typedef struct _msf1_config
{
    flash_mem_desc_t flashDesc; /*!< Program flash descriptor. */
    flash_ifr_desc_t ifrDesc;   /*!< IFR0 descriptor. */
} msf1_config_t;

/*! @brief Flash driver state information.
 *
 * An instance of this structure is allocated by the user of the flash driver and
 * passed into each of the driver APIs.
 */
typedef struct _flash_config
{
    msf1_config_t msf1Config; /*!< MSF1 flash controller configuration. */
} flash_config_t;

/*! @brief Interface for the high-level flash driver. */
typedef struct _flash_driver_interface
{
    /* Flash driver */
    status_t (*flash_init)(flash_config_t *config);
    status_t (*flash_erase_sector)(
        flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes, uint32_t key);
    status_t (*flash_program_phrase)(
        flash_config_t *config, FMU_Type *base, uint32_t start, uint8_t *src, uint32_t lengthInBytes);
    status_t (*flash_program_page)(
        flash_config_t *config, FMU_Type *base, uint32_t start, uint8_t *src, uint32_t lengthInBytes);
    status_t (*flash_verify_erase_block)(flash_config_t *config, FMU_Type *base, uint32_t blockaddr);
    status_t (*flash_verify_erase_phrase)(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_verify_erase_page)(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_verify_erase_sector)(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);
    status_t (*flash_read_into_misr)(
        flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t end, uint32_t *seed, uint32_t *signature);
    status_t (*flash_get_property)(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value);
    status_t (*flash_verify_program)(flash_config_t *config,
                                     uint32_t start,
                                     uint32_t lengthInBytes,
                                     const uint8_t *expectedData,
                                     uint32_t *failedAddress,
                                     uint32_t *failedData);
    status_t (*flash_read)(flash_config_t *config, uint32_t start, uint8_t *dest, uint32_t lengthInBytes);
    /* IFR driver */
    status_t (*ifr_verify_erase_phrase)(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);
    status_t (*ifr_verify_erase_page)(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);
    status_t (*ifr_verify_erase_sector)(flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t lengthInBytes);
    status_t (*ifr_read_into_misr)(
        flash_config_t *config, FMU_Type *base, uint32_t start, uint32_t end, uint32_t *seed, uint32_t *signature);
    /* version */
    uint32_t version;
} flash_driver_interface_t;

/*! @brief Interface for the FMU IP-level flash driver. */
typedef struct _flash_ipdriver_interface
{
    /* Flash driver */
    status_t (*flash_erase_sector)(FMU_Type *base, uint32_t start);
    status_t (*flash_program_phrase)(FMU_Type *base, uint32_t start, uint32_t *src);
    status_t (*flash_program_page)(FMU_Type *base, uint32_t start, uint32_t *src);
    status_t (*flash_verify_erase_block)(FMU_Type *base, uint32_t blockaddr);
    status_t (*flash_verify_erase_phrase)(FMU_Type *base, uint32_t start);
    status_t (*flash_verify_erase_page)(FMU_Type *base, uint32_t start);
    status_t (*flash_verify_erase_sector)(FMU_Type *base, uint32_t start);
    status_t (*flash_read_into_misr)(FMU_Type *base, uint32_t start, uint32_t end, uint32_t *seed, uint32_t *signature);
    /* IFR driver */
    status_t (*ifr_verify_erase_phrase)(FMU_Type *base, uint32_t start);
    status_t (*ifr_verify_erase_page)(FMU_Type *base, uint32_t start);
    status_t (*ifr_verify_erase_sector)(FMU_Type *base, uint32_t start);
    status_t (*ifr_read_into_misr)(FMU_Type *base, uint32_t start, uint32_t end, uint32_t *seed, uint32_t *signature);
} flash_ipdriver_interface_t;

/*! @brief Constructs the four character code for the Flash driver API key. */
#if !defined(FOUR_CHAR_CODE)
#define FOUR_CHAR_CODE(a, b, c, d) (((d) << 24) | ((c) << 16) | ((b) << 8) | ((a)))
#endif

/*!
 * @brief Enumeration for Flash driver API keys.
 *
 * @note The resulting value is built with a byte order such that the string
 * being readable in expected order when viewed in a hex editor, if the value
 * is treated as a 32-bit little endian value.
 */
enum _flash_driver_api_keys
{
    kFLASH_ApiEraseKey = FOUR_CHAR_CODE('l', 'f', 'e', 'k') /*!< Key value used to validate all flash erase APIs.*/
};

/*   API prototype fields definition.
| 31 : 24 |    23 : 20       |     19 : 16          |  15 : 0   |
|   Tag   |   Boot mode      | ISP Interface        |  Reserved |
|  0xEB   | 0: Reserved      | 0 - LPUART           |           |
|         | 1: ISP mode      | 1 - LPI2C            |           |
|         |                  | 2 - LPSPI            |           |
|         |                  | 7 - Auto detection   |           |
*/
typedef struct
{
    union
    {
        struct
        {
            uint32_t reserved : 16;
            uint32_t boot_interface : 4;
            uint32_t mode : 4;
            uint32_t tag : 8;
        } B;
        uint32_t U;
    } option;
} user_app_boot_invoke_option_t;

/*! @brief Root of the bootloader API tree.
 *
 *  An instance of this struct resides in read-only memory in the bootloader. It
 *  provides a user application access to APIs exported by the bootloader.
 *
 */
typedef struct _bootloader_tree
{
    void (*run_bootloader)(void *arg);                 /*!< Function to start the bootloader executing. */
    const flash_driver_interface_t *flash_driver;      /*!< Internal high-level Flash driver API. */
    const flash_ipdriver_interface_t *flash_ipdriver;  /*!< Internal FMU IP-level Flash driver API. */
} bootloader_tree_t;

/** ROM API base address */
#ifdef FSL_FEATURE_ROMAPI_BASE
#define ROM_API_BASE (FSL_FEATURE_ROMAPI_BASE)
#else
#define ROM_API_BASE (0x03017f00u)
#endif
/** ROM API base pointer */
#define ROM_API ((bootloader_tree_t *)ROM_API_BASE)
/** FLASH API base pointer */
#define FLASH_API (ROM_API->flash_driver)
/** FLASH IP API base pointer */
#define FLASH_IP_API (ROM_API->flash_ipdriver)

/*!
 * @name Flash API
 * @{
 */

/*!
 * @brief Initializes the global flash properties structure members
 *
 * This function checks and initializes the Flash module for the other Flash APIs.
 *
 * @param config Pointer to the storage for the driver runtime state.
 *
 */
static inline status_t FLASH_Init(flash_config_t *config)
{
    return FLASH_API->flash_init(config);
}

/*!
 * @brief Erases the flash sectors encompassed by parameters passed into function
 *
 * This function erases the flash sectors (8 KB) which include the start address
 * and the (start + lengthInBytes - 1) address.
 *
 * @param config The pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be erased.
 *              NOTE: The start address need to be phrase-aligned (16 Bytes).
 *
 * @param lengthInBytes The length, given in bytes to be erased.
 *
 * @param key The value used to validate all flash erase APIs.
 *
 */
static inline status_t FLASH_EraseSector(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    return FLASH_API->flash_erase_sector(config, FMU0, start, lengthInBytes, key);
}

/*!
 * @brief Programs flash phrases with data at locations passed in through parameters
 *
 * This function programs the flash memory with the desired data for a given
 * flash area as determined by the start address and the length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be programmed. Must be
 *              phrase-aligned (16 Bytes).
 * @param src A pointer to the source buffer of data that is to be programmed
 *            into the flash. Must be word-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *                      to be programmed. Must be phrase-aligned (16 Bytes).
 *
 */
static inline status_t FLASH_ProgramPhrase(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    return FLASH_API->flash_program_phrase(config, FMU0, start, src, lengthInBytes);
}

/*!
 * @brief Programs flash page with data at locations passed in through parameters
 *
 * This function programs the flash memory with the desired data for a given
 * flash area as determined by the start address and the length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be programmed. Must be
 *              page-aligned (128 Bytes).
 * @param src A pointer to the source buffer of data that is to be programmed
 *            into the flash. Must be word-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *                      to be programmed. Must be page-aligned (128 Bytes).
 *
 */
static inline status_t FLASH_ProgramPage(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    return FLASH_API->flash_program_page(config, FMU0, start, src, lengthInBytes);
}

/*!
 * @brief Verifies programming of the desired flash area
 *
 * This function compares the data programmed in the flash memory with the expected
 * data for a given flash area as determined by the start address and length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be verified. Must be word-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. Must be word-aligned.
 * @param expectedData A pointer to the expected data that is to be
 *        verified against.
 * @param failedAddress A pointer to the returned failing address.
 * @param failedData A pointer to the returned failing data.
 *
 */
static inline status_t FLASH_VerifyProgram(flash_config_t *config,
                                           uint32_t start,
                                           uint32_t lengthInBytes,
                                           const uint8_t *expectedData,
                                           uint32_t *failedAddress,
                                           uint32_t *failedData)
{
    return FLASH_API->flash_verify_program(config, start, lengthInBytes, expectedData, failedAddress, failedData);
}

/*!
 * @brief Verify that the flash block is erased
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param blockaddr The start address of the flash block, must be block-aligned.
 *
 */
static inline status_t FLASH_VerifyEraseBlock(flash_config_t *config, uint32_t blockaddr)
{
    return FLASH_API->flash_verify_erase_block(config, FMU0, blockaddr);
}

/*!
 * @brief Verify that the flash phrases are erased
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be verified.
 *        Must be phrase-aligned (16 Bytes).
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. Must be phrase-aligned (16 Bytes).
 *
 */
static inline status_t FLASH_VerifyErasePhrase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    return FLASH_API->flash_verify_erase_phrase(config, FMU0, start, lengthInBytes);
}

/*!
 * @brief Verify that the flash pages are erased
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be verified.
 *        Must be page-aligned (128 Bytes).
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. Must be page-aligned (128 Bytes).
 *
 */
static inline status_t FLASH_VerifyErasePage(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    return FLASH_API->flash_verify_erase_page(config, FMU0, start, lengthInBytes);
}

/*!
 * @brief Verify that the flash sectors are erased
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be verified.
 *        Must be sector-aligned (8 KB).
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. Must be sector-aligned (8 KB).
 *
 */
static inline status_t FLASH_VerifyEraseSector(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    return FLASH_API->flash_verify_erase_sector(config, FMU0, start, lengthInBytes);
}

/*!
 * @brief Generates a signature of the selected flash region using the embedded MISR
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the selected flash region. Must be page-aligned (128 Bytes).
 * @param end The end address of the selected flash region. Must be phrase-aligned (16 Bytes)
 *        and be the last phrase in a page.
 * @param seed A pointer to the 128-bit MISR seed (4 words).
 * @param signature A pointer to the 128-bit buffer (4 words) to store the generated signature.
 *
 */
static inline status_t FLASH_ReadIntoMisr(
    flash_config_t *config, uint32_t start, uint32_t end, uint32_t *seed, uint32_t *signature)
{
    return FLASH_API->flash_read_into_misr(config, FMU0, start, end, seed, signature);
}

/*!
 * @brief Returns the desired flash property
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param whichProperty The desired property from the list of properties in
 *        enum flash_property_tag_t
 * @param value A pointer to the value returned for the desired flash property.
 *
 */
static inline status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value)
{
    if (kFLASH_PropertyPflashPageSize == whichProperty)
    {
        if (NULL == value)
        {
            return kStatus_FLASH_InvalidArgument;
        }
        *value = (uint32_t)FSL_FEATURE_FLASH_PFLASH_PAGE_SIZE;
        return kStatus_FLASH_Success;
    }

    return FLASH_API->flash_get_property(config, whichProperty, value);
}

/*!
 * @brief Verify that the IFR0 phrases are erased
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired IFR0 memory to be verified.
 *        Must be phrase-aligned (16 Bytes).
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. Must be phrase-aligned (16 Bytes).
 *
 */
static inline status_t IFR_VerifyErasePhrase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    return FLASH_API->ifr_verify_erase_phrase(config, FMU0, start, lengthInBytes);
}

/*!
 * @brief Verify that the IFR0 pages are erased
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired IFR0 memory to be verified.
 *        Must be page-aligned (128 Bytes).
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. Must be page-aligned (128 Bytes).
 *
 */
static inline status_t IFR_VerifyErasePage(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    return FLASH_API->ifr_verify_erase_page(config, FMU0, start, lengthInBytes);
}

/*!
 * @brief Verify that the IFR0 sectors are erased
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired IFR0 memory to be verified.
 *        Must be sector-aligned (8 KB).
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *        to be verified. Must be sector-aligned (8 KB).
 *
 */
static inline status_t IFR_VerifyEraseSector(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    return FLASH_API->ifr_verify_erase_sector(config, FMU0, start, lengthInBytes);
}

/*!
 * @brief Generates a signature of the selected IFR0 region using the embedded MISR
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the selected IFR0 region. Must be page-aligned (128 Bytes).
 * @param end The end address of the selected IFR0 region. Must be phrase-aligned (16 Bytes)
 *        and be the last phrase in a page.
 * @param seed A pointer to the 128-bit MISR seed (4 words).
 * @param signature A pointer to the 128-bit buffer (4 words) to store the generated signature.
 *
 */
static inline status_t IFR_ReadIntoMisr(
    flash_config_t *config, uint32_t start, uint32_t end, uint32_t *seed, uint32_t *signature)
{
    return FLASH_API->ifr_read_into_misr(config, FMU0, start, end, seed, signature);
}

/*!
 * @brief Reads flash at locations passed in through parameters
 *
 * This function read the flash memory from a given flash area as determined
 * by the start address and the length.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be read.
 * @param dest A pointer to the dest buffer of data that is to be read
 *            from the flash.
 * @param lengthInBytes The length, given in bytes (not words or long-words),
 *                      to be read.
 *
 */
static inline status_t FLASH_Read(flash_config_t *config, uint32_t start, uint8_t *dest, uint32_t lengthInBytes)
{
    return FLASH_API->flash_read(config, start, dest, lengthInBytes);
}

/*!
 * @brief Get ROM API version.
 *
 * This function read the flash driver API version.
 *
 */
static inline uint32_t ROMAPI_GetVersion(void)
{
    return FLASH_API->version;
}

/*!
 * @brief Run the Bootloader API to force into the ISP mode base on the user arg
 *
 * @param arg Indicates API prototype fields definition.
 *          Refer to the above #user_app_boot_invoke_option_t structure
 */
static inline void ROMAPI_RunBootloader(void *arg)
{
    ROM_API->run_bootloader(arg);
}

/* @} */

/*!
 * @name Flash FMU IP-level API
 * @{
 */

/*!
 * @brief Erases one flash sector which includes the start address
 *
 * @param start The start address of the flash sector to be erased. Must be phrase-aligned (16 Bytes).
 *
 */
static inline status_t FLASH_IPEraseSector(uint32_t start)
{
    return FLASH_IP_API->flash_erase_sector(FMU0, start);
}

/*!
 * @brief Programs one flash phrase
 *
 * @param start The start address of the phrase to be programmed. Must be phrase-aligned (16 Bytes).
 * @param src A pointer to the source data (one phrase, 4 words).
 *
 */
static inline status_t FLASH_IPProgramPhrase(uint32_t start, uint32_t *src)
{
    return FLASH_IP_API->flash_program_phrase(FMU0, start, src);
}

/*!
 * @brief Programs one flash page
 *
 * @param start The start address of the page to be programmed. Must be page-aligned (128 Bytes).
 * @param src A pointer to the source data (one page, 32 words).
 *
 */
static inline status_t FLASH_IPProgramPage(uint32_t start, uint32_t *src)
{
    return FLASH_IP_API->flash_program_page(FMU0, start, src);
}

/*!
 * @brief Verify that the flash block is erased
 *
 * @param blockaddr The start address of the flash block, must be block-aligned.
 *
 */
static inline status_t FLASH_IPVerifyEraseBlock(uint32_t blockaddr)
{
    return FLASH_IP_API->flash_verify_erase_block(FMU0, blockaddr);
}

/*!
 * @brief Verify that one flash phrase is erased
 *
 * @param start The start address of the phrase. Must be phrase-aligned (16 Bytes).
 *
 */
static inline status_t FLASH_IPVerifyErasePhrase(uint32_t start)
{
    return FLASH_IP_API->flash_verify_erase_phrase(FMU0, start);
}

/*!
 * @brief Verify that one flash page is erased
 *
 * @param start The start address of the page. Must be page-aligned (128 Bytes).
 *
 */
static inline status_t FLASH_IPVerifyErasePage(uint32_t start)
{
    return FLASH_IP_API->flash_verify_erase_page(FMU0, start);
}

/*!
 * @brief Verify that one flash sector is erased
 *
 * @param start The start address of the sector. Must be sector-aligned (8 KB).
 *
 */
static inline status_t FLASH_IPVerifyEraseSector(uint32_t start)
{
    return FLASH_IP_API->flash_verify_erase_sector(FMU0, start);
}

/*!
 * @brief Generates a signature of the selected flash region using the embedded MISR
 *
 * @param start The start address of the selected flash region. Must be page-aligned (128 Bytes).
 * @param end The end address of the selected flash region. Must be phrase-aligned (16 Bytes)
 *        and be the last phrase in a page.
 * @param seed A pointer to the 128-bit MISR seed (4 words).
 * @param signature A pointer to the 128-bit buffer (4 words) to store the generated signature.
 *
 */
static inline status_t FLASH_IPReadIntoMisr(uint32_t start, uint32_t end, uint32_t *seed, uint32_t *signature)
{
    return FLASH_IP_API->flash_read_into_misr(FMU0, start, end, seed, signature);
}

/*!
 * @brief Verify that one IFR0 phrase is erased
 *
 * @param start The offset address from the IFR0 start address. Must be phrase-aligned (16 Bytes).
 *
 */
static inline status_t IFR_IPVerifyErasePhrase(uint32_t start)
{
    return FLASH_IP_API->ifr_verify_erase_phrase(FMU0, start);
}

/*!
 * @brief Verify that one IFR0 page is erased
 *
 * @param start The offset address from the IFR0 start address. Must be page-aligned (128 Bytes).
 *
 */
static inline status_t IFR_IPVerifyErasePage(uint32_t start)
{
    return FLASH_IP_API->ifr_verify_erase_page(FMU0, start);
}

/*!
 * @brief Verify that one IFR0 sector is erased
 *
 * @param start The offset address from the IFR0 start address. Must be sector-aligned (8 KB).
 *
 */
static inline status_t IFR_IPVerifyEraseSector(uint32_t start)
{
    return FLASH_IP_API->ifr_verify_erase_sector(FMU0, start);
}

/*!
 * @brief Generates a signature of the selected IFR0 region using the embedded MISR
 *
 * @param start The offset address from the IFR0 start address. Must be page-aligned (128 Bytes).
 * @param end The offset address from the IFR0 start address. Must be phrase-aligned (16 Bytes)
 *        and be the last phrase in a page.
 * @param seed A pointer to the 128-bit MISR seed (4 words).
 * @param signature A pointer to the 128-bit buffer (4 words) to store the generated signature.
 *
 */
static inline status_t IFR_IPReadIntoMisr(uint32_t start, uint32_t end, uint32_t *seed, uint32_t *signature)
{
    return FLASH_IP_API->ifr_read_into_misr(FMU0, start, end, seed, signature);
}

/* @} */

/*! @} */

#endif /* FSL_ROMAPI_H_ */
