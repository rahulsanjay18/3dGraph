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
CMAKE_SOURCE_DIR = /home/rahul/Documents/3dGraph/graph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rahul/Documents/3dGraph/graph

# Include any dependencies generated for this target.
include CMakeFiles/UrhoGrapher.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UrhoGrapher.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UrhoGrapher.dir/flags.make

CMakeFiles/UrhoGrapher.dir/main.cpp.o: CMakeFiles/UrhoGrapher.dir/flags.make
CMakeFiles/UrhoGrapher.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rahul/Documents/3dGraph/graph/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UrhoGrapher.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UrhoGrapher.dir/main.cpp.o -c /home/rahul/Documents/3dGraph/graph/main.cpp

CMakeFiles/UrhoGrapher.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UrhoGrapher.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rahul/Documents/3dGraph/graph/main.cpp > CMakeFiles/UrhoGrapher.dir/main.cpp.i

CMakeFiles/UrhoGrapher.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UrhoGrapher.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rahul/Documents/3dGraph/graph/main.cpp -o CMakeFiles/UrhoGrapher.dir/main.cpp.s

CMakeFiles/UrhoGrapher.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/UrhoGrapher.dir/main.cpp.o.requires

CMakeFiles/UrhoGrapher.dir/main.cpp.o.provides: CMakeFiles/UrhoGrapher.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/UrhoGrapher.dir/build.make CMakeFiles/UrhoGrapher.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/UrhoGrapher.dir/main.cpp.o.provides

CMakeFiles/UrhoGrapher.dir/main.cpp.o.provides.build: CMakeFiles/UrhoGrapher.dir/main.cpp.o


CMakeFiles/UrhoGrapher.dir/math.cpp.o: CMakeFiles/UrhoGrapher.dir/flags.make
CMakeFiles/UrhoGrapher.dir/math.cpp.o: math.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rahul/Documents/3dGraph/graph/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/UrhoGrapher.dir/math.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UrhoGrapher.dir/math.cpp.o -c /home/rahul/Documents/3dGraph/graph/math.cpp

CMakeFiles/UrhoGrapher.dir/math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UrhoGrapher.dir/math.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rahul/Documents/3dGraph/graph/math.cpp > CMakeFiles/UrhoGrapher.dir/math.cpp.i

CMakeFiles/UrhoGrapher.dir/math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UrhoGrapher.dir/math.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rahul/Documents/3dGraph/graph/math.cpp -o CMakeFiles/UrhoGrapher.dir/math.cpp.s

CMakeFiles/UrhoGrapher.dir/math.cpp.o.requires:

.PHONY : CMakeFiles/UrhoGrapher.dir/math.cpp.o.requires

CMakeFiles/UrhoGrapher.dir/math.cpp.o.provides: CMakeFiles/UrhoGrapher.dir/math.cpp.o.requires
	$(MAKE) -f CMakeFiles/UrhoGrapher.dir/build.make CMakeFiles/UrhoGrapher.dir/math.cpp.o.provides.build
.PHONY : CMakeFiles/UrhoGrapher.dir/math.cpp.o.provides

CMakeFiles/UrhoGrapher.dir/math.cpp.o.provides.build: CMakeFiles/UrhoGrapher.dir/math.cpp.o


# Object files for target UrhoGrapher
UrhoGrapher_OBJECTS = \
"CMakeFiles/UrhoGrapher.dir/main.cpp.o" \
"CMakeFiles/UrhoGrapher.dir/math.cpp.o"

# External object files for target UrhoGrapher
UrhoGrapher_EXTERNAL_OBJECTS =

bin/UrhoGrapher: CMakeFiles/UrhoGrapher.dir/main.cpp.o
bin/UrhoGrapher: CMakeFiles/UrhoGrapher.dir/math.cpp.o
bin/UrhoGrapher: CMakeFiles/UrhoGrapher.dir/build.make
bin/UrhoGrapher: /home/rahul/Documents/Urho3D-1.7/lib/libUrho3D.a
bin/UrhoGrapher: CMakeFiles/UrhoGrapher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rahul/Documents/3dGraph/graph/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/UrhoGrapher"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UrhoGrapher.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/strip /home/rahul/Documents/3dGraph/graph/bin/UrhoGrapher

# Rule to build all files generated by this target.
CMakeFiles/UrhoGrapher.dir/build: bin/UrhoGrapher

.PHONY : CMakeFiles/UrhoGrapher.dir/build

CMakeFiles/UrhoGrapher.dir/requires: CMakeFiles/UrhoGrapher.dir/main.cpp.o.requires
CMakeFiles/UrhoGrapher.dir/requires: CMakeFiles/UrhoGrapher.dir/math.cpp.o.requires

.PHONY : CMakeFiles/UrhoGrapher.dir/requires

CMakeFiles/UrhoGrapher.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UrhoGrapher.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UrhoGrapher.dir/clean

CMakeFiles/UrhoGrapher.dir/depend:
	cd /home/rahul/Documents/3dGraph/graph && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rahul/Documents/3dGraph/graph /home/rahul/Documents/3dGraph/graph /home/rahul/Documents/3dGraph/graph /home/rahul/Documents/3dGraph/graph /home/rahul/Documents/3dGraph/graph/CMakeFiles/UrhoGrapher.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UrhoGrapher.dir/depend

