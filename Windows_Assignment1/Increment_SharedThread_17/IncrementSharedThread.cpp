#include<iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std;
long global_value ;			//Global Value that si to be shared by threads
DWORD WINAPI ThreadFunction1(LPVOID lparam)
{
	global_value++;
	return 0;	
}
DWORD WINAPI ThreadFunction2(LPVOID lparam)
{
	global_value++;
	
	return 0;
}
int _tmain()
{
	DWORD Thread1, Thread2;			//Variables for Threads
	HANDLE ThreadHandle1, ThreadHandle2;		//Handle variables to hold Thread Handles

	
	while (1)
	{

		/*---------------------Thread creation------------------*/
		global_value = 0;
		ThreadHandle1 = CreateThread(NULL, 0, ThreadFunction1, NULL, 0, &Thread1);			//Thread1 is created and handle returned is stored in ThreadHandle1
		if (ThreadHandle1 == NULL)			//Test for failure condition of Thread creation
			cout << "Falied to create thread1";

		ThreadHandle2 = CreateThread(NULL, 0, ThreadFunction2, NULL, 0, &Thread2);			//Thread2 is created and handle returned is stored in ThreadHandle2
		if (ThreadHandle2 == NULL)			//Test for failure condition of Thread creation
			cout << "Falied to create thread2";

		/*-------------------Witing for termination of signle object-------------*/
		WaitForSingleObject(ThreadHandle1, 1000);	//Waits until Thread1 is in signaled state(Thread1 will not wait for execution)
		WaitForSingleObject(ThreadHandle2, 2000);	//Waits until Thread2 is in signaled state(Thread2 will not wait for execution)

		if (global_value == 1)		
		{
			cout << "Inconsistent value \n";
			break;
		}
		else
		{
			cout << "Global Value is : " << global_value << endl;
			
		}

		/*---------------------------------Closing the Thread Handles-----------------------------------*/
		CloseHandle(ThreadHandle1);
		CloseHandle(ThreadHandle2);
	}

	

	getchar();
	return 0;
}