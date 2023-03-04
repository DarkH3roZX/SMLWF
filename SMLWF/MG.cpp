#include "MG.h"

void MG::setMaxRecoil(int value) {
	maxRecoil = value;
}

void MG::setRecoilGain(int value) {
	recoilGain = value;
}

void MG::setEffectiveRange(int value) {
	effectiveRange = value;
}

int MG::getMaxRecoil() {
	return maxRecoil;
}

int MG::getRecoilGain() {
	return recoilGain;
}

int MG::getEffectiveRange() {
	return effectiveRange;
}