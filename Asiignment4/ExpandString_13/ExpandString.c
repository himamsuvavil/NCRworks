#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int expand(char *s1, char *s2)
{
	int i, j, k, start, end;
	i = j = k = 0;
	while (s1[i] != '\0')		//Running until end of string
	{
		if (s1[i] == '-')		//if expansion symbol is encountered 
		{
			start = s1[i - 1];		//charcater before '-'
			end = s1[i + 1];		//character after '-'
			if (s1[end] == '-')		//condition to check string of format a--h
				return -1;
			if ((start>='a'&&end<='z')||(start>='A'&&end<='Z')||(start>='0'&&end<='9'))		//condition to check if two characters of string before and after '-' are in valid format
			{
				for (j = start + 1; j < end; j++)
				{
					s2[k] = j;
					k++;
				}
			}
			else
			{

				if (isalpha(s1[i - 1]) && isalpha(s1[i + 1]))		//if start and end charcters are alphabets
				{
					if ((islower(s1[i + 1]) && isupper(s1[i - 1])) || (islower(s1[i - 1]) && isupper(s1[i + 1])))		//if start and end chacters are of different CASE
						printf("You have entered two alphabates of different CASE to expand\n");
					else
						printf("You have entered wrong order to expand\n");
				}
				else  if ((isdigit(s1[i - 1]) && isalpha(s1[i + 1])) || (isdigit(s1[i + 1]) && isalpha(s1[i - 1])))		//if start and end characters of string are in invalid format
					printf("You have entered input to be expand as alpha-digit or digit-alpha format\n");
				else
					printf("Given string is of invalid fromat of (abc9-3 or abj-a)\n");

				return 0;
			}
		}
		else/*----------storing remaing characters----------*/
		{
			s2[k] = s1[i];
			k++;
		}
		i++;
	}
	s2[k] = '\0';		// Ending the expanded string
	puts(s2);
	return 0;
}
int getsizes2(char *s1)			//to determine the size of the expanded string
{
	
	int i = 0, s2size = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '-')
			s2size++;
		else if (!(isdigit(s1[i]) || isalpha(s1[i])))		//if characters are other than alphabates and integers raise error
			return -1;
		i++;
	}
	return s2size;
}
int FirstLastCheck(char *s)			//To check is beginning and end characters of given string are alphabates or integers
{
	if ((isalpha(s[0]) || isdigit(s[0])) && (isalpha(s[strlen(s) - 1]) || isdigit(s[strlen(s) - 1])))
		return 0;
	return -1;
}
int main()
{
	char *s1, *s2;			//string varaibles
	int s1size ,s2size;		//size varibles for strings
	s1 = s2 = NULL;

	/*----------------Taking String1 data-------------*/
	printf("Enter the size for the string that you want to enter: ");
	scanf("%d", &s1size);									//string1 size is inputed
	s1 = (char *)malloc(s1size*(sizeof(char))+1);			//Memory for string1 is allocated

	if (s1 == NULL)											//Checking for failure condition for string1 memory allocation
		printf("Memory allocation for input string is failed\n");
	else
	{
		printf("Enter string to be Expanded-(Format Ex:abc-h01-6): ");		//User input of string1
		scanf("%s", s1);
		if (strlen(s1) == s1size)
			printf("Given string needs more memory\n");
		else
		{
			/*-------------------To check is fisrt and last charcaters of string are valid---------------*/
			int checkvar1 = FirstLastCheck(s1);
			if (checkvar1 == -1)
			{
				printf("You wanted to expand string with invalid beginning or ending \n");
				getchar();
				return 0;
			}
			else
			{
				/*----------------To check if there is no expansion for given string----------------*/
				int checkvar2 = getsizes2(s1);

				if (checkvar2 == 0)				//No expansion of given string
					printf("String cannot be expanded\n");
				else if (checkvar2 == -1)		//Invalid characters in given string condition
					printf("Invalid special character are in given string\n");
				else
				{
					s2size = s1size +( checkvar2 * 24)-checkvar2;
					/*size allocated for string2 based on number of '-' and it is done by adding size of string1 with 31*no.of'-'s (used 31 as to allocate for alphabets and for number from 0-9) */

					s2 = (char *)malloc(s2size*(sizeof(char))+1);
					if (s2 == NULL)
						printf("Memory allocation for Expanded string is failed\n");
					else
					{
						int checkvar3 = expand(s1, s2);		//string expansion
						if (checkvar3 == -1)			//condition to handle string of format ab---r 
							printf("You have entered wrong format to expand as (abc--h)\n");
					}
				}
			}
		}
	}
	
	system("pause");
	return 0;
}