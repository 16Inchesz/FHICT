// #include "unity.h"
#include "C:\Repositories\FHICT\CODES\Unity-master\src\unity.h"
#include "skater.h"

Skater skaters[MAX_NUMBER_SKATERS] = {  {"Anna", 22, 378}, {"John", 34, 420},
                                        {"Luca", 17, 280}, {"Mark", 28, 325},
                                        {"Rose", 17, 354}};
int number_of_skaters = 5;

void setUp(void)
{
     
}

void tearDown(void)
{
    
}

void test_update_score_by_name_1(void){
    //assign
    char first_name[MAX_NAME_SIZE] = "Mark";
    int new_score = 320;
    bool expected_result = true;
    Skater expected_skaters [MAX_NUMBER_SKATERS] = {    {"Anna", 22, 378}, {"John", 34, 420},
                                                        {"Luca", 17, 280}, {"Mark", 28, 320},
                                                        {"Rose", 17, 354}};
    

    //act
    bool result = update_score_by_name(skaters, number_of_skaters, first_name, new_score);

    //assert
    TEST_ASSERT_EQUAL(expected_result, result); //test if function returns true
    TEST_ASSERT_EQUAL_PTR_ARRAY(expected_skaters, skaters, number_of_skaters);  //test if new score is implemented
}

void test_update_score_by_name_2(void){
    //assign
    char first_name[MAX_NAME_SIZE] = "Jack";
    int new_score = 15;
    bool expected_result = false;
    Skater expected_skaters [MAX_NUMBER_SKATERS] = {    {"Anna", 22, 378}, {"John", 34, 420},
                                                        {"Luca", 17, 280}, {"Mark", 28, 325},
                                                        {"Rose", 17, 354}};

    //act
    bool result = update_score_by_name(skaters, number_of_skaters, first_name, new_score);

    //assert
    TEST_ASSERT_EQUAL(expected_result, result); //test if function returns false
    TEST_ASSERT_EQUAL_PTR_ARRAY(expected_skaters, skaters, number_of_skaters);  //test if new score has not indeed been implemented
} 

int main(void)
{
    UnityBegin(0);

    RUN_TEST(test_update_score_by_name_1);
    RUN_TEST(test_update_score_by_name_2);

    return UnityEnd();
}
