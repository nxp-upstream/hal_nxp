# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.nvm)
    mcux_add_source(
        SOURCES Interface/NVM_Interface.h
                Source/NV_Flash.c
                Source/NV_Flash.h
                README.md
                pics/flash_active_page_layout.PNG
                pics/flash_copy_of_ram_table_entry_structure.PNG
                pics/NVM_entry_example.PNG
                pics/NVM_MIT_structure.PNG
                pics/NVM_Page_copy_and_defragmentation.PNG
                pics/NVM_table_entry_list_example.PNG
                pics/NVM_virtual_page_getting_full_example.PNG
    )
    mcux_add_include(
        INCLUDES Interface
                Source
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.nvm.fsci)
    mcux_add_macro(gFsciIncluded_c=1)
    mcux_add_source(
        SOURCES Source/NV_FsciCommands.c
                Source/NV_FsciCommands.h
    )
    mcux_add_include(
        INCLUDES Source
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.nvm.interval_policy.w_jitter)
    mcux_add_macro(gNvmSaveOnIdlePolicy_d=3)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.nvm.interval_policy.wo_jitter)
    mcux_add_macro(gNvmSaveOnIdlePolicy_d=1)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.nvm.interval_policy.none)
    mcux_add_macro(gNvmSaveOnIdlePolicy_d=0)
endif()
