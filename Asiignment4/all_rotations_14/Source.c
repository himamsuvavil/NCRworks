#include<stdio.h>
#include<string.h>
int main()
{
	char a[2], s[50], s1[50];
	int i, len;
	printf("Enter string: ");
	gets(s);
	len = strlen(s);
	printf("%d\n", len);
	
	for (i = 0; i < len; i++)
	{
		a[0] = s[0]; a[1] = '\0';
		strcpy_s(s1, sizeof(s)+1,s + 1);
		strcat_s(s1, sizeof(s)+1,a);
		printf("%s\n", s1);
		strcpy_s(s, sizeof(s) + 1, s1);
	}
	
	gets(s);
	return 0;
}