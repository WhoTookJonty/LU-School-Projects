//Jonathan Wilson
//CSIS 112-002
//Lab6- Dynamic pets
/*
This program allows allow the financial advisor to maintain the portfolios for his/her clients. This includes purchasing Stocks and Bonds. 
*/
//Citations:

#include <iostream>
#include <string>
#include <iomanip>
#include "Portfolio.h"
#include "Date.h"

using namespace std;



void tokenizeDate(char* cDate, int& month, int& day, int& year) //Tokenizes the dates passed in by user
{
    char seps[] = "/";
    char* token = NULL;
    char* next_token = NULL;

    token = NULL;
    next_token = NULL;

    // Establish string and get the tokens:  
    token = strtok_s(cDate, seps, &next_token);
    month = atoi(token);

    token = strtok_s(NULL, seps, &next_token);
    day = atoi(token);

    token = strtok_s(NULL, seps, &next_token);
    year = atoi(token);
}

Date configureDate() //function that uses tokenizeDate
{
    int m, d, y;
    char charDate[20]; //holds the date the user entered in char array
    Date realDate;  //date object; holds date after tokenization	
 
    std::cin >> charDate;

    tokenizeDate(charDate, m, d, y); //separates char array into month, day, and year
    realDate.setDate(d, m, y); //sets the date of the object using the parsed values
    return realDate;
}

