#include "MList.h"
#include "gtest/gtest.h"

/*
  Test functionality of MList functions before building / testing memory manager
  IMPORTANT NOTE: all items made here do not follow the memory manager functionality as to seperate tests for ease
*/

class MlistTest : public ::testing::Test {
 protected:
  virtual void SetUp() 
  {
    ll  = new MList(head);
  }
 
  virtual void TearDown() 
  {
    delete ll;
  }

  ITEM * head = new ITEM(1, 100);
  MList * ll;
};

//main functions
TEST_F(MlistTest, getHead)
{
  ITEM *testItem = ll->getHead();
  ASSERT_EQ(testItem->_addr, 1);
  ASSERT_EQ(testItem->_size, 100);
  ASSERT_EQ(testItem->next, nullptr);
}

TEST_F(MlistTest, getTail)
{
  ITEM *testItem = ll->getTail();
  ASSERT_EQ(testItem->_addr, 1);
  ASSERT_EQ(testItem->_size, 100);
  ASSERT_EQ(testItem->next, nullptr);
}

TEST_F(MlistTest, addFirst)
{
  int addr = 11;
  int size = 55;
  ASSERT_EQ(0, ll->addFirst(addr, size));
  ASSERT_EQ(addr, ll->getHead()->_addr);
  ASSERT_EQ(size, ll->getHead()->_size);
}

TEST_F(MlistTest, addLast)
{
  int addr = 5;
  int size = 64;
  ASSERT_EQ(0, ll->addLast(addr, size));
  ASSERT_EQ(addr, ll->getTail()->_addr);
  ASSERT_EQ(size, ll->getTail()->_size);
}

TEST_F(MlistTest, addAfter)
{
  ASSERT_EQ(0, ll->addLast(2, 10));
  ASSERT_EQ(0, ll->addLast(4, 12));
  ASSERT_EQ(0, ll->addLast(5, 13));

  ITEM * item = ll->getHead()->next;

  ASSERT_EQ(0, ll->addAfter(item, 3, 11));

  ASSERT_EQ(1, ll->getHead()->_addr);
  ASSERT_EQ(2, ll->getHead()->next->_addr);
  ASSERT_EQ(3, ll->getHead()->next->next->_addr);
  ASSERT_EQ(4, ll->getHead()->next->next->next->_addr);
  ASSERT_EQ(5, ll->getHead()->next->next->next->next->_addr);
}

TEST_F(MlistTest, remThisItem)
{
  ASSERT_EQ(0, ll->addLast(2, 10));
  ASSERT_EQ(0, ll->addLast(3, 12));
  ASSERT_EQ(0, ll->addLast(4, 13));

  ITEM * itemToFind = ll->getHead()->next;

  ASSERT_EQ(2, ll->remThisItem(itemToFind));

  ASSERT_EQ(1, ll->getHead()->_addr);
  ASSERT_EQ(3, ll->getHead()->next->_addr);
  ASSERT_EQ(4, ll->getHead()->next->next->_addr);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc,argv);
  return  RUN_ALL_TESTS();
}