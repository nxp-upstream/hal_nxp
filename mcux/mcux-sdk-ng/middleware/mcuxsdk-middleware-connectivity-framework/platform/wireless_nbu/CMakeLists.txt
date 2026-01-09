# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform)
    mcux_add_source(SOURCES
        fwk_platform.c
        fwk_platform.h
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core1"
    )
    mcux_add_source(SOURCES
        fwk_platform.c
        fwk_platform.h
        DEVICE_IDS "KW45B41Z83xxxA_NBU" "KW43B43ZC7xxxA_NBU"
    )
    mcux_add_include(INCLUDES
        .
        ../include
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core1"
    )
    mcux_add_include(INCLUDES
        .
        ../include
        DEVICE_IDS "KW45B41Z83xxxA_NBU" "KW43B43ZC7xxxA_NBU"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ble)
    mcux_add_source(SOURCES
        fwk_platform_ble.c
        fwk_platform_ble.h
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core1"
    )
    mcux_add_source(SOURCES
        fwk_platform_ble.c
        fwk_platform_ble.h
        DEVICE_IDS "KW45B41Z83xxxA_NBU" "KW43B43ZC7xxxA_NBU"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ics)
    mcux_add_source(SOURCES
        fwk_platform_ics.c
        fwk_platform_ics.h
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core1"
    )
    mcux_add_source(SOURCES
        fwk_platform_ics.c
        fwk_platform_ics.h
        DEVICE_IDS "KW45B41Z83xxxA_NBU" "KW43B43ZC7xxxA_NBU"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.sensors)
    mcux_add_source(SOURCES
        fwk_platform_sensors.c
        fwk_platform_sensors.h
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core1"
    )
    mcux_add_source(SOURCES
        fwk_platform_sensors.c
        fwk_platform_sensors.h
        DEVICE_IDS "KW45B41Z83xxxA_NBU" "KW43B43ZC7xxxA_NBU"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.lowpower)
    mcux_add_source(SOURCES
        fwk_platform_lowpower.c
        fwk_platform_lowpower.h
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core1"
    )
    mcux_add_source(SOURCES
        fwk_platform_lowpower.c
        fwk_platform_lowpower.h
        DEVICE_IDS "KW45B41Z83xxxA_NBU" "KW43B43ZC7xxxA_NBU"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.genfsk)
    mcux_add_source(SOURCES
        fwk_platform_genfsk.c
        fwk_platform_genfsk.h
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core1"
    )
    mcux_add_source(SOURCES
        fwk_platform_genfsk.c
        fwk_platform_genfsk.h
        DEVICE_IDS "KW45B41Z83xxxA_NBU" "KW43B43ZC7xxxA_NBU"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.rng)
    mcux_add_source(SOURCES
        fwk_platform_rng.c
        ../include/fwk_platform_rng.h
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core1"
    )
    mcux_add_source(SOURCES
        fwk_platform_rng.c
        ../include/fwk_platform_rng.h
        DEVICE_IDS "KW45B41Z83xxxA_NBU" "KW43B43ZC7xxxA_NBU"
    )
endif()
