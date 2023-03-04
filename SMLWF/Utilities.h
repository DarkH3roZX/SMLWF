#define NOMINMAX
#include <iostream>
#include <string>
#include <fstream>
#include <format>
#include <vector>
#include <windows.h>
using namespace std;

#ifndef Utilities_H
#define Utilities_H

class Utilities {
	private:
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	public:
		void logo();

		void subtitile(string title);

		void tableHeaderDisplay();
};

#endif