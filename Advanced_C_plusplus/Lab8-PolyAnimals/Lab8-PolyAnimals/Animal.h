//Animal.h 
//I didnt know if you wanted us to split header files into imp files? I didnt see it in the rubric
#pragma once
#include <iostream>


class Animal {
public:
	Animal()  //Constructor
	{
		std::cout << "In the Animal default constructor" << std::endl;
	}
	Animal(int a, std::string n)//2-arg constructor to initliaze age and name variables for this object
	{
		std::cout << "In 2-argument Animal construtor" << std::endl;
		setName(n);
		setAge(a);
	}
	virtual ~Animal() //Virtual destructor
	{
		std::cout << "In the default Animal destructor" << std::endl;
	}

	virtual void Move() = 0; //Virtual function Move(). this is implemented in the derived classes

	void setName(std::string n) //Sets the variable name
	{
		name = n;
	}

	std::string getName() //returns the variable name
	{
		return name;
	}

	void setAge(int a) //Sets the variable age
	{
		age = a;
	}
	int getAge() //Returns the variable age
	{
		return age;
	}

private:
	std::string name; //Stores name of animal
	int age; //Stores age of animal
};