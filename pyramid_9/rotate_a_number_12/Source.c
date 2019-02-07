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
int rotate_right(int a, int b)
{
	int tmp=a, sum,r1,r2,i = 0;
		while (b > 0)
		{
			sum = 0;
			r1 = tmp % 10;
			tmp /= 10;
			i = 0;
			while (tmp > 0)
			{
				r2 = tmp % 10;
				sum += r2*power(10, i);
				i++;
				tmp /= 10;
			}
			sum += r1*power(10, i);
			b--;
			tmp = sum;
		}
		printf("After rotations number is:%d", sum);
		return sum;
}
int main()
{
	int n, b;
	printf("Enter the number:");
	scanf_s("%d", &n);
	printf("Enter the no.of positions:");
	scanf_s("%d", &b);
	rotate_right(n, b);
	scanf_s("%d", &n);
	return 0;
}