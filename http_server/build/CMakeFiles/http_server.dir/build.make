# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/router/Documents/use_muduo/http_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/router/Documents/use_muduo/http_server/build

# Include any dependencies generated for this target.
include CMakeFiles/http_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/http_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/http_server.dir/flags.make

CMakeFiles/http_server.dir/httpd.cc.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/httpd.cc.o: ../httpd.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/router/Documents/use_muduo/http_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/http_server.dir/httpd.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/httpd.cc.o -c /home/router/Documents/use_muduo/http_server/httpd.cc

CMakeFiles/http_server.dir/httpd.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/httpd.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/router/Documents/use_muduo/http_server/httpd.cc > CMakeFiles/http_server.dir/httpd.cc.i

CMakeFiles/http_server.dir/httpd.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/httpd.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/router/Documents/use_muduo/http_server/httpd.cc -o CMakeFiles/http_server.dir/httpd.cc.s

CMakeFiles/http_server.dir/httpd.cc.o.requires:

.PHONY : CMakeFiles/http_server.dir/httpd.cc.o.requires

CMakeFiles/http_server.dir/httpd.cc.o.provides: CMakeFiles/http_server.dir/httpd.cc.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/httpd.cc.o.provides.build
.PHONY : CMakeFiles/http_server.dir/httpd.cc.o.provides

CMakeFiles/http_server.dir/httpd.cc.o.provides.build: CMakeFiles/http_server.dir/httpd.cc.o


CMakeFiles/http_server.dir/HttpContext.cc.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/HttpContext.cc.o: ../HttpContext.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/router/Documents/use_muduo/http_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/http_server.dir/HttpContext.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/HttpContext.cc.o -c /home/router/Documents/use_muduo/http_server/HttpContext.cc

CMakeFiles/http_server.dir/HttpContext.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/HttpContext.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/router/Documents/use_muduo/http_server/HttpContext.cc > CMakeFiles/http_server.dir/HttpContext.cc.i

CMakeFiles/http_server.dir/HttpContext.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/HttpContext.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/router/Documents/use_muduo/http_server/HttpContext.cc -o CMakeFiles/http_server.dir/HttpContext.cc.s

CMakeFiles/http_server.dir/HttpContext.cc.o.requires:

.PHONY : CMakeFiles/http_server.dir/HttpContext.cc.o.requires

CMakeFiles/http_server.dir/HttpContext.cc.o.provides: CMakeFiles/http_server.dir/HttpContext.cc.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/HttpContext.cc.o.provides.build
.PHONY : CMakeFiles/http_server.dir/HttpContext.cc.o.provides

CMakeFiles/http_server.dir/HttpContext.cc.o.provides.build: CMakeFiles/http_server.dir/HttpContext.cc.o


CMakeFiles/http_server.dir/HttpResponse.cc.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/HttpResponse.cc.o: ../HttpResponse.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/router/Documents/use_muduo/http_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/http_server.dir/HttpResponse.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/HttpResponse.cc.o -c /home/router/Documents/use_muduo/http_server/HttpResponse.cc

CMakeFiles/http_server.dir/HttpResponse.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/HttpResponse.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/router/Documents/use_muduo/http_server/HttpResponse.cc > CMakeFiles/http_server.dir/HttpResponse.cc.i

CMakeFiles/http_server.dir/HttpResponse.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/HttpResponse.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/router/Documents/use_muduo/http_server/HttpResponse.cc -o CMakeFiles/http_server.dir/HttpResponse.cc.s

CMakeFiles/http_server.dir/HttpResponse.cc.o.requires:

.PHONY : CMakeFiles/http_server.dir/HttpResponse.cc.o.requires

CMakeFiles/http_server.dir/HttpResponse.cc.o.provides: CMakeFiles/http_server.dir/HttpResponse.cc.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/HttpResponse.cc.o.provides.build
.PHONY : CMakeFiles/http_server.dir/HttpResponse.cc.o.provides

CMakeFiles/http_server.dir/HttpResponse.cc.o.provides.build: CMakeFiles/http_server.dir/HttpResponse.cc.o


CMakeFiles/http_server.dir/HttpServer.cc.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/HttpServer.cc.o: ../HttpServer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/router/Documents/use_muduo/http_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/http_server.dir/HttpServer.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/HttpServer.cc.o -c /home/router/Documents/use_muduo/http_server/HttpServer.cc

CMakeFiles/http_server.dir/HttpServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/HttpServer.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/router/Documents/use_muduo/http_server/HttpServer.cc > CMakeFiles/http_server.dir/HttpServer.cc.i

CMakeFiles/http_server.dir/HttpServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/HttpServer.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/router/Documents/use_muduo/http_server/HttpServer.cc -o CMakeFiles/http_server.dir/HttpServer.cc.s

CMakeFiles/http_server.dir/HttpServer.cc.o.requires:

.PHONY : CMakeFiles/http_server.dir/HttpServer.cc.o.requires

CMakeFiles/http_server.dir/HttpServer.cc.o.provides: CMakeFiles/http_server.dir/HttpServer.cc.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/HttpServer.cc.o.provides.build
.PHONY : CMakeFiles/http_server.dir/HttpServer.cc.o.provides

CMakeFiles/http_server.dir/HttpServer.cc.o.provides.build: CMakeFiles/http_server.dir/HttpServer.cc.o


# Object files for target http_server
http_server_OBJECTS = \
"CMakeFiles/http_server.dir/httpd.cc.o" \
"CMakeFiles/http_server.dir/HttpContext.cc.o" \
"CMakeFiles/http_server.dir/HttpResponse.cc.o" \
"CMakeFiles/http_server.dir/HttpServer.cc.o"

# External object files for target http_server
http_server_EXTERNAL_OBJECTS =

../bin/http_server: CMakeFiles/http_server.dir/httpd.cc.o
../bin/http_server: CMakeFiles/http_server.dir/HttpContext.cc.o
../bin/http_server: CMakeFiles/http_server.dir/HttpResponse.cc.o
../bin/http_server: CMakeFiles/http_server.dir/HttpServer.cc.o
../bin/http_server: CMakeFiles/http_server.dir/build.make
../bin/http_server: /usr/lib/libmuduo_net.a
../bin/http_server: /usr/lib/libmuduo_base.a
../bin/http_server: CMakeFiles/http_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/router/Documents/use_muduo/http_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../bin/http_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/http_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/http_server.dir/build: ../bin/http_server

.PHONY : CMakeFiles/http_server.dir/build

CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/httpd.cc.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/HttpContext.cc.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/HttpResponse.cc.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/HttpServer.cc.o.requires

.PHONY : CMakeFiles/http_server.dir/requires

CMakeFiles/http_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/http_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/http_server.dir/clean

CMakeFiles/http_server.dir/depend:
	cd /home/router/Documents/use_muduo/http_server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/router/Documents/use_muduo/http_server /home/router/Documents/use_muduo/http_server /home/router/Documents/use_muduo/http_server/build /home/router/Documents/use_muduo/http_server/build /home/router/Documents/use_muduo/http_server/build/CMakeFiles/http_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/http_server.dir/depend
