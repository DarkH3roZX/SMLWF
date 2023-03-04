#define NOMINMAX
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#ifndef Weapon_H
#define Weapon_H

class Weapon {
	protected:
		char name[21];

		float damage;
		float accuracy;
		float critRate;
		float critDmg;

		int weaponIndex;

	public:
		Weapon() {}

		void setName(string value);

		void setDamage(float value);

		void setAccuracy(float value);

		void setCR(float value);

		void setCD(float value);

		void setIndex(int value);

		string getName();

		float getDamage();

		float getAccuracy();

		float getCR();

		float getCD();

		int getIndex();
};

#endif