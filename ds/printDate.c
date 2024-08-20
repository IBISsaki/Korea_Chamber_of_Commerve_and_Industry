#include <stdio.h>

typedef struct
{
	int year;
	int month;
	int day;
} Date;

void printDate(Date d)
{
	printf("(%d/%d/%d)\n", d.year, d.month, d.day);
}

void printDate2(const Date *pd)
{
	printf("(%d/%d/%d)\n", (*pd).year, (*pd).month, (*pd).day);
	printf("(%d/%d/%d)\n", pd->year, pd->month, pd->day);
}


int main(void)
{
	Date today = {2024, 8, 20};
	
	printDate(today);
	printDate2(&today);
	return 0;
}
