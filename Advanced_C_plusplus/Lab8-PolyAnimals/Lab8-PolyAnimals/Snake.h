//Snake.h
//I didnt know if you wanted us to split header files into imp files? I didnt see it in the rubric
#pragma once
#include "Animal.h"

class Snake : public Animal{ //Inherits from Animal
public :
	Snake() //Constructor
	{
		std::cout << "In the Snake default constructor" << std::endl;
	}
	Snake(int a, std::string n) : Animal(a, n)//2-arg constructor to initliaze age and name variables for this object
	{
		std::cout << "In 2-argument Snake construtor" << "\n\n";
	}
	~Snake()//Destructor
	{
		std::cout << "In the default Snake destructor" << std::endl;
	}

	void Move()//Move function that implements the virtual version in Animal.h
	{
		std::cout << "I slither" << std::endl;
	}

};