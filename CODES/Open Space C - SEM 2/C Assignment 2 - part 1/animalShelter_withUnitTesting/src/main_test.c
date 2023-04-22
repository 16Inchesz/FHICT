#include "animal.h"
#include "unity.h"


//animals array for testing
Animal animal_test[MAX_NUMBER_ANIMAL] = {{"Crouton", 1, 1}, {"Casper", 1, 2}, {"Nova", 2, 3},
                                     {"Mocha", 2, 4}, {"Taco", 0, 20}, {"Sambal", 3, 5}};

void setUp(void){}

void tearDown(void){}

//show animals------------------------------------------------------------------------------------------------------------------
void test_show_animals_happy(void){
    int number_of_animals = 6;

    //result 1 = Happy flow
    bool result_1 = show_animals(animal_test, number_of_animals);
    bool expected_result_1 = true;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
    
}

void test_show_animals_no_animals(void){
    bool result_1 = show_animals(animal_test, 0);
    bool expected_result_1 = true;
    
    TEST_ASSERT_EQUAL(expected_result_1, result_1);
}

void test_show_animals_NULL_animals(void){
    int number_of_animals = 6;

    bool result_2 = show_animals(NULL, number_of_animals);
    bool expected_result_2 = false;

    TEST_ASSERT_EQUAL(expected_result_2, result_2);
}

void test_show_animals_negative_input(void){
    int negative_number_of_animals = -1;
    
    bool result_3 = show_animals(animal_test, negative_number_of_animals);
    bool expected_result_3 = false;

    TEST_ASSERT_EQUAL(expected_result_3, result_3);
}

//add animal------------------------------------------------------------------------------------------------------------------
void test_add_animal_happy(void){
    int number_of_animals = 6;
    Animal new_animal_test = {"Test", 2, 7};

    //result 1 = happy flow.
    bool result_1 = add_animal_unit_test(animal_test, &number_of_animals, new_animal_test);
    bool expected_result_1 = true;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
}

void test_add_animal_NULL_animals(void){
    int number_of_animals = 6;
    Animal new_animal_test = {"Test", 2, 7};

    bool result_1 = add_animal_unit_test(NULL, &number_of_animals, new_animal_test);
    bool expected_result_1 = false;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
}

void test_add_animal_NULL_number_animals(void){
    Animal new_animal_test = {"Test", 2, 7};

    //result 2 = NULL number of animals
    bool result_2 = add_animal_unit_test(animal_test, NULL, new_animal_test);
    bool expected_result_2 = false;

    TEST_ASSERT_EQUAL(expected_result_2, result_2);
}

void test_add_animal_full_shelter(void){
    int max_num_of_animals = MAX_NUMBER_ANIMAL;
    Animal new_animal_test = {"Test", 2, 7};

    bool result_3 = add_animal_unit_test(animal_test, &max_num_of_animals, new_animal_test);
    bool expected_result_3 = true;

    TEST_ASSERT_EQUAL(expected_result_3, result_3);
}

void test_add_animal_same_chip_number(void){
    int number_of_animals = 6;
    Animal new_animal_test_unhappy = {"Test", 2, 1};

    bool result_4 = add_animal_unit_test(animal_test, &number_of_animals, new_animal_test_unhappy);
    bool expected_result_4 = true;

    TEST_ASSERT_EQUAL(expected_result_4, result_4);
}

//search animal------------------------------------------------------------------------------------------------------------------
void test_search_animal_happy(void){
    int number_of_animals = 6;
    char searched_name[MAX_LENGTH_NAME] = "Crouton";

    //result 1 = happy flow
    bool result_1 = search_animal_by_name_unit_test(animal_test, number_of_animals, searched_name);
    bool expected_result_1 = true;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
}

void test_search_animal_unknown_name(void){
    int number_of_animals = 6;
    char searched_name[MAX_LENGTH_NAME] = "Peanut";

    bool result_1 = search_animal_by_name_unit_test(animal_test, number_of_animals, searched_name);
    bool expected_result_1 = true;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
}

void test_search_animal_NULL_animal(void){
    int number_of_animals = 6;
    char searched_name[MAX_LENGTH_NAME] = "Peanut";

    bool result_2 = search_animal_by_name_unit_test(NULL, number_of_animals, searched_name);
    bool expected_result_2 = false;

    TEST_ASSERT_EQUAL(expected_result_2, result_2);
}

void test_search_animal_negative_input(void){
    int negative_number_of_animals = -1;
    char searched_name[MAX_LENGTH_NAME] = "Peanut";

    bool result_3 = search_animal_by_name_unit_test(animal_test, negative_number_of_animals, searched_name);
    bool expected_result_3 = false;

    TEST_ASSERT_EQUAL(expected_result_3, result_3);
}

//update animal species------------------------------------------------------------------------------------------------------------------
void test_update_animal_happy(void){
    int number_of_animals = 6;
    int searched_chip_number = 1;
    int new_animal_species = 0;

    //result 1 = happy flow.
    bool result_1 = update_animal_species_unit_test(animal_test, number_of_animals, searched_chip_number, new_animal_species);
    bool expected_result_1 = true;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
    
}

void test_update_animal_NULL_animal(void){
    int number_of_animals = 6;
    int searched_chip_number = 100;
    int new_animal_species = 0;

    bool result_1 = update_animal_species_unit_test(NULL, number_of_animals, searched_chip_number, new_animal_species);
    bool expected_result_1 = false;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
}

