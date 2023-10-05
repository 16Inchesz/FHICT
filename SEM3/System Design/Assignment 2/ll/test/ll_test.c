#include <string.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "unity.h"

#define MY_RUN_TEST(func) RUN_TEST(func, 0)


void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
  // This is run after EACH test
}

//---------------------------------------------------
void test_add_first_no_elements(void)
{
  int ret;
  ITEM *list = NULL;

  //verify behaviour
  ret = add_first(&list, 1);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order
  TEST_ASSERT_EQUAL(1, list->value);
  
  clean(&list);
}

void test_add_first_multiple_elements(void){
  int ret;
  ITEM* list = NULL;

  //verify behaviour
  ret = add_first(&list, 3);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_first(&list, 2);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_first(&list, 1);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order.
  TEST_ASSERT_EQUAL(1, list->value);
  TEST_ASSERT_EQUAL(2, list->next->value);
  TEST_ASSERT_EQUAL(3, list->next->next->value);

  clean(&list);
}

void test_add_first_negative_element(void){
  int ret;
  ITEM* list = NULL;

  //verify behaviour
  ret = add_first(&list, 3);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_first(&list, -1);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_first(&list, 1);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order.
  TEST_ASSERT_EQUAL(1, list->value);
  TEST_ASSERT_EQUAL(-1, list->next->value);
  TEST_ASSERT_EQUAL(3, list->next->next->value);

  clean(&list);
}

void test_add_first_big_element(void){
  int ret;
  ITEM* list = NULL;

  //verify behaviour
  ret = add_first(&list, 3);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_first(&list, 100000);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_first(&list, 1);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order.
  TEST_ASSERT_EQUAL(1, list->value);
  TEST_ASSERT_EQUAL(100000, list->next->value);
  TEST_ASSERT_EQUAL(3, list->next->next->value);

  clean(&list);
}

void test_add_last_no_elements(void){
  int ret;
  ITEM *list = NULL;
  
  //verify behaviour
  ret = add_last(&list, 1);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order
  TEST_ASSERT_EQUAL(1, list->value);

  clean(&list);
}

void test_add_last_multiple_elements(void){
  int ret;
  ITEM* list = NULL;

  //verify behaviour
  ret = add_last(&list, 3);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_last(&list, 2);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_last(&list, 1);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order. 
  TEST_ASSERT_EQUAL(3, list->value);
  TEST_ASSERT_EQUAL(2, list->next->value);
  TEST_ASSERT_EQUAL(1, list->next->next->value);

  clean(&list);
}

void test_add_last_negative_element(void){
  int ret;
  ITEM* list = NULL;

  //verify behaviour
  ret = add_last(&list, 3);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_last(&list, -111111);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_last(&list, 1);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order. 
  TEST_ASSERT_EQUAL(3, list->value);
  TEST_ASSERT_EQUAL(-111111, list->next->value);
  TEST_ASSERT_EQUAL(1, list->next->next->value);

  clean(&list);
}

void test_add_last_big_element(void){
  int ret;
  ITEM* list = NULL;

  //verify behaviour
  ret = add_last(&list, 3);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_last(&list, 111111);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_last(&list, 1);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order. 
  TEST_ASSERT_EQUAL(3, list->value);
  TEST_ASSERT_EQUAL(111111, list->next->value);
  TEST_ASSERT_EQUAL(1, list->next->next->value);

  clean(&list);
}

void test_add_after_NULL_list(void){
  int ret;
  ITEM* list = NULL;
  ITEM* c_item = list;

  //verify behaviour
  ret = add_after(list, c_item, 1);
  TEST_ASSERT_EQUAL(-1, ret);
  TEST_ASSERT_NULL(list);

  clean(&list);
}

void test_add_after_c_item_NULL(void){
  int ret;
  ITEM* list = NULL;

  add_first(&list, 3);
  add_first(&list, 2);

  ITEM* c_item = NULL;

  //verify behaviour
  ret = add_after(list, c_item, 1);
  TEST_ASSERT_EQUAL(-1, ret);

  clean(&list);
}

void test_add_after_c_item_not_found(void){
  int ret;
  ITEM* list = NULL;

  add_first(&list, 3);
  add_first(&list, 2);

  ITEM* c_item = list->next->next;  //list of 2 elements, c_item points to NULL.

  //verify behaviour
  ret = add_after(list, c_item, 1);
  TEST_ASSERT_EQUAL(-1, ret);

  clean(&list);
}

void test_add_after_multiple_elements(void){
  int ret;
  ITEM* list = NULL;

  add_first(&list, 3);
  add_first(&list, 2);

  ITEM* c_item = list;  //after first element

  //verify behaviour
  ret = add_after(list, c_item, 1);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order
  TEST_ASSERT_EQUAL(2, list->value);
  TEST_ASSERT_EQUAL(1, list->next->value);
  TEST_ASSERT_EQUAL(3, list->next->next->value);

  clean(&list);
}

void test_rem_first_multiple_elements(void){
  int ret;
  ITEM* list = NULL;
  add_first(&list, 3);
  add_first(&list, 2);
  add_first(&list, 1);

  //verify behaviour
  ret = rem_first(&list);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order
  TEST_ASSERT_EQUAL(2, list->value);
  TEST_ASSERT_EQUAL(3, list->next->value);

  clean(&list);
}

