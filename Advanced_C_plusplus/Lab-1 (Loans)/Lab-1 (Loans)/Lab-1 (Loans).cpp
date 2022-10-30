//Jonathan Wilson
//CSIS 112-002
//Lab-1 (Loans).cpp
//This program generates random interest rates based on how good a customer's credit score is when they request a loan.
//Citations:


#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>


using namespace std;

//Calculates monthly payments using the formula for fixed interest loan. 
double CalcPayment(double principal, double interestRate, double loanTerm) {
    double endAmount = 0;

   
    interestRate = (interestRate / 12)/100;
    loanTerm = loanTerm * 12;


    endAmount = principal * (interestRate * pow(1 + interestRate, loanTerm) / (pow (1 + interestRate, loanTerm) - 1));
   
    return endAmount;
}

int main()
{

    //initializing variables
    double principalLoan;
    double interestRate;
    double endAmount;

    int creditScore;
    int loanTerm;

    enum creditRating { Bad, Fair, Good, Excellent };
    creditRating credRating;

    srand(time(0));
  
    //Begin user dialogue
    cout << "Enter the amount for the loan you want" << endl;

    cin >> principalLoan;

    //Catch potential errors from the user
    while (cin.fail() || principalLoan < 0 || principalLoan > INT_MAX) {
        cout << "Please enter a positive number that is below the value of 2147483647 and try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> principalLoan;
    }

    cout << "Enter your credit score (between 300 and 850)" << endl;

    cin >> creditScore;

    //contains a statement that, if the credit score is below 300, then the program
    //exits with the return value 0.
    while (cin.fail() || creditScore < 300 || creditScore > 850) {

        if (creditScore < 300) {
            cout << "A loan cannot be offered due to the atrocious credit score, the program will now exit." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("pause");
            return 0;
        }
        else {
            cout << "Please enter a positive number that is less than or equal to 850 while being above or equal to 300 and try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin >> creditScore;
    }


    cout << "Enter preffered the term for your loan, accepted values are listed below: \n 1. 10 years \n 2. 15 years \n 3. 30 years" << endl;

    cin >> loanTerm;

    while (cin.fail() || loanTerm != 10 && loanTerm != 15 && loanTerm != 30) {
        cout << "Please enter a loan term of either 10, 15, or 30 years and try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> loanTerm;
    }

    //Checks customer's credit score to determine it's future interest rate.
    if (creditScore >= 720 && creditScore <= 850) {
        credRating = Excellent;
    }
    else if (creditScore >= 690 && creditScore <= 719) {
        credRating = Good;
    }
    else if (creditScore >= 630 && creditScore <= 689) {
        credRating = Fair;
    }
    else if (creditScore >= 300 && creditScore <= 629) {
        credRating = Bad;
    }

    //Assigns interest rate based on customer's credit score
    switch (credRating) {
    case 0:
        cout << "Bad credit score " << endl;
        interestRate = (rand() % (176 + 1) + (876));
        interestRate /= 100;
        cout << interestRate << endl;


        break;

    case 1:
        cout << "Fair credit score" << endl;
        interestRate = (rand() % (224 + 1) + (651));
        interestRate /= 100;
        cout << interestRate << endl;

        break;

    case 2:
        cout << "Good credit score" << endl;
        interestRate = (rand() % (249 + 1) + (401));
        interestRate /= 100;
        cout << interestRate << endl;

        break;

    case 3:
        cout << "Excellent credit score" << endl;
        interestRate = (rand() % (125 + 1) + (275));
        interestRate /= 100;
        cout << interestRate << endl;

        break;

    }
 

    //Prints out to the console the customer's annual monthly payments of interest for the loan.
    endAmount = CalcPayment(principalLoan, interestRate, loanTerm);

    cout << fixed << showpoint << setprecision(2);
    cout << "your monthly payment amounts to: $" << endAmount << endl;



    system("pause");
    return 0;
}

 