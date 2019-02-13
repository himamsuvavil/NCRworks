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

	for (i = 0; i < n; i++)

		*(s + i) = (char *)malloc(30 * sizeof(char));

	if (s == NULL)

		printf("memory allocation failed\n");

	printf("Enter strings:");

	for (i = 0; i < n; i++)

		scanf("%s", s[i]);
	printf("Entered strings are:");
	for (i = 0; i < n; i++)

		puts(s[i]);
	return 0;
}