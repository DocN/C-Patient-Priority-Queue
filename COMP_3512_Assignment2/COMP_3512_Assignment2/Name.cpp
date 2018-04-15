#include "Name.hpp"
Name::Name() {

}
Name::Name(std::string _firstName, std::string _lastName,  std::string _middleName) {
	setFirstName(_firstName);
	setLastName(_lastName);
	setMiddleName(_middleName);
}
void Name::setFirstName(std::string _firstName) {
	firstName = _firstName;
}

void Name::setLastName(std::string _lastName) {
	lastName = _lastName;
}

void Name::setMiddleName(std::string _middleName) {
	middleName = _middleName;
}

std::string Name::getFirstName() {
	return firstName;
}

std::string Name::getLastName() {
	return lastName;
}

std::string Name::getMiddleName() {
	return middleName;
}

std::string Name::getFullName() {
	return firstName + " " + middleName + " " + lastName;
}