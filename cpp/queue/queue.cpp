// #include <cstdio>
#include <cassert>
// #include <cstdlib>
#include "queue.h"

Queue::Queue(int size)
{
	this -> pArr = new int[size];
	assert(this -> pArr );

	this -> size = size;
	this -> rear = 0;
	this -> front = 0;
}

Queue::~Queue()
{
	delete[] this -> pArr;
}

void Queue::push(int data)
{
	assert((this -> rear + 1) % this -> size != this -> front);

	this -> pArr[this -> rear] = data;
	this -> rear = (this -> rear + 1) % this -> size;
}

int Queue::pop()
{
	assert(this -> front != this -> rear);

	int i = this -> front;
	this -> front = (this -> front + 1) % this -> size;
	return this -> pArr[i];
}
