/*
 *	Description: 
 *		This VS code project
 *         - is meant to be used as start-up project for installing the Unity framework,
 *           and practicing with unit tests
 *         - consists of the following three modules:
 *             1) Module "statistics" consists of several functions performing 
 *				  statistical operations on integers (e.g. finding a maximum value)
 *             2) Module "main" provides an end-user with a console application 
 *				  to perform the operations of module “statistics”
 *             3) Module "main_test" provides software developers with a console application (main_test.exe) 
 *			      to check whether the functions in module "statistics" are functional. 
 *		
 *	Author : Brice Guayrin, b.guayrin@fontys.nl
 * 	Date: 7 April 2023
 */
 
#include <stdio.h>
#include "statistics.h"

int main()
{
    int option = -1;

    while (option != 0)
    {
        printf("\nMENU\n====\n");
        printf("1: Find maximum (of 2 values)\n");
        printf("2: Find maximum (of array)\n");
        printf("3: Sort array\n");
        printf("0: Stop program\n");
                
        scanf("%d", &option);
	
        switch(option)
        {
            case 1: 
            {
                int first_value, second_value;

                // Read inputs from terminal
                printf("\nEnter first value: \n");
                scanf("%d", &first_value);
                printf("\nEnter second value: \n");
                scanf("%d", &second_value);

                // Find minimum of two numbers
                int max = find_maximum(first_value, second_value);
                
                // Write output to terminal
                printf("\nMaximum value is: %d\n", max);
                break;
            }
            case 2:
                break;
            case 3:
                break;
            case 0:
                printf("Stop program");
                break;
            default:
                printf("Error: option %d is not available\n", option);
                break;
		}
	}
    return 0;
}