#include <stdio.h>

int main(void)
{
	int nums1[5] = {1, 2, 3, 4, 5};
	int nums2[5];
	
	// nums2 = nums1; 배열은 대입 불가
	for(int i = 0; i < 5; i++)
	{
		nums2[i] = nums1[i];
	}
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", nums2[i]);
	}
	printf("\n");
	
	return 0;
}
