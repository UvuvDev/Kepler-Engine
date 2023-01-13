#pragma once

#include "Entity.hpp"
#include "InputHandler.hpp"
#include "AnimationHandler.hpp"
#include "StateMachines.hpp"
#include "Level.hpp"
#include "Audio.hpp"

class Character : Entity {
private:

	InputHandlerClass inputHandler;
	AnimationHandlerClass animationHandler;

	CharacterStates characterStateMachine;
	CollisionStates collisionState;

	//AudioController audio;

	Level* levelPtr;

	Rectangle collisionBoxTop;
	Rectangle collisionBoxBottom;
	Rectangle collisionBoxLeft;
	Rectangle collisionBoxRight;
	
	bool isInAir = true;

	bool collisionBottom = false;

	void bottomFloor();

	float gravityEquation();

	float G = 9.8;

	float terminalVelocity = 15;

	float inAirSpeed = 0.f;

	bool isJumping = false;

	char* textureName = "Character";

	Rectangle hitBox;

	Rectangle debugBox = { 500, 500, 900, 900 };

	void render();

	void jumpingCheck();

	void movingCheck();

	void gravity();

	void updateTimes();

	bool collisionCheck();

	bool newCollision();


public:

	Character();

	Character(HashTextureMap textureMapArg);

	Character::Character(HashTextureMap textureMapArg,
		Level* levelPtrArg);

	void update();

	
	


};