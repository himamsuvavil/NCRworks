#include<iostream>
#include<Windows.h>
using namespace std;
DWORD WINAPI ThreadFucntion1(LPVOID lparam)
{
	DWORD exitcode=1;
	cout << "Thread1 created successfully\n";
	ExitThread(exitcode);
	return 0;
}
int main()
{
	DWORD Thread1;		//variable that hold threads
	HANDLE ThreadHandle1;	//handle to threads
	DWORD ThreadPointer=0;
	ThreadHandle1 = CreateThread(NULL, 0, ThreadFucntion1, NULL, 0, &Thread1);  // //creates the thread and runs immediately

	if (ThreadHandle1 == NULL)			//Test for failure condition of Thread creation
		cout << "Falied to create thread";
	else
	{

		WaitForSingleObject(ThreadHandle1, 0);
		
		int ThreadStatus = GetExitCodeThread(ThreadHandle1, &ThreadPointer);

		if (ThreadStatus == 0)
			cout << "Error occured In getting the status\n";

		CloseHandle(ThreadHandle1);
		getchar();
	}
	return 0;
}
