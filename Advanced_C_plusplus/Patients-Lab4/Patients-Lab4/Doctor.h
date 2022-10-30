#pragma once
//Header file for Doctor

#include <iostream>
#include "Patient.h" //Links header file for the access of the Patient class

class Doctor{
public:
	Doctor(); //Default constructor
	Doctor(std::string); //constructor that initilizes doctors name of type string
	~Doctor();//Destructor

	void setDocName(std::string); //set doctors name
	std::string getDocName()const; //return doctors name
	
	void addPatient(std::string); //Creates patient object, prompts user for cholesterol readings, sets patient name, then adds object to a list

	void printDocPatients();//Prints Name of patient at the iterated location of the list then calls function printCholReadings that prints out cholesterol 
							//readings of patient 
	
	void setPatientList(Patient);//Adds object of the Patient class to vector
	std::vector<Patient> getPatientList();//returns the vector patientList

private:
	std::string docName; //Doctors name
	std::vector <Patient> patientList; //Vector that holds objects of the Patient class
};