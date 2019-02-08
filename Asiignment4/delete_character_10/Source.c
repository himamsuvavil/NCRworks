#include<stdio.h>
#include<string.h>
int deletechar(char *s, char c)
{
	int i=0, k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
			s[k++] = s[i++];
	}
	s[k] = '\0';
	puts(s);
	gets(s);
	return 0;

}
int main()
{
	char a[100],ch;
	char *s = a;
	printf("Enter string:");
	gets(a);
	printf("Enter character to be deleted:");
	scanf_s("%c", &ch);
	deletechar(s, ch);
	gets(a);
	return 0;
}
