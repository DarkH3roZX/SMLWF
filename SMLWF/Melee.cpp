#include "Melee.h"

void Melee::setAtkSpeed(int value) {
	attackSpeed = value;
}

void Melee::setMaxRange(int value) {
	maxRange = value;
}

void Melee::setCategory(int index) {
	if (index == 1)
		strcpy_s(category, "Sword");
	else if (index == 2)
		strcpy_s(category, "Hammer");
	else if (index == 3)
		strcpy_s(category, "Glove");
	else if (index == 4)
		strcpy_s(category, "Spear");
}

int Melee::getAtkSpeed() {
	return attackSpeed;
}

int Melee::getMaxRange() {
	return maxRange;
}

string Melee::getCategory() {
	return category;
}