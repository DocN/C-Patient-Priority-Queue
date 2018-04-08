#pragma once
#include <iostream>
#include <string>

class Time {
private:
	int hour;
	int minute;
	int second;
	const int ZERO_TIME = 0;
public:
	Time();
	Time(int, int);
	Time(int, int, int);
	void setHour(int _hour);
	int getHour();
	void setMinute(int _minute);
	int getMinute();
	void setSecond(int _second);
	int getSecond();
	std::string returnTime();
};