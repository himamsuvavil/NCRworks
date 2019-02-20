#include<iostream>
#include<string.h>
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
		if (str.top != -1)
			return str.s[str.top];
		else
			return -1;
	}
	int precedence(char ch)
	{
		switch (ch)
		{
		case '*':
		case '/':
			return 3;
			break;
		case '+':
		case '-':
			return 2;
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
		char *t;
		t = new char[strlen(a)];
		int i = strlen(a)-1;
		int k = 0;
		while (i>=0)
		{
			if (isdigit(a[i]) || isalpha(a[i]))
				t[k++] = a[i];
			else if (a[i] == ')'|| a[i] ==']' || a[i] == '}')
				push(a[i]);
			else
			{
				int d = precedence(a[i]);
				if (d > precedence(peek()))
				{
					push(a[i]);
				}
				else
				{

					if (a[i] == '(' || a[i] == '['||a[i] == '{')
					{
						while (peek() != ')')
						{
							t[k++]= pop();
						}
						pop();
					}
					else
					{
						t[k++]= pop();
						push(a[i]);
					}

				}
			}
			i--;
		}
		while (!IsEmpty())
			t[k++]= pop();
		t[k] = '\0';
		cout <<_strrev(t) << endl;
	}
};
int main()
{
	_stack_ s1;
	cout << "Enter Infix notation:\n";
	s1.string_a();
	cout << "Prefix Notation is\n:";
	s1.postfix();
	cout << endl;
	system("pause");

}