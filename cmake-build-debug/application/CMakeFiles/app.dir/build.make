# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\code\C++\GLFW_Draw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\code\C++\GLFW_Draw\cmake-build-debug

# Include any dependencies generated for this target.
include application/CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include application/CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include application/CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include application/CMakeFiles/app.dir/flags.make

application/CMakeFiles/app.dir/Application.cpp.obj: application/CMakeFiles/app.dir/flags.make
application/CMakeFiles/app.dir/Application.cpp.obj: application/CMakeFiles/app.dir/includes_CXX.rsp
application/CMakeFiles/app.dir/Application.cpp.obj: D:/code/C++/GLFW_Draw/application/Application.cpp
application/CMakeFiles/app.dir/Application.cpp.obj: application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\C++\GLFW_Draw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object application/CMakeFiles/app.dir/Application.cpp.obj"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT application/CMakeFiles/app.dir/Application.cpp.obj -MF CMakeFiles\app.dir\Application.cpp.obj.d -o CMakeFiles\app.dir\Application.cpp.obj -c D:\code\C++\GLFW_Draw\application\Application.cpp

application/CMakeFiles/app.dir/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/Application.cpp.i"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\C++\GLFW_Draw\application\Application.cpp > CMakeFiles\app.dir\Application.cpp.i

application/CMakeFiles/app.dir/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/Application.cpp.s"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\C++\GLFW_Draw\application\Application.cpp -o CMakeFiles\app.dir\Application.cpp.s

application/CMakeFiles/app.dir/camera/camera.cpp.obj: application/CMakeFiles/app.dir/flags.make
application/CMakeFiles/app.dir/camera/camera.cpp.obj: application/CMakeFiles/app.dir/includes_CXX.rsp
application/CMakeFiles/app.dir/camera/camera.cpp.obj: D:/code/C++/GLFW_Draw/application/camera/camera.cpp
application/CMakeFiles/app.dir/camera/camera.cpp.obj: application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\C++\GLFW_Draw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object application/CMakeFiles/app.dir/camera/camera.cpp.obj"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT application/CMakeFiles/app.dir/camera/camera.cpp.obj -MF CMakeFiles\app.dir\camera\camera.cpp.obj.d -o CMakeFiles\app.dir\camera\camera.cpp.obj -c D:\code\C++\GLFW_Draw\application\camera\camera.cpp

application/CMakeFiles/app.dir/camera/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/camera/camera.cpp.i"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\C++\GLFW_Draw\application\camera\camera.cpp > CMakeFiles\app.dir\camera\camera.cpp.i

application/CMakeFiles/app.dir/camera/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/camera/camera.cpp.s"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\C++\GLFW_Draw\application\camera\camera.cpp -o CMakeFiles\app.dir\camera\camera.cpp.s

application/CMakeFiles/app.dir/camera/cameracontrol.cpp.obj: application/CMakeFiles/app.dir/flags.make
application/CMakeFiles/app.dir/camera/cameracontrol.cpp.obj: application/CMakeFiles/app.dir/includes_CXX.rsp
application/CMakeFiles/app.dir/camera/cameracontrol.cpp.obj: D:/code/C++/GLFW_Draw/application/camera/cameracontrol.cpp
application/CMakeFiles/app.dir/camera/cameracontrol.cpp.obj: application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\C++\GLFW_Draw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object application/CMakeFiles/app.dir/camera/cameracontrol.cpp.obj"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT application/CMakeFiles/app.dir/camera/cameracontrol.cpp.obj -MF CMakeFiles\app.dir\camera\cameracontrol.cpp.obj.d -o CMakeFiles\app.dir\camera\cameracontrol.cpp.obj -c D:\code\C++\GLFW_Draw\application\camera\cameracontrol.cpp

application/CMakeFiles/app.dir/camera/cameracontrol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/camera/cameracontrol.cpp.i"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\C++\GLFW_Draw\application\camera\cameracontrol.cpp > CMakeFiles\app.dir\camera\cameracontrol.cpp.i

application/CMakeFiles/app.dir/camera/cameracontrol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/camera/cameracontrol.cpp.s"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\C++\GLFW_Draw\application\camera\cameracontrol.cpp -o CMakeFiles\app.dir\camera\cameracontrol.cpp.s