void test_update_animal_unknown_chip_number(void){
    int number_of_animals = 6;
    int searched_chip_number = 100;
    int new_animal_species = 0;

    bool result_2 = update_animal_species_unit_test(animal_test, number_of_animals, searched_chip_number, new_animal_species);
    bool expected_result_2 = true;

    TEST_ASSERT_EQUAL(expected_result_2, result_2);
}

void test_update_animal_negative_input(void){
    int negative_number_of_animals = -1;
    int searched_chip_number = 100;
    int new_animal_species = 0;

    bool result_3 = update_animal_species_unit_test(animal_test, negative_number_of_animals, searched_chip_number, new_animal_species);
    bool expected_result_3 = false;

    TEST_ASSERT_EQUAL(expected_result_3, result_3);
}

//remove animal------------------------------------------------------------------------------------------------------------------
void test_remove_animal_happy(void){
    int number_of_animals = 6;
    int chip_number = 5;
    
    //result 1 = happy flow
    bool result_1 = remove_animal_by_chip_number_unit_test(animal_test, &number_of_animals, chip_number);
    bool expected_result_1 = true;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
}

void test_remove_animal_NULL_animal(void){
    int number_of_animals = 6;
    int chip_number = 100;

    bool result_1 = remove_animal_by_chip_number_unit_test(NULL, &number_of_animals, chip_number);
    bool expected_result_1 = false;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
}

void test_remove_anime_NULL_number_of_animals(void){
    int chip_number = 100;

    bool result_2 = remove_animal_by_chip_number_unit_test(animal_test, NULL, chip_number);
    bool expected_result_2 = false;

    TEST_ASSERT_EQUAL(expected_result_2, result_2);
}

void test_remove_animal_no_animals_in_shelter(void){
    int number_of_animals_none = 0;
    int chip_number = 100;

    bool result_3 = remove_animal_by_chip_number_unit_test(animal_test, &number_of_animals_none, chip_number);
    bool expected_result_3 = true;

    TEST_ASSERT_EQUAL(expected_result_3, result_3);
}

void test_remove_animal_unknown_chip_number(void){
    int number_of_animals = 6;
    int chip_number = 100;

    //result 4 = animal with chip number not found
    bool result_4 = remove_animal_by_chip_number_unit_test(animal_test, &number_of_animals, chip_number);
    bool expected_result_4 = true;

    TEST_ASSERT_EQUAL(expected_result_4, result_4);
}

//sort animal------------------------------------------------------------------------------------------------------------------
void test_sort_animal_happy(void){
    int number_of_animals = 6;

    //result 1 = happy flow
    bool result_1 = sort_animals(animal_test, number_of_animals);
    bool expected_result_1 = true;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
}

void test_sort_animal_NULL_animal(void){
    int number_of_animals = 6;

    bool result_1 = sort_animals(NULL, number_of_animals);
    bool expected_result_1 = false;

    TEST_ASSERT_EQUAL(expected_result_1, result_1);
}

void test_sort_animal_unable_to_sort(void){
    int number_of_animals_low = 1;

    bool result_2 = sort_animals(animal_test, number_of_animals_low);
    bool expected_result_2 = true;

    TEST_ASSERT_EQUAL(expected_result_2, result_2);
}

void test_sort_animal_negative_input(void){
    int negative_number_of_animals = -1;

    bool result_3 = sort_animals(animal_test, negative_number_of_animals);
    bool expected_result_3 = false;

    TEST_ASSERT_EQUAL(expected_result_3, result_3);

}

//-------------------------------------------------------------------------------------------------------------------------------


int main(void)
{
    UnityBegin(0);
    
    //show animals
    RUN_TEST(test_show_animals_happy);
    RUN_TEST(test_show_animals_negative_input);
    RUN_TEST(test_show_animals_no_animals);
    RUN_TEST(test_show_animals_NULL_animals);

    //add animals
    RUN_TEST(test_add_animal_happy);
    RUN_TEST(test_add_animal_full_shelter);
    RUN_TEST(test_add_animal_NULL_animals);
    RUN_TEST(test_add_animal_NULL_number_animals);
    RUN_TEST(test_add_animal_same_chip_number);

    //search animals
    RUN_TEST(test_search_animal_happy);
    RUN_TEST(test_search_animal_negative_input);
    RUN_TEST(test_search_animal_NULL_animal);
    RUN_TEST(test_search_animal_unknown_name);

    //update animals
    RUN_TEST(test_update_animal_happy);
    RUN_TEST(test_update_animal_negative_input);
    RUN_TEST(test_update_animal_NULL_animal);
    RUN_TEST(test_update_animal_unknown_chip_number);

    //remove animals
    RUN_TEST(test_remove_animal_happy);
    RUN_TEST(test_remove_animal_NULL_animal);
    RUN_TEST(test_remove_animal_no_animals_in_shelter);
    RUN_TEST(test_remove_animal_unknown_chip_number);
    RUN_TEST(test_remove_anime_NULL_number_of_animals);

    //sort animals
    RUN_TEST(test_sort_animal_happy);
    RUN_TEST(test_sort_animal_negative_input);
    RUN_TEST(test_sort_animal_NULL_animal);
    RUN_TEST(test_sort_animal_unable_to_sort);

    return UnityEnd();
}
