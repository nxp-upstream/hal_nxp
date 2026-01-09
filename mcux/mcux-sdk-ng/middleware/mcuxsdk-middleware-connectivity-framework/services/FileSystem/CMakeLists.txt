# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.file_system)
    mcux_add_source(
        SOURCES fwk_filesystem.c
                fwk_filesystem.h
    )

    mcux_add_include(
        INCLUDES .
    )
endif()
