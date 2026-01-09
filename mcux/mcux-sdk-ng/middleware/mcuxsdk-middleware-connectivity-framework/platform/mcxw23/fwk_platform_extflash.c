/* -------------------------------------------------------------------------- */
/*                        Copyright 2021-2022-2025 NXP                        */
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
#include "fsl_spifi_nor_flash.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
/* _SECTOR_ADDR returns the address of sector containing address */
#define _SECTOR_ADDR(addr) (((addr) & ~(PLATFORM_EXTFLASH_SECTOR_SIZE - 1U)))
/* _PAGE_ADDR returns the address of page containing address */
#define _PAGE_ADDR(addr) (((addr) & ~(PLATFORM_EXTFLASH_PAGE_SIZE - 1U)))

#define RAM_FUNC __attribute__((section(".ramfunc"))) __attribute__((used)) __attribute__((noinline))

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

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

    st = Nor_Flash_Init(BOARD_GetExtFlashConfig(), &norHandle);
    if (st != kStatus_Success)
    {
        assert(0);
    }
    return (int)st;
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

        /* The external flash used in frdm board is an MX25R6435F which supports 4K-byte, 32K-byte and 64K-byte erase
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

        st = Nor_Flash_Erase(&norHandle, index * PLATFORM_EXTFLASH_SECTOR_SIZE + FSL_FEATURE_SPIFI_START_ADDR,
                             nbSectors * PLATFORM_EXTFLASH_SECTOR_SIZE);
        if (st != kStatus_Success)
        {
            break;
        }
        index += nbSectors;
    }

    return (int)st;
}

/* This API is used to copy from the temporary download location from the external flash
 * to the target location overwriting the ongoing image. This API and all its associated calls
 * should be loaded and executed from RAM. In total this introduces 960B increase in RAM.
 * This is a re-implementation of Nor_Flash_Read API with some minor changes to avoid using
 * memcpy and simplify the placement in RAM.
 */
RAM_FUNC int PLATFORM_ReadExternalFlash(uint8_t *dest, uint32_t length, uint32_t offset, bool requestFastRead)
{
    spifi_command_t         cmd;
    status_t                status          = kStatus_Success;
    spifi_mem_nor_handle_t *memSpifiHandler = (spifi_mem_nor_handle_t *)(norHandle.deviceSpecific);
    SPIFI_Type             *base            = (SPIFI_Type *)norHandle.driverBaseAddr;
    (void)requestFastRead;

    cmd.dataLen           = 0;
    cmd.isPollMode        = false;
    cmd.direction         = kSPIFI_DataInput;
    cmd.intermediateBytes = memSpifiHandler->intermediateLen;
    cmd.format            = memSpifiHandler->readmemCommandFormt;
    cmd.type              = memSpifiHandler->commandType;
    cmd.opcode            = memSpifiHandler->commandSet.readMemoryCommand;
    SPIFI_SetMemoryCommand(base, &cmd);

    for (uint32_t i = 0; i < length; i++)
    {
        dest[i] = *((uint8_t *)(offset + FSL_FEATURE_SPIFI_START_ADDR + i));
    }
    /* Reset to command mode. */
    SPIFI_ResetCommand(base);

    return status;
}

int PLATFORM_WriteExternalFlash(uint8_t *data, uint32_t length, uint32_t address)
{
    status_t st;
    st = Nor_Flash_Program(&norHandle, address + FSL_FEATURE_SPIFI_START_ADDR, data, length);
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
        if (kStatus_Success !=
            Nor_Flash_Read(&norHandle, address + FSL_FEATURE_SPIFI_START_ADDR, (uint8_t *)read_buf, read_sz))
        {
            ret = false;
        }
        else
        {
            if (!MemCmpToEraseValue((uint8_t *)read_buf, read_sz))
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
