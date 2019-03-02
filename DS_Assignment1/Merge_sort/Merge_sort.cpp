#include<iostream>
using namespace std;
class merging
{
	int *a, n, tmp[30];
public:
	merging()
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
			cin >> tmp[i];
	}
	void display()
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	void merge(int low, int high)
	{
		if (low <high)
		{
			int mid = (low + high) / 2;
			merge(low, mid);
			merge(mid + 1, high);
			mergesort(low, mid, high);
		}
	}
	void mergesort(int low1,int high1,int high2)
	{
		int low2 = high1 + 1;
		int i = low1, j = low2;
		int k = 0;
		while (i <= high1&&j <= high2)
		{
			if (a[i] < a[j])
				tmp[k++] = a[i++];
			else
				tmp[k++] = a[j++];
		}
		while (i <= high1)
			tmp[k++] = a[i++];
		while (j <= high2)
			tmp[k++] = a[j++];
		for (i = 0; i < k; i++)
			cout << tmp[i] << " ";
		cout << endl;
		
	}
	
};
int main()
{
	merging m1;
	cout << "Enter size:";
	int size;
	cin >> size;
	m1.add(size);
	cout << "Enter elements:";
	m1.get_data();
	cout << "after sorting :\n";
	m1.merge(0, size - 1);
	m1.display();
	system("pause");
	return 0;

}