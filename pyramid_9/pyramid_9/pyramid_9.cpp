// pyramid_9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;
int main()
{
	int rows, i, j,space,k ;
	cout << "Enter rows:";
	cin >> rows;
	int tmp = rows - 1;
	for (i =1; i <= rows; i++)
	{
		
		for (space = 0; space < tmp; space++)
		{
			cout << "  ";
		}
		tmp--;
		for (j = i; j >0;j--)
		{
			cout << j << " ";
		}
		if (i != 1)
		{
			for (k = 2; k <= i; k++)
				cout << k << " ";
		}
		cout << endl;
		
	}
	cin >>rows;
	return 0;

}

