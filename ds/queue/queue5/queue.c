#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void initQueue(Queue *pq, int size, int eleSize)
{
	//pq -> pArr = malloc(sizeof(int) * size);
	pq -> pArr = malloc(eleSize * size);
	assert(pq -> pArr /* != NULL */);

	pq -> eleSize = eleSize;
	pq -> size = size;
	pq -> rear = 0;
	pq -> front = 0;
}

void cleanupQueue(Queue *pq)
{
	free(pq -> pArr);
}

void push(Queue *pq, const void *pData)
{
	assert(pq -> rear != pq -> size);
	
	// pq -> pArr[pq -> rear] = data;
	memcpy( (unsigned char *)pq -> pArr + pq -> eleSize * pq -> rear, pData, pq -> eleSize);
	++pq -> rear;
}

void pop(Queue *pq, void *pResult)
{
	assert(pq -> front != pq -> rear);

	// *pResult = pq -> pArr[pq -> front];
	memcpy(pResult, (unsigned char *)pq -> pArr + pq -> eleSize * pq -> front, pq -> eleSize);
	++pq -> front;
}

// int pop(Queue *pq)
// {
// 	assert(pq -> front != pq -> rear);
// 	int i = pq -> front;
// 	++pq -> front;
// 	return pq -> pArr[i];
// }