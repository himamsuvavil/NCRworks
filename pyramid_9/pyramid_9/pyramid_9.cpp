// pyramid_9.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include "stdafx.h"

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



	}
}

