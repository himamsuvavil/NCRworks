#include<iostream>
using namespace std;
class employee
{
	int x;
	char name[12];
public:
	employee()
	{
		cout << "Deafault constructor\n";
	}
	employee(const employee &e)
	{
		cout << "Copy constructor\n";
	}
	~employee()
	{
		cout << "Destructor initiated\n";
	}
};
int main()
{
	employee e1, e2(e1);
	cout << "size of object 1:" << sizeof(e1) << endl;
	cout << "size of object 2:" << sizeof(e2) << endl;
	system("pause");
	return 0;
	
}