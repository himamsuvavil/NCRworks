#include<stdio.h>
int main()
{
	int a[100], i, j, n, sum, sum1;
	printf("Enter size of array:");
	scanf_s("%d", &n);
	printf("Enter elements:");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("enter sum to be verified:");
	scanf_s("%d", &sum1);
	for (i=0; i < n; i++)
	{
		sum = 0;
		for (j = i; j < n; j++)
		{
			sum += a[j];
			if (sum == sum1)
			{
				printf("Sum is obtained from index %d to %d\n", i, j);
				scanf_s("%d", &n);
				return 0;
			}
				
		}
	}
	printf("No subarray is found\n");
	scanf_s("%d", &n);
	return 0;
	
	
}