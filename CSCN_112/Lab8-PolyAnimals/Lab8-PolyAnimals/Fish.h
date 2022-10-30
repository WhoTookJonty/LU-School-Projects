//Fish.h
//I didnt know if you wanted us to split header files into imp files? I didnt see it in the rubric
#pragma once
#include "Animal.h"

class Fish : public Animal {  //Inherits from Animal
public:
	Fish() //Constructor
	{
		std::cout << "In the Fish default constructor" << std::endl;
	}
	Fish(int a, std::string n) : Animal(a, n) //2-arg constructor to initliaze age and name variables for this object
	{
		std::cout << "In 2-argument Fish construtor" << "\n\n";
	}
	~Fish() //Destructor
	{
		std::cout << "In the default Fish destructor" << std::endl;
	}
	void Move() //Move function that implements the virtual version in Animal.h
	{
		std::cout << "I swim" << std::endl;
	}

};
