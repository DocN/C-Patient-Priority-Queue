#pragma once
#include "PatientList.hpp"
class ReadWriter {
private:
	const std::string fileName = "patients.txt";
public:
	ReadWriter();
	void writePatientList(PatientList&);
	void loadPatientList(PatientList&);
	int stringToInt(std::string);
	void deleteFile();
};