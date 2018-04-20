#include "Menu.hpp"
#include "Patient.hpp"
#include <string>
#include <sstream>

/* Menu Default constructor - creates all our initial display menus
*/
Menu::Menu() {
	//generate all our menus
	this->generateMainMenu();
	this->generateSubMenus();
	this->generateCriticalMenu();
	this->printMainMenu();
}

/*Menu::pickMainMenu(char selected) - display the menu user has selected
Input:
char selected - the char the user has selected from console
Output:
bool - completed menu boolean
*/
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
		changePatientCategoryMenu();
	}
	else if (selected == '4') {
		//save 
		readwriter.writePatientList(myPatients);
	}
	else if (selected == '5') {
		//load
		readwriter.loadPatientList(myPatients);
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

/*Menu::menuSelectionA() - The add patient menu
Input:
N/A
Output:
void
*/
void Menu::menuSelectionA() {
	//create a new patient
	Patient currentPatient;
	//get all the data for a patient from the user
	for (int i = 0; i < menuSelection[SUB_MENUA_INDEX].size(); i++) {
		bool repeat = true;
		std::string value;
		//loop until we have our valid data
		while (repeat) {
			repeat = false;
			//print out prompt
			std::cout << menuSelection[SUB_MENUA_INDEX].at(i) << std::endl;
			std::cin >> value;

			//get the data and set it to the patient
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
				//attempt to set the birthday to see if data is valid
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
				//attempt to set the month to see if an error is thrown
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
				//attempt to set set the date to see if an error is thrown
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
				//attempt to set the care card number to see if an error is thrown
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
				//attempt to set a time to see if an error is thrown
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
					std::cerr << "Error invalid time! Please enter in format 00:00 greater than the current time" << std::endl;
				}
			}
			else if (i == SYMPTOM_INDEX) {
				//get the patient's symptom 
				printCriticalMenu();
				currentPatient.setMainSymptoms(value);
			}
			else if (i == CATEGORY_INDEX) {
				try {
					int potentialCategoryID = stringToInt(value);
					if (potentialCategoryID < MIN_CATEGORY_ID || potentialCategoryID > MAX_CATEGORY_ID) {
						throw "invalid category id, please enter an id between 1-6";
					}
					currentPatient.setCategoryNumber(potentialCategoryID);
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
	//add a new patient 
	myPatients.addPatient(currentPatient);
	//see if anyone deserves a promotion
	myPatients.promoteQueue();
}

/*
Menu::changePatientCategoryMenu() - used for changing the patient's priority if their condition worsens
Input:
N/A
Output:
Void
*/
void Menu::changePatientCategoryMenu() {
	bool repeat = true;
	std::string value;
	//repeat until we've updated a patient
	while (repeat) {
		try {
			//prompt user for health care
			std::cout << "Please enter health care number of patient you wish to change " << std::endl;
			std::cin >> value;
			checkValidHealthCare(value);
			std::string currentHealthNumber = value;
			int currentPatientCategory = myPatients.getPatientCategory(value);

			//check if the patient is actually in the list
			if (currentPatientCategory == -1) {
				std::cout << std::endl << "patient with id " << value << " not found! " << std::endl  << std::endl;
				return;
			}
			//output the patient's current condition 
			std::cout << "=====Patient Health # " << value << "============" << std::endl;
			std::cout << "Current patient condition: " << critMenu.at(currentPatientCategory - 1) << std::endl;
			std::cout << "===========================================" << std::endl << std::endl;

			//update the patient's category
			try {
				std::cout << "=================================================" << std::endl;
				printCriticalMenu();
				std::cout << "Please enter new patient category " << std::endl;
				std::cin >> value;
				int potentialCategoryID = stringToInt(value);
				if (potentialCategoryID < MIN_CATEGORY_ID || potentialCategoryID > MAX_CATEGORY_ID) {
					throw "invalid category id, please enter an id between 1-6";
				}
				myPatients.setCategoryID(potentialCategoryID, currentHealthNumber);
				std::cout << "Successfully changed patient category to  " << potentialCategoryID << std::endl;
				repeat = false;
			}
			catch (const std::string& ex) {
				repeat = true;
				std::cout << ex << std::endl;

			}
			catch (...)
			{
				repeat = true;
				std::cerr << "Error invalid category ID, please try again" << std::endl;
			}
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
}

/*  Menu::printMainMenu() - print's the main menu for the user 
Input: 
N/A
Output:
void
*/
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

/*
Menu::generateMainMenu() - Creates the main menu text
Input:
N/A
Output:
void
*/
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

/*Menu::generateSubMenus() - generates the submenus 
Input:
N/A
Output:
void
*/
void Menu::generateSubMenus() {
	this->generateSubMenuA();
}

/* Menu::generateSubMenuA() - Generates the prompts for adding a patient
Input:
N/A
Output:
void
*/
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

/* Menu::generateCriticalMenu()  - Generates the critical condition level menu
Input:
N/A
Output:
void
*/
void Menu::generateCriticalMenu() {
	critMenu.push_back("(1) Critical and life-threatening, requires immediate care");
	critMenu.push_back("(2) Critical, requires care very soon");
	critMenu.push_back("(3) Serious, requires care soon");
	critMenu.push_back("(4) Serious");
	critMenu.push_back("(5) Non-serious");
	critMenu.push_back("(6) Not a priority");
}

/* Menu::printCriticalMenu() - Outputs the critical condition menu to console
Input:
N/A
Output:
void
*/
void Menu::printCriticalMenu() {
	for (int i = 0; i < critMenu.size(); i++) {
		std::cout << critMenu.at(i) << std::endl;
	}
}

/* Menu::stringToInt(std::string myStr) - converts a string value to an integer if it's an integer
Input:
std::string myStr - the input string we're converting
Output:
void
integer - The converted integer from string
*/
int Menu::stringToInt(std::string myStr) {
	int inteVal;
	//pass through buffer to convert to int
	std::istringstream buffer(myStr);
	buffer >> inteVal;
	//when it's not a number
	if (inteVal < 0) {
		throw "Invalid (integer) number exception";
	}
	return inteVal;
}

/* Menu::checkValidHealthCare(std::string healthcareNumber) - checks if a string is a valid health care number 
Input:
std::string healthcareNumber - string format potential healthcare number
Output:
void
*/
void Menu::checkValidHealthCare(std::string healthcareNumber) {
	//check length and check if the healthcare number is all numbers
	if (healthcareNumber.length() == 8) {
		if (is_digits(healthcareNumber)) {
			return;
		}
		else {
			throw "Invalid health care number, please enter all digits with length 8";
		}
	}
	else {
		throw "Invalid health care number, please enter all digits with length 8";
	}
}

/* is_digits(const std::string &str) - checks if a string is an integer number
Input:
const std::string &str - the string we're passing in to check if it's a number
Output:
bool - if it's a number or not 
*/
bool Menu::is_digits(const std::string &str)
{
	return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}




