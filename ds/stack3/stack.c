#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/*
void push(Stack s, int data)
{
	//stack[tos] = data;
	//++tod;
	s.array[s.tos] = data;
	++s.tos;
}

int pop(Stack s)
{
	//--tos;
	//return stack[tos];
	
	--s.tos;
	return s.array[s.tos];
}
*/

void initStack(Stack *ps)
{
	ps -> tos = 0;
}

void push(Stack *ps, int data)
{
	//stack[tos] = data;
	//++tod;
	
	//s.array[s.tos] = data;
	//++s.tos;
	if(ps -> tos == STACKSIZE)
	{
		fprintf(stdout, "stack is full\n");
		exit(1);
	}
	
	ps -> array[ps -> tos] = data;
	++ps -> tos;
}

int pop(Stack *ps)
{
	//--tos;
	//return stack[tos];
	
	//--s.tos;
	//return s.array[s.tos];
	
	if(ps -> tos == 0)
	{
		fprintf(stdout, "stack is empty\n");
		exit(2);
	}
	
	--ps -> tos;
	return ps -> array[ps -> tos];
}
