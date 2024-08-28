#ifndef STACK_H
#define STACK_H
// #define STACKSIZE 100
// extern int STACKSIZE;

class Stack {
private:
    static const int STACKSIZE;

    int *pArr_;
	int size_;
	int tos_;

    Stack(const Stack& );
    Stack& operator = (const Stack& );

public:
    explicit Stack(int size = 100);
    ~Stack();

	void push(int data);
	int pop();

    bool isFull() const;
    bool isEmpty() const;
};

#endif