#include "Patient.hpp"
#include <string>
Patient::Patient() {
	myName = Name();
	birthday = Date();
}

void Patient::setHealthCareNumber(std::string _healthCareNumber) {
	healthCareNumber = _healthCareNumber;
}

void Patient::setTimeAdmited(int _hour, int _minute) {
	timeAdmited.setHour(_hour);
	timeAdmited.setMinute(_minute);
}

void Patient::setMainSymptoms(std::string _mainSymptoms) {
	mainSymptoms = _mainSymptoms;
}

void Patient::setCategoryNumber(int _categoryNumber) {
	categoryNumber = _categoryNumber;
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

