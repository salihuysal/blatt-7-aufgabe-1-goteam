# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/avltree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/avltree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/avltree.dir/flags.make

CMakeFiles/avltree.dir/library.cpp.obj: CMakeFiles/avltree.dir/flags.make
CMakeFiles/avltree.dir/library.cpp.obj: ../library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/avltree.dir/library.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\avltree.dir\library.cpp.obj -c "C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree\library.cpp"

CMakeFiles/avltree.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avltree.dir/library.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree\library.cpp" > CMakeFiles\avltree.dir\library.cpp.i

CMakeFiles/avltree.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avltree.dir/library.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree\library.cpp" -o CMakeFiles\avltree.dir\library.cpp.s

CMakeFiles/avltree.dir/library.cpp.obj.requires:

.PHONY : CMakeFiles/avltree.dir/library.cpp.obj.requires

CMakeFiles/avltree.dir/library.cpp.obj.provides: CMakeFiles/avltree.dir/library.cpp.obj.requires
	$(MAKE) -f CMakeFiles\avltree.dir\build.make CMakeFiles/avltree.dir/library.cpp.obj.provides.build
.PHONY : CMakeFiles/avltree.dir/library.cpp.obj.provides

CMakeFiles/avltree.dir/library.cpp.obj.provides.build: CMakeFiles/avltree.dir/library.cpp.obj


# Object files for target avltree
avltree_OBJECTS = \
"CMakeFiles/avltree.dir/library.cpp.obj"

# External object files for target avltree
avltree_EXTERNAL_OBJECTS =

libavltree.a: CMakeFiles/avltree.dir/library.cpp.obj
libavltree.a: CMakeFiles/avltree.dir/build.make
libavltree.a: CMakeFiles/avltree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libavltree.a"
	$(CMAKE_COMMAND) -P CMakeFiles\avltree.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\avltree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/avltree.dir/build: libavltree.a

.PHONY : CMakeFiles/avltree.dir/build

CMakeFiles/avltree.dir/requires: CMakeFiles/avltree.dir/library.cpp.obj.requires

.PHONY : CMakeFiles/avltree.dir/requires

CMakeFiles/avltree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\avltree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/avltree.dir/clean

CMakeFiles/avltree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree" "C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree" "C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree\cmake-build-debug" "C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree\cmake-build-debug" "C:\Users\Mario\Documents\02 Master\WS 17-18\01 Algorithmen und Datenstrukturen\Praktikum\blatt-7-aufgabe-1-goteam\avltree\cmake-build-debug\CMakeFiles\avltree.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/avltree.dir/depend

