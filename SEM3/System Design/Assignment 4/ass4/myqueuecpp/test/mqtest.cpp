#include "myqueuecpp.h"
#include "gtest/gtest.h"

class myQueueTest : public :: testing::Test {
protected:
  virtual void SetUp() {  }
 
  virtual void TearDown() {  }
};

TEST_F(myQueueTest, enqueue_multiple){
  Queue queue(sizeof(int));
  int a = 5;
  int b = 4;
  EXPECT_EQ(0, queue.myqueue_enqueue(&a));
  EXPECT_EQ(0, queue.myqueue_enqueue(&b));
}

TEST_F(myQueueTest, enqueue_void_obj){
  Queue queue(sizeof(int));
  EXPECT_EQ(-1, queue.myqueue_enqueue(nullptr));
}

TEST_F(myQueueTest, dequeue_multiple){
  Queue queue(sizeof(int));
  int a = 5;
  int b = 4;
  EXPECT_EQ(0, queue.myqueue_enqueue(&a));
  EXPECT_EQ(0, queue.myqueue_enqueue(&b));

  //2 elems in s1 and 0 in s2
  EXPECT_EQ(2, queue.stack_in.mystack_nofelem());
  EXPECT_EQ(0, queue.stack_out.mystack_nofelem());

  EXPECT_EQ(0, queue.myqueue_dequeue(&a));
  
  //0 elems in s1 and 1 in s2
  EXPECT_EQ(0, queue.stack_in.mystack_nofelem());
  EXPECT_EQ(1, queue.stack_out.mystack_nofelem());
}

TEST_F(myQueueTest, dequeue_no_elements){
  Queue queue(sizeof(int));
  int a = 5;

  //no elements present
  EXPECT_EQ(0, queue.stack_in.mystack_nofelem());
  EXPECT_EQ(0, queue.stack_out.mystack_nofelem());

  //failure
  EXPECT_EQ(-1, queue.myqueue_dequeue(&a));
}

TEST_F(myQueueTest, dequeue_void_obj){
  Queue queue(sizeof(int));

  EXPECT_EQ(-1, queue.myqueue_dequeue(nullptr));
}

