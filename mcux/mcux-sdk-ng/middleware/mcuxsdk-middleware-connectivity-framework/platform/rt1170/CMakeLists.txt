# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

mcux_set_list(RT1170_FAMILY "MIMXRT1171xxxxx MIMXRT1172xxxxx MIMXRT1173xxxxx MIMXRT1175xxxxx MIMXRT1176xxxxx")

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.rt1170)
    mcux_add_source(SOURCES
        configs/fwk_config.h
        fwk_platform_definitions.h
        fwk_platform.c
        fwk_platform.h
        DEVICE_IDS ${RT1170_FAMILY}
        CORE_IDS "cm4" "cm7"
    )

    mcux_add_include(INCLUDES
        .
        configs
        ../include
        DEVICE_IDS ${RT1170_FAMILY}
        CORE_IDS "cm4" "cm7"
    )

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.file_system)
        mcux_add_source(SOURCES
            fwk_platform_flash.c
            fwk_platform_flash.h
            DEVICE_IDS ${RT1170_FAMILY}
            CORE_IDS "cm4" "cm7"
        )
    endif()
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ota)
    mcux_add_source(SOURCES
        fwk_platform_ota.c
        ../include/fwk_platform_ota.h
        DEVICE_IDS ${RT1170_FAMILY}
        CORE_IDS "cm4" "cm7"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.external_flash)
    mcux_add_source(SOURCES
        fwk_platform_extflash.c
        ../include/fwk_platform_extflash.h
        DEVICE_IDS ${RT1170_FAMILY}
        CORE_IDS "cm4" "cm7"
    )
endif()