#pragma once
class Date {
private:
	int yearOfBirth;
	int monthOfBirth;
	int dayOfBirth;
	
	const int BEGIN_YEAR = 1850;
	const int END_YEAR = 2018;

	const int BEGIN_DAY = 1;
	const int END_DAY = 31;

	const int BEGIN_MONTH = 1;
	const int END_MONTH = 12;
public:
	Date();
	Date(int, int, int);
	void setYearOfBirth(int);
	void setMonthOfBirth(int);
	void setDayOfBirth(int);
	int getYearOfBirth();
	int getMonthOfBirth();
	int getDayOfBirth();
};