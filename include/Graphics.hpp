#pragma once
#include <stdint.h>
#include <iostream>
#include <utility>
#include "raylib-include/raylib.h"

class GraphicsEngine {
private:

	Rectangle screenToRender;

	int screenHeight, screenWidth;

	bool isPaused;

	bool showFPS;

	uint16_t targetFPS;

public:

	GraphicsEngine(Vector2 dimensions); // X is width, Y is height

	GraphicsEngine(Vector2 dimensions, uint16_t targetFPSArg);

	bool initCustomWindow();

	bool mainRenderLoop();

	bool deleteWindow();

	bool fullscreen();

	void makeButton(float xcord, float ycord);

	void goToLink(char* link);


};
