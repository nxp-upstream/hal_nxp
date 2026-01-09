# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.pdm)

    mcux_add_include(
        INCLUDES Include
    )

    mcux_add_source(
        SOURCES
            Include/PDM.h
    )
endif()
