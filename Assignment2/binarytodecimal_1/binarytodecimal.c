#include<stdio.h>
long int power(int a, int b)
{
	long int l = 1;
	while (b > 0)
	{
		l = l*a;
		b--;
	}
	return l;
}
int main()
{
	int n, r,c=0;
	long int sum = 0;
	printf("Enter binary value of number:");
	scanf_s("%d", &n);
	while (n > 0)
	{
		r = n % 10;
		sum += r*power(2, c);
		c++;
		n /= 10;
	}
	printf("It's decimal value is:%d\n", sum);
	scanf_s("%d", &n);
	return 0;
}