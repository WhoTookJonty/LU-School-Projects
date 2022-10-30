//Header file for Pet
#pragma once
#include <iostream>

class Pet {
public:
	Pet(); //Constructor
	~Pet(); //Destructor

	std::string getName(); //Gets name value
	void setName(std::string); //sets name value

	std::string getType(); //Gets type value
	void setType(std::string); //Sets type value
	int getWeight(); //Gets weight value
	void setWeight(int); //Sets weight value
	void printPet(); //Function that prints out the values stored in the Pet object


private:
	std::string name; //Pet name
	std::string type; //Pet type (e.g dog, cat, etc.)
	int weight; //Pet weight
};
