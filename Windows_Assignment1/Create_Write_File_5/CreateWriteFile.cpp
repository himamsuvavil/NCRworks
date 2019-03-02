#include<iostream>
#include<windows.h>
#include<tchar.h>
#define BUFFER_SIZE 15
using namespace std;
int _tmain(int argc, TCHAR *argv[])
{
	//Check if File name is given at command line arguments are not
	if (argc == 1)
	{
		cout << "No File is mentioned at command line arguments" << endl;
		return 0;
	}
	else
	{
		HANDLE FileHandle;
		FileHandle = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);     //Creating the file given at command line arguments at source code path
		if (INVALID_HANDLE_VALUE == FileHandle)
		{
			cout << "File cann't be opened\n";    //When File cannot be opened
			return 0;
		}
		else
		{
			cout << "File opened Successfully\n\n";
			CHAR BUFFER[]="File is opened and data is written successfull";
			int result;
			DWORD ReachedEnd;
			
				result = WriteFile(FileHandle, BUFFER, strlen(BUFFER),&ReachedEnd, NULL);  //To write data into created file
				if (result == 0)
					_tprintf(_T("Error occured during Writing the file is :%s\n"), GetLastError());  //If data cannot be written
				else if (ReachedEnd == 0)		//when no more data is available to write
				{
					cout << "Written successfully into the file %s\n" << argv[1] << endl;   
					CloseHandle(FileHandle);
				}	
		}
	}
	system("pause");
	return 0;
}