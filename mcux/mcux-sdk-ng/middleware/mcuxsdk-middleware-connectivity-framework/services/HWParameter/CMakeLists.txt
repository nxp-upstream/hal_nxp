# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.hw_parameter)

    mcux_add_source(
        SOURCES HWParameter.c
                HWParameter.h
                README.md
    )

    mcux_add_include(
        INCLUDES .
    )
endif()
