/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2022 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include "fwk_hal_macros.h"
#include "fwk_config.h"
#include "fwk_platform_extflash.h"
#include "board.h"
#include "board_extflash.h"
#include "fsl_nor_flash.h"
#include "fsl_lpspi_nor_flash.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
/* _SECTOR_ADDR returns the address of sector containing address */
#define _SECTOR_ADDR(addr) (((addr) & ~(PLATFORM_EXTFLASH_SECTOR_SIZE - 1U)))
/* _PAGE_ADDR returns the address of page containing address */
#define _PAGE_ADDR(addr) (((addr) & ~(PLATFORM_EXTFLASH_PAGE_SIZE - 1U)))
/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static nor_config_t norConfig = {NULL};
static nor_handle_t norHandle = {NULL};

/* -------------------------------------------------------------------------- */
/*                               Private functions                               */
/* -------------------------------------------------------------------------- */

static bool MemCmpToEraseValue(uint8_t *ptr, uint32_t blen)
{
    bool ret = true;
    for (uint32_t i = 0u; i < blen; i++)
    {
        if (ptr[i] != 0xffu)
        {
            ret = false;
            break;
        }
    }
    return ret;
}

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitExternalFlash(void)
{
    status_t st = kStatus_Success;

    BOARD_InitExternalFlash();

    st = Nor_Flash_Init(&norConfig, &norHandle);
    if (st != kStatus_Success)
    {
        assert(0);
    }
    return (int)st;
}

int PLATFORM_UninitExternalFlash(void)
{
    status_t status;

    status = Nor_Flash_Enter_Lowpower(&norHandle);
    assert(status == kStatus_Success);

    BOARD_UninitExternalFlash();

    return (int)status;
}

int PLATFORM_ReinitExternalFlash(void)
{
    status_t status;

    BOARD_InitExternalFlash();

    status = Nor_Flash_Exit_Lowpower(&norHandle);
    assert(status == kStatus_Success);

    return (int)status;
}

int PLATFORM_EraseExternalFlash(uint32_t address, uint32_t size)
{
    status_t st      = kStatus_Success;
    uint32_t endAddr = address + size;
    uint32_t startBlock, endBlock;
    uint32_t index;
    if ((endAddr & (PLATFORM_EXTFLASH_SECTOR_SIZE - 1U)) != 0U)
    {
        /* If the address is in the middle of a block, round up to the next block
         * This gives the upper block limit, every blocks before this one will be erased */
        endAddr = ((endAddr / PLATFORM_EXTFLASH_SECTOR_SIZE) + 1U) * PLATFORM_EXTFLASH_SECTOR_SIZE;
    }

    startBlock = address / PLATFORM_EXTFLASH_SECTOR_SIZE;
    endBlock   = endAddr / PLATFORM_EXTFLASH_SECTOR_SIZE;
    index      = startBlock;
    while (index < endBlock)
    {
        uint32_t remainingSector = endBlock - index;
        uint32_t remainingSize   = remainingSector * PLATFORM_EXTFLASH_SECTOR_SIZE;
        uint32_t nbSectors;

        /* The external flash used on EVKs is an AT25XE161D and supports different erase size in one operation
         * So we can optimize by erasing multiple sectors in one operation instead of each sector one by one */
        if (remainingSize >= (uint32_t)KB(64U))
        {
            nbSectors = (uint32_t)(KB(64U) / ((uint32_t)PLATFORM_EXTFLASH_SECTOR_SIZE));
        }
        else if (remainingSize >= (uint32_t)KB(32U))
        {
            nbSectors = (uint32_t)(KB(32U) / ((uint32_t)PLATFORM_EXTFLASH_SECTOR_SIZE));
        }
        else if (remainingSize >= (uint32_t)KB(4U))
        {
            nbSectors = (KB(4U) / ((uint32_t)PLATFORM_EXTFLASH_SECTOR_SIZE));
        }
        else
        {
            nbSectors = 1U;
        }

        st = Nor_Flash_Erase(&norHandle, index * PLATFORM_EXTFLASH_SECTOR_SIZE,
                             nbSectors * PLATFORM_EXTFLASH_SECTOR_SIZE);
        if (st != kStatus_Success)
        {
            break;
        }
        index += nbSectors;
    }

    return (int)st;
}

int PLATFORM_ReadExternalFlash(uint8_t *dest, uint32_t length, uint32_t offset, bool requestFastRead)
{
    status_t st;
    (void)requestFastRead;

    st = (int)Nor_Flash_Read(&norHandle, offset, dest, length);
    if (st != kStatus_Success)
    {
        assert(0);
    }
    return (int)st;
}

int PLATFORM_WriteExternalFlash(uint8_t *data, uint32_t length, uint32_t address)
{
    status_t st;
    st = Nor_Flash_Program(&norHandle, address, data, length);
    if (st != kStatus_Success)
    {
        assert(0);
    }
    return (int)st;
}

int PLATFORM_IsExternalFlashBusy(bool *isBusy)
{
    return (int)Nor_Flash_Is_Busy(&norHandle, isBusy);
}

bool PLATFORM_ExternalFlashAreaIsBlank(uint32_t address, uint32_t len)
{
    uint8_t  read_buf[PLATFORM_EXTFLASH_PAGE_SIZE] = {0U};
    uint32_t remaining_sz                          = len;
    bool     ret                                   = false;

    while (remaining_sz > 0u)
    {
        uint32_t read_sz;
        read_sz = MIN(remaining_sz, PLATFORM_EXTFLASH_PAGE_SIZE);
        if (kStatus_Success != Nor_Flash_Read(&norHandle, address, (uint8_t *)read_buf, read_sz))
        {
            ret = false;
        }
        else
        {
            if (!MemCmpToEraseValue((uint8_t *)address, read_sz))
            {
                ret = false;
                /* Can stop at once if one byte differ */
                break;
            }
        }
        remaining_sz -= read_sz;
    }
    if (remaining_sz == 0u)
    {
        ret = true;
    }
    return ret;
}

bool PLATFORM_IsExternalFlashPageBlank(uint32_t address)
{
    uint32_t page_addr = _PAGE_ADDR(address);
    /* Start from address of page containing argument address */

    return PLATFORM_ExternalFlashAreaIsBlank(page_addr, PLATFORM_EXTFLASH_PAGE_SIZE);
}

bool PLATFORM_IsExternalFlashSectorBlank(uint32_t address)
{
    /* Start from address of sector containing argument address */
    uint32_t sect_addr = _SECTOR_ADDR(address);

    return PLATFORM_ExternalFlashAreaIsBlank(sect_addr, PLATFORM_EXTFLASH_SECTOR_SIZE);
}
