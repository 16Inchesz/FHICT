#ifndef __MYSTACKCPP_H__
#define __MYSTACKCPP_H__

#include <stddef.h>
#include <stdlib.h>
#include <string.h> 

struct StackObject_t
{
    void* obj;
    StackObject_t *next;
};

struct StackMeta_t
{
    StackObject_t *stack;
    size_t objsize;
    int numelem;
};

class stack
{
public:
    //empty constructor
    stack(){}

    StackMeta_t *mystack_create(size_t objsize);
    int mystack_push(StackMeta_t *stack, void* obj);
    int mystack_pop(StackMeta_t *stack, void* obj);
    void mystack_destroy(StackMeta_t *stack);
    int mystack_nofelem(StackMeta_t *stack);
};

#endif