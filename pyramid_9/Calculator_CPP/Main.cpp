#include<iostream>
#include<string.h>
#include<ctype.h>
#define stack_size 50
int mul(int, int);
int divi(int, int);
int add(int, int);
int sub(int, int);
using namespace std;
char *result = NULL;
int Rsize = 0;
struct stack
{
	int  top;
	char *s;
};
class _stack_
{
	struct stack str;
	char *a;
public:
	_stack_()
	{

		str.top = -1;
		str.s = new char[stack_size];
		a = NULL;
	}
	int string_a(int arraysize)
	{
		a = new char[arraysize];
		result = new char[arraysize];
		if (a == NULL || result == NULL)
			return -1;
		else
			cin >> a;
		return 0;
	}
	bool IsFull()
	{
		if (str.top == (stack_size - 1))
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
	int checkstring()
	{
		int i = 0;
		while (a[i] != '\0')
		{
			if (isdigit(a[i]) || a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
				i++;
			else
				return -1;
		}
		return 0;
	}
	int precedence(char ch)
	{
		/*if (ch == '0')
		{

		}*/
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
	int peek_value()
	{
		return str.top;
	}
	void postfix()
	{
		int i = 0;
		
		while (a[i] != '\0')
		{
			if (isdigit(a[i]))
			{
				result[Rsize++] = a[i];
				
			}
			else if (a[i] == '(' || a[i] == '[' || a[i] == '{')
				push(a[i]);
			else
			{
				int d = precedence(a[i]);
				if (d > precedence(peek()))
				{
					push(a[i]);
				}
				else if (d == precedence(peek()))
				{
					result[Rsize++] = pop();
					push(a[i]);
				}
				else
				{

					if (a[i] == ')' || a[i] == ']' || a[i] == '}')
					{
						while (peek() != '(')
						{
							result[Rsize++] = pop();
						}
						pop();
					}
					else
					{
						result[Rsize++] = pop();
						push(a[i]);
					}

				}
			}
			i++;
		}
		while (!IsEmpty())
			result[Rsize++] = pop();
		result[Rsize] = '\0';

		strcpy(a, result);
		cout << a << endl;
	}
	int Evaluation()
	{
		int i = 0;
		while (a[i] != '\0')
		{
			if (isdigit(a[i]))
			{
				
				push(a[i]);
			}
			else
			{
				if (peek_value() == -1)
				{
					cout << "Wrong evaluation\n"; return -1;
				}
				else
				{
					int x = pop() - '0';
					//cout <<"x:"<<x<< endl;
					if (peek_value() == -1)
					{
						cout << "Wrong evaluation\n"; return -1;
					}
					else
					{
						char res;
						int y = pop() - '0';
						//cout <<"y:"<< y << endl;
						switch (a[i])
						{
						case '*': res = mul(x,y)+'0';
							//cout <<"*"<< res << endl;
							push(res);
							break;
						case '+':res = add(x,y) + '0';
							//cout << "+"<<res << endl;
							push(res);
							break;
						case '-': res = sub(x,y)+ '0';
							//cout <<"-"<< res << endl;
							push(res);
							break;
						case '/':res = divi(x,y )+ '0';
							//cout << "/" << res << endl;
							push(res);
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
	int size;
	cout << "Enter the size of inputing data:";
	cin >> size;
	if (size>0)
	{
		cout << "Enter Infix notation:\n";
		int checkvar1 = s1.string_a(size);
		if (checkvar1 == -1)
			cout << "Failed Memory Allocation\n";
		else
		{
			int checkvar2 = s1.checkstring();
			if (checkvar2 == -1)
				cout << "Invalid input format\n";
			else
			{
				s1.postfix();
				int d = s1.Evaluation();
				if (d != -1)
					cout << s1.pop() - '0';
				cout << endl;
			}
		}
	}
	else
		cout << "Invalid Input size\n";
	system("pause");
	return 0;

}