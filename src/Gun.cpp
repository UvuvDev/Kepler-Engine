#include "include/Gun.hpp"

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

Gun::Gun(int defaultAmmoCountArg, int magCountArg, float reloadTimeArg, float shootingSpeedArg) {
    ammoCount = defaultAmmoCountArg;
    magCount = magCountArg;
    reloadTime = reloadTimeArg;
    shootingSpeed = shootingSpeedArg;
}

Gun::~Gun() {

	for (int i = 0; i > magCount; i++) {
		bulletVector.clear();
	}

}

void Gun::setPos(Vector2 pos) {

}

void Gun::setPosToSocket(Vector2 pos, Vector2 socketPos) {

}

void Gun::setSocketCoords(Vector2 coords) {

}

void Gun::shoot() {

	bulletVector[magCount - ammoCount];


}

void Gun::updateTimes() {

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

bool Gun::getIfGravity() {
    return isAffectedByGravity;
}