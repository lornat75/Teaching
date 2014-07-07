cmake_minimum_required(VERSION 2.6)

project(yarp-basics)

find_package(YARP REQUIRED)

include_directories(${YARP_INCLUDE_DIRS})

add_executable(move_ball move_ball.cpp)
target_link_libraries(move_ball ${YARP_LIBRARIES})

add_executable(object_detector object_detector.cpp)
target_link_libraries(object_detector ${YARP_LIBRARIES})

add_executable(lookAtLocation lookAtLocation.cpp)
target_link_libraries(lookAtLocation ${YARP_LIBRARIES})

install(TARGETS object_detector RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
install(TARGETS move_ball RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
install(TARGETS lookAtLocation RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

