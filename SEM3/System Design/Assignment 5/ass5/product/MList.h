#pragma once   // be carefull with pragma once, most compilers support it, but not all

typedef struct ITEM
{
    int addr;
    int size;
    struct ITEM* next;
    struct ITEM* prev;
    ITEM() = delete;  // we don't want the default ctor
    ITEM(int addr, int size) { this->addr = addr; this->size = size; this->next = nullptr; this->prev = nullptr; }
}ITEM;

class MList {
    private:
        ITEM* head;
        ITEM* tail;
    public:
        MList(ITEM* head);
        MList() = delete;
        virtual ~MList();  // virtual, because this class will have children. @student why?

	    /* all MList methods should come here */
        void addFirst(int addr, int size);
        void addLast(int addr, int size);
        int addAfter(ITEM* currentItem, int addr, int size);
        int remove(ITEM* currentItem);
        int removeFirst();
        int removeLast();
        int removeAfter(ITEM* currentItem);
        void CleanList();
        ITEM* GetHead();
        ITEM* GetTail();
};

