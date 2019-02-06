#include<stdio.h>
int main()
{
	int i, j, count, a, b;
	printf("Enter the start and end numbers of the interval:");
	scanf_s("%d%d", &a, &b);
	printf("Prime numbers between %d and %d are:", a, b);
	for (i = a; i <= b; i++)
	{
		count = 0;
		for (j = 2; j<i; j++)
		{
			if (i%j == 0)
				count++;
		}
		if (count == 0)
			printf("%d ", i);
	}
	scanf_s("%d", &a);
	return 0;
}
