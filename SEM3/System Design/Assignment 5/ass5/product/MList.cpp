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
	CleanList();
}

/* all MList methods should come here */

void MList::addFirst(int addr, int size){
	ITEM* newItem = new ITEM(addr, size);
	newItem->size = size;
	newItem->prev = nullptr;
	newItem->next = head;

	if (head != nullptr) {
        head->prev = newItem;
    } else {
        tail = newItem;
    }
	
    head = newItem;
}

int MList::addAfter(ITEM* currentItem, int addr, int size){
	if (currentItem == nullptr) {
        return -1;
    }

    ITEM *newItem = new ITEM(addr, size);

    newItem->prev = currentItem;
    newItem->next = currentItem->next;

    if (currentItem->next != nullptr) {
        currentItem->next->prev = newItem;
    }

    currentItem->next = newItem;

    if (currentItem == tail) {
        tail = newItem;
    }

    return 0;
}

int MList::remove(ITEM* currentItem){

	if (currentItem == nullptr) {
        return -1;
    }

    if (currentItem == head) {
        head = currentItem->next;
    }
	else if (currentItem == tail) {
        tail = currentItem->prev;
    }

    if (currentItem->prev != nullptr) {
        currentItem->prev->next = currentItem->next;
    }

    if (currentItem->next != nullptr) {
        currentItem->next->prev = currentItem->prev;
    }

    delete currentItem;
    return 0;
}

int MList::addInOrder(int addr, int size){
    //if list is empy or if new node needs to go before another node.
    if (head == nullptr || head->addr > addr) {
        addFirst(addr, size);
        return 0;
    }

    //find correct position
    ITEM *current = head;
    while (current->next != nullptr && current->next->addr < addr) {
        current = current->next;
    }

    //insert node.
    addAfter(current, addr, size);
    return 0;
}

void MList::CleanList()
{
	ITEM *current = head;

    while (current != nullptr) {
        ITEM *next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
}

ITEM* MList::GetHead()
{
	return head;
}

ITEM* MList::GetTail()
{
	return tail;
}
