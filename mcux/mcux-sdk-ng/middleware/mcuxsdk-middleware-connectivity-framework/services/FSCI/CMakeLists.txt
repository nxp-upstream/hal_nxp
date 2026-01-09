# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.fsci)
    mcux_add_source(
        SOURCES Source/FsciCommands.c
            Source/FsciCommands.h
            Source/FsciCommunication.c
            Source/FsciCommunication.h
            Source/FsciLogging.c
            Source/FsciMain.c
            Interface/FsciInterface.h
            README.md
    )
    mcux_add_include(
        INCLUDES Source
            Interface
    )
endif()
