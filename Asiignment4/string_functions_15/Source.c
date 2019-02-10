#include<stdio.h>

#include<string.h>

int strrevfunction(char *s)

{

	int i, j;

	char t;

	i = 0; j = strlen(s) - 1;

	while (i<j)

	{

		t = s[i];

		s[i] = s[j];

		s[j] = t;

		i++; j--;

	}

	printf("%s\n", s);

}

int strcpyfunction(char *s1, char *s2)

{

	int i = 0;

	while ((s2[i] = s1[i++]) != '\0')

		continue;

	printf("%s\n", s2);

}

int strcatfunction(char *s1, char *s2)

{

	int i = 0, j = 0;

	while (s1[i] != '\0')

		i++;

	while ((s1[i++] = s2[j++]) != '\0')

		continue;

	printf("%s\n", s1);

}

int strcmpfunction(char *s1, char *s2)

{

	int i = 0;

	while (s1[i] == s2[i])

	{

		if (s1[i] != '\0')

			return 0;

		i++;

	}

	if ((s1[i] - s2[i])>0)

		return 1;

	else

		return -1;

}

int main()

{

	char s1[30], s2[30];

	printf("Enter string:");

	gets(s1);

	printf("Reverse of strings:");

	strrevfunction(s1);

	printf("String copied to string s2 is:");

	strcpyfunction(s1, s2);

	printf("Enter string to be concatinated:");

	gets(s2);

	printf("After concatination:");

	strcatfunction(s1, s2);

	printf("Enter a string to compare:");

	gets(s2);

	int d = strcmpfunction(s1, s2);

	if (d == 0)

		printf("Both the strings are same");

	else if (d>0)

		printf("string %s is greater than %s", s1, s2);

	else

		printf("String %s is lesser than %s", s1, s2);

	return 0;

}