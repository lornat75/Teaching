cmake_minimum_required(VERSION 2.6)

project(yarp-basics)

find_package(YARP REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${YARP_INCLUDE_DIRS})

add_executable(opencv opencv.cpp)
target_link_libraries(opencv ${YARP_LIBRARIES} ${OpenCV_LIBRARIES})

install(TARGETS opencv RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

