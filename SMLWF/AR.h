#include <iostream>
#include <string>
#include <vector>
#include "Gun.h"
using namespace std;

#ifndef AR_H
#define AR_H

class AR : public Gun {
	private:
		int effectiveRange;

	public:
		AR() {}

		void setEffectiveRange(int value);

		int getEffectiveRange();
};

#endif