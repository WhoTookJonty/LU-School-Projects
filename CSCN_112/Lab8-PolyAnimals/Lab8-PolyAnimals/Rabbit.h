//Rabbit.h
//I didnt know if you wanted us to split header files into imp files? I didnt see it in the rubric
#pragma once
#include "Animal.h"

class Rabbit : public Animal { //Inherits from Animal
public:
	Rabbit() //Constructor
	{
		std::cout << "In the Rabit default constructor" << std::endl;
	}
	Rabbit(int a, std::string n) : Animal(a, n)//2-arg constructor to initliaze age and name variables for this object
	{
		std::cout << "In 2-argument Rabbit construtor" << "\n\n";
	}
	~Rabbit()//Destructor
	{
		std::cout << "In the default Rabbit destructor" << std::endl;
	}
	
	void Move()//Move function that implements the virtual version in Animal.h
	{
		std::cout << "I hop" << std::endl;
	}

};