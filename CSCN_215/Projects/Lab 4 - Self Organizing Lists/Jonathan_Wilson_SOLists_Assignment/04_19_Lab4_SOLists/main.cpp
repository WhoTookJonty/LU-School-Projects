#include <iostream>
#include <string>
#include <fstream>
#include "CountSelfOrderedList.h"
#include "MTFSelfOrderedList.h"
#include "TransposeSelfOrderedList.h"

using namespace std;

int main()
{
	cout << "Jacob Greer and Jonathan Wilson - Lab 4 - Self-Ordered Lists \n\n";

	// Arrays of letters in lists to input into functions
	char forAdd[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	int aSize = 8;

	char forFind[] = { 'F', 'D', 'F', 'G', 'E', 'G', 'F', 'A', 'D', 'F', 'G', 'E', 'H', 'I' };
	int fSize = 14;

	// Output starting list
	cout << "Testing: chars" << endl;
	cout << "My starting list structure for all heuristics is:" << "\n\n ";
	for (int i = 0; i < aSize; ++i)
	{
		cout << forAdd[i] << "-0 ";
	}
	cout << "\n\n";

	// Count heuristic
	CountSelfOrderedList<char> count;
	for (int i = 0; i < aSize; ++i)
	{
		count.add(forAdd[i]);
	}
	for (int i = 0; i < fSize; ++i)
	{
		count.find(forFind[i]);
	}
	count.printlist();
	
	// Move to front
	MTFSelfOrderedList<char> move;
	for (int i = 0; i < aSize; ++i)
	{
		move.add(forAdd[i]);
	}
	for (int i = 0; i < fSize; ++i)
	{
		move.find(forFind[i]);
	}
	move.printlist();

	// Transpose
	TransposeSelfOrderedList<char> trans;
	for (int i = 0; i < aSize; ++i)
	{
		trans.add(forAdd[i]);
	}
	for (int i = 0; i < fSize; ++i)
	{
		trans.find(forFind[i]);
	}
	trans.printlist();

	// ---- String test ----
	cout << "Testing: strings" << endl;
	// Open file; exit if file is not present
	fstream input;
	input.open("test.txt");
	if (!input)
	{
		cout << "Error: test.txt not found.";
		exit;
	}

	// Initialize objects for string testing
	CountSelfOrderedList<string> countStr;
	MTFSelfOrderedList<string> moveStr;
	TransposeSelfOrderedList<string> transStr;

	string word;

	while (input >> word)
	{
		countStr.find(word);
		moveStr.find(word);
		transStr.find(word);
	}

	// Count Heuristic
	countStr.printlist(10);

	// Move-to-front Heuristic
	moveStr.printlist(10);

	// Transpose Heuristic
	transStr.printlist(10);

	// Close input.txt
	input.close();

	system("pause");
	return 0;
}