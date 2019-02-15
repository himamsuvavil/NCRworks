#include<iostream>
using namespace std;
class complex
{
	int real, img;
public:
	complex()
	{
		real = img = 0;
		cout << "empty  ";
	}
	complex(int a, int b)
	{
		real = a; img = b;
	}
	complex(int a)
	{
		real = img = a;
	}
	void display()
	{
		cout << "complex number is: " << real << "+i" << img << endl;
	}
	friend complex add(complex &, complex &);
	friend complex mul(complex &, complex &);
};
complex add(complex &a, complex &b)
{
	complex t;
	t.real = a.real + b.real;
	t.img = a.img + b.img;
	return t;
}
complex mul(complex &a, complex &b)
{
	complex t;
	t.real = a.real * b.real;
	t.img = a.img * b.img;
	return t;
}
int main()
{
	complex c1, c2(5), c3(6, 8), c4, c5;
	c4 = add(c2, c3);
	c5 = mul(c2, c3);
	c1.display();
	c2.display();
	c3.display();
	c4.display();
	c5.display();
	int n;
	cin >> n;
	return 0;
}