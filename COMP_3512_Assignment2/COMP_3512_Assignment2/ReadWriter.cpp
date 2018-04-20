#include "ReadWriter.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>


ReadWriter::ReadWriter() {

}

void ReadWriter::writePatientList(PatientList& currentList) {
	std::vector<Patient> tempList = currentList.copyPatientVector();
	std::ofstream myfile(fileName);
	if (myfile.is_open())
	{
		for (int i = 0; i < tempList.size(); i++) {
			Patient currentPatient = tempList.at(i);
			myfile << currentPatient.getName().getLastName() << "\n";
			myfile << currentPatient.getName().getFirstName() << "\n";
			myfile << currentPatient.getName().getMiddleName() << "\n";
			myfile << currentPatient.getBirthday().getMonthOfBirth() << "\n";
			myfile << currentPatient.getBirthday().getDayOfBirth() << "\n";
			myfile << currentPatient.getBirthday().getYearOfBirth() << "\n";
			myfile << currentPatient.getHealthCareNumber() << "\n";
			myfile << currentPatient.getTimeAdmitted().getHour() << "\n";
			myfile << currentPatient.getTimeAdmitted().getMinute() << "\n";
			myfile << currentPatient.getMainSymptoms() << "\n";
			myfile << currentPatient.getCategoryNumber() << "\n";
		}
		myfile.close();
	}
	currentList.removeAllPatients();
	std::cout << "Patients successfully saved!" << std::endl;
}

void ReadWriter::loadPatientList(PatientList& currentList) {
	std::string line;
	std::ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			try {
				Patient currentPatient;
				currentPatient.getName().setLastName(line);
				getline(myfile, line);
				currentPatient.getName().setFirstName(line);
				getline(myfile, line);
				currentPatient.getName().setMiddleName(line);
				getline(myfile, line);
				currentPatient.getBirthday().setMonthOfBirth(stringToInt(line));
				getline(myfile, line);
				currentPatient.getBirthday().setDayOfBirth(stringToInt(line));
				getline(myfile, line);
				currentPatient.getBirthday().setYearOfBirth(stringToInt(line));
				getline(myfile, line);
				currentPatient.setHealthCareNumber(line);
				getline(myfile, line);
				currentPatient.getTimeAdmitted().setHour(stringToInt(line));
				getline(myfile, line);
				currentPatient.getTimeAdmitted().setMinute(stringToInt(line));
				getline(myfile, line);
				currentPatient.setMainSymptoms(line);
				getline(myfile, line);
				currentPatient.setCategoryNumber(stringToInt(line));
				currentList.addPatient(currentPatient);
			}
			catch (const std::string& ex) {
				std::cout << ex << std::endl;
			}
			catch (...) {
				std::cout << "unknown error reading file" << std::endl;
			}
		}
		myfile.close();
		deleteFile();
		std::cout << "Patients successfully loaded!" << std::endl;
	}
}

void ReadWriter::deleteFile() {
	if (remove("patients.txt") != 0) {
		std::cout << "error deleting loaded file " << std::endl;
	}
}
int ReadWriter::stringToInt(std::string myStr) {
	int inteVal;
	std::istringstream buffer(myStr);
	buffer >> inteVal;
	if (inteVal < 0) {
		throw "Invalid (integer) number exception";
	}
	return inteVal;
}
