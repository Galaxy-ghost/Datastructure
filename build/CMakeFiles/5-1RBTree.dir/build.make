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
include CMakeFiles/5-1RBTree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/5-1RBTree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/5-1RBTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5-1RBTree.dir/flags.make

CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.o: CMakeFiles/5-1RBTree.dir/flags.make
CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.o: /Users/galaxy./Desktop/code/DataStructure/05.RBTree/rbTree.c
CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.o: CMakeFiles/5-1RBTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.o -MF CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.o.d -o CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.o -c /Users/galaxy./Desktop/code/DataStructure/05.RBTree/rbTree.c

CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/galaxy./Desktop/code/DataStructure/05.RBTree/rbTree.c > CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.i

CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/galaxy./Desktop/code/DataStructure/05.RBTree/rbTree.c -o CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.s

CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.o: CMakeFiles/5-1RBTree.dir/flags.make
CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.o: /Users/galaxy./Desktop/code/DataStructure/05.RBTree/main.c
CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.o: CMakeFiles/5-1RBTree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.o -MF CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.o.d -o CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.o -c /Users/galaxy./Desktop/code/DataStructure/05.RBTree/main.c

CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/galaxy./Desktop/code/DataStructure/05.RBTree/main.c > CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.i

CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/galaxy./Desktop/code/DataStructure/05.RBTree/main.c -o CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.s

# Object files for target 5-1RBTree
5__1RBTree_OBJECTS = \
"CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.o" \
"CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.o"

# External object files for target 5-1RBTree
5__1RBTree_EXTERNAL_OBJECTS =

5-1RBTree: CMakeFiles/5-1RBTree.dir/05.RBTree/rbTree.c.o
5-1RBTree: CMakeFiles/5-1RBTree.dir/05.RBTree/main.c.o
5-1RBTree: CMakeFiles/5-1RBTree.dir/build.make
5-1RBTree: CMakeFiles/5-1RBTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 5-1RBTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/5-1RBTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5-1RBTree.dir/build: 5-1RBTree
.PHONY : CMakeFiles/5-1RBTree.dir/build

CMakeFiles/5-1RBTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/5-1RBTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/5-1RBTree.dir/clean

CMakeFiles/5-1RBTree.dir/depend:
	cd /Users/galaxy./Desktop/code/DataStructure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/galaxy./Desktop/code/DataStructure /Users/galaxy./Desktop/code/DataStructure /Users/galaxy./Desktop/code/DataStructure/build /Users/galaxy./Desktop/code/DataStructure/build /Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles/5-1RBTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/5-1RBTree.dir/depend

