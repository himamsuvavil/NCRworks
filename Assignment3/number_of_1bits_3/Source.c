#include<stdio.h>
int main()
{
	int n, l, count = 0, i;
	printf("Enter the number:");
	scanf_s("%d", &n);
	for (i = 31; i >= 0; i--)
	{
		l = n >> i;
		if ((l & 1) == 1)
			count++;
	}
	printf("Number of 1 bits are:%d\n", count);
	scanf_s("%d", &n);
	return 0;
}