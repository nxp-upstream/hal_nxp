# Copyright 2025-2026 NXP
# SPDX-License-Identifier: BSD-3-Clause

if((CONFIG_NET_L2_OPENTHREAD OR CONFIG_NXP_NBU) AND (CONFIG_IEEE802154 OR CONFIG_NXP_IEEE802154_MAC))
    zephyr_include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/phy/interface
        ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/mac/interface
        ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/mac/platform/RW610N/include
    )

    if(CONFIG_IEEE802154)
        if(CONFIG_SOC_SERIES_MCXW7XX)
            zephyr_library_sources(
                ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/phy/source/PhyTime.c
                ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/phy/source/SerialDevice/Phy.c
                ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/phy/source/SerialDevice/ASP.c
            )
            zephyr_compile_definitions(USE_NBU=1)
        endif()
    endif()

    if(CONFIG_NXP_IEEE802154_MAC)
        if(CONFIG_SOC_SERIES_MCXW7XX)
            zephyr_library_sources(
                ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/mac/source/App/mac_intf_rpmsg.c
                ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/phy/source/SerialDevice/Phy.c
                ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/phy/source/PhyTime.c
                ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/phy/source/SerialDevice/ASP.c
            )
            zephyr_compile_definitions(USE_NBU=1)
        elseif(${MCUX_DEVICE} MATCHES "RW61")
            zephyr_library_sources(
                ${CMAKE_CURRENT_LIST_DIR}/../ieee_802_15_4/mac/source/App/mac_intf.c
            )
            zephyr_compile_definitions(USE_NBU=1)
        endif()
    endif()
endif()
