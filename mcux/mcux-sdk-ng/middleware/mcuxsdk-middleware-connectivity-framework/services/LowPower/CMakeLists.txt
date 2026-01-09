# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.lowpower)
    mcux_add_source(
        SOURCES
                PWR_Interface.h
                PWR.c
                README.md
                pics/fig4.PNG
                pics/fig8.PNG
                pics/fig9.PNG
                pics/fig10.PNG
    )
    mcux_add_include(
        INCLUDES ./
    )

    mcux_add_source(
        SOURCES PWR_systicks.c
        COMPONENTS middleware.freertos-kernel
    )

    mcux_add_source(
        SOURCES PWR_systicks_bm.c
        COMPONENTS component.osa_bm
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.lowpower.cli)
    mcux_add_source(
        SOURCES
                PWR_cli.h
                PWR_cli.c
    )
    mcux_add_include(
        INCLUDES ./
    )
endif()
