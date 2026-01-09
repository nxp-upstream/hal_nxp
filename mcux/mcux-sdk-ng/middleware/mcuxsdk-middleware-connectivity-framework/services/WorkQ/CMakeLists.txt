# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.workq)
    mcux_add_source(
        SOURCES fwk_workq.c
                fwk_sysworkq.c
                fwk_workq.h
                README.md
    )
    mcux_add_include(
        INCLUDES .
    )
endif()
