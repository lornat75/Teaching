# Install script for directory: /home/icub/dev/Teaching/code/icubVision

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/object_detector" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/object_detector")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/object_detector"
         RPATH "")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/icub/dev/Teaching/code/icubVision/../bin/object_detector")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/icub/dev/Teaching/code/icubVision/../bin" TYPE EXECUTABLE FILES "/home/icub/dev/Teaching/code/icubVision/build/object_detector")
  IF(EXISTS "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/object_detector" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/object_detector")
    FILE(RPATH_REMOVE
         FILE "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/object_detector")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/object_detector")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/move_ball" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/move_ball")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/move_ball"
         RPATH "")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/icub/dev/Teaching/code/icubVision/../bin/move_ball")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/icub/dev/Teaching/code/icubVision/../bin" TYPE EXECUTABLE FILES "/home/icub/dev/Teaching/code/icubVision/build/move_ball")
  IF(EXISTS "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/move_ball" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/move_ball")
    FILE(RPATH_REMOVE
         FILE "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/move_ball")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/move_ball")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/lookAtLocation" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/lookAtLocation")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/lookAtLocation"
         RPATH "")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/icub/dev/Teaching/code/icubVision/../bin/lookAtLocation")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/icub/dev/Teaching/code/icubVision/../bin" TYPE EXECUTABLE FILES "/home/icub/dev/Teaching/code/icubVision/build/lookAtLocation")
  IF(EXISTS "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/lookAtLocation" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/lookAtLocation")
    FILE(RPATH_REMOVE
         FILE "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/lookAtLocation")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/icub/dev/Teaching/code/icubVision/../bin/lookAtLocation")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/icub/dev/Teaching/code/icubVision/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/icub/dev/Teaching/code/icubVision/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
