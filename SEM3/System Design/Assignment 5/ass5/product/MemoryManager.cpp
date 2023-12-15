#include "MemoryManager.h"
// #include "MList.h"
#include "AllocList.h"
#include "FreeList.h"

#include <iostream>


/* Starting point for MemoryManager constructor */
MemoryManager::MemoryManager(int memStart, int maxSize)
	: memStart(memStart)
	, maxSize(maxSize)
	, allocList(new AllocList(memStart, maxSize))
	, freeList(new FreeList(memStart, maxSize))
{
}

/* Code correct destructor to cleanup all memory */
MemoryManager::~MemoryManager()
{
	delete allocList;
	delete freeList;
}

/* pre : size > 0
 * post: If no memory block of size "size" available return -1
 *       Otherwise claimMemory() returns the first
 *       address in the freeList where a memory block of at least size is present.
 *       This memory is allocated and not any more available.
 *       The newly allocated block is added to the allocList and addr of the newly
 *       allocated block is returned
 */
int MemoryManager::ClaimMemory(int size)
{
	//pre
	if (size > maxSize || size <= 0){
		return -1;
	}

	//free memory chunk
	ITEM* freeChunk = freeList->GetHead();

	//iterate through free list.
	while (freeChunk != nullptr){

		//enough memory found.
		if(freeChunk->size >= size){
			int allocatedAddr = freeChunk->addr;
			int newSize = freeChunk->size - size;

			//new free list.
			if (newSize > 0){
				freeList->addAfter(freeChunk, (allocatedAddr + size), newSize);
			}
			freeList->remove(freeChunk);

			//add allocated memory in allocList at the correct spot.
			allocList->addInOrder(allocatedAddr, size);

			return allocatedAddr;
		}
		freeChunk = freeChunk->next;
	}
	return -1;
}

/* pre:  Parameter addr must match the start of an allocatd memory block. Otherwhise return -1.
 *
 * post: If addr is a part of allocated memory of allocList then the memory from this address
 * 	     with registered size should be removed from the allocList and added to the freeList
 *
 *       freeMemory(addr) returns number of bytes (size) belongig to the address addr
 *       In all other cases freeMemory(freeList,allocList,addr) returns -1.
 */
int MemoryManager::FreeMemory(int addr)
{
	if (addr < memStart || addr >= memStart + maxSize){
		return -1;
	}

	//allocated memory chunk
	ITEM* allocatedChunk = allocList->GetHead();
	
	while (allocatedChunk != nullptr)
    {
        if (allocatedChunk->addr == addr)
        {
            int chunkSize = allocatedChunk->size;

            allocList->remove(allocatedChunk);

            //add the freed memory in freeList at the correct spot
            freeList->addInOrder(addr, chunkSize);

            //if applicable, merge memories that need to be merged.
            freeList->mergeMemory();

            return chunkSize;
        }
        allocatedChunk = allocatedChunk->next;
    }

    return -1;
}

AllocList* MemoryManager::GetAllocList()
{
	return allocList;
}
FreeList* MemoryManager::GetFreeList()
{
	return freeList;
}

int MemoryManager::GetMemStart()
{
	return memStart;
}

int MemoryManager::GetMaxSize()
{
	return maxSize;
}
