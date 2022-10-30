//Date header file
#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>
class Date {
	friend std::ostream& operator<<(std::ostream&, Date);
public:
	Date(int d = 0, int m = 0, int yyyy = 0) { //Date constructor
		setDate(d, m, yyyy);
	}
	~Date() {} //Destructor

	void setDate(int  d, int m, int yyyy) { //Sets date variables to user passed values
		day = d;
		month = m;
		year = yyyy;
	}

	//Getters and Setters for variables
	int getDay() 
	{
		return day;
	}

	int getMonth()
	{
		return month;
	}
	
	int getYear()
	{
		return year;
	}

private:
	int day;
	int month;
	int year;
};
std::ostream& operator<<(std::ostream& output, Date d) { //Overloaded operator for the Date class object
	output << d.month << "/" << d.day << "/" << d.year;
	return output;
}
