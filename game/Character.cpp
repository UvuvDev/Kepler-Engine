#include "Character.hpp"

Character::Character() {

	textureHue = WHITE;

	damage = defaultDamage;
	health = defaultHealth;

	coords.x = 0;
	coords.y = 0;

	defaultCoords.x = 0;
	defaultCoords.y = 0;
}

void Character::update() {

	DrawTexture(testTexture, coords.x, coords.y, WHITE);
	
}