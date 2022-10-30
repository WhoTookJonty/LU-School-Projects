//Review implementation file for Review.h

#include "Review.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Review::Review() {} //constructor
Review::~Review() {} //destructor

void Review::addWord(char* token) { //Adds word object to vector by parsing in a pointer
	
	Word w(token);
	bool exists = false; //variable checks if word already exists

	for (size_t i = 0; i < getWordsVector().size(); i++)
	{
		if (strcmp(w.getWord(),getWordsVector().at(i).getWord()) == 0) {
			exists = true; 
			wordsVector[i].setFrequency(); //if word already exsts then increase frequency of that word.
		}
	}

	if (exists == false) { //if the word does not already exist then add the word to the vector
		setWordsVector(w);

	}

	
}


void Review::printWords() { //prints out the name of the word and frequency of that word per object contained in the vector. 

	for (size_t i = 0; i < getWordsVector().size(); i++) //loops through the vector
	{
		
		cout << "\t\t" << right << setw(25) << getWordsVector().at(i).getWord();
		 cout << "\t\t" << getWordsVector().at(i).getFrequency() << endl; //the tabs format the frequency and words so that they are seperated
	}
}

std::vector<Word> Review::getWordsVector() const{ //return vector that contains Word objects
	return wordsVector;
}

void Review::setWordsVector(Word w) { //Add Word object to vector
	wordsVector.push_back(w);
	
}
