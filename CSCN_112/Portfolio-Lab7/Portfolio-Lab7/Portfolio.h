//Portfolio header file
#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Stock.h"
#include "Bonds.h"


class Portfolio {
public:
	Portfolio(std::string n) //one argument constructor to set client name
	{
		clientName = n;
	}
	
	~Portfolio(){} //Destructor

	void purchaseStock(Date purchaseDate, double purchasePrice, int quantity, std::string ticker, int parValue, char st, double dividends) //Takes user passed values and sets a newly created object's variables to those values
	{
		Stocks stock;

		stock.setPurchaseDate(purchaseDate);
		stock.setPurchasePrice(purchasePrice);
		stock.setQuantity(quantity);
		stock.setTicker(ticker);
		stock.setParValue(parValue);
		stock.setStockType(st);
		stock.setDividends(dividends);

		stockList.push_back(stock); //Places object in a vector

	}

	void purchaseBond (Date purchaseDate, double purchasePrice, int quantity, std::string issuer, double faceValue, double interestRate, Date maturityDate) //Takes user passed values and sets a newly created object's variables to those values
	{
		Bonds bond;
		
		bond.setPurchaseDate(purchaseDate);
		bond.setPurchasePrice(purchasePrice);
		bond.setQuantity(quantity);
		bond.setIssuer(issuer);
		bond.setFaceValue(faceValue);
		bond.setInterestRate(interestRate);
		bond.setMaturity(maturityDate);
		
		bondList.push_back(bond); //Places object in a vector

	}

	void listPortfolio() //Prints out vector's object's values
	{
		sortSecurities(); //Sorts vectors by their issuer for Bonds or ticker for Stocks


		std::cout << "These are the STOCKS in your " << getName() << " portfolio" << std::endl;
		for (size_t i = 0; i < stockList.size(); i++)
		{
			std::cout << stockList[i];
		}

		std::cout << "\n";

		std::cout << "These are the BONDS in your " << getName() << " portfolio" << std::endl;
		for (size_t i = 0; i < bondList.size(); i++)
		{
			std::cout << bondList[i];
		}
	}

	void sortSecurities() //Sorts vectors by their issuer for Bonds or ticker for Stocks
	{
		//Uses overloaded operator "<" in their respective classes to compare and sort
		sort(stockList.begin(), stockList.end()); 
		sort(bondList.begin(), bondList.end());
	}


	//*******Getters and Setters for private variables************
	std::string getName()
	{
		return clientName;
	}

	void setName(std::string s)
	{
		clientName = s;
	}
	//************************************************************

private:
	std::string clientName; //Stores client's name 
	std::vector<Stocks> stockList; //Creates vector of the object type Stocks
	std::vector<Bonds> bondList; //Creates vector of the object type Bonds
};


