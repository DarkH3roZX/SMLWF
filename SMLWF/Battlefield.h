#define NOMINMAX
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <format>
#include <windows.h>
#include "Utilities.h"
#include "Functions.h"
#include "Weapon.h"
#include "Gun.h"
#include "Pistol.h"
#include "Shotgun.h"
#include "SMG.h"
#include "AR.h"
#include "Sniper.h"
#include "MG.h"
#include "Explosive.h"
#include "Melee.h"
using namespace std;

#ifndef Battlefield_H
#define Battlefield_H

class Backpack {
	public:
		int weaponIndex;
		int weaponType;

		string name;
};

class Battlefield {
	private:
		// Classes
		Utilities utility;
		Backpack backpack[4];
		Functions functions;

		// Weapons on Inventory
		vector<Pistol> pistol;
		vector<Shotgun> shotgun;
		vector<SMG> smg;
		vector<AR> ar;
		vector<Sniper> sniper;
		vector<MG> mg;
		vector<Explosive> explosive;
		vector<Melee> melee;

		// Information Variables
		int robots;
		int weapons;
		int positions[5][2]; // 0 = player ; 1-4 = bots
		
		int arena[10][10];

		// Battlefield Variables
		int ammos[4];
		int magSizes[4];
		long int botHP[4];
		int currWeapon;

		// Battlefield Stats Variables
		int totalDmg;
		int highestDmg;
		int attacks;

		float timeElapsed;

		// Utility Variables
		int temp;
		int rng;
		int counts[9];

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	public:
		void arenaDisplay();

		void backpackDisplay(int pickedWeapons);

		void hpDisplay();

		void battleUI();

		void initializeArena();
		
		void pickWeapon(int totalWeapons);

		void reset();

		void attack();

		void move();

		void reload();

		void changeWeapon();

		void statsDisplayOnBattlefield(int displayType);

		bool putObject(string coordinate, int object);

		void updateWeaponData();

		float distanceCalculation(int x0, int y0, int x1, int y1);

		int critCalculation(float damage, float critRate, float critDamage, bool& isCrit);

		bool checkAllDeath();

		bool gridInputCheck(string coordinate);

		void statsUpdate(int damage);

		void statsDisplay();
};

#endif