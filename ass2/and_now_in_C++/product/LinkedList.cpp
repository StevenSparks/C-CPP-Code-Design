#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) { }

int LinkedList::addFirst(int value)
 {
	Item *it = new Item(value);
	if(head == nullptr)
	{
		head = it;
		tail = it;
	}
	else
	{
		it->setNext(head);
		head = it;
	}
	
	return 0;
}
	
int LinkedList::addLast(int value){
	Item *it = new Item(value);
	if(head == nullptr)
	{
		head = it;
		tail = it;
	}
	else
	{
		Item * current = head;
		while (current->getNext() != nullptr)
		{	
			current = current->getNext();
		}
		current->setNext(it);
		tail = it;	
	}

	return 0;
}

int LinkedList::addAfter(Item *c_item, int value)
{
	if(c_item == nullptr)
	{
		return -1;
	}

	Item * current = head;
	while (current != nullptr)
	{	
		if(current == c_item)
		{
			Item *new_item = new Item(value);
	
			Item *temp = current->getNext();
			current->setNext(new_item);
			new_item->setNext(temp);
			return 0;
		}
		current = current->getNext();
	}

	return -2;
}

int LinkedList::remFirst(){
	if(head == nullptr){
		return -1;
	}

	Item * current = head;
	if(current->getNext() != nullptr){
		head = current->getNext();
	}

	delete current;
	return 0;
}
	
int LinkedList::remLast(){
	if(head == nullptr){
		return -1;
	}

	Item * next = head->getNext();
	Item * current = head;

	while (next->getNext() != nullptr){
		current = next;
		next = next->getNext();
	}
	
	delete next;
	current->setNext(nullptr);
	tail = current;

	return 0;
}

int LinkedList::remAfter(Item *c_item)
{
	if(c_item == NULL || head == nullptr) { return -1; }

	Item * current = head;
	while (current != nullptr)
	{
		if (current == c_item)
		{
			if(current->getNext() == nullptr) { return -2; }

			Item *rem = current->getNext();
			current->setNext(rem->getNext());

			delete rem;
			break;
		}
		current = current->getNext();
	}

	return 0;
}

void LinkedList::Clean(){
	if (head == nullptr){
		return;
	}
	
	Item * current = head;
	while (current != nullptr)
	{
		Item * previous = current;

		current = current->getNext();
		delete previous;
	}
	delete current;

	return;
}

void LinkedList::showList()
{
	cout << "List elements are \n";
	
	for(Item *it=head; it!=nullptr; it=it->getNext() )
	{
		cout << it->getValue() << endl;
	}
}

Item * LinkedList::getHead()
{
	if (head == nullptr) return nullptr;

	return head;
}

Item * LinkedList::getTail()
{
	if (tail == nullptr) return nullptr;
	
	return tail;
}
