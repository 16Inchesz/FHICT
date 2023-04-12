#ifndef STATISTICS_H
#define STATISTICS_H

#include "stdbool.h"
#include "stdint.h"

/*
 *	Function finds and returns the maximum value of the two inputs variables
 *  Input(s):
 *      - a: first integer input
 *      - b: second integer input
 *  Output(s):
 *      - maximum of the two integer inputs
 */
int find_maximum(int a, int b);

/*
 *	Function finds the maximum value of an array of integers
 *  Input(s):
 *      - array: pointer to the first element of an array of integers
 *      - size: number of elements in the array of integers
 *      - maximum: pointer to the maximum value in the array of integers
 *  Output(s):
 *      - Boolean indicating the successful execution of the function 
 *        (e.g. return false if at least one of the input pointers is NULL)
 */
bool find_maximum_array(int* array, int size, int* maximum);

/*
 *  Function sorts the an array of integers in ascending order
 *  Input(s):
 *      - array: pointer to the first element of an array of integers
 *      - size: number of elements in the array of integers
 *  Output(s):
 *      - Boolean indicating the successful execution of the function  
 *       (e.g. return false if at least one of the input pointers is NULL)
 */
bool sort_array(int* array, int size);


#endif