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
CMAKE_COMMAND = /opt/clion-2020.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.1.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/seadragnol/CLionProjects/findStreet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seadragnol/CLionProjects/findStreet/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/findStreet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/findStreet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/findStreet.dir/flags.make

CMakeFiles/findStreet.dir/main.cpp.o: CMakeFiles/findStreet.dir/flags.make
CMakeFiles/findStreet.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/seadragnol/CLionProjects/findStreet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/findStreet.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/findStreet.dir/main.cpp.o -c /home/seadragnol/CLionProjects/findStreet/main.cpp

CMakeFiles/findStreet.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/findStreet.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/seadragnol/CLionProjects/findStreet/main.cpp > CMakeFiles/findStreet.dir/main.cpp.i

CMakeFiles/findStreet.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/findStreet.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/seadragnol/CLionProjects/findStreet/main.cpp -o CMakeFiles/findStreet.dir/main.cpp.s

# Object files for target findStreet
findStreet_OBJECTS = \
"CMakeFiles/findStreet.dir/main.cpp.o"

# External object files for target findStreet
findStreet_EXTERNAL_OBJECTS =

findStreet: CMakeFiles/findStreet.dir/main.cpp.o
findStreet: CMakeFiles/findStreet.dir/build.make
findStreet: CMakeFiles/findStreet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/seadragnol/CLionProjects/findStreet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable findStreet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/findStreet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/findStreet.dir/build: findStreet

.PHONY : CMakeFiles/findStreet.dir/build

CMakeFiles/findStreet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/findStreet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/findStreet.dir/clean

CMakeFiles/findStreet.dir/depend:
	cd /home/seadragnol/CLionProjects/findStreet/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/seadragnol/CLionProjects/findStreet /home/seadragnol/CLionProjects/findStreet /home/seadragnol/CLionProjects/findStreet/cmake-build-debug /home/seadragnol/CLionProjects/findStreet/cmake-build-debug /home/seadragnol/CLionProjects/findStreet/cmake-build-debug/CMakeFiles/findStreet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/findStreet.dir/depend

