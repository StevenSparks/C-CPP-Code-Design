#include "MyStack.h"
#include "MyQueue.h"
#include "gtest/gtest.h"

class MyQueueTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    Johnny = new MyQueue(mysize);
  }
 
  virtual void TearDown() {
    delete Johnny;
    Johnny = nullptr;
  }

  size_t mysize = 64;
  MyQueue * Johnny;
};

TEST_F(MyQueueTest, EnqueueSingleTest)
{ 
  int value = 1;
  int* myValue = (int*)malloc(mysize);
  *myValue = value;

  EXPECT_EQ(0, Johnny->myQueueEnqueue(myValue));

  free(myValue);
  myValue = nullptr;
}

TEST_F(MyQueueTest, EnqueueMultipleTest)
{ 
  int val1 = 1;
  int val2 = 4;
  int val3 = 3;

  int* MalVal1 = (int*)malloc(mysize);
  int* MalVal2 = (int*)malloc(mysize);
  int* MalVal3 = (int*)malloc(mysize);

  *MalVal1 = val1;
  *MalVal2 = val2;
  *MalVal3 = val3;

  EXPECT_EQ(0, Johnny->myQueueEnqueue(MalVal1));
  EXPECT_EQ(0, Johnny->myQueueEnqueue(MalVal2));
  EXPECT_EQ(0, Johnny->myQueueEnqueue(MalVal3));

  free(MalVal1);
  free(MalVal2);
  free(MalVal3);

  MalVal1 = nullptr;
  MalVal2 = nullptr;
  MalVal3 = nullptr;
}

TEST_F(MyQueueTest, DeqeueueSingle)
{
  int testValue = 6;
  int* myValue = (int*)malloc(mysize);
  *myValue = testValue;

  Johnny->myQueueEnqueue(myValue);

  free(myValue);
  myValue = nullptr;

  int* retVal = (int*)malloc(mysize);

  EXPECT_EQ(0, Johnny->myQueueDequeue(retVal)); 
  EXPECT_EQ(*retVal, testValue);

  free(retVal);
  retVal = nullptr;
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return  RUN_ALL_TESTS();
}