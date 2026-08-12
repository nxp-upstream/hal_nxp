# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# fsl_clock.c calls MODCON_GetCFG() (and the SoC reset path uses
# RESET_PeripheralReset()), both defined in fsl_modcon.c. The mcux component
# auto-selection does not pull driver.modcon for this lean tree, so force it on
# for the Zephyr RT2260-EVK baseline to satisfy the clock driver's dependency.
set(CONFIG_MCUX_COMPONENT_driver.modcon ON)

include(./CMakeLists_clock.txt)
include(./CMakeLists_edma_soc.txt)
include(./CMakeLists_iomuxc.txt)
include(./CMakeLists_memory.txt)
include(./CMakeLists_modcon.txt)
# NOTE (Zephyr RT2260-EVK baseline): driver.power (fsl_power.c) is intentionally
# NOT pulled in. fsl_power.h depends on fsl_pmu.h plus the powercon / pdcon /
# rt2k_pmu components, which are not present in this lean hal_nxp tree, so
# force-building it breaks the build. The RAM-execution baseline does not need
# the power driver. Re-enable this include once those components are synced.
# include(./CMakeLists_power.txt)
include(./CMakeLists_trdc_soc.txt)
include(./CMakeLists_mipi_dsi_soc.txt)
include(./CMakeLists_inputmux_connections.txt)
include(./CMakeLists_vbatcon.txt)
include(./CMakeLists_memcon.txt)
include(./CMakeLists_resetcon.txt)
include(./CMakeLists_mcm.txt)
