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
include CMakeFiles/olaMundo.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/olaMundo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/olaMundo.dir/flags.make

CMakeFiles/olaMundo.dir/olaMundo.c.obj: CMakeFiles/olaMundo.dir/flags.make
CMakeFiles/olaMundo.dir/olaMundo.c.obj: ../olaMundo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/olaMundo.dir/olaMundo.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\olaMundo.dir\olaMundo.c.obj -c C:\Users\anton\Desktop\EDA2_2.2020\olaMundo.c

CMakeFiles/olaMundo.dir/olaMundo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/olaMundo.dir/olaMundo.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\anton\Desktop\EDA2_2.2020\olaMundo.c > CMakeFiles\olaMundo.dir\olaMundo.c.i

CMakeFiles/olaMundo.dir/olaMundo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/olaMundo.dir/olaMundo.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\anton\Desktop\EDA2_2.2020\olaMundo.c -o CMakeFiles\olaMundo.dir\olaMundo.c.s

# Object files for target olaMundo
olaMundo_OBJECTS = \
"CMakeFiles/olaMundo.dir/olaMundo.c.obj"

# External object files for target olaMundo
olaMundo_EXTERNAL_OBJECTS =

olaMundo.exe: CMakeFiles/olaMundo.dir/olaMundo.c.obj
olaMundo.exe: CMakeFiles/olaMundo.dir/build.make
olaMundo.exe: CMakeFiles/olaMundo.dir/linklibs.rsp
olaMundo.exe: CMakeFiles/olaMundo.dir/objects1.rsp
olaMundo.exe: CMakeFiles/olaMundo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable olaMundo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\olaMundo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/olaMundo.dir/build: olaMundo.exe
.PHONY : CMakeFiles/olaMundo.dir/build

CMakeFiles/olaMundo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\olaMundo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/olaMundo.dir/clean

CMakeFiles/olaMundo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\anton\Desktop\EDA2_2.2020 C:\Users\anton\Desktop\EDA2_2.2020 C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles\olaMundo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/olaMundo.dir/depend

