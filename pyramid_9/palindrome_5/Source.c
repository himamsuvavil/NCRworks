#include<stdio.h>
int power(int a,int b)
{
	int l = 1;
	while (b > 0)
	{
		l = l*a;
		b--;
	}
	return l;
}
int main()
{
	int n, rev, sum = 0, tmp, len = 0;
	printf("Enter a number:");
	scanf_s("%d", &n);
	tmp = n;
	while (tmp > 0)
	{
		len++;
		tmp /=10;
	}
	tmp = n;
	while (tmp > 0)
	{
		rev = tmp % 10;
		sum += rev*power(10, len - 1);
		len--;
		tmp /= 10;
	}
	if (sum == n)
		printf("Number is palindrome");
	else
		printf("Number is not plaindrome");
	scanf_s("%d", &n);
	return 0;

}