application/CMakeFiles/app.dir/camera/gamecameracontrol.cpp.obj: application/CMakeFiles/app.dir/flags.make
application/CMakeFiles/app.dir/camera/gamecameracontrol.cpp.obj: application/CMakeFiles/app.dir/includes_CXX.rsp
application/CMakeFiles/app.dir/camera/gamecameracontrol.cpp.obj: D:/code/C++/GLFW_Draw/application/camera/gamecameracontrol.cpp
application/CMakeFiles/app.dir/camera/gamecameracontrol.cpp.obj: application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\C++\GLFW_Draw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object application/CMakeFiles/app.dir/camera/gamecameracontrol.cpp.obj"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT application/CMakeFiles/app.dir/camera/gamecameracontrol.cpp.obj -MF CMakeFiles\app.dir\camera\gamecameracontrol.cpp.obj.d -o CMakeFiles\app.dir\camera\gamecameracontrol.cpp.obj -c D:\code\C++\GLFW_Draw\application\camera\gamecameracontrol.cpp

application/CMakeFiles/app.dir/camera/gamecameracontrol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/camera/gamecameracontrol.cpp.i"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\C++\GLFW_Draw\application\camera\gamecameracontrol.cpp > CMakeFiles\app.dir\camera\gamecameracontrol.cpp.i

application/CMakeFiles/app.dir/camera/gamecameracontrol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/camera/gamecameracontrol.cpp.s"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\C++\GLFW_Draw\application\camera\gamecameracontrol.cpp -o CMakeFiles\app.dir\camera\gamecameracontrol.cpp.s

application/CMakeFiles/app.dir/camera/orthocamera.cpp.obj: application/CMakeFiles/app.dir/flags.make
application/CMakeFiles/app.dir/camera/orthocamera.cpp.obj: application/CMakeFiles/app.dir/includes_CXX.rsp
application/CMakeFiles/app.dir/camera/orthocamera.cpp.obj: D:/code/C++/GLFW_Draw/application/camera/orthocamera.cpp
application/CMakeFiles/app.dir/camera/orthocamera.cpp.obj: application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\C++\GLFW_Draw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object application/CMakeFiles/app.dir/camera/orthocamera.cpp.obj"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT application/CMakeFiles/app.dir/camera/orthocamera.cpp.obj -MF CMakeFiles\app.dir\camera\orthocamera.cpp.obj.d -o CMakeFiles\app.dir\camera\orthocamera.cpp.obj -c D:\code\C++\GLFW_Draw\application\camera\orthocamera.cpp

application/CMakeFiles/app.dir/camera/orthocamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/camera/orthocamera.cpp.i"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\C++\GLFW_Draw\application\camera\orthocamera.cpp > CMakeFiles\app.dir\camera\orthocamera.cpp.i

application/CMakeFiles/app.dir/camera/orthocamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/camera/orthocamera.cpp.s"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\C++\GLFW_Draw\application\camera\orthocamera.cpp -o CMakeFiles\app.dir\camera\orthocamera.cpp.s

application/CMakeFiles/app.dir/camera/perspectivecamera.cpp.obj: application/CMakeFiles/app.dir/flags.make
application/CMakeFiles/app.dir/camera/perspectivecamera.cpp.obj: application/CMakeFiles/app.dir/includes_CXX.rsp
application/CMakeFiles/app.dir/camera/perspectivecamera.cpp.obj: D:/code/C++/GLFW_Draw/application/camera/perspectivecamera.cpp
application/CMakeFiles/app.dir/camera/perspectivecamera.cpp.obj: application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\C++\GLFW_Draw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object application/CMakeFiles/app.dir/camera/perspectivecamera.cpp.obj"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT application/CMakeFiles/app.dir/camera/perspectivecamera.cpp.obj -MF CMakeFiles\app.dir\camera\perspectivecamera.cpp.obj.d -o CMakeFiles\app.dir\camera\perspectivecamera.cpp.obj -c D:\code\C++\GLFW_Draw\application\camera\perspectivecamera.cpp

application/CMakeFiles/app.dir/camera/perspectivecamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/camera/perspectivecamera.cpp.i"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\C++\GLFW_Draw\application\camera\perspectivecamera.cpp > CMakeFiles\app.dir\camera\perspectivecamera.cpp.i

