#include "Patient.hpp"
#include <string>
#include <algorithm>    // std::all_of

/*Patient - Default constructor*/
Patient::Patient() {

}

/* Patient::setHealthCareNumber(std::string _healthCareNumber) - sets the patient's healthcare number
Input:
std::string _healthCareNumber - the healthcare number
Output:
void
*/
void Patient::setHealthCareNumber(std::string _healthCareNumber) {
	//check if it's exactly 8 digits
	if (_healthCareNumber.length() == 8) {
		//check if they're all digits
		if (is_digits(_healthCareNumber)) {
			healthCareNumber = _healthCareNumber;
			return;
		}
	}
	throw "Invalid health care number";
}

/* Patient::setTimeAdmitted(int _hour, int _minute) - sets the time the patient was admitted hours and mins
Input:
int _hour - the hour the patient was admitted 
int _minute
Output:
void
*/
void Patient::setTimeAdmitted(int _hour, int _minute) {
	timeAdmitted.setHour(_hour);
	timeAdmitted.setMinute(_minute);
}

/* Patient::setMainSymptoms(std::string _mainSymptoms) - sets the main symptoms 
Input:
std::string _mainSymptoms - the new main symptoms
Output:
void
*/
void Patient::setMainSymptoms(std::string _mainSymptoms) {
	mainSymptoms = _mainSymptoms;
}

/*  Patient::setCategoryNumber(int _categoryNumber) - sets the category number 
Input:
int _categoryNumber - the new category number
Output:
void
*/
void Patient::setCategoryNumber(int _categoryNumber) {
	//checks if it's a valid category number first
	if (_categoryNumber >= BEGIN_CATEGORY && _categoryNumber <= END_CATEGORY) {
		categoryNumber = _categoryNumber;
		return;
	}
	throw "Invalid category number please enter a number between 1-6";
}

/*Patient::getHealthCareNumber() - gets the patient's healthcare number
Input:
void
Output:
std::string - patient's healthcare number
*/
std::string Patient::getHealthCareNumber() {
	return Patient::healthCareNumber;
}

/*Patient::getTimeAdmittedString() - patient's admitted time in string format
Input:
void
Output:
std::string - patient's healthcare number
*/
std::string Patient::getTimeAdmittedString() {
	return timeAdmitted.returnTime();
}

/*Patient::getMainSymptoms()- gets the patient's main symptom
Input:
void
Output:
std::string - the patient's main symptoms
*/
std::string Patient::getMainSymptoms() {
	return mainSymptoms;
}

/*Patient::getCategoryNumber() - gets the patient's category number
Input:
void
Output:
int - the patient's category number
*/
int Patient::getCategoryNumber() {
	return categoryNumber;
}

/*Patient::getName() - returns the patient's name object
Input:
N/A
Output:
Name& - the patient's name object
*/
Name & Patient::getName() {
	return myName;
}

/*Patient::getTimeAdmitted() - returns the patient's TimeAdmitted object
Input:
N/A
Output:
Time& - the patient's TimeAdmitted object
*/
Time & Patient::getTimeAdmitted() {
	return timeAdmitted;
}

/*Patient::getBirthday() - returns the patient's Date birthday object
Input:
N/A
Output:
Date& - the patient's Date Birthday object
*/
Date & Patient::getBirthday() {
	return birthday;
}

/*is_digits(const std::string &str) - checks if a string is an integer number
Input:
const std::string &str - the string we're passing in to check if it's a number
Output:
bool - if it's a number or not
*/
bool Patient::is_digits(const std::string &str)
{
	return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}

/*swap(Patient& p1, Patient& p2) - for swapping patients data
Input:
Patient& p1 - the first patient
Patient& p2 - the second patient
Output:
void
*/
void swap(Patient& p1, Patient& p2) {
	//swap all the patient data
	std::swap(p1.myName, p2.myName);
	std::swap(p1.birthday, p2.birthday);
	std::swap(p1.timeAdmitted, p2.timeAdmitted);
	std::swap(p1.healthCareNumber, p2.healthCareNumber);
	std::swap(p1.mainSymptoms, p2.mainSymptoms);
	std::swap(p1.categoryNumber, p2.categoryNumber);
};

/*overloaded operater= for replacing data in a patient with new patient data
Input:
Patient p - Patient object with new patient data
Output:
Patient& - the patient object with new patient data
*/
Patient& Patient::operator=(Patient p) {
	swap(*this, p);
	return *this;
}

/* overloaded operator> (Patient &p1, Patient &p2) - for comparing two patients against each other to see which is greater for priority queue
Input:
Patient &p1 - first patient
Patient &p2 - second patient
Output:
bool - if p1 is > than p2 
*/
bool operator> (Patient &p1, Patient &p2) {
	//when p1 is higher priority than p2 return true right away
	if (p1.getCategoryNumber() > p2.getCategoryNumber()) {
		return true;
	}
	//when p2 has greater priority
	else if(p1.getCategoryNumber() < p2.getCategoryNumber()) {
		return false;
	}
	//equal condition
	else {
		//use the admitted time to compare which patient has higher priority
		if (p1.getTimeAdmitted() >= p2.getTimeAdmitted()) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

/*Overloaded operator<< - Used for outputting patient data
Input:
std::ostream& os - output stream we're feeding patient data to 
Patient& myPatient - the patient we're getting data from 
Output:
std::ostream& - output stream object 
*/
std::ostream& operator<<(std::ostream& os, Patient& myPatient)
{
	//output all the patient data to os stream
	os << "=============================================" << std::endl;
	os << "Name: " << myPatient.getName().getFullName() << std::endl;
	os << "Health #: " << myPatient.getHealthCareNumber() << std::endl;
	os << "Time Admitted: " << myPatient.getTimeAdmittedString() << std::endl;
	os << "Date of Birth: " << myPatient.getBirthday() << std::endl;
	os << "Symptoms: " << myPatient.getMainSymptoms() << std::endl;
	os << "Seriousness Level: " << myPatient.getCategoryNumber() << std::endl;
	os << "=============================================" << std::endl;

	return os;
}


