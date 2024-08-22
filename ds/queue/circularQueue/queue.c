#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *pq, int size)
{
	pq -> pArr = malloc(sizeof(int) * size);
	assert(pq -> pArr /* != NULL */);

	pq -> size = size;
	pq -> rear = 0;
	pq -> front = 0;
}

void cleanupQueue(Queue *pq)
{
	free(pq -> pArr);
}

void push(Queue *pq, int data)
{
	// assert(pq -> rear != pq -> size);
	assert((pq -> rear + 1) % pq -> size != pq -> front);
	pq -> pArr[pq -> rear] = data;
	// ++pq -> rear;
	pq -> rear = (pq -> rear + 1) % pq -> size;
}

int pop(Queue *pq)
{
	assert(pq -> front != pq -> rear);
	int i = pq -> front;
	// ++pq -> front;
	pq -> front = (pq -> front + 1) % pq -> size;
	return pq -> pArr[i];
}
