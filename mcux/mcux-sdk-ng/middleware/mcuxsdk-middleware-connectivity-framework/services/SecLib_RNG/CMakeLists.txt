# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng)

    mcux_add_include(
        INCLUDES
            .
    )

    mcux_add_source(
        SOURCES SecLib.h
                SecLib_ecp256.h
                CryptoLibSW.h
                SecLib_aes_mmo.c
                RNG_Interface.h
                README.md
    )

    mcux_add_iar_configuration(
        LD "--diag_suppress=Lt056,Li026"
    )

    # Crypto libraries will be selected automatically based on the device capabilities
    mcux_add_library(
        LIBS lib_crypto_m33_nodsp.a
        CORES cm33
        DSP NO_DSP
        FPU SP_FPU
    )

    mcux_add_library(
        LIBS lib_crypto_m33_nodsp_nofp.a
        CORES cm33
        DSP NO_DSP
        FPU NO_FPU
    )

    mcux_add_library(
        LIBS lib_crypto_m33.a
        CORES cm33
        DSP "DSP"
        FPU SP_FPU
    )

endif()

if (CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.mbedtls)
    mcux_add_source(
       SOURCES SecLib_mbedTLS.c
    )
    mcux_add_macro(CONNFWK_SECLIB_MBEDTLS)

    mcux_add_macro(gRngUseSecureSubSystem_d=0)
    mcux_add_source(
        SOURCES RNG_mbedTLS.c
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.secure_subsystem)
    mcux_add_source(
        SOURCES SecLib_sss.c
    )

    mcux_add_macro(gRngUseSecureSubSystem_d=1)
    mcux_add_source(
        SOURCES RNG.c
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.sw)
    mcux_add_source(
        SOURCES SecLib.c
    )

    mcux_add_macro(gRngUseSecureSubSystem_d=0)
    mcux_add_source(
        SOURCES RNG.c
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.seclib_rng_port.psa)

    mcux_add_source(
        SOURCES
            SecLib_psa.c
            RNG_psa.c
    )

    # replace the original config file with ours
    mcux_remove_macro("-DMBEDTLS_CONFIG_FILE=\\\"mcux_mbedtls_psa_crypto_config.h\\\"")
    mcux_add_configuration(
        CC  "-DMBEDTLS_CONFIG_FILE=\\\"SecLib_psa_config.h\\\""
    )
    mcux_add_macro(gSecLibUsePsa_d=1)
endif()
