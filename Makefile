# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/alexander/CLionProjects/TDP005/Campusrunner/campusrunner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexander/CLionProjects/TDP005/Campusrunner/campusrunner

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/alexander/CLionProjects/TDP005/Campusrunner/campusrunner/CMakeFiles /home/alexander/CLionProjects/TDP005/Campusrunner/campusrunner//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/alexander/CLionProjects/TDP005/Campusrunner/campusrunner/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named campusrunner

# Build rule for target.
campusrunner: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 campusrunner
.PHONY : campusrunner

# fast build rule for target.
campusrunner/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/build
.PHONY : campusrunner/fast

Audio_Manager.o: Audio_Manager.cpp.o
.PHONY : Audio_Manager.o

# target to build an object file
Audio_Manager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Audio_Manager.cpp.o
.PHONY : Audio_Manager.cpp.o

Audio_Manager.i: Audio_Manager.cpp.i
.PHONY : Audio_Manager.i

# target to preprocess a source file
Audio_Manager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Audio_Manager.cpp.i
.PHONY : Audio_Manager.cpp.i

Audio_Manager.s: Audio_Manager.cpp.s
.PHONY : Audio_Manager.s

# target to generate assembly for a file
Audio_Manager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Audio_Manager.cpp.s
.PHONY : Audio_Manager.cpp.s

Bouncer.o: Bouncer.cpp.o
.PHONY : Bouncer.o

# target to build an object file
Bouncer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Bouncer.cpp.o
.PHONY : Bouncer.cpp.o

Bouncer.i: Bouncer.cpp.i
.PHONY : Bouncer.i

# target to preprocess a source file
Bouncer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Bouncer.cpp.i
.PHONY : Bouncer.cpp.i

Bouncer.s: Bouncer.cpp.s
.PHONY : Bouncer.s

# target to generate assembly for a file
Bouncer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Bouncer.cpp.s
.PHONY : Bouncer.cpp.s

Bridge.o: Bridge.cpp.o
.PHONY : Bridge.o

# target to build an object file
Bridge.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Bridge.cpp.o
.PHONY : Bridge.cpp.o

Bridge.i: Bridge.cpp.i
.PHONY : Bridge.i

# target to preprocess a source file
Bridge.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Bridge.cpp.i
.PHONY : Bridge.cpp.i

Bridge.s: Bridge.cpp.s
.PHONY : Bridge.s

# target to generate assembly for a file
Bridge.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Bridge.cpp.s
.PHONY : Bridge.cpp.s

Camera.o: Camera.cpp.o
.PHONY : Camera.o

# target to build an object file
Camera.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Camera.cpp.o
.PHONY : Camera.cpp.o

Camera.i: Camera.cpp.i
.PHONY : Camera.i

# target to preprocess a source file
Camera.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Camera.cpp.i
.PHONY : Camera.cpp.i

Camera.s: Camera.cpp.s
.PHONY : Camera.s

# target to generate assembly for a file
Camera.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Camera.cpp.s
.PHONY : Camera.cpp.s

Checkpoint.o: Checkpoint.cpp.o
.PHONY : Checkpoint.o

# target to build an object file
Checkpoint.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Checkpoint.cpp.o
.PHONY : Checkpoint.cpp.o

Checkpoint.i: Checkpoint.cpp.i
.PHONY : Checkpoint.i

# target to preprocess a source file
Checkpoint.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Checkpoint.cpp.i
.PHONY : Checkpoint.cpp.i

Checkpoint.s: Checkpoint.cpp.s
.PHONY : Checkpoint.s

# target to generate assembly for a file
Checkpoint.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Checkpoint.cpp.s
.PHONY : Checkpoint.cpp.s

Door.o: Door.cpp.o
.PHONY : Door.o

# target to build an object file
Door.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Door.cpp.o
.PHONY : Door.cpp.o

Door.i: Door.cpp.i
.PHONY : Door.i

# target to preprocess a source file
Door.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Door.cpp.i
.PHONY : Door.cpp.i

Door.s: Door.cpp.s
.PHONY : Door.s

# target to generate assembly for a file
Door.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Door.cpp.s
.PHONY : Door.cpp.s

Enemy.o: Enemy.cpp.o
.PHONY : Enemy.o

# target to build an object file
Enemy.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Enemy.cpp.o
.PHONY : Enemy.cpp.o

