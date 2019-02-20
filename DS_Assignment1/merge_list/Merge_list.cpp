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
	_list_ merge(_list_ l1, _list_ l2)
	{
		while (l1.start != NULL&&l2.start != NULL)
		{
			struct node *tmp;
			tmp = new node;
			tmp->next = NULL;
			if (l1.start->data>l2.start->data)
			{
				tmp->data = l2.start->data;
				if (start == NULL)
					start = tmp;
				else
				{
					struct node *t = start;
					while (t->next != NULL)
						t = t->next;
					t->next = tmp;
				}
				l2.start = l2.start->next;
			}
			else
			{
				tmp->data = l1.start->data;
				if (start == NULL)
					start = tmp;
				else
				{
					struct node *t = start;
					while (t->next != NULL)
						t = t->next;
					t->next = tmp;
				}
				l1.start = l1.start->next;
			}
		}
		while (l2.start != NULL)
		{
			struct node *tmp;
			tmp = new node;
			tmp->next = NULL;
			tmp->data = l2.start->data;
			struct node *t = start;
			while (t->next != NULL)
				t = t->next;
			t->next = tmp;
			l2.start = l2.start->next;
		}
		while (l1.start != NULL)
		{
			struct node *tmp;
			tmp = new node;
			tmp->next = NULL;
			tmp->data = l1.start->data;
			struct node *t = start;
			while (t->next != NULL)
				t = t->next;
			t->next = tmp;
			l1.start = l1.start->next;
		}
		return *this;
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
	_list_ l1, l2, l3;
	int n1, n2, elem;
	cout << "Enter size of the 2 lists:";
	cin >> n1 >> n2;
	cout << "Enter elements for list1:";
	for (int i = 0; i<n1; i++)
	{
		cin >> elem;
		l1.add(elem);
	}
	cout << "Enter elements for list2:";
	for (int i = 0; i<n2; i++)
	{
		cin >> elem;
		l2.add(elem);
	}
	l3.merge(l1, l2);
	cout << "merged list is:\n";
	l3.display();
	system("pause");
	return 0;
}