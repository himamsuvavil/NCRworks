#include<iostream>
using namespace std;
class quick_sort
{
	int *a, n;
public:
	quick_sort()
	{
		a = NULL;
		n = 0;
	}
	void add(int t)
	{
		n = t;
		a = new int[n];
	}
	void get_data()
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	void display()
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	void quick(int low, int high)
	{
		int pivot = a[low];
		int i = low + 1, j = high;
		if (low < high)
		{
			while (i < high&&a[i] < pivot)
				i++;
			while (j > low + 1 && a[j] > pivot)
				j--;
			if (i < j)
				swap(a[i], a[j]);
			else
				break;
		}
		swap(a[j],a[low])

	}
};