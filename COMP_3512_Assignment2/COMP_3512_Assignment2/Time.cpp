#include "Time.hpp"

Time::Time() {
	setHour(ZERO_TIME);
	setMinute(ZERO_TIME);
	setSecond(ZERO_TIME);
}

Time::Time(int _hour, int _minute) {
	setHour(_hour);
	setMinute(_minute);
}
Time::Time(int _hour, int _minute, int _second) {
	setHour(_hour);
	setMinute(_minute);
	setSecond(_second);
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
void Time::setSecond(int _second) {
	second = _second;
}
int Time::getSecond() {
	return second;
}

std::string Time::returnTime() {
	if (minute >= 10) {
		return (hour + ":" + minute);
	}
	return (hour + ":0" + minute);
}

