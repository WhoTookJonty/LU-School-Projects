#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Graph.h"

using namespace std;

// Enum declarations
enum MARK { VISITED, UNVISITED };
enum INCLUDED { INCLUDED, EXCLUDED };

// Adjacency matrix class
class AMGraph : public Graph {
public:
	AMGraph(int v) { Init(v); }
	AMGraph(string file) { read(file); }
	~AMGraph()
	{
		delete[] spots;
		for (int i = 0; i < numVertices; ++i)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	// Initialize a graph of n vertices
	void Init(int n)
	{
		spots = new int[n];
		numEdges = 0;
		numVertices = n;
		for (int i = 0; i < numVertices; ++i)
		{
			spots[i] = UNVISITED;
		}

		// Construct matrix and set all weights to 0
		matrix = (int**) new int* [numVertices];
		for (int i = 0; i < numVertices; ++i)
		{
			matrix[i] = new int[numVertices];
		}

		for (int i = 0; i < numVertices; ++i)
		{
			for (int j = 0; j < numVertices; ++j)
			{
				matrix[i][j] = 0;
			}
		}
	}

	// Returns the number of vertices and edges
	int n() const { return numVertices; }
	int e() const { return numEdges; }

	// Return v’s first neighbor
	int first(int v) const
	{
		int n = this->n();
		for (int i = 0; i < n; ++i)
		{
			if (matrix[v][i] != 0)
			{
				n = i;
				break;
			}
		}
		return n;
	}

	// Return v’s next neighbor
	int next(int v, int w) const
	{
		int x = numVertices;
		for (int i = 1 + w; i < numVertices; ++i)
		{
			if (matrix[v][i] != 0)
			{
				x = i;
				break;
			}
		}
		return x;
	}

	// Sets the weight for an edge. i, j: The vertices, wgt: weight
	// First setEdge function that couts
	void setEdge(int v1, int v2, int wt)
	{
		std::cout << "Add edge " << v1 << " to " << v2 << std::endl;
		if (wt >= 0)
		{
			if (matrix[v1][v2] == 0)
			{
				numEdges++;
			}
			matrix[v1][v2] = wt;
		}
	}

	// Second setEdge function that doesn't cout, for formatting purposes
	void setEdge2(int v1, int v2, int wt)
	{
		if (wt >= 0)
		{
			if (matrix[v1][v2] == 0)
			{
				numEdges++;
			}
			matrix[v1][v2] = wt;
		}
	}

	// Delete an edge
	// i, j: The vertices
	void delEdge(int v1, int v2)
	{
		if (matrix[v1][v2] != 0)
		{
			numEdges--;
		}
		matrix[v1][v2] = 0;
	}

	// Determines if an edge is in the graph
	// Return: true if edge v1,v2 has non-zero weight
	bool isEdge(int v1, int v2) const
	{
		return matrix[v1][v2] != 0;
	}

	// Returns an edge’s weight
	// Return: The weight of edge v1,v2, or zero
	int weight(int v1, int v2) const
	{
		return matrix[v1][v2];
	}

	// Get and Set the mark value for a vertex
	int getMark(int v) const
	{
		return spots[v];
	}
	void setMark(int v, int val)
	{
		spots[v] = val;
	}

	// Output to console
	void print(bool mst) const
	{
		if (!mst)
		{
			cout << "Number of vertices is " << numVertices << endl;
			cout << "Number of edges is " << numEdges << endl;
			cout << "Matrix is: " << endl;
		}
		cout << endl;
		for (int row = 0; row < numVertices; ++row)
		{
			for (int col = 0; col < numVertices; ++col)
			{
				cout << matrix[row][col] << " ";
			}
			cout << endl;
		}
	}

	// Writes graph to text file
	void write(string file)
	{
		if (!isValidFile(file)) { return; }

		fileWrite.open(file);
		fileWrite << "GraphFile" << endl;
		fileWrite << "Vertices=" << numVertices << endl;

		for (int row = 0; row < numVertices; ++row)
		{
			for (int col = 0; col < numVertices; ++col)
			{
				fileWrite << matrix[row][col];
				if (col + 1 < numVertices)
				{
					fileWrite << " ";
				}
			}
			fileWrite << endl;
		}

		fileWrite.close();
	}

	// MST starting from given vertex start point
	AMGraph* MCST(int s)
	{
		AMGraph* mst = new AMGraph(numVertices);
		cout << endl << "Begin MST starting at Vertex " << s << endl;
		int i, w;
		int* D = new int[this->n()];
		int* V = new int[this->n()];

		for (int i = 0; i < this->n(); ++i)
		{
			D[i] = INT_MAX;
			V[i] = INT_MAX;
			this->setMark(i, UNVISITED);
		}

		// s = vertice starting point
		// E.g in pos 0 (vert) is set to 0, pos 4 (vert) is set to 0 etc. 
		D[s] = 0;
		for (i = 0; i < this->n(); ++i)
		{
			int v = minVertex(this, D);
			this->setMark(v, VISITED);
			if (v != s)
			{
				int a = (V[v] == INT_MAX ? s : V[v]); // if V[v] == INT_MAX, then a = V[v], else a = (s = V[v])
				mst->setEdge(a, v, D[v]);
				mst->setEdge2(v, a, D[v]);
			}
			if (D[v] == INFINITY) { return mst; }

			for (w = this->first(v); w < this->n(); w = this->next(v, w))
			{
				if (D[w] > this->weight(v, w))
				{
					D[w] = this->weight(v, w);
					V[w] = v;
				}
			}
		}
		mst->print(true);
		return mst;
	}
private:
	ifstream readFile;
	ofstream fileWrite;
	int numVertices, numEdges;
	int* spots;
	int** matrix;

	// Exit if file is not present
	bool isValidFile(string file)
	{
		bool found = file.find(".graphfile") != string::npos;
		if (!found)
		{
			cout << "Error: graphfile not found" << endl;
			exit;
		}
		return found;
	}

	// Read graphfile
	void read(string file)
	{
		string buffer;
		bool flag = true;
		int index = 0;
		int row = 0;
		
		if (!isValidFile(file))
		{
			return;
		}

		readFile.open(file);

		while (getline(readFile, buffer))
		{
			if (index == 0)
			{
				flag = (buffer == "GraphFile");
			}
			else if (index == 1)
			{
				int numIndex = (int)buffer.find("Vertices=");
				int numVertices;
				flag = (numIndex != string::npos);
				if (flag)
				{
					// The word "Vertices=" is 9 chars long, we accoutn for this by adding 9
					numVertices = stoi(buffer.substr(numIndex + 9, (buffer.size() - numIndex + 9)));
					Init(numVertices);
				}
			}
			else
			{
				stringstream line;
				line.str(buffer);
				int weight = 0;
				for (int col = 0; col < numVertices; ++col)
				{
					line >> weight;
					if (weight != 0)
					{
						setEdge2(row, col, weight);
					}
					weight = 0;
				}
				row++;
			}

			if (!flag)
			{
				cout << "Error: invalid file" << endl;
				return;
			}
			buffer.clear();
			index++;
		}
		readFile.close();
	}

	// Find mincost vertex
	int minVertex(AMGraph* G, int* D)
	{
		int i;
		int v = -1;

		for (i = 0; i < G->n(); ++i)
		{
			if (G->getMark(i) == UNVISITED)
			{
				v = i;
				break;
			}
		}

		for (i++; i < G->n(); ++i)
		{
			if (G->getMark(i) == UNVISITED && D[i] < D[v])
			{
				v = i;
			}
		}
		return v;
	}
};