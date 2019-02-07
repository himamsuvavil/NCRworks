#include<stdio.h>
int main()
{
	int val = 0xCAFE;
	int l,x, r1,res,r;
	res = 0x0000E000;
	l = val >> 4;
	r = val << 12;
	x = val << 28;
	
	r1 = r&x;
	res = l | r;
	printf("%x", x);
	scanf_s("%d", &l);
	return 0;
}