cmake_minimum_required(VERSION 2.8)

project(hello_yarp)

find_package(YARP)

include_directories(${YARP_INCLUDE_DIRS})

add_executable(hello_yarp hello_yarp.cpp)

target_link_libraries(hello_yarp ${YARP_LIBRARIES})

install(TARGETS hello_yarp
	RUNTIME DESTINATION 	${CMAKE_CURRENT_SOURCE_DIR}/../bin)


