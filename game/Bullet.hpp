#pragma once

#include "raylib.h"

class Bullet {
protected:
		
	Texture2D texture;

	Vector2 coords;

	Vector2 movementVector;

public:

	Bullet(Vector2 coordsArg, Texture2D textureArg);

	void setMovementVector(Vector2* movementVectorArg);

	void update();

	Vector2 getCoords();

};