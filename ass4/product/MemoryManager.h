#ifndef MEMORYMANAGER
#define MEMORYMANAGER
#include "AllocList.h"
#include "FreeList.h"

class MemoryManager {
    public:
        MemoryManager();
        ~MemoryManager();

        //core functionality
        int claimMemory(int size);
        int freeMemory(int addr);

        //getters
        int getMemStart();
        int getMaxSize();
        AllocList * getAllocList();
        FreeList * getFreeList();

    private:
        int defragmentList();
        int addToListSortedByAddr(MList *list, int addr, int size);
        const int memStart = 1000;
        const int maxSize = 100;
        AllocList * allocList;
        FreeList * freeList;
};

#endif