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
include CMakeFiles/lock_account_testcase3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lock_account_testcase3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lock_account_testcase3.dir/flags.make

CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.o: CMakeFiles/lock_account_testcase3.dir/flags.make
CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.o: ../lock_account_testcase3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.o   -c /home/ellanti/Desktop/ST/Project/src/server/lock_account_testcase3.c

CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ellanti/Desktop/ST/Project/src/server/lock_account_testcase3.c > CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.i

CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ellanti/Desktop/ST/Project/src/server/lock_account_testcase3.c -o CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.s

CMakeFiles/lock_account_testcase3.dir/database.c.o: CMakeFiles/lock_account_testcase3.dir/flags.make
CMakeFiles/lock_account_testcase3.dir/database.c.o: ../database.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lock_account_testcase3.dir/database.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lock_account_testcase3.dir/database.c.o   -c /home/ellanti/Desktop/ST/Project/src/server/database.c

CMakeFiles/lock_account_testcase3.dir/database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lock_account_testcase3.dir/database.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ellanti/Desktop/ST/Project/src/server/database.c > CMakeFiles/lock_account_testcase3.dir/database.c.i

CMakeFiles/lock_account_testcase3.dir/database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lock_account_testcase3.dir/database.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ellanti/Desktop/ST/Project/src/server/database.c -o CMakeFiles/lock_account_testcase3.dir/database.c.s

# Object files for target lock_account_testcase3
lock_account_testcase3_OBJECTS = \
"CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.o" \
"CMakeFiles/lock_account_testcase3.dir/database.c.o"

# External object files for target lock_account_testcase3
lock_account_testcase3_EXTERNAL_OBJECTS =

lock_account_testcase3: CMakeFiles/lock_account_testcase3.dir/lock_account_testcase3.c.o
lock_account_testcase3: CMakeFiles/lock_account_testcase3.dir/database.c.o
lock_account_testcase3: CMakeFiles/lock_account_testcase3.dir/build.make
lock_account_testcase3: CMakeFiles/lock_account_testcase3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lock_account_testcase3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lock_account_testcase3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lock_account_testcase3.dir/build: lock_account_testcase3

.PHONY : CMakeFiles/lock_account_testcase3.dir/build

CMakeFiles/lock_account_testcase3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lock_account_testcase3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lock_account_testcase3.dir/clean

CMakeFiles/lock_account_testcase3.dir/depend:
	cd /home/ellanti/Desktop/ST/Project/src/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ellanti/Desktop/ST/Project/src/server /home/ellanti/Desktop/ST/Project/src/server /home/ellanti/Desktop/ST/Project/src/server/build /home/ellanti/Desktop/ST/Project/src/server/build /home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles/lock_account_testcase3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lock_account_testcase3.dir/depend

