# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.zephyr_port.nvs)
    mcux_add_source(
        SOURCES fwk_nvs_flash.c
                nvs_port.h
    )
    
    mcux_add_include(
        INCLUDES .
    )

    if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.zephyr_port.nvs.internal_flash)
        mcux_add_source(
            SOURCES fwk_nvs_InternalFlash.c
        )
        mcux_add_macro(
            gAppNvsExternalFlash_c=0
            gAppNvsInternalFlash_c=1
        )
    endif()

    if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.zephyr_port.nvs.external_flash)
        mcux_add_source(
            SOURCES fwk_nvs_ExternalFlash.c
        )
        mcux_add_macro(
            gAppNvsExternalFlash_c=1
            gAppNvsInternalFlash_c=0
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.zephyr_port.nvs.stats)
        mcux_add_source(
            SOURCES fwk_nvs_stats.c
                    fwk_nvs_stats.h
        )
    endif()

endif()