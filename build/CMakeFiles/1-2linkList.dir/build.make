# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.26.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/galaxy./Desktop/code/DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/galaxy./Desktop/code/DataStructure/build

# Include any dependencies generated for this target.
include CMakeFiles/1-2linkList.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/1-2linkList.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/1-2linkList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1-2linkList.dir/flags.make

CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.o: CMakeFiles/1-2linkList.dir/flags.make
CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.o: /Users/galaxy./Desktop/code/DataStructure/01.linear/02.linkList/linkList.c
CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.o: CMakeFiles/1-2linkList.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.o -MF CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.o.d -o CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.o -c /Users/galaxy./Desktop/code/DataStructure/01.linear/02.linkList/linkList.c

CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/galaxy./Desktop/code/DataStructure/01.linear/02.linkList/linkList.c > CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.i

CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/galaxy./Desktop/code/DataStructure/01.linear/02.linkList/linkList.c -o CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.s

CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.o: CMakeFiles/1-2linkList.dir/flags.make
CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.o: /Users/galaxy./Desktop/code/DataStructure/01.linear/02.linkList/main.c
CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.o: CMakeFiles/1-2linkList.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.o -MF CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.o.d -o CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.o -c /Users/galaxy./Desktop/code/DataStructure/01.linear/02.linkList/main.c

CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/galaxy./Desktop/code/DataStructure/01.linear/02.linkList/main.c > CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.i

CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/galaxy./Desktop/code/DataStructure/01.linear/02.linkList/main.c -o CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.s

# Object files for target 1-2linkList
1__2linkList_OBJECTS = \
"CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.o" \
"CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.o"

# External object files for target 1-2linkList
1__2linkList_EXTERNAL_OBJECTS =

1-2linkList: CMakeFiles/1-2linkList.dir/01.linear/02.linkList/linkList.c.o
1-2linkList: CMakeFiles/1-2linkList.dir/01.linear/02.linkList/main.c.o
1-2linkList: CMakeFiles/1-2linkList.dir/build.make
1-2linkList: CMakeFiles/1-2linkList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 1-2linkList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1-2linkList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1-2linkList.dir/build: 1-2linkList
.PHONY : CMakeFiles/1-2linkList.dir/build

CMakeFiles/1-2linkList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1-2linkList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1-2linkList.dir/clean

CMakeFiles/1-2linkList.dir/depend:
	cd /Users/galaxy./Desktop/code/DataStructure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/galaxy./Desktop/code/DataStructure /Users/galaxy./Desktop/code/DataStructure /Users/galaxy./Desktop/code/DataStructure/build /Users/galaxy./Desktop/code/DataStructure/build /Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles/1-2linkList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1-2linkList.dir/depend
