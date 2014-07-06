cmake_minimum_required(VERSION 2.8)
set(PROJECTNAME tracker)
project(${PROJECTNAME})

find_package(YARP)
find_package(ICUB)
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ICUB_MODULE_PATH})

include_directories(${ICUB_INCLUDE_DIRS} ${YARP_INCLUDE_DIRS})
add_executable(${PROJECTNAME} main.cpp)
target_link_libraries(${PROJECTNAME} icubmod ${YARP_LIBRARIES})
install(TARGETS ${PROJECTNAME} DESTINATION bin)

