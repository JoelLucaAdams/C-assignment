# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Membership_Program.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Membership_Program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Membership_Program.dir/flags.make

CMakeFiles/Membership_Program.dir/main.c.obj: CMakeFiles/Membership_Program.dir/flags.make
CMakeFiles/Membership_Program.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Membership_Program.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Membership_Program.dir\main.c.obj   -c "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\main.c"

CMakeFiles/Membership_Program.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Membership_Program.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\main.c" > CMakeFiles\Membership_Program.dir\main.c.i

CMakeFiles/Membership_Program.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Membership_Program.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\main.c" -o CMakeFiles\Membership_Program.dir\main.c.s

CMakeFiles/Membership_Program.dir/membership.c.obj: CMakeFiles/Membership_Program.dir/flags.make
CMakeFiles/Membership_Program.dir/membership.c.obj: ../membership.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Membership_Program.dir/membership.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Membership_Program.dir\membership.c.obj   -c "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\membership.c"

CMakeFiles/Membership_Program.dir/membership.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Membership_Program.dir/membership.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\membership.c" > CMakeFiles\Membership_Program.dir\membership.c.i

CMakeFiles/Membership_Program.dir/membership.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Membership_Program.dir/membership.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\membership.c" -o CMakeFiles\Membership_Program.dir\membership.c.s

CMakeFiles/Membership_Program.dir/search_members.c.obj: CMakeFiles/Membership_Program.dir/flags.make
CMakeFiles/Membership_Program.dir/search_members.c.obj: ../search_members.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Membership_Program.dir/search_members.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Membership_Program.dir\search_members.c.obj   -c "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\search_members.c"

CMakeFiles/Membership_Program.dir/search_members.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Membership_Program.dir/search_members.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\search_members.c" > CMakeFiles\Membership_Program.dir\search_members.c.i

CMakeFiles/Membership_Program.dir/search_members.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Membership_Program.dir/search_members.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\search_members.c" -o CMakeFiles\Membership_Program.dir\search_members.c.s

CMakeFiles/Membership_Program.dir/print.c.obj: CMakeFiles/Membership_Program.dir/flags.make
CMakeFiles/Membership_Program.dir/print.c.obj: ../print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Membership_Program.dir/print.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Membership_Program.dir\print.c.obj   -c "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\print.c"

CMakeFiles/Membership_Program.dir/print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Membership_Program.dir/print.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\print.c" > CMakeFiles\Membership_Program.dir\print.c.i

CMakeFiles/Membership_Program.dir/print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Membership_Program.dir/print.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\print.c" -o CMakeFiles\Membership_Program.dir\print.c.s

# Object files for target Membership_Program
Membership_Program_OBJECTS = \
"CMakeFiles/Membership_Program.dir/main.c.obj" \
"CMakeFiles/Membership_Program.dir/membership.c.obj" \
"CMakeFiles/Membership_Program.dir/search_members.c.obj" \
"CMakeFiles/Membership_Program.dir/print.c.obj"

# External object files for target Membership_Program
Membership_Program_EXTERNAL_OBJECTS =

Membership_Program.exe: CMakeFiles/Membership_Program.dir/main.c.obj
Membership_Program.exe: CMakeFiles/Membership_Program.dir/membership.c.obj
Membership_Program.exe: CMakeFiles/Membership_Program.dir/search_members.c.obj
Membership_Program.exe: CMakeFiles/Membership_Program.dir/print.c.obj
Membership_Program.exe: CMakeFiles/Membership_Program.dir/build.make
Membership_Program.exe: CMakeFiles/Membership_Program.dir/linklibs.rsp
Membership_Program.exe: CMakeFiles/Membership_Program.dir/objects1.rsp
Membership_Program.exe: CMakeFiles/Membership_Program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Membership_Program.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Membership_Program.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Membership_Program.dir/build: Membership_Program.exe

.PHONY : CMakeFiles/Membership_Program.dir/build

CMakeFiles/Membership_Program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Membership_Program.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Membership_Program.dir/clean

CMakeFiles/Membership_Program.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program" "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program" "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\cmake-build-debug" "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\cmake-build-debug" "C:\Users\joelu\Dropbox\University work\CS23820 Assignment\Membership_Program\cmake-build-debug\CMakeFiles\Membership_Program.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Membership_Program.dir/depend

