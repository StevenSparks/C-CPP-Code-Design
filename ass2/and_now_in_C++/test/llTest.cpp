#include "LinkedList.h"
#include "gtest/gtest.h"
 
class LinkedListTest : public ::testing::Test {
 protected:
  virtual void SetUp()
  {
    list = new LinkedList();
  }
 
  virtual void TearDown() 
  {
    list->Clean();
    delete list;
  }

  LinkedList * list;
};

TEST_F(LinkedListTest,addFirst){
  EXPECT_EQ(0,list->addFirst(1));
  EXPECT_EQ(0,list->addFirst(2));
  EXPECT_EQ(2,list->getHead()->getValue());
  EXPECT_EQ(1,list->getTail()->getValue());
}


TEST_F(LinkedListTest,addLast){
  EXPECT_EQ(0,list->addLast(1));
  EXPECT_EQ(0,list->addLast(2));
  EXPECT_EQ(0,list->addLast(3));
  EXPECT_EQ(1,list->getHead()->getValue());
  EXPECT_EQ(3,list->getTail()->getValue());
}

TEST_F(LinkedListTest,addAfter){
  EXPECT_EQ(0,list->addLast(1));
  EXPECT_EQ(0,list->addLast(2));
  EXPECT_EQ(0,list->addLast(4));
  EXPECT_EQ(0,list->addAfter(list->getHead()->getNext(), 3));
  EXPECT_EQ(3, list->getHead()->getNext()->getNext()->getValue());
}

TEST_F(LinkedListTest,remFirst){
  list->addFirst(1);
  list->addLast(2);
  list->addLast(3);
  EXPECT_EQ(0, list->remFirst());
  EXPECT_EQ(2, list->getHead()->getValue());
}

TEST_F(LinkedListTest,remLast){
  list->addFirst(1);
  list->addLast(2);
  list->addLast(3);
  EXPECT_EQ(0, list->remLast());
  EXPECT_EQ(2, list->getTail()->getValue());
}

TEST_F(LinkedListTest,remAfter){
  EXPECT_EQ(0,list->addLast(1));
  EXPECT_EQ(0,list->addLast(2));
  EXPECT_EQ(0,list->addLast(3));
  EXPECT_EQ(0,list->remAfter(list->getHead()->getNext()));
  EXPECT_EQ(list->getHead()->getNext()->getValue(), 2);
  EXPECT_EQ(list->getHead()->getNext()->getNext(), nullptr);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}