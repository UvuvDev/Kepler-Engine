#include "include/Bullet.hpp"

Bullet::Bullet(Vector2 coordsArg, Texture2D textureArg) {
	coords = coordsArg;
	texture = textureArg;

}

void Bullet::setMovementVector(Vector2* movementVectorArg) {
	movementVector = *movementVectorArg;
}

void Bullet::update() {
	coords.x += movementVector.x;
	coords.y += movementVector.y;
}

Vector2 Bullet::getCoords() {
	return coords;
}

