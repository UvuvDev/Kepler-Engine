#include "Entity.hpp"

/*=========================================================*/

// Constructors

Entity::Entity() {

	textureHue = WHITE;

	damage = defaultDamage;
	health = defaultHealth;

	coords.x = 0;
	coords.y = 0;

	defaultCoords.x = 0;
	defaultCoords.y = 0;

	isFlipped = 1;

}

Entity::Entity(HashTextureMap textureMapArg) {

	//textureVector.emplace_back( LoadTexture("resources/KeplerEngineLogo.png") );

	textureMap = textureMapArg; //= std::make_shared<Texture2D>( textureVector[0] );

	textureHue = WHITE;

	damage = defaultDamage;
	health = defaultHealth;

	coords.x = 0;
	coords.y = 0;

	defaultCoords.x = 0;
	defaultCoords.y = 0;

}

Entity::Entity(HashTextureMap textureMapArg,
	Color textureHueArg) {

	textureMap = textureMapArg;

	textureHue = textureHueArg;

	coords.x = 0;
	coords.y = 0;

	damage = defaultDamage;
	health = defaultHealth;

	defaultCoords.x = 0;
	defaultCoords.y = 0;
}

Entity::Entity(HashTextureMap textureMapArg,
	Vector2 coordsArg) {

	textureMap = textureMapArg;

	textureHue = WHITE;

	coords.x = coordsArg.x;
	coords.y = coordsArg.y;

	damage = defaultDamage;
	health = defaultHealth;

	defaultCoords.x = coordsArg.x;
	defaultCoords.y = coordsArg.y;

}

Entity::Entity(HashTextureMap textureMapArg,
	Color textureHueArg, Vector2 coordsArg) {

	textureMap = textureMapArg;

	textureHue = textureHueArg;

	coords.x = coordsArg.x;
	coords.y = coordsArg.y;

	damage = defaultDamage;
	health = defaultHealth;

	defaultCoords.x = coordsArg.x;
	defaultCoords.y = coordsArg.y;

}

/*=========================================================*/

// REQUIRED Functions

void Entity::update() { // Put every function you need to update in here
	
	//DrawTexture(testTexture, coords.x, coords.y, WHITE);
	DrawTexture(textureMap->find("Entity")->second, coords.x, coords.y, WHITE);

}

void Entity::reset() { // Resets your Entities variables.
	
	coords.x = defaultCoords.x;
	coords.y = defaultCoords.y;

}

/*=========================================================*/

// Class Functions

void Entity::setMovement(Vector2 moveVectorArg) { // Sets Movement.
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

void Entity::flipSpriteForward() {
	isFlipped = 1;
}

void Entity::flipSpriteReverse() {
	isFlipped = -1;
}

/*=========================================================*/