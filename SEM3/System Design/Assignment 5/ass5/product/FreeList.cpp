#include "FreeList.h"

FreeList::FreeList(int memStart, int maxSize)
    : MList(new ITEM(memStart, maxSize))
    , memStart(memStart)
    , maxSize(maxSize)
{
}

void FreeList::mergeMemory()
{
    ITEM *current = GetHead();

    while (current != nullptr && current->next != nullptr) {
        if (current->addr + current->size == current->next->addr) {
            current->size += current->next->size;
            remove(current->next);
        }
        else {
            current = current->next;
        }
    }
}

FreeList::~FreeList()
{
}