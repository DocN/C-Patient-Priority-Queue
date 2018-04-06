#pragma once
#include <iostream>
#include <string>


class Patient {
private:
	std::string firstName;
	std::string lastName;
	std::string middleName;
	int yearOfBirth;
	int monthOfBirth;
	int dayOfBirth;
	std::string healthCareNumber;

public:
	Patient();
	void setFirstName(std::string);
	void setLastName(std::string);
	void setMiddleName(std::string);
	std::string getFirstName();
	std::string getLastName();
	std::string getMiddleName();
};