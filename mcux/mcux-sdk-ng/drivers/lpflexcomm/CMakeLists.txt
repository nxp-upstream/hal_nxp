# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpflexcomm)
    mcux_component_version(2.2.1)

    mcux_add_source(SOURCES fsl_lpflexcomm.h fsl_lpflexcomm.c)

    mcux_add_include(INCLUDES .)

endif()
