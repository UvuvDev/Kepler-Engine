
#include "include/Level.hpp"
#include <iostream>

Level::Level() {

	//platforms;

}

void Level::update() {
	
	platforms.update();

}

std::vector<Rectangle> Level::coordsToCheckCollision(Vector2 coords) {
	
	std::vector<Rectangle> returnCoordsForCollision;

	std::cout << "\nsize of platform vector: " << platforms.getPlatformVector().size() << "  ";

	for (const Rectangle& throwaway : platforms.getPlatformVector()) {
		std::cout << "\n\nAAAaaa\n\n";

		returnCoordsForCollision.emplace_back(throwaway);

		// if coords > 0 + width and < Screen width, collision check. else dont emplace back

	}

	return returnCoordsForCollision;
	

}
