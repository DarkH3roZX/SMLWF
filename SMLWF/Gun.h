#include <iostream>
#include <string>
#include <vector>
#include "Weapon.h"
using namespace std;

#ifndef Gun_H
#define Gun_H

class Gun : public Weapon {
	protected:
		int magSize;
		float reloadSpeed;
		int bulletSpeed;
		int fireRate;

	public:
		Gun() {}

		void setMagSize(int value);

		void setReloadSpeed(float value);

		void setBulletSpeed(int value);

		void setFireRate(int value);

		int getMagSize();

		float getReloadSpeed();

		int getBulletSpeed();

		int getFireRate();
};

#endif