Enemy.i: Enemy.cpp.i
.PHONY : Enemy.i

# target to preprocess a source file
Enemy.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Enemy.cpp.i
.PHONY : Enemy.cpp.i

Enemy.s: Enemy.cpp.s
.PHONY : Enemy.s

# target to generate assembly for a file
Enemy.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Enemy.cpp.s
.PHONY : Enemy.cpp.s

Fan.o: Fan.cpp.o
.PHONY : Fan.o

# target to build an object file
Fan.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Fan.cpp.o
.PHONY : Fan.cpp.o

Fan.i: Fan.cpp.i
.PHONY : Fan.i

# target to preprocess a source file
Fan.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Fan.cpp.i
.PHONY : Fan.cpp.i

Fan.s: Fan.cpp.s
.PHONY : Fan.s

# target to generate assembly for a file
Fan.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Fan.cpp.s
.PHONY : Fan.cpp.s

Flamer.o: Flamer.cpp.o
.PHONY : Flamer.o

# target to build an object file
Flamer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Flamer.cpp.o
.PHONY : Flamer.cpp.o

Flamer.i: Flamer.cpp.i
.PHONY : Flamer.i

# target to preprocess a source file
Flamer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Flamer.cpp.i
.PHONY : Flamer.cpp.i

Flamer.s: Flamer.cpp.s
.PHONY : Flamer.s

# target to generate assembly for a file
Flamer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Flamer.cpp.s
.PHONY : Flamer.cpp.s

Game_Complete_State.o: Game_Complete_State.cpp.o
.PHONY : Game_Complete_State.o

# target to build an object file
Game_Complete_State.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Complete_State.cpp.o
.PHONY : Game_Complete_State.cpp.o

Game_Complete_State.i: Game_Complete_State.cpp.i
.PHONY : Game_Complete_State.i

# target to preprocess a source file
Game_Complete_State.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Complete_State.cpp.i
.PHONY : Game_Complete_State.cpp.i

Game_Complete_State.s: Game_Complete_State.cpp.s
.PHONY : Game_Complete_State.s

# target to generate assembly for a file
Game_Complete_State.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Complete_State.cpp.s
.PHONY : Game_Complete_State.cpp.s

Game_Engine.o: Game_Engine.cpp.o
.PHONY : Game_Engine.o

# target to build an object file
Game_Engine.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Engine.cpp.o
.PHONY : Game_Engine.cpp.o

Game_Engine.i: Game_Engine.cpp.i
.PHONY : Game_Engine.i

# target to preprocess a source file
Game_Engine.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Engine.cpp.i
.PHONY : Game_Engine.cpp.i

Game_Engine.s: Game_Engine.cpp.s
.PHONY : Game_Engine.s

# target to generate assembly for a file
Game_Engine.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Engine.cpp.s
.PHONY : Game_Engine.cpp.s

Game_Object.o: Game_Object.cpp.o
.PHONY : Game_Object.o

# target to build an object file
Game_Object.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Object.cpp.o
.PHONY : Game_Object.cpp.o

Game_Object.i: Game_Object.cpp.i
.PHONY : Game_Object.i

# target to preprocess a source file
Game_Object.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Object.cpp.i
.PHONY : Game_Object.cpp.i

Game_Object.s: Game_Object.cpp.s
.PHONY : Game_Object.s

# target to generate assembly for a file
Game_Object.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Object.cpp.s
.PHONY : Game_Object.cpp.s

Game_Over_State.o: Game_Over_State.cpp.o
.PHONY : Game_Over_State.o

# target to build an object file
Game_Over_State.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Over_State.cpp.o
.PHONY : Game_Over_State.cpp.o

Game_Over_State.i: Game_Over_State.cpp.i
.PHONY : Game_Over_State.i

# target to preprocess a source file
Game_Over_State.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Over_State.cpp.i
.PHONY : Game_Over_State.cpp.i

Game_Over_State.s: Game_Over_State.cpp.s
.PHONY : Game_Over_State.s

# target to generate assembly for a file
Game_Over_State.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Game_Over_State.cpp.s
.PHONY : Game_Over_State.cpp.s

Harmful_Block.o: Harmful_Block.cpp.o
.PHONY : Harmful_Block.o

