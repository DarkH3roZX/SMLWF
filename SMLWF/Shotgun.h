#include <iostream>
#include <string>
#include <vector>
#include "Gun.h"
using namespace std;

#ifndef Shotgun_H
#define Shotgun_H

class Shotgun : public Gun {
	private:
		int effectiveRange;
		int pelletCount;

	public:
		Shotgun() {}

		void setEffectiveRange(int value);

		void setPelletCount(int value);

		int getEffectiveRange();

		int getPelletCount();
};

#endif