#include<stdio.h>
#include<string.h>
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
			for (j = start + 1; j < end; j++)
			{
				s2[k] = j;
				k++;
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
int main()
{
	char a[50],b[100];
	char *s1 = a,*s2=b;
	printf("Enter string:");
	gets(a);
	expand(s1, s2);
	gets(a);
	return 0;
}