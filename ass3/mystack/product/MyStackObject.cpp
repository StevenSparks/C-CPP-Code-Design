#include <cstdlib>
#include <cstring>
#include <exception>
using namespace std;

#include "MyStackObject.h"

MyStackObject::MyStackObject() : obj(NULL), next(NULL) {}

MyStackObject::MyStackObject(void *obj, size_t objSize) : MyStackObject() 
{	
	this->obj = malloc(objSize);
	copyObject(obj, objSize);
};

MyStackObject::MyStackObject(void *obj, size_t objSize, MyStackObject* next)
	: obj(malloc(objSize))
	, next(next)

{
	//this->obj = malloc(objSize);
	copyObject(obj, objSize);
	//this->next = next;
}

MyStackObject::~MyStackObject()
{	
	free(this->getObject());
}

void MyStackObject::copyObject(void* obj, size_t objSize)	
{
	if(obj == nullptr){
		this->obj = nullptr;
		return;
	}
	
	std::memcpy(this->obj, obj, objSize);
}

void* MyStackObject::getObject()
{
	return obj;
}

void MyStackObject::setNext(MyStackObject* next)
{
	this->next = next;
}

MyStackObject* MyStackObject::getNext()
{
	return next;
}