#pragma once

#include "Entity.hpp"
#include "InputHandler.hpp"
#include "AnimationHandler.hpp"

class Character : Entity {
private:

	InputHandlerClass inputHandler;
	AnimationHandlerClass animationHandler;

	float jumpEquation();

	float gravityEquation();

	float G = 9.8;

	bool isJumping = false;

public:

	Character();

	Character(std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >> textureMapArg);

	void update();

	


};