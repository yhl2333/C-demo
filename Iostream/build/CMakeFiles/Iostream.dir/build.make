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
CMAKE_SOURCE_DIR = C:\vsproject\AAA\Iostream

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\vsproject\AAA\Iostream\build

# Include any dependencies generated for this target.
include CMakeFiles/Iostream.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Iostream.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Iostream.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Iostream.dir/flags.make

CMakeFiles/Iostream.dir/main.cpp.obj: CMakeFiles/Iostream.dir/flags.make
CMakeFiles/Iostream.dir/main.cpp.obj: C:/vsproject/AAA/Iostream/main.cpp
CMakeFiles/Iostream.dir/main.cpp.obj: CMakeFiles/Iostream.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\vsproject\AAA\Iostream\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Iostream.dir/main.cpp.obj"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Iostream.dir/main.cpp.obj -MF CMakeFiles\Iostream.dir\main.cpp.obj.d -o CMakeFiles\Iostream.dir\main.cpp.obj -c C:\vsproject\AAA\Iostream\main.cpp

CMakeFiles/Iostream.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Iostream.dir/main.cpp.i"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\vsproject\AAA\Iostream\main.cpp > CMakeFiles\Iostream.dir\main.cpp.i

CMakeFiles/Iostream.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Iostream.dir/main.cpp.s"
	C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\vsproject\AAA\Iostream\main.cpp -o CMakeFiles\Iostream.dir\main.cpp.s

# Object files for target Iostream
Iostream_OBJECTS = \
"CMakeFiles/Iostream.dir/main.cpp.obj"

# External object files for target Iostream
Iostream_EXTERNAL_OBJECTS =

Iostream.exe: CMakeFiles/Iostream.dir/main.cpp.obj
Iostream.exe: CMakeFiles/Iostream.dir/build.make
Iostream.exe: CMakeFiles/Iostream.dir/linkLibs.rsp
Iostream.exe: CMakeFiles/Iostream.dir/objects1.rsp
Iostream.exe: CMakeFiles/Iostream.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\vsproject\AAA\Iostream\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Iostream.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Iostream.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Iostream.dir/build: Iostream.exe
.PHONY : CMakeFiles/Iostream.dir/build

CMakeFiles/Iostream.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Iostream.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Iostream.dir/clean

CMakeFiles/Iostream.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\vsproject\AAA\Iostream C:\vsproject\AAA\Iostream C:\vsproject\AAA\Iostream\build C:\vsproject\AAA\Iostream\build C:\vsproject\AAA\Iostream\build\CMakeFiles\Iostream.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Iostream.dir/depend

