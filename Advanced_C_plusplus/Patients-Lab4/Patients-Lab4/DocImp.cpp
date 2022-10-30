//Implementation of the header file Doctor.h

#include "Doctor.h" //links header file to implementation file
#include <iostream>
#include <string>

using namespace std;

Doctor::Doctor() {} //default constructor

Doctor::Doctor(string name) { //constructor to initialize doctors name
	setDocName(name);
}

Doctor::~Doctor() {}//Destructor

void Doctor::setDocName(string name) { //set doctors name
	docName = name;
}

string Doctor::getDocName() const{ //return doctors name
	return docName;
}

std::vector<Patient> Doctor::getPatientList() { //returns the vector patientList
	return patientList;
}

void Doctor::setPatientList(Patient p) { //Adds object of the Patient class to vector
	patientList.push_back(p);

}


void Doctor::addPatient(string patientName) { //Creates patient object, prompts user for cholesterol readings, sets patient name, then adds object to a list
	Patient p{patientName};
	p.addCholesterol();
	setPatientList(p);

}

void Doctor::printDocPatients() { //Prints Name of patient at the iterated location of the list then calls function printCholReadings that prints out cholesterol 
								  //readings of patient 
	for (size_t i = 0; i < getPatientList().size(); i++)
	{
		cout << "Patient number " << (i+1) << " whose name is " << getPatientList().at(i).getPName() << " has records: " << endl;
		getPatientList().at(i).printCholReadings();
	}
}

