#include "sort.h"

/*
 * Function swaps the values pointed to by pointers x and y 
 */
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/*
 * Function sorts in ascending order the values pointed to by pointers a, b and c
 */
void sort3(int* a, int* b, int* c)
{
	if (*a > *b) {
		swap(a,b);
	}

	if (*a > *c) {
		swap(a,c);
	}

	if (*b > *c) {
		swap(b,c);
	}
}

