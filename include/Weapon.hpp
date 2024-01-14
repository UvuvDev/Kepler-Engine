#pragma once
#include <string>
#include "Item.hpp"
#include "Socket.h"

class Weapon : public Item {
protected:

	Texture2D texture;
	Color colorHue;

	static constexpr float defaultDamage = 1000.f;
	static constexpr float defaultRange = 1000.f;

	float damage;
	float range;

	Vector2 coords;

	bool isLockedToSocket;

	Rectangle collisionBox;

public:
	
	Weapon();

	Weapon(float damageArg);

	Weapon(float damageArg, float rangeArg, KeplerSocket* socketArg);

	virtual void setPos(Vector2 pos) = 0;

    virtual void setSocket(KeplerSocket* socketArg) = 0;

    virtual void update() = 0;

    virtual void reset() = 0;

    virtual void attack(int* health) = 0;

    virtual bool getIfGravity() = 0;



};