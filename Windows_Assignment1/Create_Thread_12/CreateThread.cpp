#include<iostream>
#include<Windows.h>
using namespace std;
DWORD WINAPI ThreadFucntion1(LPVOID lparam)
{
	Sleep(4000);
	cout <<"  Thread1 created successfully\n";
		return 0;
}
DWORD WINAPI ThreadFucntion2(LPVOID lparam)
{
	cout << "  Thread2 created successfully\n";
	return 0;
}
int main()
{
	DWORD Thread1,Thread2;			//variable that hold threads
	HANDLE ThreadHandle1, ThreadHandle2;		//handles to threads

	ThreadHandle1 = CreateThread(NULL, 0, ThreadFucntion1, NULL, 0, &Thread1);  //create of the thread and runs soon after creation
	
	if (ThreadHandle1 == NULL)			//Test for failure condition of Thread creation
		cout << "Falied to create thread";

	ThreadHandle2 = CreateThread(NULL, 0, ThreadFucntion2, NULL, CREATE_SUSPENDED, &Thread1);		// //creates the thread and runs after ResumeThread() is called
	if (ThreadHandle2 == NULL)			//Test for failure condition of Thread creation
		cout << "Falied to create thread";
	ResumeThread(ThreadHandle2);		//Resume Thread2 which is suspended state

	CloseHandle(ThreadHandle1);		//closes the thread
	CloseHandle(ThreadHandle2);
	system("pause");
	return 0;
}