# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise

# Include any dependencies generated for this target.
include CMakeFiles/BuildIndexBlockwise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BuildIndexBlockwise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BuildIndexBlockwise.dir/flags.make

CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o: CMakeFiles/BuildIndexBlockwise.dir/flags.make
CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o: test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o -c /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/test.cpp

CMakeFiles/BuildIndexBlockwise.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BuildIndexBlockwise.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/test.cpp > CMakeFiles/BuildIndexBlockwise.dir/test.cpp.i

CMakeFiles/BuildIndexBlockwise.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BuildIndexBlockwise.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/test.cpp -o CMakeFiles/BuildIndexBlockwise.dir/test.cpp.s

CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o.requires

CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o.provides: CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/BuildIndexBlockwise.dir/build.make CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o.provides

CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o.provides.build: CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o


CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o: CMakeFiles/BuildIndexBlockwise.dir/flags.make
CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o: src/sbwtBlockwise.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o -c /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/src/sbwtBlockwise.cpp

CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/src/sbwtBlockwise.cpp > CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.i

CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/src/sbwtBlockwise.cpp -o CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.s

CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o.requires:

.PHONY : CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o.requires

CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o.provides: CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o.requires
	$(MAKE) -f CMakeFiles/BuildIndexBlockwise.dir/build.make CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o.provides.build
.PHONY : CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o.provides

CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o.provides.build: CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o


# Object files for target BuildIndexBlockwise
BuildIndexBlockwise_OBJECTS = \
"CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o" \
"CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o"

# External object files for target BuildIndexBlockwise
BuildIndexBlockwise_EXTERNAL_OBJECTS =

BuildIndexBlockwise: CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o
BuildIndexBlockwise: CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o
BuildIndexBlockwise: CMakeFiles/BuildIndexBlockwise.dir/build.make
BuildIndexBlockwise: CMakeFiles/BuildIndexBlockwise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BuildIndexBlockwise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BuildIndexBlockwise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BuildIndexBlockwise.dir/build: BuildIndexBlockwise

.PHONY : CMakeFiles/BuildIndexBlockwise.dir/build

CMakeFiles/BuildIndexBlockwise.dir/requires: CMakeFiles/BuildIndexBlockwise.dir/test.cpp.o.requires
CMakeFiles/BuildIndexBlockwise.dir/requires: CMakeFiles/BuildIndexBlockwise.dir/src/sbwtBlockwise.cpp.o.requires

.PHONY : CMakeFiles/BuildIndexBlockwise.dir/requires

CMakeFiles/BuildIndexBlockwise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BuildIndexBlockwise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BuildIndexBlockwise.dir/clean

CMakeFiles/BuildIndexBlockwise.dir/depend:
	cd /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/CMakeFiles/BuildIndexBlockwise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BuildIndexBlockwise.dir/depend
