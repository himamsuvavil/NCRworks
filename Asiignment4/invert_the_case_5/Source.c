#include<stdio.h>
#include<ctype.h>
int main()
{
	char s[100];
	int i;
	printf("Enter the string:");
	gets(s);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (isupper(s[i]))
			s[i] = tolower(s[i]);
		else if(islower(s[i]))
			s[i] = toupper(s[i]);
	}
	printf("After iverting the cases string is:%s\n", s);
	gets(s);
	return 0;
}