application/CMakeFiles/app.dir/camera/perspectivecamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/camera/perspectivecamera.cpp.s"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\C++\GLFW_Draw\application\camera\perspectivecamera.cpp -o CMakeFiles\app.dir\camera\perspectivecamera.cpp.s

application/CMakeFiles/app.dir/camera/trackballcamera.cpp.obj: application/CMakeFiles/app.dir/flags.make
application/CMakeFiles/app.dir/camera/trackballcamera.cpp.obj: application/CMakeFiles/app.dir/includes_CXX.rsp
application/CMakeFiles/app.dir/camera/trackballcamera.cpp.obj: D:/code/C++/GLFW_Draw/application/camera/trackballcamera.cpp
application/CMakeFiles/app.dir/camera/trackballcamera.cpp.obj: application/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\C++\GLFW_Draw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object application/CMakeFiles/app.dir/camera/trackballcamera.cpp.obj"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT application/CMakeFiles/app.dir/camera/trackballcamera.cpp.obj -MF CMakeFiles\app.dir\camera\trackballcamera.cpp.obj.d -o CMakeFiles\app.dir\camera\trackballcamera.cpp.obj -c D:\code\C++\GLFW_Draw\application\camera\trackballcamera.cpp

application/CMakeFiles/app.dir/camera/trackballcamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/camera/trackballcamera.cpp.i"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\C++\GLFW_Draw\application\camera\trackballcamera.cpp > CMakeFiles\app.dir\camera\trackballcamera.cpp.i

application/CMakeFiles/app.dir/camera/trackballcamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/camera/trackballcamera.cpp.s"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && "D:\Program Files\JetBrains\CLion 2023.2.2\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\C++\GLFW_Draw\application\camera\trackballcamera.cpp -o CMakeFiles\app.dir\camera\trackballcamera.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/Application.cpp.obj" \
"CMakeFiles/app.dir/camera/camera.cpp.obj" \
"CMakeFiles/app.dir/camera/cameracontrol.cpp.obj" \
"CMakeFiles/app.dir/camera/gamecameracontrol.cpp.obj" \
"CMakeFiles/app.dir/camera/orthocamera.cpp.obj" \
"CMakeFiles/app.dir/camera/perspectivecamera.cpp.obj" \
"CMakeFiles/app.dir/camera/trackballcamera.cpp.obj"

# External object files for target app
app_EXTERNAL_OBJECTS =

application/libapp.a: application/CMakeFiles/app.dir/Application.cpp.obj
application/libapp.a: application/CMakeFiles/app.dir/camera/camera.cpp.obj
application/libapp.a: application/CMakeFiles/app.dir/camera/cameracontrol.cpp.obj
application/libapp.a: application/CMakeFiles/app.dir/camera/gamecameracontrol.cpp.obj
application/libapp.a: application/CMakeFiles/app.dir/camera/orthocamera.cpp.obj
application/libapp.a: application/CMakeFiles/app.dir/camera/perspectivecamera.cpp.obj
application/libapp.a: application/CMakeFiles/app.dir/camera/trackballcamera.cpp.obj
application/libapp.a: application/CMakeFiles/app.dir/build.make
application/libapp.a: application/CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\code\C++\GLFW_Draw\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libapp.a"
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && $(CMAKE_COMMAND) -P CMakeFiles\app.dir\cmake_clean_target.cmake
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\app.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/CMakeFiles/app.dir/build: application/libapp.a
.PHONY : application/CMakeFiles/app.dir/build

application/CMakeFiles/app.dir/clean:
	cd /d D:\code\C++\GLFW_Draw\cmake-build-debug\application && $(CMAKE_COMMAND) -P CMakeFiles\app.dir\cmake_clean.cmake
.PHONY : application/CMakeFiles/app.dir/clean

application/CMakeFiles/app.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\code\C++\GLFW_Draw D:\code\C++\GLFW_Draw\application D:\code\C++\GLFW_Draw\cmake-build-debug D:\code\C++\GLFW_Draw\cmake-build-debug\application D:\code\C++\GLFW_Draw\cmake-build-debug\application\CMakeFiles\app.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : application/CMakeFiles/app.dir/depend

