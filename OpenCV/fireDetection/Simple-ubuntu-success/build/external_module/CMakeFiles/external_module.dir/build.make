# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/u/yao/fireDetection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/u/yao/fireDetection/build

# Include any dependencies generated for this target.
include external_module/CMakeFiles/external_module.dir/depend.make

# Include the progress variables for this target.
include external_module/CMakeFiles/external_module.dir/progress.make

# Include the compile flags for this target's objects.
include external_module/CMakeFiles/external_module.dir/flags.make

external_module/CMakeFiles/external_module.dir/easylogging++.cc.o: external_module/CMakeFiles/external_module.dir/flags.make
external_module/CMakeFiles/external_module.dir/easylogging++.cc.o: ../external_module/easylogging++.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/u/yao/fireDetection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external_module/CMakeFiles/external_module.dir/easylogging++.cc.o"
	cd /home/u/yao/fireDetection/build/external_module && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/external_module.dir/easylogging++.cc.o -c /home/u/yao/fireDetection/external_module/easylogging++.cc

external_module/CMakeFiles/external_module.dir/easylogging++.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/external_module.dir/easylogging++.cc.i"
	cd /home/u/yao/fireDetection/build/external_module && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u/yao/fireDetection/external_module/easylogging++.cc > CMakeFiles/external_module.dir/easylogging++.cc.i

external_module/CMakeFiles/external_module.dir/easylogging++.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/external_module.dir/easylogging++.cc.s"
	cd /home/u/yao/fireDetection/build/external_module && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u/yao/fireDetection/external_module/easylogging++.cc -o CMakeFiles/external_module.dir/easylogging++.cc.s

external_module/CMakeFiles/external_module.dir/easylogging++.cc.o.requires:

.PHONY : external_module/CMakeFiles/external_module.dir/easylogging++.cc.o.requires

external_module/CMakeFiles/external_module.dir/easylogging++.cc.o.provides: external_module/CMakeFiles/external_module.dir/easylogging++.cc.o.requires
	$(MAKE) -f external_module/CMakeFiles/external_module.dir/build.make external_module/CMakeFiles/external_module.dir/easylogging++.cc.o.provides.build
.PHONY : external_module/CMakeFiles/external_module.dir/easylogging++.cc.o.provides

external_module/CMakeFiles/external_module.dir/easylogging++.cc.o.provides.build: external_module/CMakeFiles/external_module.dir/easylogging++.cc.o


# Object files for target external_module
external_module_OBJECTS = \
"CMakeFiles/external_module.dir/easylogging++.cc.o"

# External object files for target external_module
external_module_EXTERNAL_OBJECTS =

external_module/libexternal_module.a: external_module/CMakeFiles/external_module.dir/easylogging++.cc.o
external_module/libexternal_module.a: external_module/CMakeFiles/external_module.dir/build.make
external_module/libexternal_module.a: external_module/CMakeFiles/external_module.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/u/yao/fireDetection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libexternal_module.a"
	cd /home/u/yao/fireDetection/build/external_module && $(CMAKE_COMMAND) -P CMakeFiles/external_module.dir/cmake_clean_target.cmake
	cd /home/u/yao/fireDetection/build/external_module && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/external_module.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external_module/CMakeFiles/external_module.dir/build: external_module/libexternal_module.a

.PHONY : external_module/CMakeFiles/external_module.dir/build

external_module/CMakeFiles/external_module.dir/requires: external_module/CMakeFiles/external_module.dir/easylogging++.cc.o.requires

.PHONY : external_module/CMakeFiles/external_module.dir/requires

external_module/CMakeFiles/external_module.dir/clean:
	cd /home/u/yao/fireDetection/build/external_module && $(CMAKE_COMMAND) -P CMakeFiles/external_module.dir/cmake_clean.cmake
.PHONY : external_module/CMakeFiles/external_module.dir/clean

external_module/CMakeFiles/external_module.dir/depend:
	cd /home/u/yao/fireDetection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/u/yao/fireDetection /home/u/yao/fireDetection/external_module /home/u/yao/fireDetection/build /home/u/yao/fireDetection/build/external_module /home/u/yao/fireDetection/build/external_module/CMakeFiles/external_module.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external_module/CMakeFiles/external_module.dir/depend

