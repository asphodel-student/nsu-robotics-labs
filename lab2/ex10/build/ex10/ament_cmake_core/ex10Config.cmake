# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ex10_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ex10_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ex10_FOUND FALSE)
  elseif(NOT ex10_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ex10_FOUND FALSE)
  endif()
  return()
endif()
set(_ex10_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ex10_FIND_QUIETLY)
  message(STATUS "Found ex10: 0.0.0 (${ex10_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ex10' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ex10_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ex10_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ex10_DIR}/${_extra}")
endforeach()
