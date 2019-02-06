#include<stdio.h>
int main()
{
	int r,i,n;
	printf("Enter a number:");
	scanf_s("%d", &n);
	printf("It's binary format is: ");
	for (i = 31; i >= 0; i--)
	{
		r = n >> i;
		if ((r & 1)==1)
			printf("1");
		else
			printf("0");
	}
	scanf_s("%d", &n);
	return 0;
	
}