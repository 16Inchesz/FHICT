#pragma once

#include "MList.h"
#include "AllocList.h"
#include "FreeList.h"

class MemoryManager 
{
    private:
        int memStart;
        int maxSize;
        AllocList* allocList;
        FreeList* freeList;
    public:   
        MemoryManager(int memStart, int maxSize);
        ~MemoryManager();
        int ClaimMemory(int size);
        int FreeMemory(int addr);
        AllocList* GetAllocList();
        FreeList* GetFreeList();
        int GetMemStart();
        int GetMaxSize();
};

