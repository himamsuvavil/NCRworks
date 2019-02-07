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
	int n, r, c = 0, tmp;
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
	tmp = sum;
	while (tmp > 0)
	{
		r = tmp % 16;
		if (r <= 9)
			printf("%d", r);
		else
		{
			switch (r)
			{
			case 10:printf('A');
				break;
			case 11:printf('B');
				break;
			case 12:printf('C');
				break;
			case 13:printf('D');
				break;
			case 14:printf('E');
				break;
			case 15:printf('F');
				break;
			}
		}
		tmp /= 16;
	}
	scanf_s("%d", &n);
	return 0;
}