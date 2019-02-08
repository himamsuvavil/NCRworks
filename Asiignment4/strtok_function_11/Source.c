#include<stdio.h>
#include<string.h>
int main()
{
	char s[100], delim[3] = { "*" };
	char *token;
	printf("Enter sentence:");
	gets(s);
	token = strtok_s(s,delim);
	while (token != NULL)
	{
		printf("%s\n", *token);
		token = strtok_s(NULL, delim);
	}

}