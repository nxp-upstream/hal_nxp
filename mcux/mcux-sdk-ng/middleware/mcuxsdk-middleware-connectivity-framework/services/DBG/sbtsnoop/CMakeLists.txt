# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.dbg.sbtsnoop)
    mcux_add_include(
        INCLUDES .
    )

    mcux_add_source(
        SOURCES sbtsnoop.h
                sbtsnoop.c
                sbtsnoop_port.h
                readme.md
    )

endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.dbg.sbtsnoop.port.nxp_ble)
    mcux_add_source(
        SOURCES sbtsnoop_port_nxp_ble.h
    )

    mcux_add_macro(
        SBTSNOOP_PORT_FILE=sbtsnoop_port_nxp_ble.h
    )
endif()
