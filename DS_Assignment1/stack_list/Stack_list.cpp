#include<iostream>
using namespace std;
struct stack
{
	int data;
	struct stack *next;
};
class stack_list
{
	struct stack *top;
public:
	stack_list()
	{
		top = NULL;
	}
	void push(int elem)
	{
		struct stack *tmp;
		tmp = new stack;
		tmp->data=elem;
		tmp->next = NULL;
		if (top == NULL)
			top = tmp;
		else
		{
			struct stack *t = top;
			while (t->next != NULL)
				t = t->next;
			t->next = tmp;
		}
	}
	int pop()
	{
		int x = -1;
		if (top == NULL)
			return x;
		else if (top->next == NULL)
		{
			x = top->data;
			struct stack *t = top;
			top = NULL;
			delete t;
		}
		else
		{
			struct stack *t = top;
			while (t->next->next != NULL)
				t = t->next;
			struct stack *tmp = t->next;
			x = t->next->data;
			t->next = NULL;
			delete 	tmp;
		}
		return x;
	}
	void display()
	{
		if (top == NULL)
			cout << "under flow\n";
		else
		{
			struct stack *t = top;
			while (t != NULL)
			{
				cout << t->data << " ";
				t = t->next;
			}
			cout << endl;
		}
	}
};
int main()
{
	stack_list s1;
	int ch, n;
	while (1)
	{
		cout << "Enter choice:\n";
		cout << "1.Push\n2.Pop\n3.Display\n4.Exit\n";
		int ch, x, n;
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter element to be pushed:\n";
			cin >> n;
			s1.push(n); break;
		case 2:x = s1.pop();
			if (x != -1)
				cout << "popped element is " << x << endl;
			break;
		case 3:s1.display();
			break;
		case4:
		default:exit(0);
			break;
		}
	}
	return 0;
}