//Implementation file for header file Patient.h

#include "Patient.h" //Linked to header file
#include <iostream>

using namespace std;

Patient::Patient(){} //Default constructor

Patient::Patient(std::string name) { //Constructor to initiliaze patients name
	setPName(name);
}

Patient::~Patient() {}//Destructor

void Patient::setPName(std::string name) { //Sets patients name
	pName = name;
}

string Patient::getPName() const { //returns patients name
	return pName;
}

void Patient::setReadings(int i) { //Adds user passed value to a vector
	readings.push_back(i);
}
std::vector<int> Patient::getReadings() { //returns vector full of cholesterol readings
	return readings;
}



void Patient::addCholesterol() { //Function to add cholesterol readings
	int numOfR; //Number of readings 
	int reading;//used to store cholesterol readings before they are passed into a vector
	
		cout << "How many readings would you like to add?" << endl; 
		cin >> numOfR;
		while (cin.fail() || numOfR < 0 || numOfR> 5) { //Checks if user tries to a non-integer or more than 5 cholesterol readings
			cout << "Please enter a positive number that is 5 or less" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> numOfR;
		}
	
	for (size_t i = 0; i < numOfR; i++) //iterates up to number of cholesterol readings a user wants, prompts user to input number and adds it to a vector
	{
		cout << "Enter your reading: ";
		cin >> reading;
		setReadings(reading);
	}
	

}

void Patient::printCholReadings() { //Iterates through cholesteral readings in a vector
	for (size_t i = 0; i < getReadings().size(); i++)
	{
		cout << "Cholesterol Reading " << (i+1) << ": " << getReadings().at(i) << endl;
		
	}
	cout << endl;
}
