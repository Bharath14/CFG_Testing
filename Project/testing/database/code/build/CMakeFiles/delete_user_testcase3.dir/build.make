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
include CMakeFiles/delete_user_testcase3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/delete_user_testcase3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/delete_user_testcase3.dir/flags.make

CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.o: CMakeFiles/delete_user_testcase3.dir/flags.make
CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.o: ../delete_user_testcase3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.o   -c /home/ellanti/Desktop/ST/Project/src/server/delete_user_testcase3.c

CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ellanti/Desktop/ST/Project/src/server/delete_user_testcase3.c > CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.i

CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ellanti/Desktop/ST/Project/src/server/delete_user_testcase3.c -o CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.s

CMakeFiles/delete_user_testcase3.dir/database.c.o: CMakeFiles/delete_user_testcase3.dir/flags.make
CMakeFiles/delete_user_testcase3.dir/database.c.o: ../database.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/delete_user_testcase3.dir/database.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/delete_user_testcase3.dir/database.c.o   -c /home/ellanti/Desktop/ST/Project/src/server/database.c

CMakeFiles/delete_user_testcase3.dir/database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/delete_user_testcase3.dir/database.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ellanti/Desktop/ST/Project/src/server/database.c > CMakeFiles/delete_user_testcase3.dir/database.c.i

CMakeFiles/delete_user_testcase3.dir/database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/delete_user_testcase3.dir/database.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ellanti/Desktop/ST/Project/src/server/database.c -o CMakeFiles/delete_user_testcase3.dir/database.c.s

# Object files for target delete_user_testcase3
delete_user_testcase3_OBJECTS = \
"CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.o" \
"CMakeFiles/delete_user_testcase3.dir/database.c.o"

# External object files for target delete_user_testcase3
delete_user_testcase3_EXTERNAL_OBJECTS =

delete_user_testcase3: CMakeFiles/delete_user_testcase3.dir/delete_user_testcase3.c.o
delete_user_testcase3: CMakeFiles/delete_user_testcase3.dir/database.c.o
delete_user_testcase3: CMakeFiles/delete_user_testcase3.dir/build.make
delete_user_testcase3: CMakeFiles/delete_user_testcase3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable delete_user_testcase3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/delete_user_testcase3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/delete_user_testcase3.dir/build: delete_user_testcase3

.PHONY : CMakeFiles/delete_user_testcase3.dir/build

CMakeFiles/delete_user_testcase3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/delete_user_testcase3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/delete_user_testcase3.dir/clean

CMakeFiles/delete_user_testcase3.dir/depend:
	cd /home/ellanti/Desktop/ST/Project/src/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ellanti/Desktop/ST/Project/src/server /home/ellanti/Desktop/ST/Project/src/server /home/ellanti/Desktop/ST/Project/src/server/build /home/ellanti/Desktop/ST/Project/src/server/build /home/ellanti/Desktop/ST/Project/src/server/build/CMakeFiles/delete_user_testcase3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/delete_user_testcase3.dir/depend

