#include "Character.hpp"
#include <iostream>
#include <algorithm>

Character::Character() {

	textureHue = WHITE;

	isAffectedByGravity = true;

	damage = defaultDamage;
	health = defaultHealth;

	coords.x = 200;
	coords.y = 200;

	defaultCoords.x = 200;
	defaultCoords.y = 200;


}

Character::Character(std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >> textureMapArg) {

	textureMap = textureMapArg; //= std::make_shared<Texture2D>( textureVector[0] );

	textureHue = WHITE;

	isAffectedByGravity = true;

	damage = defaultDamage;
	health = defaultHealth;

	coords.x = 0;
	coords.y = 0;

	defaultCoords.x = 0;
	defaultCoords.y = 0;

}

void Character::update() {

	//DrawTexture(testTexture, coords.x, coords.y, WHITE);
	std::cout << "Time: " << GetTime() << "\n";

	/*=======================================*/

	if (IsKeyDown(KEY_LEFT)) {
		movementVector.x = -5;
		flipSpriteReverse();
	}
	else if (IsKeyDown(KEY_RIGHT)) {
		movementVector.x = 5;
		flipSpriteForward();
	}
	else {
		movementVector.x = 0;
		animationHandler.freezeFrame();
	}


	if (IsKeyDown(KEY_UP)) {
		movementVector.y = -5;	
		isInAir = false;
	}
	else if (IsKeyDown(KEY_DOWN)) {
		movementVector.y = 5;	
		animationHandler.freezeFrame();
		isInAir = true;
	}
	else {
		movementVector.y = 0;
	}

	/*=======================================*/

	if (IsKeyPressed(KEY_SPACE)) {
		isInAir = true;
		isJumping = true;
		
	}

	if (isInAir && isJumping) {
		movementVector.y += jumpEquation();
	}

	/*=======================================*/

	if (isInAir) {
		timeInAir = GetTime();
	}

	else {
		startTimeInAir = GetTime();
	}


	if (isAffectedByGravity && isInAir) {
		movementVector.y -= gravityEquation();
	}

	coords.x += movementVector.x;
	coords.y += movementVector.y;

	animationHandler.update();

	DrawTextureRec( *(*textureMap->find("Character")).second , {animationHandler.getCurrentChunk().x,

		animationHandler.getCurrentChunk().y, (float)animationHandler.getPixelDensityPerChunk()* isFlipped,

		(float)animationHandler.getPixelDensityPerChunk() }, {coords.x, coords.y}, WHITE);

	//DrawTextureRec(animationHandler.testTexture, { 128, 128,
	//	64, 64 }, { coords.x, coords.y }, WHITE);
	



}

float Character::jumpEquation() {
	return std::clamp(( 2 * G * (startTimeInAir - timeInAir), 1.f, 1.f);
}

float Character::gravityEquation() {
	return G * (startTimeInAir - timeInAir);
}