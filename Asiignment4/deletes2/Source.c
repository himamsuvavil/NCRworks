#include<stdio.h>

#include<string.h>

int deletes2(char *s1, char *s2)

{

	int m, i = 0, j = 0, c, k;

	while (s1[i] != '\0')

	{

		j = 0; m = 0;

		while (s2[j] != '\0')

		{

			if (s1[i] == s2[j])

			{

				k = i + 1; c = i;

				while (s1[k] != '\0')

				{

					s1[c] = s1[k];

					c++; k++;

				}

				s1[c] = '\0';

				m++;

				printf("%s\n", s1);

			}

			j++;

		}

		if (m == 0)

			i++;

	}

	printf("After deleting characters from string are:%s\n", s1);

	return 0;

}

int main()

{

	char a[30], b[30];

	printf("Enter strings:");

	scanf_s("%s%s", a, b);

	deletes2(a, b);

	return 0;

}