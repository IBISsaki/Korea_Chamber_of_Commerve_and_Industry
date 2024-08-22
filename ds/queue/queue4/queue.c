#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *pq, int size)
{
	pq -> pArr = malloc(sizeof(int) * size);
	// if(pq -> pArr == NULL)
	// {
	// 	//
	// }
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
	//ps -> queue[ps -> rear] = data;
	//++ps -> rear;
	assert(pq -> rear != pq -> size);
	
	pq -> pArr[pq -> rear] = data;
	++pq -> rear;
}

int pop(Queue *pq)
{
	//int i = ps -> queue[ps -> front];
	//++ps -> front;
	//return i;
	
	assert(pq -> front != pq -> rear);
	int i = pq -> front;
	++pq -> front;
	return pq -> pArr[i];
}
