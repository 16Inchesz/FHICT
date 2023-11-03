#ifndef __MYSTACKCPP_H__
#define __MYSTACKCPP_H__ 

#include <stdio.h>
#include <cstring>

class Stack
{
public:
    //empty constructor
    Stack(size_t objsize);
    ~Stack();

    int mystack_push(void* obj);
    int mystack_pop(void* obj);
    int mystack_nofelem();

private:
    struct StackObject_t
    {
        void* obj;
        StackObject_t *next;
    };

    StackObject_t* stack;
    size_t objsize;
    int numelem;
};

#endif