# Copyright 2024 NXP
# SPDX-License-Identifier: Apache-2.0

if (CONFIG_NVS)
    mcux_add_source(
        SOURCES ../../../include/zephyr/fs/nvs.h
                nvs_priv.h
                nvs.c
    )

    mcux_add_include(
        INCLUDES .
    )
endif()