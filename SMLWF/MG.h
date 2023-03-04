#include <iostream>
#include <string>
#include <vector>
#include "Gun.h"
using namespace std;

#ifndef MG_H
#define MG_H

class MG : public Gun {
	private:
		int maxRecoil;
		int recoilGain;
		int effectiveRange;

	public:
		MG() {}

		void setMaxRecoil(int value);

		void setRecoilGain(int value);

		void setEffectiveRange(int value);

		int getMaxRecoil();

		int getRecoilGain();

		int getEffectiveRange();
};

#endif