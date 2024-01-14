#include "include/Entity.hpp"
#include "include/AnimationHandler.hpp"
#include "include/StateMachines.hpp"
#include "include/Level.hpp"
#include "include/Audio.hpp"

/*=========================================================*/

// Constructors

Entity::Entity() {

	textureHue = WHITE;

	damage = defaultDamage;
	health = defaultHealth;

	coords.x = 0;
	coords.y = 0;

	defaultCoords.x = 0;
	defaultCoords.y = 0;

	isFlipped = 1;

}

Entity::Entity(HashTextureMap textureMapArg) {

	//textureVector.emplace_back( LoadTexture("resources/KeplerEngineLogo.png") );

	textureMap = textureMapArg; //= std::make_shared<Texture2D>( textureVector[0] );

	textureHue = WHITE;

	damage = defaultDamage;
	health = defaultHealth;

	coords.x = 0;
	coords.y = 0;

	defaultCoords.x = 0;
	defaultCoords.y = 0;

}

Entity::Entity(HashTextureMap textureMapArg,
	Color textureHueArg) {

	textureMap = textureMapArg;

	textureHue = textureHueArg;

	coords.x = 0;
	coords.y = 0;

	damage = defaultDamage;
	health = defaultHealth;

	defaultCoords.x = 0;
	defaultCoords.y = 0;
}

Entity::Entity(HashTextureMap textureMapArg,
	Vector2 coordsArg) {

	textureMap = textureMapArg;

	textureHue = WHITE;

	coords.x = coordsArg.x;
	coords.y = coordsArg.y;

	damage = defaultDamage;
	health = defaultHealth;

	defaultCoords.x = coordsArg.x;
	defaultCoords.y = coordsArg.y;

}

Entity::Entity(HashTextureMap textureMapArg,
	Color textureHueArg, Vector2 coordsArg) {

	textureMap = textureMapArg;

	textureHue = textureHueArg;

	coords.x = coordsArg.x;
	coords.y = coordsArg.y;

	damage = defaultDamage;
	health = defaultHealth;

	defaultCoords.x = coordsArg.x;
	defaultCoords.y = coordsArg.y;

}

/*=========================================================*/

// REQUIRED Functions

void Entity::update() { // Put every function you need to update in here
	
	//DrawTexture(testTexture, coords.x, coords.y, WHITE);
	DrawTexture(textureMap->find("Entity")->second, coords.x, coords.y, WHITE);

}

void Entity::reset() { // Resets your Entities variables.
	
	coords.x = defaultCoords.x;
	coords.y = defaultCoords.y;

}

/*=========================================================*/

// Class Functions

void Entity::setMovement(Vector2 moveVectorArg) { // Sets Movement.
	movementVector = moveVectorArg;
}

void Entity::setHealth(double healthArg) { // Sets Health.
	health = healthArg;
}

double Entity::getHealth() {
	return health;
}

void Entity::setDamage(double damageArg) {
	damage = damageArg;
}

double Entity::getDamage() {
	return damage;
}

float Entity::gravityEquation() {
	return G * (currentTime - startTimeInAir);
}

void Entity::bottomFloor() {

	if (coords.y > GetScreenHeight() - animationHandler.getPixelDensityPerChunk() - 50) {
		coords.y = GetScreenHeight() - animationHandler.getPixelDensityPerChunk() - 50;
		//isInAir = false;
	}

}

void Entity::render() {

	animationHandler.update();

	if (shouldRender) {

		DrawTextureRec(textureMap->find(textureName)->second, { animationHandler.getCurrentChunk().x,

			animationHandler.getCurrentChunk().y, (float)animationHandler.getPixelDensityPerChunk() * isFlipped,

			(float)animationHandler.getPixelDensityPerChunk() }, { coords.x, coords.y }, textureHue);

	}

}

void Entity::gravity() {

	if (isAffectedByGravity && isInAir) {
		movementVector.y += gravityEquation();
	}

	if (movementVector.y > terminalVelocity) {
		movementVector.y = terminalVelocity;
	}

}

void Entity::updateTimes() {

	currentTime = GetTime();


	if (!isInAir) {
		startTimeInAir = GetTime();
	}

}

void Entity::movingCheck() {

	if (IsKeyDown(KEY_LEFT)) {
		movementVector.x = -5;
		flipSpriteReverse();
		animationHandler.unfreezeFrame();
	}
	else if (IsKeyDown(KEY_RIGHT)) {
		movementVector.x = 5;
		flipSpriteForward();
		animationHandler.unfreezeFrame();
	}
	else {
		movementVector.x = 0;
		animationHandler.freezeFrame({ 4, 5 });
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

bool Entity::collisionCheck() {

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

	hitBox.x = coords.x;
	hitBox.y = coords.y;


	collisionBoxTop = { coords.x,
		coords.y, static_cast<float>(animationHandler.getPixelDensityPerChunk()), 5 }; // Top

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



/*=========================================================*/

void Entity::flipSpriteForward() {
	isFlipped = 1;
}

void Entity::flipSpriteReverse() {
	isFlipped = -1;
}

/*=========================================================*/