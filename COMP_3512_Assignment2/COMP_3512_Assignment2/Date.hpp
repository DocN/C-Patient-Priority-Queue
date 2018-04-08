#pragma once
class Date {
private:
	int yearOfBirth;
	int monthOfBirth;
	int dayOfBirth;
public:
	Date(int, int, int);
	void setYearOfBirth(int);
	void setMonthOfBirth(int);
	void setDayOfBirth(int);
	int getYearOfBirth();
	int getMonthOfBirth();
	int getDayOfBirth();
};