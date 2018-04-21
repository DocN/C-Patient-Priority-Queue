#include "PatientList.hpp"
#include <vector>
#include <stdio.h>
#include <string.h>

/*PatientList::PatientList() - PatientList default constructor 
*/
PatientList::PatientList() {
	//set default time when first making the list 
	currentTime.setDefaultTime();
}

/*PatientList::addPatient(Patient & currentPatient) - adding a patient to the queue
Input:
Patient & currentPatient - the patient we're adding to queue
Output:
void
*/
void PatientList::addPatient(Patient & currentPatient) {
	pList.push(currentPatient);
	Time currentPatientTime = currentPatient.getTimeAdmitted();
	updateTime(currentPatientTime);
}

/*PatientList::updateTime(Time newTime) - updating the time of the patientList 
Input:
Time newTime - the time of the most recent patient to update our current time
Output:
void
*/
void PatientList::updateTime(Time newTime) {
	//set the new time
	currentTime.setHour(newTime.getHour());
	currentTime.setMinute(newTime.getMinute());
	std::cout << "New Time! " << currentTime.returnTime() << std::endl;
}

/*PatientList::compareTime(Time newTime)  - used for comparing two times against each other to see which is greater or if they're equal
Input:
Time newTime - the new time we're checking to see if it's greater than the current time
Output:
bool - if the new time is greater true/false
*/
bool PatientList::compareTime(Time newTime) {
	if (newTime >= currentTime) {
		return true;
	}
	return false;
}

/*PatientList::printPatients() - prints all the patients in our priority queue at the moment
Input:
N/A
Output:
void
*/
void PatientList::printPatients() {
	std::vector<Patient> tempList;
	std::cout << std::endl << "******Patient's List******" << std::endl;
	if (pList.empty()) {
		std::cout << "No Patients in list" << std::endl;
	}
	//pop them off and print them 
	while (!pList.empty()) {
		Patient current = pList.top();
		tempList.push_back(current);
		std::cout << current;
		pList.pop();
	}
	std::cout << "**************************" << std::endl << std::endl;
	//add them back on the list
	for (int i = 0; i < tempList.size(); i++) {
		Patient currentPatient = tempList.at(i);
		pList.push(currentPatient);
	}
}

/*PatientList::getNextPatient() - gets the next patient in the priority queue
Input:
N/A
Output:
void
*/
void PatientList::getNextPatient() {
	if (pList.empty()) {
		std::cout << "error patient list is empty " << std::endl;
		return;
	}
	//displays the next patient
	std::cout << "=================Next Patient================" << std::endl;
	Patient nextPatient = pList.top();
	std::cout << nextPatient;
	pList.pop();
	std::cout << "=============================================" << std::endl << std::endl;
}

/*PatientList::getPatientCategory(std::string currentHealthID) - gets the current patient category 
Input:
std::string currentHealthID - the patient's health id we're trying to pull up
Output:
int - the integer value of the patient category
*/
int PatientList::getPatientCategory(std::string currentHealthID) {
	std::vector<Patient> tempList;
	//pop users off the list so we can search them
	while(!pList.empty()) {
		Patient currentPatient = pList.top();
		tempList.push_back(currentPatient);
		pList.pop();
	}
	//put them back on the queue
	for (int i = 0; i < tempList.size(); i++) {
		pList.push(tempList.at(i));
	}

	//check for the patient index of the patient with the currentHealthID
	int patientIndex = getPatientIndex(tempList, currentHealthID);
	//no patient with health care number found
	if (patientIndex == -1) {
		return -1;
	}
	//return that patient's category number
	Patient keyPatient = tempList.at(patientIndex);
	return keyPatient.getCategoryNumber();
}

