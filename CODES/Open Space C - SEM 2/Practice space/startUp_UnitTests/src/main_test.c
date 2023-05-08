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

#include "statistics.h"
#include "unity.h"

/*
 * Unity calls automatically function setUp before calling each unit tests
 * Writing code in setUp is optional but the function must exist
 */
void setUp(void)
{
     
}


/*
 * Unity calls automatically function tearDown after executing each unit tests
 * Writing code in tearDown is optional but the function must exist
 */
void tearDown(void)
{
    
}

int main(void)
{
    UnityBegin(0);

    return UnityEnd();
}
