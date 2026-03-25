#ifndef MLIST_H
#define MLIST_H
#include "MemItem.h"

class MList {
    public:
        MList(ITEM* head);
        MList() = delete;
        ~MList(void);
	    
        int addFirst(int addr, int size);
        int addLast(int addr, int size);
        int addAfter(ITEM * item, int addr, int size);
        int remThisItem(ITEM * item);
        void showList();
        void cleanList();
        ITEM * getHead();
        ITEM * getTail();
    protected: 
        int memStart;
        int maxSize;
        ITEM * head = nullptr;
        ITEM * tail = nullptr;
};

#endif