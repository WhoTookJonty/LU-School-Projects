//Bonds header file
#pragma once
#include <iostream>
#include <iomanip>
#include "Security.h"



class Bonds : public Security{ //Inherits from base class Security

	friend std::ostream& operator<<(std::ostream&, Bonds&); //Friend function overload the ostream operator "<<"

public:

	Bonds() {} //Constructor
	~Bonds(){} //Destructor

	double calcIncome() { //Calculates income of the Bond
		double income;

		income = getQuantity() * getFaceValue() * getInterestRate();

		return income;
	}



	bool operator<(Bonds& s) //overloads the "<" operator to allow the Bonds vector in Portfolio.h to be sorted
	{
		return (this->getIssuer().compare(s.getIssuer()) < 0) ? true : false;
	}

	//****************** Getters and Setters for private variables *****************************
	std::string getIssuer()
	{
		return issuer;
	}

	void setIssuer(std::string i)
	{
		issuer = i;
	}

	double getFaceValue()
	{
		return faceValue;
	}
	void setFaceValue(double f)
	{
		faceValue = f;
	}

	double getInterestRate()
	{
		return interestRate;
	}

	void setInterestRate(double i) 
	{
		interestRate = i;
	}

	Date getMaturity() {
		return maturity;
	}

	void setMaturity(Date d) 
	{
		maturity.setDate(d.getDay(), d.getMonth(), d.getYear()); //Uses set date function from Date class to set day month and year of the date object
	}

	//***************************************************************************************************


private:
	std::string issuer; //Stores name of issuer 
	double faceValue; //Stores face value
	double interestRate; //Stores interest rate
	Date maturity; //stores date of maturity of bond
};

std::ostream& operator<<(std::ostream& output, Bonds& r) //Overloaded operator "<<" that outputs a formatted version of the value stored in a Bond object
														//Uses iomanip library for formatting
{

	output << std::left << std::setw(20) << "Issuer: " << "\t" << r.getIssuer() << std::endl;
	output << std::left << std::setw(20) << "Purchase date: " << "\t" << r.getPurchaseDate() << std::endl;
	output << std::left << std::setw(20) << "Quantity: " << "\t" << r.getPurchasePrice() << std::endl;
	output << std::left << std::setw(20) << "Total purchase price: " << "\t" << r.getQuantity();
	output << "\t\t" << std::left << std::setw(20) << "Stated Interest Rate: " << "\t" << r.getInterestRate() * 100 << std::endl;
	output << std::left << std::setw(20) << "Interest Income: " << "\t" << r.calcIncome();
	output << "\t\t" << std::left << std::setw(20) << "Maturity date: " << "\t" << r.getMaturity() << std::endl;
	output << std::left << std::setw(20) << "Face value: " << "\t" << r.getFaceValue() << std::endl;
	output << "\n\n";
	
	return output;
}
