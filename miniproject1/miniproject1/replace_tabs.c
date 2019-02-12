int replace(char *fp)
{
	printf("hello\n");
	while(!feof(fp))
	{
		char ch = fgetc(fp);
		if(ch=='\t')
		{
			
		
			printf("/t");
		}
		else
		{
			printf("%c", ch);
		}
	}
	return 0;
}