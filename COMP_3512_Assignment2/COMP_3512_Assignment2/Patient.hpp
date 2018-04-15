#pragma once
#include <iostream>
#include <string>
#include "Time.hpp"
#include "Name.hpp"
#include "Date.hpp"

class Patient {
private:
	Name myName;
	Date birthday;
	Time timeAdmited;
	std::string healthCareNumber;
	std::string mainSymptoms;
	int categoryNumber;
	const int BEGIN_CATEGORY = 1;
	const int END_CATEGORY = 6;
public:
	Patient();
	Name& getName();
	Time& getTimeAdmitted();
	void setHealthCareNumber(std::string);
	void setTimeAdmited(int, int);
	void setMainSymptoms(std::string);
	void setCategoryNumber(int);
	std::string getHealthCareNumber();
	std::string getTimeAdmitedString();
	std::string getMainSymptoms();
	int getCategoryNumber();
	Date & getBirthday();
	bool is_digits(const std::string &str);
	friend bool operator> (const Patient &p1, const Patient &p2);
	friend void swap(Patient& p1, Patient& p2);
	Patient& operator=(Patient p);
};