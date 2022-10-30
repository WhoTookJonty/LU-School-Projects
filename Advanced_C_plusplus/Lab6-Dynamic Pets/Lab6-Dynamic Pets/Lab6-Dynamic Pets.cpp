//Jonathan Wilson
//CSIS 112-002
//Lab6- Dynamic pets
//This program creates objects using dynamic array allocation and prints out their values to the counsel
//Citations:

#include <iostream>
#include <string>
#include "Pet.h"

using namespace std;
int main()
{
    int numberOfPets;
    string petName;
    string typePet;

    cout << "How many pets do you have:" << endl;
    cin >> numberOfPets;

    Pet** pets = new Pet *[numberOfPets]; //Creates a dynamic array whose size is set to the numberOfPets variable


    for (size_t i = 0; i < numberOfPets; ++i) //This loop requests the user's input and assigns those values to a dynamic array of objects of the Pet class 
    {
        cout << "What is the name of your pet" << endl;
        cin >> petName;
  
        cout << "What type of pet is " << petName << "?" << endl;
        cin >> typePet;
  
       pets[i] = new Pet(); //creates object of the Pet class
       cout << endl;

       pets[i]->setType(typePet); 
       pets[i]->setName(petName);
       pets[i]->setWeight(rand() % 100 + 1); //creates weight using a random number generator from 1-100
    }

    cout << "These are the pets you have: " << endl;
    for (size_t i = 0; i < numberOfPets; i++)
    {

        pets[i]->printPet(); //calls the print function in the Pets class
        cout << endl;
    }


    for (size_t i = 0; i < numberOfPets; ++i)
    {
        delete pets[i]; //de-allocates memory in pets
    }

    delete[] pets; //de-allocates pets
    pets = NULL;   //Sets memory to NULL

    system("pause");
    return 0;

}


