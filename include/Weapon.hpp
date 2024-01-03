#pragma once
#include "Item.hpp"
#include "Socket.h"

class Weapon : Item {
protected:

	Texture2D texture;
	Color colorHue;

	static constexpr float defaultDamage = 1000.f;
	static constexpr float defaultRange = 1000.f;

	float damage;
	float range;

	Vector2 coords;

	KeplerSocket* socket;

	bool isLockedToSocket;

	Rectangle collisionBox;

public:
	
	Weapon();

	Weapon(float damageArg);

	Weapon(float damageArg, float rangeArg, KeplerSocket* socketArg);

	void setPos(Vector2 pos);

	void setSocket(KeplerSocket* socketArg);

	void update();

	void reset();

	void attack(int* health);



};