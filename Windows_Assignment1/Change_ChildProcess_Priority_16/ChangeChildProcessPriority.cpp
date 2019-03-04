#include<iostream>
#include<Windows.h>
using namespace std;
DWORD WINAPI ThreadFucntion1(LPVOID lparam)
{
	cout << "Thread1 created successfully\n";
	return 0;
}
int main()		//Child Process
{
	

	DWORD Thread1;		//variable that hold threads
	HANDLE ThreadHandle1;	//handle to threads

	ThreadHandle1 = CreateThread(NULL, 0, ThreadFucntion1, NULL, 0, &Thread1);  // //creates the thread and runs immediately

	if (ThreadHandle1 == NULL)			//Test for failure condition of Thread creation
		cout << "Falied to create thread";
	else
	{
		SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);
		SetThreadPriority(ThreadHandle1, THREAD_PRIORITY_LOWEST);
	}
	CloseHandle(ThreadHandle1);
	system("pause");
	return 0;
}