#pragma once
#include "llist.h"
#include "SelfOrderedListADT.h"

using namespace std;

template <typename E>
class TransposeSelfOrderedList : public SelfOrderedListADT<E> {
public:
	TransposeSelfOrderedList() { comparisons = 0; }
	~TransposeSelfOrderedList() {}

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
		cout << "Transpose Heuristic:\n\n";
		cout << "The number of compares is: " << getCompares() << "\n";
		cout << "My list size is: " << size() << "\n";
		cout << "My final list structure with frequencies is: \n\n";
		list.print();
		cout << "\n\n";
	}

	void printlist(int n)
	{
		cout << "-------\n";
		cout << "Transpose Heuristic:\nSize of list: " << size() << "\n";
		cout << "Number of compares: " << getCompares();
		list.print(n);
		cout << "\n\n";
	}

	// Transpose Heuristic
	void reorder()
	{
		E front = list.getFrontValue();
		E tail = list.getTailValue();

		// Stop function if values match
		if (list.getValue() == front)
		{
			return;
		}

		// Proceed if current value matches end value
		if (list.getValue() == tail)
		{
			int endValue = list.getTimesAccessed();
			list.prev();
			int previous = list.getTimesAccessed();

			E temp = list.remove();
			list.setAccess(previous);
			list.moveToEnd();

			list.insert(temp);
			list.setAccess(previous);
			list.prev();
			list.setAccess(endValue);
			return;
		}

		int swap = list.getTimesAccessed();
		list.prev();

		int prev = list.getTimesAccessed();
		list.next();
		int curr = list.getTimesAccessed();
		list.next();
		int next = list.getTimesAccessed();
		list.prev();
		E temp = list.remove();
		list.setAccess(next);
		list.prev();
		prev = list.getTimesAccessed();
		list.insert(temp);
		list.setAccess(swap);
		list.next();
		list.setAccess(prev);
	}

private:
	LList<E> list;
	int comparisons;
	TransposeSelfOrderedList(const TransposeSelfOrderedList&) {}
};