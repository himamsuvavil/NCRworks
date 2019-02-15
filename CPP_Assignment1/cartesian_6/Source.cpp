#include<iostream>
#include<math.h>
using namespace std;
class point
{
	int x, y;
	
public:
	void get()
	{
		cout << "Enter points x,y:";
		cin >> x >> y;
	}
	friend float distance(point, point);
};
inline int sqr(int a)
{
	return a*a;
}
float distance(point a, point b)
{
	float res;
	res = sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
	return res;
}
int main()
{
	point p1, p2;
	p1.get();
	p2.get();
	float res = distance(p1, p2);
	cout << "Distance of 2 points is:" << res;
	system("pause");

}