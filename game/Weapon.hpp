#pragma once
#include "Item.hpp"

class Weapon : Item {
private:

	static constexpr float defaultDamage = 1000.f;
	static constexpr float defaultRange = 1000.f;

	float damage;
	float range;

public:
	
	Weapon();

	Weapon(float damageArg);

	Weapon(float damageArg, float rangeArg);


};