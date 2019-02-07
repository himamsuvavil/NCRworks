#include<stdio.h>
int main()
{
	int n, r, sum = 0;
	printf("Enter the number:");
	scanf_s("%d", &n);
	while (n > 0)
	{
		r = n % 10;
		sum += r;
		n /= 10;
	}
	printf("Sum of digits is:%d", sum);
	scanf_s("%d", &n);
	return 0;

}