# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\anton\Desktop\EDA2_2.2020

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/menoresPlacas.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/menoresPlacas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/menoresPlacas.dir/flags.make

CMakeFiles/menoresPlacas.dir/menoresPlacas.c.obj: CMakeFiles/menoresPlacas.dir/flags.make
CMakeFiles/menoresPlacas.dir/menoresPlacas.c.obj: ../menoresPlacas.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/menoresPlacas.dir/menoresPlacas.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\menoresPlacas.dir\menoresPlacas.c.obj -c C:\Users\anton\Desktop\EDA2_2.2020\menoresPlacas.c

CMakeFiles/menoresPlacas.dir/menoresPlacas.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/menoresPlacas.dir/menoresPlacas.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\anton\Desktop\EDA2_2.2020\menoresPlacas.c > CMakeFiles\menoresPlacas.dir\menoresPlacas.c.i

CMakeFiles/menoresPlacas.dir/menoresPlacas.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/menoresPlacas.dir/menoresPlacas.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\anton\Desktop\EDA2_2.2020\menoresPlacas.c -o CMakeFiles\menoresPlacas.dir\menoresPlacas.c.s

# Object files for target menoresPlacas
menoresPlacas_OBJECTS = \
"CMakeFiles/menoresPlacas.dir/menoresPlacas.c.obj"

# External object files for target menoresPlacas
menoresPlacas_EXTERNAL_OBJECTS =

menoresPlacas.exe: CMakeFiles/menoresPlacas.dir/menoresPlacas.c.obj
menoresPlacas.exe: CMakeFiles/menoresPlacas.dir/build.make
menoresPlacas.exe: CMakeFiles/menoresPlacas.dir/linklibs.rsp
menoresPlacas.exe: CMakeFiles/menoresPlacas.dir/objects1.rsp
menoresPlacas.exe: CMakeFiles/menoresPlacas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable menoresPlacas.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\menoresPlacas.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/menoresPlacas.dir/build: menoresPlacas.exe
.PHONY : CMakeFiles/menoresPlacas.dir/build

CMakeFiles/menoresPlacas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\menoresPlacas.dir\cmake_clean.cmake
.PHONY : CMakeFiles/menoresPlacas.dir/clean

CMakeFiles/menoresPlacas.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\anton\Desktop\EDA2_2.2020 C:\Users\anton\Desktop\EDA2_2.2020 C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles\menoresPlacas.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/menoresPlacas.dir/depend

