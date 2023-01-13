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

	hitBox.x = coords.x;
	hitBox.x = coords.x;

	hitBox.width = 64;
	hitBox.height = 64; // Need to fix and tie to anim.getPixelDen

	defaultCoords.x = 200;
	defaultCoords.y = 200;

	
	collisionBoxTop = { coords.x, coords.y + animationHandler.getPixelDensityPerChunk() };
	collisionBoxBottom = { coords.x, coords.y };
	collisionBoxLeft = { coords.x, coords.y };
	collisionBoxRight = { coords.x, coords.y };

}

Character::Character(HashTextureMap textureMapArg) {

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

Character::Character(HashTextureMap textureMapArg,
	Level* levelPtrArg) {

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

		DrawTextureRec(textureMap->find(textureName)->second, {animationHandler.getCurrentChunk().x,

			animationHandler.getCurrentChunk().y, (float)animationHandler.getPixelDensityPerChunk() * isFlipped,

			(float)animationHandler.getPixelDensityPerChunk() }, { coords.x, coords.y }, textureHue);

	}
	

}

void Character::gravity() {
	
	if (isAffectedByGravity && isInAir) {
		movementVector.y += gravityEquation();
	}

	if (movementVector.y > terminalVelocity) {
		movementVector.y = terminalVelocity;
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
		//isInAir = false;
	}
	else if (IsKeyDown(KEY_DOWN)) {
		//movementVector.y = 5;	
		//animationHandler.freezeFrame();
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
		movementVector.y -= 7;
	}

	else {
		movementVector.y = 0;
	} 

	if (movementVector.y > 0) {
		isJumping = false;
	}
	

}
/*
bool Character::collisionCheck() {

	int collisionIncremement = 0;

	std::vector<Rectangle> collisionBoxesToCheck;

	collisionBoxesToCheck = levelPtr->coordsToCheckCollision({ 100, 100 });



	std::cout << "\n\n\n\n" << levelPtr->coordsToCheckCollision({ 100, 100 }).size();



	hitBox.x = coords.x;
	hitBox.y = coords.y;

	hitBox.width = animationHandler.getPixelDensityPerChunk();
	hitBox.height = animationHandler.getPixelDensityPerChunk();

	
	
	DrawRectangleLines(hitBox.x, hitBox.y, hitBox.width, hitBox.height, RED);
	


	for (int i = 0; i < collisionBoxesToCheck.size(); i++) {

		// if coords > 0 + width and < Screen width, collision check. else dont emplace back		

		if (CheckCollisionRecs(hitBox, collisionBoxesToCheck.at(i)) && collisionIncremement < 1) {
			
			DrawTexture(*(*textureMap.find("Checkmark")).second, 150, 100, WHITE);

			//collisionBox.y += 100;
			//coords.y += 100;
			
			movementVector.y = 0;

			isInAir = false;
			isJumping = false;

			collisionIncremement++;

			return true;
		
		}

		else {

			isInAir = true;
			
			updateTimes();


		}

	}

	collisionIncremement = 0;

	return false;

}
*/
bool Character::collisionCheck() {

	static bool collisionLastFrameBottom = false;
	static bool collisionLastFrameTop = false;
	static bool collisionLastFrameLeft = false;
	static bool collisionLastFrameRight = false;

	int collisionIncTop = 0;
	int collisionIncBottom = 0;
	int collisionIncLeft = 0;
	int collisionIncRight = 0;

	std::vector<Rectangle> collisionBoxesToCheck;

	collisionBoxesToCheck = levelPtr->coordsToCheckCollision({ 100, 100 });

	std::cout << "\n\n\n\n" << levelPtr->coordsToCheckCollision({ 100, 100 }).size();


	hitBox.x = coords.x;
	hitBox.y = coords.y;


	collisionBoxTop = { coords.x, 
		coords.y, static_cast<float>(animationHandler.getPixelDensityPerChunk()), 5}; // Top
	
	collisionBoxLeft = { coords.x,
		coords.y, 5, static_cast<float>(animationHandler.getPixelDensityPerChunk()) }; // Left
	
	collisionBoxRight = { coords.x + animationHandler.getPixelDensityPerChunk() - 5, // Right
		coords.y  , 5, static_cast<float>(animationHandler.getPixelDensityPerChunk()) };

	collisionBoxBottom = { coords.x, // Bottom
		coords.y + animationHandler.getPixelDensityPerChunk() , static_cast<float>(animationHandler.getPixelDensityPerChunk()), 10 };



	hitBox.width = animationHandler.getPixelDensityPerChunk();
	hitBox.height = animationHandler.getPixelDensityPerChunk();



	DrawRectangleLines(collisionBoxBottom.x, collisionBoxBottom.y, // Bottom
		collisionBoxBottom.width, collisionBoxBottom.height, RED);

	DrawRectangleLines(collisionBoxRight.x, collisionBoxRight.y, // Right
		collisionBoxRight.width, collisionBoxRight.height, BLUE);

	DrawRectangleLines(collisionBoxTop.x, collisionBoxTop.y, // Top
		collisionBoxTop.width, collisionBoxTop.height, GREEN);

	DrawRectangleLines(collisionBoxLeft.x, collisionBoxLeft.y, // Left
		collisionBoxLeft.width, collisionBoxLeft.height, YELLOW);

	for (int i = 0; i < collisionBoxesToCheck.size(); i++) {

		/*========== Bottom ===========*/

		if (CheckCollisionRecs(collisionBoxBottom, collisionBoxesToCheck.at(i)) && collisionIncBottom < 1) {
			

			/*
			
			Collision was very tricky. The main issue to always consider is the Jumping and inAir booleans.
			These were commonly left on while the player was touching the platform, and sometimes wouldn't even work
			if i directly set them in the function to false. In the end i had to do much trial and error, and these
			are still mostly workarounds probably. I don't know how other game engines do it. The top and sides though 
			did not nearly have as much of a problem though. The jump code doesn't affect them at all, so its fine.
			
			*/
			
			if (collisionBoxesToCheck.at(i).y < coords.y + animationHandler.getPixelDensityPerChunk() + collisionBoxBottom.height - 1) {
				collisionBoxBottom.y -= 1;
				coords.y -= 1;

				// This just makes sure the players lifted up to the top when the collision detects.
				// Obviously, when moving up and down, it won't always fall perfectly on top of a platform,
				// Meaning that logic needs to be handled.

			}
			

			if (movementVector.y > 0) {
				movementVector.y = 0;
				updateTimes();
				
				// If its moving down, instead just kill the Vector. Stops gravity and outside forces from 
				// the thing moving down: basically just the collision reaction.

			}

			if (isJumping && IsKeyDown(KEY_SPACE)) {
				isInAir = true;

				// If you're jumping and the space key is down, then you are in the air. To be honest it's
				// redundant right now because Jump is always tied to space, but whatever. Its a nice failsafe maybe.
				// This fixes the issue of a jump still being registered after colliding, messing up with the 
				// updateTimes() function and thereby messing up gravity.
			}

			else {
				isInAir = false;
				isJumping = false;
				updateTimes();

				// If you're not trying to jump off the platform then you're not in the air, you're not jumping,
				// and the times will be reset so when you walk off the platform gravity works properly.
			}



			

			collisionIncBottom++; // Used for optimization, if there's already been one collision, there need 
								  // not be more. Should cover most use cases. If not, just edit it yourself.
								  // It's a game engine, not a packaged game lmao.
			
			collisionBottom = true; // Just a return value.


		}

		else {

			if (collisionLastFrameBottom) {
				updateTimes();
				collisionBottom = false;
				//movementVector.y = 0;
			}


			if (!collisionLastFrameBottom) {
				// Add logic here I guess
			}

			isInAir = true;

			collisionIncBottom = 0;
			//updateTimes();

			


		}

		/*========== Top ===========*/

		if (CheckCollisionRecs(collisionBoxTop, collisionBoxesToCheck.at(i)) && collisionIncTop < 1) {

			if (movementVector.y < 0) {
				movementVector.y *= -1;
			}

			isJumping = false; // If you hit the roof you're no longer jumping.

			collisionIncTop++; // Used for optimization, if there's already been one collision, there need 
							   // not be more. Should cover most use cases. If not, just edit it yourself.
							   // It's a game engine, not a packaged game lmao.

			collisionLastFrameTop = true; // Saves if theres a collision last frame, use for logic if you like.

		}

		else {

			if (collisionLastFrameTop) {
				updateTimes(); 
				isJumping = false;

				// Sets it to not jumping again (in case the function decides to be a goofball) and also updateTimes()
				// so gravity can operate properly.
			}

			collisionLastFrameTop = false; // Obvi there wasn't collision this frame, so it sets to false;


		}

		/*========== Left ===========*/

		if (CheckCollisionRecs(collisionBoxLeft, collisionBoxesToCheck.at(i)) && collisionIncLeft < 1) {

			if (movementVector.x < 0) {
				movementVector.x = 0; // If player's moving to the right, force it to not.
			}

			if (collisionBoxesToCheck.at(i).x > coords.x - collisionBoxLeft.width - 1) {
				collisionBoxLeft.x += 1;
				coords.x += 1;

				// This just makes sure the players pushed over to the right when the collision detects.
				// Obviously, when moving left and right, it won't always move perfectly on a platform,
				// Meaning that logic needs to be handled.

			}

			

			collisionIncLeft++; // Used for optimization, if there's already been one collision, there need 
							    // not be more. Should cover most use cases. If not, just edit it yourself.
							    // It's a game engine, not a packaged game lmao.


		}

		/*========== Right ===========*/

		if (CheckCollisionRecs(collisionBoxRight, collisionBoxesToCheck.at(i)) && collisionIncRight < 1) {

		
			if (collisionBoxesToCheck.at(i).x < coords.x - animationHandler.getPixelDensityPerChunk() - collisionBoxBottom.height + 1) {
				collisionBoxBottom.x -= 1;
				coords.x -= 1;

				// This just makes sure the players pushed over to the left when the collision detects.
				// Obviously, when moving left and right, it won't always fall perfectly on top of a platform,
				// Meaning that logic needs to be handled.

			}

			if (movementVector.x > 0) {
				movementVector.x = 0;
			}

			

			collisionIncRight++;

			//return true;

		}
	}

	return true;
}