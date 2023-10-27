
#include "mystack.h"
#include "logging.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/* The stack is an abstract data type.
* this means that the internal structures are
* never exposed to the users of the library.
*/

/* Note: the stacks have no knowledge of what types
* they are storing. This is not a concern of the stack
*/

//references: geeksforgeeks and mycodeschool(youtube)

StackMeta_t *mystack_create(size_t objsize)
{
	//create stack
	StackMeta_t *stack = (StackMeta_t *)malloc(sizeof(StackMeta_t));
	
	if (stack == NULL){
		//memory failure
		return NULL;
	}

	//initialize new stack variables.
	stack->stack = NULL;
	stack->objsize = objsize;
	stack->numelem = 0;

	//created stack
 	return stack;
}

int mystack_push(StackMeta_t *stack, void* obj)
{
	//invalid stack pointer
	if (stack == NULL){
		return -1;
	}

	//create a new stack object/element.
	StackObject_t *new_stack_element = (StackObject_t *)malloc(sizeof(StackObject_t));
	
	//memory failure
	if (new_stack_element == NULL){
		return -1;
	}

	//create a new stack object and check for memory issues.
	new_stack_element->obj = malloc(stack->objsize);
	//memory failure.
	if (new_stack_element->obj == NULL){
		free(new_stack_element);
		return -1;
	}

	//pass the data into the stack by copying it. 
	memcpy(new_stack_element->obj, obj, stack->objsize);
	new_stack_element->next = stack->stack;	//set new element in stack ("link" it with the stack)
	stack->stack = new_stack_element;	//new object is the top
	stack->numelem++;
	
	return 0;
}

int mystack_pop(StackMeta_t *stack, void* obj)
{
	//invalid stack pointer
	if (stack == NULL){
		return -1;
	}

	//nothing to pop (stack is empty)
	if (stack->numelem == 0){
		return -1;
	}

	//define top of stack
	StackObject_t *top = stack->stack;

	//make next element new top
	stack->stack = top->next;
	memcpy(obj, top->obj, stack->objsize);
	free(top->obj);
	free(top);
	stack->numelem--;

	return 0;
}

void mystack_destroy(StackMeta_t *stack)
{
	//invalid stack pointer.
	if (stack == NULL){
		return;
	}

	//delete all stack objects
	while(stack->stack != NULL){
		StackObject_t *top = stack->stack;
		stack->stack = top->next;
		free(top->obj);
		free(top);
	}

	//delete stack
	free(stack);
}

int mystack_nofelem(StackMeta_t *stack)
{
	//invalid stack pointer
	if (stack == NULL){
		return -1;
	}
	
	//num of elems
	return stack->numelem;
}
