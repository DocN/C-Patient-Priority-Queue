#pragma once
#include <iostream>
#include <string>

class Time {
private:
	int hour;
	int minute;
	const int ZERO_TIME = 0;
public:
	Time();
	Time(int, int);
	void setDefaultTime();
	void setHour(int);
	int getHour();
	void setMinute(int);
	int getMinute();
	std::string returnTime();
};