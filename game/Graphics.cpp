
#include "Graphics.hpp"
#include "GUIConfig.hpp"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION 
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION


GraphicsEngine::GraphicsEngine(std::pair <uint16_t, uint16_t> dimensions) {

	screenWidth = dimensions.first;
	screenHeight = dimensions.second;
	isPaused = false;
	showFPS = true;
	targetFPS = 60;

}


GraphicsEngine::GraphicsEngine(std::pair <uint16_t, uint16_t> dimensions, uint16_t targetFPSArg) {

	screenWidth = dimensions.first;
	screenHeight = dimensions.second;
	isPaused = false;
	showFPS = true;
	targetFPS = targetFPSArg;

}


bool GraphicsEngine::initCustomWindow() {

	InitWindow(screenHeight, screenWidth, GUIName);
	InitAudioDevice();
	SetTargetFPS(targetFPS);

	return true;

}


bool GraphicsEngine::mainRenderLoop() {

	BeginDrawing();

	ClearBackground(RED);

	if (showFPS == true) {
		DrawFPS(300, 300);
	}

	makeButton(500, 5000);

	EndDrawing();

	return 0;

}

bool GraphicsEngine::deleteWindow() {

	CloseWindow();

	return true;

}

bool GraphicsEngine::fullscreen() {

	SetWindowSize( GetMonitorWidth(1), GetMonitorHeight(1));
	ToggleFullscreen();

	return true;

}

void GraphicsEngine::makeButton(float xcord, float ycord) {

	bool button = GuiButton({ xcord, ycord, 100, 40 }, "Load Game.");

	if ( button ) {
		std::cout << "Button Is Pressed\n";
	}
	else {
		std::cout << "Buttons dead.\n";
	}

}

void GraphicsEngine::goToLink(char* link) {

	/* * * * * * * * * * * * * * * * * * * *
	 *	 
	 * [https://github.com/DancingRicardo/Kepler-Engine/blob/main/README.md] 
	 * 
	 * Example in how to format the link. Use as you wish.
	 * 
	 * * * * * * * * * * * * * * * * * * * */
	
	//ShellExecute(NULL, NULL, link, NULL, NULL, SW_SHOWNORMAL);
	
	
}

