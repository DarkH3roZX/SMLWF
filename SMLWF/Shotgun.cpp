#include "Shotgun.h"

void Shotgun::setEffectiveRange(int value) {
	effectiveRange = value;
}

void Shotgun::setPelletCount(int value) {
	pelletCount = value;
}

int Shotgun::getEffectiveRange() {
	return effectiveRange;
}

int Shotgun::getPelletCount() {
	return pelletCount;
}