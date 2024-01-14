cmake_minimum_required(VERSION 3.26)
project(KeplerEngine)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/resources
)
link_directories(${CMAKE_SOURCE_DIR}/library)

ADD_LIBRARY(Raylib
        library/junksrc.cpp
)

target_link_libraries(Raylib -LRaylib)
target_link_libraries(Raylib libraylib.a
    winMM.Lib)

add_executable(KeplerEngine main.cpp
        AnimationHandler.cpp
        BaseClass.cpp
        Audio.cpp
        Bullet.cpp
        Character.cpp
        Entity.cpp
        Graphics.cpp
        Gun.cpp
        InputHandler.cpp
        Item.cpp
        Level.cpp
        Loader.cpp
        Platform.cpp
        UI.cpp
        Weapon.cpp
        library/junksrc.cpp
        include/non-library-includes/Sword.hpp
        non-library-sources/Sword.cpp
        include/non-library-includes/ElementalSword.hpp
        non-library-sources/ElementalSword.cpp)


target_link_libraries(KeplerEngine Raylib) # libbar.so is found in ${CMAKE_SOURCE_DIR}/lib
