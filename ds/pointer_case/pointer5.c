#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}

int substract(int a, int b)
{
	return a-b;
}

int main(void)
{
	int (*fp)(int, int);
	
	int re;
	
	fp = &add;
	re = (*fp)(4, 3);
	printf("re = %d\n", re);
	
	fp = substract;
	re = fp(4, 3);
	printf("re = %d\n", re);

	return 0;
}
