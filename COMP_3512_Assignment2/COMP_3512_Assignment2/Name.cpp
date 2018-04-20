#include "Name.hpp"
/* Name - Default constructor
*/
Name::Name() {

}

/* Name - Overloaded constructor 
Input:
std::string _firstName - the new first name 
std::string _lastName  - the new last name
std::string _middleName - the new middle name
*/
Name::Name(std::string _firstName, std::string _lastName,  std::string _middleName) {
	//set all the parts of a name
	setFirstName(_firstName);
	setLastName(_lastName);
	setMiddleName(_middleName);
}

/*Name::setFirstName(std::string _firstName) - sets the firstname
Input:
std::string _firstName - the new first name
Output:
void
*/
void Name::setFirstName(std::string _firstName) {
	firstName = _firstName;
}

/*Name::setLastName(std::string _lastName)  - sets the lastname
Input:
std::string _lastName - the new last name
Output:
void
*/
void Name::setLastName(std::string _lastName) {
	lastName = _lastName;
}

/*Name::setMiddleName(std::string _middleName)   - sets the middlename
Input:
std::string _middleName - the new middle name
Output:
void
*/
void Name::setMiddleName(std::string _middleName) {
	middleName = _middleName;
}

/*Name::getFirstName()  - get the first name
Input:
N/A
Output:
std::string - the firstname of the current name
*/
std::string Name::getFirstName() {
	return firstName;
}

/*Name::getLastName()  - get the last name
Input:
N/A
Output:
std::string - the lastname of the current name
*/
std::string Name::getLastName() {
	return lastName;
}

/*Name::getMiddleName()  - get the middle name
Input:
N/A
Output:
std::string - the middle name of the current name
*/
std::string Name::getMiddleName() {
	return middleName;
}

/*Name::getFullName()  - get the full name 
Input:
N/A
Output:
std::string - the full name of the current name
*/
std::string Name::getFullName() {
	return firstName + " " + middleName + " " + lastName;
}