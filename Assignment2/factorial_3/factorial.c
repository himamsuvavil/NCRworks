#include<stdio.h>
long int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n*fact(n - 1);
}
int main()
{
	int n;
	printf("Entee the value of n:");
	scanf_s("%d", &n);
	printf("Factorial value is :%ld\n", fact(n));
	scanf_s("%d", &n);
	return 0;
}