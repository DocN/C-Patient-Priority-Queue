#include "Name.hpp"
Name::Name() {

}
Name::Name(std::string _firstName, std::string _lastName,  std::string _middleName) {
	setFirstName(_firstName);
	setLastName(_lastName);
	setMiddleName(_middleName);
}
void Name::setFirstName(std::string _firstName) {
	Name::firstName = _firstName;
}

void Name::setLastName(std::string _lastName) {
	Name::lastName = _lastName;
}

void Name::setMiddleName(std::string _middleName) {
	Name::middleName = _middleName;
}

std::string Name::getFirstName() {
	return Name::firstName;
}

std::string Name::getLastName() {
	return Name::lastName;
}

std::string Name::getMiddleName() {
	return Name::middleName;
}
