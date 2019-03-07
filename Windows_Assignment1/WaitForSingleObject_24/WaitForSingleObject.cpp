#include<iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std;
DWORD WINAPI ThreadFunction1(LPVOID lparam)
{
	Sleep(1000);
	return 0;
}
DWORD WINAPI ThreadFunction2(LPVOID lparam)
{
	
	return 0;
}
DWORD WINAPI ThreadFunction3(LPVOID lparam)
{
	Sleep(3000);
	return 0;
}

int _tmain()
{
	DWORD Thread1, Thread2, Thread3;
	HANDLE hThread1, hThread2, hThread3;

	/*-----------------------Threads Creation-------------*/
	hThread1 = CreateThread(NULL, 0, ThreadFunction1, NULL, 0, &Thread1);
	if (hThread1 == NULL)
		cout << "Failed to create Thread1\n";
	hThread2 = CreateThread(NULL, 0, ThreadFunction2, NULL, 0, &Thread2);
	if (hThread2 == NULL)
		cout << "Failed to create Thread2\n";
	hThread3 = CreateThread(NULL, 0, ThreadFunction3, NULL, 0, &Thread2);
	if (hThread3 == NULL)
		cout << "Failed to create Thread3\n";
	DWORD value[3];
	
		/*---------------Waiting for single thread to terminate------------------*/
		value[0] = WaitForSingleObject(hThread1, INFINITE);
		value[1] = WaitForSingleObject(hThread2, 1000);
		value[2] = WaitForSingleObject(hThread3, 2000);
		cout << endl << endl;
		for (int i = 0; i < 3; i++)
			switch (value[i])
			{
			case WAIT_TIMEOUT: cout << "Thread Terminated due to wait timeout\n";
				break;
			case WAIT_FAILED:cout << "Wait Failed\n";
				break;
			case WAIT_OBJECT_0:cout << "Thread got signaled\n";
				break;
			}
	
		/*--------------Close the Handles of Threads---------------------------*/
		CloseHandle(hThread1);
		CloseHandle(hThread2);
		CloseHandle(hThread3);
	
	getchar();
	return 0;
}