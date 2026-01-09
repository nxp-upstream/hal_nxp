# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.zephyr_common)
    mcux_add_include(INCLUDES
        include
        include/zephyr/fs
        include/zephyr/settings
        include/zephyr/sys
    )
    mcux_add_source(SOURCES
        include/zephyr/fs/nvs.h
        include/zephyr/settings/settings.h
        include/zephyr/sys/crc.h
        include/zephyr/sys/list_gen.h
        include/zephyr/sys/slist.h
    )
endif()
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/lib)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/port)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/subsys)
