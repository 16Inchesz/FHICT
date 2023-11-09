#pragma once
#include "MList.h"


/* Code functionality for the AllocList, think well which functionality is specific for AllocList and which is generic to MList */

class AllocList : public MList
{
private:
    int memStart;
    int maxSize;
public:
    AllocList() = delete;
    AllocList(int memStart, int maxSize);
    ~AllocList();
};