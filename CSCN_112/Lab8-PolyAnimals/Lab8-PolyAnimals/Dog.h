//Dog.h
//I didnt know if you wanted us to split header files into imp files? I didnt see it in the rubric
#pragma once
#include "Animal.h"

class Dog : public Animal { //Inherits from Animal
public:
	Dog() //Constructor
	{
		std::cout << "In the Dog default constructor" << std::endl;
	}
	Dog(int a, std::string n) : Animal(a, n)//2-arg constructor to initliaze age and name variables for this object 
											
	{
		std::cout << "In 2-argument Dog construtor" << "\n\n";
	}
	~Dog()//Destructor
	{
		std::cout << "In the default Dog destructor" << std::endl;
	}
	void Move()//Move function that implements the virtual version in Animal.h
	{
		std::cout << "I run" << std::endl;
	}

};