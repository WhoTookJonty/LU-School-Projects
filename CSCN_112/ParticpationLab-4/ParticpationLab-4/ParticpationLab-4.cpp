// ParticpationLab-4.cpp 
//

#include <iostream>
#include "NegativeNumberException.h"
using namespace std;

int negativeTest(int number) {

    if (number < 0) {
        throw NegativeNumEx{};
    }

    return static_cast<int>(number);
}

int main()
{
    int number = 0;


    cout << "enter a nonnegative integer: ";

    while (cin >> number){

    try {
        int result{ negativeTest(number) };
        cout << "The number is: " << result << endl;
        break;
    }
    catch (exception & e)
    {
        cout << "Exception occurred: " << e.what() << endl;
    }

    cout << "\nEnter a nonnegative integer: ";

}

    cout << endl;
    system("pause");
    return 0;
}