# target to build an object file
Harmful_Block.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Harmful_Block.cpp.o
.PHONY : Harmful_Block.cpp.o

Harmful_Block.i: Harmful_Block.cpp.i
.PHONY : Harmful_Block.i

# target to preprocess a source file
Harmful_Block.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Harmful_Block.cpp.i
.PHONY : Harmful_Block.cpp.i

Harmful_Block.s: Harmful_Block.cpp.s
.PHONY : Harmful_Block.s

# target to generate assembly for a file
Harmful_Block.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Harmful_Block.cpp.s
.PHONY : Harmful_Block.cpp.s

Healthpack.o: Healthpack.cpp.o
.PHONY : Healthpack.o

# target to build an object file
Healthpack.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Healthpack.cpp.o
.PHONY : Healthpack.cpp.o

Healthpack.i: Healthpack.cpp.i
.PHONY : Healthpack.i

# target to preprocess a source file
Healthpack.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Healthpack.cpp.i
.PHONY : Healthpack.cpp.i

Healthpack.s: Healthpack.cpp.s
.PHONY : Healthpack.s

# target to generate assembly for a file
Healthpack.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Healthpack.cpp.s
.PHONY : Healthpack.cpp.s

Launcher.o: Launcher.cpp.o
.PHONY : Launcher.o

# target to build an object file
Launcher.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Launcher.cpp.o
.PHONY : Launcher.cpp.o

Launcher.i: Launcher.cpp.i
.PHONY : Launcher.i

# target to preprocess a source file
Launcher.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Launcher.cpp.i
.PHONY : Launcher.cpp.i

Launcher.s: Launcher.cpp.s
.PHONY : Launcher.s

# target to generate assembly for a file
Launcher.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Launcher.cpp.s
.PHONY : Launcher.cpp.s

Map.o: Map.cpp.o
.PHONY : Map.o

# target to build an object file
Map.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Map.cpp.o
.PHONY : Map.cpp.o

Map.i: Map.cpp.i
.PHONY : Map.i

# target to preprocess a source file
Map.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Map.cpp.i
.PHONY : Map.cpp.i

Map.s: Map.cpp.s
.PHONY : Map.s

# target to generate assembly for a file
Map.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Map.cpp.s
.PHONY : Map.cpp.s

Menu_State.o: Menu_State.cpp.o
.PHONY : Menu_State.o

# target to build an object file
Menu_State.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Menu_State.cpp.o
.PHONY : Menu_State.cpp.o

Menu_State.i: Menu_State.cpp.i
.PHONY : Menu_State.i

# target to preprocess a source file
Menu_State.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Menu_State.cpp.i
.PHONY : Menu_State.cpp.i

Menu_State.s: Menu_State.cpp.s
.PHONY : Menu_State.s

# target to generate assembly for a file
Menu_State.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Menu_State.cpp.s
.PHONY : Menu_State.cpp.s

Moving_Block.o: Moving_Block.cpp.o
.PHONY : Moving_Block.o

# target to build an object file
Moving_Block.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Moving_Block.cpp.o
.PHONY : Moving_Block.cpp.o

Moving_Block.i: Moving_Block.cpp.i
.PHONY : Moving_Block.i

# target to preprocess a source file
Moving_Block.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Moving_Block.cpp.i
.PHONY : Moving_Block.cpp.i

Moving_Block.s: Moving_Block.cpp.s
.PHONY : Moving_Block.s

# target to generate assembly for a file
Moving_Block.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Moving_Block.cpp.s
.PHONY : Moving_Block.cpp.s

Moving_Object.o: Moving_Object.cpp.o
.PHONY : Moving_Object.o

# target to build an object file
Moving_Object.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Moving_Object.cpp.o
.PHONY : Moving_Object.cpp.o

Moving_Object.i: Moving_Object.cpp.i
.PHONY : Moving_Object.i

# target to preprocess a source file
Moving_Object.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Moving_Object.cpp.i
.PHONY : Moving_Object.cpp.i

Moving_Object.s: Moving_Object.cpp.s
.PHONY : Moving_Object.s

# target to generate assembly for a file
Moving_Object.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Moving_Object.cpp.s
.PHONY : Moving_Object.cpp.s

Pause_State.o: Pause_State.cpp.o
.PHONY : Pause_State.o

# target to build an object file
Pause_State.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Pause_State.cpp.o
.PHONY : Pause_State.cpp.o

