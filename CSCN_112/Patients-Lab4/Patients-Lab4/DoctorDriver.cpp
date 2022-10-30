//Jonathan Wilson
//CSIS 112-002
//Lab-1 (Loans).cpp
//This program generates random interest rates based on how good a customer's credit score is when they request a loan.
//Citations:

#include <iostream>
#include <string>
#include "Doctor.h" //include Doctor Header file

using namespace std;

int main()
{
    string docName;//doctrs name
    char userChoice;//user's choice of menu list
    string patientName;//patients name
    int patientCounter = 0;//number of patients counter
    Doctor d{"Default"};//create object of Doctor class with a default name

    cout << "Enter the name of the doctor: ";
    getline(cin, docName);
    d.setDocName(docName);//set name of doctor

    do{//menu printout
    cout << "Would you like to..." << endl;
    cout << "(A) Add a patient" << endl;
    cout << "(L) List your patients" << endl;
    cout << "(Q) Quit" << endl;
    cin >> userChoice;

    
        switch (userChoice) {//menu selection results

        case 'A':
        case 'a':
            if (patientCounter == 3) { //check if user tries to add over 3 patients
                cout << "You can only add a maximum of 3 patients due to your terrible reputation as a doctor deterring thousands of potential customers" << endl;
                break;
            }
            cout << "Enter your patient's name" << endl;
            cin >> patientName;
            d.addPatient(patientName);
            patientCounter++;
            break;

        case 'L': //list all objects in patientList vector - providing details for each object using their functions
        case'l':
            d.printDocPatients();
            break;

        case 'Q'://quit program
        case 'q':
            return 0;
            break;

        default://print out error if a selection is made that is not a choice
            cout << "Invalid selection" << endl;
            break;

        }
    } while (userChoice != 'Q' && userChoice != 'q'); //while Q is not selected, keep looping so that the doctor can continue to use the program

}

