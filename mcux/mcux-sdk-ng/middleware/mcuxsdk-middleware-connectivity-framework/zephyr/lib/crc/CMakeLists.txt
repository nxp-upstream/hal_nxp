# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_CRC)
    mcux_add_source(
        SOURCES ../../include/zephyr/sys/crc.h
                crc8_sw.c
    )
endif()
