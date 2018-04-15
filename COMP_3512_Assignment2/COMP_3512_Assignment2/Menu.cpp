#include "Menu.hpp"
#include "Patient.hpp"
#include <string>
#include <sstream>
Menu::Menu() {
	this->generateMainMenu();
	this->generateSubMenus();
	this->printMainMenu();
}

bool Menu::pickMainMenu(char selected) {
	if (selected == 'a') {
		Patient currentPatient = Patient();
		for (int i = 0; i < menuSelection[SUB_MENUA_INDEX].size(); i++) {
			bool repeat = true; 
			std::string value;
			while (repeat) {
				std::cout << menuSelection[SUB_MENUA_INDEX].at(i) << std::endl;
				std::cin >> value;
				try {
					if (i == LAST_NAME_INDEX) {
						currentPatient.getName().setLastName(value);
						repeat = false;
					}
					else if (i == FIRST_NAME_INDEX) {
						currentPatient.getName().setFirstName(value);
						repeat = false;
					}
					else if (i == MIDDLE_NAME_IDNEX) {
						currentPatient.getName().setMiddleName(value);
						repeat = false;
					}
					else if (i == YEAR_INDEX) {
						try {
							currentPatient.getBirthday().setYearOfBirth(stringToInt(value));
						}
						catch (const char* msg) {
							repeat = true;
						}
					}
					else if (i == MONTH_INDEX) {
						currentPatient.getBirthday().setMonthOfBirth(stringToInt(value));
						repeat = false;
					}
					else if (i == DAY_INDEX) {
						currentPatient.getBirthday().setDayOfBirth(stringToInt(value));
						repeat = false;
					}
					else if (i == CARE_NUMBER_INDEX) {
						repeat = false;
					}
					else if (i == TIME_INDEX) {
						//currentPatient.getTimeAdmitted().setDefaultTime();
						repeat = false;
					}
					else if (i == CATEGORY_INDEX) {
						repeat = false;
					}
					
				}
				catch (std::exception& e) {
					std::cout << "ERROR- " << e.what() << std::endl;
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
		//terminate program
		std::exit(0);
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

int Menu::stringToInt(std::string myStr) {
	int inteVal;
	std::istringstream buffer(myStr);
	buffer >> inteVal;
	if (inteVal < 0) {
		throw "Invalid birthday exception";
	}
	return inteVal;
}




