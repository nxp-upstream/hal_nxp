# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.pdum)
    mcux_add_include(
        INCLUDES Include
    )
    mcux_add_source(
        SOURCES
            Include/pdum_nwk.h
            Include/pdum_apl.h
            Include/pdum_common.h
    )

   mcux_add_library(
        LIBS Library/rw61x/libPDUM.a
        CORES cm33
        DSP NO_DSP
        FPU SP_FPU
    )

    mcux_add_library(
        LIBS Library/libPDUM.a
        CORES cm33
        DSP "DSP"
        FPU SP_FPU
    )

endif()
