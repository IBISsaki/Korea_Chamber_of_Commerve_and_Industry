#include <stdio.h>

int f1(void)
{
	return 100;
}

void f2(int *p)
{
	*p = 200;
}

int main(void)
{
	int re;
	re = f1();
	printf("re = %d\n", re);
	
	f2(&re);
	printf("re = %d\n", re);
	
	return 0;
}
