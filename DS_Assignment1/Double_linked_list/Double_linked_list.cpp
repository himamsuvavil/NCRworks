#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next, *prev;
};
class circular_list
{
	struct node *start;
public:
	circular_list()
	{
		start = NULL;
	}
	void Insert_first(int elem)
	{
		struct node *tmp;
		tmp = new node;
		tmp->data = elem;
		tmp->prev = NULL;
		if (start == NULL)
		{
			tmp->next = NULL;
			start = tmp;
		}
		else
		{
			tmp->next = start;
			start->prev = tmp;
			start = tmp;
		}
	}
	void Insert_end(int elem)
	{
		struct node *tmp;
		tmp = new node;
		tmp->data = elem;
		tmp->next = NULL;
		if (start == NULL)
		{
			start = tmp;
			tmp->prev = NULL;
		}
		else
		{
			struct node *t = start;
			while (t->next != NULL)
				t = t->next;
			t->next = tmp; tmp->prev = t;
		}
	}
	void Insert_after(int elem, int pos)
	{

		if (start == NULL)
			cout << "Empty list\n\n";
		else
		{
			struct node *t = start;
			while (t != NULL&&t->data != pos)
				t = t->next;
			if (t != NULL)
			{
				struct node *tmp;
				tmp = new node;
				tmp->data = elem;
				tmp->next = t->next;
				tmp->prev = t;
				if (t->next != NULL)
					t->next->prev = tmp;
				t->next = tmp;
			}
			else
				cout << "No such element in list\n\n";
		}

	}
	void Insert_before(int elem, int pos)
	{

		if (start == NULL)
			cout << "Empty list\n\n";
		else
		{

			if (start->data == pos)
			{
				struct node *tmp;
				tmp = new node;
				tmp->data = elem;
				tmp->prev = NULL;
				tmp->next = start;
				start->prev = tmp;
				start = tmp;
			}
			else
			{
				struct node *t = start;
				while (t->next != NULL&&t->next->data != pos)
					t = t->next;
				if (t->next != NULL)
				{
					struct node *tmp;
					tmp = new node;
					tmp->data = elem;
					tmp->next = t->next;
					tmp->prev = t->next->prev;
					t->next->prev = tmp;
					t->next = tmp;
				}
				else
					cout << "No such element\n\n";
			}
		}

	}
	int delete_first()
	{
		int x = -1;
		if (start == NULL)
			cout << "Empty list\n\n";
		else
		{
			struct node *t;
			t = start;
			if(start->next!=NULL)
				start->next->prev = NULL;
			start = t->next;
			x = t->data;
			delete t;
		}
		return x;
	}
	int delete_end()
	{
		int x = -1;
		if (start == NULL)
			cout << "Empty list\n\n";
		else if (start->next == NULL)
		{
			struct node *t = start;
			x = t->data;
			start = NULL;
			delete t;
		}
		else
		{
			struct node *t;
			t = start;
			while (t->next->next != NULL)
				t = t->next;
			x = t->next->data;
			delete t->next;
			t->next = NULL;
		}
		return x;
	}
	int delete_elem(int elem)
	{
		int x = -1;
		if (start == NULL)
			cout << "Empty stack\n\n";
		else if (start->data == elem)
		{
			struct node *t = start;
			x = t->data;
			start = t->next;
			delete t;
		}
		else
		{
			struct node *t = start;
			while (t->next != NULL&&t->next->data != elem)
				t = t->next;
			if (t->next != NULL)
			{
				struct node *t1 = t->next;
				x = t1->data;
				t->next = t1->next;
				delete t1;
			}
			else
				cout << "No such element exits\n\n";
		}
		return x;
	}
	void T_forward()
	{
		struct node *tmp = start;
		while (tmp != NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl << endl;
	}
	void T_backward()
	{
		struct node *tmp = start;
		while (tmp ->next!= NULL)
			tmp = tmp->next;
		
		while (tmp != NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->prev;
		}
		cout << endl << endl;
	}


};
int main()
{
	circular_list s1;
	while (1)
	{
		cout << "Enter choice:\n";
		cout << "1.Add at beginning\n2.Add at end\n3.Add after an element\n4.Add before an element\n5.Delete at beginning\n";
		cout << "6.Delete at end\n7.Delete an element\n8.Traverse forward\n9.Traverse backward\n10.Exit\n";
		int ch,x;
		cin >> ch;
		switch (ch)
		{
		case 1:int n;
			cout << "Enter a number: ";
			cin >> n;
			s1.Insert_first(n);
			break;
		case 2: cout << "Enter a number:";
			cin >> n;
			s1.Insert_end(n);
			break;
		case 3:cout << "Enter a number: ";
			cin >> n;
			cout << "Enter the element after which it should be inserted: ";
			int pos; cin >> pos;
			s1.Insert_after(n, pos);
			break;
		case 4:cout << "Enter a number: ";
			cin >> n;
			cout << "Enter the element before which it should be inserted: ";
			cin >> pos;
			s1.Insert_before(n, pos);
			break;
			case 5:x = s1.delete_first();
			if (x != -1)
			cout << "Deleted element is " << x << endl << endl;
			break;
			case 6:x = s1.delete_end();
			if (x != -1)
			cout << "Deleted element is " << x << endl << endl;
			break;
			case 7:cout << "Enter the element which is to be deleted: ";
			cin >> pos;
			x = s1.delete_elem(pos);
			if (x != -1)
			cout << "Deleted element is " << x << endl << endl;
			break;
		case 8:s1.T_forward();
			break;
			case 9:s1.T_backward();
			break;
		case 10:
		default: exit(0); break;
		}
	}
}
