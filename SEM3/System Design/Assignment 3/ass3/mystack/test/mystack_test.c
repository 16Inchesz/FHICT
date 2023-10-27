#include <string.h>
#include <stdio.h>

#include "mystack.h"
#include "unity.h"
#include "testrunner.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{
}

void tearDown(void)
{
    // This is run after EACH test
}


void test_stack_create(void){
	StackMeta_t *stack = mystack_create(sizeof(int));
    int a = 5;
    int expected_ret = 1;

    //verify behaviour
    mystack_push(stack, &a);
    int ret = mystack_nofelem(stack);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    mystack_destroy(stack);
}

void test_stack_push(void){
    StackMeta_t *stack = mystack_create(sizeof(int));
    int a = 5;
    int ret;
    int num_of_elements;
    int expected_ret = 0;
    int expected_elements = 1;

    //verify behaviour
    ret = mystack_push(stack, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    num_of_elements = mystack_nofelem(stack);
    TEST_ASSERT_EQUAL(expected_elements, num_of_elements);

    mystack_destroy(stack);
}

void test_stack_push_multiple(void){
    StackMeta_t *stack = mystack_create(sizeof(int));
    int a = 5;
    int b = 4;
    int ret;
    int num_of_elements;
    int expected_ret = 0;
    int expected_elements = 2;

    //verify behaviour
    ret = mystack_push(stack, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);
    ret = mystack_push(stack, &b);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    num_of_elements = mystack_nofelem(stack);
    TEST_ASSERT_EQUAL(expected_elements, num_of_elements);

    mystack_destroy(stack);
}

void test_stack_push_NULL_stack(void){
    int a = 5;
    int ret;
    int expected_ret = -1;

    ret = mystack_push(NULL, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);
}

void test_stack_push_NULL_obj(void){
    StackMeta_t *stack = mystack_create(sizeof(int));
    int ret;
    int expected_ret = -1;

    ret = mystack_push(stack, NULL);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    mystack_destroy(stack);
}

void test_stack_pop(void){
    StackMeta_t *stack = mystack_create(sizeof(int));
    int a = 5;
    int ret;
    int num_of_elements;
    int expected_ret = 0;
    int expected_elements = 0;

    //verify behaviour
    ret = mystack_push(stack, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    ret = mystack_pop(stack, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    num_of_elements = mystack_nofelem(stack);
    TEST_ASSERT_EQUAL(expected_elements, num_of_elements);

    mystack_destroy(stack);
}

void test_stack_pop_multiple(void){
    StackMeta_t *stack = mystack_create(sizeof(int));
    int a = 5;
    int b = 4;
    int ret;
    int num_of_elements;
    int expected_ret = 0;
    int expected_elements = 0;

    //verify behaviour
    ret = mystack_push(stack, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);
    ret = mystack_push(stack, &b);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    ret = mystack_pop(stack, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);
    ret = mystack_pop(stack, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    num_of_elements = mystack_nofelem(stack);
    TEST_ASSERT_EQUAL(expected_elements, num_of_elements);

    mystack_destroy(stack);
}

void test_stack_pop_no_elements(void){
    StackMeta_t *stack = mystack_create(sizeof(int));
    int ret;
    int a = 5;
    int num_of_elements;
    int expected_ret = -1;
    int expected_elements = 0;

    //verify behaviour
    num_of_elements = mystack_nofelem(stack);
    TEST_ASSERT_EQUAL(expected_elements, num_of_elements);

    ret = mystack_pop(stack, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    mystack_destroy(stack);
}

void test_stack_pop_NULL_stack(void){
    int a = 5;
    int ret;
    int expected_ret = -1;

    //verify behaviour
    ret = mystack_pop(NULL, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);
}

void test_stack_pop_NULL_obj(void){
    StackMeta_t *stack = mystack_create(sizeof(int));
    int ret;
    int expected_ret = -1;

    ret = mystack_pop(stack, NULL);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    mystack_destroy(stack);
}

void test_stack_destroy(void){
    StackMeta_t *stack = mystack_create(sizeof(int));
    int a = 5;
    int ret;
    int num_of_elements;
    int expected_ret = 0;
    int expected_elements = 1;

    //verify behaviour
    ret = mystack_push(stack, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    num_of_elements = mystack_nofelem(stack);
    TEST_ASSERT_EQUAL(expected_elements, num_of_elements);

    mystack_destroy(stack);
}

void test_stack_destroy_NULL(void){
	mystack_destroy(NULL);
}

void test_stack_deletion(void)
{
    StackMeta_t* stack = mystack_create(sizeof(int));
    int a = 5;
    int b = 4;
    int ret;

    //verify behaviour
    ret = mystack_push(stack, &a);
    TEST_ASSERT_EQUAL(0, ret);
    ret = mystack_push(stack, &b);
    TEST_ASSERT_EQUAL(0, ret);

    mystack_destroy(stack);
}

void test_stack_nofelem(void){
    StackMeta_t *stack = mystack_create(sizeof(int));
    int a = 5;
    int b = 4;
    int c = 0;
    int ret;
    int num_of_elements;
    int expected_ret = 0;
    int expected_elements = 3;

    //verify behaviour
    ret = mystack_push(stack, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);
    ret = mystack_push(stack, &b);
    TEST_ASSERT_EQUAL(expected_ret, ret);
    ret = mystack_push(stack, &c);
    TEST_ASSERT_EQUAL(expected_ret, ret);

    num_of_elements = mystack_nofelem(stack);
    TEST_ASSERT_EQUAL(expected_elements, num_of_elements);

    mystack_destroy(stack);
}

void test_stack_nofelem_NULL_stack(void){
    int ret;
    int expected_ret = -1;

    //verify behaviour
    ret = mystack_nofelem(NULL);
    TEST_ASSERT_EQUAL(expected_ret, ret);
}

int main (int argc, char * argv[]) {
	UnityBegin();
    //create
    MY_RUN_TEST(test_stack_create);
    //push
    MY_RUN_TEST(test_stack_push);
    MY_RUN_TEST(test_stack_push_NULL_stack);
    MY_RUN_TEST(test_stack_push_NULL_obj);
    //pop
    MY_RUN_TEST(test_stack_pop);
    MY_RUN_TEST(test_stack_pop_multiple);
    MY_RUN_TEST(test_stack_pop_no_elements);
    MY_RUN_TEST(test_stack_pop_NULL_stack);
    MY_RUN_TEST(test_stack_pop_NULL_obj);
    //destroy (check for memory leaks after running tests)
    MY_RUN_TEST(test_stack_destroy);
	MY_RUN_TEST(test_stack_destroy_NULL);
	MY_RUN_TEST(test_stack_deletion);
    //nofelem
    MY_RUN_TEST(test_stack_nofelem);
    MY_RUN_TEST(test_stack_nofelem_NULL_stack);

	return UnityEnd();
}
