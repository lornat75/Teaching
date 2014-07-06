cmake_minimum_required(VERSION 2.8)
set(PROJECTNAME detector)
project(${PROJECTNAME})

find_package(YARP)
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})

include_directories(${YARP_INCLUDE_DIRS})
add_executable(${PROJECTNAME} objectDetector.cpp Detector.cpp Detector.h)
target_link_libraries(${PROJECTNAME} ${YARP_LIBRARIES})
install(TARGETS ${PROJECTNAME} DESTINATION bin)

