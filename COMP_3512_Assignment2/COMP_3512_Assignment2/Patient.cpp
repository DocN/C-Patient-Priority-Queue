#include "Patient.hpp"
#include <string>
#include <algorithm>    // std::all_of

Patient::Patient() {

}

void Patient::setHealthCareNumber(std::string _healthCareNumber) {
	if (_healthCareNumber.length() == 8) {
		if (is_digits(_healthCareNumber)) {
			healthCareNumber = _healthCareNumber;
			return;
		}
	}
	throw "Invalid health care number";
}

void Patient::setTimeAdmited(int _hour, int _minute) {
	timeAdmited.setHour(_hour);
	timeAdmited.setMinute(_minute);
}

void Patient::setMainSymptoms(std::string _mainSymptoms) {
	mainSymptoms = _mainSymptoms;
}

void Patient::setCategoryNumber(int _categoryNumber) {
	if (_categoryNumber >= BEGIN_CATEGORY && _categoryNumber <= END_CATEGORY) {
		categoryNumber = _categoryNumber;
		return;
	}
	throw "Invalid category number please enter a number between 1-6";
}

std::string Patient::getHealthCareNumber() {
	return Patient::healthCareNumber;
}

std::string Patient::getTimeAdmitedString() {
	return timeAdmited.returnTime();
}

std::string Patient::getMainSymptoms() {
	return mainSymptoms;
}

int Patient::getCategoryNumber() {
	return categoryNumber;
}

Name & Patient::getName() {
	return myName;
}

Time & Patient::getTimeAdmitted() {
	return timeAdmited;
}

Date & Patient::getBirthday() {
	return birthday;
}


bool Patient::is_digits(const std::string &str)
{
	return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}

