#include "Battlefield.h"

void Battlefield::arenaDisplay() {
	for (int i = 0; i < 21; i++) {
		if (i % 2 == 0) {
			cout << "   ";

			for (int j = 0; j < 10; j++)
				cout << "+---";

			cout << "+\n";
		}
		else {
			cout << " " << 9 - i / 2 << " ";

			for (int j = 0; j < 10; j++) {
				if (arena[i / 2][j] == -1)
					cout << "|   ";
				else if (arena[i / 2][j] == 0) {
					cout << "| ";
					SetConsoleTextAttribute(h, 6);
					cout << "P";
					SetConsoleTextAttribute(h, 15);
					cout << " ";
				}
				else {
					cout << "| ";

					if (botHP[arena[i / 2][j] - 1] == 0) {
						SetConsoleTextAttribute(h, 4);
					}
					else {
						SetConsoleTextAttribute(h, 10);
					}

					cout << arena[i / 2][j];
					SetConsoleTextAttribute(h, 15);
					cout << " ";
				}
			}

			cout << "|\n";
		}
	}

	cout << "     ";

	for (int i = 0; i < 10; i++)
		cout << (char)(i + 'A') << "   ";

	cout << "\n\n";
}

void Battlefield::backpackDisplay(int pickedWeapons) {
	for (int i = 0; i < 4; i++) {
		cout << "==========================================\n";

		if (i < pickedWeapons && backpack[i].weaponType == 7)
			cout << "Slot " << i + 1 << ": " << backpack[i].name << " (" << static_cast<unsigned char>(236) << ")\n";
		else if (i < pickedWeapons)
			cout << "Slot " << i + 1 << ": " << backpack[i].name << " (" << ammos[i] << "/" << magSizes[i] << ")\n";
		else
			cout << "Empty" << endl;
	}

	cout << "==========================================\n\n";
}

void Battlefield::hpDisplay() {
	cout << "Bot HPs:\n";

	for (int i = 0; i < robots; i++)
		cout << "Bot " << i + 1 << " HP: " << botHP[i] << endl;
	
	cout << endl;
}

void Battlefield::battleUI() {
	arenaDisplay();
	backpackDisplay(weapons);
	hpDisplay();

	cout << "Current Weapon: " << backpack[currWeapon].name << endl;
	cout << "Time Elapsed: " << format("{0:.1f}", timeElapsed) << "s" << endl << endl;
}

