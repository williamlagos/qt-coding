# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/william/Package/0.3.x/0.3.2/zhockon.src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/william/Package/0.3.x/0.3.2/zhockon.src

# Include any dependencies generated for this target.
include core/CMakeFiles/zhockon.dir/depend.make

# Include the progress variables for this target.
include core/CMakeFiles/zhockon.dir/progress.make

# Include the compile flags for this target's objects.
include core/CMakeFiles/zhockon.dir/flags.make

core/CMakeFiles/zhockon.dir/zhockon.cc.o: core/CMakeFiles/zhockon.dir/flags.make
core/CMakeFiles/zhockon.dir/zhockon.cc.o: core/zhockon.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object core/CMakeFiles/zhockon.dir/zhockon.cc.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zhockon.dir/zhockon.cc.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/core/zhockon.cc

core/CMakeFiles/zhockon.dir/zhockon.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zhockon.dir/zhockon.cc.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/core/zhockon.cc > CMakeFiles/zhockon.dir/zhockon.cc.i

core/CMakeFiles/zhockon.dir/zhockon.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zhockon.dir/zhockon.cc.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/core/zhockon.cc -o CMakeFiles/zhockon.dir/zhockon.cc.s

core/CMakeFiles/zhockon.dir/zhockon.cc.o.requires:
.PHONY : core/CMakeFiles/zhockon.dir/zhockon.cc.o.requires

core/CMakeFiles/zhockon.dir/zhockon.cc.o.provides: core/CMakeFiles/zhockon.dir/zhockon.cc.o.requires
	$(MAKE) -f core/CMakeFiles/zhockon.dir/build.make core/CMakeFiles/zhockon.dir/zhockon.cc.o.provides.build
.PHONY : core/CMakeFiles/zhockon.dir/zhockon.cc.o.provides

core/CMakeFiles/zhockon.dir/zhockon.cc.o.provides.build: core/CMakeFiles/zhockon.dir/zhockon.cc.o
.PHONY : core/CMakeFiles/zhockon.dir/zhockon.cc.o.provides.build

core/CMakeFiles/zhockon.dir/structure.cc.o: core/CMakeFiles/zhockon.dir/flags.make
core/CMakeFiles/zhockon.dir/structure.cc.o: core/structure.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object core/CMakeFiles/zhockon.dir/structure.cc.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zhockon.dir/structure.cc.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/core/structure.cc

core/CMakeFiles/zhockon.dir/structure.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zhockon.dir/structure.cc.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/core/structure.cc > CMakeFiles/zhockon.dir/structure.cc.i

core/CMakeFiles/zhockon.dir/structure.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zhockon.dir/structure.cc.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/core/structure.cc -o CMakeFiles/zhockon.dir/structure.cc.s

core/CMakeFiles/zhockon.dir/structure.cc.o.requires:
.PHONY : core/CMakeFiles/zhockon.dir/structure.cc.o.requires

core/CMakeFiles/zhockon.dir/structure.cc.o.provides: core/CMakeFiles/zhockon.dir/structure.cc.o.requires
	$(MAKE) -f core/CMakeFiles/zhockon.dir/build.make core/CMakeFiles/zhockon.dir/structure.cc.o.provides.build
.PHONY : core/CMakeFiles/zhockon.dir/structure.cc.o.provides

core/CMakeFiles/zhockon.dir/structure.cc.o.provides.build: core/CMakeFiles/zhockon.dir/structure.cc.o
.PHONY : core/CMakeFiles/zhockon.dir/structure.cc.o.provides.build

core/CMakeFiles/zhockon.dir/platform.cc.o: core/CMakeFiles/zhockon.dir/flags.make
core/CMakeFiles/zhockon.dir/platform.cc.o: core/platform.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object core/CMakeFiles/zhockon.dir/platform.cc.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zhockon.dir/platform.cc.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/core/platform.cc

core/CMakeFiles/zhockon.dir/platform.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zhockon.dir/platform.cc.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/core/platform.cc > CMakeFiles/zhockon.dir/platform.cc.i

