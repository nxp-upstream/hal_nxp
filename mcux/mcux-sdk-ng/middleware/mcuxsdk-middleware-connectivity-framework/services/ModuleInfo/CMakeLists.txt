# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.module_info)
    mcux_add_source(
        SOURCES ModuleInfo.c
                ModuleInfo.h
                README.md
    )
    mcux_add_include(
        INCLUDES .
    )

endif()
