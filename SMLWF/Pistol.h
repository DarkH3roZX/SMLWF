#include <iostream>
#include <string>
#include <vector>
#include "Gun.h"
using namespace std;

#ifndef Pistol_H
#define Pistol_H

class Pistol : public Gun {
	private:
		int effectiveRange;

	public:
		Pistol() {}

		void setEffectiveRange(int value);

		int getEffectiveRange();
};

#endif
