#pragma once

#include "Weapon.hpp"
#include "Bullet.hpp"

class Gun : public Weapon {
private:

	static constexpr int defaultAmmoCount = 10;
	static constexpr int defaultMagCount = 10;
	static constexpr int defaultReloadTime = 2;
	static constexpr int defaultShootingSpeed = .5;

	int ammoCount;
	int magCount;
	
	float reloadTime;
	float shootingSpeed;

	float timeSinceLastShot;
	float timeSinceStartReload;

	bool isShooting;
	bool isReloading;

	void updateTimes();

	std::vector<Bullet> bulletVector;

public:

	Gun();

	Gun(int defaultAmmoCountArg, int magCountArg, float reloadTimeArg, float shootingSpeedArg);

	~Gun();

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

    virtual bool getIfGravity() = 0;

	


};