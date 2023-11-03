#ifndef __MYSTACKCPP_H__
#define __MYSTACKCPP_H__ 

#include <stdio.h>
#include <cstring>

class Stack
{
public:
    //constructor + destructor
    Stack(size_t objsize);
    ~Stack();

    //methods
    int mystack_push(void* obj);
    int mystack_pop(void* obj);
    int mystack_nofelem();

private:
    struct StackObject_t
    {
        void* obj;
        StackObject_t *next;
    };

    //variables needed for stack creation
    StackObject_t* stack;
    size_t obj_size;
    int numelem;
};

#endif