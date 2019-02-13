#include<stdio.h>
struct s
{
	int a; char s;
};
union u
{
	int a; char s;
};
int main()
{
	struct s s1;
	union u u1;
	printf("Sizeof the structure is %d\nSize of the Union is %d\n", sizeof(s1), sizeof(u1));
	gets();
	return 0;
}