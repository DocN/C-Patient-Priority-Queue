#include "Date.hpp"

Date::Date(int _month, int _day, int _year) {
	setMonthOfBirth(_month);
	setDayOfBirth(_day);
	setYearOfBirth(_year);
}
int Date::getYearOfBirth() {
	return Date::yearOfBirth;
}

int Date::getMonthOfBirth() {
	return Date::monthOfBirth;
}

int Date::getDayOfBirth() {
	return Date::dayOfBirth;
}
void Date::setYearOfBirth(int _yearOfBirth) {
	yearOfBirth = _yearOfBirth;
}
void Date::setMonthOfBirth(int _monthOfBirth) {
	monthOfBirth = _monthOfBirth;
}
void Date::setDayOfBirth(int _dayOfBirth) {
	dayOfBirth = _dayOfBirth;
}