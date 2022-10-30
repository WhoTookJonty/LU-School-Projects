#pragma once
//Header file

#include <iostream>
#include <vector>

class Patient {
public:
	Patient();//Default constructor
	Patient(std::string);//Constructor to initiliaze patients name
	~Patient();//Destructor

	void setPName(std::string);//Sets patients name
	std::string getPName()const;//returns patients name

	void addCholesterol();//Function to add cholesterol readings
	void printCholReadings();//Iterates through cholesteral readings in a vector

	

	void setReadings(int);//Adds user passed value to a vector
	std::vector <int> getReadings();//returns vector full of cholesterol readings
	


private:
	std::string pName;//Patients name
	std::vector<int> readings;//vector to contain cholesterol readings
};
