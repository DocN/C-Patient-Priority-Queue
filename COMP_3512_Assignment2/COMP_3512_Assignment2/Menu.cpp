#include "Menu.hpp"
#include "Patient.hpp"
#include <string>
#include <sstream>

Menu::Menu() {
	this->generateMainMenu();
	this->generateSubMenus();
	this->generateCriticalMenu();
	this->printMainMenu();

}

bool Menu::pickMainMenu(char selected) {
	if (selected == '1') {
		//add new patient
		menuSelectionA();
	}
	else if (selected == '2') {
		//get next patient
		myPatients.getNextPatient();
	}
	else if (selected == '3') {
		//change patient category
	}
	else if (selected == '4') {
		//save 
	}
	else if (selected == '5') {
		//load
	}
	else if (selected == '6') {
		//print patients
		myPatients.printPatients();
	}
	else if (selected == '7') {
		//terminate program
		std::exit(0);
	}
	else {
		return false;
	}
	return true;
}

void Menu::menuSelectionA() {
	Patient currentPatient;
	for (int i = 0; i < menuSelection[SUB_MENUA_INDEX].size(); i++) {
		bool repeat = true;
		std::string value;
		while (repeat) {
			repeat = false;
			std::cout << menuSelection[SUB_MENUA_INDEX].at(i) << std::endl;
			std::cin >> value;
			if (i == LAST_NAME_INDEX) {
				currentPatient.getName().setLastName(value);
			}
			else if (i == FIRST_NAME_INDEX) {
				currentPatient.getName().setFirstName(value);
			}
			else if (i == MIDDLE_NAME_IDNEX) {
				currentPatient.getName().setMiddleName(value);
			}
			else if (i == YEAR_INDEX) {
				try {
					currentPatient.getBirthday().setYearOfBirth(stringToInt(value));
				}
				catch (const std::string& ex) {
					repeat = true;
					std::cout << ex << std::endl;

				}
				catch (...)
				{
					repeat = true;
					std::cerr << "Error invalid year please enter a year between 1850 and 2018" << std::endl;
				}
			}
			else if (i == MONTH_INDEX) {
				try {
					currentPatient.getBirthday().setMonthOfBirth(stringToInt(value));
				}
				catch (const std::string& ex) {
					repeat = true;
					std::cout << ex << std::endl;
				}
				catch (...)
				{
					repeat = true;
					std::cerr << "Error invalid month! please enter a month between 1 and 12" << std::endl;
				}
			}
			else if (i == DAY_INDEX) {
				try {
					currentPatient.getBirthday().setDayOfBirth(stringToInt(value));
				}
				catch (const std::string& ex) {
					repeat = true;
					std::cout << ex << std::endl;
				}
				catch (...)
				{
					std::cerr << "Error invalid day! please enter a day between 1 and 31" << std::endl;
				}
			}
			else if (i == CARE_NUMBER_INDEX) {
				try {
					currentPatient.setHealthCareNumber(value);
				}
				catch (const std::string& ex) {
					repeat = true;
					std::cout << ex << std::endl;

				}
				catch (...)
				{
					repeat = true;
					std::cerr << "Error invalid health card number! please enter an 8 digit card number" << std::endl;
				}
			}
			else if (i == TIME_INDEX) {
				try {
					currentPatient.getTimeAdmitted().set24Time(value);
					if (!myPatients.compareTime(currentPatient.getTimeAdmitted())) {
						throw "Time must be greater or equal to the previous patient's admitted time";
					}
				}
				catch (const std::string& ex) {
					repeat = true;
					std::cout << ex << std::endl;
				}
				catch (...)
				{
					repeat = true;
					std::cerr << "Error invalid time! Please enter in format 00:00" << std::endl;
				}
			}
			else if (i == SYMPTOM_INDEX) {
				this->printCriticalMenu();
				currentPatient.setMainSymptoms(value);
			}
			else if (i == CATEGORY_INDEX) {
				try {
					currentPatient.setCategoryNumber(stringToInt(value));
				}
				catch (const std::string& ex) {
					repeat = true;
					std::cout << ex << std::endl;
				}
				catch (...)
				{
					repeat = true;
					std::cerr << "Error category number! Please enter a category between 1-6" << std::endl;
				}
			}
		}
	}
	myPatients.addPatient(currentPatient);
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
	mainMenu.push_back("============== Main menu ==============");
	mainMenu.push_back("(1). Add new patient");
	mainMenu.push_back("(2). Get next patient");
	mainMenu.push_back("(3). Change patient category");
	mainMenu.push_back("(4). Save patient list");
	mainMenu.push_back("(5). Load patient list");
	mainMenu.push_back("(6). Print patient list");
	mainMenu.push_back("(7). Exit program");
	mainMenu.push_back("=======================================");
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
	menuA.push_back("Enter Time Admitted in Format 24 hour 00:00");
	menuA.push_back("Enter Main symptoms(s)");
	menuA.push_back("Enter Category number");
	menuSelection.push_back(menuA);
}

void Menu::generateCriticalMenu() {
	critMenu.push_back("(1) Critical and life-threatening, requires immediate care");
	critMenu.push_back("(2) Critical, requires care very soon");
	critMenu.push_back("(3) Serious, requires care soon");
	critMenu.push_back("(4) Serious");
	critMenu.push_back("(5) Non-serious");
	critMenu.push_back("(6) Not a priority");
}

void Menu::printCriticalMenu() {
	for (int i = 0; i < critMenu.size(); i++) {
		std::cout << critMenu.at(i) << std::endl;
	}
}
void Menu::generateSubMenuB() {

}

int Menu::stringToInt(std::string myStr) {
	int inteVal;
	std::istringstream buffer(myStr);
	buffer >> inteVal;
	if (inteVal < 0) {
		throw "Invalid (integer) number exception";
	}
	return inteVal;
}




