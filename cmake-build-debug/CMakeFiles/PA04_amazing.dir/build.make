# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rayaanirani/Desktop/MazeSolver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PA04_amazing.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/PA04_amazing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PA04_amazing.dir/flags.make

CMakeFiles/PA04_amazing.dir/main.cpp.o: CMakeFiles/PA04_amazing.dir/flags.make
CMakeFiles/PA04_amazing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PA04_amazing.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA04_amazing.dir/main.cpp.o -c /Users/rayaanirani/Desktop/MazeSolver/main.cpp

CMakeFiles/PA04_amazing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA04_amazing.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/MazeSolver/main.cpp > CMakeFiles/PA04_amazing.dir/main.cpp.i

CMakeFiles/PA04_amazing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA04_amazing.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/MazeSolver/main.cpp -o CMakeFiles/PA04_amazing.dir/main.cpp.s

CMakeFiles/PA04_amazing.dir/DSString.cpp.o: CMakeFiles/PA04_amazing.dir/flags.make
CMakeFiles/PA04_amazing.dir/DSString.cpp.o: ../DSString.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PA04_amazing.dir/DSString.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA04_amazing.dir/DSString.cpp.o -c /Users/rayaanirani/Desktop/MazeSolver/DSString.cpp

CMakeFiles/PA04_amazing.dir/DSString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA04_amazing.dir/DSString.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/MazeSolver/DSString.cpp > CMakeFiles/PA04_amazing.dir/DSString.cpp.i

CMakeFiles/PA04_amazing.dir/DSString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA04_amazing.dir/DSString.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/MazeSolver/DSString.cpp -o CMakeFiles/PA04_amazing.dir/DSString.cpp.s

CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.o: CMakeFiles/PA04_amazing.dir/flags.make
CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.o: ../DSStringTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.o -c /Users/rayaanirani/Desktop/MazeSolver/DSStringTests.cpp

CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/MazeSolver/DSStringTests.cpp > CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.i

CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/MazeSolver/DSStringTests.cpp -o CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.s

CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.o: CMakeFiles/PA04_amazing.dir/flags.make
CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.o: ../DSVectorTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.o -c /Users/rayaanirani/Desktop/MazeSolver/DSVectorTests.cpp

CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/MazeSolver/DSVectorTests.cpp > CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.i

CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/MazeSolver/DSVectorTests.cpp -o CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.s

CMakeFiles/PA04_amazing.dir/DSListTests.cpp.o: CMakeFiles/PA04_amazing.dir/flags.make
CMakeFiles/PA04_amazing.dir/DSListTests.cpp.o: ../DSListTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PA04_amazing.dir/DSListTests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA04_amazing.dir/DSListTests.cpp.o -c /Users/rayaanirani/Desktop/MazeSolver/DSListTests.cpp

CMakeFiles/PA04_amazing.dir/DSListTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA04_amazing.dir/DSListTests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/MazeSolver/DSListTests.cpp > CMakeFiles/PA04_amazing.dir/DSListTests.cpp.i

CMakeFiles/PA04_amazing.dir/DSListTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA04_amazing.dir/DSListTests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/MazeSolver/DSListTests.cpp -o CMakeFiles/PA04_amazing.dir/DSListTests.cpp.s

CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.o: CMakeFiles/PA04_amazing.dir/flags.make
CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.o: ../DSStackTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.o -c /Users/rayaanirani/Desktop/MazeSolver/DSStackTests.cpp

CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/MazeSolver/DSStackTests.cpp > CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.i

CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/MazeSolver/DSStackTests.cpp -o CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.s

CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.o: CMakeFiles/PA04_amazing.dir/flags.make
CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.o: ../DSAdjacencyListTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.o -c /Users/rayaanirani/Desktop/MazeSolver/DSAdjacencyListTests.cpp

CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/MazeSolver/DSAdjacencyListTests.cpp > CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.i

CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/MazeSolver/DSAdjacencyListTests.cpp -o CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.s

