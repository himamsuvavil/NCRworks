#include<iostream>
using namespace std;
struct node
{
	int coeff, expo;
	struct node *next;
};
class poly
{
	struct node *start;
public:
	poly()
	{
		start = NULL;
	}
	void add(int elem, int power)
	{
		struct node *tmp;
		tmp = new node;
		tmp->coeff = elem;
		tmp->expo = power;
		tmp->next = NULL;
		if (start == NULL)
			start = tmp;
		else
		{
			struct node *t = start;
			while (t->next != NULL)
				t = t->next;
			t->next = tmp;
		}
	}
	poly addpoly(poly p1, poly p2)
	{
		struct node *t1, *t2;
		t1 = p1.start;
		t2 = p2.start;
		while (t1 != NULL&&t2 != NULL)
		{
			struct node *tmp;
			tmp = new node;
			tmp->next = NULL;
			if (t1->expo == t2->expo)
			{
				tmp->coeff = t1->coeff + t2->coeff;
				tmp->expo = t1->expo;
				cout << tmp->coeff << " " << tmp->expo << endl;
				if (start == NULL)
					start = tmp;
				else
				{
					struct node *t = start;
					while (t->next != NULL)
						t = t->next;
					t->next = tmp;
				}
				t1 = t1->next;
				t2 = t2->next;
			}
			else if (t1->expo > t2->expo)
			{
				tmp->coeff = t1->coeff;
				tmp->expo = t1->expo;
				cout << tmp->coeff << " " << tmp->expo << endl;
				if (start == NULL)
					start = tmp;
				else
				{
					struct node *t = start;
					while (t->next != NULL)
						t = t->next;
					t->next = tmp;
				}
				t1 = t1->next;
			}
			else
			{
				tmp->coeff = t2->coeff;
				tmp->expo = t2->expo;
				cout << tmp->coeff << " " << tmp->expo << endl;
				if (start == NULL)
					start = tmp;
				else
				{
					struct node *t = start;
					while (t->next != NULL)
						t = t->next;
					t->next = tmp;
				}
				t2 = t2->next;
			}
		}
			while (t1 != NULL)
			{
				struct node *tmp;
				tmp = new node;
				tmp->coeff = t1->coeff;
				tmp->expo = t1->expo;
				tmp->next = NULL;
				struct node *t = start;
				while (t->next != NULL)
					t = t->next;
				t->next = tmp;
				t1=t1->next;
			}
			while (t2 != NULL)
			{
				struct node *tmp;
				tmp = new node;
				tmp->next = NULL;
				tmp->coeff =t2->coeff;
				tmp->expo =t2->expo;
				struct node *t = start;
				while (t->next != NULL)
					t = t->next;
				t->next = tmp;
				t2=t2->next;
			}

		
		return *this;
	}
		void display()
		{
			struct node *t = start;
			while (t != NULL)
			{
				cout << t->coeff << "x^" << t->expo;
				if (t->next != NULL)
					cout << "+";
				t = t->next;
			}
			cout << endl;
		}

	};
	int main()
	{
		poly p1, p2, p3;
		cout << "Enter 1st ploynomial:\n";
		int c, e;
		char ch;
		do
		{
			cout << "Coeff & power:";
			cin >> c>>e;
			p1.add(c, e);
			cout << "continue(y/n)?";
			cin >> ch;
		} while (ch == 'y');
				cout << "Enter 2nd ploynomial:\n";
			do
			{
				cout << "Coeff & power:";
				cin >> c>> e;
				p2.add(c, e);
				cout << "continue(y/n)?";
				cin >> ch;
			} while (ch == 'y');
			p1.display();
			p2.display();
					p3.addpoly(p1, p2);
				p3.display();
				system("pause");
				return 0;
	}