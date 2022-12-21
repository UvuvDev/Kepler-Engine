#include "Character.hpp"
#include <iostream>
#include <algorithm>

Character::Character() {

	textureHue = WHITE;

	isAffectedByGravity = true;

	isInAir = true;

	damage = defaultDamage;
	health = defaultHealth;

	coords.x = 200;
	coords.y = 200;

	collisionBox.x = coords.x;
	collisionBox.x = coords.x;

	collisionBox.width = animationHandler.getPixelDensityPerChunk();
	collisionBox.height = animationHandler.getPixelDensityPerChunk();

	defaultCoords.x = 200;
	defaultCoords.y = 200;

	

}

Character::Character(std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >> textureMapArg) {

	textureMap = textureMapArg; //= std::make_shared<Texture2D>( textureVector[0] );

	textureHue = WHITE;

	isAffectedByGravity = true;

	isInAir = true;

	damage = defaultDamage;
	health = defaultHealth;

	coords.x = 0;
	coords.y = 0;

	defaultCoords.x = 0;
	defaultCoords.y = 0;

}

Character::Character(std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >> textureMapArg,
	std::shared_ptr<Level> levelPtrArg) {

	levelPtr = levelPtrArg;

	textureMap = textureMapArg; //= std::make_shared<Texture2D>( textureVector[0] );

	textureHue = WHITE;

	isAffectedByGravity = true;

	isInAir = true;

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
		
	// Movement Input Code

	movingCheck();

	/*=======================================*/

	// Jumping Code

	jumpingCheck();

	/*=======================================*/

	// Time Functions

	updateTimes();

	/*=======================================*/

	// Gravity Code

	gravity();

	/*=======================================*/

	// Collision Checker

	collisionCheck();

	/*=======================================*/

	// Final Coord Change

	coords.x += movementVector.x;
	coords.y += movementVector.y;

	bottomFloor();

	/*=======================================*/

	render();
	
	/*=======================================*/



	//DrawTextureRec(animationHandler.testTexture, { 128, 128,
	//	64, 64 }, { coords.x, coords.y }, WHITE);
	



}

float Character::jumpEquation() {

	inAirSpeed = 3.f * G * (currentTime - startTimeInAir);

	if (currentTime - startTimeInAir > 1.5 || inAirSpeed > 20.f) {
		isJumping = false;
		inAirSpeed = 0;

	}

	std::cout << "In Air Speed: " << inAirSpeed << std::endl;

	//std::cout << "Is In Air? : " << isInAir << std::endl;

	return inAirSpeed;

}

float Character::gravityEquation() {
	return G * (currentTime - startTimeInAir);
}

void Character::bottomFloor() {

	if (coords.y > GetScreenHeight() - animationHandler.getPixelDensityPerChunk() - 50 ) {
		coords.y = GetScreenHeight() - animationHandler.getPixelDensityPerChunk() - 50;
		//isInAir = false;
	}

}

void Character::render() {

	animationHandler.update();

	if (shouldRender) {

		DrawTextureRec(*(*textureMap->find(textureName)).second, { animationHandler.getCurrentChunk().x,

			animationHandler.getCurrentChunk().y, (float)animationHandler.getPixelDensityPerChunk() * isFlipped,

			(float)animationHandler.getPixelDensityPerChunk() }, { coords.x, coords.y }, textureHue);

	}
	

}

void Character::gravity() {
	
	if (isAffectedByGravity) {
		movementVector.y += gravityEquation();
	}

}

void Character::updateTimes() {

	currentTime = GetTime();


	if (!isInAir) {
		startTimeInAir = GetTime();
	}

}

void Character::movingCheck() {

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
		//movementVector.y = -5;	
		isInAir = false;
	}
	else if (IsKeyDown(KEY_DOWN)) {
		//movementVector.y = 5;	
		animationHandler.freezeFrame();
	}
	else {
		movementVector.y = 0;
	}
}

void Character::jumpingCheck() {

	if (IsKeyPressed(KEY_SPACE)) {
		startTimeInAir = GetTime();
		isInAir = true;
		isJumping = true;

	}

	if (isJumping) {
		movementVector.y -= jumpEquation();
	}

	else {
		movementVector.y = 0;
	}
}

bool Character::collisionCheck() {

	collisionBox.x = coords.x;
	collisionBox.y = coords.y;

	collisionBox.width = animationHandler.getPixelDensityPerChunk();
	collisionBox.height = animationHandler.getPixelDensityPerChunk();

	DrawRectangleLines(collisionBox.x, collisionBox.y, collisionBox.width, collisionBox.height, RED);
	DrawRectangleLines(debugBox.x, debugBox.y, debugBox.width, debugBox.height, BLUE);
	
	
	if (CheckCollisionRecs(collisionBox, debugBox)) {
		DrawTexture(*(*textureMap->find("Checkmark")).second, 150, 100, WHITE);

	}





	if (CheckCollisionRecs(collisionBox, {100, 100, 1000, 1000})) {
		//DrawTexture(*(*textureMap->find("Character")).second, 100, 100, WHITE);
		//std::cout << "RIEOVJWIOFJWIOFJEWIOFJEWQIOPFJIE";
		return true;
	}
	else {
		return false;
	}

}