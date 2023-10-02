/* SD exercise 1: simple linked list API */
/* Author : R. Frenken                   */
/* Version : 1.0			 			 */
/* Johnson Domacasse					 */
/* referenece: geeksforgeeks, 			 */
/* renata frenken YT channel, 			 */
/* mycodeschool YT channel				 */
#include "linkedlist.h"
#include <stdlib.h>

/***************************************************/
/* If *list == NULL, a new list should be created, */
/* otherwise prepend a new ITEM with value value   */
/* to the existing list                            */
/* Returns -1 if not enough memory, otherwise 0    */
/***************************************************/

int add_first(ITEM **list, int value)
{
	//insert node.
	ITEM* node = (ITEM*)malloc(sizeof(struct ITEM));	

	//check if the node was succesfully created
	if (node == NULL) {
		return -1;
	}

	//assign values
	node->value = value;
	node->next = NULL;

	//if linked list is empty.
	if (*list == NULL) {
		*list = node;
	} else {
		node->next = *list;
		*list = node;
	}
	return 0;
}

/***************************************************/
/* If *list == NULL, a new list should be created, */
/* otherwise append a new ITEM with value value to */
/* the existing list                               */
/* Returns -1 if not enough memory, otherwise 0    */
/***************************************************/

int add_last(ITEM **list, int value)
{
	//insert node
	ITEM* node = (ITEM*)malloc(sizeof(struct ITEM));

	//check if the node was succesfully created(enough memory)
	if (node == NULL) {
		return -1;
	}

	//assign values.	
	node->value = value;
	node->next = NULL;

	struct ITEM* last_node = *list;

	//if linked list is empty.
	if (*list == NULL) {
		*list = node;
	} else {
		//iterate through the linked list.
		while(last_node->next != NULL){
			last_node = last_node->next;
		}
		last_node->next = node;
	}
	return 0;
}

/****************************************************/
/* Insert a new item after current item c_item      */
/* Returns -1 if not enough memory, c_item == NULL, */
/* *list == NULL or c_item not found, otherwise 0   */
/****************************************************/

int add_after(ITEM *list, ITEM *c_item, int value)
{
	if (list == NULL || c_item == NULL) {
		return -1;
	}
	
	//insert new node.
	ITEM* node = (ITEM*)malloc(sizeof(struct ITEM));
	
	//check if node was succesfully created. (enough memory)
	if (node == NULL) {
		return -1;
	}
	
	//assign node values.
	node->value = value;
	node->next = NULL;

	ITEM* current_node = list;
	
	//iterate through list
	while (current_node != NULL) {
		//current item found
		if (current_node == c_item) {
			node->next = c_item->next;
			c_item->next = node;
			return 0;
		}
		current_node = current_node->next;
	}

	//loop didn't find the current item.
	free(node);
	return -1;
}


/***************************************************/
/* Remove first item of the list                   */
/* Returns -1 if list==NULL, otherwise 0           */
/***************************************************/

int rem_first(ITEM **list)
{
	if (*list == NULL) {
		return -1;
	} else {
		//make temp variable to delte first element.
		ITEM* temp = *list;
		*list = temp->next;
		free(temp);
	}
	return 0;
}

/***************************************************/
/* Remove last item of the list                    */
/* Returns -1 if list==NULL, otherwise 0           */
/***************************************************/


int rem_last(ITEM **list)
{
	if (*list == NULL) {
		return -1;
	}
	
	ITEM* temp = *list;
	//1 item in list
	if (temp->next == NULL) {
		free(temp);
		return 0;
	}

	ITEM* before_last = *list;
	//iterate through list
	while (before_last->next->next != NULL) {
		before_last = before_last->next;
	}

	//free last item
	free(before_last->next);

	//assign new last item.
	before_last->next = NULL;

	return 0;
}

/***************************************************/
/* Remove item after c_item of the list            */
/* Returns -1 list==NULL, c_item not found or      */
/* c_item is the last_element                      */
/***************************************************/

int rem_after(ITEM *list, ITEM *c_item)
{
	if (list == NULL) {	//add c_item->next == NULL here?
		return -1;
	}

	ITEM* current_node = list;
	
	//iterate through list
	while (current_node != NULL) {
		if (current_node == c_item){
			if (current_node->next == NULL){	//c_item->next == NULL
				return -1;
			} else {
				ITEM* temp = current_node->next->next;
				free(current_node->next);
				current_node->next = temp;
				return 0;
			}
		}
		current_node = current_node->next;
	}

	//loop didn't find the current item
	return -1;
}

/*********************************************************/
/* All dynamic memory allocated to the list is freed     */
/* Empty list should point to NULL                       */
/*********************************************************/

void clean(ITEM **list)
{
	ITEM* current = *list;
	ITEM* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	return;
}

