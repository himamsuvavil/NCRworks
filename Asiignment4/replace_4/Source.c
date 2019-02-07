#include<stdio.h>
int replace(char *s)
{
	int i = 0,count=0;
	while (s[i] != '\0')
	{
		
		if (s[i] == ' ')
		{
			
			s[i] = '-';
			count++;
		}
		i++;
	}
	printf("After replace string is:%s\n No.of spaces:%d\n", s, count);
	return 0;
}
int main()
{
	char a[100];
	char *s=NULL;
	printf("Enter string with spaces:");
	gets(a);
	s = a;
	replace(s);
	scanf_s("%s", a);
	return 0;

}