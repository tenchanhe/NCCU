# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/tenchanhe/CG/hw3-swgl-trans

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tenchanhe/CG/hw3-swgl-trans/build

# Include any dependencies generated for this target.
include CMakeFiles/trans.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/trans.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trans.dir/flags.make

CMakeFiles/trans.dir/main.cpp.o: CMakeFiles/trans.dir/flags.make
CMakeFiles/trans.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tenchanhe/CG/hw3-swgl-trans/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/trans.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/trans.dir/main.cpp.o -c /home/tenchanhe/CG/hw3-swgl-trans/main.cpp

CMakeFiles/trans.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/trans.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tenchanhe/CG/hw3-swgl-trans/main.cpp > CMakeFiles/trans.dir/main.cpp.i

CMakeFiles/trans.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/trans.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tenchanhe/CG/hw3-swgl-trans/main.cpp -o CMakeFiles/trans.dir/main.cpp.s

# Object files for target trans
trans_OBJECTS = \
"CMakeFiles/trans.dir/main.cpp.o"

# External object files for target trans
trans_EXTERNAL_OBJECTS =

trans: CMakeFiles/trans.dir/main.cpp.o
trans: CMakeFiles/trans.dir/build.make
trans: /usr/lib/x86_64-linux-gnu/libGL.so
trans: /usr/lib/x86_64-linux-gnu/libGLU.so
trans: CMakeFiles/trans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tenchanhe/CG/hw3-swgl-trans/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable trans"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trans.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trans.dir/build: trans

.PHONY : CMakeFiles/trans.dir/build

CMakeFiles/trans.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/trans.dir/cmake_clean.cmake
.PHONY : CMakeFiles/trans.dir/clean

CMakeFiles/trans.dir/depend:
	cd /home/tenchanhe/CG/hw3-swgl-trans/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tenchanhe/CG/hw3-swgl-trans /home/tenchanhe/CG/hw3-swgl-trans /home/tenchanhe/CG/hw3-swgl-trans/build /home/tenchanhe/CG/hw3-swgl-trans/build /home/tenchanhe/CG/hw3-swgl-trans/build/CMakeFiles/trans.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/trans.dir/depend

