
void count_characters(char *fp)
{
	int digit, alpha, space, special;
	digit = alpha = space = special = 0;
	
	while (!(feof(fp)))
	{
		char ch = fgetc(fp);
		if (isdigit(ch))
			digit++;
		else if (isalpha(ch))
			alpha++;
		else if (ch == ' ')
			space++;
		else
			special++;
		
	}
	printf("Digits are:%d\nAlphabets are:%d\nSpaces are:%d\nSpecial characters are:%d\n", digit, alpha, space, special);

}