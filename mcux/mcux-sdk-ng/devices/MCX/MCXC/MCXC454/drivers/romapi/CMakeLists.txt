# Copyright 2026 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.romapi)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES
            ./fsl_romapi.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()
