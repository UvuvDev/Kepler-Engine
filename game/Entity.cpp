#include "Entity.hpp"

#define X first
#define Y second

/*=========================================================*/

	// Constructors

Entity::Entity(std::shared_ptr<Texture2D> textureArg) {

	texture = textureArg;

	textureHue = WHITE;

	coords.X = 0;
	coords.Y = 0;

	defaultCoords.X = 0;
	defaultCoords.Y = 0;

}

Entity::Entity(std::shared_ptr<Texture2D> textureArg, Color textureHueArg) {

	texture = textureArg;

	textureHue = textureHueArg;

	coords.X = 0;
	coords.Y = 0;

	defaultCoords.X = 0;
	defaultCoords.Y = 0;
}

Entity::Entity(std::shared_ptr<Texture2D> textureArg, std::pair<float, float> coordsArg) {

	texture = textureArg;

	coords.X = coordsArg.X;
	coords.Y = coordsArg.Y;

	defaultCoords.X = coordsArg.X;
	defaultCoords.Y = coordsArg.Y;

}

Entity::Entity(std::shared_ptr<Texture2D> textureArg, Color textureHueArg, std::pair<float, float> coordsArg) {

	texture = textureArg;

	textureHue = textureHueArg;

	coords.X = coordsArg.X;
	coords.Y = coordsArg.Y;

	defaultCoords.X = coordsArg.X;
	defaultCoords.Y = coordsArg.Y;

}

/*=========================================================*/

// REQUIRED Functions

void Entity::update() { // Put every function you need to update in here
	
	DrawTexture(*texture, coords.X, coords.Y, WHITE);

}

void Entity::reset() { // Resets your Entities variables.
	
	coords.X = defaultCoords.X;
	coords.Y = defaultCoords.Y;

}

/*=========================================================*/

// Class Functions

void Entity::setMovement(std::pair<float, float> moveVectorArg) { // Sets Movement.

}

void Entity::setHealth(double healthArg) { // Sets Health.

}

/*=========================================================*/



#undef X
#undef Y