#pragma once

enum class CollisionStates {
	TOP = 1,
	BOTTOM = 2,
	LEFT = 4,
	RIGHT = 8

};

enum class CharacterStates {
	DEAD = 0,
	ALIVE = 1,
	JUMPING = 2,
	MOVING = 4,
	ATTACKING = 8

};