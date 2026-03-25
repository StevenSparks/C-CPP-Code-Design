#include "MemoryManager.h"
#include "MList.h"
#include <iostream>

using namespace std;

/* Starting point for MemoryManager constructor */
MemoryManager::MemoryManager()
{
	allocList = new AllocList(memStart, maxSize);
	freeList = new FreeList(memStart, maxSize);
}

/* Code correct destructor to cleanup all memory */
MemoryManager::~MemoryManager()
{
	delete allocList;
	delete freeList;
}

/*
returns ADDR when succesful
returns -1 when maxsize is exceeded, returns -2 if no memory could be allocated
*/
int MemoryManager::claimMemory(int size)
{	
	ITEM *temp = freeList->getHead();

	//i miss something here
	if (size > maxSize)
	{
		return -1;
	}

	// walk through the freelist
	while (temp != nullptr)
	{
		// complete match
		if (temp->_size == size)
		{
			int addr = temp->_addr;
			addToListSortedByAddr(allocList, temp->_addr, temp->_size);
			freeList->remThisItem(temp);
			return addr;
		}
		else if (temp->_size > size)
		{
			int addr = temp->_addr;
			addToListSortedByAddr(allocList, temp->_addr, size);
			temp->_size = temp->_size - size;
			temp->_addr = temp->_addr + size;
			return addr;
		}
		temp = temp->next;
	}

	return -1;
}

/* pre:  Parameter addr must match the start of an allocated memory block. Otherwhise return -1.
 *
 * post: If addr is a part of allocated memory of allocList then the memory from this address
 * 	     with registered size should be removed from the allocList and added to the freeList
 *
 *       freeMemory(addr) returns number of bytes (size) belongig to the address addr
 *       In all other cases freeMemory(freeList,allocList,addr) returns -1.
 */
int MemoryManager::freeMemory(int addr)
{
	ITEM *temp = allocList->getHead();
	//failsafe
	while (temp != nullptr)
	{	
		//match found
		if (temp->_addr == addr)
		{
			if (addToListSortedByAddr(freeList, temp->_addr, temp->_size) == 0)
			{
				int size = temp->_size;
				allocList->remThisItem(temp);
				
				//defragment , reexecute until no merges have been made
				int merges = 1;
				while (merges != 0)
				{
					merges = defragmentList();
				}

				return size;
			}
			else
			{
				return -2;
			}
		}
		// walk next
		temp = temp->next;
	}
	return -1;
}

int MemoryManager::addToListSortedByAddr(MList *list, int myAddr, int mySize)
{
	ITEM* temp = list->getHead();
	if(temp == nullptr || temp->_addr > myAddr)
	{
		list->addFirst(myAddr, mySize);
		return 0;
	}
	else
	{
		while(temp != nullptr)
		{
			if(temp->_addr < myAddr)
			{
				if(temp->next == nullptr)
				{
					list->addLast(myAddr, mySize);
					return 0;
				}
				else if(temp->next->_addr > myAddr)
				{
					list->addAfter(temp, myAddr, mySize);
					return 0;
				}
			}
			temp = temp->next;
		}
	}
	return -1;
}

int MemoryManager::defragmentList()
{
	int merges = 0;
	ITEM *temp = freeList->getHead();
	while(temp != nullptr)
	{
		if(temp->next != nullptr)
		{
			if((temp->_addr + temp->_size) == temp->next->_addr)
			{
				temp->_size = (temp->_size + temp->next->_size);
				freeList->remThisItem(temp->next);
				merges++;
			}
		}
		temp = temp->next;
	}
	return merges;
}


AllocList *MemoryManager::getAllocList()
{
	return allocList;
}

FreeList *MemoryManager::getFreeList()
{
	return freeList;
}

int MemoryManager::getMemStart()
{
	return memStart;
}

int MemoryManager::getMaxSize()
{
	return maxSize;
}