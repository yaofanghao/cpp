# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/yao/hello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/yao/hello/build

# Include any dependencies generated for this target.
include CMakeFiles/helloWorld_cmake.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/helloWorld_cmake.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/helloWorld_cmake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/helloWorld_cmake.dir/flags.make

CMakeFiles/helloWorld_cmake.dir/hello.cpp.o: CMakeFiles/helloWorld_cmake.dir/flags.make
CMakeFiles/helloWorld_cmake.dir/hello.cpp.o: /home/ubuntu/yao/hello/hello.cpp
CMakeFiles/helloWorld_cmake.dir/hello.cpp.o: CMakeFiles/helloWorld_cmake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/yao/hello/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/helloWorld_cmake.dir/hello.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/helloWorld_cmake.dir/hello.cpp.o -MF CMakeFiles/helloWorld_cmake.dir/hello.cpp.o.d -o CMakeFiles/helloWorld_cmake.dir/hello.cpp.o -c /home/ubuntu/yao/hello/hello.cpp

CMakeFiles/helloWorld_cmake.dir/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloWorld_cmake.dir/hello.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/yao/hello/hello.cpp > CMakeFiles/helloWorld_cmake.dir/hello.cpp.i

CMakeFiles/helloWorld_cmake.dir/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloWorld_cmake.dir/hello.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/yao/hello/hello.cpp -o CMakeFiles/helloWorld_cmake.dir/hello.cpp.s

# Object files for target helloWorld_cmake
helloWorld_cmake_OBJECTS = \
"CMakeFiles/helloWorld_cmake.dir/hello.cpp.o"

# External object files for target helloWorld_cmake
helloWorld_cmake_EXTERNAL_OBJECTS =

helloWorld_cmake: CMakeFiles/helloWorld_cmake.dir/hello.cpp.o
helloWorld_cmake: CMakeFiles/helloWorld_cmake.dir/build.make
helloWorld_cmake: CMakeFiles/helloWorld_cmake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/yao/hello/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable helloWorld_cmake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/helloWorld_cmake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/helloWorld_cmake.dir/build: helloWorld_cmake
.PHONY : CMakeFiles/helloWorld_cmake.dir/build

CMakeFiles/helloWorld_cmake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/helloWorld_cmake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/helloWorld_cmake.dir/clean

CMakeFiles/helloWorld_cmake.dir/depend:
	cd /home/ubuntu/yao/hello/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/yao/hello /home/ubuntu/yao/hello /home/ubuntu/yao/hello/build /home/ubuntu/yao/hello/build /home/ubuntu/yao/hello/build/CMakeFiles/helloWorld_cmake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/helloWorld_cmake.dir/depend

