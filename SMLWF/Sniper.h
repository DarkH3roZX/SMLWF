#include <iostream>
#include <string>
#include <vector>
#include "Gun.h"
using namespace std;

#ifndef Sniper_H
#define Sniper_H

class Sniper : public Gun {
	private:
		int scopeSize;

	public:
		Sniper() {}

		void setScopeSize(int value);

		int getScopeSize();
};

#endif