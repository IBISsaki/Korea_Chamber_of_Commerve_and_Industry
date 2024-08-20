#include <stdio.h>

int main(void)
{
	int a = 100;
	double d = 3.14;
	
	void *p;
	p = &a;
	*(int *)p = 200;
	
	p = &d;
	*(double *)p = 2.718;
	
	printf("a = %d\n", a);
	printf("d = %f\n", d);
	return 0;
}
