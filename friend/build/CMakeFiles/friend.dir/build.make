# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\vsproject\AAA\friend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\vsproject\AAA\friend\build

# Include any dependencies generated for this target.
include CMakeFiles/friend.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/friend.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/friend.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/friend.dir/flags.make

CMakeFiles/friend.dir/main.cpp.obj: CMakeFiles/friend.dir/flags.make
CMakeFiles/friend.dir/main.cpp.obj: C:/vsproject/AAA/friend/main.cpp
CMakeFiles/friend.dir/main.cpp.obj: CMakeFiles/friend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\vsproject\AAA\friend\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/friend.dir/main.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/friend.dir/main.cpp.obj -MF CMakeFiles\friend.dir\main.cpp.obj.d -o CMakeFiles\friend.dir\main.cpp.obj -c C:\vsproject\AAA\friend\main.cpp

CMakeFiles/friend.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/friend.dir/main.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\vsproject\AAA\friend\main.cpp > CMakeFiles\friend.dir\main.cpp.i

CMakeFiles/friend.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/friend.dir/main.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\vsproject\AAA\friend\main.cpp -o CMakeFiles\friend.dir\main.cpp.s

# Object files for target friend
friend_OBJECTS = \
"CMakeFiles/friend.dir/main.cpp.obj"

# External object files for target friend
friend_EXTERNAL_OBJECTS =

friend.exe: CMakeFiles/friend.dir/main.cpp.obj
friend.exe: CMakeFiles/friend.dir/build.make
friend.exe: CMakeFiles/friend.dir/linkLibs.rsp
friend.exe: CMakeFiles/friend.dir/objects1.rsp
friend.exe: CMakeFiles/friend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\vsproject\AAA\friend\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable friend.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\friend.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/friend.dir/build: friend.exe
.PHONY : CMakeFiles/friend.dir/build

CMakeFiles/friend.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\friend.dir\cmake_clean.cmake
.PHONY : CMakeFiles/friend.dir/clean

CMakeFiles/friend.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\vsproject\AAA\friend C:\vsproject\AAA\friend C:\vsproject\AAA\friend\build C:\vsproject\AAA\friend\build C:\vsproject\AAA\friend\build\CMakeFiles\friend.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/friend.dir/depend

