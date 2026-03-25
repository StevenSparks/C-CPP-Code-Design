#include "MyStack.h"
#include <cstdlib>
#include <cstring>
/* The stack is an abstract data type.
* this means that the internal structures are
* never exposed to the users of the library. */

/* Note: the stacks have no knowledge of what types
* they are storing. This is not a concern of the stack */

MyStack::MyStack(std::size_t objsize) : objSize(objsize), top(nullptr), numElem(0) { };

int MyStack::myStackPush(void* obj)
{	
	if(obj == nullptr)
	{
		return -1;
	}
	
	MyStackObject * newObj = new MyStackObject(obj, objSize);
	newObj->setNext(top);
	top = newObj;
	numElem++;
	return 0;
}

int MyStack::myStackPop(void* obj)
{
	if(top == nullptr)
	{
		return -1;
	}

	MyStackObject * temp = top->getNext();
	memcpy(obj, top->getObject(), objSize);
	delete top;
	top = temp;
	numElem--;
	return 0;
}

MyStack::~MyStack()
{	
	if (this->top == nullptr){
		return;
	}
	
	MyStackObject * current = top;
	while (current != nullptr)
	{
		MyStackObject * previous = current;
		current = current->getNext();
		delete previous;
	}
	this->numElem = 0;

	return;
}

std::size_t MyStack::myStackNoOfElem()
{
	return numElem;
}
