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
CMAKE_BINARY_DIR = /home/ellanti/Desktop/ST/Project/src/server

# Include any dependencies generated for this target.
include CMakeFiles/insert_account_testcase2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/insert_account_testcase2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/insert_account_testcase2.dir/flags.make

CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.o: CMakeFiles/insert_account_testcase2.dir/flags.make
CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.o: insert_account_testcase2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.o   -c /home/ellanti/Desktop/ST/Project/src/server/insert_account_testcase2.c

CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ellanti/Desktop/ST/Project/src/server/insert_account_testcase2.c > CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.i

CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ellanti/Desktop/ST/Project/src/server/insert_account_testcase2.c -o CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.s

CMakeFiles/insert_account_testcase2.dir/database.c.o: CMakeFiles/insert_account_testcase2.dir/flags.make
CMakeFiles/insert_account_testcase2.dir/database.c.o: database.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/insert_account_testcase2.dir/database.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/insert_account_testcase2.dir/database.c.o   -c /home/ellanti/Desktop/ST/Project/src/server/database.c

CMakeFiles/insert_account_testcase2.dir/database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/insert_account_testcase2.dir/database.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ellanti/Desktop/ST/Project/src/server/database.c > CMakeFiles/insert_account_testcase2.dir/database.c.i

CMakeFiles/insert_account_testcase2.dir/database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/insert_account_testcase2.dir/database.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ellanti/Desktop/ST/Project/src/server/database.c -o CMakeFiles/insert_account_testcase2.dir/database.c.s

# Object files for target insert_account_testcase2
insert_account_testcase2_OBJECTS = \
"CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.o" \
"CMakeFiles/insert_account_testcase2.dir/database.c.o"

# External object files for target insert_account_testcase2
insert_account_testcase2_EXTERNAL_OBJECTS =

insert_account_testcase2: CMakeFiles/insert_account_testcase2.dir/insert_account_testcase2.c.o
insert_account_testcase2: CMakeFiles/insert_account_testcase2.dir/database.c.o
insert_account_testcase2: CMakeFiles/insert_account_testcase2.dir/build.make
insert_account_testcase2: CMakeFiles/insert_account_testcase2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ellanti/Desktop/ST/Project/src/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable insert_account_testcase2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/insert_account_testcase2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/insert_account_testcase2.dir/build: insert_account_testcase2

.PHONY : CMakeFiles/insert_account_testcase2.dir/build

CMakeFiles/insert_account_testcase2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/insert_account_testcase2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/insert_account_testcase2.dir/clean

CMakeFiles/insert_account_testcase2.dir/depend:
	cd /home/ellanti/Desktop/ST/Project/src/server && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ellanti/Desktop/ST/Project/src/server /home/ellanti/Desktop/ST/Project/src/server /home/ellanti/Desktop/ST/Project/src/server /home/ellanti/Desktop/ST/Project/src/server /home/ellanti/Desktop/ST/Project/src/server/CMakeFiles/insert_account_testcase2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/insert_account_testcase2.dir/depend

