#include<stdio.h>
#include<ctype.h>
int main()
{
	char s[100];
	printf("Enter string:");
	gets(s);
	printf("Reverse of the string is:%s",strrev(s));
	gets(s);
	return 0;
}