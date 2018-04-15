#include "Time.hpp"
#include <iostream>
#include <string>
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

void Time::setHour(int _hour) {
	hour = _hour;
}
int Time::getHour() {
	return hour;
}

void Time::setMinute(int _minute) {
	minute = _minute;
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

