#include<stdio.h>
int power(int a, int b)
{
	int l = 1;
	while (b > 0)
	{
		l = l*a;
		b--;
	}
	return l;
}
int main()
{
	int n, sum = 0, tmp, c = -1;
	printf("Enter the number:");
	scanf_s("%d", &n);
	tmp = n;
	while (tmp>0)
	{
		tmp /= 10;
		c++;
	}
	while (n>0)
	{
		tmp = n % 10;
		sum += power(10, c)*tmp;
		c--;
		n /= 10;
	}
	printf("Reverse of the number is:%d", sum);
	scanf_s("%d", &n);
	return 0;
}