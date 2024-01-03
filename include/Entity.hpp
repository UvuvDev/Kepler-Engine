#pragma once
#include <stdint.h>
#include "raylib.h"
#include <memory>
#include <unordered_map>
#include <string>
#include "BaseClass.hpp"
#include "AnimationHandler.hpp"
#include "StateMachines.hpp"
#include "Level.hpp"
#include "Audio.hpp"

using HashTextureMap = std::unordered_map<std::string, Texture2D >*;

class Entity : BaseClass {
protected:

	AnimationHandlerClass animationHandler;
	CollisionStates collisionState;

	//AudioController audio;

	Level* levelPtr;

	Rectangle collisionBoxTop;
	Rectangle collisionBoxBottom;
	Rectangle collisionBoxLeft;
	Rectangle collisionBoxRight;

	bool collisionBottom = false;

	float G = 9.8;

	float terminalVelocity = 15;

	float inAirSpeed = 0.f;

	bool isJumping = false;

	char* textureName = "Entity";

	Rectangle hitBox;

	Rectangle debugBox = { 500, 500, 900, 900 };

	/*=========================================================*/

	// Graphics

	Texture2D testTexture = LoadTexture("resources/testspritesheet.png");

	HashTextureMap textureMap;
	std::unordered_map<std::string, std::shared_ptr<AudioCallback>> audioMap;

	Color textureHue;

	float isFlipped;

	/*=========================================================*/

	// Movement

	Vector2 movementVector = { 0.f, 0.f }; // Gets added to coords every frame.
	 
	Vector2 coords; // Contains the x and y cords. 

	Vector2 defaultCoords; // Contains the x and y cords. 

	/*=========================================================*/

	// Animation 


	/*=========================================================*/

	// Key Characteristics

	static constexpr uint16_t defaultHealth = 3;
	static constexpr uint16_t defaultDamage = 1;

	double health;
	double damage;	

	float currentTime = 0.f;
	float startTimeInAir = 0.f;

public: 

	/*=========================================================*/

	// States

	bool canTakeDamage = false;
	bool hasCollision = false;
	bool isDead = false;
	bool canMove = false;
	bool isAffectedByGravity = false;
	bool isInAir = false;
	bool shouldRender = true;
	

	/*=========================================================*/

	// Constructors

	Entity();

	Entity(HashTextureMap textureMapArg);

	Entity(HashTextureMap textureMapArg,
		Color textureHue);

	Entity(HashTextureMap textureMapArg,
		Vector2 coordsArg);

	Entity(HashTextureMap textureMapArg,
		Color textureHue, Vector2 coordsArg);

	/*=========================================================*/

	// REQUIRED Functions

	void update(); // Put every function you need to update in here.

	void reset(); // Resets your Entities variables.

	/*=========================================================*/

	// Class Functions

protected:

	void setMovement(Vector2 moveVectorArg); // Sets Movement.

	void setHealth(double healthArg); // Sets Health.

	double getHealth(); // Gets Health.

	void setDamage(double damageArg); // Sets Damage.

	double getDamage(); // Gets Damage.

	void gravity();

	float gravityEquation();

	void bottomFloor();

	void updateTimes();

	void movingCheck();
	
	bool collisionCheck();

	void render();

	/*=========================================================*/

	void flipSpriteForward();

	void flipSpriteReverse();

};

