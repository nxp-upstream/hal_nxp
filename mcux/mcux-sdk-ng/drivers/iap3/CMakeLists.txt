# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.iap3)
    mcux_component_version(2.1.3)

    mcux_add_source(
        SOURCES
            fsl_iap.h
            fsl_iap.c
    )

    mcux_add_include(
        INCLUDES .
    )

endif()
