#include<iostream>
using namespace std;
struct doubleLinkedList
{
	int data;
	struct doubleLinkedList *next;
	struct doubleLinkedList *prev;
};
class dQueue
{
protected:
	struct doubleLinkedList *rear, *front;
public:
	dQueue()
	{
		rear = front = NULL;
	}
	int insertRear(int elem)
	{
		struct doubleLinkedList *insertdata = NULL;
		insertdata = new doubleLinkedList;
		insertdata->data = elem;
		insertdata->next = insertdata->prev = NULL;
		if (insertdata == NULL)
		{
			cout << "Failed memory allocation\n";
			return -1;
		}
		if (rear == NULL&&front==NULL)
		{
			rear = front = insertdata;
			return 0;
		}
		else
		{
			insertdata->prev = rear;
			rear->next = insertdata;
			rear = insertdata;
			return 0;
		}
		return -1;
	}
	int insertFront(int elem)
	{

		struct doubleLinkedList *insertdata = NULL;
		insertdata = new doubleLinkedList;
		insertdata->data = elem;
		insertdata->next = insertdata->prev = NULL;
		if (insertdata == NULL)
		{
			cout << "Failed memory allocation\n";
			return -1;
		}
		if (rear == NULL&&front == NULL)
		{
			rear = front = insertdata;
			return 0;
		}
		else
		{
			insertdata->next = front;
			front->prev = insertdata;
			front = insertdata;
			return 0;
		}
		return -1;
	}
	int deleteRear()
	{
		int deleted = -1;
		if (rear == NULL&&front == NULL)
		{
			cout << "No data available\n";
			return -1;
		}
		struct doubleLinkedList *deleteNode = rear;
		deleted = rear->data;
		if(front==rear)
		{
			
			front = rear = NULL;
			//free deleteNode;
		}
		else
		{
			rear->prev->next = NULL;
			rear = rear->prev;
			deleteNode->prev = NULL;
		}
		return deleted;
	}
	int deleteFront()
	{
		int deleted = -1;
		if (rear == NULL&&front == NULL)
		{
			cout << "No data available\n";
			return -1;
		}
		struct doubleLinkedList *deleteNode = front;
		deleted = front->data;
		if (front == rear)
		{

			front = rear = NULL;
			//free deleteNode;
		}
		else
		{
			front->next->prev = NULL;
			front = front->prev;
			deleteNode->next = NULL;
		}
		return deleted;
	}
	~dQueue()
	{
		
	}
};
class Stack :public dQueue
{
	struct doubleLinkedList *top;
public:
	Stack()
	{
		top = NULL;
	}
};
