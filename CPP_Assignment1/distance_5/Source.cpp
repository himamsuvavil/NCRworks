#include<iostream>
using namespace std;
class distance2;
class distance1
{
	float meters, cms;
public:
	void get_data()
	{
		cout << "enter distance in meters and centimeters:";
		cin >> meters >> cms;
	}
	void display()
	{
		cout << "Distance is :" << meters << " meters " << cms << "centimeters "<<endl;
	}
	friend distance1 add1(distance1,distance2);
	friend distance2 add2(distance1, distance2);
};
class distance2
{
	float inches, feet;
public:
	void get_data()
	{
		cout << "enter distance in inches and feet:";
		cin >> feet >> inches;
	}
	void display()
	{
		cout << "Distance is :" <<feet << " feet" <<inches << "inches " << endl;
	}
	friend distance1 add1(distance1, distance2);
	friend distance2 add2(distance1, distance2);
};
distance1 add1(distance1 x, distance2 y)
{
	distance1 tmp;
	float l = y.feet*(0.3048f);
	tmp.meters = x.meters + l;
	l = y.inches*(2.54f);
	tmp.cms = x.cms + l;
	return tmp;
	
}
distance2 add2(distance1 x, distance2 y)
{
	distance2 tmp;
	float l = x.meters*(3.28f);
	tmp.feet = y.feet + l;
	l = x.cms*(0.393f);
	tmp.inches = y.inches + l;
	return tmp;

}
int main()
{
	distance1 d1,res1;
	distance2 d2,res2;
	d1.get_data();
	d2.get_data();
	res1 = add1(d1, d2);
	res2 = add2(d1, d2);
	res1.display();
	res2.display();
	system("pause");

}