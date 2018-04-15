#include "PatientList.hpp"

PatientList::PatientList() {
}

void PatientList::addPatient(Patient & currentPatient) {
	pList.push(currentPatient);
}

void PatientList::printPatients() {

	while (!pList.empty()) {
		Patient current = pList.top();
		std::cout << current.getName().getFullName();
		pList.pop();
	}
}