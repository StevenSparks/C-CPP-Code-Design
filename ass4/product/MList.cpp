#include <iostream>
#include "MList.h"

using namespace std;


MList::MList(ITEM* head) : head(head), tail(head) { };

MList::~MList()
{
    cleanList();
}

/* Implementation of all your MList methods */
//adapt old linkedlist functions into Mlist stored value
int MList::addFirst(int addr, int size)
{
    ITEM * newItem = new ITEM(addr, size);

	if(head == nullptr)
	{
		head = newItem;
		tail = newItem;
	}
	else
	{
        newItem->next = head;
        head = newItem;
	}
	
	return 0;
}

int MList::addLast(int addr, int size)
{
    ITEM * newItem = new ITEM(addr, size);
    if(head == nullptr)
	{
		head = newItem;
		tail = newItem;
	}
    else
    {
        ITEM *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        
        current->next = newItem;
        tail = newItem;
    }

    return 0;
}

int MList::addAfter(ITEM * item, int addr, int size)
{   
    if(item == nullptr)
    {   
        //invalid call of addafter
        return -1; 
    }
    if(head == nullptr)
    {
        return -1;
    }

    ITEM * newItem = new ITEM(addr, size);

    if(item == tail)
    {
        tail->next = newItem;
		tail = newItem;
		return 0;
    }
    else
    {
        newItem->next = item->next;
		item->next = newItem;
		return 0;
    }
}

int MList::remThisItem(ITEM * item)
{      
    if (head == nullptr)
    {
        return -1;
    }

    ITEM * current = head;
    ITEM * previous = nullptr;

    while (current != nullptr)
    {   
        //item matches but is also first result?
        if(current == item && previous == nullptr)
        {
            head = current->next;
            item->next = nullptr;
            delete item;
            item = nullptr;
            return 1;
        }
        //somewhere middle of the list
        else if(current == item && previous != nullptr)
        {
            //previous can be HEAD or further down, this accounts for both.
            previous->next = current->next;
            if(previous->next == nullptr)
            {
                tail = previous;
            }
            item->next = nullptr;
            delete item;
            item = nullptr;
            return 2;
        }
        
        //if nothing found, move up the linked list
        previous = current;
        current = current->next;
    }

    //not found
    return -2;
}

void MList::showList()
{
    cout << "List elements are \n";

    for (ITEM * it = head; it != nullptr; it = it->next)
    {
        cout << it->_addr << endl;
    }
}

void MList::cleanList()
{
    if (head == nullptr)
    {
        return;
    }

    ITEM * current = head;
    while (current != nullptr)
    {
        ITEM *previous = current;

        current = current->next;
        delete previous;
    }
    delete current;

    return;
}

ITEM * MList::getHead()
{
    return head;
}

ITEM * MList::getTail()
{
    return tail;
}