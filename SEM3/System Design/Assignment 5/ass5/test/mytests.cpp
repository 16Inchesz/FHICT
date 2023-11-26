
#include "MemoryManager.h"
#include "MList.h"
#include "gtest/gtest.h"

class metaTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }
 
  virtual void TearDown() {
  }
};

/* A simple example of Unit Test */
TEST_F(metaTest,testClaim)
{
  MemoryManager mm(1000, 100);  
  EXPECT_EQ(mm.GetMemStart(), mm.ClaimMemory(20));
  EXPECT_EQ(mm.GetMemStart(), mm.GetAllocList()->GetHead()->addr);
  EXPECT_EQ(20,               mm.GetAllocList()->GetHead()->size);
}

TEST_F(metaTest,testFree){
  MemoryManager mm(1000, 100);

  int addr = mm.ClaimMemory(20);

  EXPECT_EQ(20, mm.FreeMemory(addr));
  EXPECT_EQ(nullptr, mm.GetAllocList()->GetHead());
  EXPECT_EQ(1000, mm.GetFreeList()->GetHead()->addr);
  EXPECT_EQ(100, mm.GetFreeList()->GetHead()->size);
}

TEST_F(metaTest,testMergeMemory){
  FreeList freeList(0, 100);

  freeList.addFirst(20,30);
  freeList.addFirst(0,20);

  freeList.mergeMemory();

  EXPECT_EQ(0, freeList.GetHead()->addr);
  EXPECT_EQ(50, freeList.GetHead()->size);
}

TEST_F(metaTest,testAddFirst){
  MList list(nullptr);

  //only the second instance is considered the first. address: 1040 (50 byte)
  list.addFirst(1000, 20);
  list.addFirst(1040, 50);

  EXPECT_EQ(1040, list.GetHead()->addr);
  EXPECT_EQ(50, list.GetHead()->size);
}

TEST_F(metaTest,testAddAfter){
  MList list(nullptr);

  list.addFirst(1000, 20);

  list.addAfter(list.GetHead(), 1040, 50);

  EXPECT_EQ(1000, list.GetHead()->addr);
  EXPECT_EQ(20, list.GetHead()->size);
  EXPECT_EQ(1040, list.GetHead()->next->addr);
  EXPECT_EQ(50, list.GetHead()->next->size);
}

TEST_F(metaTest,testRemove){
  MList list(nullptr);

  list.addFirst(1000, 20);
  list.addAfter(list.GetHead(), 1040, 50);

  list.remove(list.GetHead()->next);
  EXPECT_EQ(1000, list.GetHead()->addr);
  EXPECT_EQ(nullptr, list.GetHead()->next);
}

TEST_F(metaTest,testAddInOrder){
  MList list(nullptr);
  
  list.addInOrder(1020, 30);
  list.addInOrder(1000, 20);
  list.addInOrder(1050, 10);
  
  EXPECT_EQ(1000, list.GetHead()->addr);
  EXPECT_EQ(20, list.GetHead()->size);
  EXPECT_EQ(1020, list.GetHead()->next->addr);
  EXPECT_EQ(30, list.GetHead()->next->size);
  EXPECT_EQ(1050, list.GetHead()->next->next->addr);
  EXPECT_EQ(10, list.GetHead()->next->next->size);
}

