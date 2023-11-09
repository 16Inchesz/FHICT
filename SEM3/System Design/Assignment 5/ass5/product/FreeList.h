#pragma once
#include "MList.h"


/* Code functionality for the FreeList, think well which functionality is specific for FreeList and which is generic to MList */

class FreeList : public MList
{
private:
    int memStart;
    int maxSize;
public:
    FreeList() = delete;
    FreeList(int memStart, int maxSize);
    ~FreeList();
};