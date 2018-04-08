#pragma once
#include <iostream>
#include <string>
class Name {
	private:
		std::string firstName;
		std::string lastName;
		std::string middleName;
	public:
		Name();
		Name(std::string, std::string, std::string);
		void setFirstName(std::string);
		void setLastName(std::string);
		void setMiddleName(std::string);
		std::string getFirstName();
		std::string getLastName();
		std::string getMiddleName();
};