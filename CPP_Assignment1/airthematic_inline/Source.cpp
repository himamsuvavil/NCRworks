#include<iostream>
using namespace std;
class operation
{
	int x,y; int res;
public:
	operation()
	{
		x = y = res = 0;
	}
	operation(int a,int b)
	{
		x = a; y = b; res = 0;
		
	}
	inline void sub();
	friend inline operation mul(operation);
	inline void add()
	{
		res = x + y;
	}
	inline void div()
	{
		res = (x / y);
	}
	void display()
	{
		cout << "result is:" << res << endl;
	}
};
void operation :: sub()
{
	res = x - y;
}
operation mul(operation o)
{
	operation a;
	a.res = o.x*o.y; 
	return a;
}
int main()
{
	operation obj1(5, 6),obj2;
	obj1.add();
	obj1.display();
	obj1.sub();
	obj1.display();
	obj2=mul(obj1);
	obj2.display();
	obj1.div();
	obj1.display();
	int n;
	cin >> n;
	return 0;
}