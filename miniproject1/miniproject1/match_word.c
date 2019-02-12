
int rotate(char *fp,char *s)
{
	printf("Hello");
	char a[30], l[3];
	while (!feof(fp))
	{
		
		int i = 0;
		char ch = getc(fp);
		//fgets(ch,30,fp);
			
		while (ch != '\0')
		{
			
			a[i] = ch;
			i++; 
			ch = getc(fp);
		}
		a[i] = '\0';
		if (strcmp(a, s) == 0)
		{
			//printf("%s", strrev(a));
			strcpy_s(a,sizeof(s)+1 ,s + 1);
			l[0] = s[0];
			l[1] = '\0';
			strcat_s(a,sizeof(s)+1,  l);
			strcpy_s(s, sizeof(a)+1, a);
		}
		else
		{
			puts(ch);
		}
		
		

	}
	return 0;
}