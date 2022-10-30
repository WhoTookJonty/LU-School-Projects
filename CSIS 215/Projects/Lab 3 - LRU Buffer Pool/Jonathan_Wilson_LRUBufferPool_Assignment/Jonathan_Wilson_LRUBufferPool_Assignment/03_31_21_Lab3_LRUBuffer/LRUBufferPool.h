#pragma once

#include <iostream>
#include <fstream>
#include "BufferBlock.h"
#include "BufferPoolADT.h"

class LRUBufferPool : BufferPoolADT
{
private:
	BufferBlock** bufferPool;
	std::fstream input;
	int blockSize;
	int poolSize;
public:
	LRUBufferPool() {}
	LRUBufferPool(string filename, int poolSize = 5, int blockSize = 4096) : poolSize{ poolSize }, blockSize{ blockSize }
	{
		// Return error and exit program if text file doesn't exist
		input.open(filename.c_str(), fstream::in | fstream::binary);
		if (!input)
		{
			cout << "Error: File not found.";
			exit;
		}
		else
		{
			// Read from disk
			bufferPool = new BufferBlock * [poolSize];
			for (size_t i = 0; i < poolSize; ++i)
			{
				input.seekg(i * blockSize);
				char* buffer = new char[blockSize];
				input.read(buffer, blockSize);
				bufferPool[i] = new BufferBlock(buffer, i, blockSize);
			}
		}
	}

	// Destructor
	~LRUBufferPool()
	{
		input.close();
		delete[] bufferPool;
	}

	// Copy "sz" bytes from position "pos" of the buffered
	//   storage to "space".
	void getbytes(char* space, int sz, int pos)
	{
		BufferBlock* block;
		int id = (pos / blockSize);
		int index = this->getIndex(id);

		if (index >= 0)
		{
			block = bufferPool[index];
		}
		else
		{
			char* buffer = new char[blockSize];
			input.seekg(id * blockSize);
			input.read(buffer, blockSize);
			block = new BufferBlock(buffer, id, blockSize);
		}

		block->getData(pos - (id * blockSize), sz, space);

		// Least recently used logic
		if (index >= 0)
		{
			BufferBlock* temp = bufferPool[index];
			for (int i = index; i < poolSize; ++i)
			{
				if (i + 1 < poolSize)
				{
					bufferPool[i] = bufferPool[1 + i];
				}
			}
			bufferPool[poolSize - 1] = temp;
		}

		// Delete buffer's last element, assign new block to latest position and
		// shift new block over to the front
		else
		{
			delete bufferPool[poolSize - 1];
			bufferPool[poolSize - 1] = block;
		}
		
		// Move LRU element to front of pool
		BufferBlock* temp2 = bufferPool[0];
		bufferPool[0] = bufferPool[poolSize - 1];
		for (int i = (poolSize - 1); i > 1; --i)
		{
			bufferPool[i] = bufferPool[i - 1];
		}
		bufferPool[1] = temp2;
	}

	// Print the order of the buffer blocks using the block id
	//	 numbers.
	void printBufferBlockOrder()
	{
		cout << "My buffer block order from most recently used to LRU is:" << endl << "\t";
		for (int i = 0; i < poolSize; ++i)
		{
			cout << bufferPool[i]->getID() << ", ";
		}
		cout << endl;
	}

	// Get the block id number of the least recently used 
	//	 buffer block.
	int getLRUBlockID()
	{
		return bufferPool[0]->getID();
	}
	
	// Retrieves the index of blocks from pool, returns proper -1 if block is not found
	int getIndex(int id)
	{
		int index = -1;
		for (int i = 0; i < this->poolSize; ++i)
		{
			if (bufferPool[i]->getID() == id)
			{
				index = i;
			}
		}
		return index;
	}
};