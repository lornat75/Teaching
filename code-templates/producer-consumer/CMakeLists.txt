cmake_minimum_required(VERSION 2.8)

project("Producer")

find_package(YARP)

include_directories(${YARP_INCLUDE_DIRS})

add_executable(producer producer.cpp)
add_executable(consumer consumer.cpp)

target_link_libraries(producer  ${YARP_LIBRARIES})
target_link_libraries(consumer  ${YARP_LIBRARIES})

install(TARGETS producer RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
install(TARGETS consumer RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)


