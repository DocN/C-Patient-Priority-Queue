#include "AdmitTime.hpp"

void AdmitTime::setHour(int _hour) {
	hour = _hour;
}
int AdmitTime::getHour() {
	return hour;
}

void AdmitTime::setMinute(int _minute) {
	minute = _minute;
}
int AdmitTime::getMinute() {
	return minute;
}
void AdmitTime::setSecond(int _second) {
	second = _second;
}
int AdmitTime::getSecond() {
	return second;
}

std::string AdmitTime::returnTime() {
	if (minute >= 10) {
		return (hour + ":" + minute);
	}
	return (hour + ":0" + minute);
}

