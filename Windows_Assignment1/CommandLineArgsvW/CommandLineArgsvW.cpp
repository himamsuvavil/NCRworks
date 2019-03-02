#include<Windows.h>
#include<iostream>
#include<tchar.h>
#include<shellapi.h>
using namespace std;
int _tmain()
{
	LPWSTR *SZcommandline_string=NULL;  //String pointer to command line arguments
	int NumArgs;				//Number of Command line arguments


	SZcommandline_string = CommandLineToArgvW(GetCommandLineW(), &NumArgs); //Function that takes command line widechar strings


	if (SZcommandline_string == NULL)					//Checking if no aruguments are passed
		cout << "Error in taking commandline arguments is : " << GetLastError() << "\n";
	else
	{
		for (int i = 1; i < NumArgs; i++)		//At i=0 path of the program is stored
		{
			wprintf(L"SZ[%d]: %s\n", i, SZcommandline_string[i]);	//printing command line arguments
			
		}
		
	}
	system("pause");
	return 0;
}