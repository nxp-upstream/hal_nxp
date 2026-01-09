# Copyright 2024 NXP
# SPDX-License-Identifier: Apache-2.0

mcux_add_source(
    SOURCES ../../../include/zephyr/settings/settings.h
            settings.c
            settings_init.c
            settings_store.c
)

if(CONFIG_SETTINGS_NVS)
    mcux_add_source(
        SOURCES ../include/settings/settings_nvs.h
                settings_nvs.c
    )
endif()

if(CONFIG_SETTINGS_RUNTIME)
    mcux_add_source(
        SOURCES settings_runtime.c
    )
endif()
