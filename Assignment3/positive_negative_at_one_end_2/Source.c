#include<stdio.h>
int main()
{
	int a[100], i, n, l, k = 0;
	printf("Enter size of the array:");
	scanf_s("%d", &n);
	printf("Enter elements");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			l= a[i];
			a[i] = a[k];
			a[k] = l;
			k++;
		}
	}
	printf("Sorted array is:");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	scanf_s("%d", &n);
	return 0;
}