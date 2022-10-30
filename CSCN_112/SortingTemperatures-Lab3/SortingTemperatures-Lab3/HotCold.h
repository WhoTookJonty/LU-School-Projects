#pragma once
#include <vector>
#include <algorithm> //include algorithm for sort function
#include <string>


class Temperature { 

public:

	//Constructor
	Temperature(std::string inputMonth, std::string inputYear);

	//YEAR GET AND SET
	void setYear(std::string inputYear);
	std::string getYear() const;

	//MONTH GET AND SET
	void setMonth(std::string inputMonth);
	std::string getMonth() const;

	//VECTOR GET AND SET
	std::vector<int>& getVector();
	void setVector(int temperature);

	//-------------------- Functions that manipulate the vector 'tempList' -------------------

	void AddFunction(int temperature); //Add value passed in onto the end of the vector 
	void sortVector(); //sort the temperatures stored in the vector by ascending order
	double tempAverage(); //prints out the value in each position of the vector
	int returnListSize(); //calculates the average of every value contained in the vector
	void displayVector(); //returns the size of the vector
	int lowestTemp(); //returns the lowest value found in the vector
	int highestTemp(); //returns the highest value found in the vector
	



private:
	//stores month and year in string variables
	std::string month;
	std::string year;

	//vector that can contain a list of temperatures of an integer value
	std::vector<int>tempList;
};