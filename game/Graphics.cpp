
#include "Graphics.hpp"
#include "GUIConfig.hpp"
#include "raylib.h"


GraphicsEngine::GraphicsEngine(std::pair <uint16_t, uint16_t> dimensions) {
	screenWidth = dimensions.first;
	screenHeight = dimensions.second;
	isPaused = false;
	targetFPS = 60;
}


GraphicsEngine::GraphicsEngine(std::pair <uint16_t, uint16_t> dimensions, uint16_t targetFPSArg) {
	screenWidth = dimensions.first;
	screenHeight = dimensions.second;
	isPaused = false;
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
