#include<stdio.h>
long int power(int a, int b)
{
	int s = 1;
	while (b>0)
	{
		s = s*a;
		b--;
	}
	return s;
}
int main()
{
	int n,tmp,r,len=0;
	long int sum = 0;
	printf("Enter the number:");
	scanf_s("%d", &n);
	tmp = n;
	while (tmp > 0)
	{
		len++;
		tmp /= 10;
	}
	tmp = n;
	while (tmp>0)
	{
		r = tmp % 10;
		sum += power(r, len);
		tmp /= 10;
	}
	if (n == sum)
		printf("Armstrong number");
	else
		printf("Not an Armstrong number");
	scanf_s("%d", &n);
	return 0;
		

}