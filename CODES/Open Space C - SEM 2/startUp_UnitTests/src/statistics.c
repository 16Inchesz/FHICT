#include "statistics.h"
#include <stdint.h>

int find_maximum(int a, int b)
{
	int max;
	if (a>b) 
	{
		max=a;
	}
	else
	{
		max=b;
	}
	return max;
}

bool find_maximum_array(int a[], int array_size, int *result){
	*result = INT_MIN;

	if ((a == NULL) || (result == NULL)){
		return false;
	}

	for (int i = 0; i < array_size; i++){
		if (a[i] > *result){
			*result = a[i];
		}
	}
	return true;
}