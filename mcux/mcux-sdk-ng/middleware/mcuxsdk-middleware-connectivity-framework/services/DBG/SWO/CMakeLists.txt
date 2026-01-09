# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.dbg.swo)
    mcux_add_include(
        INCLUDES .
    )

    mcux_add_source(
        SOURCES fwk_debug_swo.h
                fwk_debug_swo.c
                README.md
    )
endif()
