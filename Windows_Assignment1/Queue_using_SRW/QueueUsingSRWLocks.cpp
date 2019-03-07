#include<iostream>
#include<Windows.h>
using namespace std;
#define MaxQueueSize 5
#define MaxThreads 6
int ThreadCount;
SRWLOCK Lock;

DWORD WINAPI ReadFunction(LPVOID lparam)
{
	AcquireSRWLockExclusive(&Lock);
	if()
}
DWORD WINAPI WriteFunction(LPVOID lparam)
{
	
}
int main()
{
	DWORD Thread[MaxThreads];
	HANDLE ThreadHandle[MaxThreads];

	InitializeSRWLock(&Lock);
	/*---------------------Writer Thread creation------------------------*/
	for (int i = 0; i < 2; i++)
	{
		ThreadHandle[i] = CreateThread(NULL, 0, WriteFunction, NULL, 0, &Thread[i]);
		if (ThreadHandle[i] == NULL)
			cout << "Failed to create Thread1\n";
	}
	for (int i = 0; i < 3; i++)
	{
		ThreadHandle[i] = CreateThread(NULL, 0, ReadFunction, NULL, 0, &Thread[i]);
		if (ThreadHandle[i] == NULL)
			cout << "Failed to create Thread2\n";
	}
	
}