Pause_State.i: Pause_State.cpp.i
.PHONY : Pause_State.i

# target to preprocess a source file
Pause_State.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Pause_State.cpp.i
.PHONY : Pause_State.cpp.i

Pause_State.s: Pause_State.cpp.s
.PHONY : Pause_State.s

# target to generate assembly for a file
Pause_State.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Pause_State.cpp.s
.PHONY : Pause_State.cpp.s

Play_State.o: Play_State.cpp.o
.PHONY : Play_State.o

# target to build an object file
Play_State.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Play_State.cpp.o
.PHONY : Play_State.cpp.o

Play_State.i: Play_State.cpp.i
.PHONY : Play_State.i

# target to preprocess a source file
Play_State.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Play_State.cpp.i
.PHONY : Play_State.cpp.i

Play_State.s: Play_State.cpp.s
.PHONY : Play_State.s

# target to generate assembly for a file
Play_State.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Play_State.cpp.s
.PHONY : Play_State.cpp.s

Player.o: Player.cpp.o
.PHONY : Player.o

# target to build an object file
Player.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Player.cpp.o
.PHONY : Player.cpp.o

Player.i: Player.cpp.i
.PHONY : Player.i

# target to preprocess a source file
Player.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Player.cpp.i
.PHONY : Player.cpp.i

Player.s: Player.cpp.s
.PHONY : Player.s

# target to generate assembly for a file
Player.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Player.cpp.s
.PHONY : Player.cpp.s

Prolog_State.o: Prolog_State.cpp.o
.PHONY : Prolog_State.o

# target to build an object file
Prolog_State.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Prolog_State.cpp.o
.PHONY : Prolog_State.cpp.o

Prolog_State.i: Prolog_State.cpp.i
.PHONY : Prolog_State.i

# target to preprocess a source file
Prolog_State.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Prolog_State.cpp.i
.PHONY : Prolog_State.cpp.i

Prolog_State.s: Prolog_State.cpp.s
.PHONY : Prolog_State.s

# target to generate assembly for a file
Prolog_State.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Prolog_State.cpp.s
.PHONY : Prolog_State.cpp.s

Rolling_Stone.o: Rolling_Stone.cpp.o
.PHONY : Rolling_Stone.o

# target to build an object file
Rolling_Stone.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Rolling_Stone.cpp.o
.PHONY : Rolling_Stone.cpp.o

Rolling_Stone.i: Rolling_Stone.cpp.i
.PHONY : Rolling_Stone.i

# target to preprocess a source file
Rolling_Stone.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Rolling_Stone.cpp.i
.PHONY : Rolling_Stone.cpp.i

Rolling_Stone.s: Rolling_Stone.cpp.s
.PHONY : Rolling_Stone.s

# target to generate assembly for a file
Rolling_Stone.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Rolling_Stone.cpp.s
.PHONY : Rolling_Stone.cpp.s

Solid_Block.o: Solid_Block.cpp.o
.PHONY : Solid_Block.o

# target to build an object file
Solid_Block.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Solid_Block.cpp.o
.PHONY : Solid_Block.cpp.o

Solid_Block.i: Solid_Block.cpp.i
.PHONY : Solid_Block.i

# target to preprocess a source file
Solid_Block.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Solid_Block.cpp.i
.PHONY : Solid_Block.cpp.i

Solid_Block.s: Solid_Block.cpp.s
.PHONY : Solid_Block.s

# target to generate assembly for a file
Solid_Block.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Solid_Block.cpp.s
.PHONY : Solid_Block.cpp.s

State.o: State.cpp.o
.PHONY : State.o

# target to build an object file
State.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/State.cpp.o
.PHONY : State.cpp.o

State.i: State.cpp.i
.PHONY : State.i

# target to preprocess a source file
State.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/State.cpp.i
.PHONY : State.cpp.i

State.s: State.cpp.s
.PHONY : State.s

# target to generate assembly for a file
State.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/State.cpp.s
.PHONY : State.cpp.s

Texture_Manager.o: Texture_Manager.cpp.o
.PHONY : Texture_Manager.o

# target to build an object file
Texture_Manager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Texture_Manager.cpp.o
.PHONY : Texture_Manager.cpp.o

Texture_Manager.i: Texture_Manager.cpp.i
.PHONY : Texture_Manager.i

