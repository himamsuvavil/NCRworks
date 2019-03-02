#include<iostream>
#include<windows.h>
#include<tchar.h>
#define BUFFER_SIZE 15
using namespace std;
int _tmain(int argc, TCHAR *argv[])
{
	if (argc == 1)  //Check if File name is given at command line arguments are not
	{
		cout << "No File is mentioned at command line arguments" << endl;
		return 0;
	}
	else
	{
		HANDLE FileHandle;
		FileHandle = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);  //Open the file given at command line arguments
		if (INVALID_HANDLE_VALUE == FileHandle)  //If file cannot be opened CreateFile will returns "INVALID_HANDLE_VALUE"
		{
			cout << "File cann't be opened\n";
			return 0;
		}
		else
		{
			cout << "File opened Successfully\n\n";  
			CHAR BUFFER[BUFFER_SIZE];
			ZeroMemory(BUFFER, BUFFER_SIZE);   //Initilaize BUFFER data with zeros
			int result;
			DWORD ReachedEnd;
			while (1)
			{
				result = ReadFile(FileHandle, BUFFER, BUFFER_SIZE, &ReachedEnd, NULL);  //Redaing the 15 bytes of File data and storing in BUFFER
				if (result == 0)			//when data cannot be read
					_tprintf(_T("Error occured during reading is :%s\n"), GetLastError());
				else if (ReachedEnd == 0)		//when file reaches end
				{
					cout << "Reached End of the File\n";
					CloseHandle(FileHandle);
					break;					
				}
				else
				{
					for (int i = 0; i < ReachedEnd; i++)  //printing every character stored in buffer
					{
						printf("%c", BUFFER[i]);
					}
					
				}
			}
		}
	}
	system("pause");
	return 0;
}