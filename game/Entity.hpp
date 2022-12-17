#pragma once
#include <stdint.h>
#include "raylib.h"
#include <memory>
#include <unordered_map>
#include <string>
#include "BaseClass.hpp"

using HashmapShPtr = std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >>;

class Entity : BaseClass {
protected:

	/*=========================================================*/

	// Graphics

	Texture2D testTexture = LoadTexture("resources/testspritesheet.png");

	std::vector<Texture2D> textureVector; // Texture for Entity.

	HashmapShPtr textureMap;
	std::unordered_map<std::string, std::shared_ptr<AudioCallback>> audioMap;

	Color textureHue;

	/*=========================================================*/

	// Movement

	Vector2 movementVector = { 0.f, 0.f }; // Gets added to coords every frame.
	 
	Vector2 coords; // Contains the x and y cords. 

	Vector2 defaultCoords; // Contains the x and y cords. 

	/*=========================================================*/

	// Animation 


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
	bool isAffectedByGravity = false;

	/*=========================================================*/

	// Constructors

	Entity(std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >> textureMapArg);

	Entity(std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >> textureMapArg, 
		Color textureHue);

	Entity(std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >> textureMapArg, 
		Vector2 coordsArg);

	Entity(std::shared_ptr <std::unordered_map<std::string, std::shared_ptr<Texture2D> >> textureMapArg, 
		Color textureHue, Vector2 coordsArg);

	/*=========================================================*/

	// REQUIRED Functions

	void update(); // Put every function you need to update in here.

	void reset(); // Resets your Entities variables.

	/*=========================================================*/

	// Class Functions

	void setMovement(Vector2 moveVectorArg); // Sets Movement.

	void setHealth(double healthArg); // Sets Health.

	double getHealth(); // Gets Health.

	void setDamage(double damageArg); // Sets Damage.

	double getDamage(); // Gets Damage.

	/*=========================================================*/



};

