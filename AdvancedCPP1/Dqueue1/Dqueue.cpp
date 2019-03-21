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
	/*-----Add at the back end------*/
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
	/*-------Add at the beginning---------*/
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
	/*-------Delete at the back end----------*/
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
			
		}
		else
		{
			rear->prev->next = NULL;
			rear = rear->prev;
			deleteNode->prev = NULL;
		}
		delete deleteNode;
		return deleted;
	}
	/*---------Delete at the beginning-------*/
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
			
		}
		else
		{
			front->next->prev = NULL;
			front = front->prev;
			deleteNode->next = NULL;
		}
		delete deleteNode;
		return deleted;
	}
	~dQueue()
	{
		
	}
};

/*--------Add at rear end & delete at rear end------------*/

class stack :public dQueue
{
	
public:
	stack()
	{}
	/*------Displays from first element added to stack to top element-------*/
	int displayStack()
	{
		struct doubleLinkedList *currentNode = front;
		if (rear == NULL&&front == NULL)
		{
			cout << "Empty Stack\n";
			return -1;
		}
		while (currentNode != NULL)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << endl;
		return 0;
	}
};

/*----------Adds at front end and deletes at rear end------------*/

class queue :public dQueue
{
public:
	queue()
	{

	}
	/*--------Displays from front end to rear end-------*/
	int displayQueue()
	{
		struct doubleLinkedList *currentNode = front;
		if (rear == NULL&&front == NULL)
		{
			cout << "Empty Queue\n";
			return -1;
		}
		while (currentNode != rear)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << currentNode->data << endl;
		return 0;
	}
};
int main()
{
	stack stackObj;
	int stackChoice;
	int insertElement, deletedElement;
	int checkInsert, checkDisplay;
	cout << "*-----Performing operations on Stack-----*\n\n";
	do {
		cout << "Enter your choice:";
		cout << "1.Push\t2.Pop\t3.Display\t4.Exit\n";
		cin >> stackChoice;
		switch (stackChoice)
		{
		case 1:cout << "Enter element to be pushed into stack\n";
			cin >> insertElement;
			checkInsert = stackObj.insertFront(insertElement);
			if (checkInsert == -1)
				cout << "\nFailed to insert\n\n";
			else
				cout << "\nInserted Successfully\n\n";
			break;
		case 2:deletedElement = stackObj.deleteRear();
			if (deletedElement == -1)
				cout << "\nFailed to delete from Stack\n\n";
			else
				cout << "\nDelted element from Stack is " << deletedElement << endl << endl;
			break;
		case 3:cout << "\nStack Element are displayed from (bottom to top) are :" <<endl;
			checkDisplay = stackObj.displayStack();
			if (checkDisplay == -1)
				cout << "\nFailed to display elements of Stack\n\n";		
			break;
		case 4:
		default:
			break;
		}
	} while (stackChoice == 1 || stackChoice == 2 || stackChoice == 3);

	queue queueObj;
	int queueChoice;
	cout << "*-----Performing operations on Queue-----*\n\n";
	do {
		cout << "Enter your choice:";
		cout << "1.Add element\t2.Delete element\t3.Display\t4.Exit\n";
		cin >> queueChoice;
		switch (queueChoice)
		{
		case 1:cout << "Enter element to be pushed into stack\n";
			cin >> insertElement;
			checkInsert =queueObj.insertRear(insertElement);
			if (checkInsert == -1)
				cout << "\nFailed to insert\n\n";
			else
				cout << "\nInserted Successfully\n\n";
			break;
		case 2:deletedElement = queueObj.deleteRear();
			if (deletedElement == -1)
				cout << "\nFailed to delete from Stack\n\n";
			else
				cout << "\nDelted element from Stack is " << deletedElement << endl << endl;
			break;
		case 3:cout << "\nStack Element are displayed from (bottom to top) are :" << endl;
			checkDisplay=queueObj.displayQueue();
			if (checkDisplay == -1)
				cout << "\nFailed to display elements of Stack\n\n";				
			break;
		case 4:
		default:
			break;
		}
	} while (queueChoice == 1 || queueChoice == 2 || queueChoice == 3);

	return 0;
}
