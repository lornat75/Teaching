cmake_minimum_required(VERSION 2.8)
project(gaze-if)

find_package(ICUBcontrib)
list(APPEND CMAKE_MODULE_PATH ${ICUBCONTRIB_MODULE_PATH})
include(ICUBcontribHelpers)
include(ICUBcontribOptions)
icubcontrib_set_default_prefix()

add_subdirectory(mover)
add_subdirectory(detector)
add_subdirectory(tracker)

icubcontrib_add_uninstall_target()
