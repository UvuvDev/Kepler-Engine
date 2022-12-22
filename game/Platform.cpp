#include "Platform.hpp"
#include <iostream>


Platforms::Platforms() {

	defaultWidth = 100;
	defaultHeight = 100;

	coords.x = 0;
	coords.y = 0;

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
			platformVector[i].height, RED);
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

	std::cout << "NEW PLATFORM!!!!!!!!";
	
	Rectangle tempRec = { 100, 100, 100, 100 }; //  { location.x, location.y, dimensions.x, dimensions.y }

	platformVector.emplace_back(tempRec);

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

std::shared_ptr<std::vector<Rectangle>> Platforms::getPlatformVector() {
	return std::make_shared<std::vector<Rectangle>>(platformVector);

}