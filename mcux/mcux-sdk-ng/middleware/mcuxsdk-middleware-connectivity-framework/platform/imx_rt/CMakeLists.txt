# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

mcux_set_list(IMXRT_FAMILY "MIMXRT1171xxxxx MIMXRT1172xxxxx MIMXRT1173xxxxx MIMXRT1175xxxxx MIMXRT1176xxxxx MIMXRT1061xxxxA \
                            MIMXRT1061xxxxB MIMXRT1062xxxxA MIMXRT1062xxxxB")

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.ot)
    mcux_add_source(SOURCES
        fwk_platform_ot.c
        ../include/fwk_platform_ot.h
        DEVICE_IDS ${IMXRT_FAMILY}
        CORE_IDS "cm4" "cm7"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.hdlc)
    mcux_add_source(SOURCES
        ../include/fwk_platform_hdlc.h
        fwk_platform_hdlc.c
        DEVICE_IDS ${IMXRT_FAMILY}
        CORE_IDS "cm4" "cm7"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.coex.k32w0)
    mcux_add_source(SOURCES
        k32w0/fwk_platform_coex.c
        ../include/fwk_platform_coex.h
        DEVICE_IDS ${IMXRT_FAMILY}
        CORE_IDS "cm4" "cm7"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.coex.iw612)
    mcux_add_source(SOURCES
        iw61x/fwk_platform_coex.c
        ../include/fwk_platform_coex.h
        DEVICE_IDS ${IMXRT_FAMILY}
        CORE_IDS "cm4" "cm7"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.coex.iw610)
    mcux_add_source(SOURCES
        iw61x/fwk_platform_coex.c
        ../include/fwk_platform_coex.h
        DEVICE_IDS ${IMXRT_FAMILY}
        CORE_IDS "cm4" "cm7"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform.lfs_config)
    mcux_add_source(SOURCES
        configs/fwk_lfs_config.c
        configs/fwk_lfs_config.h
        DEVICE_IDS ${IMXRT_FAMILY}
        CORE_IDS "cm4" "cm7"
    )

    mcux_add_include(INCLUDES
        configs
        DEVICE_IDS ${IMXRT_FAMILY}
        CORE_IDS "cm4" "cm7"
    )
endif()
