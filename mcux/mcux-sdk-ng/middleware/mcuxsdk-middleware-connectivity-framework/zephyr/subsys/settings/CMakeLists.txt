# Copyright 2024 NXP
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_SETTINGS)
    mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/src)
    mcux_add_include(
        INCLUDES ./include
    )
endif()