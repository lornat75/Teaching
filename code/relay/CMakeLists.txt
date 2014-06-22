cmake_minimum_required(VERSION 2.8)

set(projectname relay)

project(${projectname})

find_package(YARP)

include_directories(${YARP_INCLUDE_DIRS})

add_executable(${projectname} relay.cpp)

target_link_libraries(${projectname} ${YARP_LIBRARIES})

install(TARGETS ${projectname} RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

