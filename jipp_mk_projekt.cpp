// jipp_mk_projekt.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "Vector.h"
#include "VectorFile.h"
#include "MessagingService.h"
#include "Interface.h"

using namespace std;

int main() {
	Interface userInterface;
	
	while(userInterface.isRunning()) {
		userInterface.showMenu();
		cin >> userInterface;
	}

	return 0;
}
