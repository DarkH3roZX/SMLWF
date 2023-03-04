#include <iostream>
#include <string>
#include <vector>
#include "Gun.h"
using namespace std;

#ifndef SMG_H
#define SMG_H

class SMG : public Gun {
	private:
		int effectiveRange;

	public:
		SMG() {}

		void setEffectiveRange(int value);

		int getEffectiveRange();
};

#endif