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
include CMakeFiles/desfilePatos.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/desfilePatos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/desfilePatos.dir/flags.make

CMakeFiles/desfilePatos.dir/desfilePatos.c.obj: CMakeFiles/desfilePatos.dir/flags.make
CMakeFiles/desfilePatos.dir/desfilePatos.c.obj: ../desfilePatos.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/desfilePatos.dir/desfilePatos.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\desfilePatos.dir\desfilePatos.c.obj -c C:\Users\anton\Desktop\EDA2_2.2020\desfilePatos.c

CMakeFiles/desfilePatos.dir/desfilePatos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/desfilePatos.dir/desfilePatos.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\anton\Desktop\EDA2_2.2020\desfilePatos.c > CMakeFiles\desfilePatos.dir\desfilePatos.c.i

CMakeFiles/desfilePatos.dir/desfilePatos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/desfilePatos.dir/desfilePatos.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\anton\Desktop\EDA2_2.2020\desfilePatos.c -o CMakeFiles\desfilePatos.dir\desfilePatos.c.s

# Object files for target desfilePatos
desfilePatos_OBJECTS = \
"CMakeFiles/desfilePatos.dir/desfilePatos.c.obj"

# External object files for target desfilePatos
desfilePatos_EXTERNAL_OBJECTS =

desfilePatos.exe: CMakeFiles/desfilePatos.dir/desfilePatos.c.obj
desfilePatos.exe: CMakeFiles/desfilePatos.dir/build.make
desfilePatos.exe: CMakeFiles/desfilePatos.dir/linklibs.rsp
desfilePatos.exe: CMakeFiles/desfilePatos.dir/objects1.rsp
desfilePatos.exe: CMakeFiles/desfilePatos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable desfilePatos.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\desfilePatos.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/desfilePatos.dir/build: desfilePatos.exe
.PHONY : CMakeFiles/desfilePatos.dir/build

CMakeFiles/desfilePatos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\desfilePatos.dir\cmake_clean.cmake
.PHONY : CMakeFiles/desfilePatos.dir/clean

CMakeFiles/desfilePatos.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\anton\Desktop\EDA2_2.2020 C:\Users\anton\Desktop\EDA2_2.2020 C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug C:\Users\anton\Desktop\EDA2_2.2020\cmake-build-debug\CMakeFiles\desfilePatos.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/desfilePatos.dir/depend

