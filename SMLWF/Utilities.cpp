#include "Utilities.h"

void Utilities::logo() {
	system("cls");

	SetConsoleTextAttribute(h, 4);
	cout << " ===== ==  == =     =          = =====   " << endl;
	cout << " |     |\\  /| |     |          | |      " << endl;
	cout << " ===== | \\/ | |     |    /\\    | ===== " << endl;
	cout << "     | |    | |      \\  /  \\  /  |     " << endl;
	cout << " ===== =    = =====   \\/    \\/   |     " << endl;

	SetConsoleTextAttribute(h, 6);
	cout << "=======================================  " << "\n\n\n";

	SetConsoleTextAttribute(h, 15);
}

void Utilities::subtitile(string title) {
	cout << " " << title << " " << endl;

	for (int i = 0; i < title.length() + 2; i++)
		cout << "=";
	
	cout << "\n\n";
}

void Utilities::tableHeaderDisplay() {
	cout << format("{0:<3} | {1:<20} | {2:<6} | {3:<7} | {4:<9} | {5:<9} \n", "Num", "Name", "DMG", "ACC", "CRIT Rate", "CRIT DMG");
	cout << "======================================================================\n";
}