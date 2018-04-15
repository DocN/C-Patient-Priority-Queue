#include "PatientList.hpp"

PatientList::PatientList() {
}

void PatientList::addPatient(Patient & currentPatient) {
	pList.push(currentPatient);
}