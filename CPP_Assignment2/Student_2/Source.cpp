#include<iostream>
using namespace std;
class student
{
	char sname[50];
	int rollno, m1, m2, m3;
	char grade[20];
	float avg;
	
public:
	friend istream& operator >> (istream& cin, student&);
	friend ostream& operator<<(ostream& cout,student);
	friend void generate_marks(student[], int);
};
istream& operator >> (istream&cin ,student &s)
{
	cout << "Enter name:";
	cin >> s.sname;
	cout << "Roll no:";
	cin >> s.rollno;
	cout << "Marks of 3 subjects:";
	cin >> s.m1 >> s.m2 >> s.m3;
	return cin;
}
ostream& operator << (ostream&cout, student s)
{
	cout << "Name:";
	cout << s.sname << endl;
	cout << "Roll no:";
	cout << s.rollno << endl;
	cout << "Marks of 3 subjects:";
	cout << s.m1 << endl << s.m2 << endl << s.m3 << endl;
	cout << "Grade:";
	cout << s.grade << endl;
	cout << "Average of marks:";
	cout << s.avg <<endl;
	return cout;
}
void generate_marks(student *s, int n)
{
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		sum = s[i].m1 + s[i].m2 + s[i].m3;
		s[i].avg = (float)sum / 3;
		if (s[i].avg > 60)
			strcpy_s(s[i].grade, sizeof(char) + 15, "First class");
		else if (s[i].avg > 50 && s[i].avg < 60)
			strcpy_s(s[i].grade, sizeof(char) + 15, "Second class");
		else if (s[i].avg > 40 && s[i].avg < 50)
			strcpy_s(s[i].grade, sizeof(char) + 15, "Third class");
		else
			strcpy_s(s[i].grade, sizeof(char) + 15, "Fail");
	}
}
int main()
{
	int n;
	cout << "Number of students:";
	cin >> n;
	student s1[30];
	cout << "Enter details:";
	for (int i = 0; i < n; i++)
	{
		cin >>s1[i];
	}
	generate_marks( s1, n);
	cout << "Student deatils are:";
	for (int i = 0; i < n; i++)
	{
		cout << s1[i];
	}
	system("pause");
}