CMakeFiles/PA04_amazing.dir/Room.cpp.o: CMakeFiles/PA04_amazing.dir/flags.make
CMakeFiles/PA04_amazing.dir/Room.cpp.o: ../Room.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/PA04_amazing.dir/Room.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA04_amazing.dir/Room.cpp.o -c /Users/rayaanirani/Desktop/MazeSolver/Room.cpp

CMakeFiles/PA04_amazing.dir/Room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA04_amazing.dir/Room.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/MazeSolver/Room.cpp > CMakeFiles/PA04_amazing.dir/Room.cpp.i

CMakeFiles/PA04_amazing.dir/Room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA04_amazing.dir/Room.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/MazeSolver/Room.cpp -o CMakeFiles/PA04_amazing.dir/Room.cpp.s

CMakeFiles/PA04_amazing.dir/Maze.cpp.o: CMakeFiles/PA04_amazing.dir/flags.make
CMakeFiles/PA04_amazing.dir/Maze.cpp.o: ../Maze.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/PA04_amazing.dir/Maze.cpp.o"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA04_amazing.dir/Maze.cpp.o -c /Users/rayaanirani/Desktop/MazeSolver/Maze.cpp

CMakeFiles/PA04_amazing.dir/Maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA04_amazing.dir/Maze.cpp.i"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rayaanirani/Desktop/MazeSolver/Maze.cpp > CMakeFiles/PA04_amazing.dir/Maze.cpp.i

CMakeFiles/PA04_amazing.dir/Maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA04_amazing.dir/Maze.cpp.s"
	/Applications/Xcode.app/Contents/Developer/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rayaanirani/Desktop/MazeSolver/Maze.cpp -o CMakeFiles/PA04_amazing.dir/Maze.cpp.s

# Object files for target PA04_amazing
PA04_amazing_OBJECTS = \
"CMakeFiles/PA04_amazing.dir/main.cpp.o" \
"CMakeFiles/PA04_amazing.dir/DSString.cpp.o" \
"CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.o" \
"CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.o" \
"CMakeFiles/PA04_amazing.dir/DSListTests.cpp.o" \
"CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.o" \
"CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.o" \
"CMakeFiles/PA04_amazing.dir/Room.cpp.o" \
"CMakeFiles/PA04_amazing.dir/Maze.cpp.o"

# External object files for target PA04_amazing
PA04_amazing_EXTERNAL_OBJECTS =

PA04_amazing: CMakeFiles/PA04_amazing.dir/main.cpp.o
PA04_amazing: CMakeFiles/PA04_amazing.dir/DSString.cpp.o
PA04_amazing: CMakeFiles/PA04_amazing.dir/DSStringTests.cpp.o
PA04_amazing: CMakeFiles/PA04_amazing.dir/DSVectorTests.cpp.o
PA04_amazing: CMakeFiles/PA04_amazing.dir/DSListTests.cpp.o
PA04_amazing: CMakeFiles/PA04_amazing.dir/DSStackTests.cpp.o
PA04_amazing: CMakeFiles/PA04_amazing.dir/DSAdjacencyListTests.cpp.o
PA04_amazing: CMakeFiles/PA04_amazing.dir/Room.cpp.o
PA04_amazing: CMakeFiles/PA04_amazing.dir/Maze.cpp.o
PA04_amazing: CMakeFiles/PA04_amazing.dir/build.make
PA04_amazing: CMakeFiles/PA04_amazing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable PA04_amazing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PA04_amazing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PA04_amazing.dir/build: PA04_amazing
.PHONY : CMakeFiles/PA04_amazing.dir/build

CMakeFiles/PA04_amazing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PA04_amazing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PA04_amazing.dir/clean

CMakeFiles/PA04_amazing.dir/depend:
	cd /Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rayaanirani/Desktop/MazeSolver /Users/rayaanirani/Desktop/MazeSolver /Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug /Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug /Users/rayaanirani/Desktop/MazeSolver/cmake-build-debug/CMakeFiles/PA04_amazing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PA04_amazing.dir/depend

