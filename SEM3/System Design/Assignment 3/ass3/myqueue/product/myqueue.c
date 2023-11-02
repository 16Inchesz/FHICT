#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "mystack.h"
#include "myqueue.h"

QueueMeta_t *myqueue_create(int item_size)
{
	//create queue
	QueueMeta_t *queue = (QueueMeta_t *)malloc(sizeof(QueueMeta_t));
	
	//memory failure
	if (queue == NULL) {
		return NULL;
	}

	queue->stack_in = mystack_create(item_size);
	queue->stack_out = mystack_create(item_size);

	return queue;
}

void myqueue_delete(QueueMeta_t *queue)
{
	//invalid pointer
	if (queue == NULL){
		return;
	}

	mystack_destroy(queue->stack_in);
	mystack_destroy(queue->stack_out);

	free(queue);
}

int myqueue_enqueue(QueueMeta_t *queue, void *obj)
{
	//invalid queue and object pointer
	if (queue == NULL || obj == NULL){
		return -1;
	}

	//check result of the push function
	int result = mystack_push(queue->stack_in, obj);

	//success
	return result;
}

int myqueue_dequeue(QueueMeta_t *queue, void *obj)
{
	//invalid queue and object pointer
	if (queue == NULL || obj == NULL){
		return -1;
	}

	//create temp object to store memory fail safe. (only when the stack out is empty)
	void *temp_obj = malloc(queue->item_size);
	if (temp_obj == NULL){
		return -1;
	}

	//algorithm from youtube link
	if (mystack_nofelem(queue->stack_out) == 0){
		while(mystack_nofelem(queue->stack_in) > 0){
			mystack_pop(queue->stack_in, temp_obj);
			mystack_push(queue->stack_out, temp_obj);
		}
	}

	//free the temporary object
	free(temp_obj);

	//check result of the function
	int result = mystack_pop(queue->stack_out, obj);

	//success
	return result;
}




