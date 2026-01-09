# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.zephyr_port.settings)
    mcux_add_include(
        INCLUDES .
    )

    mcux_add_source(
        SOURCES ../../include/zephyr/sys/list_gen.h
                ../../include/zephyr/sys/slist.h
                settings_port.h
    )

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.zephyr_port.settings.redefine_api)
        mcux_add_macro(gSettingsRedefineApiName_c=1)
    endif()

endif()