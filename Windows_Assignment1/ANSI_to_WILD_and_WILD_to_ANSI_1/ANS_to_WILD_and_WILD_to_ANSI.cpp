#include<Windows.h>
#include<iostream>
#include<tchar.h>
using namespace std;
int main()
{
	CHAR ansi_array[] ="Ansi_code";
	WCHAR widechar_array[]=L"Wildcode";
	int SizeOfANSIArray = sizeof(ansi_array);
	int SizeOfWideCharArray = sizeof(widechar_array);
	int wide_array_size,multiByteSize;
	BOOL uniresult;

	//Converting MultiByte character to Wide char

	wide_array_size=MultiByteToWideChar(CP_UTF8, 0, ansi_array, -1, NULL,0);
	WCHAR *Ansi_to_Wide_array= new WCHAR[wide_array_size];
	MultiByteToWideChar(CP_UTF8, 0, ansi_array,-1,Ansi_to_Wide_array,wide_array_size);
	uniresult = IsTextUnicode(Ansi_to_Wide_array, wide_array_size, NULL);
	if (uniresult)
	{
		cout << "It is Unicode\n";
	//	int size = sizeof(Ansi_to_Wild_array);
		cout << "Initial and final size of ANSI array " << SizeOfANSIArray << " " << wide_array_size<< endl;
	}
	else
		_tprintf(_T("It is not Unicode\n "));


	//Converting Wide char to MultiByte Character
	multiByteSize = WideCharToMultiByte(CP_UTF8, 0, widechar_array, -1, NULL, 0, NULL,NULL);
	CHAR *WildtoANSI_array = new CHAR[multiByteSize];
	multiByteSize = WideCharToMultiByte(CP_UTF8, 0, widechar_array, -1, WildtoANSI_array, multiByteSize, NULL,NULL);
	uniresult = IsTextUnicode(WildtoANSI_array, multiByteSize, NULL);
	if (uniresult)
		cout << "It is Unicode\n";
	else
	{
		_tprintf(_T("It is not Unicode\n "));
		int size = sizeof(WildtoANSI_array);
		cout << "Initial and final size of ANSI array " << SizeOfWideCharArray << " " << size << endl;
	}
	system("pause");
	return 0;
}