cmake_minimum_required(VERSION 2.8)

project(rpc)

find_package(YARP)

include_directories(${YARP_INCLUDE_DIRS})

add_executable(rpc-client rpc-client.cpp)

target_link_libraries(rpc-client ${YARP_LIBRARIES})

add_executable(rpc-server rpc-server.cpp)

target_link_libraries(rpc-server ${YARP_LIBRARIES})

install(TARGETS rpc-server
	RUNTIME DESTINATION 	${CMAKE_CURRENT_SOURCE_DIR}/../bin)

install(TARGETS rpc-client
	RUNTIME DESTINATION 	${CMAKE_CURRENT_SOURCE_DIR}/../bin)



