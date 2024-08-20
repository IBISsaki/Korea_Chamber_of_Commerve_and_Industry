#include <stdio.h>

int main(void)
{
	int nums[5] = {1, 2, 3, 4, 5};
	int *p;
	
	p = nums;								// p = &nums[0];
	printf("*p = %d\n", *p);			// 
	
	++p;									// p = p + 1;
	printf("*p = %d\n", *p);	
	
	return 0;
}
