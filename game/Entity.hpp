#pragma once
#include <stdint.h>
#include "raylib.h"
#include <memory>
#include <unordered_map>
#include <string>
#include "BaseClass.hpp"



class Entity : BaseClass {
private:

	/*=========================================================*/

	// Graphics

	std::vector<Texture2D> textureVector; // Texture for Entity.

	std::unordered_map<std::string, std::shared_ptr<Texture2D>> textureMap;
	std::unordered_map<std::string, std::shared_ptr<AudioCallback>> audioMap;

	Color textureHue;

	/*=========================================================*/

	// Movement

	std::pair<float, float> movementVector = { 0.f, 0.f }; // Gets added to coords every frame.
	 
	std::pair<float, float> coords; // Contains the X and Y cords. 

	std::pair<float, float> defaultCoords; // Contains the X and Y cords. 

	/*=========================================================*/

	// Animation 

	uint8_t framesPerSecond;
	

	/*=========================================================*/

	// Key Characteristics

	static constexpr uint16_t defaultHealth = 100;
	static constexpr uint16_t defaultDamage = 100;

	double health;
	double damage;	

public: 

	/*=========================================================*/

	// States

	bool canTakeDamage = false;
	bool hasCollision = false;
	bool isDead = false;
	bool canMove = false;

	/*=========================================================*/

	// Constructors

	Entity();

	Entity(Color textureHue);

	Entity(std::pair<float, float> coordsArg);

	Entity(Color textureHue, std::pair<float, float> coordsArg);

	/*=========================================================*/

	// REQUIRED Functions

	void update(); // Put every function you need to update in here.

	void reset(); // Resets your Entities variables.

	/*=========================================================*/

	// Class Functions

	void setMovement(std::pair<float, float> moveVectorArg); // Sets Movement.

	void setHealth(double healthArg); // Sets Health.

	double getHealth(); // Gets Health.

	void setDamage(double damageArg); // Sets Damage.

	double getDamage(); // Gets Damage.

	/*=========================================================*/



};

