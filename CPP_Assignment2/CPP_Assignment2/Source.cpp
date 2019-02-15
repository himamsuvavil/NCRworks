#include<iostream>
using namespace std;
class polar
{
	static int x;
	
public:
	
	polar()
	{
		x++;
	}
	polar(int a)
	{
		x++;

	}
	polar(const polar &a)
	{
		x++;
	}
	~polar()
	{
		x--;
	}
	void display()
	{
		cout << "Active objects are:" << x << endl;
	}
};
int polar :: x = 0;
int main()
{
	polar p1, p2(3), p3(p1), p4(p2);
	p4.display();
	system("pause");
	return 0;
}