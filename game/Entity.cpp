#include "Entity.hpp"

#define X first
#define Y second

/*=========================================================*/

// Constructors

Entity::Entity() {

	textureVector.emplace_back( LoadTexture("resources/KeplerEngineLogo.png") );

	textureMap["Logo"] = std::make_shared<Texture2D>( textureVector[0] );

	textureHue = WHITE;

	damage = defaultDamage;
	health = defaultHealth;

	coords.X = 0;
	coords.Y = 0;

	defaultCoords.X = 0;
	defaultCoords.Y = 0;

}

Entity::Entity(Color textureHueArg) {

	textureHue = textureHueArg;

	coords.X = 0;
	coords.Y = 0;

	damage = defaultDamage;
	health = defaultHealth;

	defaultCoords.X = 0;
	defaultCoords.Y = 0;
}

Entity::Entity(std::pair<float, float> coordsArg) {

	textureHue = WHITE;

	coords.X = coordsArg.X;
	coords.Y = coordsArg.Y;

	damage = defaultDamage;
	health = defaultHealth;

	defaultCoords.X = coordsArg.X;
	defaultCoords.Y = coordsArg.Y;

}

Entity::Entity(Color textureHueArg, std::pair<float, float> coordsArg) {

	textureHue = textureHueArg;

	coords.X = coordsArg.X;
	coords.Y = coordsArg.Y;

	damage = defaultDamage;
	health = defaultHealth;

	defaultCoords.X = coordsArg.X;
	defaultCoords.Y = coordsArg.Y;

}

/*=========================================================*/

// REQUIRED Functions

void Entity::update() { // Put every function you need to update in here
	
	DrawTexture(textureVector[0], coords.X, coords.Y, WHITE);

}

void Entity::reset() { // Resets your Entities variables.
	
	coords.X = defaultCoords.X;
	coords.Y = defaultCoords.Y;

}

/*=========================================================*/

// Class Functions

void Entity::setMovement(std::pair<float, float> moveVectorArg) { // Sets Movement.
	movementVector = moveVectorArg;
}

void Entity::setHealth(double healthArg) { // Sets Health.
	health = healthArg;
}

double Entity::getHealth() {
	return health;
}

void Entity::setDamage(double damageArg) {
	damage = damageArg;
}

double Entity::getDamage() {
	return damage;
}

/*=========================================================*/



#undef X
#undef Y