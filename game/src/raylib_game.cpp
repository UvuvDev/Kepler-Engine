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





int main() {	

	GraphicsEngine GraphicsEng ( { 700, 1000 } , 60);
	 
	GraphicsEng.initCustomWindow();

	Loader loader;

	loader.load();

	//loader.textureMap["Entity"];

	//Entity testentity( std::make_shared<std::unordered_map<std::string, std::shared_ptr<Texture2D>>>(loader.textureMap) );

	Level level;

	Character playerCharacter(std::make_shared<std::unordered_map<std::string, std::shared_ptr<Texture2D>>>(loader.textureMap),
		std::make_shared<Level>(level));

	//Texture2D texture = LoadTexture("resources/logo.png");

	//std::cout << GetMonitorHeight(0); // Haha getMonitorHeight returns only memory address <3 Fix in graphics.cpp

	level.platforms.makeNewPlatform({ 100, 100 }, { 100, 100 });

	while ( !WindowShouldClose() ) {

		GraphicsEng.mainRenderLoop();

		playerCharacter.update();

		

		level.update();

		std::cout << "\n\n";

	}
	

}




