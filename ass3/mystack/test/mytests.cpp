#include "MyStack.h"
#include "gtest/gtest.h"

class MyStackTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    Johnny = new MyStack(mysize);
  }
  virtual void TearDown() {
    delete Johnny;
  }
  size_t mysize = 5000;
  MyStack * Johnny;
};

TEST_F(MyStackTest, myStackPushSingle)
{
  void* myValue = malloc(mysize);

  EXPECT_EQ(0, Johnny->myStackPush(myValue));
  EXPECT_EQ(1, Johnny->myStackNoOfElem());

  free(myValue);
  myValue = nullptr;
}

TEST_F(MyStackTest, myStackPopSingle)
{
  int value = 17;
  int* myValue = (int*)malloc(mysize);
  *myValue = value;

  EXPECT_EQ(0, Johnny->myStackPush(myValue));

  free(myValue);
  myValue = nullptr;
  int* retVal = (int*)malloc(mysize);

  EXPECT_EQ(0, Johnny->myStackPop(retVal));
  EXPECT_EQ(value, *retVal);

  free(retVal);
  retVal = nullptr;
}

TEST_F(MyStackTest, MyStackPushMultiple)
{
  void* myFirst = malloc(mysize);
  void* mySecond = malloc(mysize);
  void* myThird = malloc(mysize);

  EXPECT_EQ(0, Johnny->myStackPush(myFirst));
  EXPECT_EQ(1, Johnny->myStackNoOfElem());

  EXPECT_EQ(0, Johnny->myStackPush(mySecond));
  EXPECT_EQ(2, Johnny->myStackNoOfElem());

  EXPECT_EQ(0, Johnny->myStackPush(myThird));
  EXPECT_EQ(3, Johnny->myStackNoOfElem());

  free(myFirst);
  free(mySecond);
  free(myThird);

  myFirst = nullptr;
  mySecond = nullptr;
  myThird = nullptr;
}

TEST_F(MyStackTest, MyStackPopMultiple)
{
  int* myFirst = (int*)malloc(mysize);
  int* mySecond = (int*)malloc(mysize);
  int* myThird = (int*)malloc(mysize);
  int firstVal = 3;
  int secondVal = 7;
  int thirdVal = 4;
  *myFirst = firstVal;
  *mySecond = secondVal;
  *myThird = thirdVal;

  EXPECT_EQ(0, Johnny->myStackPush(myFirst));
  EXPECT_EQ(1, Johnny->myStackNoOfElem());
  EXPECT_EQ(0, Johnny->myStackPush(mySecond));
  EXPECT_EQ(2, Johnny->myStackNoOfElem());
  EXPECT_EQ(0, Johnny->myStackPush(myThird));
  EXPECT_EQ(3, Johnny->myStackNoOfElem());

  free(myFirst);
  free(mySecond);
  free(myThird);
  myFirst = nullptr;
  mySecond = nullptr;
  myThird = nullptr;

  int* retVal1 = (int*)malloc(mysize);
  int* retVal2 = (int*)malloc(mysize);
  int* retVal3 = (int*)malloc(mysize);

  EXPECT_EQ(0, Johnny->myStackPop(retVal1));
  EXPECT_EQ(2, Johnny->myStackNoOfElem());
  EXPECT_EQ(0, Johnny->myStackPop(retVal2));
  EXPECT_EQ(1, Johnny->myStackNoOfElem());
  EXPECT_EQ(0, Johnny->myStackPop(retVal3));
  EXPECT_EQ(0, Johnny->myStackNoOfElem());
  EXPECT_EQ(thirdVal, *retVal1);
  EXPECT_EQ(secondVal, *retVal2);
  EXPECT_EQ(firstVal, *retVal3);

  free(retVal1);
  free(retVal2);
  free(retVal3);
  retVal1 = nullptr;
  retVal2 = nullptr;
  retVal3 = nullptr;
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc,argv);
  return  RUN_ALL_TESTS();
}