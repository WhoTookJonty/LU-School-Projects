#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "bagADT.h"

using namespace std;
template <typename E>

class ABag : public Bag <E> {
public:
	// Constructor
	ABag()
	{
		// Defines the maximum capacity of the bag
		maxItems = 10;
	}

	// Destructor
	// This effectively de-allocates the vector from memory
	~ABag()
	{
		vector <E>().swap(data);
	}

	// Places an item into the bag
	bool addItem(const E& item)
	{
		// Add an item only if there is room to add it (does not exceed
		// maxItems size)
		bool hasRoom = (data.size() <= maxItems);
		if (hasRoom)
		{
			data.push_back(item);
		}
		return hasRoom;
	}

	// Removes an item from the bag
	bool remove(E& item)
	{
		// If the comparison returns true and i exists, remove item
		bool found = false;
		for (int i = 0; i < data.size(); ++i)
		{
			if (item == data.at(i) && i != 0)
			{

				item = data.at(i);
				found = true;
				data.erase(data.begin() + i);
			}
			// Takes into account how we count starting at 0
			else if (item == data.at(i) && i == 0)
			{
				item = data.at(i);
				found = true;
				data.erase(data.begin());
			}
		}
		return found;
	}

	// Removes a record from the top of the bag, only if the vector is
	// larger than 0.
	bool removeTop(E& item)
	{
		bool hasRoom = (data.size() != 0);
		if (hasRoom)
		{
			item = data.at(data.size() - 1);
			data.erase(data.end() - 1);
		}
		return hasRoom;
	}

	// Finds a record in the stack
	bool find(E& returnValue) const
	{
		bool found = false;
		// Scan the vector
		for (int i = 0; i < data.size(); ++i)
		{
			// If value in vector matches returnValue query, set
			// found boolean = to true
			if (returnValue == data.at(i))
			{
				returnValue = data.at(i);
				found = true;
				// Stop scanning through the vector since we found the
				// query already
				break;
			}
		}
		return found;
	}

	// Checks the top of the stack and updates item with bag contents
	bool inspectTop(E& item) const
	{
		bool notEmpty = true;
		if (data.size() == 0)
		{
			notEmpty = false;
		}
		else
		{
			item = data.at(data.size() - 1);
		}
		return notEmpty;
	}

	// Clears the bag of all data entries, emptying it
	void emptyBag()
	{
		data.clear();
	}

	// Overloads the += operator to allow the program to reference
	// addItem to add to the vector
	bool operator+=(const E& addend)
	{
		bool hasRoomToAdd = (this->addItem(addend));
		return hasRoomToAdd;
	}

	// Returns the size of the bag
	int size() const
	{
		return data.size();
	}

	// Returns the maximum capacity of the bag, determined by maxItems
	int bagCapacity() const
	{
		return maxItems; //adding 1 to maxItems will show the total number of slots available from 1-10 instead of 0-9
	}

private:
	vector <E> data;
	int maxItems;
};