//Implementation for Word.h

#include "Word.h"
#include <iostream>


Word::Word() {} //constructor


Word::Word(char* wordFromArray) { //constructor that contains a function to the set the word for the object.
	setWord(ConvertToLowerCase(wordFromArray));
}
Word::~Word() {} //destructor

void Word::setWord(char* w) { //sets the name of the word
	word = w;
}

char* Word::getWord() const{ //returns the name of word
	return word;
}

void Word::setFrequency() //increments frequency of word by 1
{
    frequency+=1;
}

int Word::getFrequency() const{ //returns the value of frequency
	return frequency;
}

char* Word::ConvertToLowerCase(char *w) { //Converts the value in w to a lower case version and returns it
    
	char* storage = w; //pointer copys the value in w
	
	for (size_t i = 0; w[i] != '\0'; i++) //while the character in w is not NULL, then keep incrementing the loop
	{
		storage[i] = towlower(w[i]); //changes each character in w lower case
	}

	return storage;
}

