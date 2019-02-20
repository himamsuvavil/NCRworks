#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class _list_
{
	struct node *start;
public:
	_list_()
	{
		start = NULL;
	}
	void add(int n)
	{
		struct node *tmp;
		tmp = new node;
		tmp->data = n;
		tmp->next = NULL;
		if (start == NULL)
			start = tmp;
		else
		{
			struct node *t = start;
			while (t->next != NULL)
				t = t->next;
			t->next = tmp;
		}
	}
	void self_adjusting(int elem)
	{
		if (start == NULL)
			cout << "Empty list\n";
		else if (start->next == NULL)
			cout << "Only one element in list\n";
		else
		{
			struct node *tmp = start;
			while (tmp->next != NULL&&tmp->next->data != elem)
				tmp = tmp->next;
			if (tmp->next != NULL)
			{
				struct node *d = tmp->next;
				tmp->next = d->next;
				d->next = start;
				start = d;
			}
			else
				cout << "No such element in list:";
		}
	}
		void display()
		{
			if (start == NULL)
				cout << "under flow\n";
			else
			{
				struct node *t = start;
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
		_list_ l1;
		int n, ch;
		while (1)
		{
			cout << "Enter choice:\n1.Add\n2.Delete\n3.Display\n4.exit\n";
			cin >> ch;
			switch (ch)
			{
			case 1:cout << "Enter element to be inserted:\n";
				cin >> n;
				l1.add(n); break;
			case 2:cout << "Enter element to be adjusted\n";
				int elem; cin >> elem;
				l1.self_adjusting(elem);
				break;
			case 3:l1.display();
				break;
			case 4:
			default:exit(0);
				break;
			}
		}
		return 0;
	}