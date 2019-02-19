#include<iostream>
using namespace std;
#define size 50
struct stack
{
	int  top;
	int *s;
};
class _stack_
{
	struct stack str;
	char a[20];
public:
	_stack_()
	{

		str.top = -1;
		str.s = new int[size];
	}
	void Input_a()
	{
		cin >> a;
	}
	bool IsFull()
	{
		if (str.top == (size - 1))
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
	int pop()
	{
		if (IsEmpty())
			cout << "Underflow of stack\n";
		else
		{
			int x = str.s[str.top];
			str.top--;
			return x;
		}
		return -1;
	}
	int peek_value()
	{
		return str.top;
	}
	int Evaluation()
	{
		int i = 0;
		while (a[i] != '\0')
		{
			if (isdigit(a[i]))
			{
				int x = a[i] - '0';
				push(x);
			}
			else
			{
				if (peek_value() == -1)
				{
					cout << "Wrong evaluation\n"; return -1;
				}
				else
				{
					int x = pop();
					if (peek_value() == -1)
					{
						cout << "Wrong evaluation\n"; return -1;
					}
					else
					{
						int y = pop();
						switch (a[i])
						{
						case '*': push(x*y);
							break;
						case '+':push(x + y);
							break;
						case '-': push(y - x);
							break;
						case '/':push(y / x);
							break;
						}
					}
				}
				
			}
			i++;
		}
		return 0;
	}

};
int main()
{
	_stack_ s1;
	cout << "Enter Postfix notation:\n";
	s1.Input_a();
	cout << "After Postfix Notation Evaluation value is:\n";
	int d=s1.Evaluation();
	if(d!=-1)
	cout << s1.pop();
	cout << endl;
	system("pause");
}