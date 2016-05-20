cmake_minimum_required(VERSION 2.6)

project(icub-vision)

find_package(YARP REQUIRED)

find_package(OpenCV REQUIRED)

include_directories(${YARP_INCLUDE_DIRS})

add_executable(move_ball move_ball.cpp)
target_link_libraries(move_ball ${YARP_LIBRARIES})

add_executable(object_detector object_detector.cpp)
target_link_libraries(object_detector ${YARP_LIBRARIES} ${OpenCV_LIBS})

add_executable(look_at look_at.cpp)
target_link_libraries(look_at ${YARP_LIBRARIES})

install(TARGETS object_detector RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
install(TARGETS move_ball RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
install(TARGETS look_at RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

install(FILES ${CMAKE_SOURCE_DIR}/app/icub-vision.xml DESTINATION ${CMAKE_SOURCE_DIR}/../bin)


