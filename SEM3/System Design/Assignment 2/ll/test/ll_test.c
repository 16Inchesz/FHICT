#include <string.h>

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

void test_add_after_no_elements(void){
  int ret;
  ITEM* list = NULL;
  ITEM* c_item = list;

  //verify behaviour
  ret = add_after(list, c_item, 1);
  TEST_ASSERT_EQUAL(-1, ret);

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

int main (int argc, char * argv[])
{
  UnityBegin();
  
  //add_first
  MY_RUN_TEST(test_add_first_no_elements);
  MY_RUN_TEST(test_add_first_multiple_elements);

  //add_last
  MY_RUN_TEST(test_add_last_no_elements);
  MY_RUN_TEST(test_add_last_multiple_elements);

  //add_after
  MY_RUN_TEST(test_add_after_no_elements);
  MY_RUN_TEST(test_add_after_c_item_NULL);
  MY_RUN_TEST(test_add_after_c_item_not_found);
  MY_RUN_TEST(test_add_after_multiple_elements);

  //rem_first

  //rem last

  //rem_after

  //clean


  return UnityEnd();
}
