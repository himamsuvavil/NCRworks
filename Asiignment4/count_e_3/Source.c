#include<stdio.h>
int main()
{
	char *s[] = { "we will teach you how to", "move a mountain","level a building", "Erase the past", "make a million" };
	int i,j,count = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; s[i][j] != '\0'; j++)
		{
			if ((*(*(s + i) + j)) == 'e' || (*(*(s + i) + j)) == 'E')
				count++;

		}
	}
	printf("no.of 'E' are:%d", count);
	scanf_s("%d",&count);
	return 0;

}