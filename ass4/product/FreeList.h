#ifndef FREELIST
#define FREELIST
#include "MList.h"

//list of memory you have that is exists but is not allocated
class FreeList : public MList{
    public:
        FreeList(int memStart, int maxSize) : MList(new ITEM(memStart, maxSize)), memStart(memStart), maxSize(maxSize) { };
        FreeList() = delete;
        ~FreeList(void) { };
    private:
        int memStart;
        int maxSize;
};

#endif