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
	void pop()
	{
		if (IsEmpty())
			cout << "Underflow of stack\n"; 
		else
			str.top--;
	}
	void display()
	{
		for (int i = 0; i <= str.top; i++)
			cout << str.s[i] << " ";
		cout << endl;
	}
	int peek()
	{
		if(!IsEmpty())
			return str.s[str.top];
		return -1;
	}
	void balancing()
	{
		int i = 0;
		while (a[i] != '\0')
		{
			char ch = a[i];
			switch (ch)
			{
			case '(':
			case '{':
			case '[':
				
				push(ch);
				break;
			case ')':
				if (peek() == '(')
					pop();
				break;
			case '}':
				if (peek() == '{')
					pop();
				break;
			case ']':
				if (peek() == '[')
					pop();
				break;
			default: break;
			}
			i++;
		}
		if (IsEmpty())
			cout << "Perfectly Blanced\n";
		else
			cout << "Not Blanced\n";
	}
};
int main()
{
	_stack_ s1;
	cout << "Enter string for balancing\n";
	s1.string_a();
	s1.balancing();
	system("pause");
}