#pragma once
//Header file for Word

#include <iostream>

class Word {

public:
	Word(); //constructor
	Word(char*); //constructor that contains a function to the set the word for the object.
	~Word(); //destructor

	void setWord(char*); //sets the name of the word
	char* getWord() const; //returns the name of word
	void setFrequency(); //increments frequency of word by 1
	int getFrequency()const;  //returns the value of frequency
	

	char* ConvertToLowerCase(char*); //Converts the value in w to a lower case version and returns it

private:
	char* word; //pointer that will contain a word
	int frequency = 1; // sets the frequency to one because all words added will automatically have a frequency of 1

};