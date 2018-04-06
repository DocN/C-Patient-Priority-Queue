#include "Patient.hpp"

Patient::Patient() {

}
void Patient::setFirstName(std::string _firstName) {
	Patient::firstName = _firstName;
}

void Patient::setLastName(std::string _lastName) {
	Patient::lastName = _lastName;
}

void Patient::setMiddleName(std::string _middleName) {
	Patient::middleName = _middleName;
}

std::string Patient::getFirstName() {
	return Patient::firstName;
}

std::string Patient::getLastName() {
	return Patient::lastName;
}

std::string Patient::getMiddleName() {
	return Patient::middleName;
}