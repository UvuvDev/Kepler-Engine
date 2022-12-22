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

#include "raylib.h"
#include "Graphics.hpp"
#include "BaseClass.hpp"
#include "Tag.hpp"
#include "Entity.hpp"
#include "Loading.hpp"
#include "Level.hpp"
#include "AnimationHandler.hpp"
#include "Character.hpp"
#include "Platform.hpp"

#include <memory>
#include <iostream>
#include <random>



int main() {	

	srand(time(0));

	GraphicsEngine GraphicsEng ( { 700, 1000 } , 60);
	 
	GraphicsEng.initCustomWindow();

	Loader loader;

	loader.load();

	//loader.textureMap["Entity"];

	//Entity testentity( std::make_shared<std::unordered_map<std::string, std::shared_ptr<Texture2D>>>(loader.textureMap) );

	Level level;

	Level* levelPtr = &level;

	Character playerCharacter(loader.textureMap, levelPtr);

	//Texture2D texture = LoadTexture("resources/logo.png");

	std::cout << "GRIOGJRWEOIGJERIOGJERIGOREJGOIERJGRWEOIGJREO"; // Haha getMonitorHeight returns only memory address <3 Fix in graphics.cpp

	float randomNumberX = rand() % 600;
	float randomNumberY = rand() % 600;
	
	levelPtr->platforms.makeNewPlatform({ randomNumberX, randomNumberY }, {200, 50});

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