core/CMakeFiles/zhockon.dir/platform.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zhockon.dir/platform.cc.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/core/platform.cc -o CMakeFiles/zhockon.dir/platform.cc.s

core/CMakeFiles/zhockon.dir/platform.cc.o.requires:
.PHONY : core/CMakeFiles/zhockon.dir/platform.cc.o.requires

core/CMakeFiles/zhockon.dir/platform.cc.o.provides: core/CMakeFiles/zhockon.dir/platform.cc.o.requires
	$(MAKE) -f core/CMakeFiles/zhockon.dir/build.make core/CMakeFiles/zhockon.dir/platform.cc.o.provides.build
.PHONY : core/CMakeFiles/zhockon.dir/platform.cc.o.provides

core/CMakeFiles/zhockon.dir/platform.cc.o.provides.build: core/CMakeFiles/zhockon.dir/platform.cc.o
.PHONY : core/CMakeFiles/zhockon.dir/platform.cc.o.provides.build

core/CMakeFiles/zhockon.dir/audio.cc.o: core/CMakeFiles/zhockon.dir/flags.make
core/CMakeFiles/zhockon.dir/audio.cc.o: core/audio.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object core/CMakeFiles/zhockon.dir/audio.cc.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zhockon.dir/audio.cc.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/core/audio.cc

core/CMakeFiles/zhockon.dir/audio.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zhockon.dir/audio.cc.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/core/audio.cc > CMakeFiles/zhockon.dir/audio.cc.i

core/CMakeFiles/zhockon.dir/audio.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zhockon.dir/audio.cc.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/core/audio.cc -o CMakeFiles/zhockon.dir/audio.cc.s

core/CMakeFiles/zhockon.dir/audio.cc.o.requires:
.PHONY : core/CMakeFiles/zhockon.dir/audio.cc.o.requires

core/CMakeFiles/zhockon.dir/audio.cc.o.provides: core/CMakeFiles/zhockon.dir/audio.cc.o.requires
	$(MAKE) -f core/CMakeFiles/zhockon.dir/build.make core/CMakeFiles/zhockon.dir/audio.cc.o.provides.build
.PHONY : core/CMakeFiles/zhockon.dir/audio.cc.o.provides

core/CMakeFiles/zhockon.dir/audio.cc.o.provides.build: core/CMakeFiles/zhockon.dir/audio.cc.o
.PHONY : core/CMakeFiles/zhockon.dir/audio.cc.o.provides.build

core/CMakeFiles/zhockon.dir/graphics.cc.o: core/CMakeFiles/zhockon.dir/flags.make
core/CMakeFiles/zhockon.dir/graphics.cc.o: core/graphics.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object core/CMakeFiles/zhockon.dir/graphics.cc.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zhockon.dir/graphics.cc.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/core/graphics.cc

core/CMakeFiles/zhockon.dir/graphics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zhockon.dir/graphics.cc.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/core/graphics.cc > CMakeFiles/zhockon.dir/graphics.cc.i

core/CMakeFiles/zhockon.dir/graphics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zhockon.dir/graphics.cc.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/core/graphics.cc -o CMakeFiles/zhockon.dir/graphics.cc.s

core/CMakeFiles/zhockon.dir/graphics.cc.o.requires:
.PHONY : core/CMakeFiles/zhockon.dir/graphics.cc.o.requires

core/CMakeFiles/zhockon.dir/graphics.cc.o.provides: core/CMakeFiles/zhockon.dir/graphics.cc.o.requires
	$(MAKE) -f core/CMakeFiles/zhockon.dir/build.make core/CMakeFiles/zhockon.dir/graphics.cc.o.provides.build
.PHONY : core/CMakeFiles/zhockon.dir/graphics.cc.o.provides

core/CMakeFiles/zhockon.dir/graphics.cc.o.provides.build: core/CMakeFiles/zhockon.dir/graphics.cc.o
.PHONY : core/CMakeFiles/zhockon.dir/graphics.cc.o.provides.build

