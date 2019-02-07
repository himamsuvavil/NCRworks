#include<stdio.h>
int main()
{
	float table[2][3] = { {1.1,1.2,1.3},{2.1,2.2,2.3} };
	printf("value at table:%d\n", table);
	printf("value at (table+1):%d\n", (table + 1));
	printf("value at *(table+1):%d\n", *(table + 1));
	printf("value at (*(table+1)+1):%d\n", (*(table + 1) + 1));
	printf("value at (*(table)+1):%d\n", (*(table)+1));
	printf("value at *(*(table+1)+1)):%f\n", *(*(table + 1) + 1));
	printf("value at *(*(table)+1):%f\n", *(*(table)+1));
	printf("value at *(*(table+1):%f\n", *(*(table + 1)));
	printf("value at *(*(table)+1)+1:%f\n", *(*(table)+1) + 1);
	scanf_s("%f", &table[0][0]);
	return 0;
}