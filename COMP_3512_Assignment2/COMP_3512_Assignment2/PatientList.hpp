#pragma once
#include "Patient.hpp"
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

typedef bool(*comp)(Patient, Patient);

bool static compare(Patient p1, Patient p2) {
	return p1 > p2;
}

class PatientList {
private:
	std::priority_queue<Patient, std::vector<Patient>, comp> pList{ compare };
public:
	PatientList();
	void addPatient(Patient &);
};