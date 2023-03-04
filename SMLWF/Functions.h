#define NOMINMAX
#include <iostream>
#include <string>
#include <fstream>
#include <format>
#include <vector>
#include <windows.h>
#include "Utilities.h"
#include "Pistol.h"
#include "Shotgun.h"
#include "SMG.h"
#include "AR.h"
#include "Sniper.h"
#include "MG.h"
#include "Explosive.h"
#include "Melee.h"
using namespace std;

#ifndef Functions_H
#define Functions_H

class Functions {
	private:
		Utilities utility;

	public:
		bool checkValidName(string nameInput, vector<Pistol> pistol, vector<Shotgun> shotgun, vector<SMG> smg, vector<AR> ar, vector<Sniper> sniper, vector<MG> mg, vector<Explosive> explosive, vector<Melee> melee);

		void bubbleSort(int mode, vector<Pistol>& pistol, vector<Shotgun>& shotgun, vector<SMG>& smg, vector<AR>& ar, vector<Sniper>& sniper, vector<MG>& mg, vector<Explosive>& explosive, vector<Melee>& melee);

		void linearSearch(string toSearch, vector<Pistol> pistol, vector<Shotgun> shotgun, vector<SMG> smg, vector<AR> ar, vector<Sniper> sniper, vector<MG> mg, vector<Explosive> explosive, vector<Melee> melee, int& type, int& index);

		void fileUpdate(vector<Pistol> pistol, vector<Shotgun> shotgun, vector<SMG> smg, vector<AR> ar, vector<Sniper> sniper, vector<MG> mg, vector<Explosive> explosive, vector<Melee> melee);

		void fileRead(vector<Pistol>& pistol, vector<Shotgun>& shotgun, vector<SMG>& smg, vector<AR>& ar, vector<Sniper>& sniper, vector<MG>& mg, vector<Explosive>& explosive, vector<Melee>& melee, int& pistols, int& shotguns, int& smgs, int& ars, int& snipers, int& mgs, int& explosives, int& melees, int& totalWeapons);

		void detailsDisplay(string weaponInventoryInput, int inventoryWarp, int displayType, vector<Pistol> pistol, vector<Shotgun> shotgun, vector<SMG> smg, vector<AR> ar, vector<Sniper> sniper, vector<MG> mg, vector<Explosive> explosive, vector<Melee> melee);
};

#endif