#include <string.h>
#include <stdio.h>
#include "mystack.h"
#include "myqueue.h"
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

void test_queue_create(void){
	QueueMeta_t *queue = myqueue_create(sizeof(int));
	int a = 5;
	int ret;
	int num_of_elements;
	int expected_ret = 0;
	int expected_elements_before = 1;
	int expected_elements_after = 0;

	//verify behaviour
	//enqueue
	ret = myqueue_enqueue(queue, &a);
	TEST_ASSERT_EQUAL(expected_ret, ret);
	num_of_elements = mystack_nofelem(queue->stack_in);
	TEST_ASSERT_EQUAL(expected_elements_before, num_of_elements);
	
	//dequeue
	ret = myqueue_dequeue(queue, &a);
	TEST_ASSERT_EQUAL(expected_ret, ret);
	num_of_elements = mystack_nofelem(queue->stack_in);
	TEST_ASSERT_EQUAL(expected_elements_after, num_of_elements);

	myqueue_delete(queue);
}

void test_queue_delete(void){
	QueueMeta_t *queue = myqueue_create(sizeof(int));
	int a = 5;
	int b = 4;
	int c = 3;
	int num_of_elements_S1;
	int num_of_elements_S2;
	int ret;
	int expected_ret = 0;

	myqueue_enqueue(queue, &a);
	myqueue_enqueue(queue, &b);
	myqueue_enqueue(queue, &c);
	num_of_elements_S1 = mystack_nofelem(queue->stack_in);
	TEST_ASSERT_EQUAL(3, num_of_elements_S1);

	myqueue_dequeue(queue, &a);
	num_of_elements_S1 = mystack_nofelem(queue->stack_in);
	num_of_elements_S2 = mystack_nofelem(queue->stack_out);
	TEST_ASSERT_EQUAL(0, num_of_elements_S1);
	TEST_ASSERT_EQUAL(2, num_of_elements_S2);
	
	myqueue_delete(queue);
}

void test_queue_delete_NULL_queue(void){
	myqueue_delete(NULL);
}

void test_queue_enqueue(void){
	QueueMeta_t *queue = myqueue_create(sizeof(int));
	int a = 5;
	int ret;
	int num_of_elements_S1;
	int expected_ret = 0;
	int expected_elements = 1;

	ret = myqueue_enqueue(queue, &a);
	TEST_ASSERT_EQUAL(expected_ret, ret);

	num_of_elements_S1 = mystack_nofelem(queue->stack_in);
	TEST_ASSERT_EQUAL(expected_elements, num_of_elements_S1); 

	myqueue_delete(queue);
}

void test_queue_enqueue_multiple(void){
	QueueMeta_t *queue = myqueue_create(sizeof(int));
	int a = 5;
	int b = 4;
	int ret;
	int num_of_elements_S1;
	int expected_ret = 0;
	int expected_elements = 2;

	ret = myqueue_enqueue(queue, &a);
	TEST_ASSERT_EQUAL(expected_ret, ret);
	ret = myqueue_enqueue(queue, &b);
	TEST_ASSERT_EQUAL(expected_ret, ret);

	num_of_elements_S1 = mystack_nofelem(queue->stack_in);
	TEST_ASSERT_EQUAL(expected_elements, num_of_elements_S1); 

	myqueue_delete(queue);
}

void test_queue_enqueue_NULL_queue(void){
	int a = 5;
    int ret;
    int expected_ret = -1;

    //verify behaviour
    ret = myqueue_enqueue(NULL, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);
}

void test_queue_enqueue_NULL_object(void){
	QueueMeta_t *queue = myqueue_create(sizeof(int));
	int ret;
    int expected_ret = -1;

    ret = myqueue_enqueue(queue, NULL);
    TEST_ASSERT_EQUAL(expected_ret, ret);

	myqueue_delete(queue);
}

void test_queue_dequeue(void){
	QueueMeta_t *queue = myqueue_create(sizeof(int));
	int a = 5;
	int ret;
	int num_of_elements;
	int expected_ret = 0;
	int expected_elements_before = 1;
	int expected_elements_after = 0;

	//verify behaviour
	//enqueue
	ret = myqueue_enqueue(queue, &a);
	TEST_ASSERT_EQUAL(expected_ret, ret);
	num_of_elements = mystack_nofelem(queue->stack_in);
	TEST_ASSERT_EQUAL(expected_elements_before, num_of_elements);
	
	//dequeue
	ret = myqueue_dequeue(queue, &a);
	TEST_ASSERT_EQUAL(expected_ret, ret);
	num_of_elements = mystack_nofelem(queue->stack_in);
	TEST_ASSERT_EQUAL(expected_elements_after, num_of_elements);

	myqueue_delete(queue);
}

