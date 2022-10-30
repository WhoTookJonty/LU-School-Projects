//Stocks header file
#pragma once
#include <iostream>
#include <iomanip>
#include "Security.h"


class Stocks :public Security { //Inherits from Security base class

	friend std::ostream& operator<<(std::ostream& output, Stocks& r); //Friend function to overload the ostream operator "<<"
public:

	Stocks(){} //Constructor
	~Stocks(){} //Destructor

	

	double calcIncome() { //Calculates income for Stocks
		double income;

		income = getDividends() * getQuantity();

		return income;
	}

	bool operator<(Stocks& s) //overloads the "<" operator to allow the Stocks vector in Portfolio.h to be sorted
	{
		return (this->getTicker().compare(s.getTicker()) < 0) ? true : false;
	}

	enum StockType { COMMON, PREFERRED }; //Creates an enum for whether a stock is common or preferred

	void setStockType(char c)  //Sets the stocktype using characters 
	{
		if (c == 'C' || c == 'c')

			st = COMMON;
		else
			st = PREFERRED;
	}

	
	std::string getStockType() //Returns the stock type
	{
		std::string returnStr;
		if (st == COMMON)
			returnStr = "Common";
		else
			returnStr = "Preferred";

		return returnStr;
	}

	//****************Getters and Setters for private variables **************
	std::string getTicker()
	{
		return ticker;
	}

	void setTicker(std::string s)
	{
		ticker = s;
	}

	int getParValue()
	{
		return parValue;
	}

	void setParValue(int i)
	{
		parValue = i;
	}

	double getDividends()
	{
		return dividends;
	}

	void setDividends(double d)
	{
		dividends = d;
	}
	//**********************************************************************
private:
	
	StockType st{ COMMON }; //enum for stock type
	std::string ticker; //stores the name of the ticker
	int parValue; //stores par value
	double dividends; //stores dividends value
};
std::ostream& operator<<(std::ostream& output, Stocks& r) //Overloaded operator "<<" that outputs a formatted version of the value stored in a Stock object
														//Uses iomanip library for formatting
{
	output << std::left << std::setw(20) << "Ticker symbol: " << "\t" << r.getTicker() << std::endl;
	output << std::left << std::setw(20) << "Purchase date: " << "\t" << r.getPurchaseDate() << std::endl;
	output << std::left << std::setw(20) << "Total purchase price: " << "\t" << r.getPurchasePrice() << std::endl;
	output << std::left << std::setw(20) << "Quantity: " << "\t" << r.getQuantity();
	output << "\t\t" << std::left << std::setw(20) << "Price per share: " << "\t" << r.getPurchasePrice() / r.getQuantity() << std::endl;
	output << std::left << std::setw(20) << "Par value: " << "\t" << r.getParValue();
	output << "\t\t" << std::left << std::setw(20) << "Type: " << "\t" << r.getStockType() << std::endl;
	output << std::left << std::setw(20) << "Dividends per share: " << "\t" << r.getDividends() << std::endl;
	output << std::left << std::setw(20) << "Dividend Income: " << "\t" << r.calcIncome() << std::endl;
	output << "\n\n";

	return output;
}
