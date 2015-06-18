cmake_minimum_required(VERSION 2.8.9)

project("Turtle")

find_package(YARP REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${YARP_INCLUDE_DIRS})
add_executable(turtle main.cpp)

target_link_libraries(turtle ${YARP_LIBRARIES})

install(TARGETS turtle RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)




