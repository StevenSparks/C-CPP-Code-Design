#ifndef ALLOCLIST
#define ALLOCLIST
#include "MList.h"

//list of memory that you have allocated from Freelist
class AllocList : public MList{
    public:
        AllocList(int memStart, int maxSize) : MList(nullptr), memStart(memStart), maxSize(maxSize) { };
        AllocList() = delete;
        ~AllocList(void) { };
    private:
        int memStart;
        int maxSize;
};

#endif