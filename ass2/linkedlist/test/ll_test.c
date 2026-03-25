#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "unity.h"

#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void setUp(void)
{

}

void tearDown(void)
{

}

void test_add_first(void)
{
  int ret;
  ITEM *list = NULL;
  ret = add_first(&list, 1);
  TEST_ASSERT_EQUAL(0, ret);
  
  free(list);
}

void test_add_last(void){
  int ret;
  ITEM *list = NULL;

  ret = add_last(&list, 1);
  TEST_ASSERT_EQUAL(0, ret);
  ret = add_last(&list, 2);
  TEST_ASSERT_EQUAL(0, ret);

  TEST_ASSERT_EQUAL(list->next->value, 2);

  free(list->next);
  free(list);
}

void test_add_after(void){
  int ret;
  
  ITEM item2 = {5, NULL};
  ITEM item1 = {2, &item2};
  ITEM *list = &item1;

  ret = add_after(list, &item1, 3);

  TEST_ASSERT_EQUAL(0, ret);
  TEST_ASSERT_EQUAL(list->next->value, 3);

  free(list->next);
}

void test_add_after_morethan3(void){
  int ret = 0;
  
  ITEM item4 = {5, NULL};
  ITEM item3 = {3, &item4};
  ITEM item2 = {2, &item3};
  ITEM item1 = {1, &item2};
  ITEM *list = &item1;

  //third elem

  ret = add_after(list, &item3, 4);
  TEST_ASSERT_EQUAL(0, ret);
  TEST_ASSERT_EQUAL(4, list->next->next->next->value);

  free(list->next->next->next);
}

void test_rem_first(void){
  int ret;
  ITEM *item2 = malloc(sizeof(ITEM));
  ITEM *item1 = malloc(sizeof(ITEM));

  item1->value = 2;
  item2->value = 4;
  
  ITEM *list = item1;
  item1->next = item2;
  item2->next = NULL;

  ret = rem_first(&list);

  TEST_ASSERT_EQUAL(0, ret);
  TEST_ASSERT_NOT_NULL(list);
  TEST_ASSERT_EQUAL(4, list->value);

  free(item2);
}

void test_rem_last(void){
  int ret;
  ITEM *item2 = malloc(sizeof(ITEM));
  ITEM *item1 = malloc(sizeof(ITEM));

  item1->value = 2;
  item2->value = 4;
  
  ITEM *list = item1;
  item1->next = item2;
  item2->next = NULL;

  ret = rem_last(&list);

  TEST_ASSERT_EQUAL(0, ret);
  TEST_ASSERT_NOT_NULL(list);
  TEST_ASSERT_EQUAL(2, list->value);

  free(item1);
}

void test_rem_after(void){
  int ret;
  ITEM *item3 = malloc(sizeof(ITEM));
  ITEM *item2 = malloc(sizeof(ITEM));
  ITEM *item1 = malloc(sizeof(ITEM));

  item1->value = 2;
  item2->value = 4;
  item2->value = 6;
  
  ITEM *list = item1;
  item1->next = item2;
  item2->next = item3;
  item3->next = NULL;

  ret = rem_after(list, item2);

  TEST_ASSERT_EQUAL(0, ret);
  TEST_ASSERT_NOT_NULL(list);
  TEST_ASSERT_EQUAL(6, list->next->value);

  free(item1);
  free(item2);
}

void test_clean(void){
  ITEM *item3 = malloc(sizeof(ITEM));
  ITEM *item2 = malloc(sizeof(ITEM));
  ITEM *item1 = malloc(sizeof(ITEM));
  
  ITEM *list = item1;
  item1->next = item2;
  item2->next = item3;
  item3->next = NULL;

  clean(&list);
}

int main (int argc, char * argv[])
{
    UnityBegin();

    MY_RUN_TEST(test_add_first);
    MY_RUN_TEST(test_add_last);
    MY_RUN_TEST(test_add_after);
    MY_RUN_TEST(test_add_after_morethan3);
    MY_RUN_TEST(test_rem_first);
    MY_RUN_TEST(test_rem_last);
    MY_RUN_TEST(test_rem_after); 
    MY_RUN_TEST(test_clean);

    return UnityEnd();
}
