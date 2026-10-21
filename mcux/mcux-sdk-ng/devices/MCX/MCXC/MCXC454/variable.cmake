# Copyright 2026 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### chip related
include(${SdkRootDirPath}/devices/MCX/variable.cmake)
mcux_set_variable(device MCXC454)
mcux_set_variable(device_root devices)
mcux_set_variable(soc_series MCXC)
mcux_set_variable(soc_periph periph5)
mcux_set_variable(core_id_suffix_name "")
mcux_set_variable(multicore_foldername .)

#### Source record
