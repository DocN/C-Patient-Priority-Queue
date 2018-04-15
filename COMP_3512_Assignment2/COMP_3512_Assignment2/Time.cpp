#include "Time.hpp"
#include <iostream>
#include <string>
#include <sstream>
Time::Time() {
	setDefaultTime();
}

Time::Time(int _hour, int _minute) {
	//check if the input time is valid.
	if (_hour >= 24 || _minute >= 60) {
		std::cout << "invalid time, setting default " << std::endl;
		setDefaultTime();
		return;
	}
	setHour(_hour);
	setMinute(_minute);
}

void Time::setDefaultTime() {
	setHour(ZERO_TIME);
	setMinute(ZERO_TIME);
}

void Time::set24Time(std::string myTime) {
	if (myTime.length() == 5) {
		std::string hourString = myTime.substr(TIME_INDEX_HOUR, TIME_SIZE);
		std::string minuteString = myTime.substr(TIME_INDEX_MIN, TIME_SIZE);
		setHour(std::atoi(hourString.c_str()));
		setMinute(std::atoi(minuteString.c_str()));
		return;
	}
	throw "Invalid format! please use 00:00 format";
}

void Time::setHour(int _hour) {
	if (_hour >= BEGIN_HOUR && _hour <= END_HOUR) {
		hour = _hour;
		return;
	}
	throw "Invalid hour! please enter an hour between 0 and 23";
}
int Time::getHour() {
	return hour;
}

void Time::setMinute(int _minute) {
	if (_minute >= BEGIN_MIN && _minute <= END_HOUR) {
		minute = _minute;
		return;
	}
	throw "Invalid minute! please enter an hour between 0 and 59";
}
int Time::getMinute() {
	return minute;
}

std::string Time::returnTime() {
	if (minute >= 10) {
		return (std::to_string(hour) + ":" + std::to_string(minute));
	}

	return (std::to_string(hour) + ":0" + std::to_string(minute));
}

int Time::stringToInt(std::string myStr) {
	int inteVal;
	std::istringstream buffer(myStr);
	buffer >> inteVal;
	if (inteVal < 0) {
		throw "Invalid number exception";
	}
	return inteVal;
}



