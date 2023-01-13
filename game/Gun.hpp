#pragma once

#include "Weapon.hpp"

class Gun : Weapon {
private:

	Texture2D GunTexture;
	Color colorHue;

	int ammoCount;
	int defaultAmmoCount;

	float reloadTime;
	float shootingSpeed;

	float timeSinceLastShot;
	float timeSinceStartReload;

	bool isShooting;
	bool isReloading;

	Vector2 socketCoords;

	void updateTimes();

public:

	Gun();

	void setPos(Vector2 pos);
	
	void setPosToSocket(Vector2 pos, Vector2 socketPos);

	void setSocketCoords(Vector2 coords);

	void shoot();

	void stopShoot();

	void reload();

	void stopReload();

	bool isReadyToShoot();

	void update();

	void reset();

	


};