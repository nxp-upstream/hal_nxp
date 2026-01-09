# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

mcux_set_list(KW45_FAMILY "KW45B41Z52xxxA KW45B41Z53xxxA KW45B41Z82xxxA KW45B41Z83xxxA K32W1480xxxA")
mcux_set_list(MCXW71_FAMILY "MCXW716CxxxA MCXW716AxxxA")
mcux_set_list(KW47_FAMILY "KW47B42Z83xxxA KW47B42Z96xxxA KW47B42Z97xxxA KW47B42ZB2xxxA KW47B42ZB3xxxA KW47B42ZB6xxxA KW47B42ZB7xxxA KW47Z42082xxxA KW47Z42092xxxA KW47Z420B2xxxA KW47Z420B3xxxA")
mcux_set_list(MCXW72_FAMILY "MCXW727CxxxA")

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.sfc)
    mcux_add_include(
        INCLUDES .
    )
    # sources for the Host core
    mcux_add_source(
        SOURCES
            fwk_sfc.h
            README.md
        DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY}
        CORE_IDS "cm33_core0" "cm33"
    )
    # sources for the NBU core
    mcux_add_source(
        SOURCES
            fwk_rf_sfc.c
            fwk_rf_sfc.h
            README.md
        CORE_IDS "cm33_core1"
        DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
    )
    # Need to duplicate for KW45 NBU because cm3 core id doesn't exist
    mcux_add_source(
        SOURCES
            fwk_rf_sfc.c
            fwk_rf_sfc.h
            README.md
        DEVICE_IDS "KW45B41Z83xxxA_NBU"
    )
endif()
