cmake_minimum_required(VERSION 2.8)

project("Producer Buffered")

find_package(YARP)

include_directories(${YARP_INCLUDE_DIRS})

add_executable(producer-buff producer.cpp)
add_executable(consumer-buff consumer.cpp)

target_link_libraries(producer-buff  ${YARP_LIBRARIES})
target_link_libraries(consumer-buff  ${YARP_LIBRARIES})

install(TARGETS producer-buff RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
install(TARGETS consumer-buff RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)


