//Jonathan Wilson
//CSIS 112-002
//SortingTemperatures-Lab3.cpp
//This program reads in temperatures from a user-specified file and displays them to the user
//Citations:


#include <string>
#include <iostream>
//allows writing to files
#include <fstream>
//includes functions from HotCold.h header file.
#include "HotCold.h"

using namespace std;

int main()
{
    int temperature; //stores temperature values read in from the file
 
    string fileName; //stores the value of the user's file they want to be read
    string output; //stores each line from the file being read
    ifstream myFile; //object name of the file being read in

  
    Temperature list{"default", "default"};  //Creation of the vector object 'list' with placeholder values

    cout << "Please enter your filename: "; //gets user's file name
    cin >> fileName;
   
    myFile.open(fileName); //attempts to open file 
   
    while (!myFile) { //if the file fails to open

        cout << "Unable to open file, please try again with a valid file name, or check if file is in the correct location." << endl; //error message

        cout << endl << "Please enter your filename: "; //requests another filename in case user incorrectly spelt the name
        cin >> fileName;

        myFile.open(fileName); //attempts to open file
    }
  
    int i = 0; //counter
    while (getline(myFile, output)) {

        if (i == 0) { //allows month and year to be set to the first two variables and not be assigned values for the rest of the loop
            list.setMonth(output);
            getline(myFile, output);
            list.setYear(output);
            i++; 
        }

        myFile >> temperature; //read in temperature
        if (temperature > 0 || temperature < 0) { //check if it value being read in is a numeric value
            list.AddFunction(temperature);
        }
        else { //exits program if non-numeric value is found
            cout << "Non-numeric value found, please correct the problem and restart." << endl << endl <<  "Now exiting the program...." << endl;
            system("pause");
            return 0;
        }
    }
   
    
    list.sortVector(); //sort the temperatures stored in the vector by ascending order

    //Prints out results of each function call
    cout << endl << "Statistics" << endl;
    cout << "Average:\t\t\t" << list.tempAverage() << endl; //displays average of all values in vector
    cout << "Lowest temperature:\t\t" << list.lowestTemp() << endl; //displays lowest temperature in vector
    cout << "Highest temperature:\t\t" << list.highestTemp() << endl; //displays highest temperature in vector

    //Displays all values contained in the vector in thier current positions
    cout << endl <<  "The temperatures for " << list.getMonth() << ' ' << list.getYear() << " are:" << endl;
    list.displayVector();

    
}

