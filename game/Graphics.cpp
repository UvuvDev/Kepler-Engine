
#include "Graphics.hpp"
#include "GUIConfig.hpp"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION 
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION


GraphicsEngine::GraphicsEngine(Vector2 dimensions) {

	screenWidth = dimensions.x;
	screenHeight = dimensions.y;

	isPaused = false;
	showFPS = true;
	targetFPS = 60;

	screenToRender.width = dimensions.x;
	screenToRender.height = dimensions.y;


}


GraphicsEngine::GraphicsEngine(Vector2 dimensions, uint16_t targetFPSArg) {

	screenWidth = dimensions.x;
	screenHeight = dimensions.y;

	isPaused = false;
	showFPS = true;
	targetFPS = targetFPSArg;

	screenToRender.width = dimensions.x;
	screenToRender.height = dimensions.y;


}


bool GraphicsEngine::initCustomWindow() {

	InitWindow(screenHeight, screenWidth, GUIName);
	InitAudioDevice();
	SetTargetFPS(targetFPS);

	return true;

}



bool GraphicsEngine::mainRenderLoop() {

	BeginDrawing();

	ClearBackground(WHITE);

	if (showFPS == true) {
		DrawFPS(50, 50);
	}
	
	makeButton(500, 500);

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

