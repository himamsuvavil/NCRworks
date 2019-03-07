#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int expand(char *s1, char *s2)
{
	int i, j, k,start,end;
	i = j = k = 0;
	while (s1[i]!= '\0')
	{
		if (s1[i] == '-')
		{
			start = s1[i - 1];
			end = s1[i + 1];
			if (start <= end)
			{
				for (j = start + 1; j < end; j++)
				{
					s2[k] = j;
					k++;
				}
			}
			else
			{
				
				if (isalpha(s1[i - 1]) && isalpha(s1[i + 1]))
				{
					if ((islower(s1[i + 1]) && isupper(s1[i - 1])) || (islower(s1[i - 1]) && isupper(s1[i + 1])))
						printf("You have entered two alphabates of different CASE to expand\n");
					else
						printf("You have entered wrong order to expand\n");
				}
				else  if ((isdigit(s1[i - 1])&& isalpha(s1[i + 1])) || (isdigit(s1[i + 1])&& isalpha(s1[i - 1])))
					printf("You have entered input to be expand as alpha-digit or digit-alpha format\n");		
				
				return 0;
			}
		}
		else
		{
			s2[k] = s1[i];
			k++;
		}
		i++;
	}
	s2[k] = '\0';
	puts(s2);
	return 0;
}
int getsizes2(char *s1)
{
	printf("hello");
	int i = 0,s2size=0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '-')
			s2size++;
		i++;
	}
	printf("%d\n", s2size);
	return s2size;
}
int main()
{
	//char *s1, *s2;
	//int s1size ;//s2size;
	//s1 = s2 = NULL;
	//printf("Enter the size for the string that you want to enter: ");
	//scanf_s("%d", &s1size);
	//s1 = (char *)malloc(s1size*(sizeof(char)+1));
	//if (s1 == NULL)
	//	printf("Memory allocation for input string is failed\n");
	//else
	//{
	//	printf("Enter string to be Expanded-(Format Ex:abc-h01-6): ");
	//	//scanf_s("%s", s1,s1size);
	//	gets(s1);
	//	printf("%s\n", s1);
	//}
	char s[100];
	gets(s);
	puts(s);
	system("pause");
	return 0;
}