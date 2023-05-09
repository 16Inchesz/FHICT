#include "statistics.h"

int find_maximum(int a, int b)
{
	int max;

	//if values are equal
	if (a == b){
		max = a;
	}

	//if a is bigger than b
	if (a > b) 
	{
		max = a;
	}
	
	//if b is bigger than a
	else if (b > a)
	{
		max = b;
	}

	return max;
}

bool find_maximum_array(int *array, int size, int *maximum){
	//NULL values
	if (array == NULL || maximum == NULL){
		return false;
	}

	//size none existent
	if (size <= 0){
		return false;
	}

	//iterate and find maximum
	for (int i = 0; i < size; i++){
		if (*array > *maximum){
			*maximum = *array;
		}
		array++;
	}
	return true;
}

bool sort_array(int *array, int size){
	//NULL ARRAY
	if (array == NULL){
		return false;
	}

	//too little to sort.
	if (size <= 1){
		return false;
	}

	//bubble sorting using swap
	for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(array + j) > *(array+j+1)) {    
				int temp = *(array+j);
				*(array+j) = *(array+j+1);
				*(array+j+1) = temp;
            }
        }
    }
	return true;
}

void PrintArray(int *array, int size){
	for (int i = 0; i < size; i++){
		printf("%d ", *array);
		array++;
	}
}