# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_asphodel_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED asphodel_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(asphodel_FOUND FALSE)
  elseif(NOT asphodel_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(asphodel_FOUND FALSE)
  endif()
  return()
endif()
set(_asphodel_CONFIG_INCLUDED TRUE)

# output package information
if(NOT asphodel_FIND_QUIETLY)
  message(STATUS "Found asphodel: 0.0.0 (${asphodel_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'asphodel' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${asphodel_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(asphodel_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${asphodel_DIR}/${_extra}")
endforeach()
