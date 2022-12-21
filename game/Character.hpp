#pragma once

#include "Entity.hpp"
#include "InputHandler.hpp"
#include "AnimationHandler.hpp"
#include "StateMachines.hpp"
#include "Level.hpp"


class Character : Entity {
private:

	InputHandlerClass inputHandler;
	AnimationHandlerClass animationHandler;

	CharacterStates characterStateMachine;
	CollisionStates collisionState;

	std::shared_ptr<Level> levelPtr;

	void bottomFloor();

	float jumpEquation();

	float gravityEquation();

	float G = 9.8;

	float inAirSpeed = 0.f;

	bool isJumping = false;

	char* textureName = "Character";

	Rectangle collisionBox;

	Rectangle debugBox = { 500, 500, 900, 900 };

	void render();

	void jumpingCheck();

	void movingCheck();

	void gravity();

	void updateTimes();

	bool collisionCheck();

public:

	Character();

	Character(std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >> textureMapArg);

	Character::Character(std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >> textureMapArg,
		std::shared_ptr<Level> level);

	void update();

	
	


};