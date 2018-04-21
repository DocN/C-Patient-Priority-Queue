#include "Time.hpp"
#include <iostream>
#include <string>
#include <sstream>

/*Time() - default constructor

*/
Time::Time() {
	setDefaultTime();
}

/* Time(int _hour, int _minute) - Time constructor with parameters
Input:
int _hour - the hour of our new Time object
int _minute - the min of our new Time object
*/
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

/*Time::setDefaultTime() - sets the default time 00:00
Input:
N/A
Output:
void
*/
void Time::setDefaultTime() {
	setHour(ZERO_TIME);
	setMinute(ZERO_TIME);
}

/*Time::set24Time(std::string myTime) - sets the entire time based on a 24 hour format string 00:00
Input:
std::string myTime - the time in string format
Output:
void
*/
void Time::set24Time(std::string myTime) {
	//check if the string is length 5 24 standard time format 
	if (myTime.length() == 5) {
		//check if we have a : in the right spot
		if (myTime[2] == ':') {
			//split the string to the two fragments of time hour/min
			std::string hourString = myTime.substr(TIME_INDEX_HOUR, TIME_SIZE);
			std::string minuteString = myTime.substr(TIME_INDEX_MIN, TIME_SIZE);
			//set them after converting them to ints
			setHour(std::atoi(hourString.c_str()));
			setMinute(std::atoi(minuteString.c_str()));
			return;
		}
	}
	//if anything goes wrong the input is invalid
	throw "Invalid format! please use 00:00 format";
}

/*Time::setHour(int _hour) - sets the Hour of this Time object
Input:
int _hour - the new hour that we're setting
Output:
void
*/
void Time::setHour(int _hour) {
	//check if the hour is in the right range 0-23
	if (_hour >= BEGIN_HOUR && _hour <= END_HOUR) {
		hour = _hour;
		return;
	}
	throw "Invalid hour! please enter an hour between 0 and 23";
}

/*Time::getHour() - gets the hour that the Time object currently has 
Intput:
N/A
Output:
int -the current hour stored in our time object
*/
int Time::getHour() {
	return hour;
}

/*Time::setMinute(int _minute) - sets the minute of our Time object
Input:
int _minute - the current minute 
Output:
void
*/
void Time::setMinute(int _minute) {
	//check if it's a valid min between 0-59
	if (_minute >= BEGIN_MIN && _minute <= END_MIN) {
		minute = _minute;
		return;
	}
	throw "Invalid minute! please enter an hour between 0 and 59";
}

/* Time::getMinute() -  gets the minute from our Time object
Input:
N/A
Output:
int - the time in mins 
*/
int Time::getMinute() {
	return minute;
}

/* Time::returnTime() - the time in string format 24 hour 00:00
Input:
N/A
Output:
std::string - the Time object's time in string format
*/
std::string Time::returnTime() {
	if (minute >= 10) {
		return (std::to_string(hour) + ":" + std::to_string(minute));
	}

	return (std::to_string(hour) + ":0" + std::to_string(minute));
}


/* Time::stringToInt(std::string myStr) - converts a string to an integer
Input:
std::string myStr - string we're trying to convert to an integer
Output:
int - the integer version of the input string
*/
int Time::stringToInt(std::string myStr) {
	int inteVal;
	std::istringstream buffer(myStr);
	buffer >> inteVal;
	if (inteVal < 0) {
		throw "Invalid number exception";
	}
	return inteVal;
}

/* swap(Time& t1, Time& t2) - swap for swapping the values of two Time objects
Input:
Time& t1 - the first time we're swapping 
Time& t2 - the second time we're swapping
Output:
void
*/
void swap(Time& t1, Time& t2) {
	std::swap(t1.hour, t2.hour);
	std::swap(t1.minute, t2.minute);
};

/* overloaded operator= for applying t to the current Time object 
Input:
Time t - the Time object we're replacing with the this Time object's data 
Output:
Time& -this Time object with new time values from t
*/
Time& Time::operator=(Time t) {
	swap(*this, t);
	return *this;
}

/*operator>=(Time t1, Time t2) - used to compare two Time objects to see whcih is greater or if they're both equal 
Input:
Time t1 - the first Time object
Time t2 - the second Time object
Output:
bool - if the two Time objects are greater or equal
*/
bool operator>=(Time t1, Time t2) {
	//check hours first 
	if (t1.getHour() > t2.getHour()) {
		return true;
	}
	//check if both hours are equal
	else if (t1.getHour() == t2.getHour()) {
		//when ours are equal check mins instead
		if (t1.getMinute() > t2.getMinute()) {
			return true;
		}
		else if (t1.getMinute() == t2.getMinute()) {
			return false;
		}
		else {
			return false;
		}
	}
	//when t2 is greater than t1
	else {
		return false;
	}
}

/*getTimeDifference(Time currentTime) - Used for getting the difference in time of two Time objects
Input:
Time currentTime - the time we're comparing against this Time Object
Output:
Time - the Time value difference
*/
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
		//carry over 60 mins from an hour
		newMin = 60 + currentTime.getMinute();
		newMin = newMin - getMinute();
		newHour--;
	}
	//create a new Time object that has the time difference
	Time newTime;
	newTime.setHour(newHour);
	newTime.setMinute(newMin);
	return newTime;
}






