#include <iostream>
#include <string>
#include <vector>
#include "Weapon.h"
using namespace std;

#ifndef Melee_H
#define Melee_H

class Melee : public Weapon {
	private:
		int attackSpeed;
		int maxRange;
		
		char category[11];

	public:
		Melee() {}
		
		void setAtkSpeed(int value);

		void setMaxRange(int value);

		void setCategory(int index);

		int getAtkSpeed();

		int getMaxRange();

		string getCategory();
};

#endif