#include<iostream>
#include<Windows.h>
#include<tchar.h>
using namespace std;
void AllEnvironmentVariables(PTSTR pEnvBlock[]) //Prints all the available environment variables
{
	int value = 0;
	PTSTR pCurrent = NULL;
	PTSTR *pElement = (PTSTR*) pEnvBlock;
	while (pElement != NULL)			//until no environment variable is available
	{
		pCurrent = (PTSTR)(*pElement);
		if (pCurrent == NULL)			
			pElement = NULL;			//terminating condition
		else
		{
			_tprintf(_T("[%u]%s/r\n"), value, pCurrent);			//printing environmental variables value and path
			value++;
			pElement++;
		}
	}
}

int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{

	AllEnvironmentVariables(env);//calling function to print all available environmental variables
	
	cout << "Expanded path\n";
	TCHAR EnvString[] = TEXT("%public%");   //specifying path to be expanded
	TCHAR buffer[MAX_PATH];				//to store the path that will be expanded
	int ret;					//to store return value of expandenvironment strings
	ret = ExpandEnvironmentStrings(EnvString, buffer, MAX_PATH);   //expand path
	if (ret == 0)					//if there is no such path available
		printf("%d\n", GetLastError());
	else
		_tprintf(_T("%s\n"), buffer);
		//printf("%S\n", buffer);
	
	system("pause");
}