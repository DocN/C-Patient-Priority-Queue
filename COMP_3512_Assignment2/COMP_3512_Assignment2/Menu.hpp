#pragma once
#include <iostream>
#include <string>
#include <vector>

class Menu {
private:
	std::vector<std::string> mainMenu;
	std::vector<std::string> critMenu;
	std::vector<std::vector<std::string>> menuSelection;
	int const SUB_MENUA_INDEX = 0;
	int const SUB_MENUB_INDEX = 1;
	int const SUB_MENUC_INDEX = 2;
	int const SUB_MENUD_INDEX = 3;
	int const SUB_MENUE_INDEX = 4;
	int const SUB_MENUF_INDEX = 5;
	int const SUB_MENUG_INDEX = 6;
	//PATIENT MENU INDEX
	int const LAST_NAME_INDEX = 0;
	int const FIRST_NAME_INDEX = 1;
	int const MIDDLE_NAME_IDNEX = 2;
	int const YEAR_INDEX = 3;
	int const MONTH_INDEX = 4;
	int const DAY_INDEX = 5;
	int const CARE_NUMBER_INDEX = 6;
	int const TIME_INDEX = 7;
	int const SYMPTOM_INDEX = 8;
	int const CATEGORY_INDEX = 9;


public:
	Menu();
	void generateMainMenu();
	void generateSubMenus();
	void generateSubMenuA();
	void generateCriticalMenu();
	void printCriticalMenu();
	void generateSubMenuB();
	void generateSubMenuC();
	void generateSubMenuD();
	void generateSubMenuE();
	void generateSubMenuF();
	void generateSubMenuG();



	void printMainMenu();
	bool pickMainMenu(char);
	int stringToInt(std::string);
};