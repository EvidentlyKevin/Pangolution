# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kevin/Pangolution

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kevin/Pangolution/build

# Include any dependencies generated for this target.
include CMakeFiles/Pangolution.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Pangolution.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Pangolution.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pangolution.dir/flags.make

CMakeFiles/Pangolution.dir/main.cpp.o: CMakeFiles/Pangolution.dir/flags.make
CMakeFiles/Pangolution.dir/main.cpp.o: ../main.cpp
CMakeFiles/Pangolution.dir/main.cpp.o: CMakeFiles/Pangolution.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevin/Pangolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pangolution.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pangolution.dir/main.cpp.o -MF CMakeFiles/Pangolution.dir/main.cpp.o.d -o CMakeFiles/Pangolution.dir/main.cpp.o -c /home/kevin/Pangolution/main.cpp

CMakeFiles/Pangolution.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pangolution.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevin/Pangolution/main.cpp > CMakeFiles/Pangolution.dir/main.cpp.i

CMakeFiles/Pangolution.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pangolution.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevin/Pangolution/main.cpp -o CMakeFiles/Pangolution.dir/main.cpp.s

CMakeFiles/Pangolution.dir/Pangolin.cpp.o: CMakeFiles/Pangolution.dir/flags.make
CMakeFiles/Pangolution.dir/Pangolin.cpp.o: ../Pangolin.cpp
CMakeFiles/Pangolution.dir/Pangolin.cpp.o: CMakeFiles/Pangolution.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevin/Pangolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Pangolution.dir/Pangolin.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pangolution.dir/Pangolin.cpp.o -MF CMakeFiles/Pangolution.dir/Pangolin.cpp.o.d -o CMakeFiles/Pangolution.dir/Pangolin.cpp.o -c /home/kevin/Pangolution/Pangolin.cpp

CMakeFiles/Pangolution.dir/Pangolin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pangolution.dir/Pangolin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevin/Pangolution/Pangolin.cpp > CMakeFiles/Pangolution.dir/Pangolin.cpp.i

CMakeFiles/Pangolution.dir/Pangolin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pangolution.dir/Pangolin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevin/Pangolution/Pangolin.cpp -o CMakeFiles/Pangolution.dir/Pangolin.cpp.s

CMakeFiles/Pangolution.dir/Utility.cpp.o: CMakeFiles/Pangolution.dir/flags.make
CMakeFiles/Pangolution.dir/Utility.cpp.o: ../Utility.cpp
CMakeFiles/Pangolution.dir/Utility.cpp.o: CMakeFiles/Pangolution.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevin/Pangolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Pangolution.dir/Utility.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Pangolution.dir/Utility.cpp.o -MF CMakeFiles/Pangolution.dir/Utility.cpp.o.d -o CMakeFiles/Pangolution.dir/Utility.cpp.o -c /home/kevin/Pangolution/Utility.cpp

CMakeFiles/Pangolution.dir/Utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pangolution.dir/Utility.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevin/Pangolution/Utility.cpp > CMakeFiles/Pangolution.dir/Utility.cpp.i

CMakeFiles/Pangolution.dir/Utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pangolution.dir/Utility.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevin/Pangolution/Utility.cpp -o CMakeFiles/Pangolution.dir/Utility.cpp.s

# Object files for target Pangolution
Pangolution_OBJECTS = \
"CMakeFiles/Pangolution.dir/main.cpp.o" \
"CMakeFiles/Pangolution.dir/Pangolin.cpp.o" \
"CMakeFiles/Pangolution.dir/Utility.cpp.o"

# External object files for target Pangolution
Pangolution_EXTERNAL_OBJECTS =

Pangolution: CMakeFiles/Pangolution.dir/main.cpp.o
Pangolution: CMakeFiles/Pangolution.dir/Pangolin.cpp.o
Pangolution: CMakeFiles/Pangolution.dir/Utility.cpp.o
Pangolution: CMakeFiles/Pangolution.dir/build.make
Pangolution: CMakeFiles/Pangolution.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kevin/Pangolution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Pangolution"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pangolution.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pangolution.dir/build: Pangolution
.PHONY : CMakeFiles/Pangolution.dir/build

CMakeFiles/Pangolution.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pangolution.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pangolution.dir/clean

CMakeFiles/Pangolution.dir/depend:
	cd /home/kevin/Pangolution/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kevin/Pangolution /home/kevin/Pangolution /home/kevin/Pangolution/build /home/kevin/Pangolution/build /home/kevin/Pangolution/build/CMakeFiles/Pangolution.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pangolution.dir/depend

