# Add set(CONFIG_USE_device_startup true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

      if(CONFIG_TOOLCHAIN STREQUAL iar AND CONFIG_CORE_ID STREQUAL cm33_core0)
          add_config_file(${CMAKE_CURRENT_LIST_DIR}/iar/startup_MIMXRT798S_cm33_core0.s "" device_startup.MIMXRT798S)
        endif()

        if(CONFIG_TOOLCHAIN STREQUAL iar AND CONFIG_CORE_ID STREQUAL cm33_core1)
          add_config_file(${CMAKE_CURRENT_LIST_DIR}/iar/startup_MIMXRT798S_cm33_core1.s "" device_startup.MIMXRT798S)
        endif()

        if(CONFIG_TOOLCHAIN STREQUAL riscvllvm AND CONFIG_CORE_ID STREQUAL ezhv)
          add_config_file(${CMAKE_CURRENT_LIST_DIR}/llvm/startup_MIMXRT798S_ezhv.S "" device_startup.MIMXRT798S)
        endif()

  

