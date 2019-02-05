#include<stdio.h>
int res = -1;
int main()
{
	int a, b;
	printf("Enter a,b:");
	scanf_s("%d%d", &a, &b);
	res = add(a, b);
	printf("Addition gives:%d\n", res);
	res = sub(a, b);
	printf("Subtraction gives:%d\n", res);
	res = mul(a, b);
	printf("Multiplication gives:%d\n", res);
	res = div(a, b);
	printf("Division gives:%d\n", res);
	scanf_s("%d", &a);
	return 0;
}