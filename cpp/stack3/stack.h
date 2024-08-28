#ifndef STACK_H
#define STACK_H
#include "array.h"

class Stack {
private:
    static const int STACKSIZE;

    // int *pArr_;
	// int size_;
    Array arr_;             // 'has-a'관계
	int tos_;

    Stack(const Stack& );
    Stack& operator = (const Stack& );

public:
    explicit Stack(int size = 100);

	void push(int data);
	int pop();

    bool isFull() const;
    bool isEmpty() const;
};

#endif