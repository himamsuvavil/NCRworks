#include<iostream>
#include<string.h>
using namespace std;
class string1
{
	int len;
	char *s;
public:
	string1()
	{
		len = 0;
		s = NULL;
	}
	string1(char *a)
	{
		len = strlen(a);
		s = new char[len + 1];
		strcpy_s(s, len + 1, a);
	}
	string1(string a)
	{
		len = a.len;
		s = new char[len + 1];
		strcpy_s(s, len + 1, a.s);
	}
	~string1()
	{
		cout << "destructor"<<endl;
	}
	string1 operator+(string1);
	friend istream& operator>>(istream&cin, string1&);
	friend ostream& operator<<(ostream&cout, string1);
};
string1 string1::operator+(string1 a)
{
	string1 t;
	t.len = len + a.len + 1;
	t.s = new char[len];
	strcpy_s(t.s, t.len, s);
	strcat_s(t.s, t.len, a.s);
	return t;
}
istream& operator >> (istream&cin, string1 &a)
{
	cout << "Enter length of a string:";
	cin >> a.len;
	a.s = new char[a.len + 1];
	cout << "Enter string:";
	cin >> a.s;
}
ostream& operator<<(ostream&cout, string1 a)
{
	cout << "String is:" << a.s << endl;
}
int main()
{
	string1 s1, s2("apple"), s3(s2);
	s
}