/*PatientList::getPatientIndex(std::vector<Patient> tempList, std::string healthKey) - gets the patient's index in the templist
Input:
std::vector<Patient> tempList - the list of patients
std::string healthKey - the healthcare number we're trying to search for
Output:
int - the patient index in the list
*/
int PatientList::getPatientIndex(std::vector<Patient> tempList, std::string healthKey) {
	for (int i = 0; i < tempList.size(); i++) {
		Patient currentPatient = tempList.at(i);
		std::string currentHealthID = currentPatient.getHealthCareNumber();
		if (currentHealthID.compare(healthKey) == 0) {
			return i;
		}
	}
	//no result found
	return -1;
}

/*PatientList::setCategoryID(int newCategoryID, std::string currentHealthID) - sets the category id of the patient with the healthID 
Input:
int newCategoryID - the new category id we want to set for the patient
std::string currentHealthID - the patient we're looking to change's health id 
Output:
void
*/
void PatientList::setCategoryID(int newCategoryID, std::string currentHealthID) {
	std::vector<Patient> tempList;
	//empty the list and store it in a vector
	while (!pList.empty()) {
		Patient currentPatient = pList.top();
		tempList.push_back(currentPatient);
		pList.pop();
	}
	//set the new category id
	int patientIndex = getPatientIndex(tempList, currentHealthID);
	tempList.at(patientIndex).setCategoryNumber(newCategoryID);

	//resort queue by pushing elements back on
	for (int i = 0; i < tempList.size(); i++) {
		pList.push(tempList.at(i));
	}
}

/*PatientList::promoteQueue() - promotes users in the queue when x amount of time has passed depending on conditions
Input:
N/A
Output:
void
*/
void PatientList::promoteQueue() {
	std::vector<Patient> tempList;
	while (!pList.empty()) {
		Patient currentPatient = pList.top();
		tempList.push_back(currentPatient);
		pList.pop();
	}
	for (int i = 0; i < tempList.size(); i++) {
		Time passedTime = tempList.at(i).getTimeAdmitted().getTimeDifference(currentTime);
		//patient in category level 2
		if (tempList.at(i).getCategoryNumber() == 2) {
			//check if one hour has passed
			if (passedTime.getHour() >= 1) {
				int newCategory = tempList.at(i).getCategoryNumber() -1;
				tempList.at(i).setCategoryNumber(newCategory);
			}
		}
		//if they're level 3 or 4
		else if (tempList.at(i).getCategoryNumber() == 3 || tempList.at(i).getCategoryNumber() == 4) {
			//two hours have passed
			if (passedTime.getHour() >= 2) {
				tempList.at(i).setCategoryNumber(tempList.at(i).getCategoryNumber() - 1);
			}
		}
		//if they're level 
		else if (tempList.at(i).getCategoryNumber() == 4 || tempList.at(i).getCategoryNumber() == 5) {
			//two hours have passed
			if (passedTime.getHour() >= 3) {
				tempList.at(i).setCategoryNumber(tempList.at(i).getCategoryNumber() - 1);
			}
		}
		else if (tempList.at(i).getCategoryNumber() == 6) {
			//two hours have passed
			if (passedTime.getHour() >= 4) {
				tempList.at(i).setCategoryNumber(tempList.at(i).getCategoryNumber() - 1);
			}
		}
	}
	//done updating patient catgories push them back onto the queue
	for (int i = 0; i < tempList.size(); i++) {
		pList.push(tempList.at(i));
	}
}

/*std::vector<Patient> PatientList::copyPatientVector() - Make a copy of the patient priority queue in vector format
Input:
N/A
Output:
std::vector<Patient> - vector with all patients in the queue
*/
std::vector<Patient> PatientList::copyPatientVector() {
	std::vector<Patient> tempList;
	while (!pList.empty()) {
		Patient currentPatient = pList.top();
		pList.pop();
		tempList.push_back(currentPatient);
	}
	for (int i = 0; i < tempList.size(); i++) {
		pList.push(tempList.at(i));
	}
	return tempList;
}

/*PatientList::removeAllPatients() - removes all the patients from the queue
Input:
N/A
Output:
void
*/
void PatientList::removeAllPatients() {
	while (!pList.empty()) {
		pList.pop();
	}
}