# target to preprocess a source file
Texture_Manager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Texture_Manager.cpp.i
.PHONY : Texture_Manager.cpp.i

Texture_Manager.s: Texture_Manager.cpp.s
.PHONY : Texture_Manager.s

# target to generate assembly for a file
Texture_Manager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Texture_Manager.cpp.s
.PHONY : Texture_Manager.cpp.s

Treasure.o: Treasure.cpp.o
.PHONY : Treasure.o

# target to build an object file
Treasure.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Treasure.cpp.o
.PHONY : Treasure.cpp.o

Treasure.i: Treasure.cpp.i
.PHONY : Treasure.i

# target to preprocess a source file
Treasure.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Treasure.cpp.i
.PHONY : Treasure.cpp.i

Treasure.s: Treasure.cpp.s
.PHONY : Treasure.s

# target to generate assembly for a file
Treasure.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/Treasure.cpp.s
.PHONY : Treasure.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/campusrunner.dir/build.make CMakeFiles/campusrunner.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... campusrunner"
	@echo "... Audio_Manager.o"
	@echo "... Audio_Manager.i"
	@echo "... Audio_Manager.s"
	@echo "... Bouncer.o"
	@echo "... Bouncer.i"
	@echo "... Bouncer.s"
	@echo "... Bridge.o"
	@echo "... Bridge.i"
	@echo "... Bridge.s"
	@echo "... Camera.o"
	@echo "... Camera.i"
	@echo "... Camera.s"
	@echo "... Checkpoint.o"
	@echo "... Checkpoint.i"
	@echo "... Checkpoint.s"
	@echo "... Door.o"
	@echo "... Door.i"
	@echo "... Door.s"
	@echo "... Enemy.o"
	@echo "... Enemy.i"
	@echo "... Enemy.s"
	@echo "... Fan.o"
	@echo "... Fan.i"
	@echo "... Fan.s"
	@echo "... Flamer.o"
	@echo "... Flamer.i"
	@echo "... Flamer.s"
	@echo "... Game_Complete_State.o"
	@echo "... Game_Complete_State.i"
	@echo "... Game_Complete_State.s"
	@echo "... Game_Engine.o"
	@echo "... Game_Engine.i"
	@echo "... Game_Engine.s"
	@echo "... Game_Object.o"
	@echo "... Game_Object.i"
	@echo "... Game_Object.s"
	@echo "... Game_Over_State.o"
	@echo "... Game_Over_State.i"
	@echo "... Game_Over_State.s"
	@echo "... Harmful_Block.o"
	@echo "... Harmful_Block.i"
	@echo "... Harmful_Block.s"
	@echo "... Healthpack.o"
	@echo "... Healthpack.i"
	@echo "... Healthpack.s"
	@echo "... Launcher.o"
	@echo "... Launcher.i"
	@echo "... Launcher.s"
	@echo "... Map.o"
	@echo "... Map.i"
	@echo "... Map.s"
	@echo "... Menu_State.o"
	@echo "... Menu_State.i"
	@echo "... Menu_State.s"
	@echo "... Moving_Block.o"
	@echo "... Moving_Block.i"
	@echo "... Moving_Block.s"
	@echo "... Moving_Object.o"
	@echo "... Moving_Object.i"
	@echo "... Moving_Object.s"
	@echo "... Pause_State.o"
	@echo "... Pause_State.i"
	@echo "... Pause_State.s"
	@echo "... Play_State.o"
	@echo "... Play_State.i"
	@echo "... Play_State.s"
	@echo "... Player.o"
	@echo "... Player.i"
	@echo "... Player.s"
	@echo "... Prolog_State.o"
	@echo "... Prolog_State.i"
	@echo "... Prolog_State.s"
	@echo "... Rolling_Stone.o"
	@echo "... Rolling_Stone.i"
	@echo "... Rolling_Stone.s"
	@echo "... Solid_Block.o"
	@echo "... Solid_Block.i"
	@echo "... Solid_Block.s"
	@echo "... State.o"
	@echo "... State.i"
	@echo "... State.s"
	@echo "... Texture_Manager.o"
	@echo "... Texture_Manager.i"
	@echo "... Texture_Manager.s"
	@echo "... Treasure.o"
	@echo "... Treasure.i"
	@echo "... Treasure.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

