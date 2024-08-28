#include <cassert>
#include "stack.h"

const int Stack::STACKSIZE = 100;

Stack::Stack(int size)
: pArr_(new int[size]), size_(size), tos_(0)
{
	assert(pArr_ );
}

Stack::Stack(const Stack& rhs)
{
	pArr_ = rhs.pArr_;
	size_ = rhs.size_;
	tos_ = rhs.tos_;
}

Stack::~Stack()
{
	delete [] pArr_;
}

Stack& Stack::operator = (const Stack& rhs)
{
	pArr_ = rhs.pArr_;
	size_ = rhs.size_;
	tos_ = rhs.tos_;

	return *this;	
}

void Stack::push(int data)
{
    assert(!isFull());
	
	pArr_[tos_] = data;
	++tos_;
}

int Stack::pop()
{
    assert(!isEmpty());

	--tos_;
	return pArr_[tos_];
}

bool Stack::isFull() const
{
	return tos_ == size_;
}

bool Stack::isEmpty() const
{
	return tos_ == 0;
}