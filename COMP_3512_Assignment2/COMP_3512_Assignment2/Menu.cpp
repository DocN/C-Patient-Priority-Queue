#include "Menu.hpp"
#include "Patient.hpp"
#include <string>

Menu::Menu() {
	this->generateMainMenu();
	this->generateSubMenus();
	this->printMainMenu();
}

bool Menu::pickMainMenu(char selected) {
	if (selected == 'a') {
		for (int i = 0; i < menuSelection[0].size(); i++) {
			Patient currentPatient = Patient();
			bool repeat = true; 
			std::string value;
			while (repeat) {
				std::cout << menuSelection[0].at(i) << std::endl;
				std::cin >> value;
				try {
					repeat = false;
				}
				catch (std::exception &e) {
					std::cout << "ERROR- " + e.what() << std::endl;
					repeat = true;
				}
				
			}
			
		}
	}
	else if (selected == 'b') {

	}
	else if (selected == 'c') {

	}
	else if (selected == 'd') {

	}
	else if (selected == 'e') {

	}
	else if (selected == 'f') {

	}
	else if (selected == 'g') {

	}
	else {
		return false;
	}

}

void Menu::printMainMenu() {
	char value;
	bool repeater = true;

	while (repeater) {
		//print menu 
		for (const std::string& str : mainMenu) {
			std::cout << str << std::endl;
		}
		//get user input
		std::cin >> value;
		value = tolower(value);
		if (!pickMainMenu(value)) {
			std::cout << "-------------------------------" << std::endl;
			std::cout << "invalid character, please try again" << std::endl;
			std::cout << "-------------------------------" << std::endl;
		}
	}
}

void Menu::generateMainMenu() {
	mainMenu.push_back("(a). Add new patient");
	mainMenu.push_back("(b). Get next patient");
	mainMenu.push_back("(c). Change patient category");
	mainMenu.push_back("(d). Save patient list");
	mainMenu.push_back("(e). Load patient list");
	mainMenu.push_back("(f). Print patient list");
	mainMenu.push_back("(g). Exit program");
}

void Menu::generateSubMenus() {
	this->generateSubMenuA();
}

void Menu::generateSubMenuA() {
	std::vector<std::string> menuA;
	menuA.push_back("Enter Last Name");
	menuA.push_back("Enter First Name");
	menuA.push_back("Enter Middle Name");
	menuA.push_back("Enter Year of Birth");
	menuA.push_back("Enter Month of Birth");
	menuA.push_back("Enter Day of Birth");
	menuA.push_back("Enter Personal Healthcare Number");
	menuA.push_back("Enter Time Admitted in Format 24:00");
	menuA.push_back("Enter Main symptoms(s)");
	menuA.push_back("Enter Category number");
	menuSelection.push_back(menuA);
}

void Menu::generateSubMenuB() {

}




