/*
 * Copyright 2022-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FWK_PLAT_DEFS_H_
#define _FWK_PLAT_DEFS_H_

#ifndef KB
#define KB(x) (((uint32_t)x) << 10u)
#endif
#ifndef MB
#define MB(x) (((uint32_t)x) << 20u)
#endif

/* SPI NOR Flash is an 16MBytes on RT1170 evk */
#define FLASH_SIZE MB(16U)

#ifndef MFLASH_SECTOR_SIZE
#define MFLASH_SECTOR_SIZE KB(4U)
#endif

#ifndef MFLASH_PAGE_SIZE
#define MFLASH_PAGE_SIZE 256u
#endif

#define PLATFORM_EXTFLASH_START_ADDR  0x30000000UL
#define PLATFORM_EXTFLASH_SECTOR_SIZE MFLASH_SECTOR_SIZE
#define PLATFORM_EXTFLASH_PAGE_SIZE   MFLASH_PAGE_SIZE
#define PLATFORM_EXTFLASH_TOTAL_SIZE  MFLASH_BSIZE

/*
 *  NV_STORAGE_START_ADDRESS is defined by linker script.
 */
#define NV_STORAGE_EXTFLASH_START_OFFSET ((uint32_t)NV_STORAGE_START_ADDRESS - PLATFORM_EXTFLASH_START_ADDR)

#define NV_STORAGE_START_OFFSET NV_STORAGE_EXTFLASH_START_OFFSET

/*
 * Convert offset relative to start of NV storage partition to physical address.
 */
#define NV_EXTFLASH_PHYS_ADDR(offset) ((uint32_t)NV_STORAGE_START_ADDRESS + (offset))

/*
 * Convert offset relative to start of flash device to physical address.
 */
#define EXTFLASH_PHYS_ADDR(offset) ((uint32_t)PLATFORM_EXTFLASH_START_ADDR + (offset))

#endif /* _FWK_PLAT_DEFS_H_ */
