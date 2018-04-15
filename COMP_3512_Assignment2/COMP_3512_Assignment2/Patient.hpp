#pragma once
#include <iostream>
#include <string>
#include "Time.hpp"
#include "Name.hpp"
#include "Date.hpp"

class Patient {
private:
	Name * myName;
	Date * birthday;
	Time * timeAdmited;
	std::string healthCareNumber;
	std::string mainSymptoms;
	int categoryNumber;
public:
	Patient();
	Name * getName();
	Time * getTimeAdmitted();
	void setHealthCareNumber(std::string);
	void setTimeAdmited(int, int);
	void setMainSymptoms(std::string);
	void setCategoryNumber(int);
	std::string getHealthCareNumber();
	std::string getTimeAdmitedString();
	std::string getMainSymptoms();
	int getCategoryNumber();
	Date * getBirthday();
};