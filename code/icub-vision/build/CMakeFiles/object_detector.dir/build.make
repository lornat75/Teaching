# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/icub/dev/Teaching/code/icubVision

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/icub/dev/Teaching/code/icubVision/build

# Include any dependencies generated for this target.
include CMakeFiles/object_detector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/object_detector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/object_detector.dir/flags.make

CMakeFiles/object_detector.dir/object_detector.cpp.o: CMakeFiles/object_detector.dir/flags.make
CMakeFiles/object_detector.dir/object_detector.cpp.o: ../object_detector.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/icub/dev/Teaching/code/icubVision/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/object_detector.dir/object_detector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/object_detector.dir/object_detector.cpp.o -c /home/icub/dev/Teaching/code/icubVision/object_detector.cpp

CMakeFiles/object_detector.dir/object_detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/object_detector.dir/object_detector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/icub/dev/Teaching/code/icubVision/object_detector.cpp > CMakeFiles/object_detector.dir/object_detector.cpp.i

CMakeFiles/object_detector.dir/object_detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/object_detector.dir/object_detector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/icub/dev/Teaching/code/icubVision/object_detector.cpp -o CMakeFiles/object_detector.dir/object_detector.cpp.s

CMakeFiles/object_detector.dir/object_detector.cpp.o.requires:
.PHONY : CMakeFiles/object_detector.dir/object_detector.cpp.o.requires

CMakeFiles/object_detector.dir/object_detector.cpp.o.provides: CMakeFiles/object_detector.dir/object_detector.cpp.o.requires
	$(MAKE) -f CMakeFiles/object_detector.dir/build.make CMakeFiles/object_detector.dir/object_detector.cpp.o.provides.build
.PHONY : CMakeFiles/object_detector.dir/object_detector.cpp.o.provides

CMakeFiles/object_detector.dir/object_detector.cpp.o.provides.build: CMakeFiles/object_detector.dir/object_detector.cpp.o

# Object files for target object_detector
object_detector_OBJECTS = \
"CMakeFiles/object_detector.dir/object_detector.cpp.o"

# External object files for target object_detector
object_detector_EXTERNAL_OBJECTS =

object_detector: CMakeFiles/object_detector.dir/object_detector.cpp.o
object_detector: CMakeFiles/object_detector.dir/build.make
object_detector: /usr/local/lib/libYARP_OS.so.2.3.63.7
object_detector: /usr/local/lib/libYARP_sig.so.2.3.63.7
object_detector: /usr/local/lib/libYARP_math.so.2.3.63.7
object_detector: /usr/local/lib/libYARP_dev.so.2.3.63.7
object_detector: /usr/local/lib/libYARP_name.so.2.3.63.7
object_detector: /usr/local/lib/libYARP_init.so.2.3.63.7
object_detector: /usr/local/lib/libYARP_sig.so.2.3.63.7
object_detector: /usr/local/lib/libYARP_OS.so.2.3.63.7
object_detector: CMakeFiles/object_detector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable object_detector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/object_detector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/object_detector.dir/build: object_detector
.PHONY : CMakeFiles/object_detector.dir/build

CMakeFiles/object_detector.dir/requires: CMakeFiles/object_detector.dir/object_detector.cpp.o.requires
.PHONY : CMakeFiles/object_detector.dir/requires

CMakeFiles/object_detector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/object_detector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/object_detector.dir/clean

CMakeFiles/object_detector.dir/depend:
	cd /home/icub/dev/Teaching/code/icubVision/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/icub/dev/Teaching/code/icubVision /home/icub/dev/Teaching/code/icubVision /home/icub/dev/Teaching/code/icubVision/build /home/icub/dev/Teaching/code/icubVision/build /home/icub/dev/Teaching/code/icubVision/build/CMakeFiles/object_detector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/object_detector.dir/depend

