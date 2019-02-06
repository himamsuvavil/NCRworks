#include<stdio.h>
int main()
{
	int x[8]={10,20,30,40,50,60,70,80}, i;
	printf("Given array is:");
	for (i = 0; i < 8; i++)
		printf("%d ", x[i]);
	printf("\n value of x is:%d", x);
	printf("\nvalue of (x+2) is :%d", (x + 2));
	printf("\nvalue of *x is :%d", *x);
	printf("\nvalue of (*x+2) is :%d",(*x + 2));
	printf("\nvalue of *(x+2) is :%d", *(x + 2));
	scanf_s("%d", &i);
	return 0;
}
