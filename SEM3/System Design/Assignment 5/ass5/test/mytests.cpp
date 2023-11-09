
#include "MemoryManager.h"
#include "MList.h"
#include "gtest/gtest.h"

class metaTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }
 
  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

/* A simple example of Unit Test */
TEST_F(metaTest,testClaim)
{
  MemoryManager mm(1000, 100);
  // Execute once the code is implemented 
  //
  //EXPECT_EQ(mm.GetMemStart(), mm.ClaimMemory(20));
  //EXPECT_EQ(mm.GetMemStart(), mm->GetAllocList()->GetHead()->addr);
  //EXPECT_EQ(20,               mm.GetAllocList()->GetHead()->size);
  // 
  // mm goes out of scope, so MemoryManager::dtor will be called
}


