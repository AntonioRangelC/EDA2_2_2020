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
include CMakeFiles/numMalucos_180098021.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/numMalucos_180098021.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/numMalucos_180098021.dir/flags.make

CMakeFiles/numMalucos_180098021.dir/numMalucos_180098021.c.obj: CMakeFiles/numMalucos_180098021.dir/flags.make
CMakeFiles/numMalucos_180098021.dir/numMalucos_180098021.c.obj: ../numMalucos_180098021.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/numMalucos_180098021.dir/numMalucos_180098021.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\numMalucos_180098021.dir\numMalucos_180098021.c.obj -c C:\Users\anton\Desktop\EDA2_2.2020\numMalucos_180098021.c

CMakeFiles/numMalucos_180098021.dir/numMalucos_180098021.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/numMalucos_180098021.dir/numMalucos_180098021.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\anton\Desktop\EDA2_2.2020\numMalucos_180098021.c > CMakeFiles\numMalucos_180098021.dir\numMalucos_180098021.c.i

CMakeFiles/numMalucos_180098021.dir/numMalucos_180098021.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/numMalucos_180098021.dir/numMalucos_180098021.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\anton\Desktop\EDA2_2.2020\numMalucos_180098021.c -o CMakeFiles\numMalucos_180098021.dir\numMalucos_180098021.c.s

# Object files for target numMalucos_180098021
numMalucos_180098021_OBJECTS = \
"CMakeFiles/numMalucos_180098021.dir/numMalucos_180098021.c.obj"

# External object files for target numMalucos_180098021
numMalucos_180098021_EXTERNAL_OBJECTS =

numMalucos_180098021.exe: CMakeFiles/numMalucos_180098021.dir/numMalucos_180098021.c.obj
numMalucos_180098021.exe: CMakeFiles/numMalucos_180098021.dir/build.make
numMalucos_180098021.exe: CMakeFiles/numMalucos_180098021.dir/linklibs.rsp
numMalucos_180098021.exe: CMakeFiles/numMalucos_180098021.dir/objects1.rsp
numMalucos_180098021.exe: CMakeFiles/numMalucos_180098021.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable numMalucos_180098021.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\numMalucos_180098021.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/numMalucos_180098021.dir/build: numMalucos_180098021.exe
.PHONY : CMakeFiles/numMalucos_180098021.dir/build

CMakeFiles/numMalucos_180098021.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\numMalucos_180098021.dir\cmake_clean.cmake
.PHONY : CMakeFiles/numMalucos_180098021.dir/clean

CMakeFiles/numMalucos_180098021.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\anton\Desktop\EDA2_2.2020 C:\Users\anton\Desktop\EDA2_2.2020 C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles\numMalucos_180098021.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/numMalucos_180098021.dir/depend

