#include<stdio.h>
int main()
{
	int n, a[7] = { 0 }, i, j = 7;
	printf("Enter n:");
	scanf_s("%d", &n);
	if ((n >= 0) && (n <= 32))
	{
		a[0] = 1;
		while (n>0)
		{
			a[j] = n % 2;
			n = n / 2;
			j--;
		}
	}
	for (i = 0; i<8; i++)
		printf("%d", a[i]);
	scanf_s("%d", &n);
}
