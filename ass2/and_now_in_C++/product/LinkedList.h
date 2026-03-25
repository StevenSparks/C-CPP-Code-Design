#ifndef __LINKEDLISTH__
#define __LINKEDLISTH__

#include "Item.h"

class LinkedList
{
public:
    LinkedList();

    int addFirst(int value);
    int addLast(int value);
    int addAfter(Item *c_item, int value);
    int remFirst();
    int remLast();
    int remAfter(Item *c_item);
    void Clean();

    void showList();
    Item * getHead();
    Item * getTail(); 

private:
    Item *head,*tail;
};

#endif

