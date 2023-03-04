#include <iostream>
#include <string>
#include <vector>
#include "Gun.h"
using namespace std;

#ifndef Explosive_H
#define Explosive_H

class Explosive : public Gun {
	private:
		int explosiveRadius;

	public:
		Explosive() {}

		void setExplosiveRadius(int value);

		int getExplosiveRadius();
};

#endif