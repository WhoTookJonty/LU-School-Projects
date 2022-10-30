//Jonathan Wilson
//CSIS 112-002
//Lab8-Animal Polymorphism
//This program dynamically creates objects derived from the base class of Animal
//Citation: 
#include <iostream>
#include <iomanip>
#include <string>
#include "Dog.h"
#include "Fish.h"
#include "Rabbit.h"
#include "Snake.h"
#include "Animal.h"

using namespace std;

int main()
{
	srand(100); //seeds rand with 100
	int finalChoice; //used in the switch statement
	double choice; //user passes in number from menu to this variable first
	string name; //name of animal
	int age; //stores randomely generated age between 1-20
	Animal** animals = new Animal *[5]; //dynamic array of object type Animal


	for (size_t i = 0; i < 5; i++) //Loops through program 5 times - creates 5 animal objects
	{


		//Main Menu
		cout << "\t\t\t"   << "Main Menu" << endl;
		cout << "\t\t\t"  << "1 - Dog" << endl;
		cout << "\t\t\t" << "2 - Rabbit" << endl;
		cout << "\t\t\t" << "3 - Fish" << endl;
		cout << "\t\t\t"  << "4 - Snake" << endl;
		cout << "\t\t\t"  << "Enter a Selection: ";
		cin >> choice;
		while (cin.fail() || choice < 1 || choice > 4 || floor(choice) != choice) { //ERROR CHECKING FOR THE ABOVE VARIABLE -- Loops if cin enters a fail state or cin is less than 1 or greater than 4 or is a decimal
				
			cout << "Please enter an integer from the menu above: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> choice;
		}

		finalChoice = choice; //Fixes issue where the user might input a decimal which causes the program to skip name selection

		cout << "\t\t\t" << "Enter a name: "; //Enter animal name
		cin >> name;
		cout << "\n";
		age = rand() % 20 + 1; //random age between 1 and 20

		switch (finalChoice) //Switch statement for menu selection
		{
		case 1:
		{
			animals[i] = new Dog (age, name); //Dog object
				break;
		}
		case 2:
		{
			animals[i] = new Rabbit(age, name); //Rabbit object
			break;
		}
		case 3:
		{
			animals[i] = new Fish(age, name); //Fish object
			break;
		}
		case 4:
		{
			animals[i] = new Snake(age, name); //Snake object
			break;
		}
		default:
		{
			cout << "Invalid selection" << endl; //Default selection
			break;
		}
		}

		
	}
	
	for (size_t i = 0; i < 5; ++i) //Loops through animals array and returns name, age, and the Move() function of each object
	{
		cout << "My name is " << animals[i]->getName() << " and I am " << animals[i]->getAge() << " years old" << "\n";
		animals[i]->Move();
		cout << endl;
	}

	for (size_t i = 0; i < 5; ++i)
	{
		delete animals[i]; //de-allocates memory in animals
	}

	delete[] animals; //de-allocates animals
	animals = NULL;   //Sets memory to NULL

	system("pause");
	return 0;
}

