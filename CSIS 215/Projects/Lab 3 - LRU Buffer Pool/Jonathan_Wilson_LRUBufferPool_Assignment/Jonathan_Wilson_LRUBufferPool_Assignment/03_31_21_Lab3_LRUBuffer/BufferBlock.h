#pragma once

#include <iostream>
#include "BufferBlockADT.h"

class BufferBlock : public BufferblockADT {
private:
    int blockID;
    char* block;
    int size;
public:
    BufferBlock(char* data, int id, int sz = 4096) : block{ data }, blockID{ id }, size{ sz } {}

    virtual ~BufferBlock() {}

    //read the block from pos to pos + sz-1 (or to the end of the block)
    void getData(int pos, int sz, char* data)
    {
        int blockEnd;

        if (sz + pos > this->size)
        {
            blockEnd = this->size - 1;
        }
        else
        {
            blockEnd = sz - 1 + pos;
        }
        for (size_t i = 0; i + pos < blockEnd; ++i)
        {
            data[i] = block[i + pos];
        }
    }

    //setID
    void setID(int id)
    {
        this->blockID = id;
    }

    //getID
    int getID() const
    {
        return this->blockID;
    }

    //getBlocksize
    int getBlocksize() const
    {
        return this->size;
    }

    //return the block
    char* getBlock() const
    {
        return this->block;
    }

    //set the block
    void setBlock(char* blk)
    {
        this->block = blk;
    }

};