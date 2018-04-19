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
		if (myTime[2] == ':') {
			std::string hourString = myTime.substr(TIME_INDEX_HOUR, TIME_SIZE);
			std::string minuteString = myTime.substr(TIME_INDEX_MIN, TIME_SIZE);
			setHour(std::atoi(hourString.c_str()));
			setMinute(std::atoi(minuteString.c_str()));
			return;
		}
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
	if (_minute >= BEGIN_MIN && _minute <= END_MIN) {
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

void swap(Time& t1, Time& t2) {
	std::swap(t1.hour, t2.hour);
	std::swap(t1.minute, t2.minute);
};

Time& Time::operator=(Time t) {
	swap(*this, t);
	return *this;
}

bool operator>=(Time t1, Time t2) {
	if (t1.getHour() > t2.getHour()) {
		return true;
	}
	else if (t1.getHour() == t2.getHour()) {
		if (t1.getMinute() > t2.getMinute()) {
			return true;
		}
		else if (t1.getMinute() == t2.getMinute()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

Time Time::getTimeDifference(Time currentTime) {
	//t1 used for currentTime  and t2 used for time we're evaluating against
	int currentHour = currentTime.getHour();
	int currentMin = currentTime.getMinute();

	int newHour = currentHour - getHour();
	int newMin = 0;
	//check if we need to pull from hours
	if (currentTime.getMinute() >= getMinute()) {
		newMin = (currentTime.getMinute() - getMinute());
	}
	else {
		newMin = 60 + currentTime.getMinute();
		newMin = newMin - getMinute();
		newHour--;
	}
	Time newTime;
	newTime.setHour(newHour);
	newTime.setMinute(newMin);
	return newTime;
}






