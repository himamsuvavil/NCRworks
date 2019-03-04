#include<iostream>
#include<Windows.h>
using namespace std; 
DWORD WINAPI ThreadFucntion1(LPVOID lparam)
{
	cout << "Thread1 created successfully\n";
	for (int i = 0; i <= 1000; i++)		//printing 0 to 1000 numbers
		cout << i << " ";
	cout << endl;
	return 0;
}
int main()
{
	DWORD Thread1;		//variable that hold threads
	HANDLE ThreadHandle1;	//handle to threads
	ThreadHandle1 = CreateThread(NULL, 0, ThreadFucntion1, NULL, CREATE_SUSPENDED, &Thread1);  // //creates the thread and runs after ResumeThread() is called

	if (ThreadHandle1 == NULL)			//Test for failure condition of Thread creation
		cout << "Falied to create thread";

	Sleep(5000);		//Thread is set to waiting state for 5 seconds
	ResumeThread(ThreadHandle1);		//Resumes the thread to run

	getchar();
	return 0;
}
