#include<stdio.h>
int main()
{
	char a[100];
	int space = 0, alpha = 0, num = 0, tabs = 0, i;
	printf("Enter the string:");
	gets(a);
	for (i = 0; a[i] != '\0';i++)
	{
		if (isalpha(a[i]))
			alpha++;
		else if (isdigit(a[i]))
			num++;
		else if (a[i] == ' ')
			space++;
		else
			tabs++;
	}
	printf("Alpabets:%d\nNumber:%d\nSpaces:%d\nTabs:%d", alpha, num, space, tabs);
	scanf_s("%s",a);
	return 0;
}