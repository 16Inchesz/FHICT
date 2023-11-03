#ifndef __MYQUEUECPP_H__
#define __MYQUEUECPP_H__ 

#include "mystackcpp.h"


class Queue 
{
public:
    //constructor
    Queue(size_t item_size);
    ~Queue();

    //methods
    int myqueue_enqueue(void *obj);
    int myqueue_dequeue(void* obj);

private:
    Stack stack_in;
    Stack stack_out;
    int item_size;
};
#endif