#include "myqueuecpp.h"
#include <iostream>

using namespace std;

Queue::Queue(size_t itemSize) : stack_in(itemSize), stack_out(itemSize) {}

Queue::~Queue(){}

int Queue::myqueue_enqueue(void* obj){
    //invalid pointer
    if (obj == nullptr){
        return -1;
    }

    //push function gives result
    int result = stack_in.mystack_push(obj);

    //sucess
    return result;
}

int Queue::myqueue_dequeue(void* obj){
    //invalid pointer
    if (obj == nullptr){
        return -1;
    }

    //algorithm from previous assignment
    if ((stack_out.mystack_nofelem()) == 0){
        void* temp_obj = malloc(item_size);
        if (temp_obj == nullptr){
			return -1;
		}

        while((stack_in.mystack_nofelem()) > 0){
            stack_in.mystack_pop(temp_obj);
            stack_out.mystack_push(temp_obj);
        }
        
        free(temp_obj);
    }

    //check result of the function
    int result = stack_out.mystack_pop(obj);

    //sucess
    return result;
}