core/CMakeFiles/zhockon.dir/elements.cc.o: core/CMakeFiles/zhockon.dir/flags.make
core/CMakeFiles/zhockon.dir/elements.cc.o: core/elements.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object core/CMakeFiles/zhockon.dir/elements.cc.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zhockon.dir/elements.cc.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/core/elements.cc

core/CMakeFiles/zhockon.dir/elements.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zhockon.dir/elements.cc.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/core/elements.cc > CMakeFiles/zhockon.dir/elements.cc.i

core/CMakeFiles/zhockon.dir/elements.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zhockon.dir/elements.cc.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/core/elements.cc -o CMakeFiles/zhockon.dir/elements.cc.s

core/CMakeFiles/zhockon.dir/elements.cc.o.requires:
.PHONY : core/CMakeFiles/zhockon.dir/elements.cc.o.requires

core/CMakeFiles/zhockon.dir/elements.cc.o.provides: core/CMakeFiles/zhockon.dir/elements.cc.o.requires
	$(MAKE) -f core/CMakeFiles/zhockon.dir/build.make core/CMakeFiles/zhockon.dir/elements.cc.o.provides.build
.PHONY : core/CMakeFiles/zhockon.dir/elements.cc.o.provides

core/CMakeFiles/zhockon.dir/elements.cc.o.provides.build: core/CMakeFiles/zhockon.dir/elements.cc.o
.PHONY : core/CMakeFiles/zhockon.dir/elements.cc.o.provides.build

core/CMakeFiles/zhockon.dir/physics.cc.o: core/CMakeFiles/zhockon.dir/flags.make
core/CMakeFiles/zhockon.dir/physics.cc.o: core/physics.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object core/CMakeFiles/zhockon.dir/physics.cc.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zhockon.dir/physics.cc.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/core/physics.cc

core/CMakeFiles/zhockon.dir/physics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zhockon.dir/physics.cc.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/core/physics.cc > CMakeFiles/zhockon.dir/physics.cc.i

core/CMakeFiles/zhockon.dir/physics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zhockon.dir/physics.cc.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/core/physics.cc -o CMakeFiles/zhockon.dir/physics.cc.s

core/CMakeFiles/zhockon.dir/physics.cc.o.requires:
.PHONY : core/CMakeFiles/zhockon.dir/physics.cc.o.requires

core/CMakeFiles/zhockon.dir/physics.cc.o.provides: core/CMakeFiles/zhockon.dir/physics.cc.o.requires
	$(MAKE) -f core/CMakeFiles/zhockon.dir/build.make core/CMakeFiles/zhockon.dir/physics.cc.o.provides.build
.PHONY : core/CMakeFiles/zhockon.dir/physics.cc.o.provides

core/CMakeFiles/zhockon.dir/physics.cc.o.provides.build: core/CMakeFiles/zhockon.dir/physics.cc.o
.PHONY : core/CMakeFiles/zhockon.dir/physics.cc.o.provides.build

core/CMakeFiles/zhockon.dir/player.cc.o: core/CMakeFiles/zhockon.dir/flags.make
core/CMakeFiles/zhockon.dir/player.cc.o: core/player.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object core/CMakeFiles/zhockon.dir/player.cc.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zhockon.dir/player.cc.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/core/player.cc

core/CMakeFiles/zhockon.dir/player.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zhockon.dir/player.cc.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/core/player.cc > CMakeFiles/zhockon.dir/player.cc.i

core/CMakeFiles/zhockon.dir/player.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zhockon.dir/player.cc.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/core/player.cc -o CMakeFiles/zhockon.dir/player.cc.s

core/CMakeFiles/zhockon.dir/player.cc.o.requires:
.PHONY : core/CMakeFiles/zhockon.dir/player.cc.o.requires

core/CMakeFiles/zhockon.dir/player.cc.o.provides: core/CMakeFiles/zhockon.dir/player.cc.o.requires
	$(MAKE) -f core/CMakeFiles/zhockon.dir/build.make core/CMakeFiles/zhockon.dir/player.cc.o.provides.build
