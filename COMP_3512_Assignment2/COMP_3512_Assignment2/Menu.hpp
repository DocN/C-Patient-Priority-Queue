#pragma once
#include <iostream>
#include <string>
#include <vector>

class Menu {
private:
	std::vector<std::string> mainMenu;
	std::vector<std::vector<std::string>> menuSelection;
public:
	Menu();
	void generateMainMenu();
	void generateSubMenus();
	void generateSubMenuA();
	void generateSubMenuB();
	void generateSubMenuC();
	void generateSubMenuD();
	void generateSubMenuE();
	void generateSubMenuF();
	void generateSubMenuG();

	void printMainMenu();
	bool pickMainMenu(char);
};