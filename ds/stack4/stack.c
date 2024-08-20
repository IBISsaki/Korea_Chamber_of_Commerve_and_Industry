#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void initStack(Stack *ps, int size)
{
	ps -> pArr = malloc(sizeof(int) * size);
	ps -> size = size;
	ps -> tos = 0;
}

void cleanupStack(Stack *ps)
{
	free(ps -> pArr);
}

void push(Stack *ps, int data)
{
/*	if(ps -> tos == ps -> size)
	{
		fprintf(stdout, "stack is full\n");
		exit(1);
	}
*/

	assert(ps -> tos != ps -> size);
	
	ps -> pArr[ps -> tos] = data;
	++ps -> tos;
}

int pop(Stack *ps)
{
	
	/*if(ps -> tos == 0)
	{
		fprintf(stdout, "stack is empty\n");
		exit(2);
	} */
	assert(ps -> tos != 0);
	--ps -> tos;
	return ps -> pArr[ps -> tos];
}
