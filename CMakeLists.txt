cmake_minimum_required(VERSION 3.16)
project(campusrunner)

set(CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

if (DEFINED ENV{LOADEDMODULES} AND ("$ENV{LOADEDMODULES}" MATCHES ".*prog/gcc/6.1.0.*"))
    set(CMAKE_CXX_COMPILER /sw/gcc-6.1.0/bin/g++)
    if (DEFINED ENV{SFML_ROOT})
        list(APPEND CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/share/SFML/cmake/Modules")
    endif ()
endif ()

set(SFML_MODULES network graphics audio window system)

find_package (SFML 2 COMPONENTS ${SFML_MODULES})
include_directories (${SFML_INCLUDE_DIR})

if (NOT (${SFML_FOUND} STREQUAL "TRUE"))
    set( SFML_LIBRARIES "")
    foreach (i ${SFML_MODULES})
        list(APPEND SFML_LIBRARIES "sfml-${i}")
    endforeach (i)
endif ()

set(SOURCE_FILES main.cpp Game_Engine.cpp Game_Engine.h Game_Object.cpp Game_Object.h Moving_Object.cpp Moving_Object.h Solid_Block.cpp Solid_Block.h Texture_Manager.cpp Texture_Manager.h Map.cpp Map.h State.cpp State.h Play_State.cpp Play_State.h Player.cpp Player.h Camera.cpp Camera.h constants.h Enemy.cpp Enemy.h Harmful_Block.cpp Harmful_Block.h Menu_State.cpp Menu_State.h Pause_State.cpp Pause_State.h Door.cpp Door.h Treasure.cpp Treasure.h Prolog_State.cpp Prolog_State.h Game_Over_State.cpp Game_Over_State.h State_Action.h Launcher.cpp Launcher.h Bouncer.cpp Bouncer.h Flamer.cpp Flamer.h Bridge.cpp Bridge.h Rolling_Stone.cpp Rolling_Stone.h Fan.cpp Fan.h Moving_Block.cpp Moving_Block.h Checkpoint.cpp Checkpoint.h Healthpack.cpp Healthpack.h Game_Complete_State.cpp Game_Complete_State.h Audio_Manager.cpp Audio_Manager.h)
add_executable(campusrunner ${SOURCE_FILES})
target_link_libraries (campusrunner ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
