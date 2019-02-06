#include<stdio.h>
int invertponwards(int n, int p, int b)
{
	int i, l, k = 0;
	printf("Binary format of given number is:");
	for (i = 31; i >=0; i--)
	{
		l = n >> i;
		if ((l & 1) == 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	printf("After inverting the bits:");
	for (i = 31; i >=0; i--)
	{
		l = n >> i;
		if (i == (31- p - 1))
		{
			//intf("%d ", i);
			while (k <b)
			{
				if ((l & 1) == 1)
					printf("0");
				else
					printf("1");
				k++; i--;
			}
		}
		else
		{
			if ((l & 1) == 1)
				printf("1");
			else
				printf("0");
		}
	}

}
int main()
{
	int n, p, b;
	printf("Enter the number:");
	scanf_s("%d", &n);
	printf("Enter postion to invert bits:");
	scanf_s("%d", &p);
	printf("Enter no.of bits to be inverted:");
	scanf_s("%d", &b);
	invertponwards(n, p, b);
	scanf_s("%d", &n);
	return 0;
}