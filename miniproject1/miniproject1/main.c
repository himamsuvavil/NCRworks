#include<stdio.h>
#include<string.h>
#include<ctype.h>



int main()
{
	FILE *fp = NULL;
	char s[30];
	fopen_s(&fp, "one1.txt", "r");
	if (fp == NULL)
	{
		printf("pointer of  file is failed");
		scanf_s("%s", s);
	}
	else
	{
		int ch;
		printf("1.Counting\n2.Remove Comments\n3.Matching word\n4.Replace tabs\n");
		while (1)
		{
			printf("Enter your choice:");
			scanf_s("%d", &ch);
			switch (ch)
			{
				case 1:printf("The count of variables are:\n\n");
					count_characters(fp);
					fseek(fp, 0, SEEK_SET);
					break;
				case 2: remove_comments(fp);
					printf("\n\nComments are removed\n\n");
					fseek(fp, 0, SEEK_SET);
				break;
				case 3:printf("Enter a string to be matched\n");
					gets(s);
					printf("After rotation of the given string:\n");
					rotate(fp, s);
					fseek(fp, 0, SEEK_SET);
					break;
				case 4:replace(fp);
					printf("\n\nAll tabs in data are replaed with '/t'\n\n");
					fseek(fp, 0, SEEK_SET);
					break;
			}
		}
	}
	fclose(fp);
	return 0;
}