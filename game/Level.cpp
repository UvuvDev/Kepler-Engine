#include "Level.hpp"
#include <iostream>

Level::Level() {

	//platforms;

}

void Level::update() {
	
	platforms.update();

}

std::vector<Rectangle> Level::coordsToCheckCollision(Vector2 coords) {
	
	std::vector<Rectangle> returnCoordsForCollision;

	for (int i = 0; i < platforms.getPlatformVector()->size(); i++) {

		std::cout << "AAAaaa";

		Rectangle throwaway = platforms.getPlatformVector()->at(0);

		returnCoordsForCollision.emplace_back(throwaway);

		// if coords > 0 + width and < Screen width, collision check. else dont emplace back

	}

	return returnCoordsForCollision;
	

}
