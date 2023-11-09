#include "testUi.h"
#include <iostream>

using namespace std;

int testUi::getNumber(string message)
{
    int choice=0;
    
    if(withMenu == true)
    {
        std::cout << message;
    }
    std::cin >> choice;
    return choice;
}

void testUi::showList(MList *list)
{
    ITEM *item = list->GetHead();
    if(item == nullptr)
    {
        std::cout << "  <empty>" << endl;
        return;
    }
    int i = 0;
    while(item != nullptr)
    {
        char s[100];
        sprintf (s, "%3d:  addr:%4d  size:%4d", i, item->addr, item->size);
        std::cout << s << endl;
        item = item->next;
        i++;
    }
}

void testUi::showLists(MList *allocList, MList *freeList)
{
    std::cout <<  "FreeList:" << endl;
    std::cout <<  "---------" << endl;
    showList(freeList);
    std::cout <<  "AllocList:" << endl;
    std::cout << "----------" << endl;
    showList(allocList);
}

void testUi::startUi(MemoryManager *mm)
{
    bool quit = false;

    std::cout << endl << "SD 'MemoryC++' (version 1)" << endl;
    std::cout << "-------------------------" << endl;
    while(quit == false)
    {
        if(withMenu == true)
        {
            std::cout << endl;
            std::cout << "MENU" << endl;
            std::cout << "===================" << endl;
            std::cout << "[1] allocate memory" << endl;
            std::cout << "[2] free memory" << endl;
            std::cout << "[3] show lists" << endl;
            std::cout << "[8] show/hide menu" << endl;
            std::cout << "[9] quit" << endl << endl;

        }
        int choice = getNumber("choice: ");
        char string[100];

        switch(choice){
            case 1: {
                        int nrOfBytes = getNumber("Give nr of bytes: ");
                        int addr = mm->ClaimMemory(nrOfBytes);
                        if(addr == -1)
                        {
                            std::cout << "[ALLOC] not enough memory for " << nrOfBytes << " byte" << endl;
                        }
                        else
                        {
                            std::cout << "[ALLOC] address: " << addr << " (" << nrOfBytes << " byte)" << endl;
                        }
                    }
                    break;
            case 2: {
                        int addr=getNumber("Give address to be freed: ");
                        int nrOfBytes = mm->FreeMemory(addr);
                        if (nrOfBytes == -1)
                        {
                            sprintf(string,"[FREE]  address: %4d was not allocated",addr);
                        }
                        else
                        {
                            sprintf(string,"[FREE]  address: %4d (%d byte)",addr, nrOfBytes);
                        }
                        std::cout << string << endl;
                    }
                    break;
            case 3: showLists(mm->GetAllocList(), mm->GetFreeList());
                    break;
            case 8:
                    if (withMenu == true)
                    {
                        withMenu = false;
                        std::cout << "printing of MENU is diabled" << endl;
                    }
                    else
                    {
                    // printing enabled
                        withMenu = true;
                    }
                    break;

            case 9:
                    quit = true;
                    break;
            
            default:
                    std::cout << "invalid choice: " << choice << endl;
                    break;

        }
    }
}