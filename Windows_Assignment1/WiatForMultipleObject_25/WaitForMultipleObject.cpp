#include<iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std;
DWORD WINAPI ThreadFunction1(LPVOID lparam)
{
	cout << "Thread1 is created\n";
	Sleep(4000);
	return 0;
}
DWORD WINAPI ThreadFunction2(LPVOID lparam)
{
	cout << "Thread2 is created\n";
	Sleep(3000);
	return 0;
}

int _tmain()
{
	DWORD Thread1, Thread2;
	HANDLE hThread1, hThread2;

	/*-----------------------Threads Creation-------------*/
	hThread1 = CreateThread(NULL, 0, ThreadFunction1, NULL, 0, &Thread1);
	if (hThread1 == NULL)
		cout << "Failed to create Thread1\n";
	hThread2 = CreateThread(NULL, 0, ThreadFunction2, NULL, 0, &Thread2);
	if (hThread2 == NULL)
		cout << "Failed to create Thread2\n";
	HANDLE Res[2];
	Res[0] = hThread1;
	Res[1] = hThread2;
	DWORD value[4];

	/*---------------Waiting for single thread to terminate------------------*/
	value[0] = WaitForMultipleObjects(2,Res,TRUE, INFINITE);
	value[1] = WaitForMultipleObjects(2, Res,FALSE, INFINITE);
	value[2]= WaitForMultipleObjects(2, Res, FALSE, INFINITE);
	value[3]= WaitForMultipleObjects(2, Res, FALSE, 2000);
	
	cout << endl << endl;
	for (int i = 0; i < 4; i++)
		switch (value[i])
		{
		case WAIT_TIMEOUT: cout << "Thread Terminated due to wait timeout\n";
			break;
		case WAIT_FAILED:cout << "Wait Failed\n";
			break;
		case WAIT_OBJECT_0:cout << "Thread got signaled\n";
			break;
		case WAIT_ABANDONED_0: cout << "Wait is abonded\n";
			break;
		/*defualt: cout << "Inavlid\n";
			break;*/
		}

	/*--------------Close the Handles of Threads---------------------------*/
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	

	getchar();
	return 0;
}