#pragma once

#include "Entity.hpp"
#include "InputHandler.hpp"
#include "AnimationHandler.hpp"

class Character : Entity {

	InputHandlerClass inputHandler;

public:

	Character();

	void update();


};