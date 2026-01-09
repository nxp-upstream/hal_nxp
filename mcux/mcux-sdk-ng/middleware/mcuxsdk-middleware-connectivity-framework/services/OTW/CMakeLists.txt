# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.otw)
    mcux_add_source(
        SOURCES k32w0_transceiver/fwk_otw.c
                Interface/fwk_otw.h
    )

    mcux_add_include(
        INCLUDES Interface
    )
endif()