#include "Date.hpp"
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string

Date::Date() {

}

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
	if (_yearOfBirth >= BEGIN_YEAR && _yearOfBirth <= END_YEAR) {
		yearOfBirth = _yearOfBirth;
		return;
	}
	throw "Invalid year of birth! please select a year between " + std::to_string(BEGIN_YEAR) + "-" + std::to_string(END_YEAR);
}

void Date::setMonthOfBirth(int _monthOfBirth) {
	if (_monthOfBirth >= BEGIN_MONTH && _monthOfBirth <= END_MONTH) {
		monthOfBirth = _monthOfBirth;
		return;
	}
	throw "Invalid month! please select a month between " + std::to_string(BEGIN_MONTH) + "-" + std::to_string(END_MONTH);
}

void Date::setDayOfBirth(int _dayOfBirth) {
	if (_dayOfBirth >= BEGIN_DAY && _dayOfBirth <= END_DAY) {
		dayOfBirth = _dayOfBirth;
		return;
	}
	throw "Invalid day of birth! please select a day between " + std::to_string(BEGIN_DAY) + "-" + std::to_string(END_DAY);
}

void swap(Date& d1, Date& d2) {
	std::swap(d1.yearOfBirth, d2.yearOfBirth);
	std::swap(d1.monthOfBirth, d2.monthOfBirth);
	std::swap(d1.dayOfBirth, d2.dayOfBirth);
};

Date& Date::operator=(Date d) {
	swap(*this, d);
	return *this;
}
