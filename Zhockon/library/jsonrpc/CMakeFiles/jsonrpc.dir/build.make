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
include library/jsonrpc/CMakeFiles/jsonrpc.dir/depend.make

# Include the progress variables for this target.
include library/jsonrpc/CMakeFiles/jsonrpc.dir/progress.make

# Include the compile flags for this target's objects.
include library/jsonrpc/CMakeFiles/jsonrpc.dir/flags.make

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o: library/jsonrpc/CMakeFiles/jsonrpc.dir/flags.make
library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o: library/jsonrpc/src/jsonrpc_client.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_client.cpp

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_client.cpp > CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.i

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_client.cpp -o CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.s

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o.requires:
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o.requires

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o.provides: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o.requires
	$(MAKE) -f library/jsonrpc/CMakeFiles/jsonrpc.dir/build.make library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o.provides.build
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o.provides

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o.provides.build: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o.provides.build

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o: library/jsonrpc/CMakeFiles/jsonrpc.dir/flags.make
library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o: library/jsonrpc/src/jsonrpc_handler.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_handler.cpp

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_handler.cpp > CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.i

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_handler.cpp -o CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.s

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o.requires:
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o.requires

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o.provides: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o.requires
	$(MAKE) -f library/jsonrpc/CMakeFiles/jsonrpc.dir/build.make library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o.provides.build
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o.provides

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o.provides.build: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o.provides.build

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o: library/jsonrpc/CMakeFiles/jsonrpc.dir/flags.make
library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o: library/jsonrpc/src/jsonrpc_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_server.cpp

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_server.cpp > CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.i

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_server.cpp -o CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.s

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o.requires:
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o.requires

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o.provides: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o.requires
	$(MAKE) -f library/jsonrpc/CMakeFiles/jsonrpc.dir/build.make library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o.provides.build
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o.provides

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o.provides.build: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o.provides.build

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o: library/jsonrpc/CMakeFiles/jsonrpc.dir/flags.make
library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o: library/jsonrpc/src/jsonrpc_tcpclient.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_tcpclient.cpp

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_tcpclient.cpp > CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.i

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_tcpclient.cpp -o CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.s

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o.requires:
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o.requires

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o.provides: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o.requires
	$(MAKE) -f library/jsonrpc/CMakeFiles/jsonrpc.dir/build.make library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o.provides.build
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o.provides

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o.provides.build: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o.provides.build

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o: library/jsonrpc/CMakeFiles/jsonrpc.dir/flags.make
library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o: library/jsonrpc/src/jsonrpc_tcpserver.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_tcpserver.cpp

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_tcpserver.cpp > CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.i

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_tcpserver.cpp -o CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.s

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o.requires:
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o.requires

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o.provides: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o.requires
	$(MAKE) -f library/jsonrpc/CMakeFiles/jsonrpc.dir/build.make library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o.provides.build
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o.provides

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o.provides.build: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o.provides.build

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o: library/jsonrpc/CMakeFiles/jsonrpc.dir/flags.make
library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o: library/jsonrpc/src/jsonrpc_udpclient.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_udpclient.cpp

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_udpclient.cpp > CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.i

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_udpclient.cpp -o CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.s

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o.requires:
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o.requires

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o.provides: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o.requires
	$(MAKE) -f library/jsonrpc/CMakeFiles/jsonrpc.dir/build.make library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o.provides.build
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o.provides

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o.provides.build: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o.provides.build

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o: library/jsonrpc/CMakeFiles/jsonrpc.dir/flags.make
library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o: library/jsonrpc/src/jsonrpc_udpserver.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_udpserver.cpp

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_udpserver.cpp > CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.i

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/jsonrpc_udpserver.cpp -o CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.s

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o.requires:
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o.requires

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o.provides: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o.requires
	$(MAKE) -f library/jsonrpc/CMakeFiles/jsonrpc.dir/build.make library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o.provides.build
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o.provides

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o.provides.build: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o.provides.build

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o: library/jsonrpc/CMakeFiles/jsonrpc.dir/flags.make
library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o: library/jsonrpc/src/netstring.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/jsonrpc.dir/src/netstring.cpp.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/netstring.cpp

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jsonrpc.dir/src/netstring.cpp.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/netstring.cpp > CMakeFiles/jsonrpc.dir/src/netstring.cpp.i

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jsonrpc.dir/src/netstring.cpp.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/netstring.cpp -o CMakeFiles/jsonrpc.dir/src/netstring.cpp.s

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o.requires:
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o.requires

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o.provides: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o.requires
	$(MAKE) -f library/jsonrpc/CMakeFiles/jsonrpc.dir/build.make library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o.provides.build
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o.provides

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o.provides.build: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o.provides.build

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o: library/jsonrpc/CMakeFiles/jsonrpc.dir/flags.make
library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o: library/jsonrpc/src/networking.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/william/Package/0.3.x/0.3.2/zhockon.src/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/jsonrpc.dir/src/networking.cpp.o -c /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/networking.cpp

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jsonrpc.dir/src/networking.cpp.i"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/networking.cpp > CMakeFiles/jsonrpc.dir/src/networking.cpp.i

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jsonrpc.dir/src/networking.cpp.s"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/src/networking.cpp -o CMakeFiles/jsonrpc.dir/src/networking.cpp.s

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o.requires:
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o.requires

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o.provides: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o.requires
	$(MAKE) -f library/jsonrpc/CMakeFiles/jsonrpc.dir/build.make library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o.provides.build
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o.provides

