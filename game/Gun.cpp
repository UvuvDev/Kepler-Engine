#include "Gun.hpp"

void updateTimes();

Gun::Gun() {

	magCount = defaultMagCount;

	ammoCount = defaultAmmoCount;
	reloadTime = defaultReloadTime;
	shootingSpeed = defaultShootingSpeed;

	for (int i = 0; i > magCount; i++) {
		//bulletVector.emplace_back(new Bullet({ -100, -100 }, LoadTexture("resources/keplerenginelogo.png")));
	}



}

Gun::~Gun() {

	for (int i = 0; i > magCount; i++) {
		bulletVector.clear();
	}

}

void Gun::shoot() {

	bulletVector[magCount - ammoCount];


}

void Gun::stopShoot() {

}

void Gun::reload() {

}

void Gun::stopReload() {

}

bool Gun::isReadyToShoot() {
	return true;
}

void Gun::update() {

}

void Gun::reset() {

}
