#pragma once
#include "Platform.hpp"

class Level {
private:

public:
	
	Platforms platforms;

	Level();

	void update();

	void reset();

	std::vector<Rectangle> coordsToCheckCollision(Vector2 coords);



};