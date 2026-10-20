# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

include_guard(GLOBAL)

option(
  MCUX_USE_TARGET_SCOPED_FLAGS
  "Apply MCUX compiler and linker flags through target usage requirements"
  ON)

if(MCUX_USE_TARGET_SCOPED_FLAGS)
  set(_mcux_requested_flag_engine "target")
else()
  set(_mcux_requested_flag_engine "legacy")
endif()

get_property(
  _mcux_previous_flag_engine
  CACHE MCUX_FLAG_ENGINE_MODE
  PROPERTY VALUE)
if(_mcux_previous_flag_engine
   AND NOT _mcux_previous_flag_engine STREQUAL _mcux_requested_flag_engine)
  message(
    FATAL_ERROR
      "MCUX flag engine changed from '${_mcux_previous_flag_engine}' to "
      "'${_mcux_requested_flag_engine}' in an existing build directory. "
      "Use a pristine build directory when changing MCUX_USE_TARGET_SCOPED_FLAGS."
  )
endif()
set(
  MCUX_FLAG_ENGINE_MODE
  "${_mcux_requested_flag_engine}"
  CACHE INTERNAL "Selected MCUX compiler/linker flag engine" FORCE)
message(STATUS "MCUX flag engine: ${MCUX_FLAG_ENGINE_MODE}")

if(MCUX_USE_TARGET_SCOPED_FLAGS)
  if(TARGET mcux_sdk_compile_options OR TARGET mcux_sdk_link_options)
    message(
      FATAL_ERROR
        "The target names mcux_sdk_compile_options and mcux_sdk_link_options "
        "are reserved by the MCUX target-scoped flag engine.")
  endif()
  add_library(mcux_sdk_compile_options INTERFACE)
  add_library(mcux_sdk_link_options INTERFACE)
endif()

function(_mcux_target_flags_get_active type output)
  get_property(
    _flags
    TARGET mcux_build_properties
    PROPERTY MCUX_${type}_ACTIVE_FLAGS)
  set(${output}
      "${_flags}"
      PARENT_SCOPE)
endfunction()

function(_mcux_target_flags_set_active type)
  set_property(
    TARGET mcux_build_properties
    PROPERTY MCUX_${type}_ACTIVE_FLAGS "${ARGN}")
endfunction()

function(_mcux_target_flags_append type flag)
  if("${flag}" STREQUAL "")
    return()
  endif()

  _mcux_target_flags_get_active(${type} _flags)
  list(APPEND _flags "${flag}")
  _mcux_target_flags_set_active(${type} ${_flags})
endfunction()

function(_mcux_target_flags_replace type old_flag new_flag)
  _mcux_target_flags_get_active(${type} _flags)
  list(FIND _flags "${old_flag}" _index)
  if(_index GREATER -1)
    list(REMOVE_AT _flags ${_index})
    list(INSERT _flags ${_index} "${new_flag}")
  else()
    list(APPEND _flags "${new_flag}")
  endif()
  _mcux_target_flags_set_active(${type} ${_flags})
endfunction()

function(_mcux_target_flags_remove_exact type flag)
  get_property(
    _removed_flags
    TARGET mcux_build_properties
    PROPERTY INTERFACE_${type}_TO_BE_REMOVED_FLAGS)
  list(FIND _removed_flags "${flag}" _removed_index)
  if(_removed_index EQUAL -1)
    list(APPEND _removed_flags "${flag}")
    set_property(
      TARGET mcux_build_properties
      PROPERTY INTERFACE_${type}_TO_BE_REMOVED_FLAGS "${_removed_flags}")
  endif()

  _mcux_target_flags_get_active(${type} _active_flags)
  list(REMOVE_ITEM _active_flags "${flag}")
  _mcux_target_flags_set_active(${type} ${_active_flags})
endfunction()

function(_mcux_register_target property target_name)
  if(NOT MCUX_USE_TARGET_SCOPED_FLAGS OR "${target_name}" STREQUAL "")
    return()
  endif()

  get_property(
    _targets
    TARGET mcux_build_properties
    PROPERTY ${property})
  list(FIND _targets "${target_name}" _index)
  if(_index EQUAL -1)
    list(APPEND _targets "${target_name}")
    set_property(
      TARGET mcux_build_properties
      PROPERTY ${property} "${_targets}")
  endif()
endfunction()

function(_mcux_register_compile_target target_name)
  _mcux_register_target(MCUX_COMPILE_TARGETS "${target_name}")
endfunction()

function(_mcux_register_final_link_target target_name)
  _mcux_register_target(MCUX_FINAL_LINK_TARGETS "${target_name}")
