void remove_comments(char *fp)
{
	
	while (!(feof(fp)))
	{
		char ch = fgetc(fp);
		if (ch == '/')
		{
			char ch1 = fgetc(fp);
			if (ch1 == '/')
			{
				
				while (fgetc(fp) != '\n')
					continue;
			}
			else if (ch1 == '*')
			{
				while (1)
				{
				char ch2 = fgetc(fp);
				if (ch2 == '*')
				{
					char ch3 = fgetc(fp);
					if (ch3 == '/')
						break;
				}
				}
				
			}
		}
		else
		{
			//fputc(ch, fw);
			printf("%c", ch);
		}
	}
//	return 0;
}