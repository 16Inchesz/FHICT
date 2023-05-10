#include "unity.h"
#include "skater.h"

//global variables 
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

//test cases
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

void test_search_winner_1(void){
    //assign
    Skater winner;
    bool expected_result = true;
    Skater expected_winner [MAX_NUMBER_SKATERS] = {{"John", 34, 420}};

    //act
    bool result = search_winner(skaters, number_of_skaters, &winner);

    //assert
    TEST_ASSERT_EQUAL(expected_result, result); //test if function ran smoothly.
    TEST_ASSERT_EQUAL_PTR(expected_winner, &winner);
}

void test_search_winner_2(void){
    //assign
    Skater winner;
    bool expected_result = false;
    
    //act
    bool result = search_winner(NULL, number_of_skaters, &winner);
    
    //assert
    TEST_ASSERT_EQUAL(expected_result, result);

}

void test_find_youngest_performer_1(void){
    //assign
    Skater youngest_performer;
    bool expected_result = true;
    Skater expected_performer [MAX_NUMBER_SKATERS] = {{"Rose", 17, 354}};

    //act
    bool result = find_youngest_performer(skaters, number_of_skaters, &youngest_performer);
    
    //assert
    TEST_ASSERT_EQUAL(expected_result, result);
    TEST_ASSERT_EQUAL_PTR(expected_performer, &youngest_performer);

}

int main(void)
{
    UnityBegin(0);
    RUN_TEST(test_update_score_by_name_1);
    RUN_TEST(test_update_score_by_name_2);
    RUN_TEST(test_search_winner_1);
    RUN_TEST(test_search_winner_2);
    RUN_TEST(test_find_youngest_performer_1);

    return UnityEnd();
}
