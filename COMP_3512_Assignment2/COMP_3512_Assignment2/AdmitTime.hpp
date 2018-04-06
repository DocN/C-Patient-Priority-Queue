#pragma once
#include <iostream>
#include <string>

class AdmitTime {
private:
	int hour;
	int minute;
	int second;
public:
	void setHour(int _hour);
	int getHour();
	void setMinute(int _minute);
	int getMinute();
	void setSecond(int _second);
	int getSecond();
	std::string returnTime();
};