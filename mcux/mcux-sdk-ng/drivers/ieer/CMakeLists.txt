# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ieer)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES fsl_ieer.c fsl_ieer.h)

    mcux_add_include(INCLUDES .)

endif()
