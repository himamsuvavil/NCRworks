#include<iostream>
using namespace std;
void swap_reference(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
	cout << "after swapping:" << a << " " << b;
}
void swap_value(int a, int b)
{
	int t = a;
	a = b;
	b = t;
	cout << "after swapping:" << a << " " << b;
}

int main()
{
	int a,b;
	cout << "Enter a,b:";
	cin >> a >> b;
	cout << "Swap numbers by:" << endl << "1.call by reference\n2.call by value\n";
	int n;
	cin >> n;
	
	switch (n)
	{
	case 1:swap_reference(a, b);
		break;
	case 2:swap_value(a, b);
		break;
	default:cout << "Invalid choice\n";
	}
	
	system("pause");
	return 0;
}
