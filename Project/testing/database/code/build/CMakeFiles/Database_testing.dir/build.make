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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ellanti/Desktop/ST/Project/src/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ellanti/Desktop/ST/Project/src/server/build

# Include any dependencies generated for this target.
include CMakeFiles/Database_testing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Database_testing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Database_testing.dir/flags.make

CMakeFiles/Database_testing.dir/database.c.o: CMakeFiles/Database_testing.dir/flags.make
CMakeFiles/Database_testing.dir/database.c.o: ../database.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Database_testing.dir/database.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Database_testing.dir/database.c.o   -c /home/ellanti/Desktop/ST/Project/src/server/database.c

CMakeFiles/Database_testing.dir/database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Database_testing.dir/database.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ellanti/Desktop/ST/Project/src/server/database.c > CMakeFiles/Database_testing.dir/database.c.i

CMakeFiles/Database_testing.dir/database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Database_testing.dir/database.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ellanti/Desktop/ST/Project/src/server/database.c -o CMakeFiles/Database_testing.dir/database.c.s

# Object files for target Database_testing
Database_testing_OBJECTS = \
"CMakeFiles/Database_testing.dir/database.c.o"

# External object files for target Database_testing
Database_testing_EXTERNAL_OBJECTS =

libDatabase_testing.a: CMakeFiles/Database_testing.dir/database.c.o
libDatabase_testing.a: CMakeFiles/Database_testing.dir/build.make
libDatabase_testing.a: CMakeFiles/Database_testing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libDatabase_testing.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Database_testing.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Database_testing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Database_testing.dir/build: libDatabase_testing.a

.PHONY : CMakeFiles/Database_testing.dir/build

CMakeFiles/Database_testing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Database_testing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Database_testing.dir/clean

CMakeFiles/Database_testing.dir/depend:
	cd /home/ellanti/Desktop/ST/Project/src/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ellanti/Desktop/ST/Project/src/server /home/ellanti/Desktop/ST/Project/src/server /home/ellanti/Desktop/ST/Project/src/server/build /home/ellanti/Desktop/ST/Project/src/server/build /home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles/Database_testing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Database_testing.dir/depend

