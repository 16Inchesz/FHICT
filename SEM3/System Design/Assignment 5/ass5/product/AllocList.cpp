#include "AllocList.h"

AllocList::AllocList(int memStart, int maxSize)
    : MList(nullptr)
    , memStart(memStart)
    , maxSize(maxSize)
{
}

AllocList::~AllocList() 
{
}