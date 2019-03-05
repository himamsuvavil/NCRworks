#include<iostream>
#include<Windows.h>
using namespace std;
CRITICAL_SECTION Object;
long GlobalValue;
DWORD WINAPI ThreadFunction1(LPVOID lparam)
{
	EnterCriticalSection(&Object);

	GlobalValue++;

	LeaveCriticalSection(&Object);
	return 0;
}
DWORD WINAPI ThreadFunction2(LPVOID lparam)
{
	EnterCriticalSection(&Object);

	GlobalValue++;

	LeaveCriticalSection(&Object);
	return 0;
}
int main()
{
	DWORD Thread1, Thread2;
	HANDLE ThreadHandle1, ThreadHandle2;

	InitializeCriticalSection(&Object);

	while (1)
	{
		GlobalValue = 0;
		/*---------------------Thread creation------------------------*/
		ThreadHandle1 = CreateThread(NULL, 0, ThreadFunction1, NULL, 0, &Thread1);
		if (ThreadHandle1 == NULL)
			cout << "Failed to create Thread1\n";
		ThreadHandle2 = CreateThread(NULL, 0, ThreadFunction2, NULL, 0, &Thread2);

		/*-------------------Witing for termination of signle object-------------*/
		WaitForSingleObject(ThreadHandle1, 1000);	//Waits until Thread1 is in signaled state(Thread1 will not wait for execution)
		WaitForSingleObject(ThreadHandle2, 2000);	//Waits until Thread2 is in signaled state(Thread2 will not wait for execution)


		if (ThreadHandle2 == NULL)
			cout << "Failed to create Thread2\n";

		if (GlobalValue != 2)
			cout << "Inconsistent\n";
		else
			cout << "Global Value is: " << GlobalValue << endl;

		/*---------------------------------Closing the Thread Handles-----------------------------------*/
		CloseHandle(ThreadHandle1);
		CloseHandle(ThreadHandle2);
	}
	DeleteCriticalSection(&Object);
	getchar();
	return 0;
}