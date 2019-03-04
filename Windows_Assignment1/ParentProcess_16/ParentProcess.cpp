#include<iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std; 
int _tmain(int argc, TCHAR *argv[])		//Parent Process
{
	STARTUPINFO s1;
	PROCESS_INFORMATION p1;
	ZeroMemory(&s1, sizeof(s1));
	ZeroMemory(&p1, sizeof(p1));
	bool ProcessResult = CreateProcess(NULL, argv[1], NULL, NULL, TRUE, 0, NULL, NULL, &s1, &p1);
	if (!ProcessResult)
		cout << "Process creation is failed\n";
	else
	{
		cout << "Process created\n";
		SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	}
	CloseHandle(p1.hThread);
	return 0;
}