#include "PatientList.hpp"
#include <vector>


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