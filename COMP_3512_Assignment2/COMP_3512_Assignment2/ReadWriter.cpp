#include "ReadWriter.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>

/*ReadWriter - default constructor 
*/
ReadWriter::ReadWriter() {

}

/*ReadWriter::writePatientList(PatientList& currentList) - writes the patient's in the system to patients.txt
Input:
PatientList& currentList - the list of patients
Output:
void
*/
void ReadWriter::writePatientList(PatientList& currentList) {
	std::vector<Patient> tempList = currentList.copyPatientVector();
	//create the file we're writing our patientlist to 
	std::ofstream myfile(fileName);
	try {
		if (myfile.is_open())
		{
			//go through all our patients and write them onto the file
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
		//remove patients from queue that were written to file
		currentList.removeAllPatients();
		std::cout << "Patients successfully saved!" << std::endl;
	} catch (...) {
		std::cout << "failed to save patients!" << std::endl;
	}
}

/*ReadWriter::loadPatientList(PatientList& currentList) - loads all the patients from patients.txt to the patient queue
Input:
PatientList& currentList - our patient list
Output:
void
*/
void ReadWriter::loadPatientList(PatientList& currentList) {
	std::string line;
	std::ifstream myfile(fileName);
	//load the file 
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
		//delete the file after we're done loading it
		deleteFile();
		std::cout << "Patients successfully loaded!" << std::endl;
	}
}

/*ReadWriter::deleteFile() - deletes the patients.txt list
Input:
N/A
Output:
void
*/
void ReadWriter::deleteFile() {
	if (remove("patients.txt") != 0) {
		std::cout << "error deleting loaded file " << std::endl;
	}
}

/*ReadWriter::stringToInt(std::string myStr) - converts a string to an integer if it's numbers
Input: 
std::string myStr - the string we're converting to an integer
Output:
int - integer value we get from the string
*/
int ReadWriter::stringToInt(std::string myStr) {
	int inteVal;
	std::istringstream buffer(myStr);
	buffer >> inteVal;
	if (inteVal < 0) {
		throw "Invalid (integer) number exception";
	}
	return inteVal;
}
