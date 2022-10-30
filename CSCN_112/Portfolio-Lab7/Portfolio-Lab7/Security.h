//Security header file
#pragma once
#include "Date.h";

class Security {
public:

	Security() {} //Constructor
	~Security(){}//Destructor

	//Getters and Settrs for private variables
	double getPurchasePrice()
	{
		return price;
	}

	void setPurchasePrice(double p)
	{
		price = p;
	}

	int getQuantity()
	{
		return quantity;
	}

	void setQuantity(int amount)
	{
		quantity = amount;
	}
	
	void setPurchaseDate(Date d)
	{
		purchaseDate.setDate(d.getDay(), d.getMonth(), d.getYear()); //Uses setDate function from Date class to add day month and year to Date object.
	}

	Date getPurchaseDate()
	{
		return purchaseDate;
	}



private:
	Date purchaseDate; //stores date of purchase
	double price; //stores purchase price
	int quantity; //stores purchase quantity
};