void test_queue_dequeue_multiple(void){
	QueueMeta_t *queue = myqueue_create(sizeof(int));
	int a = 5;
	int b = 4;
	int ret;
	int num_of_elements_S1;
	int num_of_elements_S2;
	int expected_ret = 0;
	int expected_elements_before_S1 = 2;
	int expected_elements_before_S2 = 0;
	int expected_element_after_S1 = 0;
	int expected_element_after_S2 = 1;

	//enqueue 2 elements
	ret = myqueue_enqueue(queue, &a);
	TEST_ASSERT_EQUAL(expected_ret, ret);
	ret = myqueue_enqueue(queue, &b);
	TEST_ASSERT_EQUAL(expected_ret, ret);

	//2 elems in S1 and 0 in S2
	num_of_elements_S1 = mystack_nofelem(queue->stack_in);
	num_of_elements_S2 = mystack_nofelem(queue->stack_out);
	TEST_ASSERT_EQUAL(expected_elements_before_S1, num_of_elements_S1);
	TEST_ASSERT_EQUAL(expected_elements_before_S2, num_of_elements_S2);


	ret = myqueue_dequeue(queue, &a);
	TEST_ASSERT_EQUAL(expected_ret, ret);

	num_of_elements_S1 = mystack_nofelem(queue->stack_in);
	num_of_elements_S2 = mystack_nofelem(queue->stack_out);
	TEST_ASSERT_EQUAL(expected_element_after_S1, num_of_elements_S1);
	TEST_ASSERT_EQUAL(expected_element_after_S2, num_of_elements_S2);

	myqueue_delete(queue);
}

void test_queue_dequeue_no_elements(void){
	QueueMeta_t *queue = myqueue_create(sizeof(int));
	int a = 5;
	int ret;
	int num_of_elements;
	int expected_ret = -1;
    int expected_elements_S1 = 0;
	int expected_elements_S2 = 0;

	//no elements present
	num_of_elements = mystack_nofelem(queue->stack_in);
	TEST_ASSERT_EQUAL(expected_elements_S1, num_of_elements);
	num_of_elements = mystack_nofelem(queue->stack_out);
	TEST_ASSERT_EQUAL(expected_elements_S2, num_of_elements);

	//dequeue returns -1
	ret = myqueue_dequeue(queue, &a);
	TEST_ASSERT_EQUAL(expected_ret, ret);

	myqueue_delete(queue);
}

void test_queue_dequeue_NULL_queue(void){
	int a = 5;
    int ret;
    int expected_ret = -1;

    //verify behaviour
    ret = myqueue_dequeue(NULL, &a);
    TEST_ASSERT_EQUAL(expected_ret, ret);
}

void test_queue_dequeue_NULL_object(void){
	QueueMeta_t *queue = myqueue_create(sizeof(int));
	int ret;
    int expected_ret = -1;

    ret = myqueue_dequeue(queue, NULL);
    TEST_ASSERT_EQUAL(expected_ret, ret);

	myqueue_delete(queue);
}

int main () {
	UnityBegin();
	//create
	MY_RUN_TEST(test_queue_create);
	//delete (check memory leaks)
	MY_RUN_TEST(test_queue_delete);
	MY_RUN_TEST(test_queue_delete_NULL_queue);
	//enqueue
	MY_RUN_TEST(test_queue_enqueue);
	MY_RUN_TEST(test_queue_enqueue_multiple);
	MY_RUN_TEST(test_queue_enqueue_NULL_queue);
	MY_RUN_TEST(test_queue_enqueue_NULL_object);
	//dequeue
	MY_RUN_TEST(test_queue_dequeue);
	MY_RUN_TEST(test_queue_dequeue_multiple);
	MY_RUN_TEST(test_queue_dequeue_no_elements);
	MY_RUN_TEST(test_queue_dequeue_NULL_queue);
	MY_RUN_TEST(test_queue_dequeue_NULL_object);
	return UnityEnd();
}
