#pragma once
#include <iostream>
#include <string>

class Time {
private:
	int hour;
	int minute;
	const int ZERO_TIME = 0;
	const int BEGIN_HOUR = 0;
	const int END_HOUR = 23;
	const int BEGIN_MIN = 0;
	const int END_MIN = 59;

	const int TIME_SIZE = 2;
	const int TIME_INDEX_HOUR = 0;
	const int TIME_INDEX_MIN = 3;
public:
	Time();
	Time(int, int);
	void setDefaultTime();
	void setHour(int);
	int getHour();
	void setMinute(int);
	int getMinute();
	std::string returnTime();
	void set24Time(std::string);
	int stringToInt(std::string myStr);
	friend void swap(Time& t1, Time& t2);
	Time& operator=(Time t);
	friend bool operator>=(Time t1, Time t2);
	Time getTimeDifference(Time);
};