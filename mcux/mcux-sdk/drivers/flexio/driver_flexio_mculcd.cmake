#Description: FLEXIO MCULCD Driver; user_visible: True
include_guard(GLOBAL)
message("driver_flexio_mculcd component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/mculcd/fsl_flexio_mculcd.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/mculcd/.
)


include(driver_flexio)
