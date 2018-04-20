#include "Date.hpp"
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string

/* Date Default constructor
*/
Date::Date() {

}
/* Date overloaded constructor 
Input: 
int _month - integer month value between 1-12 
int _day - integer day value between 1-31
int _year - integer year value between 1850 to 2018
Output:
N/A
*/
Date::Date(int _month, int _day, int _year) {
	//set all the values
	setMonthOfBirth(_month);
	setDayOfBirth(_day);
	setYearOfBirth(_year);
}

/* Date::getYearOfBirth() - gets the year of birth 
Input:
N/A
Output:
Integer - the year of birth
*/
int Date::getYearOfBirth() {
	return Date::yearOfBirth;
}

/* Date::getMonthOfBirth() - gets the month of birth
Input:
N/A
Output:
Integer - the month of birth
*/
int Date::getMonthOfBirth() {
	return Date::monthOfBirth;
}

/* Date::getDayOfBirth() - gets the day of birth
Input:
N/A
Output:
Integer - the day of birth
*/
int Date::getDayOfBirth() {
	return Date::dayOfBirth;
}

/* Date::setYearOfBirth(int _yearOfBirth) - sets the year of birth
Input:
int _yearOfBirth - the new year of birth we're setting
Output:
void
*/
void Date::setYearOfBirth(int _yearOfBirth) {
	//check if the year if valid before setting it 
	if (_yearOfBirth >= BEGIN_YEAR && _yearOfBirth <= END_YEAR) {
		yearOfBirth = _yearOfBirth;
		return;
	}
	//when the date is invalid
	throw "Invalid year of birth! please select a year between " + std::to_string(BEGIN_YEAR) + "-" + std::to_string(END_YEAR);
}

/* Date::setMonthOfBirth(int _monthOfBirth) - sets the month of birth
Input:
int _monthOfBirth - the new month of birth
Output:
void
*/
void Date::setMonthOfBirth(int _monthOfBirth) {
	//check if the month is valid 
	if (_monthOfBirth >= BEGIN_MONTH && _monthOfBirth <= END_MONTH) {
		monthOfBirth = _monthOfBirth;
		return;
	}
	//errors if it isn't valid
	throw "Invalid month! please select a month between " + std::to_string(BEGIN_MONTH) + "-" + std::to_string(END_MONTH);
}

/* Date::setDayOfBirth(int _dayOfBirth) - sets the day of birth
Input:
int _dayOfBirth - the new day of birth we're setting
Output:
void
*/
void Date::setDayOfBirth(int _dayOfBirth) {
	//check if it's a valid day before setting it
	if (_dayOfBirth >= BEGIN_DAY && _dayOfBirth <= END_DAY) {
		dayOfBirth = _dayOfBirth;
		return;
	}
	//errors when invalid input is entered
	throw "Invalid day of birth! please select a day between " + std::to_string(BEGIN_DAY) + "-" + std::to_string(END_DAY);
}

/*swap(Date& d1, Date& d2) - swap function for operator=  
Input:
Date& d1 - the first date we're swapping
Date& d2 - the second date we're swapping
Output:
void
*/
void swap(Date& d1, Date& d2) {
	std::swap(d1.yearOfBirth, d2.yearOfBirth);
	std::swap(d1.monthOfBirth, d2.monthOfBirth);
	std::swap(d1.dayOfBirth, d2.dayOfBirth);
};

/* Date::operator=(Date d) - overloaded equals operator for Date object
Input:
Date d - the date we're swapping with this
Output:
Date& - the date we're replacing with the equal operator
*/
Date& Date::operator=(Date d) {
	swap(*this, d);
	return *this;
}

/* Overloaded operator<< for outputting the Date in string format.
Input:
std::ostream& os - the output stream
Date& currentDate - the date we're outputting date information from
Output:
std::ostream& - the output stream 
*/
std::ostream& operator<<(std::ostream& os, Date& currentDate) {
	os << currentDate.getMonthOfBirth() << "/" << currentDate.getDayOfBirth() << "/" << currentDate.getYearOfBirth();
	return os;
}
