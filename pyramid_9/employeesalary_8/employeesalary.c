#include<stdio.h>
void gross_salary(int sal, int hrd, int da)
{
	int gs = sal + hrd + da;
	printf("gross salary is %d", gs);
}
int percentage(int a, int b)
{
	int c = (b*a) / 100;
	return c;
}
int main()
{
	int sal, h, d;
	printf("enter basic salary\n");
	scanf_s("%d", &sal);
	if (sal >= 1 && sal <= 4000)
	{
		h = percentage(sal, 10);
		d = percentage(sal, 50);
		gross_salary(sal, h, d);
	}
	else if (sal>4000 && sal <= 8000)
	{
		h = percentage(sal, 20);
		d = percentage(sal, 60);
		gross_salary(sal, h, d);
	}
	else if (sal>8000 && sal <= 12000)
	{
		h = percentage(sal, 25);
		d = percentage(sal, 70);
		gross_salary(sal, h, d);
	}
	else
	{
		h = percentage(sal, 30);
		d = percentage(sal, 80);
		gross_salary(sal, h, d);
	}
	scanf_s("%d", &h);
	return 0;
}

