/*------Header files----------------*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

/*-----------------String Reverse Function----------*/

int strrevfunction(char *s)
{
	int i, j;
	char t;
	i = 0; j = strlen(s) - 1;
	while (i<j)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++; j--;
	}
	return 0;
}

/*------------------String Copy Function--------------*/

int strcpyfunction(char *s1, char *s2)
{
	int i = 0;
	while ((s2[i] = s1[i++]) != '\0')
		continue;
	return 0;
}

/*-------------String Concatination Function------------*/

int strcatfunction(char *s1, char *s2)
{
	int i = 0, j = 0;
	while (s1[i] != '\0')
		i++;
	while ((s1[i++] = s2[j++]) != '\0')
		continue;
	return 0;
}

/*------------String Compare Function----------------*/

int strcmpfunction(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] != '\0')
			return 0;
		i++;
	}
	if ((s1[i] - s2[i])>0)
		return 1;
	else
		return -1;
}

/*--------------Dynamic Memory Allocation Function for passed String--------------*/

char* memoryallocation(char *s, int size)
{
	s = (char *)malloc(size * sizeof(char));
	return s;
}

/*-----------------Main Function------------------*/

int main()
{
	char *s1, *s2;
	int s1size, s2size;
	s1 = s2 = NULL;

	/*------------------String1 Details-----------*/
	printf("Enter size of string you want to enter (Size must be of Positive Integer):");
	scanf("%d", &s1size);
	if (s1size > 0)
	{
		s1 = memoryallocation(s1, s1size);

		//----Failure Condition for Memory Allocation of String1

		if (s1 == NULL)
			printf("Failed to allocate memory for given first string\n");
		else
		{
			printf("Enter string you want to perform operations (String must be within given size):");
			scanf(" %[^\n]s", s1);
		}
		if (strlen(s1) > s1size)
			printf("Trying to store beyond memory will lead to loss of data\n");
		else
		{
			/*---------------string reverse functionality----------------*/

			printf("Reverse of given string is:");
			strrevfunction(s1);
			printf("%s\n", s1);

			strrevfunction(s1);
			/*---------------String copy functionality-------------------*/

			printf("String copied to string s2 is:");
			s2 = memoryallocation(s2, s1size);

			//----Failure Condition for Memory Allocation of String2

			if (s2 == NULL)
				printf("Failed to allocate memory to store copied string\n");
			else
			{
				strcpyfunction(s1, s2);
				printf("%s\n", s2);
				free(s2);

			}

			/*------------------String Concatination functionality--------------*/

			printf("Enter size of the string you want to concatinate:");
			scanf("%d", &s2size);
			if (s2size > 0)
			{
				s2 = memoryallocation(s2, s2size);

				//----Failure Condition for Memory Allocation of String2

				if (s2 == NULL)
					printf("Failed to allocate memory to store copied string\n");
				else
				{
					printf("Enter string to be concatinated:");
					scanf("%s", s2);
					if (strlen(s2) > s2size)
						printf("Trying to store beyond memory will lead to loss of data\n");
					else
					{
						printf("After concatination:");
						strcatfunction(s1, s2);
						printf("%s\n", s1);
						free(s2);
					}
				}
			}
			else
				printf("Invalid string size\n");


			/*----------------------String Comparision functionality----------------------*/

			printf("Enter size of the string you want to compare with %s :", s1);
			scanf("%d", &s2size);
			char invalid = '0' + s2size;
			if (s2size > 0)
			{
				s2 = memoryallocation(s2, s2size);

				//----Failure Condition for Memory Allocation of String2

				if (s2 == NULL)
					printf("Failed to allocate memory to store copied string\n");
				else
				{
					printf("Enter a string to compare:");
					scanf("%s", s2);
					if (strlen(s2) > s2size)
						printf("Trying to store beyond memory will lead to loss of data\n");
					else
					{
						int d = strcmpfunction(s1, s2);
						if (d == 0)
							printf("Both the strings are same");
						else if (d > 0)
							printf("String %s is greater than %s", s1, s2);
						else
							printf("String %s is lesser than %s", s1, s2);
					}
				}
			}
			else
				printf("Invalid string size\n");
		}
	}
	else
		printf("Invalid string size\n");
	getchar();
	return 0;

}