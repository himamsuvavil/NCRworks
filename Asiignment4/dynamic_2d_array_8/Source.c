#include<stdio.h>
#include<ctype.h>
int main()
{
	
	int n,i;
	printf("Enter n:");
	scanf_s("%d", &n);
	char **s;
	s = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
	{
		s[i]= (char )malloc(sizeof(char ) * 30);
	}
	printf("Enter strings:");
	for (i = 0; i < n; i++)
	{
		gets(s[i]);
	}
	printf("values entered are:");
	for (i = 0; i < n; i++)
	{
		printf("%s\n", s[i]);
	}

}