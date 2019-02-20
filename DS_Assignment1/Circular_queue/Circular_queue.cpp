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
		q.front = q.rear = -1;
	}
	void equeue(int elem)
	{
		if (q.rear == -1 || q.front == -1)
		{
			q.rear++; q.front++;
			q.qtr[q.rear] = elem;
		}
		else if (q.front == ((q.rear + 1) % size))
			cout << "overflow\n";
		else
		{
			q.rear = (q.rear + 1) % size;
			q.qtr[q.rear] = elem;
		}
	}
	void dequeue()
	{
		if (q.rear == -1 && q.front == -1)
			cout << "Underflow\n";
		else if (q.rear == q.front)
			q.rear = q.front = -1;
		else
			q.front = (q.front + 1) % size;
	}
	void display()
	{
		int i;
		for ( i = q.front; i != q.rear; i = (i + 1) % size)
			cout << q.qtr[i] << " ";
		cout << q.qtr[i];
		cout << endl;
	}
};
int main()
{
	_queue_ q1;
	while (1)
	{
		cout << "Enter choice\n";
		cout << "1.Add\n2.Delete\n3.Display\n4.exit\n";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1:int elem;
			cout << "enter element:\n";
			cin >> elem;
			q1.equeue(elem);
			break;
		case 2: q1.dequeue();
			break;
		case 3:cout << "Elements in queue are:\n";
			q1.display();
			break;
		case 4:
		default:
			exit(0);
			break;
		}
	}
}
