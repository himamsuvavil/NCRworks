#include<iostream>
using namespace std;
class search
{
	int *s, n;
public:
	search()
	{
		s = NULL;
	}
	void add(int t)
	{
		n = t;
		s = new int[n];
	}
	void get_data()
	{
		for (int i = 0; i < n; i++)
			cin >>s[i];
	}
	int  linear_search(int ch)
	{
		int x = -1;
		for (int i = 0; i < n; i++)
			if (s[i] == ch)
			{
				x = i;
				break;
			}
		return x;		
	}
};
int main()
{
	search s1;
	cout << "Enter size of array:";
	int n;
	cin >> n;
	s1.add(n);
	cout << "Enter elements:";
	s1.get_data();
	cout << "Enter element to be searched:";
	int elem;
	cin >> elem;
	int x = s1.linear_search(elem);
	if (x == -1)
		cout << "No such element is found\n";
	else
		cout << "Element is found at " << x << " index\n";
	system("pause");
	return 0;

}