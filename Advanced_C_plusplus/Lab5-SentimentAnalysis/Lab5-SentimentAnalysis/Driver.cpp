//Jonathan Wilson
//CSIS 112-002
//Lab5-SentimentAnalysis
//This program takes text from a file and performs sentiment anaylsis in a limited form where only the frequency of the word is recorded
//Citations: :  https://msdn.microsoft.com/en-us/library/ftsafwz3.aspx

#include "Review.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    string fileName; 
    fstream myFile; 
    Review review; 
    char sentence[1000]; 
    string outPut; //will contain text from file
   
    char seps[] = ",. "; 

    char* token = NULL;
    char* next_token = NULL;

   

    cout << "Enter filename: " << endl; //gets file name from user
    getline(cin, fileName);
    cout << "\n\n\n";

    myFile.open(fileName);


    while (!myFile) { //if the file fails to open keep prompting user for a file name

        cout << "Unable to open file, please try again with a valid file name, or check if file is in the correct location." << endl; //error message

        cout << endl << "Please enter your filename: "; //requests another filename in case user incorrectly spelt the name
        cin >> fileName;

        myFile.open(fileName); //attempts to open file
    }

   
    while (getline(myFile, outPut)) { //Loops through the file text and stores it in the variable outPut
        cout << outPut; //prints out the full text
        strcpy_s(sentence, outPut.c_str()); //this function converts the value in outPut to a character arry, which is then added to the sentence array
    }

    myFile.close(); //close file

    cout << "\n\n\n"; //creates spacing between main text and stats 

    token = NULL;
    next_token = NULL;
    token = strtok_s(sentence, seps, &next_token);

    while (token != NULL) { //This loop sorts through the text, takes out certain characters that are not words, and adds each word from the text to a 
                            // Word object that is contained in a vector

        if (token!= NULL) {
       
            review.addWord(token); //adds name of word to vector array
            token = strtok_s(NULL, seps, &next_token); //token is set to the next word in line
        }
    }

    review.printWords(); //prints out values contained in the vector array
    
    system("pause");
    return 0;
    
}




