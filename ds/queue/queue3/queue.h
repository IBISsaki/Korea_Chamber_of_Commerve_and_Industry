#ifndef QUEUE_H
#define QUEUE_H
#define QUEUESIZE 100

typedef struct
{
	int queue[QUEUESIZE];
	int front;
	int rear;
} Queue;

void initQueue(Queue *pq);

void push(Queue *pq, int data);
int pop(Queue *pq);

#endif
