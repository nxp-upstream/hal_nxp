# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.kw47_mcxw72_nbu)
    mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/../wireless_nbu)
    mcux_add_source(SOURCES
        configs/fwk_config.h
        configs/rpmsg_config.h
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core1"
    )
    mcux_add_include(INCLUDES
        .
        configs
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core1"
    )

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.dcdc)
        mcux_add_source(SOURCES
            fwk_platform_dcdc.c
            fwk_platform_dcdc.h
            DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
            CORE_IDS "cm33_core1"
        )
        mcux_add_macro(
            gPlatformEnableDcdcOnNbu_d=1
        )
        mcux_add_include(INCLUDES
            .
            DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
            CORE_IDS "cm33_core1"
        )
    endif()
    if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.dbg)
        mcux_add_source(SOURCES
            fwk_platform_dbg.c
            ../wireless_nbu/fwk_platform_dbg.h
            DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
            CORE_IDS "cm33_core1"
        )
        mcux_add_include(INCLUDES
            .
            ../wireless_nbu
            DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
            CORE_IDS "cm33_core1"
        )
        mcux_add_macro(USE_FWK_DBG_STRUCT=1)
    endif()
endif()

