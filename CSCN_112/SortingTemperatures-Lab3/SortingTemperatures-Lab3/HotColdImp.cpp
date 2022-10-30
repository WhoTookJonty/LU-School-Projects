
#include "HotCold.h" //includes functions from header file
#include <iostream>
#include <vector>


//Constructor
Temperature::Temperature(std::string inputMonth, std::string inputYear) {
	setMonth(inputMonth);
	setYear(inputYear);
}

//Setters and Getters
void Temperature::setYear(std::string inputYear) { //sets value of year to passed in value
	year = inputYear;
}

std::string Temperature::getYear() const { //returns value of year
	return year;
}

void Temperature::setMonth(std::string inputMonth) { //sets value of month to passed in value
	month = inputMonth;

}

std::string Temperature::getMonth() const { //returns value of month
	return month;
}

std::vector<int>&Temperature:: getVector() { //sets value of year to passed in value
	return tempList;
}

 void Temperature::setVector(int temperature) { //adds value passed in to the end of the vector
	tempList.push_back(temperature);
	
}


//-------------------------------------------- Functions manipulating vector 'tempList' -----------------------------------------------

void Temperature::AddFunction(int temperature) { //Add value passed in onto the end of the vector 
	setVector(temperature);
}


void Temperature::sortVector() { //sort the temperatures stored in the vector by ascending order

	sort(getVector().begin(), getVector().end());
}

void Temperature::displayVector() { //prints out the value in each position of the vector
	
	for (const auto& i : getVector())
		std::cout << i << ' ' << std::endl;
}

double Temperature::tempAverage() { //calculates the average of every value contained in the vector
	double average = 0;
	for (size_t i = 0; i < returnListSize(); i++)
	{
		average += getVector().at(i); //adds all values in vector together
	}
	average = average / getVector().size(); //calculates average by dividing by how many elements are in the vector

	return average;
}

int Temperature::returnListSize() { //returns the size of the vector
		
	return getVector().size();
}

int Temperature::lowestTemp() { //returns the lowest value found in the vector
	

	int low = getVector().at(0);

	for (size_t i = 0; i < returnListSize(); i++)
	{
		if (low > getVector().at(i)) { //if the next value in vector is less than current value, replace the current value
			low = getVector().at(i);
		}
	}
	return low;
}

int Temperature::highestTemp() { //returns the highest value found in the vector
	int high = getVector().at(0);

	for (size_t i = 0; i < returnListSize(); i++)
	{
		if (high < getVector().at(i)) { //if the next value in vector is greater than the current value, replace the current value
			high = getVector().at(i);
		}
	}
	return high;
}

