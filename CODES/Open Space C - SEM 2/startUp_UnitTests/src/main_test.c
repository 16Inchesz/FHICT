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
#include "/Repositories/FHICT/CODES/Unity-master/src/unity.h"


/*
 * Unity calls automatically function setUp before calling each unit tests
 * Writing code in setUp is optional but the function must exist
 */
void setUp(void)
{
    printf("\nRUN BEFORE TEST \n");
}


/*
 * Unity calls automatically function tearDown after executing each unit tests
 * Writing code in tearDown is optional but the function must exist
 */
void tearDown(void)
{
    printf("\nRUN AFTER TEST \n");
}

void test_find_maximum_1(void){
    //ARRANGE
    int firstInput = 1;
    int secondInput = 2;
    int expectedResult = 2;

    //ACT
    int actualResult = find_maximum(firstInput, secondInput);

    //ASSERT
    TEST_ASSERT_EQUAL_INT(expectedResult, actualResult);
}

void test_find_maximum_array_1(void){
    //ARRANGE
    int a[4] = {4,3,7,6};
    int array_size = sizeof(a) / sizeof(a[0]);
    int expectedResult = 7;
    int actual_result = 0;
    bool expected_status = true;
    bool actual_status = false;

    //ACT
    actual_status = find_maximum_array(a, array_size, &actual_result);

    //ASSERT
    TEST_ASSERT_EQUAL_INT(expectedResult, actual_result);
    TEST_ASSERT_EQUAL_INT(expected_status, actual_status);
}

int main(void)
{
    UnityBegin(0);
    test_find_maximum_array_1();
    return UnityEnd();
}
