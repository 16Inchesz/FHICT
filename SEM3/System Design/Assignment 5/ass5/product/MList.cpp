#include <iostream>
#include "MList.h"

/* Implementation of all your MList methods */

MList::MList(ITEM* head)
	: head(head)
	, tail(head)
{
}

MList::~MList()
{
	//tobedone
}

/* all MList methods should come here */
void MList::CleanList()
{
	//tobedone
}

ITEM* MList::GetHead()
{
	return head;
}

ITEM* MList::GetTail()
{
	return tail;
}
