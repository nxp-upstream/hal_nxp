# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/nvs)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/settings)

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.zephyr_common)
    mcux_add_include(INCLUDES ./common)
    mcux_add_source(
        SOURCES common/zephyr_errno.h
    )
endif()
