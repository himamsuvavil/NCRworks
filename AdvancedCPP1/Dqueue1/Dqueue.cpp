#include<iostream>
using namespace std;

//class userInputException : public exception
//{
//public:
//	const char * what() const throw()
//	{
//		return "Invalid user Input\n";
//	}
//};


/*----------------A structure for double linked list used by dQueue class----------------*/
struct doubleLinkedList
{
	int data;
	struct doubleLinkedList *next;
	struct doubleLinkedList *prev;
};


/*--------------CLASS NAMED dQueue-----------*/
class dQueue
{

protected:
	struct doubleLinkedList *rear, *front;		//pointers that points to front and rear end nodes of list

public:

	/*--------Constructor that initialises rear & front end pointers to NULL indicating list is empty*/
	dQueue()
	{
		rear = front = NULL;			
	}


	/*-----Add at the back end------*/

	/*------->function name: insertRear()
			>parameters: element to be added to list ,it's datatype is int
			>returns: -1 for failed conditions of insertion
					  0 for successfull conditions of insertion
			>Failure Conditions: Failed memory allocation for node to be created
			>Functionality: Adds new node at the end of the list-----------------*/
	int insertRear(int elem)
	{
		struct doubleLinkedList *insertdata = NULL;
		insertdata = new doubleLinkedList;
		insertdata->data = elem;
		insertdata->next = insertdata->prev = NULL;
		if (insertdata == NULL)				//memory allocation failure
		{
			cout << "Failed memory allocation\n";
			return -1;
		}
		if (rear == NULL&&front==NULL)		//list is empty
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

	/*---------->function name: insertFront()
				>parameters: element to be added to list ,it's datatype is int
				>returns: -1 for failed conditions of insertion
						   0 for successfull conditions of insertion
				>Failure Conditions: Failed memory allocation for node to be created
				>Functionality: Adds new node at the beginning of the list-----------------*/

	int insertFront(int elem)
	{

		struct doubleLinkedList *insertdata = NULL;
		insertdata = new doubleLinkedList;
		insertdata->data = elem;
		insertdata->next = insertdata->prev = NULL;
		if (insertdata == NULL)			//memory allocation failure
		{
			cout << "Failed memory allocation\n";
			return -1;
		}
		if (rear == NULL&&front == NULL)		//list is empty
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

	/*---------->function name: deleteRear()
				>parameters: none
				>returns: -1 for failed conditions of deletion
						  deleted element for successfull conditions of deletion
				>Failure Conditions:No data in list
				>Functionality: Deletes a node at the end of the list-----------------*/

	int deleteRear()
	{
		int deleted = -1;
		if (rear == NULL&&front == NULL)		//list is empty
		{
			cout << "\nNo data available\n";
			return -1;
		}
		struct doubleLinkedList *deleteNode = rear;		//holds node which is to be deleted
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
		delete deleteNode;				//free the memory
		return deleted;
	}


	/*---------Delete at the beginning-------*/

	/*---------->function name: deleteFront()
				>parameters: none
				>returns: -1 for failed conditions of deletion
						   deleted element for successfull conditions of deletion
				>Failure Conditions:No data in list
				>Functionality: Deletes a node at the front of the list-----------------*/

	int deleteFront()
	{
		int deleted = -1;
		if (rear == NULL&&front == NULL)				//list is empty
		{
			cout << "\nNo data available\n";
			return -1;
		}
		struct doubleLinkedList *deleteNode = front;	//holds node which is to be deleted
		deleted = front->data;
		if (front == rear)
			front = rear = NULL;
		else
		{
			front = front->next;		//front points to next node
			front->prev = NULL;			//prev value of updated front points to nothing 
			deleteNode->next = NULL;	//
		}
		delete deleteNode;					//free the memory
		return deleted;
	}

	/*--------Destructor that deallocats memory of all nodes--------*/

	~dQueue()
	{
		struct doubleLinkedList *deleteMemoryNode = front;
		while (front != NULL)
		{
			front = front->next;
			delete deleteMemoryNode;
		}
	}
};

/*--------Add at rear end & delete at rear end------------*/

class stack :public dQueue
{
	
public:
	stack()
	{}
	/*------Displays from newly added element to end of list-------*/

	/*---------->function name: displayStack()
				>parameters: none
				>returns: -1 for failed conditions of deletion
						   0 element for successfull conditions of deletion
				>Failure Conditions:No data in list
				>Functionality:Displays data from rear end to front end -----------------*/


	int displayStack()
	{
		struct doubleLinkedList *currentNode = rear;

		if (rear == NULL&&front == NULL)		//Empty list condition
		{
			cout << "\nEmpty Stack\n";
			return -1;
		}
		while (currentNode != NULL)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->prev;
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
	/*--------Displays from front end to rear end-------*/\

	/*---------->function name: displayQueue()
				>parameters: none
				>returns: -1 for failed conditions of deletion
						   0 element for successfull conditions of deletion
				>Failure Conditions:No data in list
				>Functionality:Displays data from rear end to front end -----------------*/

	int displayQueue()
	{
		struct doubleLinkedList *currentNode = front;

		if (rear == NULL&&front == NULL)			//Empty list condition
		{
			cout << "\nEmpty Queue\n";
			return -1;
		}
		while (currentNode != rear)			//until current pointer reaches rear poniter print data and traverse next
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << currentNode->data << endl;		//print data ponited by rear pointer
		return 0;
	}
};


/*----------------MAIN FUNCTION-------------------*/

int main()
{

	/*
	*
			STACK
	*
	*/
	stack stackObj;
	int stackChoice;
	int insertElement, deletedElement;
	int checkInsert, checkDisplay;
	cout << "*-----Performing operations on Stack-----*\n\n";
	do {
		cout << "Enter your choice:\n";
		cout << "1.Push\t2.Pop\t3.Display\t4.Exit\n";
		cin >> stackChoice;

		switch (stackChoice)
		{
		case 1:cout << "Enter element to be pushed into stack\n";
			cin >> insertElement;
			checkInsert = stackObj.insertRear(insertElement);			//Insert at rear end
			if (checkInsert == -1)
				cout << "\nFailed to insert\n\n";
			else
				cout << "\nInserted Successfully\n\n";
			break;
		case 2:deletedElement = stackObj.deleteRear();		//delete at rear end
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


	/*
	*			
				QUEUE
	*
	*/

	queue queueObj;
	int queueChoice;
	cout << "*-----Performing operations on Queue-----*\n\n";
	do {
		cout << "Enter your choice:\n";
		cout << "1.Add element\t2.Delete element\t3.Display\t4.Exit\n";
		cin >> queueChoice;
		switch (queueChoice)
		{
		case 1:cout << "Enter element to be pushed into stack\n";
			cin >> insertElement;
			checkInsert =queueObj.insertRear(insertElement);				//Insert at rear end
			if (checkInsert == -1)
				cout << "\nFailed to insert\n\n";
			else
				cout << "\nInserted Successfully\n\n";
			break;
		case 2:deletedElement = queueObj.deleteFront();						//Deletes from front end
			if (deletedElement == -1)
				cout << "\nFailed to delete from Queue\n\n";
			else
				cout << "\nDelted element from Queue is " << deletedElement << endl << endl;
			break;
		case 3:cout << "\nQueue Element are displayed from (bottom to top) are :" << endl;
			checkDisplay=queueObj.displayQueue();
			if (checkDisplay == -1)
				cout << "\nFailed to display elements of Queue\n\n";				
			break;
		case 4:
		default:
			break;
		}
	} while (queueChoice == 1 || queueChoice == 2 || queueChoice == 3);

	return 0;

}
