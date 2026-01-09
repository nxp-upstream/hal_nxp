# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

mcux_set_list(IMX_FAMILY "MIMXRT595S")

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.MIMXRT595S)
    mcux_add_source(SOURCES
        fwk_platform.c
        fwk_platform.h
        DEVICE_IDS ${IMX_FAMILY}
    )

    mcux_add_include(INCLUDES
        .
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.lowpower)
    mcux_add_source(SOURCES
        fwk_platform_lowpower.c
        fwk_platform_lowpower.h
        fwk_platform_lowpower_timer.h
        DEVICE_IDS ${IMX_FAMILY})
endif()
