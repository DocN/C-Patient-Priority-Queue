#include "PatientList.hpp"
#include <vector>
#include <stdio.h>
#include <string.h>

PatientList::PatientList() {
	//set default time when first making the list 
	currentTime.setDefaultTime();
}

void PatientList::addPatient(Patient & currentPatient) {
	pList.push(currentPatient);
	Time currentPatientTime = currentPatient.getTimeAdmitted();
	updateTime(currentPatientTime);
}

void PatientList::updateTime(Time newTime) {
	currentTime.setHour(newTime.getHour());
	currentTime.setMinute(newTime.getMinute());
	std::cout << "New Time! " << currentTime.returnTime() << std::endl;
}

bool PatientList::compareTime(Time newTime) {
	if (newTime >= currentTime) {
		return true;
	}
	return false;
}

void PatientList::printPatients() {
	std::vector<Patient> tempList;
	std::cout << std::endl << "******Patient's List******" << std::endl;
	if (pList.empty()) {
		std::cout << "No Patients in list" << std::endl;
	}
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

void PatientList::getNextPatient() {
	std::cout << "=================Next Patient================" << std::endl;
	Patient nextPatient = pList.top();
	std::cout << nextPatient;
	pList.pop();
	std::cout << "=============================================" << std::endl << std::endl;
}

int PatientList::getPatientCategory(std::string currentHealthID) {
	std::vector<Patient> tempList;
	while(!pList.empty()) {
		Patient currentPatient = pList.top();
		tempList.push_back(currentPatient);
		pList.pop();
	}

	for (int i = 0; i < tempList.size(); i++) {
		pList.push(tempList.at(i));
	}

	int patientIndex = getPatientIndex(tempList, currentHealthID);
	//no patient with health care number found
	if (patientIndex == -1) {
		return -1;
	}
	Patient keyPatient = tempList.at(patientIndex);
	return keyPatient.getCategoryNumber();
}

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

void PatientList::setCategoryID(int newCategoryID, std::string currentHealthID) {
	std::vector<Patient> tempList;
	while (!pList.empty()) {
		Patient currentPatient = pList.top();
		tempList.push_back(currentPatient);
		pList.pop();
	}

	int patientIndex = getPatientIndex(tempList, currentHealthID);
	tempList.at(patientIndex).setCategoryNumber(newCategoryID);

	//resort queue by pushing elements back on
	for (int i = 0; i < tempList.size(); i++) {
		pList.push(tempList.at(i));
	}
}

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

	for (int i = 0; i < tempList.size(); i++) {
		pList.push(tempList.at(i));
	}
}


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

void PatientList::removeAllPatients() {
	while (!pList.empty()) {
		pList.pop();
	}
}