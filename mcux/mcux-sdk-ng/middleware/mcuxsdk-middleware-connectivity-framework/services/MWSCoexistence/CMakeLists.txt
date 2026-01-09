# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.mws)
    mcux_add_source(
        SOURCES MWS.c
                MWS.h
    )
    mcux_add_include(
        INCLUDES .
    )

endif()
