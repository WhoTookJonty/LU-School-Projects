//Header file for Review

#pragma once
#include "Word.h"
#include <vector>

class Review {
public:
	Review(); //constructor
	~Review(); // destructor

	void addWord(char* token); //Adds word object to vector by parsing in a pointer

	std::vector<Word> getWordsVector()const; //return vector that contains Word objects
	void setWordsVector(Word); //Add Word object to vector

	void printWords(); //prints out the name of the word and frequency of that word per object contained in the vector. 


private:
	std::vector<Word> wordsVector; //creates vector that contains objects of the class Word
};