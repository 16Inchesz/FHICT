#include "mystackcpp.h"
#include "gtest/gtest.h"

class myStackTest : public :: testing::Test {
protected:
  virtual void SetUp() {  }
 
  virtual void TearDown() {  }
};

TEST_F(myStackTest, push_multiple){
  Stack stack(sizeof(int));
  int a = 5;
  int b = 4;
  EXPECT_EQ(0, stack.mystack_push(&a));
  EXPECT_EQ(0, stack.mystack_push(&b));
  EXPECT_EQ(2, stack.mystack_nofelem());
}

TEST_F(myStackTest, push_void_obj){
  Stack stack(sizeof(int));
  EXPECT_EQ(-1, stack.mystack_push(nullptr));
}

TEST_F(myStackTest, pop_multiple){
  Stack stack(sizeof(int));
  int a = 5;
  int b = 4;
  EXPECT_EQ(0, stack.mystack_push(&a));
  EXPECT_EQ(0, stack.mystack_push(&b));
  EXPECT_EQ(2, stack.mystack_nofelem());
  EXPECT_EQ(0, stack.mystack_pop(&b));
  EXPECT_EQ(1, stack.mystack_nofelem());
  EXPECT_EQ(0, stack.mystack_pop(&a));
  EXPECT_EQ(0, stack.mystack_nofelem());
}

TEST_F(myStackTest, pop_void_obj){
  Stack stack(sizeof(int));
  EXPECT_EQ(-1, stack.mystack_pop(nullptr));
}

TEST_F(myStackTest, num_elements){
  Stack stack (sizeof(int));
  int a = 4;
  EXPECT_EQ(0, stack.mystack_push(&a));
  EXPECT_EQ(1, stack.mystack_nofelem());
  EXPECT_EQ(0, stack.mystack_pop(&a));
  EXPECT_EQ(0, stack.mystack_nofelem());
}