# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.factory_data_provider)
    mcux_add_source(
        SOURCES fwk_factory_data_provider.c
                fwk_factory_data_provider.h
    )

    mcux_add_include(
        INCLUDES .
    )
endif()
