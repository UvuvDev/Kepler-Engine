#include "include/Platform.hpp"
#include <iostream>


Platforms::Platforms() {

	defaultWidth = 100;
	defaultHeight = 100;

	coords.x = 0;
	coords.y = 0;

	canMove = false;
	hasCollision = true;

}

Platforms::Platforms(Rectangle recArg) {

	coords.x = 0;
	coords.y = 0;

	defaultWidth = 100;
	defaultHeight = 100;

	canMove = false;
	hasCollision = true;

}


void Platforms::update() {
	
	coords.x += movementVector.x;
	coords.y += movementVector.y;

	for (int i = 0; i < platformVector.size(); i++) {
		DrawRectangle(platformVector[i].x, platformVector[i].y, platformVector[i].width,
			platformVector[i].height, BLUE);
		DrawRectangleLines(platformVector[i].x, platformVector[i].y, platformVector[i].width,
			platformVector[i].height, BLACK);

	}	

}

void Platforms::reset() {

	coords.x = 0;
	coords.y = 0;
	platformVector.clear();

}

void Platforms::makeNewPlatform(Vector2 location) {

	Rectangle tempRec = { location.x, location.y, defaultWidth, defaultHeight };

	platformVector.emplace_back(tempRec);

	std::cout << "NEW PLATFORM!!!!!!!!";

}

void Platforms::makeNewPlatform(Vector2 location, Vector2 dimensions) {

	std::cout << "\n\n" << platformVector.size() << "\n\n";
	
	Rectangle tempRec = { location.x, location.y, dimensions.x, dimensions.y }; //  { location.x, location.y, dimensions.x, dimensions.y }

	platformVector.emplace_back(tempRec);

	std::cout << "\n\n" << platformVector[0].x << "\n\n";
}

void Platforms::makeNewPlatform(Vector2 location, Vector2 dimensions, uint16_t amountToMake) {

	for (uint16_t i = 0; i < amountToMake; i++) {
		
		Rectangle tempRec = { location.x, location.y, dimensions.x, dimensions.y };

		platformVector.emplace_back(tempRec);
	
	}
	
}

void Platforms::removePlatform(uint32_t index) {
	//platformVector.empty(index);
}

const std::vector<Rectangle>& Platforms::getPlatformVector() {
	return platformVector;

}
