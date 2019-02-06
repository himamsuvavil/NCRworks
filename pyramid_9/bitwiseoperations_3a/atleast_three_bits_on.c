#include <stdio.h>

int main()
{
	int val = 0xCAFE;
	int r, l;
	//bits are on or not
	if ((val & 14) == 14 || (val & 11) == 11 || (val & 13) == 13 || (val & 7) == 7 || (val & 15) == 15)
	{
		printf("Atleast 3 bits are on\n");
	}

	return 0;
}
