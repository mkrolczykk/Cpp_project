// jipp_mk_projekt.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "Vector.h"
#include "VectorFile.h"
#include "MessagingService.h"
#include "Interface.h"

using namespace std;

int main() {
	MessagingService logger;
	Interface userInterface;
	int choice = -1;
	
	while(userInterface.isRunning()) {
		userInterface.showMenu();
		cin >> choice;

		if (cin.fail()) logger.message(WARN_MENU_WRONG_CHOICE);

		switch (choice) {
			case 0:
				userInterface.push();
				break;
			case 1:
				userInterface.pop();
				break;
			case 2:
				userInterface.erase();
				break;
			case 3:
				userInterface.clear();
				break;
			case 4:
				userInterface.modify();
				break;
			case 5:
				userInterface.insert();
				break;
			case 6:
				userInterface.findObjects();
				break;
			case 7:
				userInterface.save();
				break;
			case 8:
				userInterface.load();
				break;
			case 9:
				userInterface.display();
				break;
			case 10:
				userInterface.finish();
				break;
			default:
				userInterface.wrongChoice();
				break;
		}
	}

	return 0;
}
