#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static int queue[QUEUESIZE];
static int front;
static int rear;

void initQueue(Queue *pq)
{
	pq -> rear = 0;
	pq -> front = 0;
}

void push(Queue *pq, int data)
{
	if(pq -> rear == QUEUESIZE)
	{
		fprintf(stderr, "qeueu is full\n");
		exit(1);
	}
	pq -> queue[pq -> rear] = data;
	++pq -> rear;
}

int pop(Queue *pq)
{
	if(pq -> rear == pq -> front)
	{
		fprintf(stderr, "qeueu is empty\n");
		exit(2);
	}
	int i = pq -> front;
	++pq -> front;
	return pq -> queue[i];
}
