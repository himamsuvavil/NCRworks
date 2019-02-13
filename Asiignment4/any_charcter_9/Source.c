#include<stdio.h>

int any(char *s1, char *s2)

{

	int i = 0, j;

	while (s1[i] != '\0')

	{

		j = 0;

		while (s2[j] != '\0')

		{

			if (s1[i] == s2[j])

				return i;

			j++;

		}

		i++;

	}

	return -1;

}

int main()

{

	char a[30], b[30];

	printf("Enter strings:");

	gets(a); gets(b);

	int d = any(a, b);

	if (d == -1)

		printf("No such index");

	else

		printf("Same characters are found at the index %d of string %s\n", d, a);

	return 0;

}

