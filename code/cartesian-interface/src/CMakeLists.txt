cmake_minimum_required(VERSION 2.8.9)
project(cartesian-interface)

find_package(YARP)
find_package(ICUB)
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
list(APPEND CMAKE_MODULE_PATH ${ICUB_MODULE_PATH})

# import math symbols from standard cmath
add_definitions(-D_USE_MATH_DEFINES)

include_directories(${ICUB_INCLUDE_DIRS} ${YARP_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${YARP_LIBRARIES})
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
