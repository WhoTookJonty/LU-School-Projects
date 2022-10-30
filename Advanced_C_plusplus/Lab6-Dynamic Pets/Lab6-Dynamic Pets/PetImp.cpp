//Implementation file for Pet.h
#include <iostream>
#include <iomanip>
#include "Pet.h"

using namespace std;
Pet::Pet() { //Constructor
	cout << "Creating new pet" << endl;
}
Pet::~Pet()  //Destructor
{
	cout << "In the Pet destructor." << endl;
}



void Pet::setName(string n) {  //Sets pet name
	name = n;
}

std::string Pet::getName() { //gets pet name
	return name;
}

void Pet::setType(string t) { //sets pet type
	type = t;
}
std::string Pet::getType() { //gets pet type
	return type;
}

void Pet::setWeight(int w) { //set pets weight
	weight = w;
}
int Pet::getWeight() { //get pets weight
	return weight;
}

void Pet::printPet() { //Function that prints out the values stored in the Pet object
	cout << left << setw(20) << "Pet name: " << getName() << endl;
	cout << left << setw(20) << "Pet type: " << getType() << endl;
	cout << left << setw(20) << "Pet weight: " << getWeight() << endl;
}