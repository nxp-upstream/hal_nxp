# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.ota_support)
    mcux_add_source(
        SOURCES Source/OtaSupport.c
                Source/OtaPrivate.h
                Interface/OtaSupport.h
                Interface/OtaServerSupport.h
                README.md
    )

    mcux_add_include(
        INCLUDES Interface
                    Source
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.ota_support.external_flash)
    mcux_add_source(
        SOURCES Source/OtaExternalFlash.c
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.ota_support.internal_flash)
    mcux_add_source(
        SOURCES Source/OtaInternalFlash.c
    )
    mcux_add_linker_symbol(SYMBOLS "gUseInternalStorageLink_d=1" )

endif()

if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.ota_support.no_flash_selected)
    mcux_add_source(
        SOURCES
            Source/OtaInternalFlash.c
            Source/OtaExternalFlash.c
    )
    # Note : gUseInternalStorageLink_d not set, user shall select whether it is internal or external flash at application level
endif()
