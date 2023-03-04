#include "Weapon.h"

void Weapon::setName(string value) {
	strcpy_s(name, value.c_str());
}

void Weapon::setDamage(float value) {
	damage = value;
}

void Weapon::setAccuracy(float value) {
	accuracy = value;
}

void Weapon::setCR(float value) {
	critRate = value;
}

void Weapon::setCD(float value) {
	critDmg = value;
}

void Weapon::setIndex(int value) {
	weaponIndex = value;
}

string Weapon::getName() {
	return name;
}

float Weapon::getDamage() {
	return damage;
}

float Weapon::getAccuracy() {
	return accuracy;
}

float Weapon::getCR() {
	return critRate;
}

float Weapon::getCD() {
	return critDmg;
}

int Weapon::getIndex() {
	return weaponIndex;
}