#pragma once
#include "BaseClass.hpp"
#include "raylib.h"
#include <memory>

class Platforms : BaseClass {
private:

	std::vector<Rectangle> platformVector;

	Vector2 coords;
	Vector2 movementVector;
	bool hasCollision;
	bool canMove;

	uint16_t defaultWidth;
	uint16_t defaultHeight;

public: 

	Platforms::Platforms();

	Platforms::Platforms(Rectangle recArg);

	void update();

	void reset();

	void makeNewPlatform(Vector2 location);

	void makeNewPlatform(Vector2 location, Vector2 dimensions);

	void makeNewPlatform(Vector2 location, Vector2 dimensions, uint16_t amountToMake);

	void removePlatform(uint32_t index);

	std::shared_ptr<std::vector<Rectangle>> getPlatformVector();



};