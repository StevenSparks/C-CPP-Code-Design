#include "MemoryManager.h"
#include "MList.h"
#include "gtest/gtest.h"

class MemoryManagerTest : public ::testing::Test {
 protected:
  virtual void SetUp() 
  {
    mm = new MemoryManager();
  }
 
  virtual void TearDown() 
  {
    delete mm;
    mm = nullptr;
  }
  
  MemoryManager * mm;
};

/* A simple example of Unit Test */
TEST_F(MemoryManagerTest, testClaimBasic)
{
  int ret = mm->claimMemory(20);
  EXPECT_EQ(mm->getMemStart(), ret);
  EXPECT_EQ(mm->getMemStart(), mm->getAllocList()->getHead()->_addr);
  EXPECT_EQ(20, mm->getAllocList()->getHead()->_size);
}

TEST_F(MemoryManagerTest, testClaimAll)
{
  int ret = mm->claimMemory(100);
  EXPECT_EQ(mm->getMemStart(), ret);
  EXPECT_EQ(mm->getMemStart(), mm->getAllocList()->getHead()->_addr);
  EXPECT_EQ(100, mm->getAllocList()->getHead()->_size);
  EXPECT_EQ(nullptr, mm->getFreeList()->getHead());
}

TEST_F(MemoryManagerTest, TestFreeBasic)
{
  int claim = 20;
  mm->claimMemory(claim);
  int ret = mm->freeMemory(mm->getAllocList()->getHead()->_addr);
  EXPECT_EQ(ret, claim);
}

TEST_F(MemoryManagerTest, testClaimMultiple)
{
  mm->claimMemory(20);
  mm->claimMemory(15);
  mm->claimMemory(7);
  mm->claimMemory(30);

  EXPECT_EQ(20, mm->getAllocList()->getHead()->_size);
  EXPECT_EQ(15, mm->getAllocList()->getHead()->next->_size);
  EXPECT_EQ(7, mm->getAllocList()->getHead()->next->next->_size);
  EXPECT_EQ(30, mm->getAllocList()->getTail()->_size);

  EXPECT_EQ((mm->getMemStart() + 72), mm->getFreeList()->getHead()->_addr);
  EXPECT_EQ(28, mm->getFreeList()->getHead()->_size);
}

TEST_F(MemoryManagerTest, testFreeSecondElementOutOfFour)
{
  mm->claimMemory(20);
  mm->claimMemory(15);
  mm->claimMemory(7);
  mm->claimMemory(30);

  int ret = mm->freeMemory(mm->getAllocList()->getHead()->next->_addr);
  EXPECT_EQ(ret, 15);
}

TEST_F(MemoryManagerTest, testFreememoryDefragmentationLastElement)
{
  mm->claimMemory(20);
  mm->claimMemory(15);
  mm->claimMemory(7);
  mm->claimMemory(30);

  mm->freeMemory(mm->getAllocList()->getTail()->_addr);

  EXPECT_EQ(mm->getFreeList()->getHead()->next, nullptr);
  EXPECT_EQ(mm->getFreeList()->getHead(), mm->getFreeList()->getTail());
  EXPECT_EQ(mm->getFreeList()->getHead()->_size, 58);
}

TEST_F(MemoryManagerTest, testFreememoryDefragmentationThreeElements)
{
  EXPECT_EQ(1000 ,mm->claimMemory(20));
  EXPECT_EQ(1020, mm->claimMemory(15));
  EXPECT_EQ(1035, mm->claimMemory(7));
  EXPECT_EQ(1042, mm->claimMemory(30));

  EXPECT_EQ(7, mm->freeMemory(1035));
  EXPECT_EQ(15, mm->freeMemory(1020));  
  
  EXPECT_EQ((mm->getMemStart() + 20), mm->getFreeList()->getHead()->_addr);
  EXPECT_EQ(22, mm->getFreeList()->getHead()->_size);
  EXPECT_EQ((mm->getMemStart() + 72), mm->getFreeList()->getTail()->_addr);
  EXPECT_EQ(28, mm->getFreeList()->getTail()->_size);

  EXPECT_EQ(30, mm->freeMemory(1042));
  EXPECT_EQ((mm->getMemStart() + 20), mm->getFreeList()->getHead()->_addr);
  EXPECT_EQ(80, mm->getFreeList()->getHead()->_size);
  EXPECT_EQ(mm->getFreeList()->getHead()->next, nullptr);
  EXPECT_EQ(mm->getFreeList()->getHead(), mm->getFreeList()->getTail());
}