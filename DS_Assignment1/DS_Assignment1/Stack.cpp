#include<iostream>
using namespace std;
struct stack
{
	int size, top;
	int *s;
};
class _stack_
{
	struct stack str;
public:
	_stack_()
	{
		str.size = 0;
		str.top = -1;
		str.s = NULL;
	}
	void size(int n)
	{
		str.size = n;
		str.s = new int[n];
	}
	bool IsFull()
	{
		if (str.top == (str.size - 1))
			return true;
		return false;
	}
	bool IsEmpty()
	{
		if (str.top == -1)
			return true;
		return false;
	}
	void push(int elem)
	{
		if (IsFull())
			cout << "Overflow of stack\n";
		else
			str.s[++str.top] = elem;
	}
	void pop()
	{
		if (IsEmpty())
			cout << "Underflow of stack\n";
		else
		{
			cout << str.s[str.top] << " is delted from stack\n";
			str.top--;
		}
	}
	void display()
	{
		for (int i = 0; i <= str.top; i++)
			cout << str.s[i] << " ";
		cout << endl;
	}
	void peek()
	{
		cout << "Element at the top the stack is " << str.s[str.top]<<endl;
	}
};
int main()
{
	_stack_ s1;
	cout << "Enter the size:";
	int n;
	cin >> n;
	s1.size(n);
	while (1)
	{
		cout << "Enter your choice:\n";
		cout << "1.Push\n2.pop\n3.display\n4.peek\n5.exit\n";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1: int elem;
			cout << "Enter element to be pushed\n";
			cin >> elem;
			s1.push(elem);
			break;
		case 2: s1.pop();
			break;
		case 3:s1.display();
			break;
		case 4:s1.peek();
			break;
		case 5:
		default :exit(0);
		}
	}
}