.PHONY : core/CMakeFiles/zhockon.dir/player.cc.o.provides

core/CMakeFiles/zhockon.dir/player.cc.o.provides.build: core/CMakeFiles/zhockon.dir/player.cc.o
.PHONY : core/CMakeFiles/zhockon.dir/player.cc.o.provides.build

# Object files for target zhockon
zhockon_OBJECTS = \
"CMakeFiles/zhockon.dir/zhockon.cc.o" \
"CMakeFiles/zhockon.dir/structure.cc.o" \
"CMakeFiles/zhockon.dir/platform.cc.o" \
"CMakeFiles/zhockon.dir/audio.cc.o" \
"CMakeFiles/zhockon.dir/graphics.cc.o" \
"CMakeFiles/zhockon.dir/elements.cc.o" \
"CMakeFiles/zhockon.dir/physics.cc.o" \
"CMakeFiles/zhockon.dir/player.cc.o"

# External object files for target zhockon
zhockon_EXTERNAL_OBJECTS =

library/libzhockon.so: core/CMakeFiles/zhockon.dir/zhockon.cc.o
library/libzhockon.so: core/CMakeFiles/zhockon.dir/structure.cc.o
library/libzhockon.so: core/CMakeFiles/zhockon.dir/platform.cc.o
library/libzhockon.so: core/CMakeFiles/zhockon.dir/audio.cc.o
library/libzhockon.so: core/CMakeFiles/zhockon.dir/graphics.cc.o
library/libzhockon.so: core/CMakeFiles/zhockon.dir/elements.cc.o
library/libzhockon.so: core/CMakeFiles/zhockon.dir/physics.cc.o
library/libzhockon.so: core/CMakeFiles/zhockon.dir/player.cc.o
library/libzhockon.so: /usr/lib64/libSDLmain.a
library/libzhockon.so: /usr/lib64/libSDL.so
library/libzhockon.so: /usr/lib64/libopenal.so
library/libzhockon.so: core/CMakeFiles/zhockon.dir/build.make
library/libzhockon.so: core/CMakeFiles/zhockon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../library/libzhockon.so"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zhockon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
core/CMakeFiles/zhockon.dir/build: library/libzhockon.so
.PHONY : core/CMakeFiles/zhockon.dir/build

core/CMakeFiles/zhockon.dir/requires: core/CMakeFiles/zhockon.dir/zhockon.cc.o.requires
core/CMakeFiles/zhockon.dir/requires: core/CMakeFiles/zhockon.dir/structure.cc.o.requires
core/CMakeFiles/zhockon.dir/requires: core/CMakeFiles/zhockon.dir/platform.cc.o.requires
core/CMakeFiles/zhockon.dir/requires: core/CMakeFiles/zhockon.dir/audio.cc.o.requires
core/CMakeFiles/zhockon.dir/requires: core/CMakeFiles/zhockon.dir/graphics.cc.o.requires
core/CMakeFiles/zhockon.dir/requires: core/CMakeFiles/zhockon.dir/elements.cc.o.requires
core/CMakeFiles/zhockon.dir/requires: core/CMakeFiles/zhockon.dir/physics.cc.o.requires
core/CMakeFiles/zhockon.dir/requires: core/CMakeFiles/zhockon.dir/player.cc.o.requires
.PHONY : core/CMakeFiles/zhockon.dir/requires

core/CMakeFiles/zhockon.dir/clean:
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/core && $(CMAKE_COMMAND) -P CMakeFiles/zhockon.dir/cmake_clean.cmake
.PHONY : core/CMakeFiles/zhockon.dir/clean

core/CMakeFiles/zhockon.dir/depend:
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/william/Package/0.3.x/0.3.2/zhockon.src /home/william/Package/0.3.x/0.3.2/zhockon.src/core /home/william/Package/0.3.x/0.3.2/zhockon.src /home/william/Package/0.3.x/0.3.2/zhockon.src/core /home/william/Package/0.3.x/0.3.2/zhockon.src/core/CMakeFiles/zhockon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : core/CMakeFiles/zhockon.dir/depend