int main()
{
    char choice;
    string clientName;


    //Shared variables between Stock and Bond:
    double purchasePrice;
    int quantity;
    //**************

    //Stock Variables:
    string ticker;
    int parValue;
    char stockType;
    double dividends;
    //****************

    //Bond Variables:
    string issuer;
    double faceValue;
    double interestRate;
    //******************


    cout << "\t" << "Enter a name for your portfolio: ";
    getline(cin, clientName);

    Portfolio porty(clientName); //creates portfolio object

    do {
        //Formats menu
        cout << "\n\n";
        cout << "\t\t" << right << setw(15) << "Main menu" << endl;
        cout << "\t\t" << left << setw(20) << "S -- Purchase stock" << endl;
        cout << "\t\t" << left << setw(20) << "B -- Purchase bond" << endl;
        cout << "\t\t" << left << setw(20) << "L -- List portfolio securities" << endl;
        cout << "\t\t" << left << setw(20) << "Q -- Quit" << endl;

        cout << "\n";
        cout << "\t\t" << "Selection: ";
        cin >> choice; //user's menu choice
        cout << "\n";

        Date purchaseDate; //date object for purchase date
        Date maturityDate; //date object for maturity date

        switch (choice) 
        {
        case's':
        case'S':

            cout << "\t\t" << "Purchase Stocks" << "\n\n";

            cout << "Purchase date (mm/dd/yyyy): ";
            purchaseDate = configureDate();
            cout << "\n";
            cout << "Total purchase price: ";
            cin >> purchasePrice;  //Sets purchase price

            while (cin.fail() || purchasePrice < INT_MIN || purchasePrice > INT_MAX) { //ERROR CHECKING FOR THE ABOVE VARIABLE -- Loops if cin enters a fail state or 
                                                                                       //purchase price is above or below the integer limit of c++
                                                                                       //THIS ERROR CHECKING CODE IS COPIED IN MULTIPLE CASES
                cout << "Please enter an integer that is below the value of 2147483647 and above the value -2147483647 and try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> purchasePrice;
            }
            
            cout << "\n";
            cout << "Quantity purchased: ";
            cin >> quantity; //sets quantity
            cin.ignore();

            while (cin.fail() || quantity < INT_MIN || quantity > INT_MAX) {//ERROR CHECKING FOR THE ABOVE VARIABLE
                cout << "Please enter an integer that is below the value of 2147483647 and above the value -2147483647 and try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> quantity;
                cin.ignore();
            }
            cout << "\n";
            cout << "Ticker symbol: ";
            getline(cin, ticker); //Sets ticker symbol

            cout << "\n";
            cout << "Par value: ";
            cin >> parValue; //Sets par value

            while (cin.fail() || parValue< INT_MIN || parValue > INT_MAX) {//ERROR CHECKING FOR THE ABOVE VARIABLE
                cout << "Please enter an integer that is below the value of 2147483647 and above the value -2147483647 and try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> purchasePrice;
            }
            cout << "\n";
            cout << "Stock type (C for Common or P for Preferred): ";
            cin >> stockType; //sets stocktype

            while (stockType != 'C' && stockType != 'c' && stockType != 'P' && stockType != 'p') //ERROR CHECKING FOR THE ABOVE VARIABLE
            {
                cout << "Please enter either a C for Common or P for Preferred stock type: ";
                cin >> stockType;
            }
            cout << "\n";
            cout << "Dividends per share: ";
            cin >> dividends; //sets dividends

            while (cin.fail() || dividends < INT_MIN || dividends > INT_MAX) { //ERROR CHECKING FOR THE ABOVE VARIABLE
                cout << "Please enter an integer that is below the value of 2147483647 and above the value -2147483647 and try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> dividends;
            }



            porty.purchaseStock(purchaseDate, purchasePrice, quantity, ticker, parValue, stockType, dividends); //Sets object variable's to the values passed in by user in the above case statement
            break;

        case'b':
        case'B':
            cout << "\t\t" << "Purchase Bonds" << "\n\n";

            cout << "Purchase date (mm/dd/yyyy): ";
            purchaseDate = configureDate(); 

            cout << "\n";
            cout << "Total purchase price: ";
            cin >> purchasePrice;

            while (cin.fail() || purchasePrice < INT_MIN || purchasePrice > INT_MAX) { //ERROR CHECKING FOR THE ABOVE VARIABLE
                cout << "Please enter an integer that is below the value of 2147483647 and above the value -2147483647 and try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> purchasePrice;
            }

            cout << "\n";
            cout << "Quantity purchased: ";
            cin >> quantity;
            cin.ignore();
            while (cin.fail() || quantity < INT_MIN || quantity > INT_MAX) { //ERROR CHECKING FOR THE ABOVE VARIABLE
                cout << "Please enter an integer that is below the value of 2147483647 and above the value -2147483647 and try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> quantity;
                cin.ignore();
            }

            cout << "\n";
            cout << "Issuer: ";
            getline(cin, issuer);

            cout << "\n";
            cout << "Face value: ";
            cin >> faceValue;
            while (cin.fail() || faceValue < INT_MIN || faceValue> INT_MAX) { //ERROR CHECKING FOR THE ABOVE VARIABLE
                cout << "Please enter an integer that is below the value of 2147483647 and above the value -2147483647 and try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> faceValue;
            }

            cout << "\n";
            cout << "Stated interest rate: ";
            cin >> interestRate; 
            while (cin.fail() || interestRate < INT_MIN || interestRate > INT_MAX) { //ERROR CHECKING FOR THE ABOVE VARIABLE
                cout << "Please enter an integer that is below the value of 2147483647 and above the value -2147483647 and try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> interestRate;
            }
            
            cout << "\n";
            cout << "Maturity date (mm/dd/yyyy): ";
            maturityDate = configureDate();

            porty.purchaseBond(purchaseDate, purchasePrice, quantity, issuer, faceValue, interestRate, maturityDate); //Sets object variable's to the values passed in by user in the above case statement
            break;

        case'l':
        case'L':
            porty.listPortfolio(); //prints out a list of the object's variables stored in the portfolio object's vectors
            break;
        case'q':
        case'Q':
            cout << "Exiting...." << endl; //Exits out of the loop with a pause for the user to hit enter
            cin.ignore();
           
            break;
        default:
            cout << "Invalid selection, please try again" << endl; //If an unrecognised variable is entered by the user then it loops back to the menu
            break;
        }

    } while (choice != 'Q' && choice != 'q'); //Loops while the user has not chosen to quit
    
    cout << "Press enter to continue..." << endl; //Pauses the program before it exits
    cin.ignore();
    return 0;
}
