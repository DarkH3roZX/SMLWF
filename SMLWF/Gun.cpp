#include "Gun.h"

void Gun::setMagSize(int value) {
	magSize = value;
}

void Gun::setReloadSpeed(float value) {
	reloadSpeed = value;
}

void Gun::setBulletSpeed(int value) {
	bulletSpeed = value;
}

void Gun::setFireRate(int value) {
	fireRate = value;
}

int Gun::getMagSize() {
	return magSize;
}

float Gun::getReloadSpeed() {
	return reloadSpeed;
}

int Gun::getBulletSpeed() {
	return bulletSpeed;
}

int Gun::getFireRate() {
	return fireRate;
}