#include "mystackcpp.h"
#include "gtest/gtest.h"

class myStackTest : public :: testing::Test {
protected:
  virtual void SetUp() {  }
 
  virtual void TearDown() {  }
};

TEST_F(myStackTest, mystack_push){
    Stack stack(sizeof(int));
    int a = 5;
    EXPECT_EQ(0, stack.mystack_push(&a));
}