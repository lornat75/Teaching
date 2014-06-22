cmake_minimum_required(VERSION 2.8)


project(hello)

message(STATUS "--> Hello from cmake")

if (WIN32)
	message(STATUS "--> running on windows")
else()
	message(STATUS "--> running elsewhere")
endif()

message(STATUS "Running from ${CMAKE_CURRENT_SOURCE_DIR}")

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/hello.cpp")
	message(FATAL_ERROR "File hello.cpp not found!")
endif()

option(ENABLE_DEBUG boolean)

If (ENABLE_DEBUG)
    add_definitions(-D_ENABLE_DEBUG_)
endif()

add_executable(hello hello.cpp)

install(TARGETS hello RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)











	