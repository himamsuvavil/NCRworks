#include<iostream>
using namespace std;
#define size 10
struct queue
{
	int *qtr;
	int front, rear;
};
class _queue_
{
	struct queue q;
public:
	_queue_()
	{
		q.qtr = new int[size];
		q.front =q. rear = -1;
	}
	void equeue(int n)
	{
		if (q.front == -1 && q.rear == -1)
		{
			q.front++;
			q.rear++;
			q.qtr[q.front] = n;
		}
		else if (q.rear == (size - 1))
			cout << "Overflow\n";
		else
		
			q.qtr[++q.rear] = n;
		
	}
	int dqueue()
	{
		int x = -1;
		if (q.rear ==-1&& q.front== - 1)
			cout << "Underflow\n";
		else if (q.rear == q.front)
		{
			x = q.qtr[q.front];
			q.front = q.rear = -1;
		}
		else
		{
			x = q.qtr[q.front];
			q.front++;
		}
		return x;
	}
	void display()
	{
		for (int i = q.front; i <= q.rear; i++)
			cout << q.qtr[i] << " ";
		cout << endl;
	}
};
int main()
{
	_queue_ q1;
	while (1)
	{
		cout << "Enter your choice:\n";
		cout << "1.Equeue\n2.Dqueue\n3.Display\n4.Exit\n";
		int ch, x; cin >> ch;
		switch (ch)
		{
		case 1: cout << "Enter number to be given to queue:\n";
			int n;
			cin >> n;
			q1.equeue(n);
			break;
		case 2: 
			x = q1.dqueue();
			if (x != -1)
				cout << "Deleted element is " << x << endl;
			break;
		case 3: cout << "Elements in queue are:\n";
			q1.display();
			break;
		case 4:
		default:
			exit(0);
			break;
		}
	}
}