void Battlefield::initializeArena() {
	string coordinateInput;

	// Clear up the entire arena
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arena[i][j] = -1;
		}
	}

	// Set Bot HP to -1
	for (int i = 0; i < 4; i++)
		botHP[i] = -1;

	// Set position for tester
	do
	{
		system("cls");
		arenaDisplay();

		cout << "Set position for tester: ";
		cin >> coordinateInput;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while (!putObject(coordinateInput, 0));

	// Set the amount of bots
	do
	{
		system("cls");
		arenaDisplay();

		cout << "Input amount of bots (1-4): ";
		cin >> robots;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while (robots < 1 || robots > 4);

	// Put the bots
	for (int i = 1; i <= robots; i++) {
		do
		{
			system("cls");
			arenaDisplay();

			cout << "Set position for Bot " << i << ": ";
			cin >> coordinateInput;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		while (!putObject(coordinateInput, i));

		do
		{
			cout << "Set HP for Bot " << i << " (50-1000000): ";
			cin >> botHP[i - 1];
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		while (botHP[i - 1] < 50 || botHP[i - 1] > 1000000);
	}
}

void Battlefield::pickWeapon(int totalWeapons) {
	string weaponInput;

	bool continuer;

	do
	{
		system("cls");
		arenaDisplay();

		cout << "How much weapon you want to bring: ";
		cin >> weapons;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (weapons > totalWeapons) {
			cout << "You don't have that much weapon!";
			cin.get();
		}
		else {
			break;
		}
	}
	while (true);

	for (int i = 0; i < weapons; i++) {
		do
		{
			system("cls");
			backpackDisplay(i);

			if (i == 0)
				cout << "Pick 1st weapon: ";
			else if (i == 1)
				cout << "Pick 2nd weapon: ";
			else if (i == 2)
				cout << "Pick 3rd weapon: ";
			else if (i == 3)
				cout << "Pick 4th weapon: ";

			cin >> weaponInput;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			// Check if weapon is in the list
			functions.linearSearch(weaponInput, pistol, shotgun, smg, ar, sniper, mg, explosive, melee, backpack[i].weaponType, backpack[i].weaponIndex);

			if (backpack[i].weaponType == -1) {
				cout << "Weapon not Found!";
				cin.get();

				continue;
			}

			// Check if the weapons is already used
			continuer = false;

			for (int j = 0; j < i; j++) {
				if (backpack[j].weaponType == backpack[i].weaponType && backpack[j].weaponIndex == backpack[i].weaponIndex) {
					continuer = true;

					break;
				}
			}

			if (continuer) {
				cout << "Weapon already used!";
				cin.get();

				continue;
			}

			break;
		}
		while (true);

		// End check
		backpack[i].name = weaponInput;

		if (backpack[i].weaponType == 0)
			magSizes[i] = ammos[i] = pistol[backpack[i].weaponIndex].getMagSize();
		else if (backpack[i].weaponType == 1)
			magSizes[i] = ammos[i] = shotgun[backpack[i].weaponIndex].getMagSize();
		else if (backpack[i].weaponType == 2)
			magSizes[i] = ammos[i] = smg[backpack[i].weaponIndex].getMagSize();
		else if (backpack[i].weaponType == 3)
			magSizes[i] = ammos[i] = ar[backpack[i].weaponIndex].getMagSize();
		else if (backpack[i].weaponType == 4)
			magSizes[i] = ammos[i] = sniper[backpack[i].weaponIndex].getMagSize();
		else if (backpack[i].weaponType == 5)
			magSizes[i] = ammos[i] = mg[backpack[i].weaponIndex].getMagSize();
		else if (backpack[i].weaponType == 6)
			magSizes[i] = ammos[i] = explosive[backpack[i].weaponIndex].getMagSize();
		else if (backpack[i].weaponType == 7)
			magSizes[i] = ammos[i] = -1;
	}
}

void Battlefield::reset() {
	currWeapon = 0;
	timeElapsed = 0;
	totalDmg = 0;
	highestDmg = 0;
	attacks = 0;

	for (int i = 0; i < 4; i++)
		isDead[i] = false;
}

void Battlefield::attack() {
	// Variables
	int rng;
	int botInput;
	int realDamage = 0;
	int bullets;

	float distanceToPlayer;
	float accuracy;

	bool isCrit;

	char getcharInput;

	// Shotgun special variables
	int maxPelletHit;
	int damageTemp;
	int pelletHits;
	bool onePelletHeadshot;

	// Explosive special variables
	float distanceBetweenBots;
	bool isHit[4];
	int hitted;
	string areaInput;

	if (ammos[currWeapon] == 0 && backpack[currWeapon].weaponType != 7) {
		cout << "Reload the weapon first!";
		cin.get();

		return;
	}
	
	do
	{
		system("cls");
		arenaDisplay();
		hpDisplay();

		if (backpack[currWeapon].weaponType == 6) {
			cout << "Pick a square to attack: ";
			cin >> areaInput;
		}
		else {
			cout << "Pick a bot to attack: ";
			cin >> botInput;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while ( (backpack[currWeapon].weaponType != 6 && (botInput < 1 || botInput > robots)) || (backpack[currWeapon].weaponType == 6 && !gridInputCheck(areaInput)) );

	if (backpack[currWeapon].weaponType != 6 && botHP[botInput - 1] == 0) {
		cout << "Bot is destroyed!";
		cin.get();

		return;
	}

	// Pistol
	if (backpack[currWeapon].weaponType == 0) {
		for (int i = 0; i <= pistol[backpack[currWeapon].weaponIndex].getMagSize(); i++) {
			system("cls");
			arenaDisplay();
			hpDisplay();

			if (i != 0) {
				if (realDamage == 0)
					cout << "You Missed!" << endl;
				else if (isCrit)
					cout << "Bot " << botInput << " Took " << realDamage << " damage! (Critical)" << endl;
				else
					cout << "Bot " << botInput << " Took " << realDamage << " damage!" << endl;
			}

			if (botHP[botInput - 1] <= 0) {
				cout << "Bot destroyed, Press 'Enter' to continue!";
				cin.get();

				botHP[botInput - 1] = 0;

				break;
			}
			
			if (i != pistol[backpack[currWeapon].weaponIndex].getMagSize()) {
				cout << ammos[currWeapon] << "/" << pistol[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to shoot or Type 's' and Press 'Enter' to stop shooting!";
				getcharInput = cin.get();
			}
			else {
				cout << ammos[currWeapon] << "/" << pistol[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to go back!";
				cin.get();

				break;
			}

			if (getcharInput == 's') {
				break;
			}
			else {
				realDamage = critCalculation(pistol[backpack[currWeapon].weaponIndex].getDamage(), pistol[backpack[currWeapon].weaponIndex].getCR(), pistol[backpack[currWeapon].weaponIndex].getCD(), isCrit);
				accuracy = pistol[backpack[currWeapon].weaponIndex].getAccuracy();

				// Accuracy calculation
				distanceToPlayer = distanceCalculation(positions[0][0], positions[0][1], positions[botInput][0], positions[botInput][1]);

				if (distanceToPlayer > pistol[backpack[currWeapon].weaponIndex].getEffectiveRange())
					accuracy -= (distanceToPlayer - pistol[backpack[currWeapon].weaponIndex].getEffectiveRange()) / 2;

				if (accuracy < 0)
					accuracy = 0;

				// Miss a shot calculation
				rng = rand() % 10000;

				if (rng >= accuracy * 100)
					realDamage = 0;

				// Reduce bot HP
				botHP[botInput - 1] -= realDamage;

				if (botHP[botInput - 1] < 0)
					botHP[botInput - 1] = 0;

				ammos[currWeapon]--;
				timeElapsed += 60.0 / pistol[backpack[currWeapon].weaponIndex].getFireRate();
				statsUpdate(realDamage);
			}
		}
	}

	// Shotgun
	else if (backpack[currWeapon].weaponType == 1) {
		for (int i = 0; i <= shotgun[backpack[currWeapon].weaponIndex].getMagSize(); i++) {
			system("cls");
			arenaDisplay();
			hpDisplay();

			if (i != 0) {
				if (backpack[currWeapon].weaponType == 1)
					cout << "Pellet Hit: " << pelletHits << endl;

				if (realDamage == 0)
					cout << "You Missed!" << endl;
				else if (isCrit)
					cout << "Bot " << botInput << " Took " << realDamage << " damage! (Critical)" << endl;
				else
					cout << "Bot " << botInput << " Took " << realDamage << " damage!" << endl;
			}

			if (botHP[botInput - 1] <= 0) {
				cout << "Bot destroyed, Press 'Enter' to continue!";
				cin.get();

				botHP[botInput - 1] = 0;

				break;
			}

			if (i != shotgun[backpack[currWeapon].weaponIndex].getMagSize()) {
				cout << ammos[currWeapon] << "/" << shotgun[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to shoot or Type 's' and Press 'Enter' to stop shooting!";
				getcharInput = cin.get();
			}
			else {
				cout << ammos[currWeapon] << "/" << shotgun[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to go back!";
				cin.get();

				break;
			}

			if (getcharInput == 's') {
				break;
			}
			else {
				onePelletHeadshot = false;
				distanceToPlayer = distanceCalculation(positions[0][0], positions[0][1], positions[botInput][0], positions[botInput][1]);
				realDamage = 0;
				maxPelletHit = shotgun[backpack[currWeapon].weaponIndex].getPelletCount();
				accuracy = shotgun[backpack[currWeapon].weaponIndex].getAccuracy();

				// Max pellet hit and accuracy calculation
				if (distanceToPlayer > shotgun[backpack[currWeapon].weaponIndex].getEffectiveRange()) {
					maxPelletHit -= ((distanceToPlayer - shotgun[backpack[currWeapon].weaponIndex].getEffectiveRange()) / 2 + 1);
					accuracy -= (distanceToPlayer - shotgun[backpack[currWeapon].weaponIndex].getEffectiveRange()) / 2;

					if (maxPelletHit < 0)
						maxPelletHit = 0;

					if (accuracy < 0)
						accuracy = 0;
				}

				pelletHits = 0;

				// Damage calculation
				for (int j = 0; j < maxPelletHit; j++) {
					damageTemp = critCalculation(shotgun[backpack[currWeapon].weaponIndex].getDamage(), shotgun[backpack[currWeapon].weaponIndex].getCR(), shotgun[backpack[currWeapon].weaponIndex].getCD(), isCrit);
					rng = rand() % 10000;
					
					if (rng < accuracy * 100) {
						realDamage += damageTemp;
						pelletHits++;
					}
				}

				// Reduce bot HP
				botHP[botInput - 1] -= realDamage;

				if (botHP[botInput - 1] < 0)
					botHP[botInput - 1] = 0;

				ammos[currWeapon]--;
				timeElapsed += 60.0 / shotgun[backpack[currWeapon].weaponIndex].getFireRate();
				statsUpdate(realDamage);
			}
		}
	}

	// SMG
	else if (backpack[currWeapon].weaponType == 2) {
		for (int i = 0; i <= smg[backpack[currWeapon].weaponIndex].getMagSize(); i++) {
			system("cls");
			arenaDisplay();
			hpDisplay();

			if (i != 0) {
				if (realDamage == 0)
					cout << "You Missed!" << endl;
				else if (isCrit)
					cout << "Bot " << botInput << " Took " << realDamage << " damage! (Critical)" << endl;
				else
					cout << "Bot " << botInput << " Took " << realDamage << " damage!" << endl;
			}

			if (botHP[botInput - 1] <= 0) {
				cout << "Bot destroyed, Press 'Enter' to continue!";
				cin.get();

				botHP[botInput - 1] = 0;

				break;
			}

			if (i != smg[backpack[currWeapon].weaponIndex].getMagSize()) {
				cout << ammos[currWeapon] << "/" << smg[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to shoot or Type 's' and Press 'Enter' to stop shooting!";
				getcharInput = cin.get();
			}
			else {
				cout << ammos[currWeapon] << "/" << smg[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to go back!";
				cin.get();

				break;
			}

			if (getcharInput == 's') {
				break;
			}
			else {
				realDamage = critCalculation(smg[backpack[currWeapon].weaponIndex].getDamage(), smg[backpack[currWeapon].weaponIndex].getCR(), smg[backpack[currWeapon].weaponIndex].getCD(), isCrit);
				accuracy = smg[backpack[currWeapon].weaponIndex].getAccuracy();

				// Accuracy calculation
				distanceToPlayer = distanceCalculation(positions[0][0], positions[0][1], positions[botInput][0], positions[botInput][1]);

				if (distanceToPlayer > smg[backpack[currWeapon].weaponIndex].getEffectiveRange())
					accuracy -= (distanceToPlayer - smg[backpack[currWeapon].weaponIndex].getEffectiveRange()) / 2;

				if (accuracy < 0)
					accuracy = 0;

				// Miss a shot calculation
				rng = rand() % 10000;

				if (rng >= accuracy * 100)
					realDamage = 0;

				// Reduce bot HP
				botHP[botInput - 1] -= realDamage;

				if (botHP[botInput - 1] < 0)
					botHP[botInput - 1] = 0;

				ammos[currWeapon]--;
				timeElapsed += 60.0 / smg[backpack[currWeapon].weaponIndex].getFireRate();
				statsUpdate(realDamage);
			}
		}
	}

	// AR
	else if (backpack[currWeapon].weaponType == 3) {
		for (int i = 0; i <= ar[backpack[currWeapon].weaponIndex].getMagSize(); i++) {
			system("cls");
			arenaDisplay();
			hpDisplay();

			if (i != 0) {
				if (realDamage == 0)
					cout << "You Missed!" << endl;
				else if (isCrit)
					cout << "Bot " << botInput << " Took " << realDamage << " damage! (Critical)" << endl;
				else
					cout << "Bot " << botInput << " Took " << realDamage << " damage!" << endl;
			}

			if (botHP[botInput - 1] <= 0) {
				cout << "Bot destroyed, Press 'Enter' to continue!";
				cin.get();

				botHP[botInput - 1] = 0;

				break;
			}

			if (i != ar[backpack[currWeapon].weaponIndex].getMagSize()) {
				cout << ammos[currWeapon] << "/" << ar[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to shoot or Type 's' and Press 'Enter' to stop shooting!";
				getcharInput = cin.get();
			}
			else {
				cout << ammos[currWeapon] << "/" << ar[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to go back!";
				cin.get();

				break;
			}

			if (getcharInput == 's') {
				break;
			}
			else {
				realDamage = critCalculation(ar[backpack[currWeapon].weaponIndex].getDamage(), ar[backpack[currWeapon].weaponIndex].getCR(), ar[backpack[currWeapon].weaponIndex].getCD(), isCrit);
				accuracy = ar[backpack[currWeapon].weaponIndex].getAccuracy();

				// Accuracy calculation
				distanceToPlayer = distanceCalculation(positions[0][0], positions[0][1], positions[botInput][0], positions[botInput][1]);

				if (distanceToPlayer > ar[backpack[currWeapon].weaponIndex].getEffectiveRange())
					accuracy -= (distanceToPlayer - ar[backpack[currWeapon].weaponIndex].getEffectiveRange()) / 2;

				if (accuracy < 0)
					accuracy = 0;

				// Miss a shot calculation
				rng = rand() % 10000;

				if (rng >= accuracy * 100)
					realDamage = 0;

				// Reduce bot HP
				botHP[botInput - 1] -= realDamage;

				if (botHP[botInput - 1] < 0)
					botHP[botInput - 1] = 0;

				ammos[currWeapon]--;
				timeElapsed += 60.0 / ar[backpack[currWeapon].weaponIndex].getFireRate();
				statsUpdate(realDamage);
			}
		}
	}

	// Sniper
	else if (backpack[currWeapon].weaponType == 4) {
		for (int i = 0; i <= sniper[backpack[currWeapon].weaponIndex].getMagSize(); i++) {
			system("cls");
			arenaDisplay();
			hpDisplay();

			if (i != 0) {
				if (realDamage == 0)
					cout << "You Missed!" << endl;
				else if (isCrit)
					cout << "Bot " << botInput << " Took " << realDamage << " damage! (Critical)" << endl;
				else
					cout << "Bot " << botInput << " Took " << realDamage << " damage!" << endl;
			}

			if (botHP[botInput - 1] <= 0) {
				cout << "Bot destroyed, Press 'Enter' to continue!";
				cin.get();

				botHP[botInput - 1] = 0;

				break;
			}

			if (i != sniper[backpack[currWeapon].weaponIndex].getMagSize()) {
				cout << ammos[currWeapon] << "/" << sniper[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to shoot or Type 's' and Press 'Enter' to stop shooting!";
				getcharInput = cin.get();
			}
			else {
				cout << ammos[currWeapon] << "/" << sniper[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to go back!";
				cin.get();

				break;
			}

			if (getcharInput == 's') {
				break;
			}
			else {
				realDamage = critCalculation(sniper[backpack[currWeapon].weaponIndex].getDamage(), sniper[backpack[currWeapon].weaponIndex].getCR(), sniper[backpack[currWeapon].weaponIndex].getCD(), isCrit);
				accuracy = sniper[backpack[currWeapon].weaponIndex].getAccuracy();

				// Miss a shot calculation
				rng = rand() % 10000;

				if (rng >= accuracy * 100)
					realDamage = 0;

				// Reduce bot HP
				botHP[botInput - 1] -= realDamage;

				if (botHP[botInput - 1] < 0)
					botHP[botInput - 1] = 0;

				ammos[currWeapon]--;
				timeElapsed += 60.0 / sniper[backpack[currWeapon].weaponIndex].getFireRate();
				statsUpdate(realDamage);
			}
		}
	}

	// MG
	else if (backpack[currWeapon].weaponType == 5) {
		for (int i = 0; i <= mg[backpack[currWeapon].weaponIndex].getMagSize(); i++) {
			system("cls");
			arenaDisplay();
			hpDisplay();

			if (i != 0) {
				if (realDamage == 0)
					cout << "You Missed!" << endl;
				else if (isCrit)
					cout << "Bot " << botInput << " Took " << realDamage << " damage! (Critical)" << endl;
				else
					cout << "Bot " << botInput << " Took " << realDamage << " damage!" << endl;
			}

			if (botHP[botInput - 1] <= 0) {
				cout << "Bot destroyed, Press 'Enter' to continue!";
				cin.get();

				botHP[botInput - 1] = 0;

				break;
			}

			if (i != mg[backpack[currWeapon].weaponIndex].getMagSize()) {
				cout << ammos[currWeapon] << "/" << mg[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to shoot or Type 's' and Press 'Enter' to stop shooting!";
				getcharInput = cin.get();
			}
			else {
				cout << ammos[currWeapon] << "/" << mg[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to go back!";
				cin.get();

				break;
			}

			if (getcharInput == 's') {
				break;
			}
			else {
				realDamage = critCalculation(mg[backpack[currWeapon].weaponIndex].getDamage(), mg[backpack[currWeapon].weaponIndex].getCR(), mg[backpack[currWeapon].weaponIndex].getCD(), isCrit);
				accuracy = mg[backpack[currWeapon].weaponIndex].getAccuracy();

				// Accuracy calculation
				distanceToPlayer = distanceCalculation(positions[0][0], positions[0][1], positions[botInput][0], positions[botInput][1]);

				if (distanceToPlayer > mg[backpack[currWeapon].weaponIndex].getEffectiveRange())
					accuracy -= (distanceToPlayer - mg[backpack[currWeapon].weaponIndex].getEffectiveRange()) / 2;

				if (i * mg[backpack[currWeapon].weaponIndex].getRecoilGain() < mg[backpack[currWeapon].weaponIndex].getMaxRecoil())
					accuracy -= i * mg[backpack[currWeapon].weaponIndex].getRecoilGain();
				else
					accuracy -= mg[backpack[currWeapon].weaponIndex].getMaxRecoil();

				if (accuracy < 0)
					accuracy = 0;

				// Miss a shot calculation
				rng = rand() % 10000;

				if (rng >= accuracy * 100)
					realDamage = 0;

				// Reduce bot HP
				botHP[botInput - 1] -= realDamage;

				if (botHP[botInput - 1] < 0)
					botHP[botInput - 1] = 0;

				ammos[currWeapon]--;
				timeElapsed += 60.0 / mg[backpack[currWeapon].weaponIndex].getFireRate();
				statsUpdate(realDamage);
			}
		}
	}

	// Explosive
	else if (backpack[currWeapon].weaponType == 6) {
		for (int i = 0; i <= explosive[backpack[currWeapon].weaponIndex].getMagSize(); i++) {
			system("cls");
			arenaDisplay();
			hpDisplay();

			if (i != 0) {
				if (realDamage == 0 || hitted == 0) {
					cout << "You Missed!" << endl;
				}
				else {
					for (int j = 0; j < robots; j++) {
						if (isCrit && isHit[j] && !isDead[j])
							cout << "Bot " << j + 1 << " Took " << realDamage << " damage! (Critical)" << endl;
						else if (isHit[j] && !isDead[j])
							cout << "Bot " << j + 1 << " Took " << realDamage << " damage!" << endl;

						if (botHP[j] == 0)
							isDead[j] = true;
					}
				}
			}

			if (i != explosive[backpack[currWeapon].weaponIndex].getMagSize()) {
				cout << ammos[currWeapon] << "/" << explosive[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to shoot or Type 's' and Press 'Enter' to stop shooting!";
				getcharInput = cin.get();
			}
			else {
				cout << ammos[currWeapon] << "/" << explosive[backpack[currWeapon].weaponIndex].getMagSize() << endl;
				cout << "Press 'Enter' to go back!";
				cin.get();

				break;
			}

			if (getcharInput == 's') {
				break;
			}
			else {
				realDamage = critCalculation(explosive[backpack[currWeapon].weaponIndex].getDamage(), explosive[backpack[currWeapon].weaponIndex].getCR(), explosive[backpack[currWeapon].weaponIndex].getCD(), isCrit);
				accuracy = explosive[backpack[currWeapon].weaponIndex].getAccuracy();

				// Miss a shot calculation
				rng = rand() % 10000;
				
				if (rng >= accuracy * 100)
					realDamage = 0;
				
				// Area damage calculation
				if (realDamage != 0) {
					hitted = 0;

					for (int j = 0; j < robots; j++) {
						distanceBetweenBots = distanceCalculation(positions[j + 1][0], positions[j + 1][1], (int)(9 - (areaInput[1] - '0')), (int)(tolower(areaInput[0]) - 'a'));

						if (distanceBetweenBots <= explosive[backpack[currWeapon].weaponIndex].getExplosiveRadius()) {
							botHP[j] -= realDamage;

							if (botHP[j] < 0)
								botHP[j] = 0;

							isHit[j] = true;
							hitted++;
						}
						else {
							isHit[j] = false;
						}
					}
				}

				// Post-fire
				ammos[currWeapon]--;
				timeElapsed += 60.0 / explosive[backpack[currWeapon].weaponIndex].getFireRate();
				statsUpdate(realDamage);
			}
		}
	}

	// Melee
	else if (backpack[currWeapon].weaponType == 7) {
		for (int i = 0; true; i++) {
			system("cls");
			arenaDisplay();
			hpDisplay();

			if (i != 0) {
				if (realDamage == 0)
					cout << "You Missed!" << endl;
				else if (isCrit)
					cout << "Bot " << botInput << " Took " << realDamage << " damage! (Critical)" << endl;
				else
					cout << "Bot " << botInput << " Took " << realDamage << " damage!" << endl;
			}

			if (botHP[botInput - 1] <= 0) {
				cout << "Bot destroyed, Press 'Enter' to continue!";
				cin.get();

				botHP[botInput - 1] = 0;

				break;
			}

			cout << static_cast<unsigned char>(236) << "/" << static_cast<unsigned char>(236) << endl;
			cout << "Press 'Enter' to strike or Type 's' and Press 'Enter' to stop striking!";
			getcharInput = cin.get();

			if (getcharInput == 's') {
				break;
			}
			else {
				realDamage = critCalculation(melee[backpack[currWeapon].weaponIndex].getDamage(), melee[backpack[currWeapon].weaponIndex].getCR(), melee[backpack[currWeapon].weaponIndex].getCD(), isCrit);
				accuracy = melee[backpack[currWeapon].weaponIndex].getAccuracy();

				// Miss a shot calculation
				rng = rand() % 10000;

				if (rng >= accuracy * 100)
					realDamage = 0;
				
				// Checks if you are out of range
				distanceToPlayer = distanceCalculation(positions[0][0], positions[0][1], positions[botInput][0], positions[botInput][1]);

				if (distanceToPlayer > melee[backpack[currWeapon].weaponIndex].getMaxRange())
					realDamage = 0;

				// Reduce bot HP
				botHP[botInput - 1] -= realDamage;

				if (botHP[botInput - 1] < 0)
					botHP[botInput - 1] = 0;

				timeElapsed += 60.0 / melee[backpack[currWeapon].weaponIndex].getAtkSpeed();
				statsUpdate(realDamage);
			}
		}
	}
}

void Battlefield::move() {
	int x, y;
	int temp[2] = { positions[0][0] , positions[0][1] };

	string placeInput;

	arena[positions[0][0]][positions[0][1]] = -1;

	do
	{
		system("cls");

		arena[positions[0][0]][positions[0][1]] = 0;
		arenaDisplay();

		cout << "Pick a spot: ";
		cin >> placeInput;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		arena[positions[0][0]][positions[0][1]] = -1;
	}
	while (!putObject(placeInput, 0));

	timeElapsed += distanceCalculation(temp[0], temp[1], positions[0][0], positions[0][1]) / 5;
}

void Battlefield::reload() {
	if (backpack[currWeapon].weaponType == 7) {
		cout << "Weapon can't be reloaded!";
		cin.get();
	}
	else if (ammos[currWeapon] == magSizes[currWeapon]) {
		cout << "Weapon already reloaded!";
		cin.get();
	}
	else {
		ammos[currWeapon] = magSizes[currWeapon];

		if (backpack[currWeapon].weaponType == 0)
			timeElapsed += pistol[backpack[currWeapon].weaponIndex].getReloadSpeed();
		else if (backpack[currWeapon].weaponType == 1)
			timeElapsed += shotgun[backpack[currWeapon].weaponIndex].getReloadSpeed();
		else if (backpack[currWeapon].weaponType == 2)
			timeElapsed += smg[backpack[currWeapon].weaponIndex].getReloadSpeed();
		else if (backpack[currWeapon].weaponType == 3)
			timeElapsed += ar[backpack[currWeapon].weaponIndex].getReloadSpeed();
		else if (backpack[currWeapon].weaponType == 4)
			timeElapsed += sniper[backpack[currWeapon].weaponIndex].getReloadSpeed();
		else if (backpack[currWeapon].weaponType == 5)
			timeElapsed += mg[backpack[currWeapon].weaponIndex].getReloadSpeed();
		else if (backpack[currWeapon].weaponType == 6)
			timeElapsed += explosive[backpack[currWeapon].weaponIndex].getReloadSpeed();
	}
}

void Battlefield::changeWeapon() {
	cout << "Choose slot: ";
	cin >> temp;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (temp < 1 || temp > 4) {
		cout << "Invalid Input!";
		cin.get();
	}
	else if (temp - 1 == currWeapon) {
		cout << "You can't choose the same weapon!";
		cin.get();
	}
	else if (temp > weapons) {
		cout << "Slot is empty!";
		cin.get();
	}
	else {
		currWeapon = temp - 1;
		timeElapsed += 1.0;
	}
}

void Battlefield::statsDisplayOnBattlefield(int displayType) {
	functions.detailsDisplay(backpack[currWeapon].name, backpack[currWeapon].weaponType + 1, displayType, pistol, shotgun, smg, ar, sniper, mg, explosive, melee);
}

bool Battlefield::putObject(string coordinate, int object) {
	int x, y;
	
	// Case where input is invalid
	if (!gridInputCheck(coordinate)) {
		cout << "Invalid Input!";
		cin.get();

		return false;
	}

	x = tolower(coordinate[0]) - 'a';
	y = 9 - coordinate[1] + '0';
	
	// Case when inputted space is occupied
	if (arena[y][x] != -1) {
		cout << "Space occupied!";
		cin.get();

		return false;
	}
	
	arena[y][x] = object;
	positions[object][0] = y;
	positions[object][1] = x;

	return true;
}

void Battlefield::updateWeaponData() {
	functions.fileRead(pistol, shotgun, smg, ar, sniper, mg, explosive, melee, counts[0], counts[1], counts[2], counts[3], counts[4], counts[5], counts[6], counts[7], counts[8]);
}

float Battlefield::distanceCalculation(int xPlayer, int yPlayer, int xBot, int yBot) {
	return sqrt(pow(abs(xPlayer * 5 - xBot * 5), 2) + pow(abs(yPlayer * 5 - yBot * 5), 2));
}

int Battlefield::critCalculation(float damage, float critRate, float critDamage, bool& isCrit) {
	int rng = rand() % 10000;

	if (critRate > 100 || rng < critRate * 100) {
		isCrit = true;

		return damage + (damage * critDamage / 100);
	}
	else {
		isCrit = false;

		return damage;
	}
}

bool Battlefield::checkAllDeath() {
	for (int i = 0; i < robots; i++) {
		if (botHP[i] > 0)
			return false;
	}

	return true;
}

bool Battlefield::gridInputCheck(string coordinate) {
	if (coordinate.length() != 2 || !isdigit(coordinate[1]) || !isalpha(coordinate[0]) || tolower(coordinate[0]) > 'j')
		return false;
	else
		return true;
}

void Battlefield::statsUpdate(int damage) {
	totalDmg += damage;
	attacks++;

	if (damage > highestDmg)
		highestDmg = damage;
}

void Battlefield::statsDisplay() {
	system("cls");
	arenaDisplay();

	cout << "Time Elapsed: " << format("{0:.1f}", timeElapsed) << "s" << endl;
	cout << "Total Damage: " << totalDmg << endl;
	cout << "Highest Damage: " << highestDmg << endl;
	cout << "Attack Count: " << attacks << endl << endl;

	cout << "Press 'Enter' to continue: ";
	cin.get();
}