void test_rem_first_single_element(void){
  int ret;
  ITEM* list = NULL;
  add_first(&list, 3);

  //verify behaviour
  ret = rem_first(&list);
  TEST_ASSERT_EQUAL(0, ret);

  clean(&list);
}

void test_rem_first_NULL_list(void){
  int ret;
  ITEM* list = NULL;

  //verify behaviour
  ret = rem_first(&list);
  TEST_ASSERT_EQUAL(-1, ret);
  TEST_ASSERT_NULL(list);

  clean(&list);
}

void test_rem_last_multiple_elements(void){
  int ret;
  ITEM* list = NULL;
  add_first(&list, 3);
  add_first(&list, 2);
  add_first(&list, 1);

  //verify behaviour
  ret = rem_last(&list);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order
  TEST_ASSERT_EQUAL(1, list->value);
  TEST_ASSERT_EQUAL(2, list->next->value);

  clean(&list);
}

void test_rem_last_single_element(void){
  int ret;
  ITEM* list = NULL;
  add_first(&list, 3);

  //verify behaviour
  ret = rem_last(&list);
  TEST_ASSERT_EQUAL(0, ret);
}

void test_rem_last_NULL_list(void){
  int ret;
  ITEM* list = NULL;

  //verify behaviour
  ret = rem_last(&list);
  TEST_ASSERT_EQUAL(-1, ret);
  TEST_ASSERT_NULL(list);

  clean(&list);
}

void test_rem_after_NULL_list(void){
  int ret;
  ITEM* list = NULL;
  ITEM* c_item = list;

  //verify behaviour
  ret = rem_after(list, c_item);
  TEST_ASSERT_EQUAL(-1, ret);
  TEST_ASSERT_NULL(list);

  clean(&list);
}

void test_rem_after_c_item_not_found(void){
  int ret;
  ITEM* list = NULL;

  add_first(&list, 3);
  add_first(&list, 2);

  ITEM* c_item = list->next->next;  //list of 2 elements, c_item points to NULL.

  //verify behaviour
  ret = rem_after(list, c_item);
  TEST_ASSERT_EQUAL(-1, ret);

  clean(&list);
}

void test_rem_after_c_item_last_element(void){
  int ret;
  ITEM* list = NULL;

  add_first(&list, 3);
  add_first(&list, 2);

  ITEM* c_item = list->next;  //list of 2 elements c_item is the last element.

  //verify behaviour
  ret = rem_after(list, c_item);
  TEST_ASSERT_EQUAL(-1, ret);

  //verify order
  TEST_ASSERT_EQUAL(2, list->value);
  TEST_ASSERT_EQUAL(3, list->next->value);

  clean(&list);
}

void test_rem_after_multiple_elements(void){
  int ret;
  ITEM* list = NULL;

  add_first(&list, 3);
  add_first(&list, 2);
  add_first(&list, 1);
  
  ITEM* c_item = list->next;  //list of 3 elements c_item is the second element.

  //verify behaviour
  ret = rem_after(list, c_item);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order
  TEST_ASSERT_EQUAL(1, list->value);
  TEST_ASSERT_EQUAL(2, list->next->value);

  clean(&list);
}

void test_clean(void){
  int ret;
  ITEM* list = NULL;

  add_first(&list, 11);
  add_last(&list, 2);

  ITEM* c_item = list;  //after first element

  //verify behaviour
  ret = add_after(list, c_item, 1);
  TEST_ASSERT_EQUAL(0, ret);

  //verify order
  TEST_ASSERT_EQUAL(11, list->value);
  TEST_ASSERT_EQUAL(1, list->next->value);
  TEST_ASSERT_EQUAL(2, list->next->next->value);

  //clean function
  clean(&list);

  TEST_ASSERT_NULL(list);
}

int main (int argc, char * argv[])
{
  UnityBegin();

  
  //add_first
  MY_RUN_TEST(test_add_first_no_elements);
  MY_RUN_TEST(test_add_first_multiple_elements);
  MY_RUN_TEST(test_add_first_negative_element);
  MY_RUN_TEST(test_add_first_big_element);

  //add_last
  MY_RUN_TEST(test_add_last_no_elements);
  MY_RUN_TEST(test_add_last_multiple_elements);
  MY_RUN_TEST(test_add_last_negative_element);
  MY_RUN_TEST(test_add_last_big_element);

  //add_after
  MY_RUN_TEST(test_add_after_NULL_list);
  MY_RUN_TEST(test_add_after_c_item_NULL);
  MY_RUN_TEST(test_add_after_c_item_not_found);
  MY_RUN_TEST(test_add_after_multiple_elements);

  //rem_first
  MY_RUN_TEST(test_rem_first_multiple_elements);
  MY_RUN_TEST(test_rem_first_single_element);
  MY_RUN_TEST(test_rem_first_NULL_list);

  //rem last
  MY_RUN_TEST(test_rem_last_multiple_elements);
  MY_RUN_TEST(test_rem_last_single_element);
  MY_RUN_TEST(test_rem_last_NULL_list);
  
  //rem_after
  MY_RUN_TEST(test_rem_after_NULL_list);
  MY_RUN_TEST(test_rem_after_c_item_not_found);
  MY_RUN_TEST(test_rem_after_c_item_last_element);
  MY_RUN_TEST(test_rem_after_multiple_elements);
  
  //clean tests
  MY_RUN_TEST(test_clean);


  return UnityEnd();
}
