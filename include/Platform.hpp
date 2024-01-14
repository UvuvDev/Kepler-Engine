#pragma once
#include "BaseClass.hpp"
#include "raylib-include/raylib.h"
#include <memory>

class Platforms : BaseClass {
private:

	

	Vector2 coords;
	Vector2 movementVector;
	bool hasCollision;
	bool canMove;

	uint16_t defaultWidth;
	uint16_t defaultHeight;

public: 

	std::vector<Rectangle> platformVector;

	Platforms();

	Platforms(Rectangle recArg);

	void update();

	void reset();

	void makeNewPlatform(Vector2 location);

	void makeNewPlatform(Vector2 location, Vector2 dimensions);

	void makeNewPlatform(Vector2 location, Vector2 dimensions, uint16_t amountToMake);

	void removePlatform(uint32_t index);

	const std::vector<Rectangle>& getPlatformVector();

	



};