endfunction()

function(_mcux_register_current_sdk_compile_target)
  if(DEFINED MCUX_SDK_PROJECT_NAME AND NOT "${MCUX_SDK_PROJECT_NAME}" STREQUAL "")
    _mcux_register_compile_target("${MCUX_SDK_PROJECT_NAME}")
  endif()
endfunction()

function(_mcux_escape_generator_expression_content output value)
  set(_escaped "${value}")
  string(REPLACE ">" "__MCUX_ANGLE_RIGHT__" _escaped "${_escaped}")
  string(REPLACE ";" "__MCUX_SEMICOLON__" _escaped "${_escaped}")
  string(REPLACE "__MCUX_ANGLE_RIGHT__" "$<ANGLE-R>" _escaped "${_escaped}")
  string(REPLACE "__MCUX_SEMICOLON__" "$<SEMICOLON>" _escaped "${_escaped}")
  set(${output}
      "${_escaped}"
      PARENT_SCOPE)
endfunction()

function(_mcux_make_language_shell_option context language flag output)
  _mcux_escape_generator_expression_content(_escaped "${flag}")
  set(${output}
      "$<$<${context}:${language}>:SHELL:${_escaped}>"
      PARENT_SCOPE)
endfunction()

function(_mcux_make_shell_option flag output)
  _mcux_escape_generator_expression_content(_escaped "${flag}")
  set(${output}
      "SHELL:${_escaped}"
      PARENT_SCOPE)
endfunction()

function(_mcux_resolve_target target_name output)
  if(NOT TARGET "${target_name}")
    message(FATAL_ERROR "Registered MCUX build target '${target_name}' does not exist.")
  endif()

  get_target_property(_aliased_target "${target_name}" ALIASED_TARGET)
  if(_aliased_target)
    set(_resolved_target "${_aliased_target}")
  else()
    set(_resolved_target "${target_name}")
  endif()

  get_target_property(_imported "${_resolved_target}" IMPORTED)
  if(_imported)
    message(FATAL_ERROR "Registered MCUX build target '${_resolved_target}' is imported.")
  endif()

  set(${output}
      "${_resolved_target}"
      PARENT_SCOPE)
endfunction()

function(_mcux_attach_options_target target_name options_target)
  _mcux_resolve_target("${target_name}" _target)
  get_target_property(_type "${_target}" TYPE)
  if(_type STREQUAL "INTERFACE_LIBRARY")
    target_link_libraries("${_target}" INTERFACE "${options_target}")
  elseif(_type STREQUAL "EXECUTABLE"
         OR _type STREQUAL "STATIC_LIBRARY"
         OR _type STREQUAL "SHARED_LIBRARY"
         OR _type STREQUAL "MODULE_LIBRARY"
         OR _type STREQUAL "OBJECT_LIBRARY")
    target_link_libraries("${_target}" PRIVATE "${options_target}")
  else()
    message(
      FATAL_ERROR
        "MCUX target-scoped flags do not support target '${_target}' of type '${_type}'."
    )
  endif()
endfunction()

function(_mcux_warn_unregistered_compiled_dependencies target_name registered_targets)
  _mcux_resolve_target("${target_name}" _target)
  get_target_property(_dependencies "${_target}" LINK_LIBRARIES)
  if(NOT _dependencies)
    return()
  endif()
  get_target_property(_host_dependencies "${_target}" MCUX_HOST_LINK_LIBRARIES)

  foreach(_dependency IN LISTS _dependencies)
    if(NOT TARGET "${_dependency}")
      continue()
    endif()
    # Dependencies declared by the host before attach keep host-owned flags.
    if(_dependency IN_LIST _host_dependencies)
      continue()
    endif()

    get_target_property(_aliased_dependency "${_dependency}" ALIASED_TARGET)
    if(_aliased_dependency)
      set(_resolved_dependency "${_aliased_dependency}")
    else()
      set(_resolved_dependency "${_dependency}")
    endif()
    get_target_property(_imported_dependency "${_resolved_dependency}" IMPORTED)
    if(_imported_dependency)
      continue()
    endif()

    get_target_property(_type "${_resolved_dependency}" TYPE)
    if(_type STREQUAL "STATIC_LIBRARY"
       OR _type STREQUAL "SHARED_LIBRARY"
       OR _type STREQUAL "MODULE_LIBRARY"
       OR _type STREQUAL "OBJECT_LIBRARY")
      list(FIND registered_targets "${_resolved_dependency}" _registered_index)
      list(FIND registered_targets "${_dependency}" _alias_index)
      if(_registered_index EQUAL -1 AND _alias_index EQUAL -1)
        message(
          WARNING
            "MCUX target '${_target}' links compiled target '${_dependency}', "
            "but that dependency is not registered for target-scoped MCUX compile flags."
        )
      endif()
    endif()
  endforeach()
