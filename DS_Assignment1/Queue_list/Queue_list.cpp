#include<iostream>
using namespace std;
struct queue
{
	int data;
	struct queue *next;
};
class queue_list
{
	struct queue *start;
public:
	queue_list()
	{
		start = NULL;
	}
	void equeue(int elem)
	{
		struct queue *tmp;
		tmp = new queue;
		tmp->data = elem;
		tmp->next = NULL;
		if (start == NULL)
			start = tmp;
		else
		{
			struct queue *t = start;
			while (t->next != NULL)
				t = t->next;
			t->next = tmp;
		}
	}
	int dequeue()
	{
		int x = -1;
		if (start == NULL)
			return x;
		else if (start->next == NULL)
		{
			struct queue *t = start;
			x = t->data;
			start = NULL;
			delete t;
		}
		else
		{
			struct queue *t = start;
			x = t->data;
			start = t->next;
			delete t;
		}
		return x;
	}
	void display()
	{
		struct queue *tmp = start;
		while (tmp != NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

};
int main()
{
	queue_list s1;
	int ch, n,x;
	while (1)
	{
		cout << "Enter choice:\n";
		cout << "1.Add\n2.Delete\n3.Display\n4.Exit\n";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter element to be pushed:\n";
			cin >> n;
			s1.equeue(n); break;
		case 2: x = s1.dequeue();
			if (x != -1)
				cout << "popped element is " << x << endl;
			break;
		case 3:s1.display();
			break;
		case 4:
		default:exit(0);
			break;
		}
	}
	return 0;
}