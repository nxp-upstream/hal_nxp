include(${CMAKE_CURRENT_LIST_DIR}/../mcux-sdk-ng/middleware/mcux-sdk-middleware-ieee_802.15.4/zephyr/CMakeLists.txt)

if(CONFIG_NXP_NEUTRON)
  add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/neutron
  )
endif()

include(${CMAKE_CURRENT_LIST_DIR}/mcux-secure-subsystem/zephyr/CMakeLists.txt)
