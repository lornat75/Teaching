cmake_minimum_required(VERSION 2.8)
set(PROJECTNAME mover)
project(${PROJECTNAME})

find_package(YARP)
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
find_package(GSL)

include_directories(${GSL_INCLUDE_DIRS} ${YARP_INCLUDE_DIRS})
add_executable(${PROJECTNAME} main.cpp)
target_link_libraries(${PROJECTNAME} ${GSL_LIBRARIES} ${YARP_LIBRARIES})
install(TARGETS ${PROJECTNAME} DESTINATION bin)
