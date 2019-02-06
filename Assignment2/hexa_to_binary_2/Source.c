#include<stdio.h>
int main()
{
	int n, l, i;
	printf("Enter a hexadecimal number:");
	scanf_s("%x", &n);
	printf("Corresponding binary value is:");
	for (i = 31; i >= 0; i--)
	{
		l = n >> i;
		if ((l & 1) == 1)
			printf("1");
		else
			printf("0");
	}
	scanf_s("%x", &n);
	return 0;
}