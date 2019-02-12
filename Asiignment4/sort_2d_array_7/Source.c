#include<stdio.h>
#include<string.h>
int main()
{
	char a[15][20], tmp[100];
	int i, j, n;
	printf("Enter no.of strings:");
	scanf_s("%d", &n);
	printf("Enter strings: ");
	for (i = 0; i <= n; i++)
	{
		gets(a[i]);
	}
	int val;
	for (i = 0; i < (n); i++)
	{
		val = strcmp(a[i], a[i + 1]);
		if (val < 0)
		{
			strcpy_s(tmp, sizeof(a[i][20])+1, a[i]);
			strcpy_s(a[i], sizeof(a[i+1][20])+1, a[i+1]);
			strcpy_s(a[i+1], sizeof(a[i][20])+1, tmp);
		}
	}
	printf("After sorting:\n");
	for (i = 0; i <= n; i++)
	{
		puts(a[i]);
	}
	gets(a[0]);
	return 0;
}