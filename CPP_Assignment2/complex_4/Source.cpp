#include<iostream>
using namespace std;
class complex
{
	int real, img;
public:
	complex()
	{
		img = real = 0;
	}
	complex(int a, int b)
	{
		real = a;
		img = b;
	}
	complex(const complex &a)
	{
		real = a.real;
		img = a.img;
	}
	~complex()
	{
		//cout << "Destructor"<<endl;
	}
	void display()
	{
		cout << "It is class member function"<<endl;
	
	}
	complex operator+(complex a)
	{
		complex t;
		t.real = real + a.real;
		t.img = img + a.img;
		return t;
	}
	complex operator-(complex);
	complex operator++()
	{
		++real; ++img;
		return *this;
	}
	complex operator++(int);
	complex* operator->()
	{
		return this;
	}
	complex operator,(complex c)
	{
		return c;
	}
	friend istream& operator >> (istream&cin, complex&);
	friend ostream& operator<<(ostream&cout, complex);
};
istream& operator >> (istream&cin, complex &c)
{
	cout << "Enter real value:";
	cin >> c.real;
	cout << "Enter imaginary value:";
	cin >> c.img;
	return cin;
}
ostream& operator<<(ostream&cout, complex c)
{
	cout << "Complex number is: " << c.real << "+ i" << c.img << endl;
	return cout;
}

complex complex:: operator-(complex a)
{
	complex t;
	t.real = real - a.real;
	t.img = img - a.img;
	return t;
}
complex complex ::operator++(int a)
{
	complex t;
	t.real = real++;
	t.img = img++;
	return t;
}
int main()
{
	complex c1, c2(2, 3), c3(c2), c4, c5;
	cin >> c1;
	cout << "Given complex numbera are(c1,c2):";
	cout << c1;
	cout << c2;
	cout << "Adding two complex number(c3):";
	c3 = c1 + c2;
	cout << c3;
	cout << "Subtraction of two complex numbers(c4):";
	c4 = c1 - c2;
	cout << c4;
	cout << "Prefix operation on c1:";
	c5 = ++c1;
	cout << c5;
	cout << "Postfix operation on c2:";
	c5 = c2++;
	cout << c5;
	cout << "Assignmnet value of c3:";
	c5 = c3;
	cout << c5;
	
	cout << "Performing ->operation:";
	c2->display();
	cout << "Performing comma operation";
	c1 = c2, c3;
	cout << "c1=c2,c3: values respectively are:";
	cout << c1;
	cout << c2;
	cout << c3;
	system("pause");
	return 0;

}