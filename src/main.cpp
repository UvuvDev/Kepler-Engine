/*******************************************************************************************
*
*   raylib game template
*
*   <Game title>
*   <Game description>
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <iostream>

#include "include/raylib-include/raylib.h"
#include "include/Graphics.hpp"
#include "include/BaseClass.hpp"
#include "include/Tag.hpp"
#include "include/Entity.hpp"
#include "include/Loading.hpp"
#include "include/Level.hpp"
#include "include/AnimationHandler.hpp"
#include "include/Character.hpp"
#include "include/Platform.hpp"



#include <memory>
#include <iostream>
#include <random>


int main() {

    srand(time(0));

    GraphicsEngine GraphicsEng ( { 700, 1000 } , 60);

    GraphicsEng.initCustomWindow();

    std::cout << GetWorkingDirectory() << std::endl;

    Loader loader;

    loader.load();


    //loader.textureMap["Entity"];

    //Entity testentity( std::make_shared<std::unordered_map<std::string, std::shared_ptr<Texture2D>>>(loader.textureMap) );


    Level level;

    Level* levelPtr = &level;

    Character playerCharacter(&loader.textureMap, levelPtr);

    std::cout << "\n\n\nInitialzing Level\n\n\n";


    //Texture2D texture = LoadTexture("resources/logo.png");

    std::cout << "Beginning generation"; // Haha getMonitorHeight returns only memory address <3 Fix in graphics.cpp

    float randomNumberX = rand() % 600;
    float randomNumberY = 900;

    levelPtr->platforms.makeNewPlatform({ 200, 800 }, {200, 150});

    randomNumberX = rand() % 600;
    randomNumberY = rand() % 600;

    levelPtr->platforms.makeNewPlatform({ randomNumberX, randomNumberY }, { 200, 50 });

    randomNumberX = rand() % 600;
    randomNumberY = rand() % 600;

    levelPtr->platforms.makeNewPlatform({ randomNumberX, randomNumberY }, { 200, 50 });

    randomNumberX = rand() % 600;
    randomNumberY = rand() % 600;

    levelPtr->platforms.makeNewPlatform({ randomNumberX, randomNumberY }, { 200, 50 });

    randomNumberX = rand() % 600;
    randomNumberY = rand() % 600;

    levelPtr->platforms.makeNewPlatform({ randomNumberX, randomNumberY }, { 200, 50 });

    std::cout << "fwfqefqqwfqw";

    while ( !WindowShouldClose() ) {

        GraphicsEng.mainRenderLoop();

        playerCharacter.update();

        levelPtr->update();

        //levelPtr->coordsToCheckCollision({ 100, 100 });

        std::cout << "\n\n";

    }


}





