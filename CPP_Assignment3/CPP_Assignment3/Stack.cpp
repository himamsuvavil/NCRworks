#include<iostream>
using namespace std;
template <class T>
class stack
{
	T *s;
	int size, top;
public:
	stack(int n)
	{
		size = n;
		s = new T[n];
		top = -1;
	}
	
	void push(T elem)
	{
		if (top == size - 1)
			cout << "overflow\n";
		else
			s[++top] = elem;
	}
	void pop()
	{
		if (top == -1)
			cout << "Underflow\n";
		else
		{
			cout << s[top] << " is popped\n";
			top--;
		}
	}
	void display()
	{
		for (int i = 0; i <=top;i++)
			cout << s[i] << " ";
		cout << endl;
	}

};
int main()
{
	stack <int>s1(10);
	stack <float>s2(7);
	cout << "Stack operations on integers:\n";
	int ch;
	do
	{
		cout << "Enter your choice:\n";
		cout << "1.Push\n2.pop\n3.display\n4.exit\n";
		
		cin >> ch;
		switch (ch)
		{
		case 1: int  elem;
			cout << "Enter element to be pushed\n";
			cin >> elem;
			s1.push(elem);
			break;
		case 2: s1.pop();
			break;
		case 3:s1.display();
			break;
		case 4:
		default:break;
		}
	} while (ch != 4);
	cout << "Stack operations on float values\n";
	while (1)
	{
		cout << "Enter your choice:\n";
		cout << "1.Push\n2.pop\n3.display\n4.exit\n";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1: float elem;
			cout << "Enter element to be pushed\n";
			cin >> elem;
			s2.push(elem);
			break;
		case 2: s2.pop();
			break;
		case 3:s2.display();
			break;
		case 4:
		default:exit(0);
		}
	}
	
}