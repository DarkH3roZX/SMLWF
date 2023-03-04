#include "Functions.h"

bool Functions::checkValidName(string nameInput, vector<Pistol> pistol, vector<Shotgun> shotgun, vector<SMG> smg, vector<AR> ar, vector<Sniper> sniper, vector<MG> mg, vector<Explosive> explosive, vector<Melee> melee) {
	for (int i = 0; i < pistol.size(); i++) {
		if (pistol[i].getName() == nameInput)
			return false;
	}

	for (int i = 0; i < shotgun.size(); i++) {
		if (shotgun[i].getName() == nameInput)
			return false;
	}

	for (int i = 0; i < smg.size(); i++) {
		if (smg[i].getName() == nameInput)
			return false;
	}

	for (int i = 0; i < ar.size(); i++) {
		if (ar[i].getName() == nameInput)
			return false;
	}

	for (int i = 0; i < sniper.size(); i++) {
		if (sniper[i].getName() == nameInput)
			return false;
	}

	for (int i = 0; i < mg.size(); i++) {
		if (mg[i].getName() == nameInput)
			return false;
	}

	for (int i = 0; i < explosive.size(); i++) {
		if (explosive[i].getName() == nameInput)
			return false;
	}

	for (int i = 0; i < melee.size(); i++) {
		if (melee[i].getName() == nameInput)
			return false;
	}

	return true;
}

