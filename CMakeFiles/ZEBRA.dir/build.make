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
CMAKE_SOURCE_DIR = /home/tongust/Program/cpp/sbwt/sbwa-buildIndex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tongust/Program/cpp/sbwt/sbwa-buildIndex

# Include any dependencies generated for this target.
include CMakeFiles/ZEBRA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ZEBRA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ZEBRA.dir/flags.make

CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o: CMakeFiles/ZEBRA.dir/flags.make
CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o: buildIndexMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tongust/Program/cpp/sbwt/sbwa-buildIndex/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o -c /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/buildIndexMain.cpp

CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/buildIndexMain.cpp > CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.i

CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/buildIndexMain.cpp -o CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.s

CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o.requires:

.PHONY : CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o.requires

CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o.provides: CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o.requires
	$(MAKE) -f CMakeFiles/ZEBRA.dir/build.make CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o.provides.build
.PHONY : CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o.provides

CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o.provides.build: CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o


# Object files for target ZEBRA
ZEBRA_OBJECTS = \
"CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o"

# External object files for target ZEBRA
ZEBRA_EXTERNAL_OBJECTS =

ZEBRA: CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o
ZEBRA: CMakeFiles/ZEBRA.dir/build.make
ZEBRA: /usr/lib/x86_64-linux-gnu/libz.so
ZEBRA: CMakeFiles/ZEBRA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tongust/Program/cpp/sbwt/sbwa-buildIndex/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ZEBRA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ZEBRA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ZEBRA.dir/build: ZEBRA

.PHONY : CMakeFiles/ZEBRA.dir/build

CMakeFiles/ZEBRA.dir/requires: CMakeFiles/ZEBRA.dir/buildIndexMain.cpp.o.requires

.PHONY : CMakeFiles/ZEBRA.dir/requires

CMakeFiles/ZEBRA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ZEBRA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ZEBRA.dir/clean

CMakeFiles/ZEBRA.dir/depend:
	cd /home/tongust/Program/cpp/sbwt/sbwa-buildIndex && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tongust/Program/cpp/sbwt/sbwa-buildIndex /home/tongust/Program/cpp/sbwt/sbwa-buildIndex /home/tongust/Program/cpp/sbwt/sbwa-buildIndex /home/tongust/Program/cpp/sbwt/sbwa-buildIndex /home/tongust/Program/cpp/sbwt/sbwa-buildIndex/CMakeFiles/ZEBRA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ZEBRA.dir/depend

