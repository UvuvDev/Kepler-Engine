#pragma once
#include <stdint.h>
#include <utility>

class GraphicsEngine {
private:

	int screenHeight, screenWidth;

	bool isPaused;

	uint16_t targetFPS;


public:

	GraphicsEngine(std::pair<uint16_t, uint16_t> dimensions); // X is width, Y is height

	GraphicsEngine(std::pair <uint16_t, uint16_t> dimensions, uint16_t targetFPSArg);

	bool initCustomWindow();

	bool mainRenderLoop();

	bool deleteWindow();

	bool fullscreen();





};
