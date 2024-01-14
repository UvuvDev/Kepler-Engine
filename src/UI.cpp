#include "include/UI.hpp"


UI::UI() {
	HealthHearts = LoadTexture("resources/Hearts.png");
	//Map = LoadTexture("resources/bruh");
	//Powerup = LoadTexture("resources/bruh");

}



void UI::renderHealthHearts(Vector2 Position, bool onOrOff) {

	if (onOrOff) {
		DrawTextureRec(HealthHearts, { 0, 0, 32, 64 }, { Position.x, Position.y }, WHITE);
	}

	else {
		DrawTextureRec(HealthHearts, { 32, 0, 32, 64 }, { Position.x, Position.y }, WHITE);
	}

	


}