#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue q1, q2;
	// Queue queues[10];
	
	initQueue(&q1);		//q1.front = q1.rear = 0;
	initQueue(&q2);		//q2.front = q2.rear = 0;
	
	push(&q1, 100);
	push(&q1, 200);
	push(&q1, 300);
	
	int re = pop(&q1);
	printf("q1 1st pop() : %d\n", re);
	printf("q1 2nd pop() : %d\n", pop(&q1));
	printf("q1 3rd pop() : %d\n", pop(&q1));
	
	pop(&q1);
	
	push(&q2, 900);
	push(&q2, 800);
	push(&q2, 700);
	
	printf("q2 1st pop() : %d\n", pop(&q2));
	printf("q2 2nd pop() : %d\n", pop(&q2));
	printf("q2 3rd pop() : %d\n", pop(&q2));

	return 0;
}

/*int main(void)
{
	push(100);
	push(200);
	
	printf("1st pop() : %d\n", pop());
	
	push(300);
	
	printf("2nd pop() : %d\n", pop());
	printf("3rd pop() : %d\n", pop());
	
	return 0;
}*/
