# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util

# Include any dependencies generated for this target.
include operations/CMakeFiles/operations.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include operations/CMakeFiles/operations.dir/compiler_depend.make

# Include the progress variables for this target.
include operations/CMakeFiles/operations.dir/progress.make

# Include the compile flags for this target's objects.
include operations/CMakeFiles/operations.dir/flags.make

operations/CMakeFiles/operations.dir/operations.o: operations/CMakeFiles/operations.dir/flags.make
operations/CMakeFiles/operations.dir/operations.o: /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/operations/operations.cpp
operations/CMakeFiles/operations.dir/operations.o: operations/CMakeFiles/operations.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object operations/CMakeFiles/operations.dir/operations.o"
	cd /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util/operations && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT operations/CMakeFiles/operations.dir/operations.o -MF CMakeFiles/operations.dir/operations.o.d -o CMakeFiles/operations.dir/operations.o -c /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/operations/operations.cpp

operations/CMakeFiles/operations.dir/operations.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/operations.dir/operations.i"
	cd /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util/operations && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/operations/operations.cpp > CMakeFiles/operations.dir/operations.i

operations/CMakeFiles/operations.dir/operations.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/operations.dir/operations.s"
	cd /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util/operations && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/operations/operations.cpp -o CMakeFiles/operations.dir/operations.s

# Object files for target operations
operations_OBJECTS = \
"CMakeFiles/operations.dir/operations.o"

# External object files for target operations
operations_EXTERNAL_OBJECTS =

operations/liboperations.a: operations/CMakeFiles/operations.dir/operations.o
operations/liboperations.a: operations/CMakeFiles/operations.dir/build.make
operations/liboperations.a: operations/CMakeFiles/operations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liboperations.a"
	cd /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util/operations && $(CMAKE_COMMAND) -P CMakeFiles/operations.dir/cmake_clean_target.cmake
	cd /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util/operations && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/operations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
operations/CMakeFiles/operations.dir/build: operations/liboperations.a
.PHONY : operations/CMakeFiles/operations.dir/build

operations/CMakeFiles/operations.dir/clean:
	cd /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util/operations && $(CMAKE_COMMAND) -P CMakeFiles/operations.dir/cmake_clean.cmake
.PHONY : operations/CMakeFiles/operations.dir/clean

operations/CMakeFiles/operations.dir/depend:
	cd /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/operations /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util/operations /Users/yuki/Documents/Study/2022fall/DBMS/lab/RDBMS/rdbms/util/operations/CMakeFiles/operations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : operations/CMakeFiles/operations.dir/depend

