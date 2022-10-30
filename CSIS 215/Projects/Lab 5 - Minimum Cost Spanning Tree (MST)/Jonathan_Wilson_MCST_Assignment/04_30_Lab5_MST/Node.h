#pragma once

enum MARK { VISITED, UNVISITED };
template <typename E>

class Node
{
private:
	MARK mark;
	int index;
	E* dataptr;
public:
	Node(int i, E* d) : index{ i }, dataptr{ d }, {}
	~Node()
	{
		dataptr = NULL;
	}

	int getIndex() const
	{
		return index;
	}

	E getData() const
	{
		return (*dataptr);
	}

	MARK getMark() const
	{
		return mark;
	}

	void setMark(MARK m)
	{
		mark = m;
	}
};