#include "Weapon.hpp"

Weapon::Weapon() {

	damage = defaultDamage;
	range = defaultRange;

}

Weapon::Weapon(float damageArg) {

	damage = damageArg;
	range = defaultRange;

}

Weapon::Weapon(float damageArg, float rangeArg) {

	damage = damageArg;
	range = rangeArg;

}
