#pragma once

#include "raylib-include/raylib.h"

class UI {
private:

	Texture2D HealthBar;
	Texture2D HealthHearts;
	Texture2D Map;
	Texture2D Powerup;

	

public:

	UI();

	void renderHealthHearts(Vector2 Position, bool onOrOff);

};