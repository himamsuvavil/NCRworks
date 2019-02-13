#include<iostream>
using namespace std;
class Time
{
	int hrs, mins, sec;
public:
	Time()
	{
		hrs = mins = sec = 0;
	}
	Time(int a, int b, int c)
	{
		hrs = a; mins = b; sec = c;
	}
	void display()
	{
		cout << "Time is" << hrs << ":" << mins << ":" << sec << endl;
	}
	Time add( Time t2)
	{
		Time t;
		t.hrs = hrs + t2.hrs;
		t.mins = mins + t2.mins;
		t.sec = sec + t2.sec;
		if (t.sec > 60)
		{
			int l1 = t.sec / 60;
			int l2 = t.sec % 60;
			t.sec = l2;
			t.mins += l1;
		}
		if (t.mins > 60)
		{
			int l1 = t.mins % 60;
			int l2 = t.mins / 60;
			t.mins = l2;
			t.hrs +=l1;
		}
		if (t.hrs > 24)
		{
			int l1 = t.hrs % 24;
			t.hrs = l1;
		}
		return t;
	}
};
int main()
{
	Time o1();
	Time o2(3, 45, 56), o3(6, 12, 30);
	Time o4=o3.add (o2);
	o4.display();
	char c;
	cin >> c;
	return 0;


}