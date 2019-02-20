#include<iostream>
using namespace std;
class employee
{
	char name[50];
	int salary, empno;
public:
	friend istream& operator >> (istream& cin, employee&);
	friend ostream& operator<<(ostream& cout, employee);
};
istream& operator >> (istream&cin, employee &e)
{
	cout << "Enter name:";
	cin >> e.name;
	cout << "Employee no:";
	cin >> e.empno;
	cout << "Enter slary:";
	cin >> e.salary;
	return cin;
}
ostream& operator << (ostream&cout, employee e)
{
	cout << "Name:";
	cout << e.name << endl;
	cout << "Number:";
	cout << e.empno << endl;
	cout << "Salary given :";
	cout << e.salary << endl;
	return cout;
}
int main()
{
	employee E[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		cout << "Enter details of an emplyee:\n";
		cin >> E[i];
	}
	for (i = 0; i < 5; i++)
	{
		cout << "Employee Details are:\n";
		cout << E[i];
	}
	system("pause");
	return 0;
}