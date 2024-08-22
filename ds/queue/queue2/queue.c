#include "queue.h"

static int queue[QUEUESIZE];
static int front;
static int rear;

void push(int data)
{
	queue[rear] = data;
	++rear;
}

int pop(void)
{
	int i = front;
	++front;
	return queue[i];
}
