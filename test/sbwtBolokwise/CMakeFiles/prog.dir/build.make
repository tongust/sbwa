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
include CMakeFiles/prog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prog.dir/flags.make

CMakeFiles/prog.dir/test.o: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/test.o: test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prog.dir/test.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prog.dir/test.o -c /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/test.cpp

CMakeFiles/prog.dir/test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog.dir/test.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/test.cpp > CMakeFiles/prog.dir/test.i

CMakeFiles/prog.dir/test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog.dir/test.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/test.cpp -o CMakeFiles/prog.dir/test.s

CMakeFiles/prog.dir/test.o.requires:

.PHONY : CMakeFiles/prog.dir/test.o.requires

CMakeFiles/prog.dir/test.o.provides: CMakeFiles/prog.dir/test.o.requires
	$(MAKE) -f CMakeFiles/prog.dir/build.make CMakeFiles/prog.dir/test.o.provides.build
.PHONY : CMakeFiles/prog.dir/test.o.provides

CMakeFiles/prog.dir/test.o.provides.build: CMakeFiles/prog.dir/test.o


CMakeFiles/prog.dir/scr/sbwtBlockwise.o: CMakeFiles/prog.dir/flags.make
CMakeFiles/prog.dir/scr/sbwtBlockwise.o: scr/sbwtBlockwise.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/prog.dir/scr/sbwtBlockwise.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prog.dir/scr/sbwtBlockwise.o -c /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/scr/sbwtBlockwise.cpp

CMakeFiles/prog.dir/scr/sbwtBlockwise.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog.dir/scr/sbwtBlockwise.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/scr/sbwtBlockwise.cpp > CMakeFiles/prog.dir/scr/sbwtBlockwise.i

CMakeFiles/prog.dir/scr/sbwtBlockwise.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog.dir/scr/sbwtBlockwise.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/scr/sbwtBlockwise.cpp -o CMakeFiles/prog.dir/scr/sbwtBlockwise.s

CMakeFiles/prog.dir/scr/sbwtBlockwise.o.requires:

.PHONY : CMakeFiles/prog.dir/scr/sbwtBlockwise.o.requires

CMakeFiles/prog.dir/scr/sbwtBlockwise.o.provides: CMakeFiles/prog.dir/scr/sbwtBlockwise.o.requires
	$(MAKE) -f CMakeFiles/prog.dir/build.make CMakeFiles/prog.dir/scr/sbwtBlockwise.o.provides.build
.PHONY : CMakeFiles/prog.dir/scr/sbwtBlockwise.o.provides

CMakeFiles/prog.dir/scr/sbwtBlockwise.o.provides.build: CMakeFiles/prog.dir/scr/sbwtBlockwise.o


# Object files for target prog
prog_OBJECTS = \
"CMakeFiles/prog.dir/test.o" \
"CMakeFiles/prog.dir/scr/sbwtBlockwise.o"

# External object files for target prog
prog_EXTERNAL_OBJECTS =

prog: CMakeFiles/prog.dir/test.o
prog: CMakeFiles/prog.dir/scr/sbwtBlockwise.o
prog: CMakeFiles/prog.dir/build.make
prog: CMakeFiles/prog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable prog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prog.dir/build: prog

.PHONY : CMakeFiles/prog.dir/build

CMakeFiles/prog.dir/requires: CMakeFiles/prog.dir/test.o.requires
CMakeFiles/prog.dir/requires: CMakeFiles/prog.dir/scr/sbwtBlockwise.o.requires

.PHONY : CMakeFiles/prog.dir/requires

CMakeFiles/prog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prog.dir/clean

CMakeFiles/prog.dir/depend:
	cd /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/test/sbwtBolokwise/CMakeFiles/prog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prog.dir/depend
