# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

mcux_set_list(RT1060_FAMILY "MIMXRT1061xxxxA MIMXRT1061xxxxB MIMXRT1062xxxxA MIMXRT1062xxxxB")

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.rt1060)
    mcux_add_source(SOURCES
        configs/fwk_config.h
        fwk_platform_definitions.h
        fwk_platform.c
        fwk_platform.h
        DEVICE_IDS ${RT1060_FAMILY}
    )

    mcux_add_include(INCLUDES
        .
        configs
        ../include
        DEVICE_IDS ${RT1060_FAMILY}
    )

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.file_system)
        mcux_add_source(SOURCES
            fwk_platform_flash.c
            fwk_platform_flash.h
            DEVICE_IDS ${RT1060_FAMILY}
        )
    endif()
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ota)
    mcux_add_source(SOURCES
        fwk_platform_ota.c
        ../include/fwk_platform_ota.h
        DEVICE_IDS ${RT1060_FAMILY}
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.external_flash)
    mcux_add_source(SOURCES
        fwk_platform_extflash.c
        ../include/fwk_platform_extflash.h
        DEVICE_IDS ${RT1060_FAMILY}
    )
endif()