library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o.provides.build: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o.provides.build

# Object files for target jsonrpc
jsonrpc_OBJECTS = \
"CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o" \
"CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o" \
"CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o" \
"CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o" \
"CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o" \
"CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o" \
"CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o" \
"CMakeFiles/jsonrpc.dir/src/netstring.cpp.o" \
"CMakeFiles/jsonrpc.dir/src/networking.cpp.o"

# External object files for target jsonrpc
jsonrpc_EXTERNAL_OBJECTS =

library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o
library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o
library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o
library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o
library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o
library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o
library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o
library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o
library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o
library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/build.make
library/libjsonrpc.so: library/jsonrpc/CMakeFiles/jsonrpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../libjsonrpc.so"
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jsonrpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
library/jsonrpc/CMakeFiles/jsonrpc.dir/build: library/libjsonrpc.so
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/build

library/jsonrpc/CMakeFiles/jsonrpc.dir/requires: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_client.cpp.o.requires
library/jsonrpc/CMakeFiles/jsonrpc.dir/requires: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_handler.cpp.o.requires
library/jsonrpc/CMakeFiles/jsonrpc.dir/requires: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_server.cpp.o.requires
library/jsonrpc/CMakeFiles/jsonrpc.dir/requires: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpclient.cpp.o.requires
library/jsonrpc/CMakeFiles/jsonrpc.dir/requires: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_tcpserver.cpp.o.requires
library/jsonrpc/CMakeFiles/jsonrpc.dir/requires: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpclient.cpp.o.requires
library/jsonrpc/CMakeFiles/jsonrpc.dir/requires: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/jsonrpc_udpserver.cpp.o.requires
library/jsonrpc/CMakeFiles/jsonrpc.dir/requires: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/netstring.cpp.o.requires
library/jsonrpc/CMakeFiles/jsonrpc.dir/requires: library/jsonrpc/CMakeFiles/jsonrpc.dir/src/networking.cpp.o.requires
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/requires

library/jsonrpc/CMakeFiles/jsonrpc.dir/clean:
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc && $(CMAKE_COMMAND) -P CMakeFiles/jsonrpc.dir/cmake_clean.cmake
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/clean

library/jsonrpc/CMakeFiles/jsonrpc.dir/depend:
	cd /home/william/Package/0.3.x/0.3.2/zhockon.src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/william/Package/0.3.x/0.3.2/zhockon.src /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc /home/william/Package/0.3.x/0.3.2/zhockon.src /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc /home/william/Package/0.3.x/0.3.2/zhockon.src/library/jsonrpc/CMakeFiles/jsonrpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : library/jsonrpc/CMakeFiles/jsonrpc.dir/depend