void Functions::bubbleSort(int mode, vector<Pistol>& pistol, vector<Shotgun>& shotgun, vector<SMG>& smg, vector<AR>& ar, vector<Sniper>& sniper, vector<MG>& mg, vector<Explosive>& explosive, vector<Melee>& melee) {
	int size;
	bool swapped;

	Pistol pistolTemp;
	Shotgun shotgunTemp;
	SMG smgTemp;
	AR arTemp;
	Sniper sniperTemp;
	MG mgTemp;
	Explosive explosiveTemp;
	Melee meleeTemp;

	size = pistol.size();
	for (int i = 0; i < size; i++) {
		swapped = false;

		for (int j = 0; j < size - 1 - i; j++) {
			if (mode == 1 && pistol[j].getName() > pistol[j + 1].getName()) {
				pistolTemp = pistol[j];
				pistol[j] = pistol[j + 1];
				pistol[j + 1] = pistolTemp;

				swapped = true;
			}
			else if (mode == 2 && pistol[j].getName() < pistol[j + 1].getName()) {
				pistolTemp = pistol[j];
				pistol[j] = pistol[j + 1];
				pistol[j + 1] = pistolTemp;

				swapped = true;
			}
			else if (mode == 3 && pistol[j].getIndex() > pistol[j + 1].getIndex()) {
				pistolTemp = pistol[j];
				pistol[j] = pistol[j + 1];
				pistol[j + 1] = pistolTemp;

				swapped = true;
			}
			else if (mode == 4 && pistol[j].getIndex() < pistol[j + 1].getIndex()) {
				pistolTemp = pistol[j];
				pistol[j] = pistol[j + 1];
				pistol[j + 1] = pistolTemp;

				swapped = true;
			}
		}

		if (!swapped)
			break;
	}

	size = shotgun.size();
	for (int i = 0; i < size; i++) {
		swapped = false;

		for (int j = 0; j < size - 1 - i; j++) {
			if (mode == 1 && shotgun[j].getName() > shotgun[j + 1].getName()) {
				shotgunTemp = shotgun[j];
				shotgun[j] = shotgun[j + 1];
				shotgun[j + 1] = shotgunTemp;

				swapped = true;
			}
			else if (mode == 2 && shotgun[j].getName() < shotgun[j + 1].getName()) {
				shotgunTemp = shotgun[j];
				shotgun[j] = shotgun[j + 1];
				shotgun[j + 1] = shotgunTemp;

				swapped = true;
			}
			else if (mode == 3 && shotgun[j].getIndex() > shotgun[j + 1].getIndex()) {
				shotgunTemp = shotgun[j];
				shotgun[j] = shotgun[j + 1];
				shotgun[j + 1] = shotgunTemp;

				swapped = true;
			}
			else if (mode == 4 && shotgun[j].getIndex() < shotgun[j + 1].getIndex()) {
				shotgunTemp = shotgun[j];
				shotgun[j] = shotgun[j + 1];
				shotgun[j + 1] = shotgunTemp;

				swapped = true;
			}
		}

		if (!swapped)
			break;
	}

	size = smg.size();
	for (int i = 0; i < size; i++) {
		swapped = false;

		for (int j = 0; j < size - 1 - i; j++) {
			if (mode == 1 && smg[j].getName() > smg[j + 1].getName()) {
				smgTemp = smg[j];
				smg[j] = smg[j + 1];
				smg[j + 1] = smgTemp;

				swapped = true;
			}
			else if (mode == 2 && smg[j].getName() < smg[j + 1].getName()) {
				smgTemp = smg[j];
				smg[j] = smg[j + 1];
				smg[j + 1] = smgTemp;

				swapped = true;
			}
			else if (mode == 3 && smg[j].getIndex() > smg[j + 1].getIndex()) {
				smgTemp = smg[j];
				smg[j] = smg[j + 1];
				smg[j + 1] = smgTemp;

				swapped = true;
			}
			else if (mode == 4 && smg[j].getIndex() < smg[j + 1].getIndex()) {
				smgTemp = smg[j];
				smg[j] = smg[j + 1];
				smg[j + 1] = smgTemp;

				swapped = true;
			}
		}

		if (!swapped)
			break;
	}

	size = ar.size();
	for (int i = 0; i < size; i++) {
		swapped = false;

		for (int j = 0; j < size - 1 - i; j++) {
			if (mode == 1 && ar[j].getName() > ar[j + 1].getName()) {
				arTemp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = arTemp;

				swapped = true;
			}
			else if (mode == 2 && ar[j].getName() < ar[j + 1].getName()) {
				arTemp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = arTemp;

				swapped = true;
			}
			else if (mode == 3 && ar[j].getIndex() > ar[j + 1].getIndex()) {
				arTemp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = arTemp;

				swapped = true;
			}
			else if (mode == 4 && ar[j].getIndex() < ar[j + 1].getIndex()) {
				arTemp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = arTemp;

				swapped = true;
			}
		}

		if (!swapped)
			break;
	}

	size = sniper.size();
	for (int i = 0; i < size; i++) {
		swapped = false;

		for (int j = 0; j < size - 1 - i; j++) {
			if (mode == 1 && sniper[j].getName() > sniper[j + 1].getName()) {
				sniperTemp = sniper[j];
				sniper[j] = sniper[j + 1];
				sniper[j + 1] = sniperTemp;

				swapped = true;
			}
			else if (mode == 2 && sniper[j].getName() < sniper[j + 1].getName()) {
				sniperTemp = sniper[j];
				sniper[j] = sniper[j + 1];
				sniper[j + 1] = sniperTemp;

				swapped = true;
			}
			else if (mode == 3 && sniper[j].getIndex() > sniper[j + 1].getIndex()) {
				sniperTemp = sniper[j];
				sniper[j] = sniper[j + 1];
				sniper[j + 1] = sniperTemp;

				swapped = true;
			}
			else if (mode == 4 && sniper[j].getIndex() < sniper[j + 1].getIndex()) {
				sniperTemp = sniper[j];
				sniper[j] = sniper[j + 1];
				sniper[j + 1] = sniperTemp;

				swapped = true;
			}
		}

		if (!swapped)
			break;
	}

	size = mg.size();
	for (int i = 0; i < size; i++) {
		swapped = false;

		for (int j = 0; j < size - 1 - i; j++) {
			if (mode == 1 && mg[j].getName() > mg[j + 1].getName()) {
				mgTemp = mg[j];
				mg[j] = mg[j + 1];
				mg[j + 1] = mgTemp;

				swapped = true;
			}
			else if (mode == 2 && mg[j].getName() < mg[j + 1].getName()) {
				mgTemp = mg[j];
				mg[j] = mg[j + 1];
				mg[j + 1] = mgTemp;

				swapped = true;
			}
			else if (mode == 3 && mg[j].getIndex() > mg[j + 1].getIndex()) {
				mgTemp = mg[j];
				mg[j] = mg[j + 1];
				mg[j + 1] = mgTemp;

				swapped = true;
			}
			else if (mode == 4 && mg[j].getIndex() < mg[j + 1].getIndex()) {
				mgTemp = mg[j];
				mg[j] = mg[j + 1];
				mg[j + 1] = mgTemp;

				swapped = true;
			}
		}

		if (!swapped)
			break;
	}

	size = explosive.size();
	for (int i = 0; i < size; i++) {
		swapped = false;

		for (int j = 0; j < size - 1 - i; j++) {
			if (mode == 1 && explosive[j].getName() > explosive[j + 1].getName()) {
				explosiveTemp = explosive[j];
				explosive[j] = explosive[j + 1];
				explosive[j + 1] = explosiveTemp;

				swapped = true;
			}
			else if (mode == 2 && explosive[j].getName() < explosive[j + 1].getName()) {
				explosiveTemp = explosive[j];
				explosive[j] = explosive[j + 1];
				explosive[j + 1] = explosiveTemp;

				swapped = true;
			}
			else if (mode == 3 && explosive[j].getIndex() > explosive[j + 1].getIndex()) {
				explosiveTemp = explosive[j];
				explosive[j] = explosive[j + 1];
				explosive[j + 1] = explosiveTemp;

				swapped = true;
			}
			else if (mode == 4 && explosive[j].getIndex() < explosive[j + 1].getIndex()) {
				explosiveTemp = explosive[j];
				explosive[j] = explosive[j + 1];
				explosive[j + 1] = explosiveTemp;

				swapped = true;
			}
		}

		if (!swapped)
			break;
	}

	size = melee.size();
	for (int i = 0; i < size; i++) {
		swapped = false;

		for (int j = 0; j < size - 1 - i; j++) {
			if (mode == 1 && melee[j].getName() > melee[j + 1].getName()) {
				meleeTemp = melee[j];
				melee[j] = melee[j + 1];
				melee[j + 1] = meleeTemp;

				swapped = true;
			}
			else if (mode == 2 && melee[j].getName() < melee[j + 1].getName()) {
				meleeTemp = melee[j];
				melee[j] = melee[j + 1];
				melee[j + 1] = meleeTemp;

				swapped = true;
			}
			else if (mode == 3 && melee[j].getIndex() > melee[j + 1].getIndex()) {
				meleeTemp = melee[j];
				melee[j] = melee[j + 1];
				melee[j + 1] = meleeTemp;

				swapped = true;
			}
			else if (mode == 4 && melee[j].getIndex() < melee[j + 1].getIndex()) {
				meleeTemp = melee[j];
				melee[j] = melee[j + 1];
				melee[j + 1] = meleeTemp;

				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}
void Functions::linearSearch(string toSearch, vector<Pistol> pistol, vector<Shotgun> shotgun, vector<SMG> smg, vector<AR> ar, vector<Sniper> sniper, vector<MG> mg, vector<Explosive> explosive, vector<Melee> melee, int& type, int& index) {
	int size = pistol.size();
	for (int i = 0; i < size; i++) {
		if (pistol[i].getName() == toSearch) {
			type = 0;
			index = i;

			return;
		}
	}

	size = shotgun.size();
	for (int i = 0; i < size; i++) {
		if (shotgun[i].getName() == toSearch) {
			type = 1;
			index = i;

			return;
		}
	}

	size = smg.size();
	for (int i = 0; i < size; i++) {
		if (smg[i].getName() == toSearch) {
			type = 2;
			index = i;

			return;
		}
	}

	size = ar.size();
	for (int i = 0; i < size; i++) {
		if (ar[i].getName() == toSearch) {
			type = 3;
			index = i;

			return;
		}
	}

	size = sniper.size();
	for (int i = 0; i < size; i++) {
		if (sniper[i].getName() == toSearch) {
			type = 4;
			index = i;

			return;
		}
	}

	size = mg.size();
	for (int i = 0; i < size; i++) {
		if (mg[i].getName() == toSearch) {
			type = 5;
			index = i;

			return;
		}
	}

	size = explosive.size();
	for (int i = 0; i < size; i++) {
		if (explosive[i].getName() == toSearch) {
			type = 6;
			index = i;

			return;
		}
	}

	size = melee.size();
	for (int i = 0; i < size; i++) {
		if (melee[i].getName() == toSearch) {
			type = 7;
			index = i;

			return;
		}
	}

	type = -1;
	index = -1;
}

void Functions::fileUpdate(vector<Pistol> pistol, vector<Shotgun> shotgun, vector<SMG> smg, vector<AR> ar, vector<Sniper> sniper, vector<MG> mg, vector<Explosive> explosive, vector<Melee> melee) {
	fstream fptr;

	Pistol pistolCopy;
	Shotgun shotgunCopy;
	SMG smgCopy;
	AR arCopy;
	Sniper sniperCopy;
	MG mgCopy;
	Explosive explosiveCopy;
	Melee meleeCopy;

	fptr.open("Weapons.dhzx", ios::out | ios::binary);

	// Pistol
	int size = pistol.size();
	fptr.write((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++) {
		pistolCopy = pistol[i];
		fptr.write((char*)&pistolCopy, sizeof(pistolCopy));
	}

	// Shotgun
	size = shotgun.size();
	fptr.write((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++) {
		shotgunCopy = shotgun[i];
		fptr.write((char*)&shotgunCopy, sizeof(shotgunCopy));
	}

	// SMG
	size = smg.size();
	fptr.write((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++) {
		smgCopy = smg[i];
		fptr.write((char*)&smgCopy, sizeof(smgCopy));
	}

	// AR
	size = ar.size();
	fptr.write((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++) {
		arCopy = ar[i];
		fptr.write((char*)&arCopy, sizeof(arCopy));
	}

	// Sniper
	size = sniper.size();
	fptr.write((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++) {
		sniperCopy = sniper[i];
		fptr.write((char*)&sniperCopy, sizeof(sniperCopy));
	}

	// MG
	size = mg.size();
	fptr.write((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++) {
		mgCopy = mg[i];
		fptr.write((char*)&mgCopy, sizeof(mgCopy));
	}

	// Explosive
	size = explosive.size();
	fptr.write((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++) {
		explosiveCopy = explosive[i];
		fptr.write((char*)&explosiveCopy, sizeof(explosiveCopy));
	}

	// Melee
	size = melee.size();
	fptr.write((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++) {
		meleeCopy = melee[i];
		fptr.write((char*)&meleeCopy, sizeof(meleeCopy));
	}

	fptr.close();
}

void Functions::fileRead(vector<Pistol>& pistol, vector<Shotgun>& shotgun, vector<SMG>& smg, vector<AR>& ar, vector<Sniper>& sniper, vector<MG>& mg, vector<Explosive>& explosive, vector<Melee>& melee, int& pistols, int& shotguns, int& smgs, int& ars, int& snipers, int& mgs, int& explosives, int& melees, int& totalWeapons) {
	int tempInt;
	fstream fptr;

	Pistol pistolTemp;
	Shotgun shotgunTemp;
	SMG smgTemp;
	AR arTemp;
	Sniper sniperTemp;
	MG mgTemp;
	Explosive explosiveTemp;
	Melee meleeTemp;

	fptr.open("Weapons.dhzx", ios::in | ios::binary);

	if (!fptr.is_open()) {
		fptr.close();
		fptr.open("Weapons.dhzx", ios::out | ios::binary);

		tempInt = 0;
		for (int i = 0; i < 8; i++) {
			fptr.write((char*)&tempInt, sizeof(tempInt));
		}
	}

	// Read the file
	else {
		// Pistol
		fptr.read((char*)&pistols, sizeof(pistols));
		int size = pistols;

		for (int i = 0; i < size; i++) {
			fptr.read((char*)&pistolTemp, sizeof(pistolTemp));
			pistol.push_back(pistolTemp);
		}

		// Shotgun
		fptr.read((char*)&shotguns, sizeof(shotguns));
		size = shotguns;

		for (int i = 0; i < size; i++) {
			fptr.read((char*)&shotgunTemp, sizeof(shotgunTemp));
			shotgun.push_back(shotgunTemp);
		}

		// SMG
		fptr.read((char*)&smgs, sizeof(smgs));
		size = smgs;

		for (int i = 0; i < size; i++) {
			fptr.read((char*)&smgTemp, sizeof(smgTemp));
			smg.push_back(smgTemp);
		}

		// AR
		fptr.read((char*)&ars, sizeof(ars));
		size = ars;

		for (int i = 0; i < size; i++) {
			fptr.read((char*)&arTemp, sizeof(arTemp));
			ar.push_back(arTemp);
		}

		// Sniper
		fptr.read((char*)&snipers, sizeof(snipers));
		size = snipers;

		for (int i = 0; i < size; i++) {
			fptr.read((char*)&sniperTemp, sizeof(sniperTemp));
			sniper.push_back(sniperTemp);
		}

		// MG
		fptr.read((char*)&mgs, sizeof(mgs));
		size = mgs;

		for (int i = 0; i < size; i++) {
			fptr.read((char*)&mgTemp, sizeof(mgTemp));
			mg.push_back(mgTemp);
		}

		// Explosive
		fptr.read((char*)&explosives, sizeof(explosives));
		size = explosives;

		for (int i = 0; i < size; i++) {
			fptr.read((char*)&explosiveTemp, sizeof(explosiveTemp));
			explosive.push_back(explosiveTemp);
		}

		// Melee
		fptr.read((char*)&melees, sizeof(melees));
		size = melees;

		for (int i = 0; i < size; i++) {
			fptr.read((char*)&meleeTemp, sizeof(meleeTemp));
			melee.push_back(meleeTemp);
		}
	}

	totalWeapons = pistols + shotguns + smgs + ars + snipers + mgs + explosives + melees;
	fptr.close();
}

void Functions::detailsDisplay(string weaponInventoryInput, int inventoryWarp, int displayType, vector<Pistol> pistol, vector<Shotgun> shotgun, vector<SMG> smg, vector<AR> ar, vector<Sniper> sniper, vector<MG> mg, vector<Explosive> explosive, vector<Melee> melee) {
	int index;
	int size;

	// Index reset
	index = -1;

	/*
	 Find a weapon
	 */
	 // Pistol
	if (inventoryWarp == 1) {
		size = pistol.size();
		for (int i = 0; i < size; i++) {
			if (weaponInventoryInput == pistol[i].getName()) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			utility.logo();
			utility.subtitile(weaponInventoryInput);

			if (displayType == 1) {
				cout << "Damage: " << (int)pistol[index].getDamage() << endl;
				cout << "Accuracy: " << pistol[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << pistol[index].getCR() << "%\n";
				cout << "Crit DMG: " << pistol[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << pistol[index].getMagSize() << endl;
				cout << "Reload Speed: " << pistol[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << pistol[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << pistol[index].getFireRate() << "rpm\n";
				cout << "Effective Range: " << pistol[index].getEffectiveRange() << "m\n";
			}
			else if (displayType == 2) {
				cout << "Damage: " << (int)pistol[index].getDamage() << endl;
				cout << "Accuracy: " << (int)pistol[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << (int)pistol[index].getCR() << "%\n";
				cout << "Crit DMG: " << (int)pistol[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << pistol[index].getMagSize() << endl;
				cout << "Reload Speed: " << (int)pistol[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << pistol[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << pistol[index].getFireRate() << "rpm\n";
				cout << "Effective Range: " << pistol[index].getEffectiveRange() << "m\n";
			}

			cout << "\nPress 'Enter' to continue.";
			cin.get();
		}
	}

	// Shotgun
	else if (inventoryWarp == 2) {
		size = shotgun.size();
		for (int i = 0; i < size; i++) {
			if (weaponInventoryInput == shotgun[i].getName()) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			utility.logo();
			utility.subtitile(weaponInventoryInput);

			if (displayType == 1) {
				cout << "Damage: " << (int)shotgun[index].getDamage() << endl;
				cout << "Accuracy: " << shotgun[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << shotgun[index].getCR() << "%\n";
				cout << "Crit DMG: " << shotgun[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << shotgun[index].getMagSize() << endl;
				cout << "Reload Speed: " << shotgun[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << shotgun[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << shotgun[index].getFireRate() << "rpm\n";
				cout << "Pellet Count: " << shotgun[index].getPelletCount() << endl;
				cout << "Effective Range: " << shotgun[index].getEffectiveRange() << "m\n";
			}
			else if (displayType == 2) {
				cout << "Damage: " << (int)shotgun[index].getDamage() << endl;
				cout << "Accuracy: " << (int)shotgun[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << (int)shotgun[index].getCR() << "%\n";
				cout << "Crit DMG: " << (int)shotgun[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << shotgun[index].getMagSize() << endl;
				cout << "Reload Speed: " << (int)shotgun[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << shotgun[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << shotgun[index].getFireRate() << "rpm\n";
				cout << "Pellet Count: " << shotgun[index].getPelletCount() << endl;
				cout << "Effective Range: " << shotgun[index].getEffectiveRange() << "m\n";
			}

			cout << "\nPress 'Enter' to continue.";
			cin.get();
		}
	}

	// SMG
	else if (inventoryWarp == 3) {
		size = smg.size();
		for (int i = 0; i < size; i++) {
			if (weaponInventoryInput == smg[i].getName()) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			utility.logo();
			utility.subtitile(weaponInventoryInput);

			if (displayType == 1) {
				cout << "Damage: " << (int)smg[index].getDamage() << endl;
				cout << "Accuracy: " << smg[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << smg[index].getCR() << "%\n";
				cout << "Crit DMG: " << smg[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << smg[index].getMagSize() << endl;
				cout << "Reload Speed: " << smg[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << smg[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << smg[index].getFireRate() << "rpm\n";
				cout << "Effective Range: " << smg[index].getEffectiveRange() << "m\n";
			}
			else if (displayType == 2) {
				cout << "Damage: " << (int)smg[index].getDamage() << endl;
				cout << "Accuracy: " << (int)smg[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << (int)smg[index].getCR() << "%\n";
				cout << "Crit DMG: " << (int)smg[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << smg[index].getMagSize() << endl;
				cout << "Reload Speed: " << (int)smg[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << smg[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << smg[index].getFireRate() << "rpm\n";
				cout << "Effective Range: " << smg[index].getEffectiveRange() << "m\n";
			}

			cout << "\nPress 'Enter' to continue.";
			cin.get();
		}
	}

	// AR
	else if (inventoryWarp == 4) {
		size = ar.size();
		for (int i = 0; i < size; i++) {
			if (weaponInventoryInput == ar[i].getName()) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			utility.logo();
			utility.subtitile(weaponInventoryInput);

			if (displayType == 1) {
				cout << "Damage: " << (int)ar[index].getDamage() << endl;
				cout << "Accuracy: " << ar[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << ar[index].getCR() << "%\n";
				cout << "Crit DMG: " << ar[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << ar[index].getMagSize() << endl;
				cout << "Reload Speed: " << ar[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << ar[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << ar[index].getFireRate() << "rpm\n";
				cout << "Effective Range: " << ar[index].getEffectiveRange() << "m\n";
			}
			else if (displayType == 2) {
				cout << "Damage: " << (int)ar[index].getDamage() << endl;
				cout << "Accuracy: " << (int)ar[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << (int)ar[index].getCR() << "%\n";
				cout << "Crit DMG: " << (int)ar[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << ar[index].getMagSize() << endl;
				cout << "Reload Speed: " << (int)ar[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << ar[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << ar[index].getFireRate() << "rpm\n";
				cout << "Effective Range: " << ar[index].getEffectiveRange() << "m\n";
			}

			cout << "\nPress 'Enter' to continue.";
			cin.get();
		}
	}

	// Sniper
	else if (inventoryWarp == 5) {
		size = sniper.size();
		for (int i = 0; i < size; i++) {
			if (weaponInventoryInput == sniper[i].getName()) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			utility.logo();
			utility.subtitile(weaponInventoryInput);

			if (displayType == 1) {
				cout << "Damage: " << (int)sniper[index].getDamage() << endl;
				cout << "Accuracy: " << sniper[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << sniper[index].getCR() << "%\n";
				cout << "Crit DMG: " << sniper[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << sniper[index].getMagSize() << endl;
				cout << "Reload Speed: " << sniper[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << sniper[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << sniper[index].getFireRate() << "rpm\n";
				cout << "Scope Size: " << sniper[index].getScopeSize() << "x\n";
			}
			else if (displayType == 2) {
				cout << "Damage: " << (int)sniper[index].getDamage() << endl;
				cout << "Accuracy: " << (int)sniper[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << (int)sniper[index].getCR() << "%\n";
				cout << "Crit DMG: " << (int)sniper[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << sniper[index].getMagSize() << endl;
				cout << "Reload Speed: " << (int)sniper[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << sniper[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << sniper[index].getFireRate() << "rpm\n";
				cout << "Scope Size: " << sniper[index].getScopeSize() << "x\n";
			}

			cout << "\nPress 'Enter' to continue.";
			cin.get();
		}
	}

	// MG
	else if (inventoryWarp == 6) {
		size = mg.size();
		for (int i = 0; i < size; i++) {
			if (weaponInventoryInput == mg[i].getName()) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			utility.logo();
			utility.subtitile(weaponInventoryInput);

			if (displayType == 1) {
				cout << "Damage: " << (int)mg[index].getDamage() << endl;
				cout << "Accuracy: " << mg[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << mg[index].getCR() << "%\n";
				cout << "Crit DMG: " << mg[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << mg[index].getMagSize() << endl;
				cout << "Reload Speed: " << mg[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << mg[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << mg[index].getFireRate() << "rpm\n";
				cout << "Effective Range: " << mg[index].getEffectiveRange() << "m\n";
				cout << "Max Recoil: " << mg[index].getMaxRecoil() << endl;
				cout << "Recoil Gain / round: " << mg[index].getRecoilGain() << endl;
			}
			else if (displayType == 2) {
				cout << "Damage: " << (int)mg[index].getDamage() << endl;
				cout << "Accuracy: " << (int)mg[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << (int)mg[index].getCR() << "%\n";
				cout << "Crit DMG: " << (int)mg[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << mg[index].getMagSize() << endl;
				cout << "Reload Speed: " << (int)mg[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << mg[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << mg[index].getFireRate() << "rpm\n";
				cout << "Effective Range: " << mg[index].getEffectiveRange() << "m\n";
				cout << "Max Recoil: " << mg[index].getMaxRecoil() << endl;
				cout << "Recoil Gain / round: " << mg[index].getRecoilGain() << endl;
			}

			cout << "\nPress 'Enter' to continue.";
			cin.get();
		}
	}

	// Explosives
	else if (inventoryWarp == 7) {
		size = explosive.size();
		for (int i = 0; i < size; i++) {
			if (weaponInventoryInput == explosive[i].getName()) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			utility.logo();
			utility.subtitile(weaponInventoryInput);

			if (displayType == 1) {
				cout << "Damage: " << (int)explosive[index].getDamage() << endl;
				cout << "Accuracy: " << explosive[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << explosive[index].getCR() << "%\n";
				cout << "Crit DMG: " << explosive[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << explosive[index].getMagSize() << endl;
				cout << "Reload Speed: " << explosive[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << explosive[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << explosive[index].getFireRate() << "rpm\n";
				cout << "Explosive Radius: " << explosive[index].getExplosiveRadius() << "m\n";
			}
			else if (displayType == 2) {
				cout << "Damage: " << (int)explosive[index].getDamage() << endl;
				cout << "Accuracy: " << (int)explosive[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << (int)explosive[index].getCR() << "%\n";
				cout << "Crit Dexplosive: " << (int)explosive[index].getCD() << "%\n\n";

				cout << "Magazine Size: " << explosive[index].getMagSize() << endl;
				cout << "Reload Speed: " << (int)explosive[index].getReloadSpeed() << "s\n";
				cout << "Bullet Speed: " << explosive[index].getBulletSpeed() << "m/s\n";
				cout << "Fire Rate: " << explosive[index].getFireRate() << "rpm\n";
				cout << "Explosive Radius: " << explosive[index].getExplosiveRadius() << "m\n";
			}

			cout << "\nPress 'Enter' to continue.";
			cin.get();
		}
	}

	// Melee
	else if (inventoryWarp == 8) {
		size = melee.size();
		for (int i = 0; i < size; i++) {
			if (weaponInventoryInput == melee[i].getName()) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			utility.logo();
			utility.subtitile(weaponInventoryInput);

			if (displayType == 1) {
				cout << "Damage: " << (int)melee[index].getDamage() << endl;
				cout << "Accuracy: " << melee[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << melee[index].getCR() << "%\n";
				cout << "Crit DMG: " << melee[index].getCD() << "%\n\n";

				cout << "Attack Speed: " << melee[index].getAtkSpeed() << "hpm\n";
				cout << "Max Range: " << melee[index].getMaxRange() << "m\n";
				cout << "Category: " << melee[index].getCategory() << endl;
			}
			else if (displayType == 2) {
				cout << "Damage: " << (int)melee[index].getDamage() << endl;
				cout << "Accuracy: " << (int)melee[index].getAccuracy() << "%\n";
				cout << "Crit RATE: " << (int)melee[index].getCR() << "%\n";
				cout << "Crit Dmelee: " << (int)melee[index].getCD() << "%\n\n";

				cout << "Attack Speed: " << melee[index].getAtkSpeed() << "hpm\n";
				cout << "Max Range: " << melee[index].getMaxRange() << "m\n";
				cout << "Category: " << melee[index].getCategory() << endl;
			}

			cout << "\nPress 'Enter' to continue.";
			cin.get();
		}
	}

	if (index == -1) {
		cout << "Weapon Not Found!";
		cin.get();
	}
}