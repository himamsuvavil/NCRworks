#include<iostream>
using namespace std;
#define size 50
struct stack
{
	int  top;
	char *s;
};
class _stack_
{
	struct stack str;
	char a[20];
public:
	_stack_()
	{

		str.top = -1;
		str.s = new char[size];
	}
	void string_a()
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
	void push(char elem)
	{
		if (IsFull())
			cout << "Overflow of stack\n";
		else
			str.s[++str.top] = elem;
	}
	char pop()
	{
		if (IsEmpty())
			cout << "Underflow of stack\n";
		else
		{
			char x = str.s[str.top];
			str.top--;
			return x;
		}
		return 0;
	}
	char peek()
	{
		return str.s[str.top];
	}
	int precedence(char ch)
	{
		switch (ch)
		{
		case '*':
		case '/':
			return 6;
			break;
		case '+':
		case '-':
			return 5;
			break;
		case '(':
		case '[':
		case '{':
			return 1;
			break;
		case ')':
		case ']':
		case '}':
			return 0;
			break;
		}
		return -1;
	}
	void postfix()
	{
		int i = 0;
		while (a[i] != '\0')
		{
			if (isdigit(a[i]) || isalpha(a[i]))
				cout << a[i];
			else
			{
				int d = precedence(a[i]);
				if (d > precedence(peek()))
				{
					push(a[i]);
				}
				else
				{
					
					if (a[i]== ')' || a[i] == ']' || a[i] == '}')
					{
						while (peek() != '(')
						{
							cout << pop();
						}
						pop();
					}
					else
					{
						cout << pop();
						push(a[i]);
					}
					
				}
			}
			i++;
		}
		while (!IsEmpty())
			cout<<pop();
	}
};
int main()
{
	_stack_ s1;
	cout << "Enter Infix notation:\n";
	s1.string_a();
	cout << "Postfix Notation is:\n";
	s1.postfix();
	cout << endl;
	system("pause");

}