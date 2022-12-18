#pragma once
#include "BaseClass.hpp"

class Weapon : BaseClass {
private:
	float damage;
	float range;

public:
	
	Weapon();

	Weapon(float damageArg);

	Weapon(float damageArg, float rangeArg);


};