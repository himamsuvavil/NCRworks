#include<stdio.h>
#define bits 32
int main()
{
	int n,d;
	printf("Enter n:");
	scanf_s("%d", &n);
	printf("Enter no.of positions to rotate:");
	scanf_s("%d", &d);
	printf("%d\n",rotate_right(n, d));
	scanf_s("%d", &n);
	return 0;
}
int rotate_right(int n, int d)
{
	return n >> d | n << (bits - d);
}