endfunction()

function(_mcux_finalize_target_flags)
  if(NOT MCUX_USE_TARGET_SCOPED_FLAGS)
    return()
  endif()

  get_property(
    _finalized
    GLOBAL
    PROPERTY MCUX_TARGET_FLAGS_FINALIZED)
  if(_finalized)
    return()
  endif()
  set_property(GLOBAL PROPERTY MCUX_TARGET_FLAGS_FINALIZED TRUE)

  set(_compile_options)
  set(_link_options)
  # Dedicated-linker toolchains never consumed CMAKE_<LANG>_FLAGS while linking.
  set(_mcux_compiler_driver_link_toolchains armgcc mcux riscvllvm xtensa)
  if(CONFIG_TOOLCHAIN IN_LIST _mcux_compiler_driver_link_toolchains)
    set(_mcux_mirror_language_flags_to_link TRUE)
  else()
    set(_mcux_mirror_language_flags_to_link FALSE)
  endif()

  foreach(_type_language IN ITEMS "AS;ASM" "CC;C" "CX;CXX")
    list(GET _type_language 0 _type)
    list(GET _type_language 1 _language)
    _mcux_target_flags_get_active(${_type} _flags)
    if(_flags)
      # One shell group preserves repeated prefixes such as "-opt A -opt B".
      list(JOIN _flags " " _joined_flags)
      _mcux_make_language_shell_option(
        COMPILE_LANGUAGE "${_language}" "${_joined_flags}" _compile_option)
      list(APPEND _compile_options "${_compile_option}")
      if(_mcux_mirror_language_flags_to_link)
        _mcux_make_language_shell_option(
          LINK_LANGUAGE "${_language}" "${_joined_flags}" _link_option)
        list(APPEND _link_options "${_link_option}")
      endif()
    endif()
  endforeach()

  _mcux_target_flags_get_active(LD _ld_flags)
  if(_ld_flags)
    list(JOIN _ld_flags " " _joined_ld_flags)
    _mcux_make_shell_option("${_joined_ld_flags}" _link_option)
    list(APPEND _link_options "${_link_option}")
  endif()

  set_property(
    TARGET mcux_sdk_compile_options
    PROPERTY INTERFACE_COMPILE_OPTIONS "${_compile_options}")
  set_property(
    TARGET mcux_sdk_link_options
    PROPERTY INTERFACE_LINK_OPTIONS "${_link_options}")

  get_property(
    _compile_targets
    TARGET mcux_build_properties
    PROPERTY MCUX_COMPILE_TARGETS)
  foreach(_target IN LISTS _compile_targets)
    _mcux_warn_unregistered_compiled_dependencies(
      "${_target}" "${_compile_targets}")
    _mcux_attach_options_target("${_target}" mcux_sdk_compile_options)
  endforeach()

  get_property(
    _link_targets
    TARGET mcux_build_properties
    PROPERTY MCUX_FINAL_LINK_TARGETS)
  foreach(_target IN LISTS _link_targets)
    _mcux_resolve_target("${_target}" _resolved_target)
    get_target_property(_type "${_resolved_target}" TYPE)
    if(NOT _type STREQUAL "EXECUTABLE")
      message(
        FATAL_ERROR
          "MCUX final-link target '${_resolved_target}' must be an executable, not '${_type}'."
      )
    endif()
    target_link_libraries("${_resolved_target}" PRIVATE mcux_sdk_link_options)
  endforeach()

  list(LENGTH _compile_targets _compile_target_count)
  list(LENGTH _link_targets _link_target_count)
  message(
    STATUS
      "Applied target-scoped MCUX flags to ${_compile_target_count} compile target(s) "
      "and ${_link_target_count} final-link target(s).")
endfunction()

if(MCUX_USE_TARGET_SCOPED_FLAGS)
  get_property(
    _mcux_finalizer_scheduled
    GLOBAL
    PROPERTY MCUX_TARGET_FLAGS_FINALIZER_SCHEDULED)
  if(NOT _mcux_finalizer_scheduled)
    set_property(GLOBAL PROPERTY MCUX_TARGET_FLAGS_FINALIZER_SCHEDULED TRUE)
    cmake_language(
      DEFER
      DIRECTORY "${CMAKE_SOURCE_DIR}"
      CALL _mcux_finalize_target_flags)
  endif()
endif()
