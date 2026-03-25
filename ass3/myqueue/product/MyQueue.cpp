#include "MyStack.h"
#include "MyQueue.h"

MyQueue::MyQueue(std::size_t itemsize) : stackIn(new MyStack(itemsize)), stackOut(new MyStack(itemsize)), itemSize(itemsize) { };

MyQueue::~MyQueue()
{
	delete stackIn;
	delete stackOut;
}

int MyQueue::myQueueEnqueue(void *obj)
{
	if(obj == nullptr)
	{
		return -1;
	}
	if((stackIn->myStackPush(obj)) != 0)
	{
		//function failed
		return -2;	
	}
	return 0;
}

int MyQueue::myQueueDequeue(void *obj)
{
	if(obj == nullptr)
	{
		return -1;
	}
	
	//if stackout has elems
	if(stackOut->myStackNoOfElem() > 0)
	{
		stackOut->myStackPop(obj);
		return 0;
	}

	//if no elems in stackin
	if(stackIn->myStackNoOfElem() == 0)
	{
		return -2;
	}

	//no elems in stackout, and elems in stackin, move everything from stackin to stackout
	if(stackOut->myStackNoOfElem() == 0 && stackIn->myStackNoOfElem() > 0)
	{
		void* malleable = malloc(itemSize);

		while(stackIn->myStackNoOfElem() != 0)
		{
		 	stackIn->myStackPop(malleable);	//serious bug right here, problem with malloc?
		 	stackOut->myStackPush(malleable);
		}
		free(malleable);
		malleable = nullptr;
		stackOut->myStackPop(obj);
		return 0;
	}

	//unknown last case, super error
	return -3;
}
