#include "include/Weapon.hpp"

Weapon::Weapon() {

	damage = defaultDamage;
	range = defaultRange;
	isLockedToSocket = false;

	texture = LoadTexture("resources/weapon.png");

	colorHue = RAYWHITE;

	collisionBox = { 0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height) };

	if (socket == nullptr) {
		
	}
	else {
		socket->isFlipped = false;
	}
	


}

Weapon::Weapon(float damageArg) {

	damage = damageArg;
	range = defaultRange;
	isLockedToSocket = false;

	texture = LoadTexture("resources/weapon.png");

	colorHue = RAYWHITE;

	collisionBox = { 0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height) };

	if (socket == nullptr) {

	}
	else {
		socket->isFlipped = false;
	}

}

Weapon::Weapon(float damageArg, float rangeArg, KeplerSocket* socketArg) {

	damage = defaultDamage;
	range = defaultRange;
	isLockedToSocket = false;

	socket = socketArg;

	texture = LoadTexture("resources/weapon.png");

	colorHue = RAYWHITE;

	collisionBox = { 0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height) };

	socket->isFlipped = false;

}
/*
void Weapon::setPos(Vector2 pos) {
	isLockedToSocket = false;
	coords = pos;
	
}

void Weapon::setSocket(KeplerSocket* socketArg) {
	isLockedToSocket = true;
	socket = socketArg;
}

void Weapon::attack(int* health) {
	health--;

}

void Weapon::update() {

	if (isLockedToSocket) {
		coords = *socket->coords;
	}
	else {
		//	Do nothing
	}

	DrawTexture(texture, coords.x, coords.y, colorHue);

}

void Weapon::reset() {

} */