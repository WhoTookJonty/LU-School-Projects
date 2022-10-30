//Jonathan Wilson
//CSIS 112-002
//CircleDriver.cpp
//This program calulates the Cirumference and Area of a circle using an inputted radius.
//Citations:

#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
   
    float newRadius = 0;
    Circle circle{};

    //Begin loop to calculate Circumference and Area of circle until exited by user
    while (newRadius != -1) {
        cout << "Enter the radius OR enter -1 to exit the program" << endl;
        cin >> newRadius;

        //check if user wants to exit
        if (newRadius == -1) {
            cout << "Exiting the program" << endl;
            system("pause");
            return 0;
        }
        //checks input for wrong data set or if cin had failed
        while (cin.fail() || newRadius < 0) {

            //Checks if user wants to exit
            if (newRadius == -1) {
                cout << "Exiting the program" << endl;
                system("pause");
                return 0;
            }
            cout << "Please enter a positive integer OR -1 to exit the program" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> newRadius;
        }


        //prints out the result of Circumference and Area calculations
        circle.setRadius(newRadius);
        circle.showData();
        cout << endl;
        cout << endl;
    }
    //allow a pause before the program exits
    system("pause");
    return 0;
}

