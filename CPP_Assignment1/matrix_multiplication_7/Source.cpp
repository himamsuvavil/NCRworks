#include<iostream>
using namespace std;
class matrix
{
	int m, n;
	int **p=NULL;
public:
	void get_size()
	{
		cout << "Enter m and n:";
		cin >> m >> n;
	}
	void get_matrix()
	{
		p = new int*[m];
		for (int i = 0; i < n; i++)
		{
			*(p + i) = new int[n];
		}
		if (p == NULL)
			cout << "Memory allocation failed";
	}
	void get_data()
	{
		cout << "Enter " << m*n << " values:" << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> p[i][j];
		}
	}
	void display()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << p[i][j] << " ";
			}
			cout << endl;
		}
	}
	friend matrix mul(matrix, matrix);
};
matrix mul(matrix a, matrix b)
{
	cout << "Entered:";
	int n;
	cin >> n;
	matrix x;
	
	if (a.n == b.m)
	{
		cin >> n;
		cout << "Valid\n";
		x.m = a.m;
		x.n = b.n;
		x.get_matrix();
		int sum;
		for (int i = 0; i < a.m; i++)
		{
			sum = 0;
			for (int j = 0; j < b.n; j++)
			{
				for (int k = 0; k < b.m; k++)
				{
					sum += a.p[i][k] * b.p[k][j];
				}
				x.p[i][j] = sum;
			}
		}
	}
	else
	{
		cout << "Inavlid multiplication";
	}
	return x;

}
int main()
{
	matrix m1, m2,m3;
	m1.get_size();
	m1.get_matrix();
	m1.get_data();
	m1.display();
	m2.get_size();
	m2.get_matrix();
	m2.get_data();
	m2.display();
	m3 = mul(m1, m2);
	m3.display();
	system("pause");

}