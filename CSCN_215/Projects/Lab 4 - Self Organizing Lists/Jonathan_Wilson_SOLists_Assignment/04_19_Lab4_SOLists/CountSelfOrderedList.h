#pragma once
#include "llist.h"
#include "SelfOrderedListADT.h"

using namespace std;

template <typename E>
class CountSelfOrderedList : public SelfOrderedListADT<E> {
public:
	CountSelfOrderedList()
	{
		comparisons = 0;
	}
	~CountSelfOrderedList() {}

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
		cout << "Count Heuristic:\n";
		cout << "The number of compares is: " << getCompares() << "\n";
		cout << "My list size is: " << size() << "\n";
		cout << "My final list structure with frequencies is: \n\n";
		list.print();
		cout << "\n\n";
	}

	void printlist(int n)
	{
		cout << "-------\n";
		cout << "Count Heuristic:\nSize of list: " << size() << "\n";
		cout << "Number of compares: " << getCompares();
		list.print(n);
		cout << "\n\n";
	}

	// Get times accessed and swap if new value is greater than previous
	// value
	void reorder()
	{
		int timesAccessed = list.getTimesAccessed();
		list.prev();
		int prev = list.getTimesAccessed();

		// Swap list elements until access num of current item is
		// less than previous value
		// Count SOL Heuristic
		while (timesAccessed > prev)
		{
			list.next();
			E temp = list.remove();

			list.setAccess(prev);
			list.prev();
			list.insert(temp);
			list.setAccess(timesAccessed);
			list.next();
			list.setAccess(prev);
			list.prev();
			list.prev();
			prev = list.getTimesAccessed();
		}
	}
private:
	LList<E> list;
	int comparisons;
	CountSelfOrderedList(const CountSelfOrderedList&) {}
};