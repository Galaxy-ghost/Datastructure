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
include 04.Sort/CMakeFiles/4-2SwapSort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 04.Sort/CMakeFiles/4-2SwapSort.dir/compiler_depend.make

# Include the progress variables for this target.
include 04.Sort/CMakeFiles/4-2SwapSort.dir/progress.make

# Include the compile flags for this target's objects.
include 04.Sort/CMakeFiles/4-2SwapSort.dir/flags.make

04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.o: 04.Sort/CMakeFiles/4-2SwapSort.dir/flags.make
04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.o: /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/main.c
04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.o: 04.Sort/CMakeFiles/4-2SwapSort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object 04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.o"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT 04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.o -MF CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.o.d -o CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.o -c /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/main.c

04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.i"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/main.c > CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.i

04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.s"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/main.c -o CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.s

04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.o: 04.Sort/CMakeFiles/4-2SwapSort.dir/flags.make
04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.o: /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/bubbleSort.c
04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.o: 04.Sort/CMakeFiles/4-2SwapSort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object 04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.o"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT 04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.o -MF CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.o.d -o CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.o -c /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/bubbleSort.c

04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.i"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/bubbleSort.c > CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.i

04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.s"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/bubbleSort.c -o CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.s

04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.o: 04.Sort/CMakeFiles/4-2SwapSort.dir/flags.make
04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.o: /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/quickSort.c
04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.o: 04.Sort/CMakeFiles/4-2SwapSort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object 04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.o"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT 04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.o -MF CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.o.d -o CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.o -c /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/quickSort.c

04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.i"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/quickSort.c > CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.i

04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.s"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/galaxy./Desktop/code/DataStructure/04.Sort/02.SwapSort/quickSort.c -o CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.s

04.Sort/CMakeFiles/4-2SwapSort.dir/sortHelper.c.o: 04.Sort/CMakeFiles/4-2SwapSort.dir/flags.make
04.Sort/CMakeFiles/4-2SwapSort.dir/sortHelper.c.o: /Users/galaxy./Desktop/code/DataStructure/04.Sort/sortHelper.c
04.Sort/CMakeFiles/4-2SwapSort.dir/sortHelper.c.o: 04.Sort/CMakeFiles/4-2SwapSort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object 04.Sort/CMakeFiles/4-2SwapSort.dir/sortHelper.c.o"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT 04.Sort/CMakeFiles/4-2SwapSort.dir/sortHelper.c.o -MF CMakeFiles/4-2SwapSort.dir/sortHelper.c.o.d -o CMakeFiles/4-2SwapSort.dir/sortHelper.c.o -c /Users/galaxy./Desktop/code/DataStructure/04.Sort/sortHelper.c

04.Sort/CMakeFiles/4-2SwapSort.dir/sortHelper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/4-2SwapSort.dir/sortHelper.c.i"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/galaxy./Desktop/code/DataStructure/04.Sort/sortHelper.c > CMakeFiles/4-2SwapSort.dir/sortHelper.c.i

04.Sort/CMakeFiles/4-2SwapSort.dir/sortHelper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/4-2SwapSort.dir/sortHelper.c.s"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/galaxy./Desktop/code/DataStructure/04.Sort/sortHelper.c -o CMakeFiles/4-2SwapSort.dir/sortHelper.c.s

# Object files for target 4-2SwapSort
4__2SwapSort_OBJECTS = \
"CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.o" \
"CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.o" \
"CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.o" \
"CMakeFiles/4-2SwapSort.dir/sortHelper.c.o"

# External object files for target 4-2SwapSort
4__2SwapSort_EXTERNAL_OBJECTS =

04.Sort/4-2SwapSort: 04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/main.c.o
04.Sort/4-2SwapSort: 04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/bubbleSort.c.o
04.Sort/4-2SwapSort: 04.Sort/CMakeFiles/4-2SwapSort.dir/02.SwapSort/quickSort.c.o
04.Sort/4-2SwapSort: 04.Sort/CMakeFiles/4-2SwapSort.dir/sortHelper.c.o
04.Sort/4-2SwapSort: 04.Sort/CMakeFiles/4-2SwapSort.dir/build.make
04.Sort/4-2SwapSort: 04.Sort/CMakeFiles/4-2SwapSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/galaxy./Desktop/code/DataStructure/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable 4-2SwapSort"
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/4-2SwapSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
04.Sort/CMakeFiles/4-2SwapSort.dir/build: 04.Sort/4-2SwapSort
.PHONY : 04.Sort/CMakeFiles/4-2SwapSort.dir/build

04.Sort/CMakeFiles/4-2SwapSort.dir/clean:
	cd /Users/galaxy./Desktop/code/DataStructure/build/04.Sort && $(CMAKE_COMMAND) -P CMakeFiles/4-2SwapSort.dir/cmake_clean.cmake
.PHONY : 04.Sort/CMakeFiles/4-2SwapSort.dir/clean

04.Sort/CMakeFiles/4-2SwapSort.dir/depend:
	cd /Users/galaxy./Desktop/code/DataStructure/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/galaxy./Desktop/code/DataStructure /Users/galaxy./Desktop/code/DataStructure/04.Sort /Users/galaxy./Desktop/code/DataStructure/build /Users/galaxy./Desktop/code/DataStructure/build/04.Sort /Users/galaxy./Desktop/code/DataStructure/build/04.Sort/CMakeFiles/4-2SwapSort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 04.Sort/CMakeFiles/4-2SwapSort.dir/depend

