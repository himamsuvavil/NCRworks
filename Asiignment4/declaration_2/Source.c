#include<stdio.h>
int main()
{
	char *color[6] = { "red","green","blue","white","black","yellow" };
	printf("value at color:%d\n", color);
	printf("value at (color+2):%d\n", (color + 2));
	printf("value at *color:%s\n", *color);
	printf("value at *(color+2):%s\n", *(color + 2));
	printf("Vlaue at color[5] and *(color+5) are:%s  %s\n", color[5], *(color + 5));
	gets(color);
	return 0;
}