#pragma once
#include "SelfOrderedListADT.h"
#include "llist.h"

using namespace std;

template <typename E>
class MTFSelfOrderedList : public SelfOrderedListADT<E> {
public:
	MTFSelfOrderedList() { comparisons = 0; };
	~MTFSelfOrderedList() {};

	bool find(const E& it)
	{
		bool isFound{ false };
		list.moveToStart();

		for (int i = 0; i < list.length(); ++i)
		{
			comparisons++;
			if (list.getValue() == it)
			{
				isFound = true;
				break;
			}
			list.next();
		}

		// If a duplicate is found, increment times accessed and reorder
		if (isFound == true)
		{
			int temp = list.getTimesAccessed();
			list.setAccess(temp + 1);
			reorder();
			return true;
		}

		// Move to end, insert, reset times accessed
		else
		{
			list.moveToEnd();
			list.insert(it);
			list.setAccess(0);
			return true;
		}
		return false;
	}

	void add(const E& it)
	{
		list.append(it);
	}

	int getCompares() const
	{
		return comparisons;
	}

	int size() const
	{
		return list.length();
	}

	void printlist()
	{
		cout << "-------\n";
		cout << "Move-to-front Heuristic:\n\n";
		cout << "The number of compares is: " << getCompares() << "\n";
		cout << "My list size is: " << size() << "\n";
		cout << "My final list structure with frequencies is: \n\n";
		list.print();
		cout << "\n\n";
	}

	void printlist(int n)
	{
		cout << "-------\n";
		cout << "Move-to-front Heuristic:\nSize of list: " << size() << "\n";
		cout << "Number of compares: " << getCompares();
		list.print(n);
		cout << "\n\n";
	}

	// Reorder elements
	// Move-to-front Heuristic
	void reorder()
	{
		int timesAccessed = list.getTimesAccessed();
		list.next();
		int next = list.getTimesAccessed();
		list.prev();
		E temp = list.remove();

		list.setAccess(next);
		list.moveToStart();
		int front = list.getTimesAccessed();
		list.insert(temp);
		list.setAccess(timesAccessed);
		
		list.next();
		list.setAccess(front);
	}

private:
	int comparisons;
	MTFSelfOrderedList(const MTFSelfOrderedList&) {}
	LList<E> list;
};