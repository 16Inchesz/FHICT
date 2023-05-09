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
// #include "unity.h"
#include "C:\Repositories\FHICT\CODES\Unity-master\src\unity.h"

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

//a is bigger than b
void TestFindMaximum1(void){
    //assign
    int a = 4;
    int b = 2;
    int expectedResult = 4;

    //act
    int result = find_maximum(a, b);

    //assert
    TEST_ASSERT_EQUAL_INT(expectedResult, result);
}

//b is bigger than a
void TestFindMaximum2(void){
    //assign
    int a = 3;
    int b = 7;
    int expectedResult = 7;

    //act
    int result = find_maximum(a, b);

    //assert
    TEST_ASSERT_EQUAL_INT(expectedResult, result);
}

//a and b are equal
void TestFindMaximum3(void){
    //assign
    int a = 4;
    int b = 4;
    int expectedResult = 4;

    //act
    int result = find_maximum(a, b);

    //assert
    TEST_ASSERT_EQUAL_INT(expectedResult, result);
}

//function runs smoothly
void TestFindMaximumArray1(void){
    //assign
    int array1[MAX_ARRAY_SIZE] = {9, 3, 2, 5};
    int maximum = 0;
    int expectedvalue = 9;
    bool expectedResult = true;
    
    //act
    bool result = find_maximum_array(array1, MAX_ARRAY_SIZE, &maximum);

    //assert
    TEST_ASSERT_EQUAL(expectedResult, result);
    TEST_ASSERT_EQUAL_INT(expectedvalue, maximum);

}

//function has null array
void TestFindMaximumArray2(void){
    //assign
    int maximum = 0;
    int expectedResult = false;
    
    //act
    bool result = find_maximum_array(NULL, MAX_ARRAY_SIZE, &maximum);

    //assert
    TEST_ASSERT_EQUAL(expectedResult, result);

}

//function has null pointer maximum
void TestFindMaximumArray3(void){
    //assign
    int array1[MAX_ARRAY_SIZE] = {9, 3, 2, 5};
    int expectedResult = false;
    
    //act
    bool result = find_maximum_array(array1, MAX_ARRAY_SIZE, NULL);

    //assert
    TEST_ASSERT_EQUAL(expectedResult, result);

}

//function has size equal to or smaller than 0
void TestFindMaximumArray4(void){
    //assign
    int array1[MAX_ARRAY_SIZE] = {9, 3, 2, 5};
    int maximum = 0;
    int noSize = 0;
    bool expectedResult = false;
    
    //act
    bool result = find_maximum_array(array1, noSize, &maximum);

    //assert
    TEST_ASSERT_EQUAL(expectedResult, result);
}

//function run smoothly
void TestSortArray1(void){
    //assign
    int array1[MAX_ARRAY_SIZE] = {2, 6, 1, 3};
    int expectedArray[MAX_ARRAY_SIZE] = {1, 2, 3, 6};
    int expectedResult = true;

    //act
    bool result = sort_array(array1, MAX_ARRAY_SIZE);

    //assert
    TEST_ASSERT_EQUAL(expectedResult, result);
    TEST_ASSERT_EQUAL_INT_ARRAY(expectedArray, array1, MAX_ARRAY_SIZE); //check to see if arrays match
}

//Function has null pointer
void TestSortArray2(void){
    //assign
    int expectedResult = false;

    //act
    bool result = sort_array(NULL, MAX_ARRAY_SIZE);

    //assert
    TEST_ASSERT_EQUAL(expectedResult, result);
}

//Function has too little to sort.
void TestSortArray3(void){
    //assign
    int array1[MAX_ARRAY_SIZE] = {2, 6, 1, 3};
    int expectedArray[MAX_ARRAY_SIZE] = {2, 6, 1, 3};
    int noSize = 0;
    int expectedResult = false;

    //act
    bool result = sort_array(array1, noSize);

    //assert
    TEST_ASSERT_EQUAL(expectedResult, result);
    TEST_ASSERT_EQUAL_INT_ARRAY(expectedArray, array1, MAX_ARRAY_SIZE); //check to see if arrays match (stays the same)
}

int main(void)
{
    UnityBegin(0);

    //RUN TEST
    RUN_TEST(TestFindMaximum1);
    RUN_TEST(TestFindMaximum2);
    RUN_TEST(TestFindMaximum3);
    RUN_TEST(TestFindMaximumArray1);
    RUN_TEST(TestFindMaximumArray2);
    RUN_TEST(TestFindMaximumArray3);
    RUN_TEST(TestFindMaximumArray4);
    RUN_TEST(TestSortArray1);
    RUN_TEST(TestSortArray2);
    RUN_TEST(TestSortArray3);

    return UnityEnd();
}
