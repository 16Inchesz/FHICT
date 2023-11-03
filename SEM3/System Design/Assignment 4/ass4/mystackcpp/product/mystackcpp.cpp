#include "mystackcpp.h"
#include <iostream>

using namespace std;

//ask about this pointer object
Stack::Stack(size_t objsize){
    stack = nullptr;
    objsize = objsize;
    numelem = 0;
}

Stack::~Stack(){
    while(stack != nullptr){
        StackObject_t* top = stack;
        stack = top->next;
        free(top->obj);
        free(top);
    }
}

int Stack::mystack_push(void* obj){
    //invalid pointer
    if(obj == nullptr){
        return -1;
    }

    StackObject_t *new_stack_element = (StackObject_t *)malloc(sizeof(StackObject_t));
	
	//memory failure
	if (new_stack_element == nullptr){
		return -1;
	}

	//create a new stack object and check for memory issues.
	new_stack_element->obj = malloc(objsize);
	//memory failure.
	if (new_stack_element->obj == nullptr){
		free(new_stack_element);
		return -1;
	}

	//pass the data into the stack by copying it. 
	memcpy(new_stack_element->obj, obj, objsize);
	new_stack_element->next = stack;	//set new element in stack ("link" it with the stack)
	stack = new_stack_element;	//new object is the top
	numelem++;
	
	return 0;
}

int Stack::mystack_pop(void* obj){
    //invalid stack and object pointer
	if (obj == nullptr){
		return -1;
	}

	//nothing to pop (stack is empty)
	if (numelem == 0){
		return -1;
	}

	//define top of stack
	StackObject_t *top = stack;

	//make next element new top
	stack = top->next;
	memcpy(obj, top->obj, objsize);
	free(top->obj);
	free(top);
	numelem--;

	return 0;
}

int Stack::mystack_nofelem(){
    return numelem;
}
