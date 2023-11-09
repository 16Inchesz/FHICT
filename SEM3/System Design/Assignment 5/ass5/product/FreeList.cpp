#include "FreeList.h"

FreeList::FreeList(int memStart, int maxSize)
    : MList(new ITEM(memStart, maxSize))
    , memStart(memStart)
    , maxSize(maxSize)
{
}

FreeList::~FreeList()
{
}