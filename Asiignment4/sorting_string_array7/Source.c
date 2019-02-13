#include<stdio.h>

#include<ctype.h>

#include<string.h>

int main()

{

	char **s = NULL;

	int n, j, i;

	printf("Enter n:");

	scanf_s("%d", &n);

	s = (char **)malloc(n * sizeof(char *));

	for (i = 0; i<n; i++)

		*(s + i) = (char *)malloc(30 * sizeof(char));

	if (s == NULL)

		printf("memory allocation failed\n");

	printf("Enter strings:");

	for (i = 0; i<n; i++)

		scanf("%s", s[i]);

	char *tmp;

	for (i = 0; i<n - 1; i++)

	{

		for (j = i; j<n; j++)

		{

			int d = strcmp_s(s[i], s[j]);

			if (d>0)

			{

				tmp = *(s + i);

				*(s + i) = *(s + j);

				*(s + j) = tmp;

			}

		}

	}

	printf("After swapping:");

	for (i = 0; i<n; i++)

		puts(s[i]);
	gets(s[0]);
	return 0;

}