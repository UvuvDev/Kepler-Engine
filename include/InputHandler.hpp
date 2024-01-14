#pragma once
#include "raylib-include/raylib.h"

class InputHandlerClass {
private:
	Vector2 mousePos;

public:
	InputHandlerClass();

	Vector2 getMousePos();

	void update();
};